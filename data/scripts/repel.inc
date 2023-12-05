EventScript_RepelWoreOff:: @ 81BFB65
    checkitem ITEM_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_AskIfUseAnotherRepel
    checkitem ITEM_SUPER_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_AskIfUseAnotherRepel
    checkitem ITEM_MAX_REPEL, 1
	compare VAR_RESULT, TRUE
    goto_if_eq EventScript_AskIfUseAnotherRepel
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

EventScript_AskIfUseAnotherRepel::
	msgbox Text_RepelWoreOffUseAnother, MSGBOX_YESNO
	compare VAR_RESULT, NO
    goto_if_eq EventScript_RepelEnd
    checkitem ITEM_REPEL, 1
    compare VAR_RESULT TRUE
    goto_if_eq EventScript_DoUseAnotherRepel
    checkitem ITEM_SUPER_REPEL, 1
    compare VAR_RESULT TRUE
    goto_if_eq EventScript_DoUseAnotherSuperRepel
    checkitem ITEM_MAX_REPEL, 1
    compare VAR_RESULT TRUE
    goto_if_eq EventScript_DoUseAnotherMaxRepel
    goto EventScript_RepelEnd

EventScript_DoUseAnotherRepel::
    playse SE_REPEL
    removeitem ITEM_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 100
    msgbox Text_Repel_UsedRepel MSGBOX_SIGN
    end

EventScript_DoUseAnotherSuperRepel::
    playse SE_REPEL
    removeitem ITEM_SUPER_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 200
    msgbox Text_Repel_UsedSuperRepel MSGBOX_SIGN
    end

EventScript_DoUseAnotherMaxRepel::
    playse SE_REPEL
    removeitem ITEM_MAX_REPEL, 1
    setvar VAR_REPEL_STEP_COUNT, 250
    msgbox Text_Repel_UsedMaxRepel MSGBOX_SIGN
    end

EventScript_RepelEnd::
    closemessage
    end

Text_RepelWoreOff:: @ 81BFB6E
	.string "Repel's effect wore off…$"

Text_RepelWoreOffUseAnother:: @ 81BFB6E
	.string "Repel's effect wore off…\n"
    .string "Use another?$"

Text_Repel_UsedRepel::
    .string "{PLAYER} used the\n"
    .string "Repel.$"

Text_Repel_UsedSuperRepel::
    .string "{PLAYER} used the\n"
    .string "Super Repel.$"

Text_Repel_UsedMaxRepel::
    .string "{PLAYER} used the\n"
    .string "Max Repel.$"

