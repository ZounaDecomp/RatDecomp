#include "Bitmap_Z.h"

Bitmap_Z::Bitmap_Z()
{
    Init();
}

Bitmap_Z::Bitmap_Z(S32 width, S32 height, U8 format, U8* palPointer)
{
    Init();
    InitBmap(width, height, format, palPointer, 0);
}

Bitmap_Z::~Bitmap_Z()
{
    //stub
}

void Bitmap_Z::Init() {
    this->Flag = 0;
    Bitmap_Z::EnableFlag(0x14);
    this->Datas = 0;
    this->Palette = 0;
    this->SizeX = 0;
    this->SizeY = 0;
    this->trueFormat = 0;
    this->unkSetTo4 = 4;
    this->texID = -1;
    this->Transp = -1;
    this->MipmapCount = 0;
    this->precalculatedSize = 0;
    this->PalFormat = PAL_8888;
}
  