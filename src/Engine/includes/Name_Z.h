#ifndef _NAME_Z_H_
#define _NAME_Z_H_
#include "Types_Z.h"

class Name_Z
{
public:
    Name_Z(const Name_Z& a1);
    Name_Z(const Char* a1);
    Name_Z() { m_ID = 0; }
    void SetID(S32 a1) { m_ID = a1; }
    static S32 GetID(const S8* a1, U32 a2);
    static S32 GetID(U8* data, U32 size, U32 result);

private:
	S32 m_ID;
};

#endif
