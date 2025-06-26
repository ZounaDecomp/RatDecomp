#include "Math_Z.h"
#include "MathTools_Z.h"

const Vec3i VEC3I_NULL = Vec3i(0, 0, 0);
const Vec4i VEC4I_NULL = Vec4i(0, 0, 0, 0);

// Vec2f constants
const Vec2f VEC2F_NULL = Vec2f(0.f, 0.f);
const Vec2f VEC2F_ONE = Vec2f(1.f, 1.f);

// Vec3f constants
const Vec3f VEC3F_NULL = Vec3f(0.f, 0.f, 0.f);
const Vec3f VEC3F_ONE = Vec3f(1.f, 1.f, 1.f);
const Vec3f VEC3F_HALF = Vec3f(0.5f, 0.5f, 0.5f);
const Vec3f VEC3F_UP = Vec3f(0.f, 1.f, 0.f);
const Vec3f VEC3F_DOWN = Vec3f(0.f, -1.f, 0.f);
const Vec3f VEC3F_LEFT = Vec3f(1.f, 0.f, 0.f);
const Vec3f VEC3F_RIGHT = Vec3f(-1.f, 0.f, 0.f);
const Vec3f VEC3F_FRONT = Vec3f(0.f, 0.f, 1.f);
const Vec3f VEC3F_BACK = Vec3f(0.f, 0.f, -1.f);

// Vec4f constants
const Vec4f VEC4F_NULL = Vec4f(0.f, 0.f, 0.f, 0.f);
const Vec4f VEC4F_UP = Vec4f(0.f, 1.f, 0.f, 0.f);
const Vec4f VEC4F_DOWN = Vec4f(0.f, -1.f, 0.f, 0.f);
const Vec4f VEC4F_LEFT = Vec4f(1.f, 0.f, 0.f, 0.f);
const Vec4f VEC4F_RIGHT = Vec4f(-1.f, 0.f, 0.f, 0.f);
const Vec4f VEC4F_FRONT = Vec4f(0.f, 0.f, 1.f, 0.f);
const Vec4f VEC4F_BACK = Vec4f(0.f, 0.f, -1.f, 0.f);

// Color constants
const Color COLOR_WHITE = Color(1.f, 1.f, 1.f, 1.f);
const Color COLOR_BLACK = Color(0.f, 0.f, 0.f, 1.f);
const Color COLOR_GREY = Color(0.5f, 0.5f, 0.5f, 1.f);
const Color COLOR_LIGHTGREY = Color(0.66f, 0.66f, 0.66f, 1.f);
const Color COLOR_DARKGREY = Color(0.33f, 0.33f, 0.33f, 1.f);
const Color COLOR_RED = Color(1.f, 0.f, 0.f, 1.f);
const Color COLOR_GREEN = Color(0.f, 1.f, 0.f, 1.f);
const Color COLOR_BLUE = Color(0.f, 0.f, 1.f, 1.f);
const Color COLOR_YELLOW = Color(1.f, 1.f, 0.f, 1.f);
const Color COLOR_CYAN = Color(0.f, 1.f, 1.f, 1.f);
const Color COLOR_MAGENTA = Color(1.f, 0.f, 1.f, 1.f);
const Color COLOR_ORANGE = Color(1.f, 0.5f, 0.f, 1.f);
const Color COLOR_BROWN = Color(145.f / 255.f, 89.0f / 255.f, 60.f / 255.f, 1.f);
const Color COLOR_LIGHTBLUE = Color(0.5f, 0.5f, 1.f, 1.f);
const Color COLOR_LIGHTGREEN = Color(0.5f, 1.f, 0.5f, 1.f);
const Color COLOR_LIGHTRED = Color(1.f, 0.5f, 0.5f, 1.f);

const Quat QUAT_NULL = Quat(1.f, 0.f, 0.f, 0.f);

Vec3f::Vec3f(const Color& i_Color)
    : x(i_Color.r)
    , y(i_Color.g)
    , z(i_Color.b) { };

Vec4f::Vec4f(const Color& i_Color)
    : x(i_Color.r)
    , y(i_Color.g)
    , z(i_Color.b)
    , w(i_Color.a) { };
