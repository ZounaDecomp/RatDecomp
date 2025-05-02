#ifndef _MEMORY_Z_H_
#define _MEMORY_Z_H_
#include "Types_Z.h"

extern U32 s_GetFreeMem(void);
extern U32 s_GetAllocatedMem(void);
extern U32 s_GetNbFreeBlocks(void);
extern U32 s_GetLargestFree(void);
extern void s_MarkMem(U32 a1);
extern U32 s_ShowUnMarkedMem(void);
extern void s_ShowMostNbMalloc(void);
class Hi_MemoryManager_Z {
public:
    void* m_HeapBase;
    void* m_HeapEnd;
    U32 m_FreeMemCached;
    U32 m_MaxMemUsed;
    U8 m_Pad_0x10[0x4];
    U32 m_NbAlloc;
    U32 m_FrameNbAlloc;
    Float m_AllocTimer;

    Hi_MemoryManager_Z();
    ~Hi_MemoryManager_Z();

    virtual void Init();
    virtual void Shut();
    virtual void* Alloc(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
    virtual void* AllocEnd(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
    virtual void* Realloc(void* i_Ptr, U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line);
    virtual void Free(void* i_Ptr);
    virtual void* FindAlloc(void* i_RangeStart, void* i_RangeEnd);
    virtual U32 FindAllocNb(void* i_RangeStart, void* i_RangeEnd);
    virtual void* FindAllocID(S32 i_AllocId, Char* i_ResultDescription, void* i_RangeStart, void* i_RangeEnd);
    virtual void* AllocContiguous(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align) 
    { 
        return Alloc(i_Size, i_Comment, i_File, i_Line, i_Align); 
    };
    virtual void FreeContiguous(void* i_Ptr)
    { 
        Free(i_Ptr); 
    };
    virtual U32 Update(Float i_DeltaTime);
    virtual void PrintStatus();
    virtual U32 GetHeapSize()
    {
        return (U32)m_HeapEnd - (U32)m_HeapBase;
    };
    virtual void* GetHeapBase()
    {
        return m_HeapBase;
    };
    virtual U32 GetNbAlloc()
    {
        return m_NbAlloc;
    };
    virtual U32 GetAllocatedMem()
    {
        return s_GetAllocatedMem();
    };
    virtual U32 GetFreeMem() {
        m_FreeMemCached = s_GetFreeMem();
        return m_FreeMemCached;
    };
    virtual U32 GetFragments()
    {
        return s_GetNbFreeBlocks();
    };
    virtual U32 GetLargestFree()
    {
        return s_GetLargestFree();
    };
    virtual U32 GetFrameNbAlloc()
    {
        return m_FrameNbAlloc;
    };
    virtual U32 GetMemUsed()
    {
        return GetHeapSize() - GetFreeMem();
    };
    virtual U32 GetMaxMemUsed()
    {
        return m_MaxMemUsed;
    };
    virtual void MarkMem(U32 a1)
    {
        s_MarkMem(a1);
    };
    virtual U32 ShowUnMarkedMem()
    {
        return s_ShowUnMarkedMem();
    };
    virtual U32 ShowMostNbMalloc()
    {
        s_ShowMostNbMalloc();
    };
    virtual void VerifyMem();
    virtual void SetCallStackPtrs(U32* a1, S32 a2);
    //virtual ~Hi_MemoryManager_Z();
};

void Z_Verify();
U32 MemoryGraphColor();

void operator delete(void* i_Ptr);
void operator delete[](void* i_Ptr);

void* operator new(U32 i_Size);
void* operator new(U32 i_Size, void* i_Ptr);
void* operator new(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line);
void* operator new[](U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line);

void* Z_Alloc(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
void* Z_AllocEnd(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
void* Z_AllocContiguous(U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line, U32 i_Align);
void* Z_Realloc(void* i_Ptr, U32 i_Size, const Char* i_Comment, const Char* i_File, S32 i_Line);
void Z_Free(void* i_Ptr);
void Z_FreeContiguous(void* i_Ptr);

#undef New_Z
#define New_Z new("Anonymous New", __FILE__, __LINE__)

#undef NewC_Z
#define NewC_Z(Comment) new(Comment, __FILE__, __LINE__)

#undef Delete_Z
#define Delete_Z delete

#endif
