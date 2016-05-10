#include <kernel/irq.h>
#include <kernel/idt.h>
#include <kernel/pic.h>
#include <stdio.h>

void irq0()
{
	printf("irq0\n");
	pic_sendEOI(0x00);
}

void irq1()
{
	pic_sendEOI(0x01);
}

void irq2()
{
	pic_sendEOI(0x02);
}

void irq3()
{
	pic_sendEOI(0x03);
}

void irq4()
{
	pic_sendEOI(0x04);
}

void irq5()
{
	pic_sendEOI(0x05);
}

void irq6()
{
	pic_sendEOI(0x06);
}

void irq7()
{
	pic_sendEOI(0x07);
}

void irq8()
{
	pic_sendEOI(0x08);
}

void irq9()
{
	pic_sendEOI(0x09);
}

void irq10()
{
	pic_sendEOI(0x0a);
}

void irq11()
{
	pic_sendEOI(0x0b);
}

void irq12()
{
	pic_sendEOI(0x0c);
}

void irq13()
{
	pic_sendEOI(0x0d);
}


void irq14()
{
	pic_sendEOI(0x0e);
}

void irq15()
{
	pic_sendEOI(0x0f);
}

void install_irqs()
{
	add_idt_entry(32, (uint32_t) &irq0);
	add_idt_entry(33, (uint32_t) &irq1);
	add_idt_entry(34, (uint32_t) &irq2);
	add_idt_entry(35, (uint32_t) &irq3);
	add_idt_entry(36, (uint32_t) &irq4);
	add_idt_entry(37, (uint32_t) &irq5);
	add_idt_entry(38, (uint32_t) &irq6);
	add_idt_entry(39, (uint32_t) &irq7);
	add_idt_entry(40, (uint32_t) &irq8);
	add_idt_entry(41, (uint32_t) &irq9);
	add_idt_entry(42, (uint32_t) &irq10);
	add_idt_entry(43, (uint32_t) &irq11);
	add_idt_entry(44, (uint32_t) &irq12);
	add_idt_entry(45, (uint32_t) &irq13);
	add_idt_entry(46, (uint32_t) &irq14);
	add_idt_entry(47, (uint32_t) &irq15);
}
