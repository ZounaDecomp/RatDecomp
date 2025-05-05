#ifndef _HOLEARRAY_Z_H_
#define _HOLEARRAY_Z_H_
#include "BitArray_Z.h"

template<class T, S32 Granularity>
class HoleArray_Z {
    DynArray_Z<T, Granularity> m_DA;
    BitArray_Z m_BA;
    S32 m_Size;
    S32 m_NbElement;

public:
    HoleArray_Z() {
        m_Size = 0;
        m_NbElement = 0;
    }

    S32 FindFirst(void) const
    {
        if(m_Size==0) return  -1;
        return m_BA.FindFirstBit();
    }

    S32 FindNext(S32 i_Cur) const {
        i_Cur++;
        if (i_Cur >= m_Size) return -1;
        return m_BA.FindFirstBit(TRUE, i_Cur);
    }

    S32 Add(const T & i_Elem) {
        S32 l_Free;
        if (m_Size == 0) l_Free = -1;
        else l_Free = m_BA.FindFirstBit(FALSE);
        m_NbElement++;
        if (l_Free == -1) {
            m_DA.Add(i_Elem);
            m_BA.SetSize(m_Size + 1);
            m_BA.SetBit(m_Size);
            return m_Size++;
        } else {
            m_DA[l_Free] = i_Elem;
            m_BA.SetBit(l_Free);
            return l_Free;
        }
    }

    S32 Add() {
        S32 l_Free;
        if (m_Size == 0) l_Free = -1;
        else l_Free = m_BA.FindFirstBit(FALSE);
        m_NbElement++;
        if (l_Free == -1) {
            m_DA.Add();
            m_BA.SetSize(m_Size + 1);
            m_BA.SetBit(m_Size);
            return m_Size++;
        } else {
            new (&m_DA[l_Free]) T;
            m_BA.SetBit(l_Free);
            return l_Free;
        }
    }

    T & Get(S32 i_Index) {
        return m_DA[(U32)i_Index];
    }

    const T & Get(S32 i_Index) const {
        return m_DA[(U32)i_Index];
    }

    T & operator[](S32 i_Index) {
        return Get(i_Index);
    }

    const T & operator[](S32 i_Index) const {
        return Get(i_Index);
    }
};
#endif
