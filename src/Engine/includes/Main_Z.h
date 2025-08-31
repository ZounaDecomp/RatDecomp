#ifndef _MAIN_Z_H_
#define _MAIN_Z_H_
#include "ManipulatorManager_Z.h"
#include "Types_Z.h"
#include "ClassManager_Z.h"
#include "Timer_Z.h"
#include "Console_Z.h"
#include "AnimationManager_Z.h"
#include "XRamManager_Z.h"

Extern_Z Char* strcpy(Char* __dest, Char* __src);
Extern_Z "C" void memset(void* __s, S32 __c, U32 __n);
class GCConsole_Z;
class Renderer_Z;
class GameManager_Z;

class Globals {
public:
    virtual ~Globals() { };
    virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
    virtual void Minimize();
    virtual void GetDate();
    void InitTime();

    U8 m_Pad_0x0[0x4];
    Console_Z* Cons;
    Renderer_Z* MainRdr;
    ClassManager_Z* ClassMgr;
    U8 m_Pad_0x14[0x1C];
    ManipulatorManager_Z* ManipMgr;
    GameManager_Z* GameMgr;
    U8 m_Pad_0x34[0x4];
    AnimationManager_Z* AnimMgr;
    U8 m_Pad_0x40[0x44];
    XRamManager_Z* XRamMgr;
    U8 m_Pad_0x88[0x758];

    // TODO: Properly define members for all this so we don't gotta move stuff around
    inline Globals() {
        // m_Pad_0x14[137] = 0;
        // m_Pad_0x14[393] = 0;
        // m_Pad_0x14[649] = 0;
        // m_Pad_0x14[905] = 0;
        // m_Pad_0x14[1161] = 0;
        // m_Pad_0x14[1417] = 0;
        // m_Pad_0x14[1673] = 0;
        // *(S16*)(&m_Pad_0x14[1980]) = -1;
        // *(S16*)(&m_Pad_0x14[1982]) = 0;
        // *(S16*)(&m_Pad_0x14[1984]) = 1;
        // *(S16*)(&m_Pad_0x14[1990]) = 8;
        // *(S16*)(&m_Pad_0x14[1986]) = 60;
        // *(S16*)(&m_Pad_0x14[1988]) = 480;
        // memset(&m_Pad_0x0, 0, 132);
        // m_Pad_0x14[1968] = 1;
        // *(Float*)(&m_Pad_0x14[1976]) = 0.0f;
        // *(Float*)(&m_Pad_0x14[1972]) = 0.0f;
        // strcpy((Char*)&m_Pad_0x14[1161], ".\\");
        // strcpy((Char*)&m_Pad_0x14[1673], "Ace");
        // *(S32*)(&m_Pad_0x14[1956]) = 0;
        // *(S32*)(&m_Pad_0x14[1944]) = 0;
        // *(S32*)(&m_Pad_0x14[1952]) = 0;
        // *(S32*)(&m_Pad_0x14[1948]) = 0;
        // m_Pad_0x14[120] = 0;
        // m_Pad_0x14[121] = 0;
        // m_Pad_0x14[136] = 0;
        // m_Pad_0x14[123] = 0;
        // m_Pad_0x14[122] = 0;
        // *(S32*)(&m_Pad_0x14[84]) = 0;
        // *(S32*)(&m_Pad_0x14[80]) = 0;
        // *(S32*)(&m_Pad_0x14[108]) = 0;
        // *(Float*)(&m_Pad_0x14[1960]) = 0.0;
        // m_Pad_0x14[1932] = 0;
        // *(S32*)(&m_Pad_0x14[1940]) = 0;
        // *(Float*)(&m_Pad_0x14[132]) = 1.0f;
        // *(S32*)(&m_Pad_0x14[1964]) = 0;
    }
};

#endif
