#ifndef _ABC_AGENT_H_
#define _ABC_AGENT_H_
#include "BaseObject_Z.h"
#include "Handle_Z.h"
#include "ABC_Behavior.h"

class ABC_Message {
private:
    BaseObject_ZHdl m_Sender;
    abc_message m_MessageID;
    ABC_Message* m_Next;
    Float m_Time;
    Float m_MessageParameter;
};

class ABC_CategoryData {
private:
    ABC_CategoryData* m_Next;
    S32 m_Category;
    Char isPublic;
};

enum abc_agentState {
    agent_neverActivated = 0,
    agent_inactive = 1,
    agent_active = 2,
    agent_toBeActivated = 3,
}; // Jimmy DWARF

/* sizeof(ABC_Agent) == 0x40 */
class ABC_Agent : public BaseObject_Z {
public: 
    ABC_Agent();
    ~ABC_Agent();
    void GetBehavior(behaviorMethodPtr i_Behav);
    void Receive(abc_message i_Message, const BaseObject_ZHdl& i_Sender, Float i_Param);
private:
    abc_agentState m_AgentState;
    ABC_Agent* m_UnkAgent;
    ABC_Agent* m_UnkAgent2;
    Bool changeInBehaviorList;
    ABC_Behavior* m_BehaviorListHead;
    ABC_Message* m_MessageListHead;
    ABC_Message* m_MessageListTail;
    ABC_Message* m_BufferMessageListHead;
    ABC_Message* m_BufferMessageListTail;
    BaseObject_ZHdl m_Sender;
    S32 m_Unk0x34;
    S32 m_Unk0x38;
    U32 m_AbcAgentFlags;
};

#endif
