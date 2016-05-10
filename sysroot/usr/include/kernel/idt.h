#ifndef _IDT_H
#define _IDT_H 1

#include <stdint.h>

struct idt_table_s {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct idt_entry_s {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t flags;
	uint16_t offset_high;
} __attribute__((packed));

extern void _load_idt();
extern void _default_idt_handler();

void install_idt(void);
void add_idt_entry(uint8_t num, uint32_t callback);

#endif /* _IDT_H */
