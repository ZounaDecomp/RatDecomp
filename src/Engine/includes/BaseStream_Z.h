#ifndef _BASESTREAM_Z_H_
#define _BASESTREAM_Z_H_

#include "Types_Z.h"

class BaseStream_Z {
public:
    short m_OpenID;
    short m_ReadID;
    virtual void StreamOpened(S32 a1, S32 a2);
    virtual void StreamReaded(S32 a1, S32 a2);
    virtual void Opened(S32 a1, S32 a2, S32 a3);
    virtual void Readed(S32 a1, S32 a2, S32 a3);
};

#endif
