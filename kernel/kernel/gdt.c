#include <kernel/gdt.h>

struct gdt_entry_s gdt[3];
struct gdt_table_s gdtp;

void install_gdt(void)
{
	gdtp.limit = (sizeof(struct gdt_entry_s) * 3) - 1;
	gdtp.base = &gdt;
	
	add_gdt_entry(0, 0, 0, 0, 0);
	add_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	add_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	
	_load_gdt();
}

void add_gdt_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
	gdt[num].base_low = (base & 0xFFFF);
	gdt[num].base_middle = (base >> 16) & 0xFF;
	gdt[num].base_high = (base >> 24) & 0xFF;
	
	gdt[num].limit_low = (limit & 0xFFFF);
	gdt[num].granularity = ((limit >> 16) & 0x0F);
	
	gdt[num].granularity |= (gran & 0xF0);
	gdt[num].access = access;
}
