#include "ActionHelper_G.h"

void ActionHelper_G::Init() {
    ManipulatorSceneDraw_Z::Init();
}

void ActionHelper_G::Activate() {
    ManipulatorSceneDraw_Z::Activate();
}

void ActionHelper_G::Reset() {
    m_ActionHelperDA.Empty();
    m_ActionHelperDA.Minimize();
}

Bool ActionHelper_G::Minimize() {
    m_ActionHelperDA.Minimize();
    return TRUE;
}
