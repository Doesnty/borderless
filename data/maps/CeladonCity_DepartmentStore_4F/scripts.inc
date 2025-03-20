CeladonCity_DepartmentStore_4F_MapScripts:: @ 816BBEE
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man:: @ 816BBEF
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster:: @ 816BBF8
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign:: @ 816BC01
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk:: @ 816BC0A
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items:: @ 816BC30
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_POWER_SHARD
	.2byte ITEM_GUARD_SHARD
	.2byte ITEM_SWIFT_SHARD
	.2byte ITEM_TECH_SHARD
	.2byte ITEM_ASSIST_SHARD
	.2byte ITEM_SOLAR_SHARD
	.2byte ITEM_AUTUMN_LEAF
	.2byte ITEM_DUBIOUS_TOME
	.2byte ITEM_OLD_TEXTBOOK
	.2byte ITEM_IBUKI_GOURD
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_ZENER_CARDS
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk2:: @ 816BC0A
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items2
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items2:: @ 816BC30
	.2byte ITEM_BLOOMERS
	.2byte ITEM_MIKO_UNIFORM
	.2byte ITEM_WITCHS_ROBE
	.2byte ITEM_BLAZER
	.2byte ITEM_KIMONO
	.2byte ITEM_CHINA_DRESS
	.2byte ITEM_MISTRESS
	.2byte ITEM_BUNNY_SUIT
	.2byte ITEM_GYM_SWEATER
	.2byte ITEM_STEWARDESS
	.2byte ITEM_NURSE_OUTFIT
	.2byte ITEM_MAID_UNIFORM
	.2byte ITEM_SWIMSUIT
	.2byte ITEM_GOTHIC_DRESS
	.2byte ITEM_CAMOUFLAGE
	.2byte ITEM_NINJA_SUIT
	.2byte ITEM_THICK_FUR
	.2byte ITEM_BRIDAL_GOWN
	.2byte ITEM_NONE
	release
	end
