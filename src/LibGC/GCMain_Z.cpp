#include "GCMain_Z.h"
#include "Assert_Z.h"
#include "LowMemory_Z.h"
#include "GCConsole_Z.h"

static GCGlobals gData;
extern void OSInit();
extern void DVDInit();
extern void GetFlagsFromGame();
extern void MathInitTables();
extern Char * strcpy(Char *__dest,Char *__src);

extern MemoryManager_Z MemManager;
extern void exit(int __status);

void InitProgram() {
    OSInit();
    ExceptionHandler();
    MemManager.Init();
    *(S32*)(&gData.m_Pad_0x14[0x794]) = 0;
    GetFlagsFromGame();
    gData.Cons = New_Z GCConsole_Z;
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
