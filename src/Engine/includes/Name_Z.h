#ifndef _NAME_Z_H_
#define _NAME_Z_H_
#include "Types_Z.h"

class Name_Z
{
    public:
        static S32 GetID(U8* a1, U32 a2);
        static S32 GetID(U8* data, U32 size, U32 result);
};

#endif