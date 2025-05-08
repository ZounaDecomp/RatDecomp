#ifndef _MATH_Z_H_
#define _MATH_Z_H_
#include "Types_Z.h"
#include "Bitmap_Z.h"
#define ROL_Z(val,shift) ((val<<shift)|(val>>((sizeof(val)*8)-shift)))
#define ROR_Z(val,shift) ((val>>shift)|(val<<((sizeof(val)*8)-shift)))

class Vec3f
{
public:
    Float x, y, z;

    Vec3f() {};
    Vec3f(Float i_x, Float i_y, Float i_z) : x(i_x), y(i_y), z(i_z) {};
    Vec3f(const Color& i_Color);
};

class Vec4f 
{
public:
    Float x, y, z, w;

    Vec4f() {};
    Vec4f(Float i_x, Float i_y, Float i_z, Float i_w) : x(i_x), y(i_y), z(i_z), w(i_w) {};
    Vec4f(const Color& i_Color);
};

#endif
