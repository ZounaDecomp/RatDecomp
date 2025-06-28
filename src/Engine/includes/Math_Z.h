#ifndef _MATH_Z_H_
#define _MATH_Z_H_
#include "MathTools_Z.h"
#include "Math_Z.h"
#include "Types_Z.h"
#include "Bitmap_Z.h"

#define Float_Eps 1.e-6f
#define Pi 3.14159265358979323846f
#define ROL_Z(val, shift) ((val << shift) | (val >> ((sizeof(val) * 8) - shift)))
#define ROR_Z(val, shift) ((val >> shift) | (val << ((sizeof(val) * 8) - shift)))
struct Sphere_Z;
struct Vec2f;
struct Vec3f;
struct Vec4f;
struct Quat;
struct Mat3x3;
struct Mat4x4;

void Inverse2(const Mat4x4&, Mat4x4&);

union UDummy { // $SABE: U dummy!
    S16 i16[2];
    U16 u16[2];
    Float f32;
    S32 i32;
    U32 u32;
};

struct Vec2f {
    Float x, y;

    Vec2f() { };
    Vec2f(Float i_x, Float i_y)
        : x(i_x)
        , y(i_y) { };
};

struct Vec3f {
    Float x, y, z;

    Vec3f() { };
    Vec3f(const Color& i_Color);
    Vec3f(const Quat& Q);

    Vec3f(Float _x, Float _y, Float _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vec3f& Set(Float _x, Float _y, Float _z) {
        x = _x;
        y = _y;
        z = _z;
        return *this;
    }

    Vec3f& Set(const Vec3f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        return *this;
    }

    Vec3f operator=(const Vec3f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        return *this;
    }

    inline Vec3f operator=(const Vec4f& _v);

    Vec3f operator+(const Vec3f& _v) const { return Vec3f(x + _v.x, y + _v.y, z + _v.z); }

    Vec3f& operator+=(const Vec3f& _v) {
        x += _v.x;
        y += _v.y;
        z += _v.z;
        return *this;
    }

    Vec3f operator+() const { return *this; }

    Vec3f operator-(const Vec3f& _v) const { return Vec3f(x - _v.x, y - _v.y, z - _v.z); }

    Vec3f& operator-=(const Vec3f& _v) {
        x -= _v.x;
        y -= _v.y;
        z -= _v.z;
        return *this;
    }

    Vec3f operator-() const { return Vec3f(-x, -y, -z); }

    Vec3f operator*(Float _f) const { return Vec3f(x * _f, y * _f, z * _f); }

    Vec3f& operator*=(Float _f) {
        x *= _f;
        y *= _f;
        z *= _f;
        return *this;
    }

    Float operator*(const Vec3f& _v) const { return x * _v.x + y * _v.y + z * _v.z; }

    Vec3f operator/(Float _f) const {
        float inv = 1.f / _f;
        return Vec3f(x * inv, y * inv, z * inv);
    }

    Vec3f& operator/=(Float _f) {
        float inv = 1.f / _f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    Vec3f operator/(const Vec3f& _v) { return Vec3f(x / _v.x, y / _v.y, z / _v.z); }

    Vec3f operator^(const Vec3f& _v) const { return Vec3f(y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x); }

    Vec3f operator&(const Vec3f& _v) const { return Vec3f(x * _v.x, y * _v.y, z * _v.z); }

    Float& operator[](int _i) { return (&x)[_i]; }

    const Float& operator[](int _i) const { return (&x)[_i]; }

    Bool operator==(const Vec3f& v) const {
        Vec3f Diff = *this - v;
        return (fabsf(Diff.x) < Float_Eps) && (fabsf(Diff.y) < Float_Eps) && (fabsf(Diff.z) < Float_Eps);
    }

    Bool operator!=(const Vec3f& v) const { return !operator==(v); };

    operator Float*() { return &x; }

    Float GetNorm2() const { return (*this) * (*this); }

    Float GetNorm() const { return sqrtf(GetNorm2()); }

    Vec3f& Normalize() { return (*this) /= GetNorm(); }

    Float HGetNorm2() const { return x * x + z * z; }

    Float HGetNorm() const { return sqrtf(HGetNorm2()); }

    Vec3f& HNormalize() {
        *this = (Vec3f(x, 0.f, z) / HGetNorm());
        return *this;
    }
};

inline Vec3f operator*(Float _f, const Vec3f& _v) {
    return _v * _f;
}

struct Vec3i {
    S32 x, y, z;

    Vec3i() { };

    Vec3i(S32 _x, S32 _y, S32 _z) {
        x = _x;
        y = _y;
        z = _z;
    };

    Vec3i& Set(S32 _x, S32 _y, S32 _z) {
        x = _x;
        y = _y;
        z = _z;
        return *this;
    }

    Vec3i& Set(const Vec3i& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        return *this;
    }

    Vec3i operator=(const Vec3i& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        return *this;
    }

    Vec3i operator+(const Vec3i& _v) const { return Vec3i(x + _v.x, y + _v.y, z + _v.z); }

    Vec3i& operator+=(const Vec3i& _v) {
        x += _v.x;
        y += _v.y;
        z += _v.z;
        return *this;
    }

    Vec3i operator+() const { return *this; }

    Vec3i operator-(const Vec3i& _v) const { return Vec3i(x - _v.x, y - _v.y, z - _v.z); }

    Vec3i& operator-=(const Vec3i& _v) {
        x -= _v.x;
        y -= _v.y;
        z -= _v.z;
        return *this;
    }

    Vec3i operator-() const { return Vec3i(-x, -y, -z); }

    Vec3i operator*(S32 _f) const { return Vec3i(x * _f, y * _f, z * _f); }

    Vec3i& operator*=(S32 _f) {
        x *= _f;
        y *= _f;
        z *= _f;
        return *this;
    }

    Bool operator==(const Vec3i& v) const { return x == v.x && y == v.y && z == v.z; }

    S32& operator[](const int _i) { return (&x)[_i]; }

    const S32& operator[](const int _i) const { return (&x)[_i]; }
};

struct Vec4i {
    S32 x, y, z, w;

    Vec4i() { };
    Vec4i(S32 i_x, S32 i_y, S32 i_z, S32 i_w)
        : x(i_x)
        , y(i_y)
        , z(i_z)
        , w(i_w) { };
    Vec4i(const Vec3i& i_v)
        : x(i_v.x)
        , y(i_v.y)
        , z(i_v.z)
        , w(1) { };

    Vec4i operator+(const Vec4i& i_v) const { return Vec4i(x + i_v.x, y + i_v.y, z + i_v.z, w + i_v.w); }

    Vec4i operator-(const Vec4i& i_v) const { return Vec4i(x - i_v.x, y - i_v.y, z - i_v.z, w - i_v.w); }
};

struct Vec4f {
    Float x, y, z, w;

    Vec4f() { }

    Vec4f(const Color& i_Color);

    Vec4f(const Vec3f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        w = 1.f;
    }

    Vec4f(Float _x, Float _y, Float _z, Float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    Vec4f& Set(Float _x, Float _y, Float _z, Float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
        return *this;
    }

    Vec4f& Set(const Vec4f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        w = _v.w;
        return *this;
    }

    Vec4f operator=(const Vec4f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        w = _v.w;
        return *this;
    }

    Vec4f operator=(const Vec3f& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        w = 1.f;
        return *this;
    }

    Vec4f operator+(const Vec4f& _v) const { return Vec4f(x + _v.x, y + _v.y, z + _v.z, w + _v.w); }

    Vec4f& operator+=(const Vec4f& _v) {
        x += _v.x;
        y += _v.y;
        z += _v.z;
        w += _v.w;
        return *this;
    }

    Vec4f operator+() const { return *this; }

    Vec4f operator-(const Vec4f& _v) const { return Vec4f(x - _v.x, y - _v.y, z - _v.z, w - _v.w); }

    Vec4f& operator-=(const Vec4f& _v) {
        x -= _v.x;
        y -= _v.y;
        z -= _v.z;
        w -= _v.w;
        return *this;
    }

    Vec4f operator-() const { return Vec4f(-x, -y, -z, -w); }

    Vec4f operator*(Float _f) const { return Vec4f(x * _f, y * _f, z * _f, w * _f); }

    Vec4f& operator*=(Float _f) {
        x *= _f;
        y *= _f;
        z *= _f;
        w *= _f;
        return *this;
    }

    Float operator*(const Vec4f& _v) const { return x * _v.x + y * _v.y + z * _v.z; }

    Vec4f operator/(Float _f) const {
        float inv = 1.f / _f;
        return Vec4f(x * inv, y * inv, z * inv, w * inv);
    }

    Vec4f& operator/=(Float _f) {
        float inv = 1.f / _f;
        x *= inv;
        y *= inv;
        z *= inv;
        w *= inv;
        return *this;
    }

    Float& operator[](int _i) {
        return (&x)[_i];
    }

    const Float& operator[](int _i) const {
        return (&x)[_i];
    }

    Bool operator==(const Vec4f& v) {
        Vec4f Diff = *this - v;
        return (fabsf(Diff.x) < Float_Eps) && (fabsf(Diff.y) < Float_Eps) && (fabsf(Diff.y) < Float_Eps);
    }

    operator Float*() { return &x; }

    Vec4f operator^(const Vec4f& _v) const { return Vec4f(y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x, 1.f); }

    Float GetNorm2() const { return x * x + y * y + z * z; }

    Float GetNorm() const { return sqrtf(x * x + y * y + z * z); }

    Vec4f& Normalize() { return (*this) /= sqrtf(x * x + y * y + z * z); }
};

inline Vec4f operator*(Float _f, const Vec4f& _v) {
    return _v * _f;
}

struct Mat3x3 {
public:
    union mat {
        Float m[3][4];

        // Row2
        struct {
            float f[2];
            UDummy dummy;
            float v;
        } m02;

        struct {
            float f[6];
            UDummy dummy;
            float v;
        } m12;

        struct {
            float f[10];
            UDummy dummy;
            float v;
        } m22;

        // Row3
        struct {
            float f[3];
            UDummy dummy;
        } m03;

        struct {
            float f[7];
            UDummy dummy;
        } m13;

        struct {
            float f[11];
            UDummy dummy;
        } m23;
    } m;

    Mat3x3() { }

    //Mat3x3(const Mat3x3& i_m);
    //Mat3x3(const Mat4x4& i_m);
    Mat3x3& SetNull();
    Mat3x3& SetIdentity();
    void Transp(Mat3x3& o_m) const;
    Mat3x3& operator=(const Mat3x3& i_m);
    Mat3x3& operator*=(const Mat3x3& i_m);
    Mat3x3 operator*(const Mat3x3& i_m) const;

    Float Determinant() const;

    void Set(const Mat4x4& i_m);
    inline Vec2f operator*(const Vec2f& i_v) const;

    inline Vec3f operator*(const Vec3f& i_v) const;
    inline Vec4f operator*(const Vec4f& i_v) const;
    Bool operator==(const Mat3x3& i_m) const;
    Bool operator!=(const Mat3x3& i_m) const;
    const Vec4f& GetRow(const int i_x) const;
    Vec4f& GetRow(const int i_x);
    void GetEular(Vec3f& o_Eular);
};

struct Mat4x4 {
    Float m[4][4];

    inline Mat4x4& operator=(const Mat4x4& _m);

    Mat4x4() { }

    Mat4x4(const Float _s);

    //Mat4x4(const Vec3f& i_Trans, const Quat& i_Rot, const Vec3f& i_Scale) {
    //    SetTRS(i_Trans, i_Rot, i_Scale);
    //}

    //Mat4x4(const Vec3f& i_Trans, const Quat& i_Rot, const Float i_Scale) {
    //    SetTRS(i_Trans, i_Rot, i_Scale);
    //}

    //Mat4x4(const Mat3x3& _Mat);
    //Mat4x4(const Mat4x4& _Mat);

    const Mat3x3& m3() const;
    Mat3x3& m3();

    Mat4x4& SetNull();
    Mat4x4& SetIdentity();

    Vec3f operator*(const Vec3f& i_v) const;
    Vec4f operator*(const Vec4f& i_v) const;

    Vec3f MulHomogenous(const Vec3f& i_v) const;

    Mat4x4& operator*=(const Mat4x4& i_m);
    Mat4x4 operator*(const Mat4x4& i_m) const;

    operator Float*();
    operator const Float*() const;

    Bool operator==(const Mat4x4& i_m) const;
    Bool operator!=(const Mat4x4& i_m) const;

    const Vec4f& GetRow(const int i_x) const;
    Vec4f& GetRow(const int i_x);

    void MulWithoutTrans(const Vec3f& i_v, Vec4f& o_v) const;
    void MulWithoutTrans(const Vec3f& i_v, Vec3f& o_v) const;
    void MulWithoutTrans(const Vec4f& i_v, Vec4f& o_v) const;

    void Transp(Mat4x4& _Out) const;

    Float GetUniformScale() const;
    void GetScale(Vec3f& o_Scale) const;
    const Vec3f& GetMatrixTrans() const;
    const Vec4f& GetMatrixTrans4() const;

    void SetTRS(const Vec3f& i_Trans, const Quat& i_Rot, const Vec3f& i_Scale);
    void SetTRS(const Vec3f& i_Trans, const Quat& i_Rot, const Float i_Scale);

    U32 GetCRC() const;
    inline Vec3f operator*(const Vec3f _v) const;
    Vec4f operator*(const Vec4f _v) const;

} Aligned_Z(16);

Vec3f Mat4x4::operator*(const Vec3f _v) const {
    Vec3f vec;

    vec.x = m[0][0] * _v.x + m[1][0] * _v.y + m[2][0] * _v.z + m[3][0];
    vec.y = m[0][1] * _v.x + m[1][1] * _v.y + m[2][1] * _v.z + m[3][1];
    vec.z = m[0][2] * _v.x + m[1][2] * _v.y + m[2][2] * _v.z + m[3][2];

    return vec;
}

struct Quat {
    Vec3f v;
    Float w;

    inline Quat() { }

    inline Quat(Float _w, Float _x, Float _y, Float _z) {
        w = _w;
        v.x = _x;
        v.y = _y;
        v.z = _z;
    }

    inline Quat(Float Angle, const Vec3f& Axis) {
        w = cosf(Angle / 2.f);
        v = sinf(Angle / 2.f) * Axis;
    }

    inline Quat(const Quat& _Quat) {
        w = _Quat.w;
        v = _Quat.v;
    }

    Quat(const Vec3f& V1, const Vec3f& V2);
    Quat(const Vec3f& V1, const Vec3f& V2, const Vec3f& V3);
    Quat(const Mat3x3& Matrix);
    Quat(const Mat4x4& Matrix);

    void SetAngleAxis(Float Angle, Vec3f& Axis) {
        w = cosf(Angle / 2.f);
        v = sinf(Angle / 2.f) * Axis;
    }

    Quat& SetInverse() {
        v = -v;
        return *this;
    }

    void Normalize();
    void GetMatrix(Mat4x4& Mat) const;
    void GetMatrix(Mat3x3& Mat) const;
    void SetMatrix(const Mat4x4& Mat);
    void SetMatrix(const Mat3x3& Mat);

    Quat operator+(const Quat& q) const { return Quat(w + q.w, v.x + q.v.x, v.y + q.v.y, v.z + q.v.z); }

    Quat operator-(const Quat& q) const { return Quat(w - q.w, v.x - q.v.x, v.y - q.v.y, v.z - q.v.z); }

    Quat& operator=(const Quat& q) {
        w = q.w;
        v = q.v;
        return *this;
    }

    Quat operator*(const Quat& q) const;
    Quat& operator*=(const Quat& Q);

    Float operator*(Quat& Q) { return (v * Q.v + w * Q.w); }

    Vec3f operator*(const Vec3f& p) const;

    Bool operator==(const Quat& _Quat) const { return ((Vec4f(w - _Quat.w, v.x - _Quat.v.x, v.y - _Quat.v.y, v.z - _Quat.v.z).GetNorm2()) < Float_Eps) ? TRUE : FALSE; }

    Bool operator!=(const Quat& _Quat) const { return !operator==(_Quat); }
};

// $SABE: Tangent Binormal Vertex ? - From Monopoly MAP
struct TBVtx {
    Vec2f UnkVec2f_0x0;
    Vec2f UnkVec2f_0x8;
};

Sphere_Z operator*(const Mat4x4& Mat, const Sphere_Z& Sphere);

template <typename T>
T Clamp(T i_Value, T i_Min, T i_Max) {
    if (i_Value <= i_Min) return i_Min;
    if (i_Value >= i_Max) return i_Max;
    return i_Value;
}

template <typename T>
T Min(T i_V1, T i_V2) {
    if (i_V1 < i_V2)
        return i_V1;
    else
        return i_V2;
}

template <typename T>
T Max(T i_V1, T i_V2) {
    if (i_V1 > i_V2)
        return i_V1;
    else
        return i_V2;
}

void Inverse2(const Mat4x4& In, Mat4x4& Out);
#endif
