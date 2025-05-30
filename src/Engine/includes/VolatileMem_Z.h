#ifndef _VOLATILEMEM_Z_H_
#define _VOLATILEMEM_Z_H_
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
    void Minimize();
    void AddIndex(S32& i_Block, int i_ArrayOffset) {
        VolatileBlock& l_VolBlock = m_VolatileBlockArray[i_ArrayOffset];
        l_VolBlock.m_NextBlockToUpdate = i_Block;
        l_VolBlock.m_PrevBlockToUpdate = -1;
        if (i_Block >= 0) {
            m_VolatileBlockArray[i_Block].m_PrevBlockToUpdate = i_ArrayOffset;
        }
        i_Block = i_ArrayOffset;
    }

    void RemoveIndex(S32& i_Block, int i_ArrayOffset) {
        S16 l_PrevBlockToUpdate;
        S16 l_NextBlockToUpdate;
        VolatileBlock& l_VolBlock = m_VolatileBlockArray[i_ArrayOffset];
        if (l_VolBlock.m_NextBlockToUpdate >= 0) {
            m_VolatileBlockArray[l_VolBlock.m_NextBlockToUpdate].m_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
        }
        l_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
        if (l_PrevBlockToUpdate >= 0) {
            m_VolatileBlockArray[l_PrevBlockToUpdate].m_NextBlockToUpdate = l_VolBlock.m_NextBlockToUpdate;
        }
        else {
            i_Block = l_VolBlock.m_NextBlockToUpdate;
        }
    }
    void SetState(int i_ArrayOffset, S32 i_State);
    VolatileMgr_Z();
    void UpdateVolatileBlocks(Float);
    void FreeVolatileBlock_Z(U32 i_BlockIdx);

private:
    DynArray_Z<VolatileBlock, 8, FALSE> m_VolatileBlockArray;
    S32 m_FirstFreeBlock;
    S32 m_FirstAllocatedBlock;
};

#endif
