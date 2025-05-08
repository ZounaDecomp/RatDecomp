#ifndef _ANIMATIONMANAGER_Z_H_
#define _ANIMATIONMANAGER_Z_H_
#include "ClassNameResManager_Z.h"

class AnimationManager_Z : public ClassNameResManager_Z {
    AnimationManager_Z();

    virtual Bool MarkHandles();
    virtual Bool Minimize();
    virtual ~AnimationManager_Z();
};

#endif
