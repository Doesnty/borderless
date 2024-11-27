CinnabarIsland_Mart_MapScripts:: @ 816EA0F
	.byte 0

CinnabarIsland_Mart_EventScript_Woman:: @ 816EA10
	msgbox CinnabarIsland_Mart_Text_DontTheyHaveXAttack, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Scientist:: @ 816EA19
	msgbox CinnabarIsland_Mart_Text_ExtraItemsNeverHurt, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Clerk:: @ 816EA22
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto EventScript_ScaledShop
