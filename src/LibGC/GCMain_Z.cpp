#include "GCMain_Z.h"
#include "Assert_Z.h"
#include "LowMemory_Z.h"
#include "GCConsole_Z.h"

GCGlobals gData;

extern void OSInit();
extern void DVDInit();
extern void GetFlagsFromGame();
extern void MathInitTables();
extern Char * strcpy(Char *__dest,Char *__src);
extern "C" void OSReport(const Char* __msg, ...);
extern "C" void __start(void);

extern "C" void exit(S32 __status);
extern "C" void* OSGetArenaHi(void);
extern "C" void* OSGetArenaLo(void);

extern "C" void* _stack_end;
extern "C" void* _stack_addr;
extern "C" void* _db_stack_end;
extern "C" void* _db_stack_addr;


// $SABE: Not fully matching yet, need to fix
void PrintMemoryStatus(Char* i_Comment)
{
    void* l_ArenaLo = OSGetArenaLo();
    void* l_ArenaHi = OSGetArenaHi();
    void** l_StackEnd = &_stack_end;
    void** l_StackAddr = &_stack_addr;
    void** l_DbStackAddr = &_stack_addr;
    void** l_DbStackEnd = &_db_stack_end;
    U32 l_FreeMem = MemManager.GetFreeMem();
    U32 l_HeapSize = MemManager.GetHeapSize();
    U32 l_SizeInKo = ((U32)l_ArenaHi - (U32)l_ArenaLo) >> 10;
    void* l_End = (void*)0x803c317e;

    OSReport("\n\n");
    OSReport("> %s :\n", i_Comment ? i_Comment : "Memory Status");
    OSReport(">              start       end         size         usage\n");
    OSReport(">     ELF      0x%08x  0x%08x  %08d ko\n", (U32)&__start, (U32)l_End, 0xefc);
    OSReport(">     STACK    0x%08x  0x%08x  %08d ko\n", l_StackEnd, l_StackAddr, 0x100);
    OSReport(">     DBSTACK  0x%08x  0x%08x  %08d ko\n", l_DbStackEnd, &l_DbStackAddr, 0x40);
    OSReport(">     HEAP     0x%08x  0x%08x  %08d ko  %.2f mo\n", l_ArenaLo, l_ArenaHi, l_SizeInKo, l_HeapSize);
    OSReport("\n\n");
    return;
}

void InitProgram() {
    OSInit();
    ExceptionHandler();
    MemManager.Init();
    *(S32*)(&gData.m_Pad_0x14[0x794]) = 0;
    GetFlagsFromGame();
    gData.Cons = NewL_Z(283) GCConsole_Z;
    if (!(gData.Cons->InitConsole() & 0xFF)) {
        exit(0x14);
    }
    gData.Cons->Init();
    gData.Cons->SetVar("_GC");
    gData.Cons->SetVar("_FORCEBFREAD");
    MathInitTables();
    strcpy((Char*)(&gData.m_Pad_0x14[0x7D4]),".\\");
    DVDInit();
    return;
}
