#include <kernel/pit.h>
#include <kernel/pic.h>
#include <kernel/idt.h>
#include <kernel/io.h>

#include <stdint.h>
#include <stdio.h>

int timer_ticks = 0;

void timer_phase(int hz)
{
	int divisor = PIT_CLOCK_RATE / hz;
	outb(PIT_COMMAND, 0x36);
	outb(PIT_CHANNEL_0_DATA, divisor & 0xff);
	outb(PIT_CHANNEL_0_DATA, divisor >> 8);
	printf("[kernel init] Timer phase initialized\n");
}

void timer_handler()
{
	asm volatile("pushal");
	
	timer_ticks++;
		
	pic_sendEOI(0);

	asm volatile("popal");
	asm volatile("addl $0x1c, %esp");
	asm volatile("iret");
}

void timer_wait(int ticks)
{
	static unsigned long eticks;
	
	eticks = timer_ticks + ticks;
	
	while (timer_ticks < eticks) {
		printf("");
	}
	
	printf("\n\nTimer ended\n\n");
}

void timer_install()
{
	add_idt_entry(32, (uint32_t) timer_handler);
}
