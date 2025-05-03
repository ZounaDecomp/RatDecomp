#ifndef _HASHTABLE_Z_H_
#define _HASHTABLE_Z_H_
#include "BitArray_Z.h"

extern "C" void memset(void *__s,S32 __c,U32 __n);

#define HASHTABLE_DEFAULT_SIZE 16
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

    inline Bool IsEmpty() { return !m_Ref; }
    inline void SetShadow() { m_Ref = -1; }

    inline S32 HashBase() const { return m_Value; }
    inline S32 HashIncrement() const {
        return m_Value == 0;
    }

    Bool operator==(const S32Hash_Z &i_Elem) { return i_Elem.m_Value == m_Value; }
    Bool operator!=(const S32Hash_Z &i_Elem) { return i_Elem.m_Value != m_Value; }
};

template<class T>
class HashTableBase_Z {
    BitArray_Z* m_Status;
    T* m_Hash;
    U32 m_NbElem;
    U32 m_NbFree;
    U32 m_ScanID;

    HashTableBase_Z();

    Weak_Z Bool Insert(const T &i_Ele) {
        if (!m_Status)
            Resize(HASHTABLE_DEFAULT_SIZE);
        S32 l_HashSize = m_Status->GetSize() - 1;
        S32 l_HashID = i_Ele.HashBase() & l_HashSize;
        S32 l_HashInc = i_Ele.HashIncrement();
        S32 l_ShadowHashID = -1;
        if (!(l_HashInc & 0x1))
            l_HashInc++;

        for (;;) {
            if (!m_Status->GetBit(l_HashID)) {
                if (!m_Hash[l_HashID].m_Ref) {
                    if (l_ShadowHashID < 0)
                        m_NbFree--;
                    else
                        l_HashID = l_ShadowHashID;

                    m_Status->SetBit(l_HashID);
                    *(m_Hash + l_HashID) = i_Ele;

                    m_NbElem++;

                    if ((m_NbFree == 0) || (m_NbFree < (m_Status->GetSize() >> 2)))
                        Resize(m_NbElem);

                    return TRUE;
                } else {
                    if (l_ShadowHashID < 0)
                        l_ShadowHashID = l_HashID;
                }
            } else {
                if (m_Hash[l_HashID] == i_Ele)
                    return FALSE;
            }
            l_HashID = (l_HashID + l_HashInc) & l_HashSize;
        }
    }

    Weak_Z void Resize(S32 i_NewSize) {
        S32 l_OldSize;
        S32 l_NextScan;

        l_OldSize = 1;
        while (l_OldSize < i_NewSize)
            l_OldSize <<= 1;
        l_OldSize <<= 1;
        i_NewSize = l_OldSize;

        BitArray_Z* l_OldStatus = m_Status;
        T* l_OldHash = m_Hash;
        m_Status = NewL_Z(62) BitArray_Z(i_NewSize);
        m_Status->ClearAllBits();
        m_Hash = (T*)AllocL_Z(sizeof(T) * i_NewSize, 65);
        memset(m_Hash, 0, sizeof(T) * i_NewSize);

        S32 OldNbElem = m_NbElem;

        m_NbElem = 0;
        m_NbFree = i_NewSize;

        if (!l_OldStatus)
            return;

        l_NextScan = 0;
        while ((l_NextScan = l_OldStatus->FindFirstBit(TRUE, l_NextScan)) >= 0) {
            Bool bResult = Insert(*(l_OldHash + l_NextScan));
            l_NextScan++;
        }
        Free_Z(l_OldHash);
        Delete_Z l_OldStatus;
    }
};

typedef HashTableBase_Z<S32Hash_Z> HashS32Table_Z;
//typedef HashTableBase_Z<Name_ZHash_Z> HashName_ZTable_Z;

#endif
