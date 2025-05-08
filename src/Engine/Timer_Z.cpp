#include "Timer_Z.h"

extern U32 CONSOLE_BUS_SPEED : 0x800000F8;
extern "C" U32 OSGetTick();
void CalibrateTimer() {}
Float GetAbsoluteTime()
{
    return (((OSGetTick())) / (((CONSOLE_BUS_SPEED / 4))/ 1000.0f) / 1000.0f);
}
