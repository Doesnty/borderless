SaffronCity_CopycatsHouse_2F_MapScripts:: @ 816EB5C
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo:: @ 816EB5D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, 0
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll:: @ 816EB70
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat:: @ 816EB7B
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MIMIC, EventScript_MimicTaught
	checkitem ITEM_POKE_DOLL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_CopycatsHouse_2F_EventScript_GiveTM
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	compare VAR_RESULT, FEMALE
	call_if_eq SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale:: @ 816EBB7
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale:: @ 816EBC0
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_GiveTM:: @ 81C4CF6
	msgbox Text_MimicTeach
	removeitem ITEM_POKE_DOLL, 1
	setflag FLAG_TUTOR_MIMIC
	giveitem_msg Text_GotTM37FromCopycat, ITEM_TM37, 1, MUS_OBTAIN_KEY_ITEM
	release
	end
	
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MimicDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MimicDeclined
	msgbox Text_MimicWhichMon
	setvar VAR_0x8005, MOVETUTOR_MIMIC
	call EventScript_ChooseMoveTutorMon
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq EventScript_MimicDeclined
	removeitem ITEM_POKE_DOLL, 1
	setflag FLAG_TUTOR_MIMIC
	goto EventScript_MimicTaught
	end

EventScript_MimicDeclined:: @ 81C4D4F
	msgbox Text_MimicDeclined
	release
	end

EventScript_MimicTaught:: @ 81C4D59
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq EventScript_MimicTaughtMale
	compare VAR_RESULT, FEMALE
	call_if_eq EventScript_MimicTaughtFemale
	release
	end

EventScript_MimicTaughtMale:: @ 81C4D72
	msgbox Text_MimicTaughtMale
	return

EventScript_MimicTaughtFemale:: @ 81C4D7B
	msgbox Text_MimicTaughtFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer:: @ 816EBC9
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game:: @ 816EBD2
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end
