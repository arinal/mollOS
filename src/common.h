#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned int u32;
typedef int i32;
typedef unsigned short u16;
typedef short i16;
typedef unsigned char u8;
typedef char i8;

#define U8_MAX  0xff
#define U16_MAX 0xffff
#define U32_MAX 0xffffffff

typedef int bool;
#define false 0
#define true !false

void kmemset(void* dest, i8 value, i32 size);
void swap(i8 *n1, i8 *n2);
void itoa(int num, char *str);

u8 inb(u16 port);
u16 inw(u16 port);
void outb(u16 port, u8 value);

#endif /* _COMMON_H_ */
