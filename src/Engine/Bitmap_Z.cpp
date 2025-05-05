#include "Bitmap_Z.h"
#include "Memory_Z.h"

extern "C" void memcpy(void* dest, const void* src, S32 n);
#pragma dont_inline on
Bitmap_Z::Bitmap_Z()
{
    Init();
}

Bitmap_Z::Bitmap_Z(S32 i_Width, S32 i_Height, U8 i_Format, U8* i_Datas)
{
    Init();
    InitBmap(i_Width, i_Height, i_Format, i_Datas, 0);
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
    m_TexID = INVALID_TEXID;
    m_Transp = -1;
    m_MipmapCount = 0;
    m_PrecalculatedSize = 0;
    m_PalFormat = PAL_8888;
}

void Bitmap_Z::Reset() {
    Invalidate();
    if (m_Datas) {
        FreeContiguous_Z(m_Datas);
    }
    m_Datas = 0;

    if (m_Palette) {
        Delete_Z m_Palette;
    }
    m_Palette = 0;

    Init();
}

void Bitmap_Z::InitBmap(S32 i_SizeX, S32 i_SizeY, U8 i_Format, U8* i_Datas, U8* i_Palette) { // far from complete
    S32 l_PaletteSize;
    S32 l_BytePalleteSize;

    m_TexID = INVALID_TEXID;
    m_SizeX = i_SizeX;
    m_SizeY = i_SizeY;
    m_Format = i_Format;
    m_TrueFormat = i_Format;
    m_MipmapCount = 0;

    l_PaletteSize = GetPalSize();
    GetBytePerPixel();

    if (i_Format  == BM_4 || i_Format == BM_8) {
        l_BytePalleteSize = 4 * l_PaletteSize;
        m_Palette = AllocAlignCL_Z(l_BytePalleteSize, 128, "BITMAP_PAL_ALLOC", 74);
        if (i_Palette)
            memcpy(m_Palette, i_Palette, l_BytePalleteSize);
    }
    else {
        m_Palette = 0;
    }

    if (i_Datas)
    {
        SetUniversal(i_Datas);
    }
    else
    {
        m_Datas = AllocContiguousAlignCL_Z(GetDataSize(), 128, "BITMAP_DATA_ALLOC", 92);

        Clear(Color(0.0, 0.0, 0.0, 0.0));
    }

}

Float Bitmap_Z::GetBytePerPixel() {
    Float l_Result; // st7

    switch (m_Format) {
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
            ASSERTL_Z(FALSE, "Bitmap_Z::GetBytePerPixel", 117);
            l_Result = 0.0;
            break;
    }
    return l_Result;
}

S32 Bitmap_Z::GetPalSize()
{
    switch (GetFormat())
    {
        case BM_4:
            return 16;
        case BM_8:
            return 256;
        case BM_5551:
        case BM_565:
        case BM_4444:
        case BM_1555:
        case BM_8888:
        case BM_888:
        case BM_CMPR:
        case BM_I4A4:
            return 0;
        default:
            ASSERTL_Z(FALSE, "Bitmap_Z::GetPalSize", 138);
            return 0;
    }
}

S32 Bitmap_Z::GetDataSize()
{
    S32 l_MipSize;
    S32 l_DataSize;
    U8 l_MipmapCount;
    l_DataSize = (GetBytePerPixel() * ((Float)m_SizeY * m_SizeX));
    l_MipmapCount = m_MipmapCount;
    for ( l_MipSize = l_DataSize; l_MipmapCount--; l_MipSize += (l_DataSize + 127) & ~127)
    {
        l_DataSize >>= 2;                          
    }
    return l_MipSize;
}

S32 Bitmap_Z::GetNbEntries()
{
    U8 l_Format = m_Format;
    if (l_Format == BM_4)
        return 16;
    else
        return l_Format == BM_8 ? 256 : 0;
}

// $VIOLET: This function might make me become religious
U16 Bitmap_Z::GetColor(const Color& i_Color)
{
    U16 l_ReturnValue = 0;
    U32 l_NewRed, l_NewGreen, l_NewBlue, l_NewAlpha;
    U16 l_Red = (U16)(i_Color.m_Red * 255.0f);
    U16 l_Green = (U16)(i_Color.m_Green * 255.0f);
    U16 l_Blue = (U16)(i_Color.m_Blue * 255.0f);
    U16 l_Alpha = (U16)(i_Color.m_Alpha * 255.0f);

    switch (m_Format)
    {
        // $Violet: The comments following will give the colors with correct logic formatting, in their correct ASM order
        case BM_565:
            //green, blue, red.  in wrong order. because of course
            l_NewRed = ((l_Red & 0xFFF8) << 8);
            l_NewGreen = ((l_Green & 0xFFFC) << 3);
            l_NewBlue = ((l_Blue >> 3) & 0x1FFF);

            l_ReturnValue = l_NewRed + l_NewBlue + l_NewGreen;

            return l_ReturnValue & 0xFFFF;
        case BM_5551:
            l_NewRed = ((l_Red & 0xFFF8) << 8);
            l_NewGreen = ((l_Green & 0xFFE0) << 2);
            l_NewBlue = ((l_Blue >> 3) & 0x1FFF);
            l_NewAlpha = ((l_Alpha & 0xFF80) << 8);
            l_ReturnValue = l_NewRed + l_NewBlue + l_NewGreen;

            return l_ReturnValue & 0xFFFF;
        case BM_4444:
            return (l_Blue >> 4) + (l_Green >> 4 << 4) + (l_Red >> 4 << 8) + (l_Alpha >> 4 << 12);
        case BM_1555:
            return (l_Alpha >> 7) + (l_Blue >> 3 << 1) + (l_Green >> 3 << 6) + (l_Red >> 3 << 11);
        case BM_4:
        case BM_8:
            return GetBestPalEntry(l_Red, l_Green, l_Blue, l_Alpha);
        default:
            return l_ReturnValue;
    }
}

#pragma optimize_for_size on 
U8 Bitmap_Z::GetBestPalEntry(U8 i_Red, U8 i_Green, U8 i_Blue, U8 i_Alpha)
{
    Float l_CmpValue = 1024*1024*1024;
    Float l_Match = 0;
    U8 l_BestMatch = -1;
    U8 l_Red, l_Green, l_Blue, l_Alpha = 0;
    
    for (S32 i = 0; i < GetNbEntries(); i++)
    {
        if (m_PalFormat == PAL_8888)
        {
            U8* l_Palette = (U8*)m_Palette;
            l_Red = l_Palette[4 * i];
            l_Green = l_Palette[4 * i + 1];
            l_Blue = l_Palette[4 * i + 2];
            l_Alpha = l_Palette[4 * i + 3];
        }
        else if (m_PalFormat == PAL_565)
        {
            U16* l_Palette = (U16*)m_Palette;
            l_Red = (l_Palette[i] >> 8) & 0xF8;
            l_Green = (l_Palette[i] >> 3) & 0xFC;
            l_Blue = (l_Palette[i] & 0x1F) << 3;
            l_Alpha = -1;
        }
        else 
        {
            U16* l_Palette = (U16*)m_Palette;
            l_Red = (l_Palette[i] >> 4) & 0xF0;
            l_Green = (l_Palette[i]) & 0xF0;
            l_Blue = (l_Palette[i] << 4) & 0xF0;
            l_Alpha = (l_Palette[i] >> 7) & 0xE0;
        }

        l_Match = 
                ((Float)(l_Red - i_Red) * (Float)(l_Red - i_Red)) + 
                ((l_Green - i_Green) * (l_Green - i_Green)) + 
                ((l_Blue - i_Blue) * (l_Blue - i_Blue)) + 
                ((l_Alpha - i_Alpha) * (l_Alpha - i_Alpha));
        
        if (l_Match < l_CmpValue)
        {
            l_CmpValue = l_Match;
            l_BestMatch = i;
        }
    }
    
    return l_BestMatch;
}

void Bitmap_Z::SetDatas(U8* i_Datas)
{
    if (i_Datas != m_Datas)
    {
        if (m_Datas)
        {
            FreeContiguous_Z(m_Datas);
        }
        m_Datas = 0;
        m_Datas = i_Datas;
    }
}

Bitmap_Z::~Bitmap_Z()
{
    Reset();
}

#pragma optimize_for_size off
#pragma dont_inline off
