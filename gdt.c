#include "common.h"

struct gdtEntry {
        u16 limitLo;
        u16 baseLo;
        u8 baseMid;
        u8 accessFlags;
        u8 granularity;
        u8 baseHi;
} __attribute__((packed));

#define CODE_KERN_SEGMENT_FLAG 0x9a
#define DATA_KERN_SEGMENT_FLAG 0x92
#define CODE_USER_SEGMENT_FLAG 0xfa
#define DATA_USER_SEGMENT_FLAG 0xf2

struct gdtPtr {
        u16 limit;
        struct gdtEntry *base;
} __attribute__((packed));

static struct gdtEntry gdtEntries[5];
static struct gdtPtr gdtPtr;

extern void gdtFlush(struct gdtPtr* gdtPtr);

static void gdtSet(i32 n, u32 base, u32 limit, u8 accessFlags, u8 granularity)
{
        struct gdtEntry *entry = gdtEntries + n;

        entry->baseLo = (base & 0xffff);
        entry->baseMid = (base >> 16) & 0xff;
        entry->baseHi = (base >> 24) & 0xff;

        entry->limitLo = (limit & 0xffff);
        entry->granularity = (limit >> 16) & 0xf;

        entry->granularity |= granularity & 0xf0;
        entry->accessFlags = accessFlags;
}

void gdtInit()
{
        gdtPtr.limit = sizeof(gdtEntries) - 1;
        gdtPtr.base = gdtEntries;

        gdtSet(0, 0, 0, 0, 0);
        gdtSet(1, 0, 0xffffffff, CODE_KERN_SEGMENT_FLAG, 0xcf);
        gdtSet(2, 0, 0xffffffff, DATA_KERN_SEGMENT_FLAG, 0xcf);
        gdtSet(3, 0, 0xffffffff, CODE_USER_SEGMENT_FLAG, 0xcf);
        gdtSet(4, 0, 0xffffffff, DATA_USER_SEGMENT_FLAG, 0xcf);

        gdtFlush(&gdtPtr);
}
