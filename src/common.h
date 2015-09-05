#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned int u32;
typedef int i32;
typedef unsigned short u16;
typedef short i16;
typedef unsigned char u8;
typedef char i8;

void kmemset(void* dest, i8 value, i32 size);

u8 inb(u16 port);
u16 inw(u16 port);
void outb(u16 port, u8 value);

#endif /* _COMMON_H_ */
