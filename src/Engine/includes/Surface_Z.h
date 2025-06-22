#ifndef _SURFACE_Z_H_
#define _SURFACE_Z_H_
#include "Points_Z.h"

enum PatchFlag {
    EDGE1 = 2,
    EDGE2 = 4,
    EDGE3 = 8,
    EDGE4 = 16,
};

struct QuadCtrlPoint_Z {
    Vec4f ControlPoints[4][4];
};

struct Patch {
    U16 Flag;
    U16 EdgeIndices[4];
};

struct Edge {
    U16 P[2];
    U16 T[2];
};

class Surface_Z : public Points_Z {
public:
    U8 m_Pad[24];
    DynArray_Z<Edge, 32, 0, 1, 4> m_EdgeTab;

    void GetQuadPatchCtrlPoint(const Patch& i_Patch, QuadCtrlPoint_Z& o_QuadCtrlPoint);

protected:
};

#endif
