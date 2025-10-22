#ifndef _SCRIPTMANAGER_G_H_
#define _SCRIPTMANAGER_G_H_
#include "ABC_ScriptManager.h"
#include "BaseInGameDatas_GHdl.h"
#include "UnLock_G.h"
class ActionHelper_G;

enum GameDifficulty {
    VeryEasy,
    Easy,
    Normal,
    Hard,
    Nightmare
};

class PlayerSaveStruct_G {
    S32 m_Health;
    S32 m_MaxHealth;
    S32 m_Lives;
};

class ScriptManager_G : public ABC_ScriptManager {

    virtual ~ScriptManager_G();                                                   /* 0x08 */
    virtual void Init();                                                          /* 0x0C */
    virtual void Shut();                                                          /* 0x10 */
    virtual void MarkHandles();                                                   /* 0x14 */
    virtual void ReadEnumFromFiles();                                             /* 0x18 */
    virtual void MateriaInterpColFlag(const Char* a1);                            /* 0x1C */
    virtual void MateriaInterpObjFlag(const Char* a1);                            /* 0x20 */
    virtual void MateriaRemoveColFlag(const Char* a1);                            /* 0x24 */
    virtual void GameSet(const Game_ZHdl& i_GameHdl);                             /* 0x28 */
    virtual void GameAgentSet(const Game_ZHdl& i_GameHdl);                        /* 0x2C */
    virtual void RemoveGame(const Game_ZHdl& i_GameHdl);                          /* 0x30 */
    virtual void GameReseted(const Game_ZHdl& i_GameHdl);                         /* 0x34 */
    virtual void ActivateGame(const Game_ZHdl& i_GameHdl);                        /* 0x38 */
    virtual void UpdateIndependentResources(const World_ZHdl& a1);                /* 0x3C */
    virtual void InterpKeyframeMsg(const RegMessage_Z& a1);                       /* 0x40 */
    virtual void StreamRemoving(const Game_ZHdl& i_GameHdl, const Node_ZHdl& a2); /* 0x44 */
    virtual void StreamDone(const Game_ZHdl& i_GameHdl, const Node_ZHdl& a2);     /* 0x48 */
    virtual void StreamDone(const Game_ZHdl& i_GameHdl, S32 a2);                  /* 0x4C */
    virtual void Update(Float a1);                                                /* 0x50 */
    virtual void Minimize();                                                      /* 0x54 */
    virtual void SetPlayer(S32 a1, ABC_AgentHdl a2);                              /* 0x58 */
    virtual void GetPlayer(S32 a1);                                               /* 0x5C */
    virtual void ResetGame(Game_ZHdl& i_GameHdl);                                 /* 0x60 */

    U8 m_Pad_0xc8[0xF8];
    GameDifficulty m_Difficulty;
    U8 m_Pad_0x1c4[0x6450];
    ActionHelper_G* m_ActionHelper;
    U8 m_Pad_0x6618[0x6c];
    BaseInGameDatas_GHdl m_InGameDatasHdl;
    U8 m_Pad_0x6688[0x20];
    UnLockEvents_G m_UnlockEvents;
    U8 m_Pad_0x66b0[0x44];
    PlayerSaveStruct_G m_PlayerSaveStruct;
    U8 m_Pad_0x6700[0x10];
};

#endif // _SCRIPTMANAGER_G_H_
