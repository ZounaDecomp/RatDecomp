#ifndef _MATH_Z_H_
#define _MATH_Z_H_
#include "Types_Z.h"
#include "Bitmap_Z.h"

#define Float_Eps	1.e-6f
#define Pi			3.14159265358979323846f
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
    Vec3f(Float i_x, Float i_y, Float i_z)
        : x(i_x)
        , y(i_y)
        , z(i_z) { };
    Vec3f(const Color& i_Color);
    Vec3f(const Quat& Q);
    Vec3f operator*(const Float i_Scale) const {
        Vec3f l_Temp;
        l_Temp.x = x * i_Scale;
        l_Temp.y = y * i_Scale;
        l_Temp.z = z * i_Scale;
        return l_Temp;
    }
	Vec3f	operator -  () const;
	Vec3f& operator *= ( const Float _f );
};

struct  Vec3i
{
	S32	x,y,z;

	Vec3i()										{};
	Vec3i(S32 _x,S32 _y,S32 _z)					{x = _x;y = _y;z = _z;};
	Vec3i	&Set(S32 _x,S32 _y,S32 _z)			{x=_x;y=_y;z=_z;return *this;}
	Vec3i	&Set(const Vec3i &_v)				{x=_v.x;y=_v.y;z=_v.z; return *this;}		
	// Operator
	Vec3i	operator=(const Vec3i &_v)			{x=_v.x; y=_v.y; z=_v.z; return *this;}
	Vec3i	operator+(const Vec3i &_v) const	{return Vec3i(x+_v.x,y+_v.y,z+_v.z);}
	Vec3i	&operator+=(const Vec3i &_v)		{x+=_v.x;y+=_v.y;z+=_v.z;return *this;}
	Vec3i	operator+() const					{return *this;}
	Vec3i	operator-(const Vec3i &_v) const	{return Vec3i(x-_v.x,y-_v.y,z-_v.z);}
	Vec3i	&operator-=(const Vec3i &_v)		{x-=_v.x;y-=_v.y;z-=_v.z; return *this;}
	Vec3i	operator-() const					{return Vec3i(-x,-y,-z);}
	Vec3i	operator*(S32 _f)	const			{return Vec3i(x*_f,y*_f,z*_f);}
	Vec3i	&operator*=(S32 _f)					{x*=_f;y*=_f;z*=_f; return *this;}
	Bool	operator==(const Vec3i& v)	const	{return x==v.x && y==v.y && z==v.z;}
	S32&	operator[]  ( const int _i )		{return (&x)[_i];}
	const S32& operator[] ( const int _i ) const {return (&x)[_i];}
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

    Vec4f() { };
    Vec4f(Float i_x, Float i_y, Float i_z, Float i_w)
        : x(i_x)
        , y(i_y)
        , z(i_z)
        , w(i_w) { };

    Vec4f(Vec3f const& i_v)
        : x(i_v.x)
        , y(i_v.y)
        , z(i_v.z)
        , w(1.0f) { };

    Vec4f(const Color& i_Color);
    Vec4f(Float F)
        : x(F)
        , y(F)
        , z(F)
        , w(F) { };
    Vec4f operator+(const Vec4f& i_v) const { return Vec4f(x + i_v.x, y + i_v.y, z + i_v.z, w + i_v.w); }

    Vec4f operator-(const Vec4f& i_v) const { return Vec4f(x - i_v.x, y - i_v.y, z - i_v.z, w - i_v.w); }
};

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
} Aligned_Z(16);

struct Quat {
    Vec3f v;
    Float w;

    Quat() { }

    Quat(const Float _w, const Float _x, const Float _y, const Float _z);
    Quat(const Float Angle, const Vec3f& Axis);
    explicit Quat(const Vec3f& RV);
    Quat(const Vec3f& V1, const Vec3f& V2);
    Quat(const Vec3f& V1, const Vec3f& V2, const Vec3f& V3);
    explicit Quat(const Mat3x3& Matrix);
    explicit Quat(const Mat4x4& Matrix);

    const Vec4f& xyzw() const;
    Vec4f& xyzw();

    const Vec3f& xyz() const;
    Vec3f& xyz();

    Quat& SetNull();
    void SetAngleAxis(const Float Angle, const Vec3f& Axis);
    Quat& SetInverse();
    void Normalize();
    Bool Maximize(Float f);
    Float GetNorm2() const;
    Float GetNorm() const;
    Vec4f GetAxisAndAngle() const;
    Float GetAngle() const;
    Float GetSignedAngle() const;
    void SetAngle(Float _ang);
    void GetMatrix(Mat4x4& Mat) const;
    void GetMatrix(Mat3x3& Mat) const;
    void SetMatrix(const Mat4x4& Mat);
    void SetMatrix(const Mat3x3& Mat);
    Quat& operator=(const Vec3f& RV);
    Quat& operator=(const Vec4f& RV);
    Quat operator-() const;
    Quat operator+(const Quat& q) const;
    Quat operator-(const Quat& q) const;
    Quat& operator+=(const Quat& q);
    Quat& operator-=(const Quat& q);
    Quat operator*(const Quat& q) const;
    Quat& operator*=(const Quat& q);
    Quat operator*(const Float f) const;
    Quat& operator*=(const Float f);
    Quat operator/(const Float f) const;
    Quat& operator/=(const Float f);
    Float DotProduct(const Quat& Q) const;
    Vec3f operator*(const Vec3f& p) const;
    Vec4f operator*(const Vec4f& p) const;
    Bool operator==(const Quat& _Quat) const;
    Bool operator!=(const Quat& _Quat) const;
    void NegativeMul(const Vec3f& i_v, Vec3f& _result) const;
    void NegativeMul(const Vec4f& i_v, Vec4f& _result) const;
    void GetEular(Vec3f& Eular) const;
    void SetEular(const Vec4f& Eular);
    Float GetDist(const Quat& Q);
};

// $SABE: Tangent Binormal Vertex ? - From Monopoly MAP
struct TBVtx {
    Vec2f UnkVec2f_0x0;
    Vec2f UnkVec2f_0x8;
};

Sphere_Z operator*(const Mat4x4& Mat, const Sphere_Z& Sphere);

#endif
