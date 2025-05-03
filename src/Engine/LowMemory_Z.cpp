#include "LowMemory_Z.h"
#include "Memory_Z.h"
extern "C" void memset(void* dest, S32 c, S32 n);
extern "C" void* OSGetArenaLo();
extern "C" void* OSGetArenaHi();





extern "C" void* __sys_alloc(S32 i_Size) 
{ 
    return Z_Alloc(i_Size, "Anonymous Alloc", __FILE__, __LINE__, 0x20); 
};

extern "C" void __sys_free(void* i_Ptr) 
{ 
    Z_Free(i_Ptr); 
};


void MemoryManager_Z::Init() {
    m_HeapBase = OSGetArenaLo();
    m_HeapEnd = OSGetArenaHi();
    m_HeapEnd = (void*)((char*)m_HeapEnd - 0x10000 + 0x600);
    memset(m_HeapBase, 0xE, (char*)m_HeapEnd - (char*)m_HeapBase);
    Hi_MemoryManager_Z::Init();
}



MemoryManager_Z MemManager;
