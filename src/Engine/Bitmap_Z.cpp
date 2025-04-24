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

void Bitmap_Z::Init() {
    m_Flag = 0;
    Bitmap_Z::EnableFlag(0x14);
    m_Datas = 0;
    m_Palette = 0;
    m_SizeX = 0;
    m_SizeY = 0;
    m_TrueFormat = 0;
    m_Unk_0x31 = 4;
    m_TexID = -1;
    m_Transp = -1;
    m_MipmapCount = 0;
    m_PrecalculatedSize = 0;
    m_PalFormat = PAL_8888;
}
  
void Bitmap_Z::Invalidate() {
    //stub
};

void Bitmap_Z::Reset() {
    Invalidate();
    if (this->m_Datas) {
        Z_FreeContiguous(this->m_Datas);
    }
    this->m_Datas = 0;

    if (this->m_Palette) {
        delete this->m_Palette;
    }
    this->m_Palette = 0;

    Init();
}

void Bitmap_Z::InitBmap(S32 m_Width, S32 m_Height, U8 m_Format, U8* m_Palette, U8 m_Datas)
{
    //stub
}

//far from matching
Float Bitmap_Z::GetBytePerPixel() {
    Float result; // st7

    switch ( this->m_Format )
    {
      case BM_4:
        result = 0.5;
        break;
      case BM_8:
      case BM_I4A4:
        result = 1.0;
        break;
      case BM_5551:
      case BM_565:
      case BM_4444:
      case BM_1555:
        result = 2.0;
        break;
      case BM_8888:
        result = 4.0;
        break;
      case BM_888:
        result = 3.0;
        break;
      case BM_CMPR:
        result = 0.0;
        break;
      default:
        ExceptionFonc_Z("FALSE", "Bitmap_Z.cpp", 117, "Bitmap_Z::GetBytePerPixel", 0, 0, 0, 0, 0, 0);
        result = 0.0;
        break;
    }
    return result;
}
