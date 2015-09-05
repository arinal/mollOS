#include "common.h"
#include "video.h"
#include "stdt.h"

int main()
{
        vidClear();

        vidWrite("initializing GDT and IDT..\n");
        stdtInit();

        vidWrite("sending interrupt 2..\n");
        /* asm volatile ("int $0x2"); */

        return 0xdeadbabe;
}
