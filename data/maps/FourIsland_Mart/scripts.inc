FourIsland_Mart_MapScripts:: @ 8171CAD
	.byte 0

FourIsland_Mart_EventScript_Clerk:: @ 8171CAE
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto EventScript_ScaledShop

FourIsland_Mart_EventScript_Camper:: @ 8171CE8
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
	end
