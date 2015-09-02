#include "common.h"

u8 inb(u16 port)
{
        u8 ret;
        asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
        return ret;
}

u16 inw(u16 port)
{
        u16 ret;
        asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
        return ret;
}

void outb(u16 port, u8 value)
{
        asm volatile ("outb %1, %0" : "=dN" (port) : "a" (value));
}
