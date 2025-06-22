#include "Surface_Z.h"

void Surface_Z::GetQuadPatchCtrlPoint(const Patch& i_Patch, QuadCtrlPoint_Z& o_QuadCtrlPoint) {
    // m_Vertices on the corners
    o_QuadCtrlPoint.ControlPoints[0][0] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[0]].P[i_Patch.Flag & EDGE1 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[0][3] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[1]].P[i_Patch.Flag & EDGE2 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[3][3] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[2]].P[i_Patch.Flag & EDGE3 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[3][0] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[3]].P[i_Patch.Flag & EDGE4 ? 1 : 0]]);

    // First side
    o_QuadCtrlPoint.ControlPoints[0][1] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[0]].T[i_Patch.Flag & EDGE1 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[0][2] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[0]].T[i_Patch.Flag & EDGE1 ? 0 : 1]]);

    // Second side
    o_QuadCtrlPoint.ControlPoints[1][3] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[1]].T[i_Patch.Flag & EDGE2 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[2][3] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[1]].T[i_Patch.Flag & EDGE2 ? 0 : 1]]);

    // Third side
    o_QuadCtrlPoint.ControlPoints[3][2] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[2]].T[i_Patch.Flag & EDGE3 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[3][1] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[2]].T[i_Patch.Flag & EDGE3 ? 0 : 1]]);

    // Fourth side
    o_QuadCtrlPoint.ControlPoints[2][0] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[3]].T[i_Patch.Flag & EDGE4 ? 1 : 0]]);
    o_QuadCtrlPoint.ControlPoints[1][0] = Vec4f(m_Vertices[m_EdgeTab[i_Patch.EdgeIndices[3]].T[i_Patch.Flag & EDGE4 ? 0 : 1]]);

    // Calculate central points from adjacent corner and side points
    o_QuadCtrlPoint.ControlPoints[1][1] = (o_QuadCtrlPoint.ControlPoints[1][0] + o_QuadCtrlPoint.ControlPoints[0][1]) - o_QuadCtrlPoint.ControlPoints[0][0];
    o_QuadCtrlPoint.ControlPoints[1][2] = (o_QuadCtrlPoint.ControlPoints[0][2] + o_QuadCtrlPoint.ControlPoints[1][3]) - o_QuadCtrlPoint.ControlPoints[0][3];
    o_QuadCtrlPoint.ControlPoints[2][1] = (o_QuadCtrlPoint.ControlPoints[3][1] + o_QuadCtrlPoint.ControlPoints[2][0]) - o_QuadCtrlPoint.ControlPoints[3][0];
    o_QuadCtrlPoint.ControlPoints[2][2] = (o_QuadCtrlPoint.ControlPoints[2][3] + o_QuadCtrlPoint.ControlPoints[3][2]) - o_QuadCtrlPoint.ControlPoints[3][3];
}
