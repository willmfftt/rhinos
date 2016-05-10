#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <kernel/multiboot.h>
#include <kernel/tty.h>
#include <kernel/io.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/pic.h>
#include <kernel/exception.h>
#include <kernel/pit.h>
#include <kernel/paging.h>
#include <kernel/usermode.h>
#include <kernel/keyboard.h>

#define CHECK_FLAG(flags,bit)	((flags) & (1 << (bit)))

void kernel_init(unsigned long magic, unsigned long addr) {
	multiboot_info_t *mbi;
	
	/* Initialize terminal interface */
    terminal_initialize();

    if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		printf("Invalid magic number: 0x%x\n", (unsigned) magic);
		return;
    }
    
    mbi = (multiboot_info_t *) addr;
    
    printf("\n################## MMAP INFO ########################\n\n");
	
	printf("flags = 0x%x\n", (unsigned) mbi->flags);
	printf("mmap_addr = 0x%x, mmap_length = 0x%x\n", (unsigned) mbi->mmap_addr, (unsigned) mbi->mmap_length);
	
	if (CHECK_FLAG(mbi->flags, 0))
		printf("mem_lower = %uKB, mem_upper = %uKB\n", (unsigned) mbi->mem_lower, (unsigned) mbi->mem_upper);
		
	if (CHECK_FLAG(mbi->flags, 1))
		printf("boot_device = 0x%x\n", (unsigned) mbi->boot_device);
		
	if (CHECK_FLAG(mbi->flags, 6)) {
		multiboot_memory_map_t *mmap;
		
		for (mmap = (multiboot_memory_map_t *) mbi->mmap_addr; (unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length; mmap = (multiboot_memory_map_t *) ((unsigned long) mmap + mmap->size + sizeof(mmap->size)))
			printf("size = 0x%x, base_addr = 0x%x%x, length = 0x%x%x, type = 0x%x\n", (unsigned) mmap->size, mmap->addr >> 32, mmap->addr & 0xffffffff, mmap->len >> 32, mmap->len & 0xffffffff, (unsigned) mmap->type);
	}
	
	printf("\n################## END MMAP INFO ########################\n\n");
    
    install_gdt();
	
	pic_remap();
	install_idt();
	
	install_exceptions();
	
	timer_phase(100);
	timer_install();
	
	paging_install();
	
	// install_tss();
	// _enter_usermode();
	
	keyboard_install();
}
 
void kernel_main() {	
//	timer_wait(100 * 5);
	
	while(1);
}
