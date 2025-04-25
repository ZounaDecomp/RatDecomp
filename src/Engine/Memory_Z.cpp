#include "Memory_Z.h"
#include "Assert_Z.h"

extern Hi_MemoryManager_Z MemManager;
extern void s_free(void *i_Ptr);
extern void* s_malloc(U32 i_Size, U32 i_Align);
extern "C" S32 sprintf(const Char* i_Buf, const Char*  Format, ...);

void Hi_MemoryManager_Z::Shut() {
    MarkMem(0);
    int ret = ShowUnMarkedMem();
    if (ret == 1) {
        goto label;
    }
    
    ShowMostNbMalloc();
    label:
    if (ret != 1)
    ExceptionFonc_Z("NbLeak==1", "Memory_Z.cpp", 0x23, "Leaks Found", 0, 0, 0, 0, 0, NULL);
}

void* Hi_MemoryManager_Z::Alloc(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) {
    void* l_Result;
    Char l_Message[512];

    l_Result = s_malloc(i_Size, i_Align);
    if (!l_Result) {
        sprintf(l_Message, "Not enough mem; alloc: %dkb \"%s\"", i_Size >> 10, i_Comment);
        if (!l_Result) {
            ExceptionFonc_Z("mem", i_File, i_Line, l_Message, 0, 0, 0, 0, 0, NULL);
        }
    }
    *(U32*)(&m_Pad_0x0[0x14]) = *(U32*)(&m_Pad_0x0[0x14]) + 1;
    *(U32*)(&m_Pad_0x0[0x18]) = *(U32*)(&m_Pad_0x0[0x18]) + 1;
    return l_Result;
}

void Hi_MemoryManager_Z::Free(void* i_Ptr) {
    if (!i_Ptr) return;
    s_free(i_Ptr);
    *(U32*)(&m_Pad_0x0[0x14]) = *(U32*)(&m_Pad_0x0[0x14]) - 1;
}

void operator delete(void* i_Ptr) {
    MemManager.Free(i_Ptr);
}

void operator delete[](void* i_Ptr) {
    MemManager.Free(i_Ptr);
}

// $SABE: Added padding lines to make the line number in the ASSERT match



















void* operator new(U32 i_Size) {
    return MemManager.Alloc(i_Size, "Anonymous New", __FILE__, __LINE__, _ALLOCDEFAULTALIGN);
}

void* operator new(U32 i_Size, void* i_Ptr) {
    return i_Ptr;
}

void* operator new(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    return MemManager.Alloc(i_Size, i_Comment, i_File, i_Line, _ALLOCDEFAULTALIGN);
}

void* operator new[](U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line) {
    return MemManager.Alloc(i_Size, i_Comment, i_File, i_Line, _ALLOCDEFAULTALIGN);
}
