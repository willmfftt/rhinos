#ifndef _GDT_H
#define _GDT_H 1

struct gdt_entry_s {
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char base_middle;
	unsigned char access;
	unsigned char granularity;
	unsigned char base_high;
} __attribute__((packed));

struct gdt_table_s {
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

extern void _load_gdt();

void install_gdt(void);
void add_gdt_entry(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

#endif /* _GDT_H */
