#ifndef _UNPACK_Z_H_
#define _UNPACK_Z_H_
#include "Types_Z.h"

class Unpack_Z {
    Unpack_Z(const U8*, U8);
    ~Unpack_Z();
    void Flush();
    U8* DecodeRS();
};
#endif
