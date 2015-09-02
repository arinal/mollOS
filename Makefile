OBJECTS = boot.o main.o common.o video.o
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Wall -W
LDFLAGS = -Tlink.ld -melf_i386
ASFLAGS = --32

all: kernel

image: kernel
	@echo 'Updating floopy.img..'
	@sudo /sbin/losetup /dev/loop0 floppy.img
	@sudo mount /dev/loop0 /mnt
	@sudo cp kernel /mnt/kernel
	@sudo umount /dev/loop0
	@sudo /sbin/losetup -d /dev/loop0

run: image
	bochs

clean:
	-rm *.o kernel

dep:
	$(CC) -MM *.c

.PHONY: all image run clean dep

# Deps (use make dep to generate this)
common.o: common.c common.h
main.o: main.c video.h
video.o: video.c common.h

kernel: $(OBJECTS) link.ld
	ld $(LDFLAGS) -o kernel $(OBJECTS)

