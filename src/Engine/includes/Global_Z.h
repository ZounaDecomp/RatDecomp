// $SABE: Temporary file while testing circular dependency problems with BaseObject_ZHdl::IsValid()

// #ifndef _PROGRAM_Z_H_
// #define _PROGRAM_Z_H_

// #include "Types_Z.h"
// #include "Name_Z.h"
// //#include "BaseObject_Z.h"
// //#include "GCConsole_Z.h"
// //#include "LowMemory_Z.h"
// //#include "Main_Z.h"
// //#include "GCMain_Z.h"

// Extern_Z Char* strcpy(Char* __dest, Char* __src);
// Extern_Z "C" void memset(void* __s, S32 __c, U32 __n);
// class GCConsole_Z;
// class ClassManager_Z;

// class Globals {
// public:
//     virtual ~Globals() { };
//     virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
//     virtual void Minimize();
//     virtual void GetDate();
//     void InitTime();

//     U8 m_Pad_0x0[0x4];
//     GCConsole_Z* Cons;
//     U8 m_Pad_0xc[0x4]; // GCRenderer_Z
//     ClassManager_Z* ClassMgr;
//     U8 m_Pad_0x14[0x7CC];

//     inline Globals() {
//         m_Pad_0x14[137] = 0;
//         m_Pad_0x14[393] = 0;
//         m_Pad_0x14[649] = 0;
//         m_Pad_0x14[905] = 0;
//         m_Pad_0x14[1161] = 0;
//         m_Pad_0x14[1417] = 0;
//         m_Pad_0x14[1673] = 0;
//         *(S16*)(&m_Pad_0x14[1980]) = -1;
//         *(S16*)(&m_Pad_0x14[1982]) = 0;
//         *(S16*)(&m_Pad_0x14[1984]) = 1;
//         *(S16*)(&m_Pad_0x14[1990]) = 8;
//         *(S16*)(&m_Pad_0x14[1986]) = 60;
//         *(S16*)(&m_Pad_0x14[1988]) = 480;
//         memset(&m_Pad_0x0, 0, 132);
//         m_Pad_0x14[1968] = 1;
//         *(Float*)(&m_Pad_0x14[1976]) = 0.0f;
//         *(Float*)(&m_Pad_0x14[1972]) = 0.0f;
//         strcpy((Char*)&m_Pad_0x14[1161], ".\\");
//         strcpy((Char*)&m_Pad_0x14[1673], "Ace");
//         *(S32*)(&m_Pad_0x14[1956]) = 0;
//         *(S32*)(&m_Pad_0x14[1944]) = 0;
//         *(S32*)(&m_Pad_0x14[1952]) = 0;
//         *(S32*)(&m_Pad_0x14[1948]) = 0;
//         m_Pad_0x14[120] = 0;
//         m_Pad_0x14[121] = 0;
//         m_Pad_0x14[136] = 0;
//         m_Pad_0x14[123] = 0;
//         m_Pad_0x14[122] = 0;
//         *(S32*)(&m_Pad_0x14[84]) = 0;
//         *(S32*)(&m_Pad_0x14[80]) = 0;
//         *(S32*)(&m_Pad_0x14[108]) = 0;
//         *(Float*)(&m_Pad_0x14[1960]) = 0.0;
//         m_Pad_0x14[1932] = 0;
//         *(S32*)(&m_Pad_0x14[1940]) = 0;
//         *(Float*)(&m_Pad_0x14[132]) = 1.0f;
//         *(S32*)(&m_Pad_0x14[1964]) = 0;
//     }
// };

// class GCGlobals : public Globals {
// public:
//     virtual ~GCGlobals() { };
//     virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
//     virtual void Minimize();

//     U8 m_Pad_0x7E0[0x110];

//     GCGlobals() {
//         m_Pad_0x7E0[8] = 0;
//         *(S32*)(&m_Pad_0x7E0[0]) = 0;
//         *(S32*)(&m_Pad_0x7E0[4]) = 0;
//     }
// };

// Extern_Z GCGlobals gData;

// #endif
