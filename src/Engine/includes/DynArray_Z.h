#ifndef _DYNARRAY_Z_H_
#define _DYNARRAY_Z_H_
#include "Types_Z.h"
#include "Memory_Z.h"

#define	DYA_SIZEBITS 18
#define	DYA_RSVSIZEBITS (32-DYA_SIZEBITS)
#define	DYA_SIZEMAX ((1<<DYA_SIZEBITS))
#define	DYA_RSVSIZEMAX ((1<<DYA_RSVSIZEBITS))

template<class T, S32 Granularity = 8, Bool DeleteObject = TRUE, Bool InitObject = TRUE, S32 Align = _ALLOCDEFAULTALIGN>
class DynArray_Z {
public:
    DynArray_Z() {
        m_Size = 0;
        m_ReservedSize = 0;
        m_ArrayPtr = NULL;
    }

    ~DynArray_Z() {
        if (m_ArrayPtr) {
            if (DeleteObject) {
                for (U32 i = 0; i < m_Size; i++)
                {
                    m_ArrayPtr[i].~T();
                }
            }
            Free_Z(m_ArrayPtr);
            m_ArrayPtr = NULL;
        }
    }

    void SetSize(int i_NewSize, const Bool i_ResizeOnlyIfGreater = FALSE) {
        S32 i;
        if (i_NewSize > m_Size) {
            if ((i_NewSize - m_Size > m_ReservedSize) || !i_ResizeOnlyIfGreater) {
                Realloc(i_NewSize);
                m_ReservedSize = 0;
            } else if ((i_NewSize - m_Size <= m_ReservedSize)) {
                m_ReservedSize -= i_NewSize - m_Size;
            }
            if (InitObject) {
                for (i = m_Size; i < i_NewSize; i++) {
                    new(&m_ArrayPtr[i]) T;
                }
            }
            m_Size = i_NewSize;
        } else if (i_NewSize < m_Size) {
            if (DeleteObject) {
                for (i = m_Size - 1; i >= i_NewSize; i--) {
                    m_ArrayPtr[i].~T();
                }
            }
            if (i_ResizeOnlyIfGreater) {
                m_ReservedSize += m_Size - i_NewSize;
                m_Size = i_NewSize;
            } else {
                Realloc(i_NewSize);
                m_Size = i_NewSize;
                m_ReservedSize = 0;
            }
        }
    }

    void SetReserve(S32 i_NewReservedSize) {
        if (((U32) i_NewReservedSize) < m_Size)
            SetSize(i_NewReservedSize);
        else {
            S32 l_NewReserved = i_NewReservedSize - m_Size;
            if (l_NewReserved > DYA_RSVSIZEMAX)
                l_NewReserved = DYA_RSVSIZEMAX;
            i_NewReservedSize = m_Size + l_NewReserved;
            Realloc(i_NewReservedSize);
            m_ReservedSize = l_NewReserved;
        }
    }
    
    T* GetArrayPtr() const {
        return m_ArrayPtr;
    }

    S32 GetSize() const {
        return m_Size;
    }
    
    S32 Add() {
        if (!m_ReservedSize) {
            m_ReservedSize = Granularity;
            Realloc(m_ReservedSize + m_Size);
        }
        if (InitObject)
            new(&m_ArrayPtr[m_Size]) T();
        m_Size++;
        m_ReservedSize--;
        return m_Size - 1;
    }

    S32 Add(const T& i_Ele) {
        if (!m_ReservedSize) {
            m_ReservedSize = Granularity;
            Realloc(m_ReservedSize + m_Size);
        }
        if (InitObject)
            new(&m_ArrayPtr[m_Size]) T(i_Ele);
        else
            m_ArrayPtr[m_Size] = i_Ele;
        m_Size++;
        m_ReservedSize--;
        return m_Size - 1;
    }

    void Empty()
    {
        SetSize(0,TRUE);	
    }

    void Flush()
    {
        SetSize(0);
    }

    void Minimize()
    {
        Realloc(m_Size);
        m_ReservedSize = 0;
    }

    T& Get(S32 i_Index) const
    {
        return m_ArrayPtr[i_Index];
    }

    T& operator[](S32 i_Index) const
    {
        return m_ArrayPtr[i_Index];
    }
    
    DynArray_Z<T, Granularity, DeleteObject, InitObject, Align>& operator=(const DynArray_Z<T, Granularity, DeleteObject, InitObject, Align>& i_Src) {
        Empty();
        SetReserve(i_Src.GetSize());
        for(S32 i = 0 ; i < i_Src.GetSize() ; ++i )
        {
            Add(i_Src[i]);
        }
        return *this;
    }

private:
    void Realloc(S32 i_NewNbElement) {
        if (i_NewNbElement) {
            if (m_ArrayPtr)
                m_ArrayPtr = (T*)ReallocL_Z(m_ArrayPtr, i_NewNbElement * sizeof(T), 0x137);
            else
                m_ArrayPtr = (T*)AllocAlignL_Z(i_NewNbElement * sizeof(T), 0x13D, Align);
        } else {
            if (m_ArrayPtr) {
                Free_Z(m_ArrayPtr);
                m_ArrayPtr = NULL;
            }
        }
    }

    U32 m_ReservedSize : DYA_RSVSIZEBITS,
        m_Size : DYA_SIZEBITS;
    T* m_ArrayPtr;
};

typedef	DynArray_Z<S32,32,FALSE,FALSE,4> S32DA;
typedef	DynArray_Z<S16,32,FALSE,FALSE,4> S16DA;
typedef	DynArray_Z<S8,32,FALSE,FALSE,4> S8DA;
typedef	DynArray_Z<U32,32,FALSE,FALSE,4> U32DA;
typedef	DynArray_Z<U16,32,FALSE,FALSE,4> U16DA;
typedef	DynArray_Z<U8,32,FALSE,FALSE,4> U8DA;
typedef	DynArray_Z<Bool,32,FALSE,FALSE,4> BoolDA;
typedef	DynArray_Z<Float,32,FALSE,FALSE,4> FloatDA;

#endif
