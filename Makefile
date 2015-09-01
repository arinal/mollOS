OBJECTS = boot.o main.o
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS = -Tlink.ld -melf_i386
ASFLAGS = --32

all: kernel

image: kernel
	sudo /sbin/losetup /dev/loop0 floppy.img
	sudo mount /dev/loop0 /mnt
	sudo cp kernel /mnt/kernel
	sudo umount /dev/loop0
	sudo /sbin/losetup -d /dev/loop0

run: kernel
	bochs

clean:
	-rm *.o kernel

kernel: $(OBJECTS) link.ld
	ld $(LDFLAGS) -o kernel $(OBJECTS)

.PHONY: all clean image run
