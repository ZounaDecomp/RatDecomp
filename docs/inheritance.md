# Inheritance

Following is the inheritance pattern for classes.  This is specifically for Windows, however GC inheritance should be the same, just replacing their respective class names. 
This follows the pattern of `Class -> Base Class -> Base Class -> ........`
```ABC_Agent -> BaseObject_Z
ABC_ScriptManager
AStar_Z -> GraphSearch_Z
AStar_Z::NODE -> SearchNode_Z
ActionHelper_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
Agent_Z -> ABC_Agent -> BaseObject_Z
AnimFrame_Z -> ResourceObject_Z -> BaseObject_Z
AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
AnimationManager_Z -> ClassNameResManager_Z
Animation_Z -> ResourceObject_Z -> BaseObject_Z
AntSwarmGroupTriggerZone_G -> SwarmGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ArrowButtonsSet
ArrowButtonsSetWithText -> ArrowButtonsSet
BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
BaseInGameDatas_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
BaseIndexBuffer_Z -> IndexBuffer_Z
BaseObject_Z
BaseStream_Z
BaseVertexBuffer_Z -> VertexBuffer_Z
BehindCameraAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Bitmap_Z -> ResourceObject_Z -> BaseObject_Z
BlendMatPacket_Z -> ObjConstant_Z
Book -> Menu3DScenery
Breakable_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Button_G
CameraAgent_G -> CameraAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
CameraAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
CameraEngineZone_Z -> CameraEngine_Z -> Manipulator_Z -> BaseObject_Z
CameraEngine_Z -> Manipulator_Z -> BaseObject_Z
CameraFxVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
CameraMove_G -> CameraEngineZone_Z -> CameraEngine_Z -> Manipulator_Z -> BaseObject_Z
CameraOccluder_Z -> Manipulator_Z -> BaseObject_Z
CameraStream_Z -> Manipulator_Z -> BaseObject_Z
CameraUser_C -> CameraUser_Z -> Manipulator_Z -> BaseObject_Z
CameraUser_Z -> Manipulator_Z -> BaseObject_Z
CameraZone_Z -> SplineZone_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Camera_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Case -> Menu3DScenery
ChampionshipPurchase -> MultiPlayerPurchase -> Purchase
ChampionshipToBePlayed -> MultiPlayerGameToBePlayed -> IsToBePlayed
ChangeLevelVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
CharsData_G -> BaseObject_Z
CheatPurchase -> Purchase
CheckpointVolAgent_G -> VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ClassManager_Z -> HandleManager_Z
ClassNameResManager_Z
CollisionVol_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
ConditionVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ConsoleInterp_Z -> Manipulator_Z -> BaseObject_Z
Console_Z
CookingsessionPurchase -> SologamePurchase -> Purchase
CreaturesBoneManip -> Manipulator_Z -> BaseObject_Z
CreaturesGroupMove_G -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
CreaturesMgr_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
CreaturesMove_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
D3D_Renderer_Z -> Renderer_Z
DNameNode
DNameStatusNode -> DNameNode
DataManager_Z<struct _ParticleElement_Z>
DefaultConstant_Z -> ObjConstant_Z
DetectVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
DialogGroup_G -> BaseObject_Z
Dialog_ALERT -> Dialog_G
Dialog_AUTOSAVE -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_CHAMPIONSHIP -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_CHANGELEVEL -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_CHANGELEVELDEMO -> Dialog_G
Dialog_CHANGELEVELYESNO -> Dialog_G
Dialog_CHEATPURCHASE -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_CHOOSEMPEG -> Dialog_G
Dialog_COMMANDS -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_COOKINGSESSION -> Dialog_MiniGameSolo -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_CREATE -> Dialog_MC_Base -> Dialog_G
Dialog_CREDITS -> Dialog_G
Dialog_DELETE -> Dialog_MC_Base -> Dialog_G
Dialog_DIFFICULTY -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_DREAM -> Dialog_MiniGameSolo -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_ENABLEAUTOSAVE -> Dialog_SAVE -> Dialog_MC_Base -> Dialog_G
Dialog_ENDCHAMPIONSHIP -> Dialog_MINIGAMESUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERCHEATCODE -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERCHEATCODEJPN -> Dialog_ENTERCHEATCODE -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERPROFILENAME -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERPROFILENAMEJPN -> Dialog_ENTERPROFILENAME -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERYOURNAME -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ENTERYOURNAMEJPN -> Dialog_ENTERYOURNAME -> Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_ESCTOMAIN -> Dialog_G
Dialog_EXTRAS -> Dialog_G
Dialog_G
Dialog_GAMEMODEPURCHASE -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_GAMEOVER -> Dialog_G
Dialog_IMAGE -> Dialog_Media -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_IMAGEVISUALISATION -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_INPUTSTRINGJPN -> Dialog_INPUTSTRING -> Dialog_MC_Base -> Dialog_G
Dialog_LANGUAGES -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_LEGALTEXT -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_LEVELSPURCHASE -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_LEVELSTATUS -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_LEVELSUCCESS -> Dialog_MISSIONSUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_LIFEUPGRADE -> Dialog_G
Dialog_LOAD -> Dialog_MC_Base -> Dialog_G
Dialog_LoadMaterialLib -> Dialog_G
Dialog_MAINMENUFIRST -> Dialog_MC_Base -> Dialog_G
Dialog_MC_Base -> Dialog_G
Dialog_MINIGAMEMULTI -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_MINIGAMESOLOMENU -> Dialog_G
Dialog_MINIGAMESUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_MISSIONCOLLECT -> Dialog_MISSIONSUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_MISSIONFAILED -> Dialog_G
Dialog_MISSIONSUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_MSGBOX -> Dialog_G
Dialog_Media -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_MiniGameSolo -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_NEXTPLAYER -> Dialog_G
Dialog_NEXTROUND -> Dialog_G
Dialog_OBJECTIVES -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_OPTIONSGAME -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_OPTIONSMAIN -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_OPTIONSSOUND -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_OPTIONSVIDEO -> Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_Options -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_PAUSEMAIN -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_PRESSSTART -> Dialog_MC_Base -> Dialog_G
Dialog_PROFILES -> Dialog_MC_Base -> Dialog_G
Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_RESULT -> Dialog_MINIGAMESUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_ROUGH -> Dialog_Media -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_SAVE -> Dialog_MC_Base -> Dialog_G
Dialog_SAVEINGAME -> Dialog_MC_Base -> Dialog_G
Dialog_SECRETS -> Dialog_MC_Base -> Dialog_G
Dialog_SETUPCHAMPIONSHIP1 -> Dialog_G
Dialog_SETUPCHAMPIONSHIP2 -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_SETUPMULTIGAME -> Dialog_G
Dialog_SHOPMSGBOX -> Dialog_MSGBOX -> Dialog_G
Dialog_SLIDE -> Dialog_MiniGameSolo -> Dialog_MiniGame -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
Dialog_SPLASHSCREEN -> Dialog_G
Dialog_STARTLANG -> Dialog_MC_Base -> Dialog_G
Dialog_STATUSINFOS -> Dialog_PAUSE -> Dialog_MC_Base -> Dialog_G
Dialog_SUCCESSMULTI -> Dialog_MINIGAMESUCCESS -> Dialog_MC_Base -> Dialog_G
Dialog_TEXTBOX -> Dialog_G
Dialog_TUTORIAL -> Dialog_G
Dialog_UNLOCK -> Dialog_G
Dialog_VIDEO -> Dialog_Media -> Dialog_Multipage -> Dialog_Purchase -> Dialog_DynamicLayout -> Dialog_LoadMaterialLib -> Dialog_G
DreamPurchase -> SologamePurchase -> Purchase
DummyGen
DynamicAnim2_Z -> DynamicAnim_Z -> Manipulator_Z -> BaseObject_Z
DynamicAnim_Z -> Manipulator_Z -> BaseObject_Z
Emiter_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
EndMissionVolumeAgent_G -> VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Enemies_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
EnemyDummyGen -> DummyGen
EnemyGenerator_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
EvenementVolAgent_G -> VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
FXVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
FallVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
FileInterp_Z -> BaseStream_Z
FlareConstant_Z -> ObjConstant_Z
FlareDataPc_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
FlarePc_Z -> Flare_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Flare_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
FleeCollisionVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
FlyUpVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
FogConstant_Z -> ObjConstant_Z
Fonts_Z -> ResourceObject_Z -> BaseObject_Z
FootPrints_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
Frame_G
FriendsMove_G -> CreaturesMove_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GameLogicAgent_G -> LogicAgent_G -> Agent_Z -> ABC_Agent -> BaseObject_Z
GameObj_Z -> ResourceObject_Z -> BaseObject_Z
GameParticleMgr_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
Game_SoundMgr -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
Game_Z -> BaseObject_Z
GamemodePurchase -> Purchase
GangAgent_G -> LightVolAnimatedAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GenWorld_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Ghost_Z -> Manipulator_Z -> BaseObject_Z
GlobalInGameDatas_G -> BaseInGameDatas_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
Globals
GraphLevel_Z
GraphSearch_Z
Graph_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
GroundConstant_Z -> ObjConstant_Z
GroupAgent_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GroupWanderingZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GuardAgent_G -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GuardMove_G -> Manipulator_Z -> BaseObject_Z
GusteauAgent -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
GusteauMove -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
HFieldConstant_Z -> ObjConstant_Z
HFieldPc_Z -> HField_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
HField_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
HFogData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
HFog_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
HandleManager_Z
Hi_MemoryManager_Z
HoveringGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
HumanSeenVolumeAgent_G -> DetectVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_AK47 -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BALL -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BIGWALLDEB_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASDROIT02_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASDROIT03_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASDROIT_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASGAUCHE02_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASGAUCHE03_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BRASGAUCHE_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BREAKBASE_G -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BallMove_G -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_BallWalkMove_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_BallWalk_G -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_Break -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_BreakMove -> Manipulator_Z -> BaseObject_Z
IT_Bumper -> LightVolAnimatedAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_CASQUE -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_CASQUE_CHIEF -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_COLLECTMove_G -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_COLLECT_G -> ObjectAgent_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_Carrying -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_CarryingMove -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_Condition -> Manipulator_Z -> BaseObject_Z
IT_DOUILLE_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_DYNOBJMove_G -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_DYNOBJ_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_FISH_G -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_FUMIGENE_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_FishMove_G -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_JAMBEDROITE02_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_JAMBEDROITE03_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_JAMBEDROITE_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_JAMBEGAUCHE02_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_JAMBEGAUCHE03_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_JAMBEGAUCHE_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_LinkHamecon -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_LinkHameconMove -> IT_LinkObjMove -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_LinkObj -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_LinkObjMove -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_ROQUETER -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_SOUND -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_SOURCEENERGYMove_G -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
IT_Stone_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_Switch -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_TETE02_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_TETE03_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_TETE_G -> IT_BODY_PART_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_TIMED_PLATFORM_G -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
IT_WALLDEB_G -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ImagePurchase -> MediaPurchase -> Purchase
ImpactVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
InGameCreatures_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
InGameFX_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
InGameObjectsManipulator_Z -> Manipulator_Z -> BaseObject_Z
InGameObjectsPc_Z -> InGameObjects_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
InGameObjects_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
InGamePlayer_G -> BaseInGameDatas_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
IndexBuffer_Z
InputEngine_Z
InputPlatForm_Z
InterfacePage
IsToBePlayed
ItemMgr_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
LayerConstant_Z -> ObjConstant_Z
LevelAdvancement_G -> BaseObject_Z
LevelAgent_G -> Agent_Z -> ABC_Agent -> BaseObject_Z
LevelData_G -> BaseObject_Z
LevelManipulator_G -> Manipulator_Z -> BaseObject_Z
LevelStatusArrowButtonsSet -> ArrowButtonsSetWithText -> ArrowButtonsSet
LightConstant_Z -> ObjConstant_Z
LightData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
LightVolAnimatedAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
LightVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Light_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
LinkedThrownMove_G -> ThrownMove_G -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
LiquidFlow_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
LoadingDraw_C -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
LodData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
LodDynAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
LodPcData_Z -> LodData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
LodPc_Z -> Lod_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Lod_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
LogicAgent_G -> Agent_Z -> ABC_Agent -> BaseObject_Z
LogicLevel_G -> BaseObject_Z
ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
Manipulator_Z -> BaseObject_Z
MatConstant_Z -> ObjConstant_Z
MaterialAnim_Z -> ResourceObject_Z -> BaseObject_Z
MaterialManager_Z
MaterialObj_Z -> ResourceObject_Z -> BaseObject_Z
MaterialUser_Z
Material_Z -> ResourceObject_Z -> BaseObject_Z
MediaPurchase -> Purchase
MemoryCardManager_C -> Manipulator_Z -> BaseObject_Z
MemoryManager_Z -> Hi_MemoryManager_Z
Menu2D_Z -> Menu_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
Menu3DScenery
Menu3D_Z -> Menu_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
MenuLogicAgent_G -> LogicAgent_G -> Agent_Z -> ABC_Agent -> BaseObject_Z
MenuManager_G -> BaseInGameDatas_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
Menu_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
MeshData_Z -> PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
MeshPcData_Z -> MeshData_Z -> PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
MeshPc_Z -> Mesh_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Mesh_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
MissionManager_G -> Manipulator_Z -> BaseObject_Z
MissionTemplate_G
MissionVolumeAgent_G -> VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Mission_Chase -> MissionTemplate_G
Mission_Check -> MissionTemplate_G
Mission_Collect -> MissionTemplate_G
Mission_CollectTrigger -> MissionTemplate_G
Mission_Colony -> Mission_Collect -> MissionTemplate_G
Mission_Container -> MissionTemplate_G
Mission_ControlPanel -> MissionTemplate_G
Mission_CookingCake -> MissionTemplate_G
Mission_CookingLinguini -> MissionTemplate_G
Mission_CookingPlate -> MissionTemplate_G
Mission_CookingSoup -> MissionTemplate_G
Mission_CookingSoupYesNo -> MissionTemplate_G
Mission_CuttingPotatoes -> MissionTemplate_G
Mission_Dream -> MissionTemplate_G
Mission_Glissade -> MissionTemplate_G
Mission_Global -> MissionTemplate_G
Mission_Goto -> MissionTemplate_G
Mission_Heist -> MissionTemplate_G
Mission_LinguiniMaking -> MissionTemplate_G
Mission_MiniGame -> MissionTemplate_G
Mission_MultiTemplate_G -> MissionTemplate_G
Mission_Multi_Ball -> Mission_MultiTemplate_G -> MissionTemplate_G
Mission_Multi_Collect -> Mission_MultiTemplate_G -> MissionTemplate_G
Mission_Multi_Race -> Mission_MultiTemplate_G -> MissionTemplate_G
Mission_Multi_Rope -> Mission_MultiTemplate_G -> MissionTemplate_G
Mission_PreLinguiniMaking -> MissionTemplate_G
Mission_PushButton -> MissionTemplate_G
Mission_PushLift -> MissionTemplate_G
Mission_Raft -> MissionTemplate_G
Mission_Semaphore -> MissionTemplate_G
Mission_ShootTarget -> MissionTemplate_G
Mission_Switch -> MissionTemplate_G
Mission_TimeCount -> MissionTemplate_G
Mission_Tutorial -> MissionTemplate_G
Mission_Wii_Crepe -> MissionTemplate_G
Mission_Wii_Fish -> MissionTemplate_G
Mission_Wii_Wash -> MissionTemplate_G
Mission_WireConnect -> MissionTemplate_G
MorphConstant_Z -> ObjConstant_Z
MovieManipulator_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
Movie_Z
MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
MtlConstant_Z -> ObjConstant_Z
MultiGameToBePlayed -> MultiPlayerGameToBePlayed -> IsToBePlayed
MultiPlayerGameToBePlayed -> IsToBePlayed
MultiPlayerPurchase -> Purchase
MultigamePurchase -> MultiPlayerPurchase -> Purchase
MusicManager_G -> Manipulator_Z -> BaseObject_Z
NetManager_Virtual_Z -> NetManager_Z
NetManager_Z
NodeVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Node_Z -> ResourceObject_Z -> BaseObject_Z
ObjConstant_Z
ObjectAgent_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ObjectBankManager_Z
ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
Object_Z -> ResourceObject_Z -> BaseObject_Z
ObjectsBounce_Z -> ObjectsMove_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
ObjectsBreak_Z -> ObjectsBounce_Z -> ObjectsMove_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
ObjectsGameClip_Z -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
ObjectsGame_Z -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
ObjectsMove_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
OccludedSeadHandle_Z -> SeadHandle_Z
Occluder_Z -> SplineZone_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
OmniConstant_Z -> ObjConstant_Z
Omni_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
PLTF02_GROUP -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
PShaderDecl_Z -> ShaderDecl_Z
P_AICELI -> P_AIEMIL -> P_EMILE -> P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_AIEMIL -> P_EMILE -> P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_AITWIT -> P_AIEMIL -> P_EMILE -> P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_CELI_M -> P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_EMILE -> P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_FISH -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_CAKE -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_CREP -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_POTA -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_REMY -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_WASH -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_L_WASH2 -> P_L_WASH -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_PLAT01 -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_REMY -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_REMY_C -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_REMY_R -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_REMY_S -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_REMY_T -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_BKD -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_BUT -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_COL -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_SOUP -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_SWKN -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_SWMK -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_R_WCCT -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
P_SOUP01 -> P_LINGUI -> Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
PaddleChecker_G -> Manipulator_Z -> BaseObject_Z
PageCollect -> InterfacePage
PageColony -> PageCollect -> InterfacePage
PageContainer -> PageCollect -> InterfacePage
PageContext -> InterfacePage
PageControlPanel -> InterfacePage
PageCookingCake -> InterfacePage
PageCookingCakeJauge -> InterfacePage
PageCookingLinguini -> InterfacePage
PageCookingPlate -> InterfacePage
PageCookingSoup -> InterfacePage
PageCookingSoupYesNo -> InterfacePage
PageCuttingPotatoes -> InterfacePage
PageDrawRadar -> InterfacePage
PageDrawTimer -> InterfacePage
PageGlissade -> InterfacePage
PageHeist -> InterfacePage
PageHumanDanger -> InterfacePage
PageHumanSight -> InterfacePage
PageInfosText -> InterfacePage
PageJaugeSkinner -> InterfacePage
PageLife -> InterfacePage
PageLinguiniMaking -> InterfacePage
PageMGJauge -> InterfacePage
PageMultiBall -> InterfacePage
PageMultiCollect -> InterfacePage
PageMultiRace -> InterfacePage
PageMultiRaft -> InterfacePage
PageMultiRope -> InterfacePage
PagePushButton -> InterfacePage
PagePushButtonJauge -> InterfacePage
PageSemaphore -> InterfacePage
PageShakePad -> InterfacePage
PageShootTarget -> InterfacePage
PageTimeCount -> InterfacePage
PageTutorial -> PageCollect -> InterfacePage
PageWiiCrepe -> InterfacePage
PageWiiFish -> InterfacePage
PageWiiWash -> InterfacePage
PageWireConnect -> InterfacePage
PageWrongWay -> InterfacePage
ParticleConstant_Z -> ObjConstant_Z
ParticlesAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ParticlesDataPC_Z -> ParticlesData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
ParticlesData_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
ParticlesManager_Z -> DataManager_Z<struct _ParticleElement_Z>
Particles_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
PatchConstant_Z -> ObjConstant_Z
PermanentDraw -> BaseInGameDatas_G -> InGameDatas_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
PersoLight_G -> Manipulator_Z -> BaseObject_Z
PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
PhysicWorld_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
PigeonGroupTriggerZone_G -> SwarmGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
PlatformCameraAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
PlayAnim_Z -> Manipulator_Z -> BaseObject_Z
PlayParticles_Z -> Manipulator_Z -> BaseObject_Z
PlayerMove_G -> FriendsMove_G -> CreaturesMove_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
Player_G -> Friends_G -> Creatures_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
PointJump_G -> Manipulator_Z -> BaseObject_Z
PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
PopupItem_Z
PopupMenu_Z
ProGroundMgr_G -> ObjectGame_Z -> Manipulator_Z -> BaseObject_Z
Purchase
RaftHideAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
RaftImmobileAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
RaftMoveJumpAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
RaftTourbillonAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
Renderer_Z
RepulseAnimatedAgent_G -> LightVolAnimatedAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ResourceObject_Z -> BaseObject_Z
Ropes_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
RotShapeConstant_Z -> ObjConstant_Z
RotShapeData_Z -> PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
RotShapePcData_Z -> RotShapeData_Z -> PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
RotShapePc_Z -> RotShape_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
RotShape_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
RoughPurchase -> MediaPurchase -> Purchase
RtcAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
RtcPlayer_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
RtcScriptAgent_G -> RtcAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
RtcScripted_G -> RtcPlayer_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
Rtc_Z -> ResourceObject_Z -> BaseObject_Z
SASVolumeAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
SaveGamePc_Z -> SaveGame_Z
SaveGame_Z
SaveVolumeAgent_G -> VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ScatterConstant_Z -> ObjConstant_Z
ScriptInputManager_Z -> InputEngine_Z
ScriptManager_G -> ABC_ScriptManager
SeadHandle_Z
SearchNode_Z
SelfRunning_Z -> Manipulator_Z -> BaseObject_Z
SequenceAnim_Z -> BaseObject_Z
SequenceMixAnim_Z -> SequenceAnim_Z -> BaseObject_Z
ShaderDecl_Z
SkelPc_Z -> Skel_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
Skel_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
SkinAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
SkinPc_Z -> Skin_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Skin_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
SlidePurchase -> SologamePurchase -> Purchase
Smell_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
SologamePurchase -> Purchase
SoundManager_Z -> ClassNameResManager_Z
Sound_Z -> ResourceObject_Z -> BaseObject_Z
SplineZone_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Spline_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
StreamAgent_Z -> ABC_Agent -> BaseObject_Z
StreamFile_Z -> Manipulator_Z -> BaseObject_Z
StreamGameAgent_G -> StreamAgent_Z -> ABC_Agent -> BaseObject_Z
Stream_Z -> BaseStream_Z
SubLevelVolumeAgent_Z -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
SubWorld_Z -> ResourceObject_Z -> BaseObject_Z
SuperSpray_Z -> PlayParticles_Z -> Manipulator_Z -> BaseObject_Z
SurfaceDatas_Z -> PointsDatas_Z -> ObjectDatas_Z -> ResourceObject_Z -> BaseObject_Z
SurfacePc_Z -> Surface_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Surface_Z -> Points_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
SwarmClamsGroupTriggerZone_G -> SwarmGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
SwarmGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
SwarmMeanGroupTriggerZone_G -> SwarmGroupTriggerZone_G -> GroupTriggerZone_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
TextGameDraw_G -> ManipulatorSceneDraw_Z -> Manipulator_Z -> BaseObject_Z
Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
ThrownMove_G -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
Tree_Impostor -> Tree_Leaf
Tree_Leaf
Tree_Z -> Object_Z -> ResourceObject_Z -> BaseObject_Z
Txt_Z -> ResourceObject_Z -> BaseObject_Z
UserDefine_Z -> ResourceObject_Z -> BaseObject_Z
UserObject3DPc_Z -> UserObject3D_Z
UserObject3D_Z
VShaderDecl_Z -> ShaderDecl_Z
V_Book -> V_RAFT -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
V_RAFT -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
V_RAFTM -> V_RAFT -> IT_DYNBASE_G -> BaseAgent_G -> LodAgent_Z -> Throwable_Z -> MovingAgent_Z -> AnimatedAgent_Z -> AnimatedMsgAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
V_RaftMove -> PhysicObj_G -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
VehiculeMove_Z -> LodMove_Z -> ObjectThrow_Z -> ObjectMove_Z -> Manipulator_Z -> BaseObject_Z
VertexBuffer_Z
VibrationManager_C -> Manipulator_Z -> BaseObject_Z
VideoPurchase -> Purchase
ViewportConstant_Z -> ObjConstant_Z
VizQueryConstant_Z -> ObjConstant_Z
VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
VolumeConstant_Z -> ObjConstant_Z
VolumeDelayedStartMove_G -> Manipulator_Z -> BaseObject_Z
VolumeDelayedStart_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
WakeUpDynVolAgent_G -> VolumeAgent_Z -> Agent_Z -> ABC_Agent -> BaseObject_Z
WanderingPath_G -> BaseObject_Z
WarpPc_Z -> Warp_Z -> ResourceObject_Z -> BaseObject_Z
Warp_Z -> ResourceObject_Z -> BaseObject_Z
WaterHeightMapConstant_Z -> ObjConstant_Z
WaterHeightMap_Z -> MaterialUser_Z
WinConsole_Z -> Console_Z
WinGlobals -> Globals
WinInput_Z -> InputPlatForm_Z
WinMovieManipulator_Z -> MovieManipulator_Z -> ManipulatorDraw_Z -> Manipulator_Z -> BaseObject_Z
WinMovie_Z -> Movie_Z
WinPopupMenu_Z -> PopupMenu_Z
WinSndStream_Z -> BaseStream_Z
WinSoundBF_Z -> BaseStream_Z
WinSound_Z -> SoundManager_Z -> ClassNameResManager_Z
WinStream_Z -> Stream_Z -> BaseStream_Z
WinXRamManager_Z -> XRamManager_Z
WorldConstant_Z -> MatConstant_Z -> ObjConstant_Z
WorldManager_Z
World_Z -> ResourceObject_Z -> BaseObject_Z
XRamManager_Z
charNode -> DNameNode
pDNameNode -> DNameNode
pcharNode -> DNameNode
type_info
```
