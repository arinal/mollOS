#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned int u32;
typedef int i32;
typedef unsigned short u16;
typedef short i16;
typedef unsigned char u8;
typedef char i8;

#define S8_MAX  0x7f
#define U8_MAX  0xff
#define S16_MAX 0x7fff
#define U16_MAX 0xffff
#define S32_MAX 0x7fffffff
#define U32_MAX 0xffffffff

typedef int bool;
#define false 0
#define true !false

void kmemset(void* dest, i8 value, i32 size);
void swap(i8 *n1, i8 *n2);
void itoa(int num, char *str);
void itoab(int num, char *str, int base);
void kprint(const char *format, ...);

#endif /* _COMMON_H_ */
