#ifndef _FONTS_Z_H_
#define _FONTS_Z_H_
#include "Types_Z.h"

S32 GetUTF8CharBytes(const S8* a1);
U32 GetUTF8CharCode(const S8* a1);

class Fonts_Z
{
    virtual ~Fonts_Z();
    virtual void Load(void* a1);
    virtual void EndLoad();
    virtual void AfterEndLoad();
    virtual void MarkHandles();
};

#endif
