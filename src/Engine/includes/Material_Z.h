#ifndef _MATERIAL_Z_H_
#define _MATERIAL_Z_H_
#include "Math_Z.h"
#include "ResourceObject_Z.h"
#include "Bitmap_ZHdl.h"
#include "Material_ZHdl.h"
#include "Types_Z.h"

#define FL_MAT_RDR_UNK0 (1 << 0)
#define FL_MAT_RDR_UNK1 (1 << 1)
#define FL_MAT_RDR_UNK2 (1 << 2)
#define FL_MAT_RDR_UNK3 (1 << 3)
#define FL_MAT_RDR_UNK4 (1 << 4)
#define FL_MAT_RDR_UNK5 (1 << 5)
#define FL_MAT_RDR_UNK6 (1 << 6)
#define FL_MAT_RDR_UNK7 (1 << 7)
#define FL_MAT_RDR_UNK8 (1 << 8)
#define FL_MAT_RDR_UNK9 (1 << 9)
#define FL_MAT_RDR_UNK10 (1 << 10)
#define FL_MAT_RDR_UNK11 (1 << 11)
#define FL_MAT_RDR_UNK12 (1 << 12)
#define FL_MAT_RDR_UNK13 (1 << 13)
#define FL_MAT_RDR_UNK14 (1 << 14)
#define FL_MAT_RDR_UNK15 (1 << 15)
#define FL_MAT_RDR_UNK16 (1 << 16)
#define FL_MAT_RDR_DISABLE_CULLING (1 << 17)
#define FL_MAT_RDR_UNK18 (1 << 18)
#define FL_MAT_RDR_UNK19 (1 << 19)
#define FL_MAT_RDR_UNK20 (1 << 20)
#define FL_MAT_RDR_UNK21 (1 << 21)
#define FL_MAT_RDR_UNK22 (1 << 22)
#define FL_MAT_RDR_UNK23 (1 << 23)
#define FL_MAT_RDR_UNK24 (1 << 24)
#define FL_MAT_RDR_UNK25 (1 << 25)
#define FL_MAT_RDR_UNK26 (1 << 26)
#define FL_MAT_RDR_UNK27 (1 << 27)
#define FL_MAT_RDR_UNK28 (1 << 28)
#define FL_MAT_RDR_UNK29 (1 << 29)

#define FL_MAT_COL_UNK0 (1 << 0)
#define FL_MAT_COL_COLLIDABLE (1 << 1)
#define FL_MAT_COL_UNK2 (1 << 2)
#define FL_MAT_COL_UNK3 (1 << 3)
#define FL_MAT_COL_UNK4 (1 << 4)
#define FL_MAT_COL_UNK5 (1 << 5)
#define FL_MAT_COL_UNK6 (1 << 6)
#define FL_MAT_COL_UNK7 (1 << 7)
#define FL_MAT_COL_UNK8 (1 << 8)
#define FL_MAT_COL_UNK9 (1 << 9)
#define FL_MAT_COL_UNK10 (1 << 10)
#define FL_MAT_COL_UNK11 (1 << 11)
#define FL_MAT_COL_UNK12 (1 << 12)
#define FL_MAT_COL_UNK13 (1 << 13)
#define FL_MAT_COL_UNK14 (1 << 14)
#define FL_MAT_COL_UNK15 (1 << 15)
#define FL_MAT_COL_UNK16 (1 << 16)
#define FL_MAT_COL_UNK17 (1 << 17)
#define FL_MAT_COL_SOUND1 (1 << 18) // changes sound with 80000,100000,200000
#define FL_MAT_COL_SOUND2 (1 << 19) // changes sound with 40000,100000,200000
#define FL_MAT_COL_SOUND3 (1 << 20) // changes sound with 40000,80000,200000
#define FL_MAT_COL_SOUND4 (1 << 21) // changes sound + particles with 40000,80000,100000
#define FL_MAT_COL_SLIDE1 (1 << 22) // Slide surface 1 - slippery w/ sticky
#define FL_MAT_COL_SLIDE2 (1 << 23) // Slide surface 2
#define FL_MAT_COL_STICKY (1 << 24) // Sticky surface - slippery w/ Slide 1
#define FL_MAT_COL_UNK25 (1 << 25)
#define FL_MAT_COL_UNK26 (1 << 26)
#define FL_MAT_COL_UNK27 (1 << 27)
#define FL_MAT_COL_UNK28 (1 << 28)
#define FL_MAT_COL_UNK29 (1 << 29)

#define FL_TEX_DIFFUSE (1 << 0)  ///< Diffuse texture
#define FL_TEX_ENV (1 << 1)      ///< Environment texture
#define FL_TEX_BUMP (1 << 2)     ///< Bump texture
#define FL_TEX_SPECULAR (1 << 3) ///< Specular texture

class WaterHeightMap_Z;

class Material_Z : public ResourceObject_Z {
public:
    enum mtl_params {
        mtl_diffuse = 0, ///< Diffuse bitmap channel
        mtl_envmap,      ///< EnvMap bitmap channel
        mtl_bumpmap,     ///< Bump Map bitmap channel
        mtl_specularmap, ///< Specular Map bitmap channel

        mtl_nb_params ///< Total number of channels supported in materials
    };

    Material_Z();
    virtual ~Material_Z();
    virtual void Load(void** i_Data);
    virtual void EndLoad();
    virtual void Clean();
    virtual Bool MarkHandles();
    virtual void Clone(Material_ZHdl& a1);
    virtual void UpdateTMatrix();
    virtual void Changed();
    static U32 DefaultRdrFlag;

private:
    char m_Unk0x14[0x0C];
    Vec3f m_DiffuseColor;
    Float m_DiffuseOpacity;
    Vec3f m_EmissiveColor;
    Float m_Opacity; // $VIOLET: COULD BE WRONG
    Mat3x3 m_UVTransform;
    Vec4f m_Specular; // $VIOLET: Power in W
    Vec4f m_ParamUsedByWater;
    Float m_Rotation;
    Vec2f m_Translation;
    Vec2f m_Scale;
    U32 m_ColFlag;
    U32 m_RdrFlags;
    U32 m_ObjectFlags;
    U8 m_TextureFlags;
    U8 m_TileU;
    U8 m_TileV;
    U8 m_ConstantAlphaWriteValue;
    U32 m_RdrFlags2;
    WaterHeightMap_Z* m_WaterHeightMap;
    Bitmap_ZHdl m_CurBmapHdl[mtl_nb_params];
};

#endif
