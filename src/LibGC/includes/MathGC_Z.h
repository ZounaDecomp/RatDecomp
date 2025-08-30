#ifndef _MATHGC_Z_H_
#define _MATHGC_Z_H_

#include "Math_Z.h"

void ConcatMat4x4(const Mat4x4&, const Mat4x4&, Mat4x4&);
void ConcatMat4x4AndConvert(const Mat4x4& a1, const Mat4x4& a2, Mat3x3& a3);
#endif
