SSAnne_2F_Room1_MapScripts:: @ 8160C96
	.byte 0

SSAnne_2F_Room1_EventScript_Gentleman:: @ 8160C97
	lock
	faceplayer
	message SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis
	waitmessage
	setvar VAR_0x8004, SPECIES_CDOREMY
	special SetSeenMon
	drawmonpic SPECIES_CDOREMY, 10, 3
	waitbuttonpress
	erasemonpic
	release
	end
