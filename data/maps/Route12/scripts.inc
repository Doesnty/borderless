Route12_MapScripts:: @ 8168000
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route12_OnLoad
	.byte 0

Route12_OnResume:: @ 8168006
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_OnLoad::
	call_if_unset FLAG_ENTERED_ROUTE_13, Route12_RemoveBridge
	end

Route12_RemoveBridge::
	setmetatile 18, 81, 0x309, 1
	setmetatile 19, 81, 0x30A, 1
	setmetatile 18, 82, 0x12B, 1
	setmetatile 19, 82, 0x12B, 1
	setmetatile 18, 83, 0x12B, 1
	setmetatile 19, 83, 0x12B, 1
	setmetatile 18, 84, 0x133, 1
	setmetatile 19, 84, 0x133, 1
	return

Route12_EventScript_TryRemoveSnorlax:: @ 8168010
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax:: @ 8168014
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_CDOREMY, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_CDOREMY, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route12_EventScript_FoughtSnorlax
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route12_EventScript_FoughtSnorlax
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute:: @ 816808D
	release
	end

Route12_EventScript_FoughtSnorlax:: @ 816808F
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute:: @ 8168099
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign:: @ 81680A3
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign:: @ 81680AC
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_EventScript_Man::
	msgbox Route12_Text_ConstructionGuy
	release
	end

Route12_EventScript_Koga::
	lock
	faceplayer
	msgbox Route12_Text_Koga, MSGBOX_DEFAULT
	setflag FLAG_GOT_TEA
	setflag FLAG_HIDE_FUCHSIA_CITY_GYM_GUARD
	giveitem ITEM_TEA
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_BagIsFull
	msgbox Route12_Text_Koga2, MSGBOX_DEFAULT
	closemessage
	
	applymovement 14, Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	
	setfieldeffectarg 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 14
	waitfieldeffect FLDEFF_NPCFLY_OUT
	
	release
	end


