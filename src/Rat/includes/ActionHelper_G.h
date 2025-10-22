#ifndef _ACTIONHELPER_G_H_
#define _ACTIONHELPER_G_H_
#include "Manipulator_Z.h"
#include "Math_Z.h"
#include "Game_ZHdl.h"

class ActionHelperInfos;
class SubParticlesActionHelper;
class Node_Z;
class BoneNode_Z;
class MissionDef_G;

typedef DynArray_Z<ActionHelperInfos, 4> ActionHelperInfosDA;

#define ACTIONHELPER_SUBPARTICLE_ARRAY_SIZE 6

struct SubParticlesActionHelper {
    S32 m_MaterialIndex;
    Float m_UnkFloat_0x4;
    Float m_UnkFloat_0x8;
    Float m_DelayTimer;
    Float m_CurrentLifeTimeLeft;
    Float m_MaxLifeTime;
    Float m_UnkFloat_0x18;
    Float m_UnkFloat_0x1c;
    Float m_MaxTimeForSomething;
    Float m_CurrentTimeForSomething;
    Float m_LifeProgress; // $SABE: Life time range from 0-1 (1 being max time elapsed)
};

struct ActionHelperInfos {
    SubParticlesActionHelper m_SubPartricles[ACTIONHELPER_SUBPARTICLE_ARRAY_SIZE];
    Bool m_UnkBool_0x108;
    Bool m_UnkBool_0x109;
    Bool m_UnkBool_0x10a;
    Bool m_UnkBool_0x10b;
    Bool m_IsActiveOrSomething;
    Bool m_IsOnScreen;
    Float m_TimeSpentOnScreen;
    Float m_OtherTime;
    Bool m_IsHidden;
    Float m_MaybeOpacity;
    Bool m_HasOffset;    // $SABE: May be m_HasMagnet (related to magnet sphere)
    Vec3f m_LocalOffset; // $SABE: Position offset in Node local space
    Node_Z* m_Node;
    BoneNode_Z* m_BoneNode;
    MissionDef_G* m_MissionDef;
};

// $SABE: Action helper "manager"
class ActionHelper_G : public ManipulatorSceneDraw_Z {
public:
    Bool Minimize();

private:
    virtual void Init();                             /* 0x08 */
    virtual ~ActionHelper_G();                       /* 0x0C */
    virtual void Reset();                            /* 0x10 */
    virtual void Update(Float i_DeltaTime);          /* 0x14 */
    virtual void Draw(const DrawInfo_Z& i_DrawInfo); /* 0x18 */
    virtual void Activate();                         /* 0x1C */

private:
    Game_ZHdl m_GameHdl;
    ActionHelperInfosDA m_ActionHelperDA; // $SABE: DynArray of all action helpers
};

#endif // _ACTIONHELPER_G_H_
