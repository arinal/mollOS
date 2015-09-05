BUILDIR = build

all:
	cd src && $(MAKE)

image: all
	@echo 'Updating floppy.img..'
	@cp floppy.img $(BUILDIR)/floppy.img
	@sudo /sbin/losetup /dev/loop0 $(BUILDIR)/floppy.img
	@sudo mount /dev/loop0 /mnt
	@sudo cp build/kernel /mnt/kernel
	@sudo umount /dev/loop0
	@sudo /sbin/losetup -d /dev/loop0

run: image
	bochs

clean:
	cd src && $(MAKE) clean

.PHONY: all image run clean
