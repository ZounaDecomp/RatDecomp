#ifndef _ANIMATIONMANAGER_Z_H_
#define _ANIMATIONMANAGER_Z_H_
#include "ClassNameResManager_Z.h"

class AnimationManager_Z : public ClassNameResManager_Z {
public:
    AnimationManager_Z();

    virtual Bool MarkHandles();
    virtual Bool Minimize();
    virtual ~AnimationManager_Z();

    U32 GetMeshByName(const Name_Z& i_Name);

private:
};

#endif
