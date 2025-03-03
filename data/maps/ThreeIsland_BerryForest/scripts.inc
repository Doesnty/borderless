.set LOCALID_LOSTELLE, 1

ThreeIsland_BerryForest_MapScripts:: @ 8163C71
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition:: @ 8163C77
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 255, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle:: @ 8163C83
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_LOSTELLE, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	goto_if_questlog EventScript_ReleaseEnd
	waitse
	
	trainerbattle_no_intro TRAINER_IMAKUNI_4, ThreeIsland_BerryForest_Text_ImakuniLoss
	
	applymovement LOCALID_LOSTELLE, Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	compare VAR_RESULT, FALSE
	call_if_eq ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special BufferBigGuyOrBigGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 255, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry:: @ 8163D19
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround:: @ 8163D22
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign:: @ 8163D28
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign:: @ 8163D31
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end
