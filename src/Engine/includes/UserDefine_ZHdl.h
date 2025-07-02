#ifndef _USERDEFINE_ZHDL_H_
#define _USERDEFINE_ZHDL_H_
#include "ResourceObject_ZHdl.h"
#include "UserDefine_Z.h"

HANDLE_Z(UserDefine_Z, ResourceObject_Z);

typedef DynArray_Z<UserDefine_ZHdl, 32> UserDefine_ZHdlDA;

#endif
