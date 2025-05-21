#include "Timer_Z.h"

Extern_Z U32 CONSOLE_BUS_SPEED : 0x800000F8;
Extern_Z "C" U32 OSGetTick();
Extern_Z Float Random();
void CalibrateTimer() { }
Float GetAbsoluteTime() {
    return (((OSGetTick())) / (((CONSOLE_BUS_SPEED / 4)) / 1000.0f) / 1000.0f);
}
