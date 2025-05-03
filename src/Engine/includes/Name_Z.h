#ifndef _NAME_Z_H_
#define _NAME_Z_H_
#include "Types_Z.h"

class Name_Z
{
public:
    Name_Z(const Name_Z& a1);
    Name_Z(const Char* a1);
    Weak_Z Name_Z(const S32 a1) { m_ID = a1; }
    Name_Z() { m_ID = 0; }
    void SetID(S32 a1) { m_ID = a1; }
    static S32 GetID(const S8* a1, U32 a2);
    static S32 GetID(U8* data, U32 size, U32 result);
    Weak_Z Bool operator==(const Name_Z& a1) const { return m_ID == a1.m_ID; }
    Weak_Z Bool operator==(Name_Z a1) const { return m_ID == a1.m_ID; }

private:
	S32 m_ID;
};
// it is weak. it must be here. idk how else to tackle it
Weak_Z Name_Z::Name_Z(const Name_Z& a1) {
    m_ID = a1.m_ID;
}
Weak_Z Name_Z::Name_Z(const Char* a1)
{
    S32 result = 0;
    if (a1)
    {
        result = GetID(a1, 0);
    }
    else
    {
        result = 0;
    }
    m_ID = result;
}

#endif
