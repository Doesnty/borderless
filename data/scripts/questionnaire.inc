EventScript_Questionnaire:: @ 81A7702
	lockall
	textcolor 3
	msgbox Text_FillOutQuestionnaire, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclineQuestionnaire
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartClerkObjectId
	textcolor 0
	compare VAR_RESULT, 0
	goto_if_eq EventScript_DeclineQuestionnaire
	switch VAR_0x8004
	case 0, EventScript_TookQuestionnaire
	case 1, EventScript_CheatNuggets
	case 2, EventScript_CheatRareCandy
	case 3, EventScript_CheatEvoItems
	case 4, EventScript_CheatTMs
	case 5, EventScript_CheatTutor
	case 6, EventScript_CheatEffortGauge
	case 7, EventScript_CheatMaribel
	case 8, EventScript_CheatRenko
	case 9, EventScript_CheatImakuni
	case 10, EventScript_CheatChampion
	case 11, EventScript_CheatChampionRematch
	end

EventScript_EnableMysteryGift:: @ 81A774D
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLED
	textcolor 3
	special DisableMsgBoxWalkaway
	signmsg
	msgbox Text_YouCanAccessMysteryGift
	normalmsg
	releaseall
	end

EventScript_DeclineQuestionnaire:: @ 81A778A
	releaseall
	end

EventScript_TookQuestionnaire:: @ 81A778C
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	msgbox Text_QuestionnaireThankYou
	releaseall
	end

EventScript_CheatNuggets::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	giveitem_msg Text_Got100Nuggets, ITEM_NUGGET, 100
	releaseall
	end

EventScript_CheatRareCandy::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	giveitem_msg Text_Got600RareCandy, ITEM_RARE_CANDY, 250
	releaseall
	end

EventScript_CheatEvoItems::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	giveitem ITEM_POWER_SHARD, 50
	giveitem ITEM_GUARD_SHARD, 50
	giveitem ITEM_SWIFT_SHARD, 50
	giveitem ITEM_TECH_SHARD, 50
	giveitem ITEM_ASSIST_SHARD, 50
	giveitem ITEM_SOLAR_SHARD, 50
	giveitem ITEM_AUTUMN_LEAF, 50
	giveitem ITEM_DUBIOUS_TOME, 50
	giveitem ITEM_OLD_TEXTBOOK, 50
	giveitem ITEM_IBUKI_GOURD, 50
	releaseall
	end

EventScript_CheatTMs::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	special GiveEveryTM
	playfanfare MUS_LEVEL_UP
	msgbox Text_GotAllTMs
	releaseall
	end

EventScript_CheatTutor::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	goto_if_set FLAG_SYS_UNRESTRICTED_TUTOR, EventScript_CheatTutorRedundant
	msgbox Text_YouKnowThoseWordsTutor
	incrementgamestat GAME_STAT_CHEATS_USED
	setflag FLAG_SYS_UNRESTRICTED_TUTOR
	releaseall
	end

EventScript_CheatTutorRedundant::
	msgbox Text_YouKnowThoseWordsTutorRedundant
	releaseall
	end

EventScript_CheatEffortGauge::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	goto_if_set FLAG_GOT_FAME_CHECKER, EventScript_CheatEffortGaugeRedundant
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	setflag FLAG_GOT_FAME_CHECKER
	giveitem_msg Text_GotEffortGauge, ITEM_FAME_CHECKER, 1
	releaseall
	end

EventScript_CheatEffortGaugeRedundant::
	msgbox Text_YouKnowThoseWordsGaugeRedundant
	releaseall
	end

EventScript_CheatMaribel::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	setvar VAR_TEMP_1, SPECIES_CMARIBEL
	givemon SPECIES_CMARIBEL, 5, ITEM_STARF_BERRY
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CheatMaribelParty
	compare VAR_RESULT, 1
	goto_if_eq EventScript_CheatMaribelPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

EventScript_CheatMaribelParty::
	playfanfare MUS_LEVEL_UP
	message Text_GotCMaribel
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CMARIBEL
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CheatEnd
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto EventScript_CheatEnd
	end

EventScript_CheatMaribelPC::
	playfanfare MUS_LEVEL_UP
	message Text_GotCMaribel
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CMARIBEL
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CheatTransferMon
	call EventScript_NameReceivedBoxMon
	goto EventScript_CheatTransferMon

EventScript_CheatRenko::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWords
	incrementgamestat GAME_STAT_CHEATS_USED
	setvar VAR_TEMP_1, SPECIES_CRENKO
	givemon SPECIES_CRENKO, 5, ITEM_MENTAL_HERB
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CheatRenkoParty
	compare VAR_RESULT, 1
	goto_if_eq EventScript_CheatRenkoPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

EventScript_CheatRenkoParty::
	playfanfare MUS_LEVEL_UP
	message Text_GotCRenko
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CRENKO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CheatEnd
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto EventScript_CheatEnd
	end

EventScript_CheatRenkoPC::
	playfanfare MUS_LEVEL_UP
	message Text_GotCRenko
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CRENKO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CheatTransferMon
	call EventScript_NameReceivedBoxMon
	goto EventScript_CheatTransferMon
	
EventScript_CheatTransferMon::
	call EventScript_TransferredToPC
EventScript_CheatEnd::
	releaseall
	end

EventScript_CheatImakuni::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWordsFight
	trainerbattle_no_intro TRAINER_IMAKUNI_4, ThreeIsland_BerryForest_Text_ImakuniLoss
	releaseall
	end

EventScript_CheatChampion::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWordsFight
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CheatChampionRenko
	compare VAR_RESULT, 1
	goto_if_eq EventScript_CheatChampionMaribel
	releaseall
	end

EventScript_CheatChampionRenko::
	trainerbattle_no_intro TRAINER_CHAMPION_RENKO, Text_CheatPostFightChampion
	releaseall
	end

EventScript_CheatChampionMaribel::
	trainerbattle_no_intro TRAINER_CHAMPION_MARIBEL, Text_CheatPostFightChampion
	releaseall
	end

EventScript_CheatChampionRematch::
	applymovement VAR_0x8008, Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Movement_Delay48
	waitmovement 0
	msgbox Text_YouKnowThoseWordsFight
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CheatChampionRenkoRematch
	compare VAR_RESULT, 1
	goto_if_eq EventScript_CheatChampionMaribelRematch
	releaseall
	end

EventScript_CheatChampionRenkoRematch::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_RENKO, Text_CheatPostFightChampion
	releaseall
	end

EventScript_CheatChampionMaribelRematch::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_MARIBEL, Text_CheatPostFightChampion
	releaseall
	end
