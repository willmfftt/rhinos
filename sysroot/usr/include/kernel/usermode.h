#ifndef _USERMODE_H
#define _USERMODE_H 1

typedef volatile struct tss_s {
	unsigned short   link;
	unsigned short   link_h;  
	unsigned long   esp0;
	unsigned short   ss0;
	unsigned short   ss0_h;  
	unsigned long   esp1;
	unsigned short   ss1;
	unsigned short   ss1_h;  
    unsigned long   esp2;
	unsigned short   ss2;
	unsigned short   ss2_h;  
	unsigned long   cr3;
	unsigned long   eip;
	unsigned long   eflags;  
    unsigned long   eax;
	unsigned long   ecx; 
	unsigned long   edx;
	unsigned long    ebx;  
	unsigned long   esp;
	unsigned long   ebp;  
	unsigned long   esi;
	unsigned long   edi;  
	unsigned short   es;
    unsigned short   es_h;  
    unsigned short   cs;
    unsigned short   cs_h;  
	unsigned short   ss;
	unsigned short   ss_h;  
	unsigned short   ds;
	unsigned short   ds_h;  
	unsigned short   fs;
    unsigned short   fs_h;  
	unsigned short   gs;
	unsigned short   gs_h;  
	unsigned short   ldt;
	unsigned short   ldt_h;  
	unsigned short   trap;
	unsigned short   iomap;  
}__attribute__((packed)) tss_t;

tss_t tss;

extern void _enter_usermode();
void install_tss();

#endif /* _USERMOD_H */
