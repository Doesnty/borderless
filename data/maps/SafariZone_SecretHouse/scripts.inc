SafariZone_SecretHouse_MapScripts:: @ 8162452
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant:: @ 8162453
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM07, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM07
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03:: @ 816249F
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf:: @ 81624A9
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end
