#ifndef _MANIPULATOR_Z_H_
#define _MANIPULATOR_Z_H_
#include "BaseObject_Z.h"
class Manipulator_Z : public BaseObject_Z {

private: 
    Manipulator_Z* m_PreviousPtr;
    Manipulator_Z* m_NextPtr;
    S32 m_ManipGroup; //TODO: Define enum for this
    Bool m_IsActive;
    Float m_TimeSpentRunning;
};

#endif
