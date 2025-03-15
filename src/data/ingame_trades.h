static const struct InGameTrade sInGameTrades[] = {
    [INGAME_TRADE_MR_MIME] = 
    {
        .nickname = _("Cranky"),
        .species = SPECIES_CKANAKO,
		.level = 20,
        .ivs = {20, 20, 20, 31, 20, 20},
        .abilityNum = 0,
        .otId = 24501,
        .moves = {MOVE_NEEDLE_ARM, MOVE_SCARY_FACE, MOVE_DECISION, MOVE_SAND_TOMB},
        .personality = 0x456EC65D,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("Reyley"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_CETERNITY
    }, 
    [INGAME_TRADE_JYNX] = 
    {
        .nickname = _("Hina"),
        .species = SPECIES_CMURASA,
		.level = 13,
        .ivs = {20, 20, 31, 20, 20, 20},
        .abilityNum = 0,
        .otId = 64144,
        .moves = {MOVE_SPLASH, MOVE_AQUA_JET, MOVE_ASTONISH, MOVE_CONFUSE_RAY},
        .personality = 0x3B7390D7,
        .heldItem = 0,
        .mailNum = 255,
        .otName = _("Joetus"),
        .otGender = MALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_CNAZRIN
    }, 
    [INGAME_TRADE_NIDORAN] = 
    {
        .nickname = _("bird"),
        .species = SPECIES_CAYA,
		.level = 15,
        .ivs = {20, 20, 20, 20, 20, 31},
        .abilityNum = 0,
        .otId = 59359,
        .moves = {MOVE_GALE, MOVE_WHIRLWIND, MOVE_FORESIGHT, MOVE_SAND_ATTACK},
        .personality = 0xD551A8B5,
        .heldItem = 0,
        .mailNum = 255,
        .otName = _("Josh"),
        .otGender = MALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_CHATATE
    }, 
    [INGAME_TRADE_FARFETCHD] = 
    {
        .nickname = _("The Chef"),
        .species = SPECIES_CYOUMU,
		.level = 16,
        .ivs = {20, 31, 20, 20, 20, 20},
        .abilityNum = 0,
        .otId = 14630,
        .moves = {MOVE_IRON_DEFENSE, MOVE_SCRATCH, MOVE_DETECT, MOVE_FURY_CUTTER},
        .personality = 0x1F94662C,
        .heldItem = ITEM_FRESH_WATER,
        .mailNum = 255,
        .otName = _("Kalt"),
        .otGender = MALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_CREISEN_II
    }, 
    [INGAME_TRADE_NIDORINOA] = 
    {
        .nickname = _("Jimbo"),
        .species = SPECIES_CSHINGYOKU,
		.level = 17,
        .ivs = {31, 20, 20, 20, 20, 20},
        .abilityNum = 0,
        .otId = 8474,
        .moves = {MOVE_DECISION, MOVE_SUBSTITUTE, MOVE_BLOCK, MOVE_BLACK_RIPPLE},
        .personality = 0x328F221D,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("Turner"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_CRUMIA
    }, 
    [INGAME_TRADE_LICKITUNG] = 
    {
        .nickname = _("Margatroid"),
        .species = SPECIES_CARISU,
		.level = 32,
        .ivs = {20, 20, 20, 20, 20, 31},
        .abilityNum = 0,
        .otId = 42660,
        .moves = {MOVE_DESTINY_BOND, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .personality = 0xF64591BF,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("Red"),
        .otGender = MALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_CALICE
    }, 
    [INGAME_TRADE_ELECTRODE] = 
    {
        .nickname = _("FAVE DOLL"),
        .species = SPECIES_YUMEKO,
		.level = 50,
        .ivs = {20, 31, 20, 20, 20, 20},
        .abilityNum = 0,
        .otId = 37606,
        .moves = {MOVE_SWORDS_DANCE, MOVE_METEOR_MASH, MOVE_BLADE_FLASH, MOVE_SUCKER_PUNCH},
        .personality = 0x4CAAFA30,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("Barudo"),
        .otGender = MALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_CSHINKI
    }, 
    [INGAME_TRADE_TANGELA] = 
    {
        .nickname = _("Prototype"),
        .species = SPECIES_RUUKOTO,
		.level = 50,
        .ivs = {20, 20, 20, 20, 31, 20},
        .abilityNum = 0,
        .otId = 5150,
        .moves = {MOVE_CHARGE_BEAM, MOVE_IRON_DEFENSE, MOVE_APOTHEOSIS, MOVE_JUDGMENT},
        .personality = 0x03F2A39A,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("Mille"),
        .otGender = FEMALE,
        .sheen = 0,
        .requestedSpecies = SPECIES_TTOYOHIME
    },
    [INGAME_TRADE_SEEL] = 
    {
        .nickname = _("Pallid Devil"),
        .species = SPECIES_GENGETSU,
		.level = 50,
        .ivs = {20, 20, 20, 20, 20, 31},
        .abilityNum = 0,
        .otId = 42069,
        .moves = {MOVE_ENDURE, MOVE_FLAIL, MOVE_ENCORE, MOVE_DOUBLE_TEAM},
        .personality = 0x9FA07A66,
        .heldItem = ITEM_BRIDAL_GOWN,
        .mailNum = 255,
        .otName = _("Eevee"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_REMILIA
    }
};

static const u16 sInGameTradeMailMessages[][10] = {
    {
        EC_WORD_THAT_S,
        EC_WORD_A,
        EC_WORD_HEALTHY,
        EC_POKEMON(JYNX),
        EC_WORD_EXCL,
        EC_WORD_BE,
        EC_WORD_KIND,
        EC_WORD_TO,
        EC_WORD_IT
    }
};
