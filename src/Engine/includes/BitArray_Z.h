#ifndef _BITARRAY_Z_H_
#define _BITARRAY_Z_H_
#include "DynArray_Z.h"

class BitArray_Z {
public:
    U32DA m_BitsDA;
    S32 m_Size;

    BitArray_Z();
    BitArray_Z(S32 i_Size);
    BitArray_Z(const BitArray_Z &i_Src);
    ~BitArray_Z();
    BitArray_Z& operator=(const BitArray_Z &i_Src);

    void SetAllBits();
    void ClearAllBits();
    void ClearBitRange(S32 i_StartIndex, S32 i_EndIndex);
    S32 FindFirstBit(bool i_State = TRUE, S32 i_firstBitToCheck = 0) const;
    S32 FindLastBit(bool i_State, S32 i_firstBitToCheck) const;

    inline S32 GetSize() const { return m_Size; }

    void ClearBit(S32 i_Bit) {
        m_BitsDA[i_Bit >> 5] &= ~(1 << (i_Bit & 0x1F));
    }

    U32 GetBit(S32 i_Bit) const { 
        return m_BitsDA[i_Bit >> 5] & (1 << (i_Bit & 0x1F));
    }

    void SetBit(S32 i_Bit) {
        m_BitsDA[i_Bit >> 5] |= (1 << (i_Bit & 0x1F));
    }

    inline void SetSize(S32 i_Size) {
        m_Size = i_Size;
        if (i_Size && (i_Size >> 5) + 1 > m_BitsDA.GetSize()) {   
            m_BitsDA.SetSize((m_Size >> 5) + 1);
        }
    }

    inline void Flush() {
        m_BitsDA.Flush();
        m_Size = 0;
    }

    inline void Minimize(void) { 
        m_BitsDA.Minimize();
    }
};

#endif
