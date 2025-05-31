#ifndef _COLOR_Z_H_
#define _COLOR_Z_H_
#include "Types_Z.h"
class Color {

public:
    Color() { }

    Color(Float i_Red, Float i_Green, Float i_Blue, Float i_Alpha);

    Color& operator=(Color const& i_Color) {
        m_Red = i_Color.m_Red;
        m_Green = i_Color.m_Green;
        m_Blue = i_Color.m_Blue;
        m_Alpha = i_Color.m_Alpha;
        return *this;
    }

    Float m_Red;
    Float m_Green;
    Float m_Blue;
    Float m_Alpha;
};

#endif
