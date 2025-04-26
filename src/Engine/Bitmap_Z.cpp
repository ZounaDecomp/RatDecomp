#include "Bitmap_Z.h"
#include "Assert_Z.h"
extern void Z_FreeContiguous(void* ptr);

Bitmap_Z::Bitmap_Z()
{
    Init();
}

Bitmap_Z::Bitmap_Z(S32 i_Width, S32 i_Height, U8 i_Format, U8* i_Palette)
{
    Init();
    InitBmap(i_Width, i_Height, i_Format, i_Palette, 0);
}

Bitmap_Z::~Bitmap_Z()
{
    Reset();
}

#pragma dont_inline on
void Bitmap_Z::Init() {
    m_Flag = 0;
    Bitmap_Z::EnableFlag(0x14);
    m_Datas = 0;
    m_Palette = 0;
    m_SizeX = 0;
    m_SizeY = 0;
    m_TrueFormat = 0;
    m_UnkU8_0x31 = 4;
    m_TexID = INVALID_TEXID;
    m_Transp = -1;
    m_MipmapCount = 0;
    m_PrecalculatedSize = 0;
    m_PalFormat = PAL_8888;
}
// void Bitmap_Z::Invalidate() {
//     //stub
// };

void Bitmap_Z::Reset() {
    Invalidate();
    if (m_Datas) {
        Z_FreeContiguous(m_Datas);
    }
    m_Datas = 0;

    if (m_Palette) {
        delete m_Palette;
    }
    m_Palette = 0;

    Init();
}

// far from complete
void Bitmap_Z::InitBmap(S32 i_SizeX, S32 i_SizeY, U8 i_Format, U8* i_Palette, U8 i_UnkBool)
{
    int l_PaletteSize;
    int l_BytePalleteSize;
    m_SizeY = i_SizeY;
    m_TexID = INVALID_TEXID;
    m_SizeX = i_SizeX;
    m_Format = i_Format;
    m_TrueFormat = i_Format;
    m_MipmapCount = 0;
    l_PaletteSize = GetPalSize();
    GetBytePerPixel();

    if (m_Format == BM_4 || m_Format == BM_8) {
        l_BytePalleteSize = 4 * l_PaletteSize;
    }
}

Float Bitmap_Z::GetBytePerPixel() {
    Float l_Result; // st7

    switch ( m_Format )
    {
      case BM_4:
      l_Result = 0.5;
        break;
      case BM_8:
      case BM_I4A4:
      l_Result = 1.0;
        break;
      case BM_5551:
      case BM_565:
      case BM_4444:
      case BM_1555:
      l_Result = 2.0;
        break;
      case BM_8888:
      l_Result = 4.0;
        break;
      case BM_888:
      l_Result = 3.0;
        break;
      case BM_CMPR:
      l_Result = 0.0;
        break;
      default:
        ExceptionFonc_Z("FALSE", __FILE__, __LINE__, "Bitmap_Z::GetBytePerPixel", 0, 0, 0, 0, 0, 0);
        l_Result = 0.0;
        break;
    }
    return l_Result;
}

S32 Bitmap_Z::GetDataSize()
{
    S32 l_MipSize;
    S32 l_DataSize;
    U8 l_MipmapCount;
    l_DataSize = (GetBytePerPixel() * ((Float)m_SizeY * (Float)m_SizeX));
    l_MipmapCount = m_MipmapCount;
    for ( l_MipSize = l_DataSize; l_MipmapCount--; l_MipSize += (l_DataSize + 127) & ~127)
    {
        l_DataSize >>= 2;                          
    }
    return l_MipSize;
}

// not matching. too lazy to fix for now
S32 Bitmap_Z::GetPalSize()
{
    U8 l_PalFormat = m_PalFormat;
    if ((l_PalFormat >= PAL_ALPHA|PAL_565) && (l_PalFormat != 9 && l_PalFormat < 0x10))
        return 0;
    else
    {
        if (l_PalFormat == PAL_565)
            return 256;
        else if (l_PalFormat == PAL_3444)
            return 16;
    }
    ExceptionFonc_Z("FALSE", __FILE__, __LINE__, "Bitmap_Z::GetPalSize", 0, 0, 0, 0, 0, 0);
    return 0;
}
#pragma dont_inline off
