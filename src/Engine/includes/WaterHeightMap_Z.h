#ifndef _WATERHEIGHTMAP_Z_H_
#define _WATERHEIGHTMAP_Z_H_
#include "Material_Z.h"
class Material_Z;

// $VIOLET: TODO: Actually implement this class.
class WaterHeightMap_Z {
public:
    virtual void Release();              /* 0x08 */
    virtual void Update(Material_Z* a1); /* 0x0C */
};
#endif
