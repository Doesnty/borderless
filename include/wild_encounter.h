#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "global.h"

#define LAND_WILD_COUNT     12
#define WATER_WILD_COUNT    5
#define ROCK_WILD_COUNT     5
#define FISH_WILD_COUNT     10

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    u8 altX;
    u8 altY;
    u8 altX2;
    u8 altY2;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *altLandMonsInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u32 currMetatileAttrs, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
void DisableWildEncounters(bool8 state);
u8 GetUnownLetterByPersonalityLoByte(u32 personality);
bool8 SweetScentWildEncounter(void);
void SeedWildEncounterRng(u16 randVal);
void ResetEncounterRateModifiers(void);
bool8 TryStandardWildEncounter(u32 currMetatileAttrs);

#endif // GUARD_WILD_ENCOUNTER_H
