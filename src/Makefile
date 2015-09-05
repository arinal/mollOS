OBJECTS = boot.o main.o common.o video.o gdt.o idt.o stdt-flush.o
BUILDIR = ../build
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Wall -W
LDFLAGS = -Tlink.ld -melf_i386
ASFLAGS = --32

all: $(BUILDIR)/kernel

clean:
	-rm -rf $(BUILDIR)

dep:
	$(CC) -MM *.c

.PHONY: all clean dep

# Deps (use make dep to generate this)
common.o: common.c common.h
gdt.o: gdt.c common.h
idt.o: idt.c common.h
main.o: main.c common.h video.h stdt.h
video.o: video.c common.h

$(BUILDIR):
	mkdir $(BUILDIR)

$(BUILDIR)/kernel: $(OBJECTS) link.ld $(BUILDIR)
	ld $(LDFLAGS) -o $(BUILDIR)/kernel $(OBJECTS)
	mv *.o $(BUILDIR)
