#include "Points_Z.h"
#include "Sys_Z.h"

void Points_Z::Load(void** i_Data) {
    Object_Z::Load(i_Data);

    S32 l_Nb;

    *i_Data = Sys_Z::MemCpyFrom(&l_Nb, *i_Data, 4);
    m_Vertices.SetSize(l_Nb);
    *i_Data = Sys_Z::MemCpyFrom(m_Vertices.GetArrayPtr(), *i_Data, l_Nb * sizeof(Vec3f));

    *i_Data = Sys_Z::MemCpyFrom(&l_Nb, *i_Data, 4);
    m_TangentBinormalVertices.SetSize(l_Nb);
    *i_Data = Sys_Z::MemCpyFrom(m_TangentBinormalVertices.GetArrayPtr(), *i_Data, l_Nb * sizeof(TBVtx));

    m_Morpher.Load(i_Data);
}

void Points_Z::Clean() {
    Object_Z::Clean();

    m_Vertices.SetSize(0);
    m_TangentBinormalVertices.SetSize(0);
}
