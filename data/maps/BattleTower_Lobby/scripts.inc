.set BTSPECIAL_TEST, 0
.set BTSPECIAL_RESULT_SAVE_SCUM, 1
.set BTSPECIAL_RESULT_WON7, 2
.set BTSPECIAL_RESULT_LOST, 3
.set BTSPECIAL_RESULT_QUICKSAVE, 4
.set BTSPECIAL_RESULT_INACTIVE, 5

BattleTower_Lobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTowerLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTowerLobby_OnWarp
	.byte 0

BattleTowerLobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, BattleTowerLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, BTSPECIAL_RESULT_SAVE_SCUM, BattleTowerLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, BTSPECIAL_RESULT_WON7, BattleTowerLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, BTSPECIAL_RESULT_LOST, BattleTowerLobby_EventScript_LostChallenge
	map_script_2 VAR_TEMP_0, BTSPECIAL_RESULT_QUICKSAVE, BattleTowerLobby_EventScript_ResumeChallenge
	.2byte 0

BattleTowerLobby_OnWarp::
	map_script_2 VAR_TEMP_1, 0, BattleTowerLobby_EventScript_PlayerFaceNorth
	.2byte 0

BattleTowerLobby_EventScript_PlayerFaceNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleTowerLobby_EventScript_GetChallengeStatus::
	special BattleTowerMapScript2
	end

BattleTowerLobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, BTSPECIAL_RESULT_INACTIVE
	release
	end

BattleTowerLobby_EventScript_WonChallenge::
	lock
	faceplayer
	message BattleTowerLobby_Text_Congratulations
	waitmessage
	
	@ skip the ribbons
	
	setvar VAR_0x8004, 8
	special BattleTowerUtil
	compare VAR_RESULT, 1
	goto_if_eq BattleTower_Lobby_EventScript_GiveItem
	message BattleTowerLobby_Text_RecordSaving
	waitmessage
	setvar VAR_0x8004, 13
	special SetBattleTowerProperty
	setvar VAR_0x8004, 3
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse

BattleTower_Lobby_EventScript_GiveItem::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	special SetBattleTowerProperty
	message BattleTowerLobby_Text_GainPrize
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTowerLobby_Text_LookingForward, 4
	closemessage
	setvar VAR_TEMP_0, BTSPECIAL_RESULT_INACTIVE
	release
	end

BattleTowerLobby_EventScript_LostChallenge::
	lock
	faceplayer
	message BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	message BattleTowerLobby_Text_RecordSaving
	waitmessage
	setvar VAR_0x8004, 13
	special SetBattleTowerProperty
	setvar VAR_0x8004, 0
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse
	msgbox BattleTowerLobby_Text_LookingForward, 4
	closemessage
	setvar VAR_TEMP_0, BTSPECIAL_RESULT_INACTIVE
	release
	end
	

BattleTowerLobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special SetBattleTowerProperty
	setvar VAR_TEMP_0, BTSPECIAL_RESULT_INACTIVE
	special SavePlayerParty
	special SetBattleTowerParty
	msgbox BattleTowerLobby_Text_IllDirectYou, 4
	call BattleTowerLobby_EventScript_WalkToElevator
	warp MAP_BATTLE_TOWER_ELEVATOR, 255, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate
	
	

BattleTowerLobby_EventScript_WalkToElevator::
	applymovement 1, BattleTowerLobby_Movement_WalkUp3
	applymovement 255, BattleTowerLobby_Movement_WalkUp3
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement 1, BattleTowerLobby_Movement_WalkUpInvis
	applymovement 255, BattleTowerLobby_Movement_WalkUp2Invis
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

BattleTowerLobby_Movement_WalkUp3::
	walk_up
	walk_up
	walk_up
	step_end

BattleTowerLobby_Movement_WalkUpInvis::
	walk_up
	set_invisible
	step_end

BattleTowerLobby_Movement_WalkUp2Invis::
	walk_up
	walk_up
	set_invisible
	step_end
	
BattleTowerLobby_Receptionist::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special BattleTowerUtil
	compare VAR_RESULT, 6
	goto_if_eq BattleTowerLobby_EventScript_WonChallenge
	special SavePlayerParty
	msgbox BattleTowerLobby_Text_Welcome, 4

BattleTower_Lobby_EventScript_Hub::
	message BattleTowerLobby_Text_MakeAChallenge
	waitmessage
	multichoice 15, 6, MULTICHOICE_CHALLENGE_INFO_EXIT, 0
	switch VAR_RESULT
	case 0, BattleTower_Lobby_EventScript_Challenge
	case 1, BattleTower_Lobby_EventScript_Explain
	case 2, BattleTower_Lobby_EventScript_Goodbye
	case 127, BattleTower_Lobby_EventScript_Goodbye

BattleTower_Lobby_EventScript_Explain::
	msgbox BattleTowerLobby_Text_Explanation, 4
	goto BattleTower_Lobby_EventScript_Hub

BattleTower_Lobby_ReloadPartyIntoGoodbye::
	special LoadPlayerParty
BattleTower_Lobby_EventScript_Goodbye::
	msgbox BattleTower_Lobby_Text_LookingForward, 4
	setvar VAR_0x8004, 11
	special SetBattleTowerProperty
BattleTower_Lobby_EventScript_End::
	release
	end
	
BattleTower_Lobby_EventScript_Challenge::
	message BattleTower_Lobby_Text_WhichRoom
	waitmessage
	multichoice 18, 6, MULTICHOICE_BATTLE_TOWER_ROOM_CHOICE, 0
	switch VAR_RESULT
	case 2, BattleTower_Lobby_EventScript_Goodbye
	case 127, BattleTower_Lobby_EventScript_Goodbye
	special CheckPartyBattleTowerBanlist
	compare VAR_0x8004, 1
	goto_if_eq BattleTower_Lobby_EventScript_InvalidRoster
	setvar VAR_0x8004, 1
	copyvar VAR_0x8005, VAR_RESULT
	copyvar VAR_0x8006, VAR_RESULT
	special SetBattleTowerProperty
	@ TODO: hook for factory mode here

	msgbox BattleTower_Lobby_Text_PleaseSelectPuppets, 4
	fadescreen 1
	special ChooseBattleTowerPlayerParty
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_Lobby_ReloadPartyIntoGoodbye
	msgbox BattleTower_Lobby_Text_BeforeEnteringMustSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Lobby_ReloadPartyIntoGoodbye
	case YES, BattleTower_Lobby_EventScript_SaveForChallenge
	case 127, BattleTower_Lobby_ReloadPartyIntoGoodbye

BattleTower_Lobby_EventScript_InvalidRoster::
	msgbox BattleTower_Lobby_Text_MustHaveThreeEligible, 4
	release
	end

BattleTower_Lobby_EventScript_SaveForChallenge::
	setvar VAR_0x8004, 5
	special SetBattleTowerProperty
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 11
	special SetBattleTowerProperty
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	special SetBattleTowerProperty
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special SetBattleTowerProperty
	special LoadPlayerParty
	closemessage
	delay 2
	call EventScript_AskSaveGame
	setvar VAR_TEMP_0, 5
	erasebox 0, 0, 15, 10
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_Lobby_EventScript_RefusedToSave
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	special SavePlayerParty
	special SetBattleTowerParty
	
	msgbox BattleTower_Lobby_Text_IllDirectYou, 4
	closemessage
	call BattleTowerLobby_EventScript_WalkToElevator
	warp MAP_BATTLE_TOWER_ELEVATOR, 255, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate

BattleTower_Lobby_EventScript_RefusedToSave::
	setvar VAR_0x8004, 12
	special SetBattleTowerProperty
	goto BattleTower_Lobby_EventScript_Goodbye

BattleTower_Lobby_EventScript_RecordsConsole::
	lockall
	@ special ShowBattleTowerRecords
	waitbuttonpress
	erasebox 0, 0, 29, 19
	releaseall
	end
