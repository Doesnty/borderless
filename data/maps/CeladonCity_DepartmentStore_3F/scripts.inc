CeladonCity_DepartmentStore_3F_MapScripts:: @ 816BB84
	.byte 0

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor:: @ 816BB85
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1:: @ 816BB8B
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2:: @ 816BB94
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3:: @ 816BB9D
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl:: @ 816BBA6
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES:: @ 816BBAF
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1:: @ 816BBB8
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2:: @ 816BBC1
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3:: @ 816BBCA
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4:: @ 816BBD3
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign:: @ 816BBDC
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster:: @ 816BBE5
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Psychiatrist::
	lock
	faceplayer
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Intro, 4
	waitmessage
	showmoneybox 0, 0, 0
    nop
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_ShowPrice, MSGBOX_YESNO
	hidemoneybox 0, 0
	compare VAR_RESULT, NO
	goto_if_eq CeladonCity_DepartmentStore_3F_EventScript_PsychiatristBye
    
	checkmoney 10000, 0
    compare VAR_RESULT, 0
    goto_if_eq CeladonCity_DepartmentStore_3F_EventScript_PsychiatristNeedMoney
    
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichMon, 4
	special ChoosePartyMon
	waitstate
    compare VAR_0x8004, 255
	goto_if_eq CeladonCity_DepartmentStore_3F_EventScript_PsychiatristBye
    
	specialvar VAR_RESULT, GetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq CeladonCity_DepartmentStore_3F_EventScript_PsychiatristEgg

CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichStrength, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER1, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_AttackUp
    case 1, CeladonCity_DepartmentStore_3F_EventScript_DefenseUp
    case 2, CeladonCity_DepartmentStore_3F_EventScript_SpAtkUp
    case 3, CeladonCity_DepartmentStore_3F_EventScript_SpDefUp
    case 4, CeladonCity_DepartmentStore_3F_EventScript_SpeedUp
    case 5, CeladonCity_DepartmentStore_3F_EventScript_Balance
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristBye

CeladonCity_DepartmentStore_3F_EventScript_AttackUp:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER2, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Lonely
    case 1, CeladonCity_DepartmentStore_3F_EventScript_Adamant
    case 2, CeladonCity_DepartmentStore_3F_EventScript_Naughty
    case 3, CeladonCity_DepartmentStore_3F_EventScript_Brave
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick

CeladonCity_DepartmentStore_3F_EventScript_DefenseUp:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER3, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Bold
    case 1, CeladonCity_DepartmentStore_3F_EventScript_Impish
    case 2, CeladonCity_DepartmentStore_3F_EventScript_Lax
    case 3, CeladonCity_DepartmentStore_3F_EventScript_Relaxed
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick

CeladonCity_DepartmentStore_3F_EventScript_SpAtkUp:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER4, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Modest
    case 1, CeladonCity_DepartmentStore_3F_EventScript_Mild
    case 2, CeladonCity_DepartmentStore_3F_EventScript_Rash
    case 3, CeladonCity_DepartmentStore_3F_EventScript_Quiet
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick

CeladonCity_DepartmentStore_3F_EventScript_SpDefUp:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER5, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Calm
    case 1, CeladonCity_DepartmentStore_3F_EventScript_Gentle
    case 2, CeladonCity_DepartmentStore_3F_EventScript_Careful
    case 3, CeladonCity_DepartmentStore_3F_EventScript_Sassy
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick

CeladonCity_DepartmentStore_3F_EventScript_SpeedUp:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, MULTICHOICE_NATURE_CHANGER6, 0
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Timid
    case 1, CeladonCity_DepartmentStore_3F_EventScript_Hasty
    case 2, CeladonCity_DepartmentStore_3F_EventScript_Jolly
    case 3, CeladonCity_DepartmentStore_3F_EventScript_Naive
    goto CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick

CeladonCity_DepartmentStore_3F_EventScript_Balance:
    setvar VAR_0x8001, 6
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Balance, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Lonely:
    setvar VAR_0x8001, 1
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Lonely, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Brave:
    setvar VAR_0x8001, 2
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Brave, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Adamant:
    setvar VAR_0x8001, 3
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Adamant, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Naughty:
    setvar VAR_0x8001, 4
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Naughty, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Bold:
    setvar VAR_0x8001, 5
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Bold, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Relaxed:
    setvar VAR_0x8001, 7
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Relaxed, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Impish:
    setvar VAR_0x8001, 8
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Impish, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Lax:
    setvar VAR_0x8001, 9
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Lax, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Timid:
    setvar VAR_0x8001, 10
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Timid, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Hasty:
    setvar VAR_0x8001, 11
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Hasty, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Jolly:
    setvar VAR_0x8001, 13
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Jolly, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Naive:
    setvar VAR_0x8001, 14
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Naive, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Modest:
    setvar VAR_0x8001, 15
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Modest, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Mild:
    setvar VAR_0x8001, 16
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Mild, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Quiet:
    setvar VAR_0x8001, 17
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Quiet, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Rash:
    setvar VAR_0x8001, 19
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Rash, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Calm:
    setvar VAR_0x8001, 20
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Calm, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Gentle:
    setvar VAR_0x8001, 21
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Gentle, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Sassy:
    setvar VAR_0x8001, 22
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Sassy, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation

CeladonCity_DepartmentStore_3F_EventScript_Careful:
    setvar VAR_0x8001, 23
	msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Careful, MSGBOX_YESNO
    goto CeladonCity_DepartmentStore_3F_EventScript_Operation


CeladonCity_DepartmentStore_3F_EventScript_Operation:
	compare VAR_RESULT, NO
	goto_if_eq CeladonCity_DepartmentStore_3F_EventScript_PsychiatristFirstPick
    special SetNatureOverride
    switch VAR_RESULT
    case 0, CeladonCity_DepartmentStore_3F_EventScript_Redundant
    case 1, CeladonCity_DepartmentStore_3F_EventScript_CollectPay
    
CeladonCity_DepartmentStore_3F_EventScript_CollectPay:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Done, 4
	waitmessage
	showmoneybox 0, 0, 0
    nop
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Done2, 4
	removemoney 10000, 0
	updatemoneybox 0, 0, 0
	nop
	playse SE_SHOP
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Bye, 4
	hidemoneybox 0, 0
    release
	end
    
CeladonCity_DepartmentStore_3F_EventScript_Redundant:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Redundant, 4
    release
	end

CeladonCity_DepartmentStore_3F_EventScript_PsychiatristEgg:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Egg, 4
    release
	end

CeladonCity_DepartmentStore_3F_EventScript_PsychiatristNeedMoney:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_NeedMoney, 4
    release
	end

CeladonCity_DepartmentStore_3F_EventScript_PsychiatristBye:
    msgbox CeladonCity_DepartmentStore_3F_Text_Psychiatrist_Bye, 4
    release
	end


