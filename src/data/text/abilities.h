static const u8 sNoneDescription[] = _("No special ability.");
static const u8 sStenchDescription[] = _("Helps repel wild POKéMON.");
static const u8 sDrizzleDescription[] = _("Summons rain in battle.");
static const u8 sSpeedBoostDescription[] = _("Gradually boosts SPEED.");
static const u8 sBattleArmorDescription[] = _("Blocks critical hits.");
static const u8 sSturdyDescription[] = _("Negates 1-hit KO attacks.");
static const u8 sDampDescription[] = _("Prevents self-destruction.");
static const u8 sLimberDescription[] = _("Prevents paralysis.");
static const u8 sSandVeilDescription[] = _("Ups evasion in a sandstorm.");
static const u8 sStaticDescription[] = _("Paralyzes on contact.");
static const u8 sVoltAbsorbDescription[] = _("Turns electricity into HP.");
static const u8 sWaterAbsorbDescription[] = _("Changes water into HP.");
static const u8 sObliviousDescription[] = _("Prevents attraction.");
static const u8 sCloudNineDescription[] = _("Negates weather effects.");
static const u8 sCompoundEyesDescription[] = _("Raises accuracy.");
static const u8 sInsomniaDescription[] = _("Prevents sleep.");
static const u8 sColorChangeDescription[] = _("Changes type to foe's move.");
static const u8 sImmunityDescription[] = _("Prevents poisoning.");
static const u8 sFlashFireDescription[] = _("Powers up if hit by fire.");
static const u8 sShieldDustDescription[] = _("Prevents added effects.");
static const u8 sOwnTempoDescription[] = _("Prevents confusion.");
static const u8 sSuctionCupsDescription[] = _("Firmly anchors the body.");
static const u8 sIntimidateDescription[] = _("Lowers the foe's ATTACK.");
static const u8 sShadowTagDescription[] = _("Prevents the foe's escape.");
static const u8 sRoughSkinDescription[] = _("Hurts to touch.");
static const u8 sWonderGuardDescription[] = _("“Super effective” hits.");
static const u8 sLevitateDescription[] = _("Not hit by GROUND attacks.");
static const u8 sEffectSporeDescription[] = _("Leaves spores on contact.");
static const u8 sSynchronizeDescription[] = _("Passes on status problems.");
static const u8 sClearBodyDescription[] = _("Prevents ability reduction.");
static const u8 sNaturalCureDescription[] = _("Heals upon switching out.");
static const u8 sLightningRodDescription[] = _("Draws electrical moves.");
static const u8 sSereneGraceDescription[] = _("Promotes added effects.");
static const u8 sSwiftSwimDescription[] = _("Raises SPEED in rain.");
static const u8 sChlorophyllDescription[] = _("Raises SPEED in sunshine.");
static const u8 sIlluminateDescription[] = _("Encounter rate increases.");
static const u8 sTraceDescription[] = _("Copies special ability.");
static const u8 sHugePowerDescription[] = _("Raises ATTACK.");
static const u8 sPoisonPointDescription[] = _("Poisons foe on contact.");
static const u8 sInnerFocusDescription[] = _("Prevents flinching.");
static const u8 sMagmaArmorDescription[] = _("Prevents freezing.");
static const u8 sWaterVeilDescription[] = _("Prevents burns.");
static const u8 sMagnetPullDescription[] = _("Traps STEEL-type POKéMON.");
static const u8 sSoundproofDescription[] = _("Avoids sound-based moves.");
static const u8 sRainDishDescription[] = _("Slight HP recovery in rain.");
static const u8 sSandStreamDescription[] = _("Summons a sandstorm.");
static const u8 sPressureDescription[] = _("Raises foe's PP usage.");
static const u8 sThickFatDescription[] = _("Heat-and-cold protection.");
static const u8 sEarlyBirdDescription[] = _("Awakens quickly from sleep.");
static const u8 sFlameBodyDescription[] = _("Burns the foe on contact.");
static const u8 sRunAwayDescription[] = _("Makes escaping easier.");
static const u8 sKeenEyeDescription[] = _("Prevents loss of accuracy.");
static const u8 sHyperCutterDescription[] = _("Prevents ATTACK reduction.");
static const u8 sPickupDescription[] = _("May pick up items.");
static const u8 sTruantDescription[] = _("Moves only every two turns.");
static const u8 sHustleDescription[] = _("Trades accuracy for power.");
static const u8 sCuteCharmDescription[] = _("Infatuates on contact.");
static const u8 sPlusDescription[] = _("Powers up with MINUS.");
static const u8 sMinusDescription[] = _("Powers up with PLUS.");
static const u8 sForecastDescription[] = _("Changes with the weather.");
static const u8 sStickyHoldDescription[] = _("Prevents item theft.");
static const u8 sShedSkinDescription[] = _("Heals the body by shedding.");
static const u8 sGutsDescription[] = _("Ups ATTACK if suffering.");
static const u8 sMarvelScaleDescription[] = _("Ups DEFENSE if suffering.");
static const u8 sLiquidOozeDescription[] = _("Draining causes injury.");
static const u8 sOvergrowDescription[] = _("Ups GRASS moves in a pinch.");
static const u8 sBlazeDescription[] = _("Ups FIRE moves in a pinch.");
static const u8 sTorrentDescription[] = _("Ups WATER moves in a pinch.");
static const u8 sSwarmDescription[] = _("Ups BUG moves in a pinch.");
static const u8 sRockHeadDescription[] = _("Prevents recoil damage.");
static const u8 sDroughtDescription[] = _("Summons sunlight in battle.");
static const u8 sArenaTrapDescription[] = _("Prevents fleeing.");
static const u8 sVitalSpiritDescription[] = _("Prevents sleep.");
static const u8 sWhiteSmokeDescription[] = _("Prevents ability reduction.");
static const u8 sPurePowerDescription[] = _("Raises ATTACK.");
static const u8 sShellArmorDescription[] = _("Blocks critical hits.");
static const u8 sCacophonyDescription[] = _("Avoids sound-based moves.");
static const u8 sAirLockDescription[] = _("Negates weather effects.");
static const u8 sObsoleteDescription[] = _("Obsolete.");

const u8 *const gAbilityDescriptionPointers[ABILITIES_COUNT] =
{
    [ABILITY_NONE] = sNoneDescription,
    
    [ABILITY_DRIZZLE] = sDrizzleDescription,
    [ABILITY_SPEED_BOOST] = sSpeedBoostDescription,
    [ABILITY_GUARD_ARMOR] = sBattleArmorDescription,
    [ABILITY_STURDY] = sSturdyDescription,
    [ABILITY_DAMP] = sDampDescription,
    [ABILITY_LIMBER] = sLimberDescription,
    [ABILITY_SAND_VEIL] = sSandVeilDescription,
    [ABILITY_STATIC] = sStaticDescription,
    [ABILITY_VOLT_ABSORB] = sVoltAbsorbDescription,
    [ABILITY_WATER_ABSORB] = sWaterAbsorbDescription,
    [ABILITY_OBLIVIOUS] = sObliviousDescription,
    [ABILITY_CLOUD_NINE] = sCloudNineDescription,
    [ABILITY_FOCUS] = sCompoundEyesDescription,
    [ABILITY_INSOMNIA] = sInsomniaDescription,
    [ABILITY_MYSTERIOUS] = sColorChangeDescription,
    [ABILITY_IMMUNITY] = sImmunityDescription,
    [ABILITY_FLASH_FIRE] = sFlashFireDescription,
    [ABILITY_FLAWLESS] = sShieldDustDescription,
    [ABILITY_OWN_TEMPO] = sOwnTempoDescription,
    [ABILITY_GATE_KEEPER] = sSuctionCupsDescription,
    [ABILITY_INTIMIDATE] = sIntimidateDescription,
    [ABILITY_SHADOW_TAG] = sShadowTagDescription,
    [ABILITY_DOLL_WALL] = sRoughSkinDescription,
    [ABILITY_PLAY_GHOST] = sWonderGuardDescription,
    [ABILITY_LEVITATE] = sLevitateDescription,
    [ABILITY_INFECTIOUS] = sEffectSporeDescription,
    [ABILITY_SYNCHRONIZE] = sSynchronizeDescription,
    [ABILITY_HAKUREI_MIKO] = sClearBodyDescription,
    [ABILITY_NATURAL_CURE] = sNaturalCureDescription,
    [ABILITY_LIGHTNING_ROD] = sLightningRodDescription,
    [ABILITY_SERENE_GRACE] = sSereneGraceDescription,
    [ABILITY_SWIFT_SWIM] = sSwiftSwimDescription,
    [ABILITY_CHLOROPHYLL] = sChlorophyllDescription,
    [ABILITY_DIVA] = sIlluminateDescription,
    [ABILITY_TRACE] = sTraceDescription,
    [ABILITY_UNZAN] = sHugePowerDescription,
    [ABILITY_POISON_BODY] = sPoisonPointDescription,
    [ABILITY_INNER_FOCUS] = sInnerFocusDescription,
    [ABILITY_FIRE_VEIL] = sMagmaArmorDescription,
    [ABILITY_WATER_VEIL] = sWaterVeilDescription,
    
    [ABILITY_SOUNDPROOF] = sSoundproofDescription,
    [ABILITY_RAIN_DISH] = sRainDishDescription,
    [ABILITY_SAND_STREAM] = sSandStreamDescription,
    [ABILITY_PRESSURE] = sPressureDescription,
    [ABILITY_WALL_OF_ICE] = sThickFatDescription,
    [ABILITY_EARLY_BIRD] = sEarlyBirdDescription,
    [ABILITY_FLAME_BODY] = sFlameBodyDescription,
    [ABILITY_RUN_AWAY] = sRunAwayDescription,
    [ABILITY_KEEN_EYE] = sKeenEyeDescription,
    [ABILITY_HI_STRENGTH] = sHyperCutterDescription,
    [ABILITY_PICKUP] = sPickupDescription,
    [ABILITY_TRUANT] = sTruantDescription,
    [ABILITY_HUSTLE] = sHustleDescription,
    [ABILITY_CUTE_CHARM] = sCuteCharmDescription,
    
    
    
    [ABILITY_COLLECTOR] = sStickyHoldDescription,
    [ABILITY_MAINTENANCE] = sShedSkinDescription,
    [ABILITY_GUTS] = sGutsDescription,
    [ABILITY_SPRING_CHARM] = sMarvelScaleDescription,
    [ABILITY_STRANGE_MIST] = sLiquidOozeDescription,
    [ABILITY_INNER_POWER] = sOvergrowDescription,
    
    
    
    [ABILITY_ROCK_HEAD] = sRockHeadDescription,
    [ABILITY_DROUGHT] = sDroughtDescription,
    
    [ABILITY_VITAL_SPIRIT] = sVitalSpiritDescription,
    [ABILITY_MAGIC_BARRIER] = sWhiteSmokeDescription,
    [ABILITY_PURE_POWER] = sPurePowerDescription,
    
    
    [ABILITY_HISOUTEN] = sAirLockDescription,
};

const u8 gAbilityNames[ABILITIES_COUNT][ABILITY_NAME_LENGTH + 1] =
{
    [ABILITY_NONE] = _("-------"),
    
    [ABILITY_DRIZZLE] = _("Drizzle"),
    [ABILITY_SPEED_BOOST] = _("Speed Boost"),
    [ABILITY_GUARD_ARMOR] = _("Guard Armor"),
    [ABILITY_STURDY] = _("Sturdy"),
    [ABILITY_DAMP] = _("Damp"),
    [ABILITY_LIMBER] = _("Limber"),
    [ABILITY_SAND_VEIL] = _("Sand Veil"),
    [ABILITY_STATIC] = _("Static"),
    [ABILITY_VOLT_ABSORB] = _("Volt Absorb"),
    [ABILITY_WATER_ABSORB] = _("Water Absorb"),
    [ABILITY_OBLIVIOUS] = _("Oblivious"),
    [ABILITY_CLOUD_NINE] = _("Cloud Nine"),
    [ABILITY_FOCUS] = _("Focus"),
    [ABILITY_INSOMNIA] = _("Insomnia"),
    [ABILITY_MYSTERIOUS] = _("Mysterious"),
    [ABILITY_IMMUNITY] = _("Immunity"),
    [ABILITY_FLASH_FIRE] = _("Flash Fire"),
    [ABILITY_FLAWLESS] = _("Flawless"),
    [ABILITY_OWN_TEMPO] = _("Own Tempo"),
    [ABILITY_GATE_KEEPER] = _("Gate Keeper"),
    [ABILITY_INTIMIDATE] = _("Intimidate"),
    [ABILITY_SHADOW_TAG] = _("Shadow Tag"),
    [ABILITY_DOLL_WALL] = _("Doll Wall"),
    [ABILITY_PLAY_GHOST] = _("Play Ghost"),
    [ABILITY_LEVITATE] = _("Levitate"),
    [ABILITY_INFECTIOUS] = _("Infectious"),
    [ABILITY_SYNCHRONIZE] = _("Synchronize"),
    [ABILITY_HAKUREI_MIKO] = _("Hakurei Miko"),
    [ABILITY_NATURAL_CURE] = _("Natural Cure"),
    [ABILITY_LIGHTNING_ROD] = _("LightningRod"),
    [ABILITY_SERENE_GRACE] = _("Serene Grace"),
    [ABILITY_SWIFT_SWIM] = _("Swift Swim"),
    [ABILITY_CHLOROPHYLL] = _("Chlorophyll"),
    [ABILITY_DIVA] = _("Diva"),
    [ABILITY_TRACE] = _("Trace"),
    [ABILITY_UNZAN] = _("Unzan"),
    [ABILITY_POISON_BODY] = _("Poison Body"),
    [ABILITY_INNER_FOCUS] = _("Inner Focus"),
    [ABILITY_FIRE_VEIL] = _("Fire Veil"),
    [ABILITY_WATER_VEIL] = _("Water Veil"),
    
    [ABILITY_SOUNDPROOF] = _("Soundproof"),
    [ABILITY_RAIN_DISH] = _("Rain Dish"),
    [ABILITY_SAND_STREAM] = _("Sand Stream"),
    [ABILITY_PRESSURE] = _("Pressure"),
    [ABILITY_WALL_OF_ICE] = _("Wall of Ice"),
    [ABILITY_EARLY_BIRD] = _("Early Bird"),
    [ABILITY_FLAME_BODY] = _("Flame Body"),
    [ABILITY_RUN_AWAY] = _("Run Away"),
    [ABILITY_KEEN_EYE] = _("Keen Eye"),
    [ABILITY_HI_STRENGTH] = _("Hi Strength"),
    [ABILITY_PICKUP] = _("Pickup"),
    [ABILITY_TRUANT] = _("Truant"),
    [ABILITY_HUSTLE] = _("Hustle"),
    [ABILITY_CUTE_CHARM] = _("Cute Charm"),
    
    
    
    [ABILITY_COLLECTOR] = _("Collector"),
    [ABILITY_MAINTENANCE] = _("Maintenance"),
    [ABILITY_GUTS] = _("Guts"),
    [ABILITY_SPRING_CHARM] = _("Spring Charm"),
    [ABILITY_STRANGE_MIST] = _("Strange Mist"),
    [ABILITY_INNER_POWER] = _("Inner Power"),
    
    
    
    [ABILITY_ROCK_HEAD] = _("Rock Head"),
    [ABILITY_DROUGHT] = _("Drought"),
    
    [ABILITY_VITAL_SPIRIT] = _("Vital Spirit"),
    [ABILITY_MAGIC_BARRIER] = _("Barrier"),
    [ABILITY_PURE_POWER] = _("Pure Power"),
    
    
    [ABILITY_HISOUTEN] = _("Hisouten"),
};
