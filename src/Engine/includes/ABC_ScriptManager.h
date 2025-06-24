#ifndef _ABC_SCRIPT_MANAGER_H_
#define _ABC_SCRIPT_MANAGER_H_
#include "Renderer_Z.h"
#include "Node_ZHdl.h"
#include "Game_ZHdl.h"
#include "World_ZHdl.h"
class Message_Z;
class RegMessage_Z;
class ABC_ScriptManager
{
    virtual ~ABC_ScriptManager();
    virtual void Init();
    virtual void Shut();
    virtual void MarkHandles();
    virtual void Draw(DrawInfo_Z& a1);
    virtual void ReadEnumFromFiles();
    virtual void NoteTrackGlobalFlag(Message_Z& a1);
    virtual void MateriaInterpColFlag(const Char* a1);
    virtual void MateriaInterpRdrFlag(const Char* a1);
    virtual void MateriaInterpObjFlag(const Char* a1);
    virtual void MateriaRemoveColFlag(const Char* a1);
    virtual void MateriaRemoveRdrFlag(const Char* a1);
    virtual void MateriaRemoveObjFlag(const Char* a1);
    virtual void InterGraphFlag(const Char* a1);
    virtual void InterGraphFlag(U64 a1);
    virtual void GameSet(const Game_ZHdl& a1);
    virtual void GameAgentSet(const Game_ZHdl& a1);
    virtual void RemoveGame(const Game_ZHdl& a1);
    virtual void GameRemoved();
    virtual void GameReseted(const Game_ZHdl& a1);
    virtual void ActivateGame(const Game_ZHdl& a1);
    virtual void ViewportDone(const Game_ZHdl& a1);
    virtual void WorldAdded(const World_ZHdl& a1);
    virtual void UpdateIndependentResources(const World_ZHdl& a1);
    virtual void InterpKeyframeMsg(const RegMessage_Z& a1);
    virtual void StreamRestored(const Node_ZHdl& a1);
    virtual void StreamRemoving(const Game_ZHdl& a1, const Node_ZHdl& a2);
    virtual void StreamDone(const Game_ZHdl& a1, const Node_ZHdl& a2);
    virtual void StreamDone(const Game_ZHdl& a1, S32 a2);
    virtual void Update(Float a1);
    virtual void Minimize();
};

#endif
