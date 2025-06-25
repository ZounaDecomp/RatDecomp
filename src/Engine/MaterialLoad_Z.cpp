#include "GCMain_Z.h"
#include "Material_Z.h"
#include "ResourceObject_Z.h"
#include "Sys_Z.h"
extern GCGlobals gData;
void Material_Z::Load(void** i_Data) {
    *i_Data = Sys_Z::MemCpyFrom(&m_DiffuseColor, *i_Data, (int)&m_TextureFlags - (int)&m_DiffuseColor + sizeof(char));
    for (S32 i = 0; i < mtl_nb_params; i++) {
        gData.ClassMgr->LoadLink(m_CurBmapHdl[i], i_Data);
    }
}

void Material_Z::EndLoad() {
    ResourceObject_Z::EndLoad();
    for (S32 i = 0; i < mtl_nb_params; i++) {
        gData.ClassMgr->UpdateLink(m_CurBmapHdl[i]);
    }
    Changed();
}
