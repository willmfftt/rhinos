#include <kernel/usermode.h>
#include <kernel/gdt.h>

#include <stdint.h>

void install_tss()
{
	tss.ss0 = 0x10;
	tss.iomap = (unsigned short) sizeof(tss_t);
	
	add_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
	add_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
	
	unsigned long addr = (unsigned long) &tss;
	int size = sizeof(tss_t) + 1;
	add_gdt_entry(5, addr, addr + size, 0x89, 0xCF);
}
