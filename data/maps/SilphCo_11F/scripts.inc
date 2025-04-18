.set LOCALID_GIOVANNI, 3
.set LOCALID_GRUNT1,   4
.set LOCALID_GRUNT2,   6

SilphCo_11F_MapScripts:: @ 8161DEE
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad:: @ 8161DF4
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President:: @ 8161DFE
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq SilphCo_11F_EventScript_PresidentThanksMale
	compare VAR_RESULT, FEMALE
	call_if_eq SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_HM03_SURF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_HM03_SURF, 1, MUS_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale:: @ 8161E59
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale:: @ 8161E62
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall:: @ 8161E6B
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall:: @ 8161E75
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary:: @ 8161E7F
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft:: @ 8161E88
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight:: @ 8161E94
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni:: @ 8161EA0
	textcolor 0
	applymovement LOCALID_GIOVANNI, Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq SilphCo_11F_EventScript_GiovanniApproachLeft
	compare VAR_TEMP_1, 1
	call_if_eq SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft:: @ 8161F00
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight:: @ 8161F12
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft:: @ 8161F1D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight:: @ 8161F23
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni:: @ 8161F27
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor:: @ 8161F2E
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign:: @ 8161F37
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1:: @ 8161F40
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2:: @ 8161F57
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end
