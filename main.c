#include "common.h"
#include "video.h"
#include "stdt.h"

int main()
{
        vidClear();

        vidWrite("initializing GDT and IDT..\n");
        stdtInit();

        vidWrite("sending interrupt 0..\n");
        asm volatile ("int $0x0");

        return 0xdeadbabe;
}
