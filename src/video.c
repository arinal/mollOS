#include "common.h"

#define WIDTH 80
#define HEIGHT 24

static u16 *vidBuffer = (u16*)0xb8000;

#define COLOR_BLACK 0
#define COLOR_WHITE 15

#define CHR_BACKSPACE 0x8

#define VID_ATTR_BYTE (COLOR_BLACK << 4) | (COLOR_WHITE & 0xf)
#define VID_ATTR_UPPER (VID_ATTR_BYTE << 8)

#define BLANK (' ' | (VID_ATTR_UPPER))

struct coord {
        u8 x;
        u8 y;
};

static struct coord cursorLocation;

static inline u16 cursorIndex()
{
        return cursorLocation.y * WIDTH + cursorLocation.x;
}

static void moveCursor()
{
        u16 index = cursorIndex();
        outb(0x3d4, 14);
        outb(0x3d5, index >> 8);
        outb(0x3d4, 15);
        outb(0x3d5, index);
}

static void scroll()
{
        int i;
        for (i = 0; i < HEIGHT*WIDTH; ++i) vidBuffer[i] = vidBuffer[i + WIDTH];
        for (i = HEIGHT*WIDTH; i < (HEIGHT + 1)*WIDTH; ++i) vidBuffer[i] = BLANK;
        cursorLocation.y = HEIGHT;
}

void vidGoto(int x, int y)
{
        cursorLocation.x = x;
        cursorLocation.y = y;
        moveCursor();
}

void vidPut(char c)
{
        if (c == CHR_BACKSPACE && cursorLocation.x) cursorLocation.x--;
        else if (c == '\t') cursorLocation.x = (cursorLocation.x + 8) & ~(8 - 1);
        else if (c == '\r') cursorLocation.x = 0;
        else if (c == '\n') cursorLocation.x = 0, cursorLocation.y++;
        else if (c >= ' ') {
                u16 *addr = vidBuffer + cursorIndex();
                *addr = c | VID_ATTR_UPPER;
                cursorLocation.x++;
        }

        if (cursorLocation.x >= WIDTH) cursorLocation.x = 0, cursorLocation.y++;
        if (cursorLocation.y >= (HEIGHT + 1)) scroll();
        moveCursor();
}

void vidClear()
{
        int i;
        for (i = 0; i < HEIGHT * (WIDTH + 1); ++i) vidBuffer[i] = BLANK;
        cursorLocation.x = 0, cursorLocation.y = 0;
        moveCursor();
}

void vidWrite(char *c)
{
        int i = 0;
        while (c[i]) vidPut(c[i++]);
}
