SixIsland_Mart_MapScripts:: @ 8171E65
	.byte 0

SixIsland_Mart_EventScript_Clerk:: @ 8171E66
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto EventScript_ScaledShop

SixIsland_Mart_EventScript_Picnicker:: @ 8171EA0
	msgbox SixIsland_Mart_Text_ShouldBuyMailAndWriteLetter, MSGBOX_NPC
	end
