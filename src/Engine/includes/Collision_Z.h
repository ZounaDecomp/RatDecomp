#ifndef _COLLISION_Z_H_
#define _COLLISION_Z_H_
#include "SystemObject_Z.h"
class Node_Z;

struct ColLineResult_Z {
};

struct ClingLineResult_Z {
};

struct ColSphereResult_Z {
    Vec3f Inter;
    Float Dist;
    Vec3f Normal;
    Node_Z* NodePtr;
    U64 Flag;

    ColSphereResult_Z() { Reset(); }

    void Reset() { NodePtr = NULL; }
};

#endif
