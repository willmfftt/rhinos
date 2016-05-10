#include <kernel/pic.h>
#include <kernel/io.h>

void pic_remap(void) 
{
	unsigned char m1, m2;
	m1 = inb(PIC_MASTER_DATA);
	m2 = inb(PIC_SLAVE_DATA);
	
	outb(PIC_MASTER_COMM, PIC_ENABLE);
	io_wait();
	outb(PIC_SLAVE_COMM, PIC_ENABLE);
	io_wait();
	outb(PIC_MASTER_DATA, 0x20);
	io_wait();
	outb(PIC_SLAVE_DATA, 0x28);
	io_wait();
	outb(PIC_MASTER_DATA, 0x04);
	io_wait();
	outb(PIC_SLAVE_DATA, 0x02);
	io_wait();
	outb(PIC_MASTER_DATA, 0x01);
	io_wait();
	outb(PIC_SLAVE_DATA, 0x01);
	io_wait();
	
	outb(PIC_MASTER_DATA, m1);
	outb(PIC_SLAVE_DATA, m2);
}

void pic_sendEOI(unsigned char irq)
{
	if (irq >= 8)
		outb(PIC_SLAVE_COMM, PIC_EOI);
		
	outb(PIC_MASTER_COMM, PIC_EOI);
}
