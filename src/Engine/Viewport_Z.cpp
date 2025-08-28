#include "Viewport_Z.h"

Viewport_Z::Viewport_Z() {
    m_NumOfManipDraws = 0;
    Init();
}

void Viewport_Z::Init() {
    m_Renderer = NULL;
    m_VCenter = -1.0f;
    m_HCenter = -1.0f;
    m_VSize = -1.0f;
    m_HSize = -1.0f;
    m_VRatio = -1.0f;
    m_HRatio = -1.0f;
    m_Ratio = -1.0f;
    m_DFov = -1.0f;
    m_IdxInMat4x4Buffer = -1;
}
