.set LOCALID_DEOXYS_ROCK, 1
.set LOCALID_DEOXYS,      2

BirthIsland_Exterior_MapScripts:: @ 8165203
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
	.byte 0

BirthIsland_Exterior_OnReturnToField:: @ 8165213
	special SetDeoxysTrianglePalette
	end

BirthIsland_Exterior_OnTransition:: @ 8165217
	setworldmapflag FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DEOXYS_N
	setvar VAR_DEOXYS_INTERACTION_STEP_COUNTER, 0
	setvar VAR_DEOXYS_INTERACTION_NUM, 0
	call_if_set FLAG_FOUGHT_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
	call_if_unset FLAG_FOUGHT_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
	end

BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle:: @ 816523C
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_BIRTH_ISLAND_METEORITE
	return

BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle:: @ 8165243
	goto_if_set FLAG_DEOXYS_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_BIRTH_ISLAND_METEORITE
	clearflag FLAG_SYS_DEOXYS_AWAKENED
	return

BirthIsland_Exterior_OnResume:: @ 8165253
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
	end

BirthIsland_Exterior_EventScript_TryRemoveDeoxys:: @ 816525D
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_DEOXYS
	return

BirthIsland_Exterior_EventScript_Triangle:: @ 8165271
	lock
	faceplayer
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	special DoDeoxysTriangleInteraction
	waitstate
	switch VAR_RESULT
	case 0, BirthIsland_Exterior_EventScript_NotSolved1
	case 1, BirthIsland_Exterior_EventScript_NotSolved2
	case 2, BirthIsland_Exterior_EventScript_Deoxys
	case 3, BirthIsland_Exterior_EventScript_NotSolved3
	end

BirthIsland_Exterior_EventScript_NotSolved1:: @ 81652BA
	release
	end

BirthIsland_Exterior_EventScript_NotSolved2:: @ 81652BC
	release
	end

BirthIsland_Exterior_EventScript_NotSolved3:: @ 81652BE
	release
	end

BirthIsland_Exterior_EventScript_Deoxys:: @ 81652C0
	addobject LOCALID_DEOXYS
	waitse
	setfieldeffectarg 0, LOCALID_DEOXYS_ROCK
	setfieldeffectarg 1, 56
	setfieldeffectarg 2, 2
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	playbgm MUS_ENCOUNTER_DEOXYS, 0
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	applymovement LOCALID_DEOXYS, Movement_DeoxysApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_2HU, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_DEOXYS
	setvar VAR_0x8004, SPECIES_2HU
	setvar VAR_0x8005, 60  @ Level
	setvar VAR_0x8006, ITEM_BRIGHT_POWDER
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BirthIsland_Exterior_EventScript_DefeatedDeoxys
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BirthIsland_Exterior_EventScript_RanFromDeoxys
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BirthIsland_Exterior_EventScript_RanFromDeoxys
	setflag FLAG_FOUGHT_DEOXYS
	release
	end

BirthIsland_Exterior_EventScript_DefeatedDeoxys:: @ 816533A
	setflag FLAG_DEOXYS_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_2HU
	goto EventScript_MonFlewAway
	end

BirthIsland_Exterior_EventScript_RanFromDeoxys:: @ 8165348
	setvar VAR_0x8004, SPECIES_2HU
	goto EventScript_MonFlewAway
	end

Movement_DeoxysApproach: @ 8165353
	walk_slower_down
	walk_slower_down
	walk_slower_down
	walk_slower_down
	walk_slower_down
	walk_slower_down
	walk_slower_down
	step_end
