# Multiboot header constants
.set ALIGN,	1<<0
.set MEMINFO,	1<<1
.set FLAGS,	ALIGN | MEMINFO
.set MAGIC,	0x1BADB002
.set CHECKSUM,	-(MAGIC + FLAGS)

# Setup the multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Setup a stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 32768
stack_top:

.section .text

.global _load_gdt
.type _load_gdt, @function
_load_gdt:
	lgdt gdtp
	ljmp $0x08, $_load_gdt_finish
	
_load_gdt_finish:
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	ret

.global _load_idt
.type _load_idt, @function
_load_idt:
	lidt idtp
	ret
	
.global _default_idt_handler
.type _default_idt_handler, @function
_default_idt_handler:
	pushal
	mov $0x20, %al
	mov $0x20, %dx
	out %al, %dx
	popal
	iretl
	
.global _load_page_directory
.type _load_page_directory, @function
_load_page_directory:
	push %ebp
	mov %esp, %ebp
	mov 8(%esp), %eax
	mov %eax, %cr3
	mov %ebp, %esp
	pop %ebp
	ret

.global _enable_paging
.type _enable_paging, @function
_enable_paging:
	push %ebp
	mov %esp, %ebp
	mov %cr0, %eax
	or $0x80000000, %eax
	mov %eax, %cr0
	mov %ebp, %esp
	pop %ebp
	ret
	
.global _enter_usermode
.type _enter_usermode, @function
_enter_usermode:
	cli
	#mov $0x23, %ax
	#mov %ax, %ds
	#mov %ax, %es
	#mov %ax, %fs
	#mov %ax, %gs
	
	mov %esp, %eax
	pushl $0x23
	pushl %eax
	pushf
	mov $0x200, %eax
	push %eax
	pushl $0x1B
	#push kernel_main
	iret

.global _start
.type _start, @function
_start:
	movl $stack_top, %esp

	# Reset EFLAGS
	pushl $0
	popf

	# Push multiboot info onto stack
	pushl %ebx
	pushl %eax
	
	# Initialize the kernel
	call kernel_init
	
	sti
	
	# Start the kernel main function
	call kernel_main

	# Halt if we fall thru the kernel
	#cli
	hlt

.Lhang:
	jmp .Lhang
