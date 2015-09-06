#include "common.h"
#include "string.h"
#include "video.h"
#include "stdt.h"

int main()
{
        vidClear();

        kprint("initializing GDT and IDT..\n");
        stdtInit();

        kprint("sending interrupt 1..\n");
        asm volatile ("int $0x1");

        kprint("damn %s %d %x %c\n", "you Av!", 1, S32_MAX, '#');

        return 0xdeadbabe;
}
