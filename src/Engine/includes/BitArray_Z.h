#ifndef _BITARRAY_Z_H_
#define _BITARRAY_Z_H_
#include "DynArray_Z.h"

class BitArray_Z {
    U32DA m_BitsDA;
    U32 m_Size;

public:
    BitArray_Z();
    BitArray_Z(S32 i_Size);
    ~BitArray_Z();
    BitArray_Z& operator=(const BitArray_Z &i_Src);

    inline void SetSize(S32 i_Size) {
        m_Size = i_Size;
        if (i_Size && (i_Size >> 5) + 1 > m_BitsDA.GetSize()) {   
            m_BitsDA.SetSize((m_Size >> 5) + 1);
        }
    }
};

#endif
