#include "Bitmap_Z.h"

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

void Bitmap_Z::Init() {
    m_Flag = 0;
    Bitmap_Z::EnableFlag(0x14);
    m_Datas = 0;
    m_Palette = 0;
    m_SizeX = 0;
    m_SizeY = 0;
    m_TrueFormat = 0;
    m_UnkU8_0x31 = 4;
    m_TexID = -1;
    m_Transp = -1;
    m_MipmapCount = 0;
    m_PrecalculatedSize = 0;
    m_PalFormat = PAL_8888;
}
  