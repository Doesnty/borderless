#define EGG_MOVES_SPECIES_OFFSET 20000
#define EGG_MOVES_TERMINATOR 0xFFFF
#define egg_moves(species, moves...) (SPECIES_##species + EGG_MOVES_SPECIES_OFFSET), moves

const u16 gEggMoves[] = {
    egg_moves(CREIMU,
              MOVE_LIGHT_SCREEN,
              MOVE_SKULL_BASH,
              MOVE_SAFEGUARD,
              MOVE_CHARM,
              MOVE_PETAL_STORM,
              MOVE_MAGICAL_LEAF,
              MOVE_NATURE_SOUND,
              MOVE_CURSE),

    egg_moves(CMARISA,
              MOVE_BELLY_DRUM,
              MOVE_ANCIENT_POWER,
              MOVE_ROCK_SLIDE,
              MOVE_BITE,
              MOVE_OUTRAGE,
              MOVE_FRUSTRATION,
              MOVE_SWORDS_DANCE,
              MOVE_GALE_DANCE),

    EGG_MOVES_TERMINATOR
};
