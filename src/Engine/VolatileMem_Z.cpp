#include "VolatileMem_Z.h"

void VolatileMgr_Z::Minimize() {
    return;
}

void VolatileMgr_Z::SetState(int i_ArrayOffset, S32 i_State) {
    S16 l_PrevBlockToUpdate;
    S16 l_NextBlockToUpdate;
    VolatileBlock& l_VolBlock = m_VolatileBlockArray[i_ArrayOffset];
    if (l_VolBlock.m_State != i_State) {
        switch (l_VolBlock.m_State) {
            case 0: {
                l_NextBlockToUpdate = l_VolBlock.m_NextBlockToUpdate;
                if (l_NextBlockToUpdate >=  0) {
                    m_VolatileBlockArray[l_NextBlockToUpdate].m_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
                }
                l_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
                if (l_PrevBlockToUpdate >= 0) {
                    m_VolatileBlockArray[l_PrevBlockToUpdate].m_NextBlockToUpdate = l_VolBlock.m_NextBlockToUpdate;
                }
                else {
                    m_FirstFreeBlock = l_VolBlock.m_NextBlockToUpdate;
                }
                break;
            }
            case 1: {
                l_NextBlockToUpdate = l_VolBlock.m_NextBlockToUpdate;
                if (l_NextBlockToUpdate >= 0) {
                    m_VolatileBlockArray[l_NextBlockToUpdate].m_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
                }
                l_PrevBlockToUpdate = l_VolBlock.m_PrevBlockToUpdate;
                if (l_PrevBlockToUpdate >= 0) {
                    m_VolatileBlockArray[l_PrevBlockToUpdate].m_NextBlockToUpdate = l_VolBlock.m_NextBlockToUpdate;
                }
                else {
                    m_FirstAllocatedBlock = l_VolBlock.m_NextBlockToUpdate;
                }
                break;
            }
        }
        l_VolBlock.m_State = i_State;
        switch (l_VolBlock.m_State) {
            case 0: {
                VolatileBlock& l_VolBlock2 = m_VolatileBlockArray[i_ArrayOffset];
                l_VolBlock2.m_NextBlockToUpdate = m_FirstFreeBlock;
                l_VolBlock2.m_PrevBlockToUpdate = -1;
                if (m_FirstFreeBlock >= 0) {
                    m_VolatileBlockArray[m_FirstFreeBlock].m_PrevBlockToUpdate = i_State;
                }
                m_FirstFreeBlock = i_State;
                break;
            }
            case 1: {
                VolatileBlock& l_VolBlock2 = m_VolatileBlockArray[i_ArrayOffset];
                l_VolBlock2.m_NextBlockToUpdate = m_FirstAllocatedBlock;
                l_VolBlock2.m_PrevBlockToUpdate = -1;
                if (m_FirstAllocatedBlock >= 0) {
                    m_VolatileBlockArray[m_FirstAllocatedBlock].m_PrevBlockToUpdate = i_State;
                }
                m_FirstAllocatedBlock = i_State;
                break;
            }
        }
    }
}
VolatileMgr_Z::VolatileMgr_Z() {
    m_FirstFreeBlock = -1;
    m_FirstAllocatedBlock = -1;
    for (int i = 0; i < 0x500; i++) {
        S32 l_BlockId = m_VolatileBlockArray.Add();
        VolatileBlock& l_VolBlock = m_VolatileBlockArray[l_BlockId];
        l_VolBlock.m_Pointer = NULL;
        l_VolBlock.m_Key = 1;
        l_VolBlock.m_State = -1;
        SetState(l_BlockId,0);
    }
}


void VolatileMgr_Z::FreeVolatileBlock_Z(U32 i_BlockIdx) {
    if (i_BlockIdx < m_VolatileBlockArray.GetSize()) {
        int l_BlockIdx = i_BlockIdx;
        VolatileBlock& l_VolBlock = m_VolatileBlockArray[l_BlockIdx];
        if (l_VolBlock.m_Pointer) 
        {
            Free_Z(l_VolBlock.m_Pointer);
            l_VolBlock.m_Pointer = NULL;
        }
        l_VolBlock.m_Zero = 0;
        l_VolBlock.m_Key++;
        l_VolBlock.m_Key = l_VolBlock.m_Key & 0xFFFF;
        if (!l_VolBlock.m_Key) {
            l_VolBlock.m_Key += 1;
        }
        SetState(i_BlockIdx, 0);

    }
}
