#ifndef _AGENT_Z_H_
#define _AGENT_Z_H_
#include "ABC_Agent.h"

class Agent_Z : public ABC_Agent {

private:
    Float m_MaxSqrDistActive;
    Float m_MinSqrDistActive;
    CategoryArray m_NonResetableCategories;
    S32 m_ClassSoundIndex; // $VIOLET: Jimmy DWARF
    S32 m_NodeHdl;         // $VIOLET: update both with proper typing when we get there.
    S32 m_GameHdl;
    U32 m_AgentFlags;
};
#endif
