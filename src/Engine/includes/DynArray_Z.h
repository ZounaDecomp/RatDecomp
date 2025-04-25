#ifndef _DYNARRAY_Z_H_
#define _DYNARRAY_Z_H_
#include "Types_Z.h"


#define	DYA_SIZEBITS 18
#define	DYA_RSVSIZEBITS (32-DYA_SIZEBITS)
#define	DYA_SIZEMAX ((1<<DYA_SIZEBITS)-1)
#define	DYA_RSVSIZEMAX ((1<<DYA_RSVSIZEBITS)-1)

template<class T, S32 Granularity = 8, Bool DeleteObject = TRUE, Bool InitObject = TRUE, S32 Align = _ALLOCDEFAULTALIGN>
class DynArray_Z {
    U32 m_ReservedSize : DYA_RSVSIZEBITS,
        m_Size : DYA_SIZEBITS;
	T* m_ArrayPtr;

public:
    DynArray_Z()
	{
		m_Size = 0;
		m_ReservedSize = 0;
		m_ArrayPtr = NULL;
	}
};

#endif
