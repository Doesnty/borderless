const struct BattleMove gBattleMoves[MOVES_COUNT] =
{
    [MOVE_POUND] = 
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_KARATE_CHOP] = 
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_FEINT] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 30,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 2,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_COMET_PUNCH] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_MEGA_PUNCH] = 
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_PAY_DAY] = 
    {
        .effect = EFFECT_PAY_DAY,
        .power = 60,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FIRE_PUNCH] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_ICE_PUNCH] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_THUNDER_PUNCH] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_SCRATCH] = 
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_NIGHT_SLASH] = 
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_JUDGMENT] = 
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RAZOR_WIND] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_SWORDS_DANCE] = 
    {
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_CUT] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_GUST] = 
    {
        .effect = EFFECT_GUST,
        .power = 40,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WING_ATTACK] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WHIRLWIND] = 
    {
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = -6,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_FLY] = 
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BIND] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BRAVER] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_VINE_WHIP] = 
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_STOMP] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DOUBLE_KICK] = 
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MEGA_KICK] = 
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_JUMP_KICK] = 
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ROLLING_KICK] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 20,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SAND_ATTACK] = 
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_EARTH,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_HEADBUTT] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 70,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_KNIFE_THROW] = 
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MAGIC_KNIFE] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_REASON,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SCULPTURE] = 
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_TACKLE] = 
    {
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BODY_SLAM] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 85,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WRAP] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_TAKE_DOWN] = 
    {
        .effect = EFFECT_RECOIL,
        .power = 100,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THRASH] = 
    {
        .effect = EFFECT_THRASH,
        .power = 100,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DOUBLE_EDGE] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_TAIL_WHIP] = 
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_BEAST,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_POISON_STING] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 30,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SEAL_NEEDLE] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 40,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PIN_MISSILE] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LEER] = 
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_BITE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_GROWL] = 
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_ROAR] = 
    {
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_BEAST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = -6,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_SING] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 60,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_JAMMING] = 
    {
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_SONICBOOM] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_DISABLE] = 
    {
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_POISON_TEARS] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 40,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_EMBER] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FLAMETHROWER] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 90,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MIST] = 
    {
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_WATER_GUN] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HYDRO_PUMP] = 
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SURF] = 
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ICE_BEAM] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 90,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BLIZZARD] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 120,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PSYBEAM] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 60,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BUBBLEBEAM] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AURORA_BEAM] = 
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HYPER_BEAM] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_DARK,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PECK] = 
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FOUL_PLAY] = 
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SUBMISSION] = 
    {
        .effect = EFFECT_RECOIL,
        .power = 100,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SKANDAS_LEG] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_COUNTER] = 
    {
        .effect = EFFECT_COUNTER,
        .power = 1,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = -5,
        .target = MOVE_TARGET_DEPENDS,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SEISMIC_TOSS] = 
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_STRENGTH] = 
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ABSORB] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 25,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MEGA_DRAIN] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LEECH_SEED] = 
    {
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_GROWTH] = 
    {
        .effect = EFFECT_GROWTH,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_RAZOR_LEAF] = 
    {
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_SOLAR_BEAM] = 
    {
        .effect = EFFECT_SOLARBEAM,
        .power = 120,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_POISON_POWDER] = 
    {
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 75,
        .pp = 35,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_STUN_SPORE] = 
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 75,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_SLEEP_POWDER] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_PETAL_STORM] = 
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MESMERISM] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 40,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 25,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DARK_PULSE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FIRE_SPIN] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THUNDERSHOCK] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THUNDERBOLT] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THUNDER_WAVE] = 
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_THUNDER] = 
    {
        .effect = EFFECT_THUNDER,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ROCK_WRECKER] = 
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 120,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_EARTHQUAKE] = 
    {
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FISSURE] = 
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DIG] = 
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_TOXIC] = 
    {
        .effect = EFFECT_TOXIC,
        .power = 0,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_STATUS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_PSYSHOT] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 40,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MANA_BURST] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HYPNOSIS] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 60,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_ZEN_HEADBUTT] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_REASON,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AGILITY] = 
    {
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_QUICK_ATTACK] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RAGE] = 
    {
        .effect = EFFECT_RAGE,
        .power = 60,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_TELEPORT] = 
    {
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_NIGHT_SHADE] = 
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MIMIC] = 
    {
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_SCREECH] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_DOUBLE_TEAM] = 
    {
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_RECOVER] = 
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HARDEN] = 
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_MINIMIZE] = 
    {
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_SMOKESCREEN] = 
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_CONFUSE_RAY] = 
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_WITHDRAW] = 
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_DEFENSE_CURL] = 
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_BARRIER] = 
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_LIGHT_SCREEN] = 
    {
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HAZE] = 
    {
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_REFLECT] = 
    {
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_FOCUS_ENERGY] = 
    {
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_WORK_UP] = 
    {
        .effect = EFFECT_GROWTH,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_METRONOME] = 
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_DEPENDS,
        .flags = 0,
    },

    [MOVE_DEBT_SPIRAL] = 
    {
        .effect = EFFECT_PAY_DAY,
        .power = 100,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SELF_DESTRUCT] = 
    {
        .effect = EFFECT_EXPLOSION,
        .power = 300,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MIND_BOMB] = 
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LICK] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SMOG] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 65,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 40,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_GUNK_SHOT] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 120,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WOOD_HAMMER] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FIRE_BLAST] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WATERFALL] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MANA_SHIELD] = 
    {
        .effect = EFFECT_TRAP,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_SWIFT] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SKULL_BASH] = 
    {
        .effect = EFFECT_SKULL_BASH,
        .power = 120,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DANMAKU] = 
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_TOPSY_TURVY] = 
    {
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_AMNESIA] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_LUNA_DIAL] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 20,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 55,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SOFT_BOILED] = 
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HI_JUMP_KICK] = 
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 130,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DAUNT] = 
    {
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_DREAM_EATER] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_DARK,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_OMINOUS_WIND] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BARRAGE] = 
    {
        .effect = EFFECT_NEW,
        .power = 30,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LEECH_LIFE] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LOVELY_KISS] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_SKY_ATTACK] = 
    {
        .effect = EFFECT_SKY_ATTACK,
        .power = 140,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 80,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_TRANSFORM] = 
    {
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_BUBBLE] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DIZZY_PUNCH] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 75,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BURN_POWDER] = 
    {
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .moveClass = CLASS_STATUS,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_FLASH] = 
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 65,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PSYWAVE] = 
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SPLASH] = 
    {
        .effect = EFFECT_SPLASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_DISPERSE] = 
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_AQUA_JET] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_WATER,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_EXPLOSION] = 
    {
        .effect = EFFECT_EXPLOSION,
        .power = 400,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FURY_SWIPES] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SUCKER_PUNCH] = 
    {
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 80,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_REST] = 
    {
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_ROCK_SLIDE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_KILLING_BITE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 100,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHARPEN] = 
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_CONVERSION] = 
    {
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_TRI_ATTACK] = 
    {
        .effect = EFFECT_TRI_ATTACK,
        .power = 80,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_GIGA_IMPACT] = 
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 130,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SLASH] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_SUBSTITUTE] = 
    {
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_STRUGGLE] = 
    {
        .effect = EFFECT_RECOIL,
        .power = 50,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 1,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SKETCH] = 
    {
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_SHADOW_SNEAK] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THIEF] = 
    {
        .effect = EFFECT_THIEF,
        .power = 60,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SPIDER_WEB] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 50,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HEARTS_EYE] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
    },

    [MOVE_NIGHTMARE] = 
    {
        .effect = EFFECT_SLEEP_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FLAME_WHEEL] = 
    {
        .effect = EFFECT_THAW_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SNORE] = 
    {
        .effect = EFFECT_SNORE,
        .power = 80,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 50,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_CURSE] = 
    {
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_FLAIL] = 
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CONVERSION_2] = 
    {
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_AEROBLAST] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_COTTON_SPORE] = 
    {
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_REVERSAL] = 
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SPITE] = 
    {
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_POWDER_SNOW] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PROTECT] = 
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
    },

    [MOVE_MACH_PUNCH] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_SCARY_FACE] = 
    {
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_FEINT_ATTACK] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SWEET_KISS] = 
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_BELLY_DRUM] = 
    {
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_POISON_BOMB] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 95,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MUD_SLAP] = 
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 30,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BLACK_RIPPLE] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SPIKES] = 
    {
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_EARTH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .flags = FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_DISCHARGE] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FORESIGHT] = 
    {
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_DESTINY_BOND] = 
    {
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_PERISH_SONG] = 
    {
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_ICY_WIND] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DETECT] = 
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 4,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_HEAD_RUSH] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LOCK_ON] = 
    {
        .effect = EFFECT_ACCURACY_UP_2,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_OUTRAGE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 120,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SANDSTORM] = 
    {
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_EARTH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_GIGA_DRAIN] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ENDURE] = 
    {
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 4,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_SMILE] = 
    {
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_TREMORS] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FALSE_SWIPE] = 
    {
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SWAGGER] = 
    {
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_HOSPITALITY] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_SPARK] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FURY_CUTTER] = 
    {
        .effect = EFFECT_FURY_CUTTER,
        .power = 40,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_STEEL_WING] = 
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 75,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LURE_OF_DEATH] = 
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ATTRACT] = 
    {
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_SLEEP_TALK] = 
    {
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_DEPENDS,
        .flags = 0,
    },

    [MOVE_HEAL_BELL] = 
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_FINAL_GAMBIT] = 
    {
        .effect = EFFECT_NEW,
        .power = 1,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PRANK] = 
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FRUSTRATION] = 
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SAFEGUARD] = 
    {
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_PAIN_SPLIT] = 
    {
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_GHOST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_SACRED_FIRE] = 
    {
        .effect = EFFECT_THAW_HIT,
        .power = 100,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MAGNITUDE] = 
    {
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DYNAMIC_PUNCH] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_BRAVE_BIRD] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LAVA_PLUME] = 
    {
        .effect = EFFECT_THAW_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BATON_PASS] = 
    {
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_ENCORE] = 
    {
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_PURSUIT] = 
    {
        .effect = EFFECT_PURSUIT,
        .power = 50,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RAPID_SPIN] = 
    {
        .effect = EFFECT_RAPID_SPIN,
        .power = 40,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_NATURE_POWER] = 
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_STEEL_FIST] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_METAL_CLAW] = 
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 75,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_VITAL_THROW] = 
    {
        .effect = EFFECT_KNOCK_OFF,
        .power = 80,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = -1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ENERGY_LIGHT] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SYNTHESIS] = 
    {
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_LUNATIC] = 
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HIDDEN_POWER] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CROSS_CHOP] = 
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_SHOCK_SPIN] = 
    {
        .effect = EFFECT_RAPID_SPIN,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RAIN_DANCE] = 
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_SUNNY_DAY] = 
    {
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_CRUNCH] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MIRROR_COAT] = 
    {
        .effect = EFFECT_MIRROR_COAT,
        .power = 1,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = -5,
        .target = MOVE_TARGET_DEPENDS,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PSYCH_UP] = 
    {
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_EXTREME_SPEED] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 2,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ANCIENT_POWER] = 
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 120,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHADOW_BALL] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PSYCHO_CUT] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_REASON,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_ROCK_SMASH] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 50,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 50,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WHIRLPOOL] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DRAWN_LINE] = 
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_FAKE_OUT] = 
    {
        .effect = EFFECT_FAKE_OUT,
        .power = 40,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = 3,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PERFORMANCE] = 
    {
        .effect = EFFECT_UPROAR,
        .power = 100,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_RANDOM,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_NASTY_PLOT] = 
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_MIRROR_SHOT] = 
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AQUA_RING] = 
    {
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HEAT_WAVE] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HAIL] = 
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_TORMENT] = 
    {
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_LUCKY_CHANT] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_WILL_O_WISP] = 
    {
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .moveClass = CLASS_STATUS,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_MEMENTO] = 
    {
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FACADE] = 
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FOCUS_PUNCH] = 
    {
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = -3,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_SMELLING_SALT] = 
    {
        .effect = EFFECT_SMELLINGSALT,
        .power = 75,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_COPYCAT] = 
    {
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_DEPENDS,
        .flags = 0,
    },

    [MOVE_ROCK_BULLET] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CHARGE] = 
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_TAUNT] = 
    {
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_HELPING_HAND] = 
    {
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 5,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_TRICK] = 
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RECOLLECTION] = 
    {
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_WISH] = 
    {
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_ASSIST] = 
    {
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_DEPENDS,
        .flags = 0,
    },

    [MOVE_INGRAIN] = 
    {
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_SUPERPOWER] = 
    {
        .effect = EFFECT_SUPERPOWER,
        .power = 120,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MAGIC_COAT] = 
    {
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 4,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_RECYCLE] = 
    {
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_REVENGE] = 
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = -4,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BRICK_BREAK] = 
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_YAWN] = 
    {
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_KNOCK_OFF] = 
    {
        .effect = EFFECT_KNOCK_OFF,
        .power = 50,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ENDEAVOR] = 
    {
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ERUPTION] = 
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SKILL_SWAP] = 
    {
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_IMPRISON] = 
    {
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_REFRESH] = 
    {
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_SHADOW_DANCE] = 
    {
        .effect = EFFECT_RAMPAGE,
        .power = 120,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_RANDOM,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SNATCH] = 
    {
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 4,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_SECRET_POWER] = 
    {
        .effect = EFFECT_SECRET_POWER,
        .power = 70,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHADOW_FORCE] = 
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 140,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT,
    },

    [MOVE_FORCE_PALM] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 80,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CAMOUFLAGE] = 
    {
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_MANA_CHARGE] = 
    {
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_LUSTER_PURGE] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MIST_BALL] = 
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 120,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ROOST] = 
    {
        .effect = EFFECT_NEW,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_TEETER_DANCE] = 
    {
        .effect = EFFECT_TEETER_DANCE,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BLAZE_KICK] = 
    {
        .effect = EFFECT_BURN_HIT,
        .power = 90,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_EARTH_POWER] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ICE_BALL] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_ICE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_NEEDLE_ARM] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SLACK_OFF] = 
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HYPER_VOICE] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_CROSS_POISON] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 90,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_CRUSH_CLAW] = 
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 75,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FLARE_BLITZ] = 
    {
        .effect = EFFECT_NEW,
        .power = 120,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DAM_BREACH] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_METEOR_MASH] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_ASTONISH] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 50,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WEATHER_BALL] = 
    {
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AROMATHERAPY] = 
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_FAKE_TEARS] = 
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_AIR_SLASH] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_OVERHEAT] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHADOW_HIT] = 
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_ROCK_TOMB] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 50,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SILVER_WIND] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 120,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BINDING_VOICE] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_BEAST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_NATURE_SOUND] = 
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_TICKLE] = 
    {
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_DRACO_METEOR] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_ILLUSION,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AQUA_SHOWER] = 
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SIGNAL_BEAM] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 90,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHADOW_PUNCH] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_EXTRASENSORY] = 
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SOAR] = 
    {
        .effect = EFFECT_SKY_UPPERCUT,
        .power = 90,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SAND_TOMB] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_COLD_SNAP] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MUDDY_WATER] = 
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BULLET_SEED] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BLADE_FLASH] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ICE_SHARD] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_ICE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_IRON_DEFENSE] = 
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_BLOCK] = 
    {
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_HOWL] = 
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_BEAST,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_HEAT_CLAW] = 
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_LEAF_STORM] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BULK_UP] = 
    {
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_BOUNCE] = 
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_WIND,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MUD_SHOT] = 
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_EARTH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_POISON_JAB] = 
    {
        .effect = EFFECT_POISON_HIT,
        .power = 80,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_COVET] = 
    {
        .effect = EFFECT_THIEF,
        .power = 60,
        .type = TYPE_HEART,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_VOLT_TACKLE] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MAGICAL_LEAF] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NATURE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SPLASHBACK] = 
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_WATER,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = -4,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CALM_MIND] = 
    {
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_LEAF_BLADE] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_GALE_DANCE] = 
    {
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_ROCK_BLAST] = 
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SHOCK_WAVE] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_WATER_PULSE] = 
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_APOLLON] = 
    {
        .effect = EFFECT_FUTURE_SIGHT,
        .power = 120,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_PSYCHO_BOOST] = 
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DRAIN_PUNCH] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_PUNCHING,
    },

    [MOVE_AURA_SPHERE] = 
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FOCUS_BLAST] = 
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 75,
        .pp = 5,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HEART_BREAK] = 
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DECISION] = 
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_RAPID_FIRE] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HEAD_SMASH] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SEED_BOMB] = 
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FREEZE_DRY] = 
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 70,
        .type = TYPE_ICE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HONE_CLAWS] = 
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_QUIVER_DANCE] = 
    {
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_NATURE,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_SHELL_SMASH] = 
    {
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_WATER,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_CLOSE_COMBAT] = 
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_DARK_VOID] = 
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_DARK,
        .moveClass = CLASS_STATUS,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
    },

    [MOVE_TRICK_ROOM] = 
    {
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = -7,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_TAILWIND] = 
    {
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_WIND,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_U_TURN] = 
    {
        .effect = EFFECT_U_TURN,
        .power = 70,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_VOLT_SWITCH] = 
    {
        .effect = EFFECT_U_TURN,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PURIFY] = 
    {
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HORSEPOWER] = 
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HEALING_WISH] = 
    {
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_GALE] = 
    {
        .effect = EFFECT_QUICK_ATTACK,
        .power = 40,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 1,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ABYSS_NOVA] = 
    {
        .effect = EFFECT_EXPLOSION,
        .power = 600,
        .type = TYPE_FIRE,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MISHAGUJI] = 
    {
        .effect = EFFECT_MISHAGUJI,
        .power = 20,
        .type = TYPE_GHOST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_AEGIS_MERGE] = 
    {
        .effect = EFFECT_AEGIS_MERGE,
        .power = 0,
        .type = TYPE_FAITH,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_EXTERMINATE] = 
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FAITH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_OBLIVION_WING] = 
    {
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_WIND,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FIRE_FANG] = 
    {
        .effect = EFFECT_ELEMENTAL_FANG,
        .power = 80,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ICE_FANG] = 
    {
        .effect = EFFECT_ELEMENTAL_FANG,
        .power = 80,
        .type = TYPE_ICE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_THUNDER_FANG] = 
    {
        .effect = EFFECT_ELEMENTAL_FANG,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ACUPRESSURE] = 
    {
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_STEEL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_WILD_HUNT] = 
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_BEAST,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_MANASHOCK] = 
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_REASON,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_FLAME_CHARGE] = 
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_CHARGE_BEAM] = 
    {
        .effect = EFFECT_SPATK_UP_HIT,
        .power = 50,
        .type = TYPE_HEART,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 70,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_PSYCHO_SHIFT] = 
    {
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_REASON,
        .moveClass = CLASS_STATUS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BESTOW] = 
    {
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_HEX] = 
    {
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GHOST,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_POWER_WHIP] = 
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NATURE,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HAMMER_ARM] = 
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_FIGHTING,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_BOLT_STRIKE] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_ANCHOR_SHOT] = 
    {
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_STEEL,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_SUTRA] = 
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FAITH,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_BOTH,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND_MOVE,
    },

    [MOVE_PRISTINE_SHOT] = 
    {
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = 0,
    },

    [MOVE_DESTITUTION] = 
    {
        .effect = EFFECT_TRAP,
        .power = 60,
        .type = TYPE_MIASMA,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },

    [MOVE_EARTH_PRESS] = 
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_EARTH,
        .moveClass = CLASS_PHYSICAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
    },

    [MOVE_HAPPY_HOUR] = 
    {
        .effect = EFFECT_HAPPY_HOUR,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_HOLD_HANDS] = 
    {
        .effect = EFFECT_HAPPY_HOUR,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
    },

    [MOVE_BALL_LIGHTNING] = 
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .moveClass = CLASS_SPECIAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT,
    },

    [MOVE_MOOD_SWING] = 
    {
        .effect = EFFECT_MOOD_SWING,
        .power = 0,
        .type = TYPE_HEART,
        .moveClass = CLASS_STATUS,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_SNATCH_AFFECTED,
    },

    [MOVE_ME_FIRST] = 
    {
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .moveClass = CLASS_STATUS,
        .accuracy = 20,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED,
    },
};
