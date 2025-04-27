#include "Name_Z.h"

Name_Z::Name_Z(const Char* a1)
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
