#ifndef GUARD_POKEDEX_SCREEN_H
#define GUARD_POKEDEX_SCREEN_H

#define DEX_CATEGORY_GRASSLAND      0
#define DEX_CATEGORY_FOREST         1
#define DEX_CATEGORY_WATERS_EDGE    2
#define DEX_CATEGORY_SEA            3
#define DEX_CATEGORY_CAVE           4
#define DEX_CATEGORY_MOUNTAIN       5
#define DEX_CATEGORY_ROUGH_TERRAIN  6
#define DEX_CATEGORY_URBAN          7
#define DEX_CATEGORY_RARE           8
#define DEX_CATEGORY_LOLK           9
#define DEX_CATEGORY_HSIFS          10
#define DEX_CATEGORY_WBAWC          11
#define DEX_CATEGORY_UM             12
#define DEX_CATEGORY_UDOALG         13
#define DEX_CATEGORY_FIGHTERS       14
#define DEX_CATEGORY_WRITTEN_WORKS  15
#define DEX_CATEGORY_HRTP           16
#define DEX_CATEGORY_SOEW           17
#define DEX_CATEGORY_PODD           18
#define DEX_CATEGORY_LLS            19
#define DEX_CATEGORY_MS             20
#define DEX_CATEGORY_FANON          21
#define DEX_CATEGORY_SPECIAL        22
#define DEX_CATEGORY_COUNT          23

#define DEX_ORDER_NUMERICAL_KANTO    0
#define DEX_ORDER_ATOZ               1
#define DEX_ORDER_TYPE               2
#define DEX_ORDER_LIGHTEST           3
#define DEX_ORDER_SMALLEST           4
#define DEX_ORDER_NUMERICAL_NATIONAL 5

#define DEX_MODE(name) (DEX_CATEGORY_COUNT + DEX_ORDER_##name)

#include "pokedex.h"

extern const struct PokedexEntry gPokedexEntries[];

void CB2_OpenPokedexFromStartMenu(void);
s8 DexScreen_GetSetPokedexFlag(u16 nationalDexNo, u8 caseId, bool8 indexIsSpecies);

#endif //GUARD_POKEDEX_SCREEN_H
