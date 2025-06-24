#ifndef _WORLD_ZHDL_H_
#define _WORLD_ZHDL_H_
#include "ResourceObject_ZHdl.h"

class World_Z;
HANDLE_Z(World_Z, ResourceObject_Z);
typedef DynArray_Z<World_ZHdl, 32> World_ZHdlDA;

#endif
