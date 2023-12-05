@ Handled by data/scripts/day_care.inc

Route5_PokemonDayCare_MapScripts:: @ 816F8FF
	.byte 0


Route5_PokemonDayCare_EventScript_Clerk::
	lock
	faceplayer
	message Route5_PokemonDayCare_Text_WantMeToRaiseMon
	waitmessage
	pokemart Route5_PokemonDayCare_Items
	msgbox Text_PleaseComeAgain
	release
	end

    .align 2
Route5_PokemonDayCare_Items::
	.2byte ITEM_POWER_SHARD
	.2byte ITEM_GUARD_SHARD
	.2byte ITEM_SWIFT_SHARD
	.2byte ITEM_TECH_SHARD
	.2byte ITEM_ASSIST_SHARD
	.2byte ITEM_SOLAR_SHARD
    .2byte ITEM_NONE