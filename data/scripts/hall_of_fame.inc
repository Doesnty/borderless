EventScript_SetDefeatedEliteFourFlagsVars:: @ 81A651A
	clearflag FLAG_HIDE_POSTGAME_GOSSIPERS
	call EventScript_ResetEliteFour
	special Script_UpdateTrainerFanClubGameClear
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	compare VAR_RESULT, FALSE
	call_if_eq EventScript_SetReadyTryGiveNationalDexScene
	call EventScript_ResetLegendaries
	return

EventScript_SetReadyTryGiveNationalDexScene:: @ 81A653B
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	return

EventScript_ResetLegendaries:: @ 81A6541
	clearflag FLAG_LUGIA_FLEW_AWAY
	clearflag FLAG_HO_OH_FLEW_AWAY
	clearflag FLAG_DEOXYS_FLEW_AWAY
	return

EventScript_ResetEliteFourEnd:: @ 81A654B
	call EventScript_ResetEliteFour
	end

EventScript_ResetEliteFour:: @ 81A6551
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_CHAMP
	cleartrainerflag TRAINER_CHAMPION_MARIBEL
	cleartrainerflag TRAINER_CHAMPION_RENKO
	cleartrainerflag TRAINER_CHAMPION_FIRST_CHARMANDER
	cleartrainerflag TRAINER_CHAMPION_REMATCH_MARIBEL
	cleartrainerflag TRAINER_CHAMPION_REMATCH_RENKO
	cleartrainerflag TRAINER_CHAMPION_REMATCH_CHARMANDER
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 0
	return
