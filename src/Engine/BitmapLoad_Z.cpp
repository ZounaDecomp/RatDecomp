#include "Bitmap_Z.h"
#include "Memory_Z.h"
#include "Sys_Z.h"

void Bitmap_Z::Load(void **i_Data) {
    S32 l_DataSize;
    S32 l_AmountOfColors; 
    S32 l_PalSize; 

    *i_Data = Sys_Z::MemCpyFrom(&m_SizeX, *i_Data, ((U8*)&m_Flag) - ((U8*)&m_SizeX) + sizeof(U16));
    if (m_PrecalculatedSize)
    {
        m_Datas = AllocContiguousAlignCL_Z(m_PrecalculatedSize, "BITMAP_DATA_ALLOC", 13, 0x80);
        *i_Data = Sys_Z::MemCpyFrom(m_Datas, *i_Data, m_PrecalculatedSize);
    }
    else {
        l_DataSize = GetDataSize();
        m_Datas = AllocContiguousAlignCL_Z(l_DataSize, "BITMAP_DATA_ALLOC", 18, 0x80);
        *i_Data = Sys_Z::MemCpyFrom(m_Datas, *i_Data, l_DataSize);
    }
    l_AmountOfColors = GetPalSize();
    if (l_AmountOfColors != 0)
    {
        l_PalSize = 4 * l_AmountOfColors;
        m_Palette = AllocAlignCL_Z(l_PalSize, "BITMAP_PAL_ALLOC", 26, 0x80);
        *i_Data = Sys_Z::MemCpyFrom(m_Palette, *i_Data, l_PalSize);
    }
}


void Bitmap_Z::Clean() 
{
    U8 l_Format = m_Format;
    Reset();
    m_Format = l_Format;
    m_TrueFormat = l_Format;
}
