#include "Handle_Z.h"
#include "Program_Z.h"
#include "Node_Z.h"
void Node_Z::UpdateTM(Node_Z *i_Parent)
{

}

void Node_Z::UpdateRootTM()
{
    
}

BaseObject_Z* HandleManager_Z::GetPtr(const BaseObject_ZHdl& i_Hdl) const {    
    const HandleRec_Z& l_HdlRec = m_HandleRecDA[i_Hdl.GetID()];
    if (i_Hdl.GetKey() == l_HdlRec.m_Key) {
        if (l_HdlRec.m_xRamBlock >= 0) {
            return gData.ClassMgr->GetPtrXRam(l_HdlRec);
        }
        return l_HdlRec.m_ObjPtr;
    }
    return NULL;
}
