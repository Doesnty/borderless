.equ LOCALID_SIGN_LADY, 1
.equ LOCALID_PROF_OAK,  3

.equ SIGN_LADY_READY, VAR_TEMP_2

PalletTown_MapScripts:: @ 816545A
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnTransition:: @ 8165465
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0
	call_if_eq PalletTown_EventScript_SetSignLadyPos
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	call_if_eq PalletTown_EventScript_SetSignLadyDone
	end

PalletTown_EventScript_TryReadySignLady:: @ 8165488
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	goto_if_ge EventScript_Return
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	return

PalletTown_EventScript_SetSignLadyDone:: @ 81654A2
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	return

PalletTown_EventScript_SetSignLadyPos:: @ 81654A8
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
	setobjectxyperm LOCALID_SIGN_LADY, 5, 15
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
	return

PalletTown_EventScript_MoveSignLadyToRouteEntrance:: @ 81654BD
	setobjectxyperm LOCALID_SIGN_LADY, 12, 2
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
	setvar SIGN_LADY_READY, TRUE
	return

PalletTown_OnFrame:: @ 81654CE
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
	.2byte 0

@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
PalletTown_EventScript_OakRatingScene:: @ 81654D8
	lockall
	textcolor 0
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_PROF_OAK
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
	waitmovement 0
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
	msgbox PalletTown_Text_OakLetMeSeePokedex
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	getnumberstring 0, VAR_0x8008
	getnumberstring 1, VAR_0x8009
	compare VAR_0x8009, 1 @ was 60
	goto_if_lt PalletTown_EventScript_NotEnoughMonsForNationalDex
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 255, 6, 12
	waitstate
	releaseall
	end

PalletTown_EventScript_EndOakRatingScene:: @ 816557E
	closemessage
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
	waitmovement 0
	removeobject LOCALID_PROF_OAK
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	releaseall
	end

PalletTown_EventScript_NotEnoughMonsForNationalDex:: @ 8165593
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_EventScript_NotBeenToOneIslandYet:: @ 81655A1
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_Movement_OakWalkToPlayersDoor:: @ 81655AF
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

PalletTown_Movement_OakExit:: @ 81655BE
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_Movement_OakWalkToLabFromHouse:: @ 81655CC
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PalletTown_Movement_PlayerWalkToLabFromHouse:: @ 81655DD
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_EventScript_OakTriggerLeft:: @ 81655ED
	lockall
	setvar VAR_TEMP_1, 0
	goto PalletTown_EventScript_OakTrigger
	end

PalletTown_EventScript_OakTriggerRight:: @ 81655F9
	lockall
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_OakTrigger
	end

PalletTown_EventScript_OakTrigger:: @ 8165605
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	textcolor 0
	delay 30
	playbgm MUS_OAK, 0
	message PalletTown_Text_OakDontGoOut
	waitmessage
	delay 85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_PROF_OAK
	compare VAR_TEMP_1, 0
	call_if_eq PalletTown_EventScript_OakEnterLeft
	compare VAR_TEMP_1, 1
	call_if_eq PalletTown_EventScript_OakEnterRight
	delay 30
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
	closemessage
	delay 30
	compare VAR_TEMP_1, 0
	call_if_eq PalletTown_EventScript_OakLeadPlayerToLabLeft
	compare VAR_TEMP_1, 1
	call_if_eq PalletTown_EventScript_OakLeadPlayerToLabRight
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 255, 6, 12
	waitstate
	releaseall
	end

PalletTown_EventScript_OakEnterLeft:: @ 81656B8
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
	waitmovement 0
	return

PalletTown_EventScript_OakEnterRight:: @ 81656C3
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabLeft:: @ 81656CE
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabRight:: @ 81656E0
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
	waitmovement 0
	return

PalletTown_Movement_OakEnterLeft:: @ 81656F2
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

PalletTown_Movement_OakEnterRight:: @ 81656FB
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

	.macro walk_to_lab
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	.endm

PalletTown_Movement_OakWalkToLabLeft:: @ 8165705
	walk_down
	walk_to_lab
	walk_right
	walk_in_place_fastest_up
	step_end

PalletTown_Movement_OakWalkToLabRight:: @ 8165719
	walk_down
	walk_left
	walk_to_lab
	walk_right
	walk_in_place_fastest_up
	step_end

PalletTown_Movement_OakEnterLab:: @ 816572E
	walk_up
	set_invisible
	step_end

PalletTown_Movement_PlayerWalkToLabLeft:: @ 8165731
	walk_down
	walk_down
	walk_to_lab
	step_end

PalletTown_Movement_PlayerWalkToLabRight:: @ 8165744
	walk_down
	walk_down
	walk_left
	walk_to_lab
	step_end

PalletTown_Movement_PlayerEnterLab:: @ 8165758
	walk_right
	walk_up
	set_invisible
	step_end

PalletTown_EventScript_SignLady:: @ 816575C
	lock
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	goto_if_eq PalletTown_EventScript_SignLadyDone
	compare VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	goto_if_eq PalletTown_EventScript_SignLadyJustShowedSign
	compare SIGN_LADY_READY, TRUE
	goto_if_eq PalletTown_EventScript_SignLadyStartShowSign
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
	msgbox PalletTown_Text_HmmIsThatRight
	applymovement LOCALID_SIGN_LADY, Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SIGN_LADY, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SIGN_LADY, Movement_Delay48
	waitmovement 0
	msgbox PalletTown_Text_OhLookLook
	closemessage
	compare VAR_FACING, DIR_EAST
	call_if_eq PalletTown_EventScript_SignLadyMoveOutOfWayRight
	compare VAR_FACING, DIR_EAST
	call_if_ne PalletTown_EventScript_SignLadyMoveOutOfWayLeft
	moveobjectoffscreen 1
	setflag FLAG_TEMP_2
	release
	end

PalletTown_EventScript_SignLadyMoveOutOfWayRight:: @ 81657D7
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
	waitmovement 0
	return

PalletTown_EventScript_SignLadyMoveOutOfWayLeft:: @ 81657E2
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
	waitmovement 0
	return

PalletTown_EventScript_SignLadyDone:: @ 81657ED
	applymovement LOCALID_SIGN_LADY, Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_RaisingMonsToo
	release
	end

PalletTown_EventScript_SignLadyGoReadSign:: @ 8165801
	applymovement LOCALID_SIGN_LADY, Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_ReadItReadIt
	release
	end

PalletTown_EventScript_SignLadyJustShowedSign:: @ 8165815
	applymovement LOCALID_SIGN_LADY, Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_SignsAreUsefulArentThey
	release
	end

PalletTown_Movement_SignLadyMoveOutOfWayRight:: @ 8165829
	walk_right
	walk_in_place_fastest_left
	step_end

PalletTown_Movement_SignLadyMoveOutOfWayLeft:: @ 816582C
	walk_left
	walk_in_place_fastest_right
	step_end

PalletTown_EventScript_FatMan:: @ 816582F
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end

PalletTown_EventScript_OaksLabSign:: @ 8165838
	lockall
	famechecker FAMECHECKER_OAK, 0
	msgbox PalletTown_Text_OakPokemonResearchLab
	releaseall
	end

PalletTown_EventScript_PlayersHouseSign:: @ 8165850
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_RivalsHouseSign:: @ 8165859
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_TownSign:: @ 8165862
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips:: @ 816586B
	lockall
	msgbox PalletTown_Text_PressStartToOpenMenu
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	releaseall
	end

PalletTown_EventScript_SignLadyTrigger:: @ 816587B
	lockall
	applymovement LOCALID_SIGN_LADY, Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	releaseall
	end

PalletTown_EventScript_SignLadyShowSign:: @ 8165894
	textcolor 1
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
	closemessage
	delay 20
	textcolor 3
	setflag FLAG_OPENED_START_MENU
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	setvar SIGN_LADY_READY, FALSE
	special SetWalkingIntoSignVars
	special DisableMsgBoxWalkaway
	signmsg
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
	normalmsg
	return

PalletTown_EventScript_SignLadyStartShowSign:: @ 81658C2
	applymovement LOCALID_SIGN_LADY, Movement_FacePlayer
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	release
	end
