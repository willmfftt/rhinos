#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/rhinos.kernel isodir/boot/rhinos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "rhinos" {
	multiboot /boot/rhinos.kernel
}
EOF
grub-mkrescue -o rhinos.iso isodir
