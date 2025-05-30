#include "Object_Z.h"
#include "Sys_Z.h"

Object_Z::Object_Z() {
    m_Type = 0;
    m_Flag = 0xffe30;
    Clean();
}

void Object_Z::Clean() {
    m_FadeOutDistance = 0.0f;
}

Bool Object_Z::MarkHandles() {
}

void Object_Z::UpdateObject(Node_Z* i_Node, ObjectDatas_Z* i_Data) {
}

void Object_Z::LoadLinks(void** i_Data) {
}

void Object_Z::EndLoadLinks() {
}

void Object_Z::Load(void** i_Data) {
}

void Object_Z::EndLoad() {
}

void Object_Z::Draw(DrawInfo_Z& a1, ObjectDatas_Z* i_Data) {
    Clean();
}

ObjectDatas_Z::ObjectDatas_Z() {
    m_Flag = 0;
    m_DefaultColor.m_Red = 1.0f;
    m_DefaultColor.m_Green = 1.0f;
    m_DefaultColor.m_Blue = 1.0f;
    m_DefaultColor.m_Alpha = 1.0f;
}

void ObjectDatas_Z::Clone(ObjectDatas_ZHdl& o_ObjectDatasHdl, Object_ZHdl& o_ObjectHdl) {
    ASSERTLE_Z(o_ObjectDatasHdl.IsValid(), "", 126, "_ObjectDatasHdl.IsValid()");
    ObjectDatas_Z* l_ObjectDatas = (ObjectDatas_Z*)GETPTR(o_ObjectDatasHdl);
    l_ObjectDatas->m_DefaultColor = m_DefaultColor;
    l_ObjectDatas->m_Flag = m_Flag | FL_OBJECTDATAS_CLONED;
    l_ObjectDatas->SetName(m_Name, false);
}

void ObjectDatas_Z::Load(void** i_Data) {
    *i_Data = Sys_Z::MemCpyFrom(&m_Flag, *i_Data, 0x14);
    return;
}

Bool ObjectDatas_Z::MarkHandles() {
    U32 l_Result = ResourceObject_Z::MarkHandles();
    return l_Result;
}

void ObjectDatas_Z::Draw(DrawInfo_Z& i_DrawInfo) { }
