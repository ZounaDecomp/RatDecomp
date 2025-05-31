#ifndef _ABC_AGENT_H_
#define _ABC_AGENT_H_
#include "BaseObject_Z.h"
#include "Handle_Z.h"

struct BehaviorMethod {
    S32 unk0;
    void* vtableOffset;
    S32 unk0x8;
};

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

class ABC_Behavior {
private:
    ABC_Behavior* m_Next;
    ABC_CategoryData* m_CategoryListHead;
    BehaviorMethod m_Behavior;
    void* m_LocalData;
    S32 m_LocalDataSize;
    U16 m_BehaviorFlags;
    S16 m_BehaviorState;
};

enum abc_agentState {
    agent_neverActivated = 0,
    agent_inactive = 1,
    agent_active = 2,
    agent_toBeActivated = 3,
}; // Jimmy DWARF

/* sizeof(ABC_Agent) == 0x40 */
class ABC_Agent : public BaseObject_Z {

private:
    abc_agentState m_AgentState;
    ABC_Agent* m_UnkAgent;
    ABC_Agent* m_UnkAgetnt2;
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
