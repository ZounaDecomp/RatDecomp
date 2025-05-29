#ifndef _SYSTEMOBJECT_Z_H_
#define _SYSTEMOBJECT_Z_H_
#include "Math_Z.h"

struct Box_Z;
struct Sphere_Z;
struct Cylindre_Z;
struct Capsule_Z;
struct Segment_Z;

struct Box_Z {
    Mat3x3 Mat; // $SABE: Mat3x3 is actually Float[3][4]. 3x3 is pure rotation, center is [0][3],[1][3],[2][3]
    Vec3f Scale;
    Float Radius;

    // $SABE TODO: Not getting generated
    Box_Z()
        : Mat()
        , Scale() { };

    Box_Z(const Quat& i_Rot, const Vec3f& i_Trans, const Vec3f& i_Size);
    void Set(const Quat& i_Rot, const Vec3f& i_Trans, const Vec3f& i_Size);
    void Set(const Vec4f& i_Right, const Vec4f& i_Up, const Vec4f& i_Front, const Vec3f& i_Trans, const Vec3f& i_Size);
    void Set(const Vec3f& i_Right, const Vec3f& i_Up, const Vec3f& i_Front, const Vec3f& i_Trans, const Vec3f& i_Size);
    void Set(const Sphere_Z& i_Sph);
    Box_Z& operator=(const Box_Z& i_Box);
    Box_Z& operator+=(const Box_Z& i_Box);
    Box_Z& operator+=(const Sphere_Z& i_Sph);
    Box_Z operator*(const Mat4x4& i_Mat) const;
    void Build(const Vec3f& i_Center, const Vec3f& i_YAxis, const Vec3f* i_PointList, U32 i_NumPoint, Bool i_bAllowTinyBoxes = FALSE);
    void GetVtx(Vec3f* o_VtxArr) const;

    inline void GetTranslation(Vec3f& o_Trans) const { o_Trans.x = Mat.m.m[0][3], o_Trans.y = Mat.m.m[1][3], o_Trans.z = Mat.m.m[2][3]; }

    inline void SetTranslation(const Vec3f& i_Trans) { Mat.m.m[0][3] = i_Trans.x, Mat.m.m[1][3] = i_Trans.y, Mat.m.m[2][3] = i_Trans.z; }

    inline void GetTranslation(Vec4f& o_Trans) const { o_Trans.x = Mat.m.m[0][3], o_Trans.y = Mat.m.m[1][3], o_Trans.z = Mat.m.m[2][3], o_Trans.w = 0.f; }

    inline void SetTranslation(const Vec4f& i_Trans) { Mat.m.m[0][3] = i_Trans.x, Mat.m.m[1][3] = i_Trans.y, Mat.m.m[2][3] = i_Trans.z; }
};

struct Sphere_Z {
    Vec3f Center;
    Float Radius;
} Aligned_Z(16);

struct Cylindre_Z {
    U8 Unk_0x0[36]; // $SABE: Yet to reverse this, there's like the position of the base, normal and a radius but there's 4 unk bytes
};

struct FastBox_Z {
    Mat4x4 Mat;
    Mat4x4 RotMat;
    Vec4f Trans;
    Vec4f Scale;
    Float Radius;
} Aligned_Z(16);

struct BoxFlag_Z {
    FastBox_Z Box;
    U32 Flag;
    BaseObject_Z* Object; // $SABE: Not sure if it's really here
};

struct CollisionFastTriangle_Z {
    U8 Unk_0x0[0x110];
} Aligned_Z(16);

struct TriangleFlag_Z {
    CollisionFastTriangle_Z Triangle;
    U32 Flag;
    BaseObject_Z* Object; // $SABE: Not sure if it's really here
};

struct SphereFlag_Z {
    Sphere_Z Sph;
    U32 Flag;
    BaseObject_Z* Object; // $SABE: Not sure if it's really here
};

#endif
