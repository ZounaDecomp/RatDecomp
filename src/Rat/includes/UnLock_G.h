#ifndef _UNLOCK_G_H_
#define _UNLOCK_G_H_
#include "DynArray_Z.h"
class UnlockElem_G;

typedef DynArray_Z<UnlockElem_G, 4> UnlockElemArray;

class UnlockElem_G {
    U8 m_Pad_0x0[0xc0];
};

class UnLockEvents_G {
    UnlockElemArray m_UnlockElemDA;
};

#endif // _UNLOCK_G_H_
