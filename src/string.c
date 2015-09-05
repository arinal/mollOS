#include "common.h"
#include "string.h"

void strrevl(char *str, int len)
{
        int start = 0;
        int end = len - 1;
        while (start < end) swap((str + start++), (str + end--));
}

void strrev(char *str)
{
        strrevl(str, kstrlen(str));
}

int kstrlen(char *str)
{
        int size = 0;
        while (*str++ != 0) size++;
        return size;
}

void kmemset(void* dest, i8 value, i32 size)
{
        int i;
        for (i = 0; i < size; i++) *((i8*)dest + i) = value;
}
