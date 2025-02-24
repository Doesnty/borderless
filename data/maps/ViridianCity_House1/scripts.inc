ViridianCity_House1_MapScripts:: @ 8169E9A
	.byte 0

ViridianCity_House1_EventScript_BaldingMan:: @ 8169E9B
	msgbox ViridianCity_House1_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_LittleGirl:: @ 8169EA4
	msgbox ViridianCity_House1_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, 0
	msgbox ViridianCity_House1_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_NicknameSign:: @ 8169EC0
	msgbox ViridianCity_House1_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House1_EventScript_Cheat:
	message ViridianCity_House1_Text_NicknamingIsFun
    waitmessage
    multichoice 11, 0, MULTICHOICE_GAME_CORNER_POKEMON_PRIZES, 0
    switch VAR_RESULT
	case 0, ViridianCity_House1_EventScript_GiveFirst200
	case 1, ViridianCity_House1_EventScript_GivePast200
    case 2, ViridianCity_House1_EventScript_GiveTMs

ViridianCity_House1_EventScript_GiveFirst200::
	setvar VAR_TEMP_1, 0x1
loop1start:
	givemon VAR_TEMP_1, 60, ITEM_NONE
	addvar VAR_TEMP_1, 0x1
	compare VAR_TEMP_1, 250
	goto_if_lt loop1start
	release
	end
    
ViridianCity_House1_EventScript_GivePast200::
	setvar VAR_TEMP_1, 251
loop2start:
	givemon VAR_TEMP_1, 59, ITEM_NONE
	addvar VAR_TEMP_1, 0x1
	compare VAR_TEMP_1, NUM_SPECIES
	goto_if_lt loop2start
	release
	end

ViridianCity_House1_EventScript_GiveTMs::
	setvar VAR_TEMP_1, ITEM_TM01
loop3start:
    giveitem VAR_TEMP_1, 1
    addvar VAR_TEMP_1, 0x1
    compare VAR_TEMP_1, ITEM_HM08
    goto_if_lt loop3start
    release
    end
	
ViridianCity_House1_EventScript_DebugFight::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, 0
	waitmoncry
	trainerbattle_single TRAINER_AQUA_GRUNT_F, ViridianCity_House1_Text_Speary, ViridianCity_House1_Text_Speary, ViridianCity_House1_EventScript_DebugFightEnd, NO_MUSIC
ViridianCity_House1_EventScript_DebugFightEnd::
	release
	end



