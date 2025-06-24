#include "Material_Z.h"
#include "Sys_Z.h"
void Material_Z::Load(void** i_Data) {
    *i_Data = Sys_Z::MemCpyFrom(&m_DiffuseColor, *i_Data, (int)this - (0xb0 - (int)&m_DiffuseColor) + sizeof(char) );
    for (S32 i = 0; i < mtl_nb_params; i++) {
        gData.ClassMgr->LoadLink(m_CurBmapHdl[i], i_Data);
    }
}
