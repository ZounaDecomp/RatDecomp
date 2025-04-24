#ifndef _BITMAP_Z_H_
#define _BITMAP_Z_H_
#include "ResourceObject_Z.h"

class Bitmap_Z : public ResourceObject_Z
{
    public:
        Bitmap_Z();
        Bitmap_Z(S32 width, S32 height, U8 format, U8* palPointer);
        virtual void Init();
        virtual ~Bitmap_Z();
        virtual void Load(void* a1);
        virtual void Clean();
        void InitBmap(S32 width, S32 height, U8 format, U8* palPointer, U8 dataPointer);
        void EnableFlag(U8 _Flag)   {Flag|=_Flag;}
    private:
        void* dataPointer;
        void* palPointer;
        S16 texID;
        U32 width;
        U32 height;
        U32 precalculatedSize;
        U8 format;
        U8 formatCopy;
        U8 paletteFormat;
        U8 transpFormat;
        U8 mipmapCount;
        U8 unkSetTo4;
        U8 flag;
        U8 dontDelete;

};
#endif
