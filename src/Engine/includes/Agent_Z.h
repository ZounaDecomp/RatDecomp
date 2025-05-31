#ifndef _AGENT_Z_H_
#define _AGENT_Z_H_
#include "ABC_Agent.h"
#include "ABC_Category_Engine.h"
class Agent_Z : public ABC_Agent {

private:
    Float m_UnkFloat0x40; // $VIOLET: both floats are set as the same value when initialized
    Float m_UnkFloat0x44;
    DynArray_Z<abc_category> m_NonResetableCategories; // $VIOLET: not in Wii????? might be wrong. going off jimmy dwarf
    S32 m_ClassSoundIndex; // $VIOLET: Jimmy DWARF
    S32 m_NodeHdl; // $VIOLET: update both with proper typing when we get there.
    S32 m_GameHdl; 
    U32 m_AgentFlags;
};
#endif
