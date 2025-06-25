#ifndef _COLOR_Z_H_
#define _COLOR_Z_H_
#include "Types_Z.h"

class Color {

public:
    Color() { }

    Color(Float i_Red, Float i_Green, Float i_Blue, Float i_Alpha);

    Color& operator=(Color const& i_Color) {
        r = i_Color.r;
        g = i_Color.g;
        b = i_Color.b;
        a = i_Color.a;
        return *this;
    }

    Float r;
    Float g;
    Float b;
    Float a;
};

#endif
