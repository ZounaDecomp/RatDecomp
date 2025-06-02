#ifndef	_POINT_ZHDL_H
#define	_POINT_ZHDL_H

#include "Object_ZHdl.h"

class Points_Z;
class Object_Z;
HANDLE_Z(Points_Z,Object_Z);
typedef DynArray_Z<Points_ZHdl,8>	Points_ZHdlDA;

class PointsDatas_Z;
class ObjectDatas_Z;
HANDLE_Z(PointsDatas_Z,ObjectDatas_Z);
typedef DynArray_Z<PointsDatas_ZHdl,8>	PointsDatas_ZHdlDA;

#endif
