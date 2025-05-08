#include "Bitmap_Z.h"
#include "Memory_Z.h"


// void Bitmap_Z::Load(void** i_BigFile)
// {
//     U8* l_Header;
//     Sys_Z::MemCpyFrom((void*)l_Header, *i_BigFile, 0x14);

// }

void Bitmap_Z::Clean() 
{
    U8 l_Format = m_Format;
    Bitmap_Z::Reset();
    m_Format = l_Format;
    m_TrueFormat = l_Format;
}
