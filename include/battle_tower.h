#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

#include "global.h"
#include "constants/battle_tower.h"

#define BATTLE_TOWER_EREADER_TRAINER_ID 200
#define BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID 100

struct BattleTowerTrainer
{
    u8 trainerClass;
    u8 name[8];
    u8 teamFlags;
    u8 greeting[120];
	u8 victoryText[120];
	u8 defeatText[120];
	const u16* monRoster;
};

struct BattleTowerPokemonTemplate
{
    u16 species;
    u16 heldItem;
    u8 teamFlags;
    u16 moves[4];
    u8 evSpread[6];
    u8 nature;
	u8 abilityFlags;
	u8 tier;
};

extern const u16 gBattleTowerBannedSpecies[];

void ClearEReaderTrainer(struct BattleTowerEReaderTrainer *);
void ValidateEReaderTrainer(void);
u8 GetBattleTowerTrainerFrontSpriteId(void);
u8 GetEreaderTrainerFrontSpriteId(void);
void CopyEReaderTrainerName5(u8 *dest);
void GetBattleTowerTrainerName(u8 *text);
u8 GetEreaderTrainerClassId(void);
u8 GetBattleTowerTrainerClassNameId(void);
void GetBattleTowerOpponentWinText(u8 *dest);
void GetBattleTowerOpponentLoseText(u8 *dest);

#endif //GUARD_BATTLE_TOWER_H
