Route9_MapScripts:: @ 8167FCF
	.byte 0

Route9_EventScript_RouteSign:: @ 8167FD0
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_EventScript_Mamizou::
	goto_if_unset FLAG_BADGE03_GET, Route9_EventScript_MamizouNoBadge
	goto_if_unset FLAG_GOT_BICYCLE, Route9_EventScript_MamizouYesBadgeNoBike
Route9_EventScript_MamizouYesBadgeYesBike::
	msgbox Route9_Text_MamizouYesBadgeYesBike, MSGBOX_NPC
	end

Route9_EventScript_MamizouYesBadgeNoBike::
	msgbox Route9_Text_MamizouYesBadgeNoBike, MSGBOX_NPC
	end

Route9_EventScript_MamizouNoBadge::
	goto_if_unset FLAG_GOT_BICYCLE, Route9_EventScript_MamizouNoBadgeNoBike
	msgbox Route9_Text_MamizouNoBadgeYesBike, MSGBOX_NPC
	end

Route9_EventScript_MamizouNoBadgeNoBike::
	msgbox Route9_Text_MamizouNoBadgeNoBike, MSGBOX_NPC
	end

