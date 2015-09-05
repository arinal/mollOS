#ifndef _STDT_H_
#define _STDT_H_

void gdtInit();
void idtInit();

inline void stdtInit()
{
        gdtInit();
        idtInit();
}

#endif /* _STDT_H_ */
