#include "Txt_Z.h"
#include "Sys_Z.h"

void Txt_Z::Load(void** i_Data) {
    S32 l_Unk;
    MEMCPYFROM_Z(&l_Unk, *i_Data, sizeof(S32));
    m_File.Init(l_Unk, NULL);
    MEMCPYFROM_Z(m_File.GetBuf(), *i_Data, m_File.GetSize());
}
