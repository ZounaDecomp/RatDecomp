#ifndef _BITMAP_Z_H_
#define _BITMAP_Z_H_
#include "ResourceObject_Z.h"
#include "Types_Z.h"

enum BmFormat_Z
{
    BM_4            = 0x01        ,             // 4 Bits Indexed RGB
    BM_8            = 0x02        ,             // 8 Bits Indexed RGB
    BM_5551         = 0x07        ,             // 16 RGBA
    BM_565          = 0x08        ,             // 16 RGB
    BM_4444         = 0x0A        ,             // 16 RGBA
    BM_1555         = 0x0B        ,             //.TGA compatibility    
    BM_8888         = 0x0C        ,             // 32 RGBA
    BM_888          = 0x0D        ,             // 24 RGB
    BM_CMPR         = 0x0E        ,             // S3TC
    BM_I4A4         = 0x0F        ,             // I4A4
    BM_I8A8         = 0x10        ,             // I4A4
};

enum PalFormat_Z
{
    PAL_3444        = 0x01        ,             // 16 ARGB
    PAL_565         = 0x02        ,             // 16 RGB
    PAL_8888        = 0x03        ,             // 32 RGBA
    PAL_LUM         = 0x04        ,             // Luminance
    PAL_ALPHA       = 0x05        ,             // Alpha
    PAL_DXT1        = 0x11        ,             // DXT1 (OPAQUE)
    PAL_DXT3        = 0x12        ,             // DXT3 (ALPHA)
    PAL_DXT5        = 0x13        ,             // DXT5 (ALPHA)
};

enum BmTransp
{
    BM_NO_TRANSP    = 0,
    BM_TRANSP_ONE   = 1,
    BM_TRANSP       = 2
};

class Bitmap_Z : public ResourceObject_Z
{
public:
    Bitmap_Z();
    Bitmap_Z(S32 m_Width, S32 m_Height, U8 m_Format, U8* m_Palette);
    virtual void Init();
    virtual ~Bitmap_Z();
    virtual void Load(void* a1);
    virtual void Clean();
    void InitBmap(S32 m_Width, S32 m_Height, U8 m_Format, U8* m_Palette, U8 m_Datas);
    void EnableFlag(S16 i_Flag)   {m_Flag|=i_Flag;}
    void Reset();
    void Invalidate();
    Float GetBytePerPixel();
    Float GetDataSize();
private:
    void* m_Datas;
    void* m_Palette;
    S16 m_TexID;
    U32 m_SizeX;
    U32 m_SizeY;
    U32 m_PrecalculatedSize;
    U8 m_Format;
    U8 m_TrueFormat;
    U8 m_PalFormat;
    U8 m_Transp;
    U8 m_MipmapCount;
    U8 m_UnkU8_0x31; // Always set to 4
    S16 m_Flag;
};

#endif
