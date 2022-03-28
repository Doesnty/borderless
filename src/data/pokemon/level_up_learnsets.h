#define LEVEL_UP_MOVE(lvl, move) ((lvl << 9) | move)
#define LEVEL_UP_END 0xFFFF

static const u16 sDummyLevelUpLearnset[] = {
    LEVEL_UP_MOVE(1, MOVE_TACKLE),
    LEVEL_UP_MOVE(4, MOVE_GROWL),
    LEVEL_UP_END
};
