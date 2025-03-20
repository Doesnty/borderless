.equ LOCALID_DOME_FOSSIL,  1
.equ LOCALID_HELIX_FOSSIL, 2
.equ LOCALID_MIGUEL,       3

MtMoon_B2F_MapScripts:: @ 8160699
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtMoon_B2F_OnResume
	.byte 0

MtMoon_B2F_OnResume:: @ 8168006
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MtMoon_B2F_EventScript_TryRemoveSnorlax
	end

MtMoon_B2F_EventScript_TryRemoveSnorlax:: @ 8168010
	removeobject VAR_LAST_TALKED
	return


MtMoon_B2F_OnTransition:: @ 816069F
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils:: @ 81606A9
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_Miguel:: @ 81606C2
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel:: @ 81606DD
	textcolor 0
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked:: @ 8160707
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil:: @ 8160711
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	release
	end

MtMoon_B2F_EventScript_DomeFossil:: @ 816071B
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	special QuestLog_CutRecording
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 0
	moveobjectoffscreen LOCALID_MIGUEL
	textcolor 0
	playfanfare MUS_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_GOT_DOME_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil:: @ 816077A
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil:: @ 816077F
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	special QuestLog_CutRecording
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 0
	moveobjectoffscreen LOCALID_MIGUEL
	textcolor 0
	playfanfare MUS_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_GOT_HELIX_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil:: @ 81607DE
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil:: @ 81607E0
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1:: @ 81607E4
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2:: @ 81607FB
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3:: @ 8160812
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4:: @ 8160829
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_MiguelTrigger1::
	lockall
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniLookAround
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_MIGUEL, Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniWalkToPlayer1
    waitmovement 0
    goto MtMoon_B2F_EventScript_ImakuniEncounter

MtMoon_B2F_EventScript_MiguelTrigger2::
	lockall
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniLookAround
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_MIGUEL, Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniWalkToPlayer2
    waitmovement 0
    goto MtMoon_B2F_EventScript_ImakuniEncounter

MtMoon_B2F_EventScript_MiguelTrigger3::
	lockall
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniLookAround
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_MIGUEL, Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniWalkToPlayer3
    waitmovement 0
    goto MtMoon_B2F_EventScript_ImakuniEncounter

MtMoon_B2F_EventScript_MiguelTrigger4::
	lockall
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniLookAround
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_MIGUEL, Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniWalkToPlayer4
    waitmovement 0
    goto MtMoon_B2F_EventScript_ImakuniEncounter
    
MtMoon_B2F_EventScript_ImakuniEncounter::
	textcolor 0
	message MtMoon_B2F_Text_ImakuniIntro2
	waitmessage
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_ImakuniLoss
	msgbox MtMoon_B2F_Text_ImakuniPostFight
    closemessage
    applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_ImakuniLeave
    waitmovement 0
    setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
    setflag FLAG_HIDE_DOME_FOSSIL
    setflag FLAG_HIDE_HELIX_FOSSIL
	removeobject LOCALID_MIGUEL
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
    end

MtMoon_B2F_Movement_ImakuniLookAround::
	walk_in_place_fast_down
	walk_in_place_fast_left
	walk_in_place_fast_up
	walk_in_place_fast_right
	walk_in_place_fast_down
	walk_in_place_fast_left
	walk_in_place_fast_up
	walk_in_place_fast_right
	walk_in_place_fast_down
	walk_in_place_fast_left
	walk_in_place_fast_up
	walk_in_place_fast_right
	step_end

MtMoon_B2F_Movement_ImakuniWalkToPlayer1::
	walk_right
    walk_right
    walk_up
    walk_up
    face_right
	step_end

MtMoon_B2F_Movement_ImakuniWalkToPlayer2::
	walk_right
    walk_right
    walk_up
    face_right
	step_end

MtMoon_B2F_Movement_ImakuniWalkToPlayer3::
	walk_right
    walk_right
    face_right
	step_end

MtMoon_B2F_Movement_ImakuniWalkToPlayer4::
	walk_right
    walk_right
    walk_down
    face_right
	step_end

MtMoon_B2F_Movement_ImakuniLeave::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

MtMoon_B2F_EventScript_Snorlax:: @ 8168014
	lock
	goto_if_unset FLAG_GOT_POKE_FLUTE, MtMoon_B2F_EventScript_SnorlaxNoPokeFlute
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
	setflag FLAG_HIDE_MTMOON_SNORLAX
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setflag FLAG_WOKE_UP_MTMOON_SNORLAX
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

MtMoon_B2F_EventScript_DontUsePokeFlute:: @ 816808D
	release
	end

MtMoon_B2F_EventScript_FoughtSnorlax:: @ 816808F
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

MtMoon_B2F_EventScript_SnorlaxNoPokeFlute:: @ 8168099
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end
