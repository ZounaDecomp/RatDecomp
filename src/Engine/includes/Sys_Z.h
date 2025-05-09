#ifndef _SYS_Z_H_
#define _SYS_Z_H_
#include "Types_Z.h"

class Sys_Z {
public:
    static void* MemCpyFrom(void* o_Dest, void* i_Src, const U32 i_Size);
};

#endif
