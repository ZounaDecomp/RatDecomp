#ifndef _RENDERER_Z_H_
#define _RENDERER_Z_H_
#include "SystemObject_Z.h"

struct DrawInfo_Z {
    Mat4x4 Local2Cam;
    Mat4x4 World2Cam;
    Box_Z m_Box;

public:
    DrawInfo_Z() { }
};

class Renderer_Z {
    void Draw(S32 i_ViewportId, Float i_DeltaTime);
};

#endif
