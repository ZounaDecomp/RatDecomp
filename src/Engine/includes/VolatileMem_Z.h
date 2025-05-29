#ifndef _VOLATILE_MEM_Z_H_
#define _VOLATILE_MEM_Z_H_
#include "DynArray_Z.h"
#include "Types_Z.h"

struct VolatileBlock {
    void* m_Pointer;
    U32 m_Key;
    S32 m_Zero;
    Float m_TimeToFree;
    Float m_Timer;
    S16 m_NextBlockToUpdate;
    S16 m_PrevBlockToUpdate;
    S16 m_State;
};

class VolatileMgr_Z {
    VolatileMgr_Z();
    void Minimize();
    void SetState(int i_ArrayOffset, S32 i_State);
    void UpdateVolatileBlocks(Float);
    void FreeVolatileBlock_Z(U32 i_BlockIdx);
private:
    DynArray_Z<VolatileBlock, 8, FALSE> m_VolatileBlockArray;
    S32 m_FirstFreeBlock;
    S32 m_FirstAllocatedBlock;
};

#endif
