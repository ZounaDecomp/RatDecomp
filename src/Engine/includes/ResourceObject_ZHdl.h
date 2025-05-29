#ifndef _RESSOURCEOBJECT_ZHDL_H_
#define _RESSOURCEOBJECT_ZHDL_H_

#include "ClassManager_Z.h"
#include "Program_Z.h"

class BaseObject_Z;
class ResourceObject_Z;

HANDLE_Z(ResourceObject_Z, BaseObject_Z);

typedef DynArray_Z<ResourceObject_ZHdl, 32> ResourceObject_ZHdlDA;

#endif
