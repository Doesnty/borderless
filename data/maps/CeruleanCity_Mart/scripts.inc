CeruleanCity_Mart_MapScripts:: @ 816AC9D
	.byte 0

CeruleanCity_Mart_EventScript_Youngster:: @ 816AC9E
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman:: @ 816ACA7
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk:: @ 816ACB0
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto EventScript_ScaledShop
