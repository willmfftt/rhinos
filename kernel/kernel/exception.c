#include <stdio.h>
#include <kernel/exception.h>
#include <kernel/idt.h>

void exc_divide_by_zero()
{
	printf("Divide by zero!\n");
	
	asm volatile("hlt");
}

void exc_debug()
{
	printf("Debug!\n");
	
	asm volatile("hlt");
}

void exc_nmi()
{
	printf("NMI\n");
	
	asm volatile("hlt");
}

void exc_brp()
{
	printf("Breakpoint!\n");
	
	asm volatile("hlt");
}

void exc_overflow()
{
	printf("Overflow!\n");
	
	asm volatile("hlt");
}

void exc_bound()
{
	printf("Bound range exceeded.\n");
	
	asm volatile("hlt");
}

void exc_invopcode()
{
	printf("Invalid opcode.\n");
	
	asm volatile("hlt");
}

void exc_device_not_avail()
{
	printf("Device not available.\n");
	
	asm volatile("hlt");
}

void exc_double_fault()
{
	printf("Double fault, halting.\n");
	
	asm volatile ( "hlt" );
}

void exc_coproc()
{
	printf("Coprocessor fault, halting.\n");
	
	asm volatile ( "hlt" );
}

void exc_invtss()
{
	printf("TSS invalid.\n");
	
	asm volatile("hlt");
}

void exc_segment_not_present()
{
	printf("Segment not present.\n");
	
	asm volatile("hlt");
}

void exc_ssf()
{
	printf("Stacksegment faulted.\n");
	
	asm volatile("hlt");
}

void exc_gpf()
{
	printf("General protection fault.\n");
	
	asm volatile("hlt");
}

void exc_pf()
{
	printf("Page fault\n");
	
	asm volatile("hlt");
}

void exc_reserved()
{
	printf("This shouldn't happen. Halted.\n");
	
	asm volatile ( "hlt" );
}

void install_exceptions()
{
	add_idt_entry(0, (uint32_t) exc_divide_by_zero);
	add_idt_entry(1, (uint32_t) exc_debug);
	add_idt_entry(2, (uint32_t) exc_nmi);
	add_idt_entry(3, (uint32_t) exc_brp);
	add_idt_entry(4, (uint32_t) exc_overflow);
	add_idt_entry(5, (uint32_t) exc_bound);
	add_idt_entry(6, (uint32_t) exc_invopcode);
	add_idt_entry(7, (uint32_t) exc_device_not_avail);
	add_idt_entry(8, (uint32_t) exc_double_fault);
	add_idt_entry(9, (uint32_t) exc_coproc);
	add_idt_entry(10, (uint32_t) exc_invtss);
	add_idt_entry(11, (uint32_t) exc_segment_not_present);
	add_idt_entry(12, (uint32_t) exc_ssf);
	add_idt_entry(13, (uint32_t) exc_gpf);
	add_idt_entry(14, (uint32_t) exc_pf);
	add_idt_entry(15, (uint32_t) exc_reserved);
}
