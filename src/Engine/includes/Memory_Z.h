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
    virtual void ShowMostNbMalloc()
    {
        s_ShowMostNbMalloc();
    };
    virtual void VerifyMem();
    virtual void SetCallStackPtrs(U32* a1, S32 a2);
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

#define New_Z new("Anonymous New", __FILE__, __LINE__)
//#define NewF_Z new(__FUNCTION__, __FILE__, __LINE__)
#define NewC_Z(Comment) new(Comment, __FILE__, __LINE__)
#define NewL_Z(Line) new("Anonymous New", __FILE__, Line)
#define NewCL_Z(Comment, Line) new(Comment, __FILE__, Line)
//#define NewFL_Z(Line) new(__FUNCTION__, __FILE__, Line)

#undef Delete_Z
#define Delete_Z delete

#define Alloc_Z(Size) Z_Alloc(Size, "Anonymous Alloc", __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
//#define AllocF_Z(Size) Z_Alloc(Size, __FUNCTION__, __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
#define AllocC_Z(Size, Comment) Z_Alloc(Size, Comment, __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
#define AllocL_Z(Size, Line) Z_Alloc(Size, "Anonymous Alloc", __FILE__, Line, _ALLOCDEFAULTALIGN)
#define AllocCL_Z(Size, Comment, Line) Z_Alloc(Size, Comment, __FILE__, Line, _ALLOCDEFAULTALIGN)
//#define AllocFL_Z(Size, Line) Z_Alloc(Size, __FUNCTION__, __FILE__, Line, _ALLOCDEFAULTALIGN)

#define AllocContiguous_Z(Size) Z_AllocContiguous(Size, "Anonymous Alloc", __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
//#define AllocContiguousF_Z(Size) Z_AllocContiguous(Size, __FUNCTION__, __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
#define AllocContiguousC_Z(Size, Comment) Z_AllocContiguous(Size, Comment, __FILE__, __LINE__, _ALLOCDEFAULTALIGN)
#define AllocContiguousL_Z(Size, Line) Z_AllocContiguous(Size, "Anonymous Alloc", __FILE__, Line, _ALLOCDEFAULTALIGN)
#define AllocContiguousCL_Z(Size, Comment, Line) Z_AllocContiguous(Size, Comment, __FILE__, Line, _ALLOCDEFAULTALIGN)
//#define AllocContiguousFL_Z(Size, Line) Z_AllocContiguous(Size, __FUNCTION__, __FILE__, Line, _ALLOCDEFAULTALIGN)

#define Realloc_Z(Ptr, Size) Z_Realloc(Ptr, Size, "Anonymous Alloc", __FILE__, __LINE__)
//#define ReallocF_Z(Ptr, Size) Z_Realloc(Ptr, Size, __FUNCTION__, __FILE__, __LINE__)
#define ReallocC_Z(Ptr, Size, Comment) Z_Realloc(Ptr, Size, Comment, __FILE__, __LINE__)
#define ReallocL_Z(Ptr, Size, Line) Z_Realloc(Ptr, Size, "Anonymous Alloc", __FILE__, Line)
#define ReallocCL_Z(Ptr, Size, Comment, Line) Z_Realloc(Ptr, Size, Comment, __FILE__, Line)
//#define ReallocFL_Z(Ptr, Size, Line) Z_Realloc(Ptr, Size, __FUNCTION__, __FILE__, Line)

#define Free_Z(Ptr) Z_Free(Ptr)
#define FreeContiguous_Z(Ptr) Z_FreeContiguous(Ptr)

#define AllocAlign_Z(Size, Align) Z_Alloc(Size, "Anonymous Alloc", __FILE__, __LINE__, Align)
//#define AllocAlignF_Z(Size, Align) Z_Alloc(Size, __FUNCTION__, __FILE__, __LINE__, Align)
#define AllocAlignC_Z(Size, Align, Comment) Z_Alloc(Size, Comment, __FILE__, __LINE__, Align)
#define AllocAlignL_Z(Size, Align, Line) Z_Alloc(Size, "Anonymous Alloc", __FILE__, Line, Align)
#define AllocAlignCL_Z(Size, Align, Comment, Line) Z_Alloc(Size, Comment, __FILE__, Line, Align)
//#define AllocAlignFL_Z(Size, Align, Line) Z_Alloc(Size, __FUNCTION__, __FILE__, Line, Align)

#define AllocContiguousAlign_Z(Size, Align) Z_AllocContiguous(Size, "Anonymous Alloc", __FILE__, __LINE__, Align)
//#define AllocContiguousAlignF_Z(Size, Align) Z_AllocContiguous(Size, __FUNCTION__, __FILE__, __LINE__, Align)
#define AllocContiguousAlignC_Z(Size, Align, Comment) Z_AllocContiguous(Size, Comment, __FILE__, __LINE__, Align)
#define AllocContiguousAlignL_Z(Size, Align, Line) Z_AllocContiguous(Size, "Anonymous Alloc", __FILE__, Line, Align)
#define AllocContiguousAlignCL_Z(Size, Align, Comment, Line) Z_AllocContiguous(Size, Comment, __FILE__, Line, Align)
//#define AllocContiguousAlignFL_Z(Size, Align, Line) Z_AllocContiguous(Size, __FUNCTION__, __FILE__, Line, Align)

#endif
