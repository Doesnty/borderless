.set LOCALID_LUGIA, 1

NavelRock_Base_MapScripts:: @ 81650E7
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Base_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Base_OnResume
	.byte 0

NavelRock_Base_OnTransition:: @ 81650F2
	call_if_set FLAG_FOUGHT_LUGIA, NavelRock_Base_EventScript_HideLugia
	call_if_unset FLAG_FOUGHT_LUGIA, NavelRock_Base_EventScript_TryShowLugia
	end

NavelRock_Base_EventScript_HideLugia:: @ 8165105
	setflag FLAG_HIDE_LUGIA
	return

NavelRock_Base_EventScript_TryShowLugia:: @ 8165109
	goto_if_set FLAG_LUGIA_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_LUGIA
	return

NavelRock_Base_OnResume:: @ 8165116
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Base_EventScript_TryRemoveLugia
	end

NavelRock_Base_EventScript_TryRemoveLugia:: @ 8165120
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_LUGIA
	return

NavelRock_Base_EventScript_Lugia:: @ 8165134
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_XSUWAKO, 2
	waitmoncry
	delay 20
	setvar VAR_0x8004, SPECIES_XSUWAKO
	setvar VAR_0x8005, 90  @ Level
	setvar VAR_0x8006, ITEM_LEFTOVERS
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NavelRock_Base_EventScript_DefeatedLugia
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NavelRock_Base_EventScript_RanFromLugia
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NavelRock_Base_EventScript_RanFromLugia
	setflag FLAG_FOUGHT_LUGIA
	release
	end

NavelRock_Base_EventScript_DefeatedLugia:: @ 81651D9
	setflag FLAG_LUGIA_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_XSUWAKO
	goto EventScript_MonFlewAway
	end

NavelRock_Base_EventScript_RanFromLugia:: @ 81651E7
	setvar VAR_0x8004, SPECIES_XSUWAKO
	goto EventScript_MonFlewAway
	end
