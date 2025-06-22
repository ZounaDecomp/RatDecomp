#include "Manipulator_Z.h"
#include "ActivableGroups_Z.h"
#include "GCMain_Z.h"

Manipulator_Z::Manipulator_Z() {
    m_PreviousPtr = NULL;
    m_NextPtr = NULL;
    m_IsActive = FALSE;
    m_ManipGroup = ag_no_group;
    m_TimeSpentRunning = 0.0f;
}

Manipulator_Z::~Manipulator_Z() {
    if (gData.ManipMgr != NULL)
        gData.ManipMgr->Remove(this);
}

void Manipulator_Z::Init() {
    if ((m_IsActive) || (m_ManipGroup != 18)) {
        ASSERTLENF_Z(!m_IsActive && m_ManipGroup == ag_no_group, "", 24, "!bActive && Group==ag_no_group");
    }
    gData.ManipMgr->Add(this);
}

void Manipulator_Z::Activate() {
    if (!m_IsActive) {
        gData.ManipMgr->Activate(this);
        m_IsActive = TRUE;
        ActionOnActive();
    }
}

void Manipulator_Z::Deactivate() {
    if (m_IsActive) {
        gData.ManipMgr->Deactivate(this);
        m_IsActive = FALSE;
        ActionOnDeactivate();
    }
}

void Manipulator_Z::SetGroup(ActivableGroup_Z i_Group) {
    if (i_Group != m_ManipGroup) {
        gData.ManipMgr->Order(this, i_Group);
    }
}

void Manipulator_Z::Heartbeat(Float i_DeltaTime) {
    m_TimeSpentRunning += i_DeltaTime;
    Update(i_DeltaTime);
}
