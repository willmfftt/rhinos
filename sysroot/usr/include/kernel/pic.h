#ifndef _PIC_H
#define _PIC_H 1

#include <stdint.h>

#define PIC_ENABLE	0x11
#define PIC_MASTER_COMM	0x20
#define PIC_MASTER_DATA	0x21
#define PIC_SLAVE_COMM	0xA0
#define PIC_SLAVE_DATA	0xA1
#define PIC_EOI	0x20

void pic_remap(void);
void pic_sendEOI(unsigned char irq);

#endif /* _PIC_H */
