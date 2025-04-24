#ifndef _MAIN_Z_H_
#define _MAIN_Z_H_
#include "Types_Z.h"
#include "Handle_Z.h"

extern Char * strcpy(Char *__dest,Char *__src);
extern void * memset(void *__s,S32 __c,U32 __n);

class Globals {
public:
    virtual ~Globals() {};
    virtual U32 GetMgrSize(Name_Z *l_Name, S32 *a1, S32 *a2);
    virtual void Minimize();
    virtual void GetDate();
    void InitTime();

    U8 Pad_0x0[0xC];
    HandleManager_Z* ClassMgr;
    U8 Pad_0x14[0x7CC];

    inline Globals() {
        Pad_0x14[137] = 0;
        Pad_0x14[393] = 0;
        Pad_0x14[649] = 0;
        Pad_0x14[905] = 0;
        Pad_0x14[1161] = 0;
        Pad_0x14[1417] = 0;
        Pad_0x14[1673] = 0;
        *(S16*)(&Pad_0x14[1980]) = -1;
        *(S16*)(&Pad_0x14[1982]) = 0;
        *(S16*)(&Pad_0x14[1984]) = 1;
        *(S16*)(&Pad_0x14[1990]) = 8;
        *(S16*)(&Pad_0x14[1986]) = 60;
        *(S16*)(&Pad_0x14[1988]) = 480;
        memset(&Pad_0x0, 0, 0x84u);
        Pad_0x14[1968] = 1;
        *(Float*)(&Pad_0x14[1976]) = 0.0f;
        *(Float*)(&Pad_0x14[1972]) = 0.0f;
        strcpy((Char*)&Pad_0x14[1161], ".\\");
        strcpy((Char*)&Pad_0x14[1673], "Ace");
        *(S32*)(&Pad_0x14[1956]) = 0;
        *(S32*)(&Pad_0x14[1944]) = 0;
        *(S32*)(&Pad_0x14[1952]) = 0;
        *(S32*)(&Pad_0x14[1948]) = 0;
        Pad_0x14[120] = 0;
        Pad_0x14[121] = 0;
        Pad_0x14[136] = 0;
        Pad_0x14[123] = 0;
        Pad_0x14[122] = 0;
        *(S32*)(&Pad_0x14[84]) = 0;
        *(S32*)(&Pad_0x14[80]) = 0;
        *(S32*)(&Pad_0x14[108]) = 0;
        *(Float*)(&Pad_0x14[1960]) = 0.0;
        Pad_0x14[1932] = 0;
        *(S32*)(&Pad_0x14[1940]) = 0;
        *(S32*)(&Pad_0x14[132]) = 1.0f;
        *(S32*)(&Pad_0x14[1964]) = 0;
    }
};

#endif
