#ifndef HAL_H
#define HAL_H

#include "common.h"

u8 inb(u16 port);
u16 inw(u16 port);
void outb(u16 port, u8 value);

#endif /* HAL_H */
