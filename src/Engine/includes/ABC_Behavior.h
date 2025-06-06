#ifndef _ABC_BEHAVIOR_H_
#define _ABC_BEHAVIOR_H_
#include "Types_Z.h"
class ABC_Behavior;
class ABC_Agent;
class ABC_CategoryData;

typedef int behavior_result;
enum behavior_state_type
{
	behavior_activate,
	behavior_deactivate,
	behavior_restart,
	behavior_is_active,
	behavior_is_started,
	behavior_get_name,
	behavior_get_state,
	behavior_init,
	behavior_declaration,
	behavior_start_condition,
	behavior_start_action,
	behavior_finish_condition,
	behavior_finish_action,
	behavior_alternative,

	behavior_condition,
	behavior_action,

	behavior_fsm_states = behavior_condition
};

typedef behavior_result (ABC_Agent::*behaviorMethodPtr)(behavior_state_type behavior_state, ABC_Behavior * aBehavior);

class ABC_Behavior {
public: 
    ABC_Behavior();
    void Reset();
    ~ABC_Behavior();
    void SetLocalDataSize(S32 i_Size);
    void LoadLocalVariables(void* i_Data);
    void StoreLocalVariables(const void* i_Data);
private:
    ABC_Behavior* m_Next;
    ABC_CategoryData* m_CategoryListHead;
    behaviorMethodPtr m_Behavior;
    void* m_LocalData;
    S32 m_LocalDataSize;
    U16 m_BehaviorFlags;
    S16 m_BehaviorState;
};

#endif
