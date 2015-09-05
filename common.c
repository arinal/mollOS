#include "common.h"

void kmemset(void* dest, i8 value, i32 size)
{
        int i;
        for (i = 0; i < size; i++) *((i8*)dest + i) = value;
}

inline u8 inb(u16 port)
{
        u8 ret;
        asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
        return ret;
}

inline u16 inw(u16 port)
{
        u16 ret;
        asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
        return ret;
}

inline void outb(u16 port, u8 value)
{
        asm volatile ("outb %1, %0" : "=dN" (port) : "a" (value));
}
