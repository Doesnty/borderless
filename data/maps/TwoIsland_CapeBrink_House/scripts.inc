TwoIsland_CapeBrink_House_MapScripts:: @ 817206B
	.byte 0

TwoIsland_CapeBrink_House_EventScript_StarterTutor::
	lock
	faceplayer
	goto_if_set FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK, CapeBrinkTutor_EventScript_TaughtAllMoves
	getfirstpartymonname 0
	msgbox Text_UltimateMoveThatMon
	specialvar VAR_RESULT, CapeBrinkGetMoveToTeachLeadPokemon
	compare VAR_RESULT, FALSE
	goto_if_eq CapeBrinkTutor_EventScript_NoLeadStarter
	copyvar VAR_0x8009, VAR_0x8005
	compare VAR_FACING, DIR_NORTH
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceDown
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceUp
	compare VAR_FACING, DIR_EAST
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceLeft
	compare VAR_FACING, DIR_WEST
	call_if_eq CapeBrinkTutor_EventScript_JumpInPlaceRight
	msgbox Text_AllowMeToTeachMonUltimateMove
	
	giveitem_msg Text_ReceivedTM59, ITEM_TM59, 1, MUS_OBTAIN_KEY_ITEM
	setflag FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK
	
	msgbox Text_PassedOnEverythingIKnow
	release
	end

CapeBrinkTutor_EventScript_TaughtAllMoves:: @ 81C4EA1
	msgbox Text_FeelRejuvenated
	release
	end
