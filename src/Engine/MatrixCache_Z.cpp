#include "MatrixCache_Z.h"

Mat4x4Buffer_Z::Mat4x4Buffer_Z() {
    m_CurBuffer = 0;
    m_TotalMatNb = 0;
    m_MaxInUseMatNb = 0;
    m_FreeMatNb = 0;
    m_FreeMatDbIdNb = 0;
}
