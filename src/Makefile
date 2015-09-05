BUILDIR = ../build
OBJECTS = $(BUILDIR)/boot.o $(BUILDIR)/main.o $(BUILDIR)/common.o $(BUILDIR)/video.o $(BUILDIR)/gdt.o $(BUILDIR)/idt.o $(BUILDIR)/stdt-flush.o $(BUILDIR)/string.o
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Wall -W
LDFLAGS = -Tlink.ld -melf_i386
ASFLAGS = --32

all: $(BUILDIR)/kernel

clean:
	-rm -rf $(BUILDIR)

dep:
	$(CC) -MM *.c

.PHONY: all clean dep

$(BUILDIR)/%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

$(BUILDIR)/%.o : %.s
	as $(ASFLAGS) -c $< -o $@

# Deps (use make dep to generate this)
common.o: common.c common.h video.h string.h
gdt.o: gdt.c common.h
idt.o: idt.c common.h video.h
main.o: main.c common.h string.h video.h stdt.h
string.o: string.c common.h string.h
video.o: video.c common.h

$(BUILDIR):
	mkdir $(BUILDIR)

$(BUILDIR)/kernel: $(BUILDIR) $(OBJECTS) link.ld
	ld $(LDFLAGS) -o $(BUILDIR)/kernel $(OBJECTS)
