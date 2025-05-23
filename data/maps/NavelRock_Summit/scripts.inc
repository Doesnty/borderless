.set LOCALID_HO_OH, 1

NavelRock_Summit_MapScripts:: @ 8164F9F
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Summit_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Summit_OnResume
	.byte 0

NavelRock_Summit_OnTransition:: @ 8164FAA
	call_if_set FLAG_FOUGHT_HO_OH, NavelRock_Summit_EventScript_HideHoOh
	call_if_unset FLAG_FOUGHT_HO_OH, NavelRock_Summit_EventScript_TryShowHoOh
	end

NavelRock_Summit_EventScript_HideHoOh:: @ 8164FBD
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HO_OH
	return

NavelRock_Summit_EventScript_TryShowHoOh:: @ 8164FC6
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_HO_OH_FLEW_AWAY, EventScript_Return
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HO_OH
	return

NavelRock_Summit_OnResume:: @ 8164FDD
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Summit_EventScript_TryRemoveHoOh
	end

NavelRock_Summit_EventScript_TryRemoveHoOh:: @ 8164FE7
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_HO_OH
	return

NavelRock_Summit_EventScript_HoOh:: @ 8164FFB
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement LOCALID_HO_OH, Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather 0
	doweather
	waitse
	playmoncry SPECIES_XUTSUHO, 2
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement OBJ_EVENT_ID_CAMERA, Movement_CameraPanDown
	applymovement LOCALID_HO_OH, Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, SPECIES_XUTSUHO
	setvar VAR_0x8005, 90  @ Level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NavelRock_Summit_EventScript_DefeatedHoOh
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NavelRock_Summit_EventScript_RanFromHoOh
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NavelRock_Summit_EventScript_RanFromHoOh
	setflag FLAG_FOUGHT_HO_OH
	releaseall
	end

NavelRock_Summit_EventScript_DefeatedHoOh:: @ 81650B4
	setflag FLAG_HO_OH_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_XUTSUHO
	goto EventScript_MonFlewAway
	end

NavelRock_Summit_EventScript_RanFromHoOh:: @ 81650C2
	setvar VAR_0x8004, SPECIES_XUTSUHO
	goto EventScript_MonFlewAway
	end

Movement_CameraPanUp: @ 81650CD
	walk_up
	walk_up
	walk_up
	step_end

Movement_CameraPanDown: @ 81650D1
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Movement_HoOhApproach: @ 81650D7
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

Movement_HoOhAppear: @ 81650E0
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end
