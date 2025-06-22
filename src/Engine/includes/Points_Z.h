#ifndef _POINTS_Z_H_
#define _POINTS_Z_H_
#include "Math_Z.h"
#include "Object_Z.h"

typedef DynArray_Z<Vec3f, 32, 0, 0, 32> Vec3fDA;
typedef DynArray_Z<Vec2f, 32, 0, 0, 32> Vec2fDA;
typedef DynArray_Z<TBVtx, 32, 0, 0, 4> TBVtxDA;

// $SABE: Probably wrong, no way to tell
class MorphValue_Z {
public:
    MorphValue_Z() { }

private:
    U32 m_VertexIndex;
    Vec3f m_Delta;
};

class MorphTargetDesc_Z {
public:
    MorphTargetDesc_Z()
        : m_MeshName() { }

    void Load(void** i_Data);

private:
    Name_Z m_MeshName;
    U16 m_MeshID;
    DynArray_Z<MorphValue_Z, 64> m_MorphValues;
};

class Morpher_Z {
public:
    Morpher_Z() { }

    void Load(void** i_Data);

private:
    DynArray_Z<MorphValue_Z, 64> m_MorphValues;
    DynArray_Z<MorphTargetDesc_Z, 64> m_MorphTargetDescDA;
};

class Points_Z : public Object_Z {
public:
    Points_Z();
    virtual ~Points_Z() { };

    static BaseObject_Z* NewObject() {
        return New_Z Points_Z;
    }

    virtual void Load(void** i_Data);
    virtual void Clean();
    inline Vec3fDA& GetVertexDA();
    inline Vec3f& GetVertex(const U32 i_Index);
    inline void SetVertex(const U32 i_Index, const Vec3f& o_Point);
    inline U32 GetNbVertices() const;
    virtual U32 GetNbNormals() const;

protected:
    Vec3fDA m_Vertices;
    TBVtxDA m_TangentBinormalVertices;
    Morpher_Z m_Morpher;
};

#endif
