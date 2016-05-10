#include <kernel/keyboard.h>
#include <kernel/idt.h>
#include <kernel/pic.h>
#include <kernel/io.h>

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static char* _qwertyuiop = "qwertyuiop";
static char* _asdfghjkl = "asdfghjkl";
static char* _zxcvbnm = "zxcvbnm";
static char* _num = "123456789";

uint8_t keyboard_to_ascii(uint8_t key)
{
	if(key == 0x1C) return '\n';
	if(key == 0x39) return ' ';
	if(key == 0xE) return '\r';
	if(key == POINT_RELEASED) return '.';
	if(key == SLASH_RELEASED) return '/';
	if(key == ZERO_PRESSED) return '0';
	if(key >= ONE_PRESSED && key <= NINE_PRESSED)
		return _num[key - ONE_PRESSED];
	if(key >= 0x10 && key <= 0x1C)
	{
		return _qwertyuiop[key - 0x10];
	} else if(key >= 0x1E && key <= 0x26)
	{
		return _asdfghjkl[key - 0x1E];
	} else if(key >= 0x2C && key <= 0x32)
	{
		return _zxcvbnm[key - 0x2C];
	}
	return 0;
}

void keyboard_handler()
{
	asm volatile ( "pushal" );
	
	char c = 0;
	if (inb(0x64) & 1) {
		c = inb(0x60);
		if (c > 0) {
			printf("%c", keyboard_to_ascii(c));
		}
	}
	
	pic_sendEOI(1);
	
	asm volatile ( "popal" );
	asm volatile ( "addl $0x1c, %esp" );
	asm volatile ( "iret" );
}

void keyboard_install()
{
	add_idt_entry(33, (uint32_t) keyboard_handler);
}
