.set LOCALID_OLD_MAN,      3
.set LOCALID_TUTORIAL_MAN, 4
.set LOCALID_WOMAN,        5

ViridianCity_MapScripts:: @ 81658D3
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition:: @ 81658D9
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
	call_if_eq ViridianCity_EventScript_SetOldManBlockingRoad
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	call_if_eq ViridianCity_EventScript_SetOldManStandingByRoad
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	call_if_ge ViridianCity_EventScript_SetOldManNormal
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0
	call_if_eq ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal:: @ 8165909
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ZUN
	return

ViridianCity_EventScript_SetOldManStandingByRoad:: @ 816590F
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ZUN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad:: @ 8165920
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym:: @ 8165931
	goto_if_unset FLAG_BADGE02_GET, EventScript_Return
	goto_if_unset FLAG_BADGE03_GET, EventScript_Return
	goto_if_unset FLAG_BADGE04_GET, EventScript_Return
	goto_if_unset FLAG_BADGE05_GET, EventScript_Return
	goto_if_unset FLAG_BADGE06_GET, EventScript_Return
	goto_if_unset FLAG_BADGE07_GET, EventScript_Return
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked:: @ 816596D
	lockall
	textcolor 3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge:: @ 8165992
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign:: @ 8165994
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1:: @ 816599D
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2:: @ 81659A6
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign:: @ 81659AF
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor:: @ 81659B8
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy:: @ 81659C1
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan:: @ 81659CA
	lock
	faceplayer
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	goto_if_eq ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_OLD_MAN, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned:: @ 81659EC
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan:: @ 81659F6
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	goto_if_ge ViridianCity_EventScript_TutorialCompleted
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	goto_if_eq ViridianCity_EventScript_TutorialStart
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
	goto_if_eq ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful:: @ 8165A23
	msgbox ViridianCity_Text_HowsTeachyTVHelping
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful:: @ 8165A40
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted:: @ 8165A4A
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart:: @ 8165A54
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics:: @ 8165A5B
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused:: @ 8165A65
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady:: @ 8165A84
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster:: @ 8165A8F
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianCity_EventScript_YoungsterExplainCaterpillars
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars:: @ 8165AB0
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation:: @ 8165ABA
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman:: @ 8165AC4
	lock
	faceplayer
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0
	goto_if_eq ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked:: @ 8165ADB
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_WOMAN, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor:: @ 8165AF0
    lock
    faceplayer
    goto_if_set FLAG_TUTOR_DREAM_EATER, EventScript_DreamEaterTaught
    msgbox ViridianCity_Text_DreamEaterMan
	checkitemspace ITEM_LEFTOVERS, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_EventScript_DreamEaterNoRoom
	setflag FLAG_TUTOR_DREAM_EATER
	giveitem_msg ViridianCity_Text_DreamEaterGotLeftovers, ITEM_LEFTOVERS, 1, MUS_OBTAIN_KEY_ITEM
	release
	end

ViridianCity_EventScript_DreamEaterNoRoom::
	msgbox ViridianCity_Text_DreamEaterNoRoom
	release
	end

ViridianCity_EventScript_RoadBlocked:: @ 8165AF6
	lockall
	textcolor 0
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown:: @ 8165B0E
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft:: @ 8165B10
	lockall
	textcolor 0
	applymovement LOCALID_TUTORIAL_MAN, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight:: @ 8165B2E
	lockall
	textcolor 0
	applymovement LOCALID_TUTORIAL_MAN, Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle:: @ 8165B4C
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
    
    setvar VAR_TEMP_5, 0
    setvar VAR_TEMP_6, 0
    goto ViridianCity_EventScript_ZunMenu1

ViridianCity_EventScript_ZunCheckMon::
    specialvar VAR_ZUN_STARTER_SPECIES, SelectZunStarter
	copyvar VAR_TEMP_1, VAR_ZUN_STARTER_SPECIES
    getspeciesname 0, VAR_ZUN_STARTER_SPECIES
    
	drawmonpic VAR_ZUN_STARTER_SPECIES, 10, 3
    msgbox ViridianCity_Text_SoYouLike, MSGBOX_YESNO
    
    erasemonpic
    closemessage
    
	compare VAR_RESULT, NO
    goto_if_eq ViridianCity_EventScript_ZunMenuReturn
    

    givemon VAR_ZUN_STARTER_SPECIES, 5, ITEM_ORAN_BERRY

	compare VAR_RESULT, 0
	goto_if_eq ViridianCity_EventScript_ZunGetMonParty
	compare VAR_RESULT, 1
	goto_if_eq ViridianCity_EventScript_ZunGetMonPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
    
ViridianCity_EventScript_ZunGetMonParty::
	playfanfare MUS_LEVEL_UP
	getspeciesname 0, VAR_ZUN_STARTER_SPECIES
	message ViridianCity_Text_ObtainedAnX
	waitmessage
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_ZunDoneGetMon
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto ViridianCity_EventScript_ZunDoneGetMon

ViridianCity_EventScript_ZunGetMonPC::
	playfanfare MUS_LEVEL_UP
	getspeciesname 0, SPECIES_EEVEE
	message ViridianCity_Text_ObtainedAnX
	waitmessage
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_ZunSentMonToPC
	call EventScript_NameReceivedBoxMon
	goto ViridianCity_EventScript_ZunSentMonToPC

ViridianCity_EventScript_ZunSentMonToPC::
	call EventScript_TransferredToPC
	goto ViridianCity_EventScript_ZunDoneGetMon

ViridianCity_EventScript_ZunDoneGetMon::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	return

ViridianCity_EventScript_ZunMenuReturn::
    switch VAR_TEMP_5
    case 0, ViridianCity_EventScript_ZunMenu1
    case 1, ViridianCity_EventScript_ZunMenu2
    case 2, ViridianCity_EventScript_ZunMenu3
    case 3, ViridianCity_EventScript_ZunMenu4
    case 4, ViridianCity_EventScript_ZunMenu5
    case 5, ViridianCity_EventScript_ZunMenu6
    case 6, ViridianCity_EventScript_ZunMenu7
    case 7, ViridianCity_EventScript_ZunMenu8
    case 8, ViridianCity_EventScript_ZunMenu9
    case 9, ViridianCity_EventScript_ZunMenu10
    case 10, ViridianCity_EventScript_ZunMenu11
    case 11, ViridianCity_EventScript_ZunMenu12
    case 12, ViridianCity_EventScript_ZunMenu13
    case 13, ViridianCity_EventScript_ZunMenu14
    case 14, ViridianCity_EventScript_ZunMenu15
    case 15, ViridianCity_EventScript_ZunMenu16
    case 16, ViridianCity_EventScript_ZunMenu17
    case 17, ViridianCity_EventScript_ZunMenu18
    case 18, ViridianCity_EventScript_ZunMenu19
    case 19, ViridianCity_EventScript_ZunMenu20
    case 20, ViridianCity_EventScript_ZunMenu21

ViridianCity_EventScript_ZunMenuBus::
    switch VAR_TEMP_6
    case 0, ViridianCity_EventScript_ZunMenuNext
    case 1, ViridianCity_EventScript_ZunCheckMon
    case 2, ViridianCity_EventScript_ZunCheckMon
    case 3, ViridianCity_EventScript_ZunCheckMon
    case 4, ViridianCity_EventScript_ZunCheckMon
    case 5, ViridianCity_EventScript_ZunCheckMon
    case 6, ViridianCity_EventScript_ZunCheckMon
    case 7, ViridianCity_EventScript_ZunCheckMon
    case 8, ViridianCity_EventScript_ZunCheckMon
    case 9, ViridianCity_EventScript_ZunMenuPrevious

ViridianCity_EventScript_ZunMenuNext::
    switch VAR_TEMP_5
    case 0, ViridianCity_EventScript_ZunMenu2
    case 1, ViridianCity_EventScript_ZunMenu3
    case 2, ViridianCity_EventScript_ZunMenu4
    case 3, ViridianCity_EventScript_ZunMenu5
    case 4, ViridianCity_EventScript_ZunMenu6
    case 5, ViridianCity_EventScript_ZunMenu7
    case 6, ViridianCity_EventScript_ZunMenu8
    case 7, ViridianCity_EventScript_ZunMenu9
    case 8, ViridianCity_EventScript_ZunMenu10
    case 9, ViridianCity_EventScript_ZunMenu11
    case 10, ViridianCity_EventScript_ZunMenu12
    case 11, ViridianCity_EventScript_ZunMenu13
    case 12, ViridianCity_EventScript_ZunMenu14
    case 13, ViridianCity_EventScript_ZunMenu15
    case 14, ViridianCity_EventScript_ZunMenu16
    case 15, ViridianCity_EventScript_ZunMenu17
    case 16, ViridianCity_EventScript_ZunMenu18
    case 17, ViridianCity_EventScript_ZunMenu19
    case 18, ViridianCity_EventScript_ZunMenu20
    case 19, ViridianCity_EventScript_ZunMenu21
    case 20, ViridianCity_EventScript_ZunMenu1

ViridianCity_EventScript_ZunMenuPrevious::
    switch VAR_TEMP_5
    case 0, ViridianCity_EventScript_ZunMenu21
    case 1, ViridianCity_EventScript_ZunMenu1
    case 2, ViridianCity_EventScript_ZunMenu2
    case 3, ViridianCity_EventScript_ZunMenu3
    case 4, ViridianCity_EventScript_ZunMenu4
    case 5, ViridianCity_EventScript_ZunMenu5
    case 6, ViridianCity_EventScript_ZunMenu6
    case 7, ViridianCity_EventScript_ZunMenu7
    case 8, ViridianCity_EventScript_ZunMenu8
    case 9, ViridianCity_EventScript_ZunMenu9
    case 10, ViridianCity_EventScript_ZunMenu10
    case 11, ViridianCity_EventScript_ZunMenu11
    case 12, ViridianCity_EventScript_ZunMenu12
    case 13, ViridianCity_EventScript_ZunMenu13
    case 14, ViridianCity_EventScript_ZunMenu14
    case 15, ViridianCity_EventScript_ZunMenu15
    case 16, ViridianCity_EventScript_ZunMenu16
    case 17, ViridianCity_EventScript_ZunMenu17
    case 18, ViridianCity_EventScript_ZunMenu18
    case 19, ViridianCity_EventScript_ZunMenu19
    case 20, ViridianCity_EventScript_ZunMenu20

ViridianCity_EventScript_ZunMenu1::
    setvar VAR_TEMP_5, 0
    multichoice 8, 0, MULTICHOICE_ZUN1, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu2::
    setvar VAR_TEMP_5, 1
    multichoice 8, 0, MULTICHOICE_ZUN2, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu3::
    setvar VAR_TEMP_5, 2
    multichoice 8, 0, MULTICHOICE_ZUN3, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu4::
    setvar VAR_TEMP_5, 3
    multichoice 8, 0, MULTICHOICE_ZUN4, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu5::
    setvar VAR_TEMP_5, 4
    multichoice 8, 0, MULTICHOICE_ZUN5, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu6::
    setvar VAR_TEMP_5, 5
    multichoice 8, 0, MULTICHOICE_ZUN6, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu7::
    setvar VAR_TEMP_5, 6
    multichoice 8, 0, MULTICHOICE_ZUN7, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu8::
    setvar VAR_TEMP_5, 7
    multichoice 8, 0, MULTICHOICE_ZUN8, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu9::
    setvar VAR_TEMP_5, 8
    multichoice 8, 0, MULTICHOICE_ZUN9, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu10::
    setvar VAR_TEMP_5, 9
    multichoice 8, 0, MULTICHOICE_ZUN10, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu11::
    setvar VAR_TEMP_5, 10
    multichoice 8, 0, MULTICHOICE_ZUN11, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu12::
    setvar VAR_TEMP_5, 11
    multichoice 8, 0, MULTICHOICE_ZUN12, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu13::
    setvar VAR_TEMP_5, 12
    multichoice 8, 0, MULTICHOICE_ZUN13, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu14::
    setvar VAR_TEMP_5, 13
    multichoice 8, 0, MULTICHOICE_ZUN14, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu15::
    setvar VAR_TEMP_5, 14
    multichoice 8, 0, MULTICHOICE_ZUN15, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu16::
    setvar VAR_TEMP_5, 15
    multichoice 8, 0, MULTICHOICE_ZUN16, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu17::
    setvar VAR_TEMP_5, 16
    multichoice 8, 0, MULTICHOICE_ZUN17, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu18::
    setvar VAR_TEMP_5, 17
    multichoice 8, 0, MULTICHOICE_ZUN18, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu19::
    setvar VAR_TEMP_5, 18
    multichoice 8, 0, MULTICHOICE_ZUN19, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu20::
    setvar VAR_TEMP_5, 19
    multichoice 8, 0, MULTICHOICE_ZUN20, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    goto ViridianCity_EventScript_ZunMenuBus

ViridianCity_EventScript_ZunMenu21::
    setvar VAR_TEMP_5, 20
    multichoice 8, 0, MULTICHOICE_ZUN21, TRUE
    copyvar VAR_TEMP_6, VAR_RESULT
    switch VAR_TEMP_6
    case 0, ViridianCity_EventScript_ZunMenu1
    case 1, ViridianCity_EventScript_ZunCheckMon
    case 2, ViridianCity_EventScript_ZunCheckMon
    case 3, ViridianCity_EventScript_ZunCheckMon
    case 4, ViridianCity_EventScript_ZunCheckMon
    case 5, ViridianCity_EventScript_ZunCheckMon
    case 6, ViridianCity_EventScript_ZunCheckMon
    case 7, ViridianCity_EventScript_ZunCheckMon
    case 8, ViridianCity_EventScript_ZunCheckMon
    case 9, ViridianCity_EventScript_ZunMenu20



