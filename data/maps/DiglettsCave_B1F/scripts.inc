DiglettsCave_B1F_MapScripts:: @ 8160EF1
	map_script MAP_SCRIPT_ON_TRANSITION, DiglettsCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, DiglettsCave_B1F_OnResume
	.byte 0

DiglettsCave_B1F_OnTransition:: @ 8160EF7
	setworldmapflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	end

DiglettsCave_B1F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, DiglettsCave_B1F_TryRemoveSnorlax
	end

DiglettsCave_B1F_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

DiglettsCave_B1F_EventScript_Snorlax:: @ 8168014
	lock
	goto_if_unset FLAG_GOT_POKE_FLUTE, DiglettsCave_B1F_EventScript_SnorlaxNoPokeFlute
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DiglettsCave_B1F_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_CDOREMY, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_CDOREMY, 2
	delay 40
	waitmoncry
	setflag FLAG_HIDE_DIGLETTS_CAVE_SNORLAX
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setflag FLAG_WOKE_UP_DIGLETTS_CAVE_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DiglettsCave_B1F_EventScript_FoughtSnorlax
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq DiglettsCave_B1F_EventScript_FoughtSnorlax
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq DiglettsCave_B1F_EventScript_FoughtSnorlax
	release
	end

DiglettsCave_B1F_EventScript_DontUsePokeFlute:: @ 816808D
	release
	end

DiglettsCave_B1F_EventScript_FoughtSnorlax:: @ 816808F
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

DiglettsCave_B1F_EventScript_SnorlaxNoPokeFlute:: @ 8168099
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end
