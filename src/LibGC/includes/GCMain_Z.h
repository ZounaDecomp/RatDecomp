#ifndef _GCMAIN_Z_H_
#define _GCMAIN_Z_H_
#include "Main_Z.h"

class GCGlobals : public Globals {
public:
    virtual ~GCGlobals() { };
    virtual U32 GetMgrSize(Name_Z* l_Name, S32* a1, S32* a2);
    virtual void Minimize();

    U8 m_Pad_0x7E0[0x110];

    GCGlobals() {
        m_Pad_0x7E0[8] = 0;
        *(S32*)(&m_Pad_0x7E0[0]) = 0;
        *(S32*)(&m_Pad_0x7E0[4]) = 0;
    }
};

Weak_Z BaseObject_ZHdl::operator BaseObject_Z*() const {
    return GETPTR(*this);
}

#endif
