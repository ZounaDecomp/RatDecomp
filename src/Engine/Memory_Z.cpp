#include "Memory_Z.h"
#include "Assert_Z.h"
#include "Program_Z.h"

extern void s_free(void* i_Ptr);
extern void* s_malloc(U32 i_Size, U32 i_Align); extern void* s_realloc(void* i_Ptr, U32 i_Size);
extern void s_Init(void* i_HeapBase, U32 i_HeapSize); void s_ShowMostNbMalloc(void);
void* s_findalloc(void* i_RangeStart, void* i_RangeEnd); U32 s_getnbfindalloc(void* i_RangeStart, void* i_RangeEnd); void* s_getfindalloc(S32 i_AllocId, Char* l_ResultDescription, void* i_RangeStart, void* i_RangeEnd);
extern "C" S32 sprintf(const Char* i_Buf, const Char*  i_Format, ...); extern void s_VerifyMem(); extern void* s_malloc_end(U32 i_Size, U32 i_Align);

void Hi_MemoryManager_Z::Init() {
    m_FreeMemCached = (U32)m_HeapEnd - (U32)m_HeapBase;
    s_Init(m_HeapBase,m_FreeMemCached);
    m_NbAlloc = 0;
    m_FrameNbAlloc = 0;
    m_FreeMemCached = s_GetFreeMem();
    m_MaxMemUsed = 0;
    m_AllocTimer = 0.0f;
    return;
}

void Hi_MemoryManager_Z::Shut() {
    MarkMem(0);
    S32 NbLeak = ShowUnMarkedMem();
    if (NbLeak != 1) {
        ShowMostNbMalloc();
    }
    ASSERTL_Z(NbLeak==1, "Leaks Found", 35);
}

Hi_MemoryManager_Z::Hi_MemoryManager_Z() {
    m_HeapEnd = NULL;
    m_HeapBase = NULL;
}

Hi_MemoryManager_Z::~Hi_MemoryManager_Z() {
}

void Hi_MemoryManager_Z::VerifyMem() {
    s_VerifyMem();
}

void* Hi_MemoryManager_Z::Alloc(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    void* mem;
    Char l_Message[512];

    mem = s_malloc(i_Size, i_Align);
    if (!mem) {
        sprintf(l_Message, "Not enough mem; alloc: %dkb \"%s\"", i_Size >> 10, i_Comment);
        ASSERTL_Z(mem, l_Message, 73);
    }
    m_NbAlloc++;
    m_FrameNbAlloc++;
    return mem;
}

void* Hi_MemoryManager_Z::AllocEnd(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    void* mem;
    mem = s_malloc_end(i_Size, i_Align);
    if (!mem) {
        return mem;
    }
    m_NbAlloc++;
    m_FrameNbAlloc++;
    return mem;
}

void* Hi_MemoryManager_Z::FindAlloc(void* i_RangeStart, void* i_RangeEnd) {
    return s_findalloc(i_RangeStart, i_RangeEnd);
}

U32 Hi_MemoryManager_Z::FindAllocNb(void* i_RangeStart, void* i_RangeEnd) {
    return s_getnbfindalloc(i_RangeStart, i_RangeEnd);
}

void* Hi_MemoryManager_Z::FindAllocID(S32 i_AllocID, Char* i_ResultDescription, void* i_RangeStart, void* i_RangeEnd) {
    return s_getfindalloc(i_AllocID, i_ResultDescription, i_RangeStart, i_RangeEnd);
}

void* Hi_MemoryManager_Z::Realloc(void* i_Ptr, U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    Char l_Message[512];
    S32 something;

    void* mem = s_realloc(i_Ptr, i_Size);
    if (mem == NULL) {
        sprintf(l_Message, "Not enough mem; re-alloc: %dkb", i_Size >> 10);
        ASSERTL_Z(mem, l_Message, 179);
    }
    m_FrameNbAlloc++;
    return mem;
}

void Hi_MemoryManager_Z::Free(void* i_Ptr) {
    if (!i_Ptr) return;
    s_free(i_Ptr);
    m_NbAlloc--;
}

U32 Hi_MemoryManager_Z::Update(Float i_DeltaTime) {   
    U32 l_DidReset;

    m_AllocTimer = m_AllocTimer + i_DeltaTime;
    if (m_AllocTimer > 2.0f) {
        if (m_MaxMemUsed < GetMemUsed()) {
            m_MaxMemUsed = GetMemUsed();
        }
        l_DidReset = 1;
        m_AllocTimer = 0.0f;
        m_FrameNbAlloc = 0;
    }
    else {
        l_DidReset = 0;
    }
    return l_DidReset;
}

void Hi_MemoryManager_Z::PrintStatus() {
    GetMemUsed();
    GetMemUsed();
    GetFreeMem();
    GetFreeMem();
    GetHeapSize();
    GetHeapSize();
    s_ShowMostNbMalloc();
}

U32 MemoryGraphColor() {
    S32 l_NumParam = gData.Cons->GetNbParam();
    if (l_NumParam >= 2) {
        return TRUE;
    }
    return FALSE;
}

void Z_Verify() {
    s_VerifyMem();
}

void* operator new(U32 i_Size, void* i_Ptr) {
    return i_Ptr;
}

void* operator new(U32 i_Size) {
    return MemManager.Alloc(i_Size, "Anonymous New", "No File", 0, _ALLOCDEFAULTALIGN);
}

void operator delete(void* i_Ptr) {
    MemManager.Free(i_Ptr);
}

void* operator new[](U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    return MemManager.Alloc(i_Size, i_Comment, i_File, i_Line, _ALLOCDEFAULTALIGN);
}

void* operator new(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    return MemManager.Alloc(i_Size, i_Comment, i_File, i_Line, _ALLOCDEFAULTALIGN);
}

void operator delete[](void* i_Ptr) {
    MemManager.Free(i_Ptr);
}

void* Z_Alloc(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    return MemManager.Alloc(i_Size, i_Comment, i_File, i_Line, i_Align);
}

void* Z_AllocEnd(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    return MemManager.AllocEnd(i_Size, i_Comment, i_File, i_Line, i_Align);
}

typedef void* (*Memory_Manager__AllocContiguous)(MemoryManager_Z*,U32,const Char*,const Char*,S32,U32);

void* Z_AllocContiguous(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    MemoryManager_Z* l_MemMgr = &MemManager;
    void* result = l_MemMgr->Alloc(i_Size, i_Comment, i_File, i_Line, i_Align);
    return result;
}

void* Z_Realloc(void* i_Ptr, U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    return MemManager.Realloc(i_Ptr, i_Size, i_Comment, i_File, i_Line);
}

void Z_Free(void* i_Ptr) {
    return MemManager.Free(i_Ptr);
}

void Z_FreeContiguous(void* i_Ptr) {
    MemoryManager_Z* l_MemMgr = &MemManager;
    l_MemMgr->Free(i_Ptr);
}

void Hi_MemoryManager_Z::SetCallStackPtrs(U32* a1, S32 a2) {
    memset(a1,0,0x20);
}
