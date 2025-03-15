NavelRock_1F_MapScripts:: @ 8164F9E
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_1F_OnTransition
	.byte 0

NavelRock_1F_OnLoad::
	call_if_unset FLAG_HIDE_CERULEAN_CAVE_GUARD, NavelRock_1F_EventScript_PlaceBarrier
	end

NavelRock_1F_OnTransition:: @ 81646B4
	setworldmapflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	end

NavelRock_1F_EventScript_PlaceBarrier::
	setmetatile 8, 4, 0x2C0, 1
	return

NavelRock_1F_StairEvent::
	goto_if_set FLAG_HIDE_CERULEAN_CAVE_GUARD NavelRock_1F_StairEventOpen
	lockall
	braillemessage Braille_Text_FindTheGems
	waitbuttonpress
	releaseall
	end

NavelRock_1F_StairEventOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	end
