#include "common.h"
#include "string.h"
#include "video.h"
#include "stdt.h"

int main()
{
        vidClear();

        vidWrite("initializing GDT and IDT..\n");
        stdtInit();

        vidWrite("sending interrupt 1..\n");
        asm volatile ("int $0x1");

        return 0xdeadbabe;
}
