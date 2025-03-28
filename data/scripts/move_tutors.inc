EventScript_GlobalMoveTutor::
	lock
	message GlobalMoveTutor_Text_Intro
	waitmessage
	multichoice 0, 0, MULTICHOICE_MOVE_TUTOR, FALSE
	switch VAR_RESULT
	case 0, EventScript_GlobalMoveTutorRelearner
	case 1, EventScript_GlobalMoveTutorInheritor
	case 2, EventScript_GlobalMoveTutorDeleter
EventScript_GlobalMoveTutorEnd::
	release
	end

EventScript_GlobalMoveTutorSelectedEgg::
	msgbox GlobalMoveTutor_Text_Egg
	release
	end

EventScript_GlobalMoveTutorNothingToLearn::
	msgbox GlobalMoveTutor_Text_NothingToLearn
	release
	end

EventScript_GlobalMoveTutorNothingToForget::
	msgbox GlobalMoveTutor_Text_NothingToForget
	release
	end

EventScript_GlobalMoveTutorRelearner::
	msgbox GlobalMoveTutor_Text_RelearnWhich
	setvar VAR_0x8005, 0
	special SelectMoveTutorMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_GlobalMoveTutorEnd
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_GlobalMoveTutorSelectedEgg
	compare VAR_0x8005, 0
	goto_if_eq EventScript_GlobalMoveTutorNothingToLearn
	
	setvar VAR_0x8005, 0
	special DisplayMoveTutorMenu
	waitstate
	release
	end


EventScript_GlobalMoveTutorInheritor::
	msgbox GlobalMoveTutor_Text_TutorWhich
	setvar VAR_0x8005, 1
	special SelectMoveTutorMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_GlobalMoveTutorEnd
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_GlobalMoveTutorSelectedEgg
	compare VAR_0x8005, 0
	goto_if_eq EventScript_GlobalMoveTutorNothingToLearn
	
	setvar VAR_0x8005, 1
	special DisplayMoveTutorMenu
	waitstate
	release
	end

EventScript_GlobalMoveTutorDeleter::	
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge EventScript_GlobalMoveTutorEnd
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_GlobalMoveTutorSelectedEgg
	special GetNumMovesSelectedMonHas
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GlobalMoveTutorNothingToForget
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special SelectMoveDeleterMove
	fadescreen FADE_FROM_BLACK
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq EventScript_GlobalMoveTutorDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_GlobalMoveTutorDeleterDoDelete
	goto EventScript_GlobalMoveTutorDeleter

EventScript_GlobalMoveTutorDeleterDoDelete::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

VictoryRoad_2F_EventScript_DoubleEdgeTutor:: @ 81C47AE
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_DOUBLE_EDGE, EventScript_DoubleEdgeTaught
	msgbox Text_DoubleEdgeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DoubleEdgeDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DoubleEdgeDeclined
	msgbox Text_DoubleEdgeWhichMon
	setvar VAR_0x8005, MOVETUTOR_DOUBLE_EDGE
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_DoubleEdgeDeclined
	setflag FLAG_TUTOR_DOUBLE_EDGE
	goto EventScript_DoubleEdgeTaught
	end

EventScript_DoubleEdgeDeclined:: @ 81C4802
	msgbox Text_DoubleEdgeDeclined
	release
	end

EventScript_DoubleEdgeTaught:: @ 81C480C
	msgbox Text_DoubleEdgeTaught
	release
	end

RockTunnel_B1F_EventScript_RockSlideTutor:: @ 81C487E
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_ROCK_SLIDE, EventScript_RockSlideTaught
	msgbox Text_RockSlideTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_RockSlideDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_RockSlideDeclined
	msgbox Text_RockSlideWhichMon
	setvar VAR_0x8005, MOVETUTOR_ROCK_SLIDE
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RockSlideDeclined
	setflag FLAG_TUTOR_ROCK_SLIDE
	goto EventScript_RockSlideTaught
	end

EventScript_RockSlideDeclined:: @ 81C48D2
	msgbox Text_RockSlideDeclined
	release
	end

EventScript_RockSlideTaught:: @ 81C48DC
	msgbox Text_RockSlideTaught
	release
	end

MtEmber_Exterior_EventScript_ExplosionTutor:: @ 81C48E6
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_EXPLOSION, EventScript_ExplosionTaught
	msgbox Text_ExplosionTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ExplosionDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ExplosionDeclined
	msgbox Text_ExplosionWhichMon
	setvar VAR_0x8005, MOVETUTOR_EXPLOSION
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_ExplosionDeclined
	setflag FLAG_TUTOR_EXPLOSION
	goto EventScript_ExplosionTaught
	end

EventScript_ExplosionDeclined:: @ 81C493A
	msgbox Text_ExplosionDeclined
	release
	end

EventScript_ExplosionTaught:: @ 81C4944
	msgbox Text_ExplosionTaught
	release
	end

Route4_EventScript_MegaPunchTutor:: @ 81C494E
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM77, EventScript_MegaPunchTaught
	msgbox Text_MegaPunchTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MegaPunchDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MegaPunchDeclined
	msgbox Text_MegaPunchWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_PUNCH
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_MegaPunchDeclined
	setflag FLAG_GOT_TM77
	goto EventScript_MegaPunchTaught
	end

EventScript_MegaPunchDeclined:: @ 81C49A2
	msgbox Text_MegaPunchDeclined
	release
	end

EventScript_MegaPunchTaught:: @ 81C49AC
	msgbox Text_MegaPunchTaught
	release
	end

Route4_EventScript_MegaKickTutor:: @ 81C49B6
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MEGA_KICK, EventScript_MegaKickTaught
	msgbox Text_MegaKickTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MegaKickDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_MegaKickDeclined
	msgbox Text_MegaKickWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_KICK
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_MegaKickDeclined
	setflag FLAG_TUTOR_MEGA_KICK
	goto EventScript_MegaKickTaught
	end

EventScript_MegaKickDeclined:: @ 81C4A0A
	msgbox Text_MegaKickDeclined
	release
	end

EventScript_MegaKickTaught:: @ 81C4A14
	msgbox Text_MegaKickTaught
	release
	end

EventScript_DreamEaterTutor:: @ 81C4A1E
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_DREAM_EATER, EventScript_DreamEaterTaught
	msgbox Text_DreamEaterTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DreamEaterDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DreamEaterDeclined
	msgbox Text_DreamEaterWhichMon
	setvar VAR_0x8005, MOVETUTOR_DREAM_EATER
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_DreamEaterDeclined
	setflag FLAG_TUTOR_DREAM_EATER
	goto EventScript_DreamEaterTaught
	end

EventScript_DreamEaterDeclined:: @ 81C4A72
	msgbox Text_DreamEaterDeclined
	release
	end

EventScript_DreamEaterTaught:: @ 81C4A7C
	msgbox Text_DreamEaterTaught
	release
	end

EventScript_SoftboiledTutor:: @ 81C4A86
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SOFT_BOILED, EventScript_SoftboiledTaught
	msgbox Text_SoftboiledTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SoftboiledDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SoftboiledDeclined
	msgbox Text_SoftboiledWhichMon
	setvar VAR_0x8005, MOVETUTOR_SOFT_BOILED
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SoftboiledDeclined
	setflag FLAG_TUTOR_SOFT_BOILED
	goto EventScript_SoftboiledTaught
	end

EventScript_SoftboiledDeclined:: @ 81C4ADA
	msgbox Text_SoftboiledDeclined
	release
	end

EventScript_SoftboiledTaught:: @ 81C4AE4
	msgbox Text_SoftboiledTaught
	release
	end

FuchsiaCity_EventScript_SubstituteTutor:: @ 81C4AEE
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SUBSTITUTE, EventScript_SubstituteTaught
	msgbox Text_SubstituteTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SubstituteDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SubstituteDeclined
	msgbox Text_SubstituteWhichMon
	setvar VAR_0x8005, MOVETUTOR_SUBSTITUTE
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SubstituteDeclined
	setflag FLAG_TUTOR_SUBSTITUTE
	goto EventScript_SubstituteTaught
	end

EventScript_SubstituteDeclined:: @ 81C4B42
	msgbox Text_SubstituteDeclined
	release
	end

EventScript_SubstituteTaught:: @ 81C4B4C
	msgbox Text_SubstituteTaught
	release
	end

SevenIsland_EventScript_SwordsDanceTutor:: @ 81C4B56
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SWORDS_DANCE, EventScript_SwordsDanceTaught
	msgbox Text_SwordsDanceTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SwordsDanceDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SwordsDanceDeclined
	msgbox Text_SwordsDanceWhichMon
	setvar VAR_0x8005, MOVETUTOR_SWORDS_DANCE
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SwordsDanceDeclined
	setflag FLAG_TUTOR_SWORDS_DANCE
	goto EventScript_SwordsDanceTaught
	end

EventScript_SwordsDanceDeclined:: @ 81C4BAA
	msgbox Text_SwordsDanceDeclined
	release
	end

EventScript_SwordsDanceTaught:: @ 81C4BB4
	msgbox Text_SwordsDanceTaught
	release
	end

PewterCity_Museum_1F_EventScript_SeismicTossTutor:: @ 81C4BBE
	msgbox Text_SeismicTossTeach, MSGBOX_NPC
	end
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SEISMIC_TOSS, EventScript_SeismicTossTaught
	msgbox Text_SeismicTossTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SeismicTossDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SeismicTossDeclined
	msgbox Text_SeismicTossWhichMon
	setvar VAR_0x8005, MOVETUTOR_SEISMIC_TOSS
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SeismicTossDeclined
	setflag FLAG_TUTOR_SEISMIC_TOSS
	goto EventScript_SeismicTossTaught
	end

EventScript_SeismicTossDeclined:: @ 81C4C12
	msgbox Text_SeismicTossDeclined
	release
	end

EventScript_SeismicTossTaught:: @ 81C4C1C
	msgbox Text_SeismicTossTaught
	release
	end

EventScript_CounterTutor:: @ 81C4C26
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_COUNTER, EventScript_CounterTaught
	msgbox Text_CounterTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CounterDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CounterDeclined
	msgbox Text_CounterWhichMon
	setvar VAR_0x8005, MOVETUTOR_COUNTER
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CounterDeclined
	setflag FLAG_TUTOR_COUNTER
	goto EventScript_CounterTaught
	end

EventScript_CounterDeclined:: @ 81C4C7A
	msgbox Text_CounterDeclined
	release
	end

EventScript_CounterTaught:: @ 81C4C84
	msgbox Text_CounterTaught
	release
	end

FourIsland_House1_EventScript_BodySlamTutor:: @ 81C4D84
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_BODY_SLAM, EventScript_BodySlamTaught
	msgbox Text_BodySlamTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_BodySlamDeclined
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq EventScript_BodySlamDeclined
	msgbox Text_BodySlamWhichMon
	setvar VAR_0x8005, MOVETUTOR_BODY_SLAM
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_BodySlamDeclined
	setflag FLAG_TUTOR_BODY_SLAM
	goto EventScript_BodySlamTaught
	end

EventScript_BodySlamDeclined:: @ 81C4DD8
	msgbox Text_BodySlamDeclined
	release
	end

EventScript_BodySlamTaught:: @ 81C4DE2
	msgbox Text_BodySlamTaught
	release
	end

.set LOCALID_CAPE_BRINK_TUTOR, 1

:: @ 81C4DEC
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_set FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK, CapeBrinkTutor_EventScript_TaughtAllMoves
	goto_if_set FLAG_TEMP_2, CapeBrinkTutor_EventScript_MoveJustTaught
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
	msgbox Text_AllowMeToTeachMonUltimateMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	call EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	msgbox Text_LetMeConferUltimateMove
	closemessage
	fadescreen FADE_TO_BLACK
	goto CapeBrinkTutor_EventScript_ChooseMon

@ Unused
CapeBrinkTutor_EventScript_FadeTaughtMove:: @ 81C4E8F
	fadescreen FADE_FROM_BLACK
	goto CapeBrinkTutor_EventScript_TaughtMove
	end

CapeBrinkTutor_EventScript_MoveJustTaught:: @ 81C4E97
	msgbox Text_MakeBestUseOfMove
	release
	end

CapeBrinkTutor_EventScript_TaughtMove:: @ 81C4EAB
	copyvar VAR_0x8005, VAR_0x8009
	specialvar VAR_RESULT, HasLearnedAllMovesFromCapeBrinkTutor
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrinkTutor_EventScript_LearnedAllMoves
	msgbox Text_TaughtMove
	setflag FLAG_TEMP_2
	release
	end

CapeBrinkTutor_EventScript_LearnedAllMoves:: @ 81C4ECD
	msgbox Text_PassedOnEverythingIKnow
	setflag FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK
	release
	end

CapeBrinkTutor_EventScript_ChooseMon:: @ 81C4EDA
	call EventScript_ChooseMoveTutorMon
	compare VAR_RESULT, FALSE
	goto_if_eq CapeBrinkTutor_EventScript_DeclineMove
	goto CapeBrinkTutor_EventScript_TaughtMove
	end

CapeBrinkTutor_EventScript_JumpInPlaceDown:: @ 81C4EF0
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceDown
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceUp:: @ 81C4EFB
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceUp
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceLeft:: @ 81C4F06
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceLeft
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceRight:: @ 81C4F11
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceRight
	waitmovement 0
	return

CapeBrinkTutor_EventScript_DeclineMove:: @ 81C4F1C
	msgbox Text_YouRejectIt
	release
	end

CapeBrinkTutor_EventScript_NoLeadStarter:: @ 81C4F26
	msgbox Text_JustMistaken
	release
	end

EventScript_ChooseMoveTutorMon:: @ 81C4F30
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

EventScript_CanOnlyBeLearnedOnce:: @ 81C4F37
	textcolor 3
	special DisableMsgBoxWalkaway
	signmsg
	msgbox Text_MoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	normalmsg
	call EventScript_RestorePrevTextColor
	return

Movement_JumpInPlaceDown: @ 81C4F4C
	jump_in_place_down
	step_end

Movement_JumpInPlaceUp: @ 81C4F4E
	jump_in_place_up
	step_end

Movement_JumpInPlaceLeft: @ 81C4F50
	jump_in_place_left
	step_end

Movement_JumpInPlaceRight: @ 81C4F52
	jump_in_place_right
	step_end
