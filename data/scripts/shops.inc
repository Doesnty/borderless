EventScript_ScaledShop::
	specialvar VAR_0x8004, CountBadges
	switch VAR_0x8004
	case 0, NoBadge_Shop
	case 1, OneBadge_Shop
	case 2, TwoBadge_Shop
	case 3, ThreeBadge_Shop
	case 4, FourBadge_Shop
	case 5, FiveBadge_Shop
	case 6, SixBadge_Shop
	case 7, SevenBadge_Shop
	case 8, EightBadge_Shop
	goto EightBadge_Shop

NoBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart NoBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

OneBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart OneBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

TwoBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart TwoBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

ThreeBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart ThreeBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

FourBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart FourBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

FiveBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart FiveBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

SixBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart SixBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

SevenBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart SevenBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

EightBadge_Shop:
	message Text_MayIHelpYou
	waitmessage
	pokemart EightBadge_ShopInventory
	msgbox Text_PleaseComeAgain
	release
	end

NoBadge_ShopInventory:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE

@ adds more status heals, field items
OneBadge_ShopInventory:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

 @ adds super potions, ice heal
TwoBadge_ShopInventory:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_POTION
	.2byte ITEM_NONE

 @ adds great ball, soda pop, full heal, super repel
ThreeBadge_ShopInventory:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_SODA_POP
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

 @ adds hyper potion, lemonade
FourBadge_ShopInventory:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_LEMONADE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

 @ adds ultra ball, max repel
FiveBadge_ShopInventory:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_LEMONADE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

 @ adds moomoo milk, revive(!)
SixBadge_ShopInventory:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

 @ adds max potion
SevenBadge_ShopInventory:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MAX_POTION
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

 @ adds full restore
EightBadge_ShopInventory:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
