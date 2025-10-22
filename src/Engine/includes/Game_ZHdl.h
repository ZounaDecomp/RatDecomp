#ifndef _GAME_ZHDL_H_
#define _GAME_ZHDL_H_
#include "Handle_Z.h"
#include "Program_Z.h"
class Game_Z;
HANDLE_Z(Game_Z, BaseObject_Z);
typedef DynArray_Z<Game_ZHdl, 32> Game_ZHdlDA;

#endif
