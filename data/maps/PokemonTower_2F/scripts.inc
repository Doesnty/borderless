.set LOCALID_RIVAL, 6

PokemonTower_2F_MapScripts:: @ 8163285
	.byte 0

PokemonTower_2F_EventScript_Channeler:: @ 8163286
	msgbox PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts, MSGBOX_NPC
	end

PokemonTower_2F_EventScript_RivalTriggerRight:: @ 816328F
	lockall
	setvar VAR_TEMP_1, 0
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_RivalTriggerDown:: @ 816329B
	lockall
	setvar VAR_TEMP_1, 1
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_Rival:: @ 81632A7
	textcolor 0
	playbgm MUS_ENCOUNTER_RIVAL, 0
	compare VAR_TEMP_1, 0
	call_if_eq PokemonTower_2F_EventScript_RivalFacePlayerRight
	compare VAR_TEMP_1, 1
	call_if_eq PokemonTower_2F_EventScript_RivalFacePlayerDown
	msgbox PokemonTower_2F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	compare VAR_STARTER_MON, 2
	call_if_eq PokemonTower_2F_EventScript_RivalSquirtle
	compare VAR_STARTER_MON, 1
	call_if_eq PokemonTower_2F_EventScript_RivalBulbasaur
	compare VAR_STARTER_MON, 0
	call_if_eq PokemonTower_2F_EventScript_RivalCharmander
	msgbox PokemonTower_2F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	compare VAR_TEMP_1, 0
	call_if_eq PokemonTower_2F_EventScript_RivalExitRight
	compare VAR_TEMP_1, 1
	call_if_eq PokemonTower_2F_EventScript_RivalExitDown
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setvar VAR_MAP_SCENE_POKEMON_TOWER_2F, 1
	releaseall
	end

PokemonTower_2F_EventScript_RivalFacePlayerRight:: @ 8163339
	applymovement LOCALID_RIVAL, PokemonTower_6F_Movement_RivalGreetRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalFacePlayerDown:: @ 816334B
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	applymovement LOCALID_RIVAL, PokemonTower_6F_Movement_RivalGreetLeft
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalSquirtle:: @ 816335D
	trainerbattle_no_intro TRAINER_RIVAL_POKENON_TOWER_SQUIRTLE, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalBulbasaur:: @ 8163368
	trainerbattle_no_intro TRAINER_RIVAL_POKENON_TOWER_BULBASAUR, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalCharmander:: @ 8163373
	trainerbattle_no_intro TRAINER_RIVAL_POKENON_TOWER_CHARMANDER, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalExitRight:: @ 816337E
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitRight
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalExitDown:: @ 8163389
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitDown
	waitmovement 0
	return
	
PokemonTower_6F_Movement_RivalGreetLeft::
	face_up
	emote_exclamation_mark
	delay_16
	delay_16
	walk_up
	step_end
	
PokemonTower_6F_Movement_RivalGreetRight::
	face_up
	emote_exclamation_mark
	delay_16
	delay_16
	walk_up
	face_right
	step_end

PokemonTower_2F_Movement_RivalExitRight:: @ 8163394
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PokemonTower_2F_Movement_RivalExitDown:: @ 816339D
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end
