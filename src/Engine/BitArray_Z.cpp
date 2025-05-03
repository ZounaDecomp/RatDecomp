#include "BitArray_Z.h"

BitArray_Z::BitArray_Z() {
    m_Size = 0;
}

BitArray_Z::~BitArray_Z() {
}

BitArray_Z::BitArray_Z(S32 i_Size) {
    SetSize(i_Size);
}

#pragma dont_inline on
BitArray_Z& BitArray_Z::operator=(const BitArray_Z &i_Src) {
    m_BitsDA = i_Src.m_BitsDA;
    m_Size = i_Src.m_Size;
    return *this;
}
#pragma dont_inline off
