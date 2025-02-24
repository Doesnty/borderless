SilphCo_2F_MapScripts:: @ 8161641
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad:: @ 8161647
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor:: @ 816165A
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign:: @ 8161660
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor:: @ 8161669
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry:: @ 8161680
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1:: @ 8161697
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2:: @ 81616AE
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

EventScript_ThunderWaveTutor:: @ 81C4816
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_THUNDER_WAVE, EventScript_ThunderWaveTaught
	msgbox Text_ThunderWaveTeach
	
	setflag FLAG_TUTOR_THUNDER_WAVE
	giveitem_msg SilphCo_2F_Text_GotTM40, ITEM_TM40, 1, MUS_OBTAIN_KEY_ITEM
	release
	end
	
	
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ThunderWaveDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ThunderWaveDeclined
	msgbox Text_ThunderWaveWhichMon
	setvar VAR_0x8005, MOVETUTOR_THUNDER_WAVE
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_ThunderWaveDeclined
	setflag FLAG_TUTOR_THUNDER_WAVE
	goto EventScript_ThunderWaveTaught
	end

EventScript_ThunderWaveDeclined:: @ 81C486A
	msgbox Text_ThunderWaveDeclined
	release
	end

EventScript_ThunderWaveTaught:: @ 81C4874
	msgbox Text_ThunderWaveTaught
	release
	end
