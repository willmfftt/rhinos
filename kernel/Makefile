HOST?=i686-elf
HOSTARCH:=i386

CFLAGS?=-O2 -g
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin -Wall -Wextra
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR:=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

OBJS:=\
$(KERNEL_ARCH_OBJS) \
kernel/kernel.o \
kernel/gdt.o \
kernel/idt.o \
kernel/irq.o \
kernel/pic.o \
kernel/exception.o \
kernel/pit.o \
kernel/paging.o \
kernel/usermode.o \
kernel/driver/keyboard.o \

all: rhinos.kernel

.PHONY: all clean install install-headers install-kernel

rhinos.kernel: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS)

%.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f rhinos.kernel $(OBJS) *.o */*.o */*/*.o

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-kernel: rhinos.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp rhinos.kernel $(DESTDIR)$(BOOTDIR)
