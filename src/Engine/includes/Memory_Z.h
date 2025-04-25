#ifndef _MEMORY_Z_H_
#define _MEMORY_Z_H_
#include "Types_Z.h"

class Hi_MemoryManager_Z {
public:
    U8 m_Pad_0x0[0x20];

    Hi_MemoryManager_Z();

    virtual void Init();
    virtual void Shut();
    virtual void* Alloc(U32 i_Size, Char* i_Comment, Char* i_File, S32 i_Line, U32 i_Align);
    virtual void* AllocEnd(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
    virtual void* Realloc(void* i_Ptr, U32 i_Size, Char* i_Comment, Char* i_File, S32 i_Line);
    virtual void Free(void* i_Ptr);
    virtual U32 FindAlloc(void* a1, void* a2);
    virtual U32 FindAllocNb(void* a1, void* a2);
    virtual U32 FindAllocID(S32 a1, Char* a2, void* a3, void* a4);
    virtual void* AllocContiguous(U32 a1, const Char* a2, const Char* a3, S32 a4, U32 a5);
    virtual void FreeContiguous(void* a1);
    virtual U32 Update(Float a1);
    virtual void PrintStatus();
    virtual U32 GetHeapSize();
    virtual U32 GetHeapBase();
    virtual U32 GetNbAlloc();
    virtual U32 GetAllocatedMem();
    virtual U32 GetFreeMem();
    virtual U32 GetFragments();
    virtual U32 GetLargestFree();
    virtual U32 GetFrameNbAlloc();
    virtual U32 GetMemUsed();
    virtual U32 GetMaxMemUsed();
    virtual void MarkMem(U32 a1);
    virtual U32 ShowUnMarkedMem();
    virtual U32 ShowMostNbMalloc();
    virtual void VerifyMem();
    virtual void SetCallStackPtrs(U32* a1, S32 a2);
    virtual ~Hi_MemoryManager_Z();
};

void operator delete(void* i_Ptr);
void operator delete[](void* i_Ptr);

void* operator new(U32 i_Size);
void* operator new(U32 i_Size, void* i_Ptr);
void* operator new(U32 i_Size, Char* i_Comment, Char* i_File, S32 i_Line);
void* operator new[](U32 i_Size, Char* i_Comment, Char* i_File, S32 i_Line);

#undef New_Z
#define New_Z new("Anonymous New", __FILE__, __LINE__)

#undef NewC_Z
#define NewC_Z(Comment) new(Comment, __FILE__, __LINE__)

#undef Delete_Z
#define Delete_Z delete

#endif
