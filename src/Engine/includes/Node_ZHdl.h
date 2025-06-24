#ifndef _NODE_ZHDL_H_
#define _NODE_ZHDL_H_
#include "ResourceObject_ZHdl.h"

class Node_Z;

HANDLE_Z(Node_Z, ResourceObject_Z);

typedef DynArray_Z<Node_ZHdl, 32> Node_ZHdlDA;


#endif
