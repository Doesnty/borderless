

NavelRock_Fork_MapScripts:: @ 8165202
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Fork_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Fork_OnResume
	.byte 0

NavelRock_Fork_OnTransition::
	call_if_set FLAG_FOUGHT_XTENSHI, NavelRock_Fork_EventScript_HideXTenshi
	call_if_unset FLAG_FOUGHT_XTENSHI, NavelRock_Fork_EventScript_TryShowXTenshi
	end

NavelRock_Fork_EventScript_HideXTenshi::
	setflag FLAG_HIDE_XTENSHI
	return

NavelRock_Fork_EventScript_TryShowXTenshi::
	goto_if_set FLAG_XTENSHI_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_XTENSHI
	return

NavelRock_Fork_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Fork_EventScript_TryRemoveXTenshi
	end

NavelRock_Fork_EventScript_TryRemoveXTenshi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject 1
	return

NavelRock_Fork_EventScript_XTenshi::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	
	playmoncry SPECIES_XTENSHI, 2
	delay 30
	waitmoncry
	delay 60
	
	setvar VAR_0x8004, SPECIES_XTENSHI
	setvar VAR_0x8005, 90  @ Level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NavelRock_Fork_EventScript_DefeatedXTenshi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NavelRock_Fork_EventScript_RanFromXTenshi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NavelRock_Fork_EventScript_RanFromXTenshi
	setflag FLAG_FOUGHT_XTENSHI
	releaseall
	end

NavelRock_Fork_EventScript_DefeatedXTenshi::
	setflag FLAG_XTENSHI_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_XTENSHI
	goto EventScript_MonFlewAway
	end

NavelRock_Fork_EventScript_RanFromXTenshi::
	setvar VAR_0x8004, SPECIES_XTENSHI
	goto EventScript_MonFlewAway
	end
