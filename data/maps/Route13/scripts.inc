Route13_MapScripts:: @ 81680B5
	map_script MAP_SCRIPT_ON_RESUME, Route13_OnResume
	.byte 0

Route13_OnResume::
	setflag FLAG_ENTERED_ROUTE_13
	end

Route13_EventScript_TrainerTips1:: @ 81680B6
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2:: @ 81680BF
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign:: @ 81680C8
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end
