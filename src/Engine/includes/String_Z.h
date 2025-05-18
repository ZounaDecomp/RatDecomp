#ifndef _STRING_Z_H_
#define _STRING_Z_H_
#include "Types_Z.h"

S32 fstricmp(const S8* a1, const S8* a2);
void fsprintfID(S8* a1, U32 a2, U32 a3);

template <S32 Size>
class String_Z {
protected:
    Char m_Str[Size];
};

#endif
