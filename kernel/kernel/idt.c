#include <string.h>
#include <kernel/idt.h>
#include <kernel/exception.h>
#include <kernel/pit.h>
#include <kernel/irq.h>
#include <stdio.h>

struct idt_entry_s idt[256];
struct idt_table_s idtp;

void install_idt(void)
{
	idtp.limit = (sizeof(struct idt_entry_s) * 256) - 1;
	idtp.base = &idt;
	
	memset(&idt, 0, sizeof(struct idt_entry_s) * 256);
	
	_load_idt();
}

void add_idt_entry(uint8_t num, uint32_t callback)
{
	idt[num].offset_low = callback & 0xFFFF;
	idt[num].offset_high = (callback >> 16) & 0xFFFF;
	idt[num].zero = 0;
	idt[num].selector = 0x08;
	idt[num].flags = 0x8E;
}
