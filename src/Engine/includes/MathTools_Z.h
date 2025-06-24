#ifndef _MATHTOOLS_Z_H_
#define _MATHTOOLS_Z_H_
#include "Types_Z.h"
#include <math.h>
void MathInitTables();

Float InvSqrt(Float x, Float y) {
    return x / sqrtf(y);
}

Float O_Atan2(Float x, Float y);
Float O_Cos(Float x);
Float O_Sin(Float x);
Float O_Tan(Float x);
Float O_ACos(Float x);
Float O_ASin(Float x);
Float O_ATan(Float x);
#endif
