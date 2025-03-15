CeruleanCave_B2FReal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B2F_OnResume
	.byte 0

CeruleanCave_B2F_OnTransition::
	call_if_set FLAG_FOUGHT_XSENDAI, CeruleanCave_B2F_EventScript_HideXSendai
	call_if_unset FLAG_FOUGHT_XSENDAI, CeruleanCave_B2F_EventScript_TryShowXSendai
	end

CeruleanCave_B2F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, CeruleanCave_B2F_EventScript_TryRemoveXSendai
	end

CeruleanCave_B2F_EventScript_HideXSendai::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_XSENDAI
	return

CeruleanCave_B2F_EventScript_TryShowXSendai::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_XSENDAI_FLEW_AWAY, EventScript_Return
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_XSENDAI
	return

CeruleanCave_B2F_EventScript_TryRemoveXSendai::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject 1
	return

CeruleanCave_B2F_EventScript_XSendai::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	
	playmoncry SPECIES_XSENDAI, 2
	delay 30
	waitmoncry
	
	setvar VAR_0x8004, SPECIES_XSENDAI
	setvar VAR_0x8005, 90  @ Level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CeruleanCave_B2F_EventScript_DefeatedXSendai
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq CeruleanCave_B2F_EventScript_RanFromXSendai
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CeruleanCave_B2F_EventScript_RanFromXSendai
	setflag FLAG_FOUGHT_XSENDAI
	releaseall
	end

CeruleanCave_B2F_EventScript_DefeatedXSendai::
	setflag FLAG_XSENDAI_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_XSENDAI
	goto EventScript_MonFlewAway
	end

CeruleanCave_B2F_EventScript_RanFromXSendai::
	setvar VAR_0x8004, SPECIES_XSENDAI
	goto EventScript_MonFlewAway
	end
