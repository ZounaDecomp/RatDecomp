#ifndef _HASHTABLE_Z_H_
#define _HASHTABLE_Z_H_
#include "BitArray_Z.h"

class S32Hash_Z {
public:
    S32 m_Value;
    S32 m_Ref;

    S32Hash_Z() {}
    S32Hash_Z(S32 i_Value) { m_Value = i_Value; }
    S32Hash_Z(S32 i_Value, S32 i_Ref) {
        m_Value = i_Value;
        m_Ref = i_Ref;
    }
};

template<class T>
class HashTableBase_Z {
    BitArray_Z* m_Status;
    T* m_Hash;
    U32 m_NbElem;
    U32 m_NbFree;

    HashTableBase_Z() {

    }
};

typedef HashTableBase_Z<S32Hash_Z> HashS32Table_Z;
//typedef HashTableBase_Z<Name_ZHash_Z> HashName_ZTable_Z;

#endif
