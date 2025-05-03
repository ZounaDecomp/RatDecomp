#ifndef _CLASSNAMERESMANAGER_Z_H_
#define _CLASSNAMERESMANAGER_Z_H_
#include "HashTable_Z.h"

class ClassNameRes_Z {
    U8 m_Pad_0x0[0xc];
    HashS32Table_Z m_HashTab;

    ClassNameRes_Z();
};

#endif
