#ifndef _MANIPULATOR_Z_H_
#define _MANIPULATOR_Z_H_
#include "ActivableGroups_Z.h"
#include "BaseObject_Z.h"
#include "Types_Z.h"

class ManipulatorManager_Z;
class ManipulatorList_Z;

class Manipulator_Z : public BaseObject_Z {
    friend class ManipulatorManager_Z;
    friend class ManipulatorList_Z;

public:
    Manipulator_Z();
    void Activate();
    void Deactivate();
    void SetGroup(ActivableGroup_Z i_Group);
    void Heartbeat(Float i_DeltaTime);
    virtual void Init();
    virtual ~Manipulator_Z();
    virtual void Reset();
    virtual void ActionOnActive();
    virtual void ActionOnDeactivate();
    virtual void Update(Float i_DeltaTime) = 0;

    inline ActivableGroup_Z GetGroup() { return m_ManipGroup; }

private:
    Manipulator_Z* m_PreviousPtr;
    Manipulator_Z* m_NextPtr;
    ActivableGroup_Z m_ManipGroup; //TODO: Define enum for this
    Bool m_IsActive;
    Float m_TimeSpentRunning;
};

#endif
