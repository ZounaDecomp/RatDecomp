#ifndef _MAIN_Z_H_
#define _MAIN_Z_H_
#include "Types_Z.h"
#include "Handle_Z.h"

extern Char * strcpy(Char *__dest,Char *__src);
extern "C" void * memset(void *__s,S32 __c,U32 __n);
class GCConsole_Z;

class Globals {
public:
    virtual ~Globals() {};
    virtual U32 GetMgrSize(Name_Z *l_Name, S32 *a1, S32 *a2);
    virtual void Minimize();
    virtual void GetDate();
    void InitTime();

    U8 m_Pad_0x0[0x4];
    GCConsole_Z* Cons;
    U8 m_Pad_0xc[0x4]; // GCRenderer_Z
    HandleManager_Z* ClassMgr; // Actually is ClassManager_Z
    U8 m_Pad_0x14[0x7CC];

    inline Globals() {
        m_Pad_0x14[137] = 0;
        m_Pad_0x14[393] = 0;
        m_Pad_0x14[649] = 0;
        m_Pad_0x14[905] = 0;
        m_Pad_0x14[1161] = 0;
        m_Pad_0x14[1417] = 0;
        m_Pad_0x14[1673] = 0;
        *(S16*)(&m_Pad_0x14[1980]) = -1;
        *(S16*)(&m_Pad_0x14[1982]) = 0;
        *(S16*)(&m_Pad_0x14[1984]) = 1;
        *(S16*)(&m_Pad_0x14[1990]) = 8;
        *(S16*)(&m_Pad_0x14[1986]) = 60;
        *(S16*)(&m_Pad_0x14[1988]) = 480;
        memset(&m_Pad_0x0, 0, 0x84u);
        m_Pad_0x14[1968] = 1;
        *(Float*)(&m_Pad_0x14[1976]) = 0.0f;
        *(Float*)(&m_Pad_0x14[1972]) = 0.0f;
        strcpy((Char*)&m_Pad_0x14[1161], ".\\");
        strcpy((Char*)&m_Pad_0x14[1673], "Ace");
        *(S32*)(&m_Pad_0x14[1956]) = 0;
        *(S32*)(&m_Pad_0x14[1944]) = 0;
        *(S32*)(&m_Pad_0x14[1952]) = 0;
        *(S32*)(&m_Pad_0x14[1948]) = 0;
        m_Pad_0x14[120] = 0;
        m_Pad_0x14[121] = 0;
        m_Pad_0x14[136] = 0;
        m_Pad_0x14[123] = 0;
        m_Pad_0x14[122] = 0;
        *(S32*)(&m_Pad_0x14[84]) = 0;
        *(S32*)(&m_Pad_0x14[80]) = 0;
        *(S32*)(&m_Pad_0x14[108]) = 0;
        *(Float*)(&m_Pad_0x14[1960]) = 0.0;
        m_Pad_0x14[1932] = 0;
        *(S32*)(&m_Pad_0x14[1940]) = 0;
        *(Float*)(&m_Pad_0x14[132]) = 1.0f;
        *(S32*)(&m_Pad_0x14[1964]) = 0;
    }
};

#endif
