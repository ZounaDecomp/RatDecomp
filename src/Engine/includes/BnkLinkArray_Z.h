#ifndef _BNKLINKARRAY_Z_H_
#define _BNKLINKARRAY_Z_H_
#include "Types_Z.h"

template <class T, S32 Granularity = 256, S32 Alignment = 4> 
class BnkLinkArrayEle_Z {
public:

private:
    BnkLinkArrayEle_Z<T>* m_NextBank;
    T m_Reserve[Granularity];
    T* m_Current;
    T* m_First;
    T* m_Last;
    S32 m_NbFree;
};

template <class T, S32 Granularity = 256, S32 Alignment = 4>
class BnkLinkArray_Z {
public:

private:
    BnkLinkArrayEle_Z<T, Granularity, Alignment>* m_BankListHead;
    S32 m_MaxSizeTotal;
    S32 m_SizeTotal;
    S32 m_NbFreeTotal;
};

#endif
