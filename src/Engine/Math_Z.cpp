#include "Math_Z.h"

Vec3f::Vec3f(const Color& i_Color) : x(i_Color.m_Red), y(i_Color.m_Green), z(i_Color.m_Blue) {};
Vec4f::Vec4f(const Color& i_Color) : x(i_Color.m_Red), y(i_Color.m_Green), z(i_Color.m_Blue), w(i_Color.m_Alpha) {};
