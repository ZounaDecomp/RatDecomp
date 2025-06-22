#include "ABC_Agent.h"

ABC_Agent::ABC_Agent() {
    m_AgentState = agent_neverActivated;
    m_UnkAgent = NULL;
    m_UnkAgent2 = NULL;
    m_Sender = 0;
    m_MessageListHead = NULL;
    m_MessageListTail = NULL;
    m_BufferMessageListHead = NULL;
    m_BufferMessageListTail = NULL;
    m_BehaviorListHead = NULL;
    m_AbcAgentFlags = NULL;
}

ABC_Agent::~ABC_Agent() { }

void ABC_Agent::GetBehavior(behaviorMethodPtr i_Behav) {
}
