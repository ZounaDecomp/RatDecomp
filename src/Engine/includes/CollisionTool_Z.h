#ifndef _COLLISIONTOOL_Z_H_
#define _COLLISIONTOOL_Z_H_
#include "Math_Z.h"
#include "SystemObject_Z.h"

struct CollisionReport_Z {
    Vec4f m_Intersection;
    Vec4f m_Normal;
    Char m_Unk0x20[8];
    Float m_CollisionDistance;
    Char m_Unk0x2c[8];
    U16 m_Flag;
};

#endif
