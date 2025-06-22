#include "ABC_Behavior.h"
#include "Memory_Z.h"
Extern_Z "C" void memcpy(void* dst, const void* src, int n);

ABC_Behavior::ABC_Behavior() {
    m_LocalDataSize = 0;
    m_LocalData = NULL;
    Reset();
}

void ABC_Behavior::Reset() {
    m_BehaviorFlags &= 0xFFF8;
    m_BehaviorState = 0;
    if (m_LocalDataSize != 0) {
        Delete_Z m_LocalData;
    }
    m_LocalData = NULL;
    m_LocalDataSize = 0;
    m_Next = NULL;
    m_CategoryListHead = NULL;
}

ABC_Behavior::~ABC_Behavior() {
    if (m_LocalDataSize != 0) {
        Delete_Z m_LocalData;
    }
}

void ABC_Behavior::SetLocalDataSize(S32 i_Size) {
    if (i_Size) {
        m_LocalDataSize = i_Size;
        //TODO: WRITE MACRO FOR THIS
        m_LocalData = operator new[](m_LocalDataSize, "Anonymous New", __FILE__, 40);
    }
}

void ABC_Behavior::LoadLocalVariables(void* i_Data) {
    if (!i_Data)
        return;
    if (m_LocalDataSize)
        memcpy(i_Data, m_LocalData, m_LocalDataSize);
}

void ABC_Behavior::StoreLocalVariables(const void* i_Data) {
    if (!i_Data)
        return;
    if (m_LocalDataSize)
        memcpy(m_LocalData, i_Data, m_LocalDataSize);
}

//cannot do rest without abc script manager and abc agent stuff
