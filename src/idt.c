#include "common.h"
#include "video.h"

struct idtEntry {
        u16 baseLo;
        u16 selector;
        u8 always0;
        u8 flags;
        u16 baseHi;
} __attribute__((packed));

struct idtPtr {
        u16 limit;
        struct idtEntry *base;
} __attribute__((packed));

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void idtFlush(struct idtPtr *idtPtr);

struct idtEntry idtEntries[256];
struct idtPtr idtPtr;

static void idtSetGate(u8 n, void isr(), u16 selector, u8 flags)
{
        struct idtEntry *entry = idtEntries + n;

        u32 isrAddr = (u32)isr;
        entry->baseLo = isrAddr & 0xffff;
        entry->baseHi = (isrAddr >> 16) & 0xffff;

        entry->selector = selector;
        entry->always0 = 0;
        entry->flags = flags;
}

void idtInit()
{
        idtPtr.limit = sizeof(idtEntries) - 1;
        idtPtr.base = idtEntries;

        kmemset(idtEntries, 0, sizeof(idtEntries));
        idtSetGate( 0,  isr0, 0x8, 0x8e);
        idtSetGate( 1,  isr1, 0x8, 0x8e);
        idtSetGate( 2,  isr2, 0x8, 0x8e);
        /* idtSetGate( 3,  isr3, 0x8, 0x8e); */
        /* idtSetGate( 4,  isr4, 0x8, 0x8e); */
        /* idtSetGate( 5,  isr5, 0x8, 0x8e); */
        /* idtSetGate( 6,  isr6, 0x8, 0x8e); */
        /* idtSetGate( 7,  isr7, 0x8, 0x8e); */
        /* idtSetGate( 8,  isr8, 0x8, 0x8e); */
        /* idtSetGate( 9,  isr9, 0x8, 0x8e); */
        /* idtSetGate(10, isr10, 0x8, 0x8e); */

        idtFlush(&idtPtr);
}

struct registerState {
        u32 ds;
        u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
        u32 intNo;
        u32 eip, cs, eflags, userEsp, ss;
};

void isrHandler(struct registerState registers)
{
        /* printk("Handled interrupt %d\n", registers.intNo); */
        vidWrite("DAMN!\n");
}
