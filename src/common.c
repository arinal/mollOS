#include "common.h"
#include "video.h"
#include "string.h"

void swap(i8 *n1, i8 *n2)
{
        i8 temp = *n1;
        *n1 = *n2;
        *n2 = temp;
}

void itoab(int num, char* str, int base)
{
        int i = 0;
        bool negative = false;

        if (num == 0)
        {
                str[i++] = '0';
                str[i] = 0;
                return;
        }

        if (num < 0 && base == 10)
        {
                negative = true;
                num = -num;
        }

        while (num != 0)
        {
                int rem = num % base;
                str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
                num = num / base;
        }

        if (negative) str[i++] = '-';
        str[i] = 0;
        strrevl(str, i);
}

inline void itoa(int num, char *str)
{
        itoab(num, str, 10);
}

void kprint(const char *format, ...)
{
        const char *p;
        const int *args = (const int*)(&format + 1);
        vidWrite("-> ");
        vidWrite((char*)args);
        vidPut('\n');
        int argc = -1;
        for (p = format; *p != 0; ++p) {
                if (*p++ != '%') vidPut(*p);
                else {
                        argc++;
                        int i;
                        char *s;
                        switch (*p) {
                        case 'c':
                                i = args[argc];
                                vidPut(i);
                                break;
                                /* case 'd': */
                                /*         i = args[argc]; */
                                /*         s = itoa(i, fmtbuf, 10); */
                                /*         fputs(s, stdout); */
                                /* break; */
                        case 's':
                                s = (char*)args[argc];
                                vidWrite(s);
                                break;
                                /* case 'x': */
                                /*         i = va_arg(argp, int); */
                                /*         s = itoa(i, fmtbuf, 16); */
                                /*         fputs(s, stdout); */
                                /*         break; */
                        case '%':
                                vidPut('%');
                                break;
                        }
                }
        }
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
