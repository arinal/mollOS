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
        char buff[50];
        int argc = -1;
        for (p = format; *p != 0; ++p) {
                if (*p != '%') vidPut(*p);
                else if (*p + 1 == '%')
                        vidPut('%'), p++;
                else {
                        argc++;
                        switch (*++p) {
                        case 'c':
                                vidPut(args[argc]);
                                break;
                        case 'd':
                                itoa(args[argc], buff);
                                vidWrite(buff);
                                break;
                        case 's':
                                vidWrite((char*)args[argc]);
                                break;
                        case 'x':
                                itoab(args[argc], buff, 16);
                                vidWrite(buff);
                                break;
                        }
                }
        }
}

