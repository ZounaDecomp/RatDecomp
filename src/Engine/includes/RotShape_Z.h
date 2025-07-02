#ifndef _ROTSHAPE_Z_H_
#define _ROTSHAPE_Z_H_
#include "DynArray_Z.h"
#include "Handle_Z.h"
#include "Points_Z.h"
#include "Points_ZHdl.h"

class RotShapeData_Z;
class RotShape_Z;

HANDLE_Z(RotShapeData_Z, PointsDatas_Z);
HANDLE_Z(RotShape_Z, Points_Z);
typedef DynArray_Z<RotShape_ZHdl, 32> RotShape_ZHdlDA;

typedef DynArray_Z<RotShape_Z, 32> RotShape_ZDA;

class RotShape_Z : public Points_Z {
    S32DA m_UnkDA;
};
#endif
