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
    this->flag = 0;
    Bitmap_Z::EnableFlag(0x14);
    this->dataPointer = 0;
    this->palPointer = 0;
    this->width = 0;
    this->height = 0;
    this->formatCopy = 0;
    this->unkSetTo4 = 4;
    this->texID = -1;
    this->transpFormat = -1;
    this->mipmapCount = 0;
    this->precalculatedSize = 0;
    this->paletteFormat = 3;
}
  
