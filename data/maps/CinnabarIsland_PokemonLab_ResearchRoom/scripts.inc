CinnabarIsland_PokemonLab_ResearchRoom_MapScripts:: @ 816E3DE
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor:: @ 816E3DF
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist:: @ 816E3E5
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer:: @ 816E3EE
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe:: @ 816E3F7
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

EventScript_MetronomeTutor:: @ 81C4C8E
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_METRONOME, EventScript_MetronomeTaught
	msgbox Text_MetronomeTeach
	setflag FLAG_TUTOR_METRONOME
	giveitem_msg CinnabarIsland_PokemonLab_ResearchRoom_Text_GotTM69, ITEM_TM69, 1, MUS_OBTAIN_KEY_ITEM
	release
	end
	
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MetronomeDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MetronomeDeclined
	msgbox Text_MetronomeWhichMon
	setvar VAR_0x8005, MOVETUTOR_METRONOME
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_MetronomeDeclined
	setflag FLAG_TUTOR_METRONOME
	goto EventScript_MetronomeTaught
	end

EventScript_MetronomeDeclined:: @ 81C4CE2
	msgbox Text_MetronomeDeclined
	release
	end

EventScript_MetronomeTaught:: @ 81C4CEC
	msgbox Text_MetronomeTaught
	release
	end
