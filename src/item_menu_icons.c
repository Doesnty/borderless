#include "global.h"
#include "gflib.h"
#include "decompress.h"
#include "graphics.h"
#include "item_menu_icons.h"
#include "constants/items.h"

static EWRAM_DATA u8 sItemMenuIconSpriteIds[12] = {0};
static EWRAM_DATA void * sItemIconTilesBuffer = NULL;
static EWRAM_DATA void * sItemIconTilesBufferPadded = NULL;

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite * sprite);
static void SpriteCB_ShakeBagSprite(struct Sprite * sprite);

static const struct OamData sOamData_BagOrSatchel = {
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_BagOrSatchel_OpenItemPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x40, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_BagOrSatchel_OpenKeyItemPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x80, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_BagOrSatchel_OpenPokeBallsPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0xc0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_BagOrSatchel[] = {
    sAnim_BagOrSatchel_OpenKeyItemPocket,
    sAnim_BagOrSatchel_OpenPokeBallsPocket,
    sAnim_BagOrSatchel_OpenItemPocket
};

static const union AffineAnimCmd sAffineAnim_Idle[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Wobble[] = {
    AFFINEANIMCMD_FRAME(0, 0, -2, 2),
    AFFINEANIMCMD_FRAME(0, 0,  2, 4),
    AFFINEANIMCMD_FRAME(0, 0, -2, 4),
    AFFINEANIMCMD_FRAME(0, 0,  2, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnimTable_BagOrSatchel[] = {
    sAffineAnim_Idle,
    sAffineAnim_Wobble
};

const struct CompressedSpriteSheet gSpriteSheet_Backpack = {
    gUnknown_8E8362C,
    0x2000,
    100
};

const struct CompressedSpriteSheet gSpriteSheet_Satchel = {
    gUnknown_8E83DBC,
    0x2000,
    100
};

const struct CompressedSpritePalette gSpritePalette_BagOrSatchel = {
    gUnknown_8E84560,
    100
};

static const struct SpriteTemplate sSpriteTemplate_BagOrSatchel = {
    100,
    100,
    &sOamData_BagOrSatchel,
    sAnimTable_BagOrSatchel,
    NULL,
    sAffineAnimTable_BagOrSatchel,
    SpriteCallbackDummy
};

static const struct OamData gUnknown_83D4214 = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 1,
    .paletteNum = 1
};

static const union AnimCmd gUnknown_83D421C[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_83D4224[] = {
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd gUnknown_83D422C[] = {
    ANIMCMD_FRAME(0, 0, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const gUnknown_83D4234[] = {
    gUnknown_83D421C,
    gUnknown_83D4224,
    gUnknown_83D422C
};

const struct CompressedSpriteSheet gBagSwapSpriteSheet = {
    gFile_graphics_interface_bag_swap_sheet,
    0x100,
    101
};

const struct CompressedSpritePalette gBagSwapSpritePalette = {
    gFile_graphics_interface_bag_swap_palette,
    101
};

static const struct SpriteTemplate gUnknown_83D4250 = {
    101,
    101,
    &gUnknown_83D4214,
    gUnknown_83D4234,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const struct OamData sOamData_ItemIcon = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 1,
    .paletteNum = 2
};

static const union AnimCmd sAnim_ItemIcon_0[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_ItemIcon[] = {
    sAnim_ItemIcon_0
};

static const struct SpriteTemplate sSpriteTemplate_ItemIcon = {
    102,
    102,
    &sOamData_ItemIcon,
    sAnimTable_ItemIcon,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const void *const sItemIconGfxPtrs[][2] = {
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_master_ball_sheet, gFile_graphics_items_icon_palettes_master_ball_palette},
    {gFile_graphics_items_icons_ultra_ball_sheet, gFile_graphics_items_icon_palettes_ultra_ball_palette},
    {gFile_graphics_items_icons_great_ball_sheet, gFile_graphics_items_icon_palettes_great_ball_palette},
    {gFile_graphics_items_icons_poke_ball_sheet, gFile_graphics_items_icon_palettes_poke_ball_palette},
    {gFile_graphics_items_icons_safari_ball_sheet, gFile_graphics_items_icon_palettes_safari_ball_palette},
    {gFile_graphics_items_icons_net_ball_sheet, gFile_graphics_items_icon_palettes_net_ball_palette},
    {gFile_graphics_items_icons_dive_ball_sheet, gFile_graphics_items_icon_palettes_dive_ball_palette},
    {gFile_graphics_items_icons_nest_ball_sheet, gFile_graphics_items_icon_palettes_nest_ball_palette},
    {gFile_graphics_items_icons_repeat_ball_sheet, gFile_graphics_items_icon_palettes_repeat_ball_palette},
    {gFile_graphics_items_icons_timer_ball_sheet, gFile_graphics_items_icon_palettes_timer_ball_palette},
    {gFile_graphics_items_icons_luxury_ball_sheet, gFile_graphics_items_icon_palettes_luxury_ball_palette},
    {gFile_graphics_items_icons_premier_ball_sheet, gFile_graphics_items_icon_palettes_premier_ball_palette},
    {gFile_graphics_items_icons_potion_sheet, gFile_graphics_items_icon_palettes_potion_palette},
    {gFile_graphics_items_icons_antidote_sheet, gFile_graphics_items_icon_palettes_antidote_palette},
    {gFile_graphics_items_icons_status_heal_sheet, gFile_graphics_items_icon_palettes_burn_heal_palette},
    {gFile_graphics_items_icons_status_heal_sheet, gFile_graphics_items_icon_palettes_ice_heal_palette},
    {gFile_graphics_items_icons_status_heal_sheet, gFile_graphics_items_icon_palettes_awakening_palette},
    {gFile_graphics_items_icons_status_heal_sheet, gFile_graphics_items_icon_palettes_paralyze_heal_palette},
    {gFile_graphics_items_icons_large_potion_sheet, gFile_graphics_items_icon_palettes_full_restore_palette},
    {gFile_graphics_items_icons_large_potion_sheet, gFile_graphics_items_icon_palettes_max_potion_palette},
    {gFile_graphics_items_icons_potion_sheet, gFile_graphics_items_icon_palettes_hyper_potion_palette},
    {gFile_graphics_items_icons_potion_sheet, gFile_graphics_items_icon_palettes_super_potion_palette},
    {gFile_graphics_items_icons_full_heal_sheet, gFile_graphics_items_icon_palettes_full_heal_palette},
    {gFile_graphics_items_icons_revive_sheet, gFile_graphics_items_icon_palettes_revive_palette},
    {gFile_graphics_items_icons_max_revive_sheet, gFile_graphics_items_icon_palettes_revive_palette},
    {gFile_graphics_items_icons_fresh_water_sheet, gFile_graphics_items_icon_palettes_fresh_water_palette},
    {gFile_graphics_items_icons_soda_pop_sheet, gFile_graphics_items_icon_palettes_soda_pop_palette},
    {gFile_graphics_items_icons_lemonade_sheet, gFile_graphics_items_icon_palettes_lemonade_palette},
    {gFile_graphics_items_icons_moomoo_milk_sheet, gFile_graphics_items_icon_palettes_moomoo_milk_palette},
    {gFile_graphics_items_icons_powder_sheet, gFile_graphics_items_icon_palettes_energy_powder_palette},
    {gFile_graphics_items_icons_energy_root_sheet, gFile_graphics_items_icon_palettes_energy_root_palette},
    {gFile_graphics_items_icons_powder_sheet, gFile_graphics_items_icon_palettes_heal_powder_palette},
    {gFile_graphics_items_icons_revival_herb_sheet, gFile_graphics_items_icon_palettes_revival_herb_palette},
    {gFile_graphics_items_icons_ether_sheet, gFile_graphics_items_icon_palettes_ether_palette},
    {gFile_graphics_items_icons_ether_sheet, gFile_graphics_items_icon_palettes_max_ether_palette},
    {gFile_graphics_items_icons_ether_sheet, gFile_graphics_items_icon_palettes_elixir_palette},
    {gFile_graphics_items_icons_ether_sheet, gFile_graphics_items_icon_palettes_max_elixir_palette},
    {gFile_graphics_items_icons_lava_cookie_sheet, gFile_graphics_items_icon_palettes_lava_cookie_and_letter_palette},
    {gFile_graphics_items_icons_flute_sheet, gFile_graphics_items_icon_palettes_blue_flute_palette},
    {gFile_graphics_items_icons_flute_sheet, gFile_graphics_items_icon_palettes_yellow_flute_palette},
    {gFile_graphics_items_icons_flute_sheet, gFile_graphics_items_icon_palettes_red_flute_palette},
    {gFile_graphics_items_icons_flute_sheet, gFile_graphics_items_icon_palettes_black_flute_palette},
    {gFile_graphics_items_icons_flute_sheet, gFile_graphics_items_icon_palettes_white_flute_palette},
    {gFile_graphics_items_icons_berry_juice_sheet, gFile_graphics_items_icon_palettes_berry_juice_palette},
    {gFile_graphics_items_icons_sacred_ash_sheet, gFile_graphics_items_icon_palettes_sacred_ash_palette},
    {gFile_graphics_items_icons_powder_sheet, gFile_graphics_items_icon_palettes_shoal_salt_palette},
    {gFile_graphics_items_icons_shoal_shell_sheet, gFile_graphics_items_icon_palettes_shell_palette},
    {gFile_graphics_items_icons_shard_sheet, gFile_graphics_items_icon_palettes_red_shard_palette},
    {gFile_graphics_items_icons_shard_sheet, gFile_graphics_items_icon_palettes_blue_shard_palette},
    {gFile_graphics_items_icons_shard_sheet, gFile_graphics_items_icon_palettes_yellow_shard_palette},
    {gFile_graphics_items_icons_shard_sheet, gFile_graphics_items_icon_palettes_green_shard_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_hp_up_sheet, gFile_graphics_items_icon_palettes_hp_up_palette},
    {gFile_graphics_items_icons_vitamin_sheet, gFile_graphics_items_icon_palettes_protein_palette},
    {gFile_graphics_items_icons_vitamin_sheet, gFile_graphics_items_icon_palettes_iron_palette},
    {gFile_graphics_items_icons_vitamin_sheet, gFile_graphics_items_icon_palettes_carbos_palette},
    {gFile_graphics_items_icons_vitamin_sheet, gFile_graphics_items_icon_palettes_calcium_palette},
    {gFile_graphics_items_icons_rare_candy_sheet, gFile_graphics_items_icon_palettes_rare_candy_palette},
    {gFile_graphics_items_icons_pp_up_sheet, gFile_graphics_items_icon_palettes_pp_up_palette},
    {gFile_graphics_items_icons_vitamin_sheet, gFile_graphics_items_icon_palettes_zinc_palette},
    {gFile_graphics_items_icons_pp_max_sheet, gFile_graphics_items_icon_palettes_pp_max_palette},
    {gFile_graphics_items_icons_rare_candy_sheet, gFile_graphics_items_icon_palettes_rare_candy_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_guard_spec_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_dire_hit_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_x_attack_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_x_defend_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_x_speed_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_x_accuracy_palette},
    {gFile_graphics_items_icons_battle_stat_item_sheet, gFile_graphics_items_icon_palettes_x_special_palette},
    {gFile_graphics_items_icons_poke_doll_sheet, gFile_graphics_items_icon_palettes_poke_doll_palette},
    {gFile_graphics_items_icons_fluffy_tail_sheet, gFile_graphics_items_icon_palettes_fluffy_tail_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_repel_sheet, gFile_graphics_items_icon_palettes_super_repel_palette},
    {gFile_graphics_items_icons_repel_sheet, gFile_graphics_items_icon_palettes_max_repel_palette},
    {gFile_graphics_items_icons_escape_rope_sheet, gFile_graphics_items_icon_palettes_escape_rope_palette},
    {gFile_graphics_items_icons_repel_sheet, gFile_graphics_items_icon_palettes_repel_palette},
    {gFile_graphics_items_icons_ability_capsule_sheet, gFile_graphics_items_icon_palettes_ability_capsule_palette},
    {gFile_graphics_items_icons_dream_capsule_sheet, gFile_graphics_items_icon_palettes_dream_capsule_palette},
    {gFile_graphics_items_icons_clear_mochi_sheet, gFile_graphics_items_icon_palettes_lucky_egg_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_solar_shard_sheet, gFile_graphics_items_icon_palettes_solar_shard_palette},
    {gFile_graphics_items_icons_power_shard_sheet, gFile_graphics_items_icon_palettes_power_shard_palette},
    {gFile_graphics_items_icons_defense_shard_sheet, gFile_graphics_items_icon_palettes_defense_shard_palette},
    {gFile_graphics_items_icons_swift_shard_sheet, gFile_graphics_items_icon_palettes_swift_shard_palette},
    {gFile_graphics_items_icons_tech_shard_sheet, gFile_graphics_items_icon_palettes_tech_shard_palette},
    {gFile_graphics_items_icons_support_shard_sheet, gFile_graphics_items_icon_palettes_support_shard_palette},
    {gFile_graphics_items_icons_autumn_leaf_sheet, gFile_graphics_items_icon_palettes_autumn_leaf_palette},
    {gFile_graphics_items_icons_dubious_tome_sheet, gFile_graphics_items_icon_palettes_dubious_tome_palette},
    {gFile_graphics_items_icons_old_textbook_sheet, gFile_graphics_items_icon_palettes_old_textbook_palette},
    {gFile_graphics_items_icons_ibuki_gourd_sheet, gFile_graphics_items_icon_palettes_ibuki_gourd_palette},
    {gFile_graphics_items_icons_tiny_mushroom_sheet, gFile_graphics_items_icon_palettes_mushroom_palette},
    {gFile_graphics_items_icons_big_mushroom_sheet, gFile_graphics_items_icon_palettes_mushroom_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_pearl_sheet, gFile_graphics_items_icon_palettes_pearl_palette},
    {gFile_graphics_items_icons_big_pearl_sheet, gFile_graphics_items_icon_palettes_pearl_palette},
    {gFile_graphics_items_icons_stardust_sheet, gFile_graphics_items_icon_palettes_star_palette},
    {gFile_graphics_items_icons_star_piece_sheet, gFile_graphics_items_icon_palettes_star_palette},
    {gFile_graphics_items_icons_nugget_sheet, gFile_graphics_items_icon_palettes_nugget_palette},
    {gFile_graphics_items_icons_heart_scale_sheet, gFile_graphics_items_icon_palettes_heart_scale_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_orange_mail_sheet, gFile_graphics_items_icon_palettes_orange_mail_palette},
    {gFile_graphics_items_icons_harbor_mail_sheet, gFile_graphics_items_icon_palettes_harbor_mail_palette},
    {gFile_graphics_items_icons_glitter_mail_sheet, gFile_graphics_items_icon_palettes_glitter_mail_palette},
    {gFile_graphics_items_icons_mech_mail_sheet, gFile_graphics_items_icon_palettes_mech_mail_palette},
    {gFile_graphics_items_icons_wood_mail_sheet, gFile_graphics_items_icon_palettes_wood_mail_palette},
    {gFile_graphics_items_icons_wave_mail_sheet, gFile_graphics_items_icon_palettes_wave_mail_palette},
    {gFile_graphics_items_icons_bead_mail_sheet, gFile_graphics_items_icon_palettes_bead_mail_palette},
    {gFile_graphics_items_icons_shadow_mail_sheet, gFile_graphics_items_icon_palettes_shadow_mail_palette},
    {gFile_graphics_items_icons_tropic_mail_sheet, gFile_graphics_items_icon_palettes_tropic_mail_palette},
    {gFile_graphics_items_icons_dream_mail_sheet, gFile_graphics_items_icon_palettes_dream_mail_palette},
    {gFile_graphics_items_icons_fab_mail_sheet, gFile_graphics_items_icon_palettes_fab_mail_palette},
    {gFile_graphics_items_icons_retro_mail_sheet, gFile_graphics_items_icon_palettes_retro_mail_palette},
    {gFile_graphics_items_icons_cheri_berry_sheet, gFile_graphics_items_icon_palettes_cheri_berry_palette},
    {gFile_graphics_items_icons_chesto_berry_sheet, gFile_graphics_items_icon_palettes_chesto_berry_palette},
    {gFile_graphics_items_icons_pecha_berry_sheet, gFile_graphics_items_icon_palettes_pecha_berry_palette},
    {gFile_graphics_items_icons_rawst_berry_sheet, gFile_graphics_items_icon_palettes_rawst_berry_palette},
    {gFile_graphics_items_icons_aspear_berry_sheet, gFile_graphics_items_icon_palettes_aspear_berry_palette},
    {gFile_graphics_items_icons_leppa_berry_sheet, gFile_graphics_items_icon_palettes_leppa_berry_palette},
    {gFile_graphics_items_icons_oran_berry_sheet, gFile_graphics_items_icon_palettes_oran_berry_palette},
    {gFile_graphics_items_icons_persim_berry_sheet, gFile_graphics_items_icon_palettes_persim_berry_palette},
    {gFile_graphics_items_icons_lum_berry_sheet, gFile_graphics_items_icon_palettes_lum_berry_palette},
    {gFile_graphics_items_icons_sitrus_berry_sheet, gFile_graphics_items_icon_palettes_sitrus_berry_palette},
    {gFile_graphics_items_icons_figy_berry_sheet, gFile_graphics_items_icon_palettes_figy_berry_palette},
    {gFile_graphics_items_icons_wiki_berry_sheet, gFile_graphics_items_icon_palettes_wiki_berry_palette},
    {gFile_graphics_items_icons_mago_berry_sheet, gFile_graphics_items_icon_palettes_mago_berry_palette},
    {gFile_graphics_items_icons_aguav_berry_sheet, gFile_graphics_items_icon_palettes_aguav_berry_palette},
    {gFile_graphics_items_icons_iapapa_berry_sheet, gFile_graphics_items_icon_palettes_iapapa_berry_palette},
    {gFile_graphics_items_icons_occa_berry_sheet, gFile_graphics_items_icon_palettes_occa_berry_palette},
    {gFile_graphics_items_icons_passho_berry_sheet, gFile_graphics_items_icon_palettes_passho_berry_palette},
    {gFile_graphics_items_icons_wacan_berry_sheet, gFile_graphics_items_icon_palettes_wacan_berry_palette},
    {gFile_graphics_items_icons_rindo_berry_sheet, gFile_graphics_items_icon_palettes_rindo_berry_palette},
    {gFile_graphics_items_icons_yache_berry_sheet, gFile_graphics_items_icon_palettes_yache_berry_palette},
    {gFile_graphics_items_icons_chople_berry_sheet, gFile_graphics_items_icon_palettes_chople_berry_palette},
    {gFile_graphics_items_icons_kebia_berry_sheet, gFile_graphics_items_icon_palettes_kebia_berry_palette},
    {gFile_graphics_items_icons_shuca_berry_sheet, gFile_graphics_items_icon_palettes_shuca_berry_palette},
    {gFile_graphics_items_icons_coba_berry_sheet, gFile_graphics_items_icon_palettes_coba_berry_palette},
    {gFile_graphics_items_icons_payapa_berry_sheet, gFile_graphics_items_icon_palettes_payapa_berry_palette},
    {gFile_graphics_items_icons_tanga_berry_sheet, gFile_graphics_items_icon_palettes_tanga_berry_palette},
    {gFile_graphics_items_icons_charti_berry_sheet, gFile_graphics_items_icon_palettes_charti_berry_palette},
    {gFile_graphics_items_icons_kasib_berry_sheet, gFile_graphics_items_icon_palettes_kasib_berry_palette},
    {gFile_graphics_items_icons_haban_berry_sheet, gFile_graphics_items_icon_palettes_haban_berry_palette},
    {gFile_graphics_items_icons_colbur_berry_sheet, gFile_graphics_items_icon_palettes_colbur_berry_palette},
    {gFile_graphics_items_icons_babiri_berry_sheet, gFile_graphics_items_icon_palettes_babiri_berry_palette},
    {gFile_graphics_items_icons_chilan_berry_sheet, gFile_graphics_items_icon_palettes_chilan_berry_palette},
    {gFile_graphics_items_icons_enigma_berry_sheet, gFile_graphics_items_icon_palettes_enigma_berry_palette},
    {gFile_graphics_items_icons_durin_berry_sheet, gFile_graphics_items_icon_palettes_durin_berry_palette},
    {gFile_graphics_items_icons_belue_berry_sheet, gFile_graphics_items_icon_palettes_belue_berry_palette},
    {gFile_graphics_items_icons_liechi_berry_sheet, gFile_graphics_items_icon_palettes_liechi_berry_palette},
    {gFile_graphics_items_icons_ganlon_berry_sheet, gFile_graphics_items_icon_palettes_ganlon_berry_palette},
    {gFile_graphics_items_icons_salac_berry_sheet, gFile_graphics_items_icon_palettes_salac_berry_palette},
    {gFile_graphics_items_icons_petaya_berry_sheet, gFile_graphics_items_icon_palettes_petaya_berry_palette},
    {gFile_graphics_items_icons_apicot_berry_sheet, gFile_graphics_items_icon_palettes_apicot_berry_palette},
    {gFile_graphics_items_icons_lansat_berry_sheet, gFile_graphics_items_icon_palettes_lansat_berry_palette},
    {gFile_graphics_items_icons_starf_berry_sheet, gFile_graphics_items_icon_palettes_starf_berry_palette},
    {gFile_graphics_items_icons_enigma_berry_sheet, gFile_graphics_items_icon_palettes_enigma_berry_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_bright_powder_sheet, gFile_graphics_items_icon_palettes_bright_powder_palette},
    {gFile_graphics_items_icons_in_battle_herb_sheet, gFile_graphics_items_icon_palettes_white_herb_palette},
    {gFile_graphics_items_icons_macho_brace_sheet, gFile_graphics_items_icon_palettes_macho_brace_palette},
    {gFile_graphics_items_icons_exp_share_sheet, gFile_graphics_items_icon_palettes_exp_share_palette},
    {gFile_graphics_items_icons_quick_claw_sheet, gFile_graphics_items_icon_palettes_quick_claw_palette},
    {gFile_graphics_items_icons_soothe_bell_sheet, gFile_graphics_items_icon_palettes_soothe_bell_palette},
    {gFile_graphics_items_icons_in_battle_herb_sheet, gFile_graphics_items_icon_palettes_mental_herb_palette},
    {gFile_graphics_items_icons_choice_band_sheet, gFile_graphics_items_icon_palettes_choice_band_palette},
    {gFile_graphics_items_icons_kings_rock_sheet, gFile_graphics_items_icon_palettes_kings_rock_palette},
    {gFile_graphics_items_icons_blazer_sheet, gFile_graphics_items_icon_palettes_blazer_palette},
    {gFile_graphics_items_icons_amulet_coin_sheet, gFile_graphics_items_icon_palettes_amulet_coin_palette},
    {gFile_graphics_items_icons_cleanse_tag_sheet, gFile_graphics_items_icon_palettes_cleanse_tag_palette},
    {gFile_graphics_items_icons_soul_dew_sheet, gFile_graphics_items_icon_palettes_soul_dew_palette},
    {gFile_graphics_items_icons_kusanagi_sheet, gFile_graphics_items_icon_palettes_kusanagi_palette},
    {gFile_graphics_items_icons_yata_mirror_sheet, gFile_graphics_items_icon_palettes_yata_mirror_palette},
    {gFile_graphics_items_icons_smoke_ball_sheet, gFile_graphics_items_icon_palettes_smoke_ball_palette},
    {gFile_graphics_items_icons_everstone_sheet, gFile_graphics_items_icon_palettes_everstone_palette},
    {gFile_graphics_items_icons_focus_band_sheet, gFile_graphics_items_icon_palettes_focus_band_palette},
    {gFile_graphics_items_icons_lucky_egg_sheet, gFile_graphics_items_icon_palettes_lucky_egg_palette},
    {gFile_graphics_items_icons_scope_lens_sheet, gFile_graphics_items_icon_palettes_scope_lens_palette},
    {gFile_graphics_items_icons_maid_uniform_sheet, gFile_graphics_items_icon_palettes_maid_uniform_palette},
    {gFile_graphics_items_icons_leftovers_sheet, gFile_graphics_items_icon_palettes_leftovers_palette},
    {gFile_graphics_items_icons_dragon_scale_sheet, gFile_graphics_items_icon_palettes_dragon_scale_palette},
    {gFile_graphics_items_icons_ice_ball_sheet, gFile_graphics_items_icon_palettes_ice_ball_palette},
    {gFile_graphics_items_icons_gym_sweater_sheet, gFile_graphics_items_icon_palettes_gym_sweater_palette},
    {gFile_graphics_items_icons_bunny_suit_sheet, gFile_graphics_items_icon_palettes_bunny_suit_palette},
    {gFile_graphics_items_icons_camouflage_sheet, gFile_graphics_items_icon_palettes_camouflage_palette},
    {gFile_graphics_items_icons_mistress_sheet, gFile_graphics_items_icon_palettes_mistress_palette},
    {gFile_graphics_items_icons_china_dress_sheet, gFile_graphics_items_icon_palettes_china_dress_palette},
    {gFile_graphics_items_icons_ninja_suit_sheet, gFile_graphics_items_icon_palettes_ninja_suit_palette},
    {gFile_graphics_items_icons_swimsuit_sheet, gFile_graphics_items_icon_palettes_swimsuit_palette},
    {gFile_graphics_items_icons_stewardess_sheet, gFile_graphics_items_icon_palettes_stewardess_palette},
    {gFile_graphics_items_icons_nurse_outfit_sheet, gFile_graphics_items_icon_palettes_nurse_outfit_palette},
    {gFile_graphics_items_icons_thick_fur_sheet, gFile_graphics_items_icon_palettes_thick_fur_palette},
    {gFile_graphics_items_icons_kimono_sheet, gFile_graphics_items_icon_palettes_kimono_palette},
    {gFile_graphics_items_icons_witchs_robe_sheet, gFile_graphics_items_icon_palettes_witchs_robe_palette},
    {gFile_graphics_items_icons_gothic_dress_sheet, gFile_graphics_items_icon_palettes_gothic_dress_palette},
    {gFile_graphics_items_icons_miko_uniform_sheet, gFile_graphics_items_icon_palettes_miko_uniform_palette},
    {gFile_graphics_items_icons_bridal_gown_sheet, gFile_graphics_items_icon_palettes_bridal_gown_palette},
    {gFile_graphics_items_icons_bloomers_sheet, gFile_graphics_items_icon_palettes_bloomers_palette},
    {gFile_graphics_items_icons_shell_bell_sheet, gFile_graphics_items_icon_palettes_shell_palette},
    {gFile_graphics_items_icons_sea_incense_sheet, gFile_graphics_items_icon_palettes_sea_incense_palette},
    {gFile_graphics_items_icons_lax_incense_sheet, gFile_graphics_items_icon_palettes_lax_incense_palette},
    {gFile_graphics_items_icons_lucky_punch_sheet, gFile_graphics_items_icon_palettes_lucky_punch_palette},
    {gFile_graphics_items_icons_metal_powder_sheet, gFile_graphics_items_icon_palettes_metal_powder_palette},
    {gFile_graphics_items_icons_black_belt_sheet, gFile_graphics_items_icon_palettes_black_type_enhancing_item_palette},
    {gFile_graphics_items_icons_stick_sheet, gFile_graphics_items_icon_palettes_stick_palette},
    {gFile_graphics_items_icons_stone_baby_sheet, gFile_graphics_items_icon_palettes_stone_baby_palette},
    {gFile_graphics_items_icons_moon_stone_sheet, gFile_graphics_items_icon_palettes_moon_stone_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_old_plate_sheet, gFile_graphics_items_icon_palettes_pearl_palette},
    {gFile_graphics_items_icons_scarlet_rock_sheet, gFile_graphics_items_icon_palettes_scarlet_rock_palette},
    {gFile_graphics_items_icons_roukanken_sheet, gFile_graphics_items_icon_palettes_roukanken_palette},
    {gFile_graphics_items_icons_wide_lens_sheet, gFile_graphics_items_icon_palettes_wide_lens_palette},
    {gFile_graphics_items_icons_light_clay_sheet, gFile_graphics_items_icon_palettes_light_clay_palette},
    {gFile_graphics_items_icons_toxic_orb_sheet, gFile_graphics_items_icon_palettes_toxic_orb_palette},
    {gFile_graphics_items_icons_flame_orb_sheet, gFile_graphics_items_icon_palettes_flame_orb_palette},
    {gFile_graphics_items_icons_hope_mask_sheet, gFile_graphics_items_icon_palettes_hope_mask_palette},
    {gFile_graphics_items_icons_retro_mail_sheet, gFile_graphics_items_icon_palettes_retro_mail_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_scarf_sheet, gFile_graphics_items_icon_palettes_red_scarf_palette},
    {gFile_graphics_items_icons_scarf_sheet, gFile_graphics_items_icon_palettes_blue_scarf_palette},
    {gFile_graphics_items_icons_scarf_sheet, gFile_graphics_items_icon_palettes_pink_scarf_palette},
    {gFile_graphics_items_icons_scarf_sheet, gFile_graphics_items_icon_palettes_green_scarf_palette},
    {gFile_graphics_items_icons_scarf_sheet, gFile_graphics_items_icon_palettes_yellow_scarf_palette},
    {gFile_graphics_items_icons_mach_bike_sheet, gFile_graphics_items_icon_palettes_mach_bike_palette},
    {gFile_graphics_items_icons_coin_case_sheet, gFile_graphics_items_icon_palettes_coin_case_palette},
    {gFile_graphics_items_icons_itemfinder_sheet, gFile_graphics_items_icon_palettes_itemfinder_palette},
    {gFile_graphics_items_icons_old_rod_sheet, gFile_graphics_items_icon_palettes_old_rod_palette},
    {gFile_graphics_items_icons_good_rod_sheet, gFile_graphics_items_icon_palettes_good_rod_palette},
    {gFile_graphics_items_icons_super_rod_sheet, gFile_graphics_items_icon_palettes_super_rod_palette},
    {gFile_graphics_items_icons_ss_ticket_sheet, gFile_graphics_items_icon_palettes_ss_ticket_palette},
    {gFile_graphics_items_icons_contest_pass_sheet, gFile_graphics_items_icon_palettes_contest_pass_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_wailmer_pail_sheet, gFile_graphics_items_icon_palettes_wailmer_pail_palette},
    {gFile_graphics_items_icons_devon_goods_sheet, gFile_graphics_items_icon_palettes_devon_goods_palette},
    {gFile_graphics_items_icons_soot_sack_sheet, gFile_graphics_items_icon_palettes_soot_sack_palette},
    {gFile_graphics_items_icons_basement_key_sheet, gFile_graphics_items_icon_palettes_old_key_palette},
    {gFile_graphics_items_icons_acro_bike_sheet, gFile_graphics_items_icon_palettes_acro_bike_palette},
    {gFile_graphics_items_icons_pokeblock_case_sheet, gFile_graphics_items_icon_palettes_pokeblock_case_palette},
    {gFile_graphics_items_icons_letter_sheet, gFile_graphics_items_icon_palettes_lava_cookie_and_letter_palette},
    {gFile_graphics_items_icons_eon_ticket_sheet, gFile_graphics_items_icon_palettes_eon_ticket_palette},
    {gFile_graphics_items_icons_orb_sheet, gFile_graphics_items_icon_palettes_red_orb_palette},
    {gFile_graphics_items_icons_orb_sheet, gFile_graphics_items_icon_palettes_blue_orb_palette},
    {gFile_graphics_items_icons_scanner_sheet, gFile_graphics_items_icon_palettes_scanner_palette},
    {gFile_graphics_items_icons_go_goggles_sheet, gFile_graphics_items_icon_palettes_go_goggles_palette},
    {gFile_graphics_items_icons_meteorite_sheet, gFile_graphics_items_icon_palettes_meteorite_palette},
    {gFile_graphics_items_icons_room1_key_sheet, gFile_graphics_items_icon_palettes_key_palette},
    {gFile_graphics_items_icons_room2_key_sheet, gFile_graphics_items_icon_palettes_key_palette},
    {gFile_graphics_items_icons_room4_key_sheet, gFile_graphics_items_icon_palettes_key_palette},
    {gFile_graphics_items_icons_room6_key_sheet, gFile_graphics_items_icon_palettes_key_palette},
    {gFile_graphics_items_icons_storage_key_sheet, gFile_graphics_items_icon_palettes_old_key_palette},
    {gFile_graphics_items_icons_root_fossil_sheet, gFile_graphics_items_icon_palettes_hoenn_fossil_palette},
    {gFile_graphics_items_icons_claw_fossil_sheet, gFile_graphics_items_icon_palettes_hoenn_fossil_palette},
    {gFile_graphics_items_icons_devon_scope_sheet, gFile_graphics_items_icon_palettes_devon_scope_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette}, // focus punch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dark_tm_hm_palette}, // frustration
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_water_tm_hm_palette}, // water pulse
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_faith_tm_hm_palette}, // calm mind
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_rock_tm_hm_palette}, // roar
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_poison_tm_hm_palette}, // toxic
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_flying_tm_hm_palette}, // razor wind
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ghost_tm_hm_palette}, // curse
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_faith_tm_hm_palette}, // decision
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_poison_tm_hm_palette}, // poison jab
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fire_tm_hm_palette}, // sunny day
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dark_tm_hm_palette}, // taunt
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ice_tm_hm_palette}, // ice beam
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ice_tm_hm_palette}, // blizzard
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_steel_tm_hm_palette}, // sonicboom
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // light screen
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // detect
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_water_tm_hm_palette}, // rain dance
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_grass_tm_hm_palette}, // giga drain
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_faith_tm_hm_palette}, // safeguard
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_heart_tm_hm_palette}, // signal beam
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_grass_tm_hm_palette}, // solarbeam
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_steel_tm_hm_palette}, // steel fist
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // thunderbolt
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // thunder
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ground_tm_hm_palette}, // earthquake
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // mega punch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ground_tm_hm_palette}, // dig
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // mana burst
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ghost_tm_hm_palette}, // shadow ball
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette}, // brick break
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_heart_tm_hm_palette}, // psych up
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // reflect
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette}, // focus blast
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fire_tm_hm_palette}, // flamethrower
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_poison_tm_hm_palette}, // poison bomb
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // psycho cut
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fire_tm_hm_palette}, // fire blast
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ground_tm_hm_palette}, // rock tomb
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // thunder wave
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fire_tm_hm_palette}, // will-o-wisp
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // facade
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dragon_tm_hm_palette}, // secret power
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // rest
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_heart_tm_hm_palette}, // attract
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dark_tm_hm_palette}, // thief
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_steel_tm_hm_palette}, // steel wing
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // sleep talk
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dark_tm_hm_palette}, // snatch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_heart_tm_hm_palette}, // mind bomb
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fire_tm_hm_palette}, // fire punch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ice_tm_hm_palette}, // ice punch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // thunder punch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // u-turn
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // volt switch
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_faith_tm_hm_palette}, // extrasensory
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_grass_tm_hm_palette}, // energy light
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dragon_tm_hm_palette}, // hidden power
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ghost_tm_hm_palette}, // shadow force
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette}, // endure
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette}, // counter
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // mirror coat
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // trick
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ice_tm_hm_palette}, // icy wind
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // substitute
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_flying_tm_hm_palette}, // tailwind
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_psychic_tm_hm_palette}, // trick room
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ground_tm_hm_palette}, // spikes
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dragon_tm_hm_palette}, // metronome
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_flying_tm_hm_palette}, // flight
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ground_tm_hm_palette}, // sandstorm
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_ice_tm_hm_palette}, // hail
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_electric_tm_hm_palette}, // shock wave
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_grass_tm_hm_palette}, // magical leaf
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_rock_tm_hm_palette}, // heat claw
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_dark_tm_hm_palette}, // dark pulse
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // danmaku
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // double-edge
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_grass_tm_hm_palette}, // seed bomb
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // mega kick
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette}, // cut
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_flying_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_water_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_normal_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_fighting_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_water_tm_hm_palette},
    {gFile_graphics_items_icons_tm_sheet, gFile_graphics_items_icon_palettes_water_tm_hm_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_question_mark_sheet, gFile_graphics_items_icon_palettes_question_mark_palette},
    {gFile_graphics_items_icons_oaks_parcel_sheet, gFile_graphics_items_icon_palettes_oaks_parcel_palette},
    {gFile_graphics_items_icons_poke_flute_sheet, gFile_graphics_items_icon_palettes_poke_flute_palette},
    {gFile_graphics_items_icons_secret_key_sheet, gFile_graphics_items_icon_palettes_secret_key_palette},
    {gFile_graphics_items_icons_bike_voucher_sheet, gFile_graphics_items_icon_palettes_bike_voucher_palette},
    {gFile_graphics_items_icons_gold_teeth_sheet, gFile_graphics_items_icon_palettes_gold_teeth_palette},
    {gFile_graphics_items_icons_old_amber_sheet, gFile_graphics_items_icon_palettes_old_amber_palette},
    {gFile_graphics_items_icons_card_key_sheet, gFile_graphics_items_icon_palettes_card_key_palette},
    {gFile_graphics_items_icons_lift_key_sheet, gFile_graphics_items_icon_palettes_key_palette},
    {gFile_graphics_items_icons_helix_fossil_sheet, gFile_graphics_items_icon_palettes_kanto_fossil_palette},
    {gFile_graphics_items_icons_dome_fossil_sheet, gFile_graphics_items_icon_palettes_kanto_fossil_palette},
    {gFile_graphics_items_icons_silph_scope_sheet, gFile_graphics_items_icon_palettes_silph_scope_palette},
    {gFile_graphics_items_icons_bicycle_sheet, gFile_graphics_items_icon_palettes_bicycle_palette},
    {gFile_graphics_items_icons_town_map_sheet, gFile_graphics_items_icon_palettes_town_map_palette},
    {gFile_graphics_items_icons_vs_seeker_sheet, gFile_graphics_items_icon_palettes_vs_seeker_palette},
    {gFile_graphics_items_icons_fame_checker_sheet, gFile_graphics_items_icon_palettes_fame_checker_palette},
    {gFile_graphics_items_icons_tm_case_sheet, gFile_graphics_items_icon_palettes_tm_case_palette},
    {gFile_graphics_items_icons_berry_pouch_sheet, gFile_graphics_items_icon_palettes_berry_pouch_palette},
    {gFile_graphics_items_icons_teachy_tv_sheet, gFile_graphics_items_icon_palettes_teachy_tv_palette},
    {gFile_graphics_items_icons_tri_pass_sheet, gFile_graphics_items_icon_palettes_tri_pass_palette},
    {gFile_graphics_items_icons_rainbow_pass_sheet, gFile_graphics_items_icon_palettes_rainbow_pass_palette},
    {gFile_graphics_items_icons_tea_sheet, gFile_graphics_items_icon_palettes_tea_palette},
    {gFile_graphics_items_icons_mystic_ticket_sheet, gFile_graphics_items_icon_palettes_mystic_ticket_palette},
    {gFile_graphics_items_icons_aurora_ticket_sheet, gFile_graphics_items_icon_palettes_aurora_ticket_palette},
    {gFile_graphics_items_icons_powder_jar_sheet, gFile_graphics_items_icon_palettes_powder_jar_palette},
    {gFile_graphics_items_icons_gem_sheet, gFile_graphics_items_icon_palettes_ruby_palette},
    {gFile_graphics_items_icons_gem_sheet, gFile_graphics_items_icon_palettes_sapphire_palette},
    {gFile_graphics_items_icons_return_to_field_arrow_sheet, gFile_graphics_items_icon_palettes_return_to_field_arrow_palette}
};

void ResetItemMenuIconState(void)
{
    u16 i;

    for (i = 0; i < NELEMS(sItemMenuIconSpriteIds); i++)
        sItemMenuIconSpriteIds[i] = 0xFF;
}

void CreateBagOrSatchelSprite(u8 animNum)
{
    sItemMenuIconSpriteIds[0] = CreateSprite(&sSpriteTemplate_BagOrSatchel, 40, 68, 0);
    SetBagVisualPocketId(animNum);
}

void SetBagVisualPocketId(u8 animNum)
{
    struct Sprite * sprite = &gSprites[sItemMenuIconSpriteIds[0]];
    sprite->y2 = -5;
    sprite->callback = SpriteCB_BagVisualSwitchingPockets;
    StartSpriteAnim(sprite, animNum);
}

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite * sprite)
{
    if (sprite->y2 != 0)
        sprite->y2++;
    else
        sprite->callback = SpriteCallbackDummy;
}

void ShakeBagSprite(void)
{
    struct Sprite * sprite = &gSprites[sItemMenuIconSpriteIds[0]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = SpriteCB_ShakeBagSprite;
    }
}

static void SpriteCB_ShakeBagSprite(struct Sprite * sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, 0);
        sprite->callback = SpriteCallbackDummy;
    }
}

void ItemMenuIcons_CreateInsertIndicatorBarHidden(void)
{
    u8 i;
    u8 * ptr = &sItemMenuIconSpriteIds[1];

    for (i = 0; i < 9; i++)
    {
        ptr[i] = CreateSprite(&gUnknown_83D4250, i * 16 + 0x60, 7, 0);
        switch (i)
        {
        case 0:
            break;
        case 8:
            StartSpriteAnim(&gSprites[ptr[i]], 2);
            break;
        default:
            StartSpriteAnim(&gSprites[ptr[i]], 1);
            break;
        }
        gSprites[ptr[i]].invisible = TRUE;
    }
}

void ItemMenuIcons_ToggleInsertIndicatorBarVisibility(bool8 invisible)
{
    u8 i;
    u8 * ptr = &sItemMenuIconSpriteIds[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].invisible = invisible;
    }
}

void ItemMenuIcons_MoveInsertIndicatorBar(s16 x, u16 y)
{
    u8 i;
    u8 * ptr = &sItemMenuIconSpriteIds[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].x2 = x;
        gSprites[ptr[i]].y = y + 7;
    }
}

static bool8 TryAllocItemIconTilesBuffers(void)
{
    void ** ptr1, ** ptr2;

    ptr1 = &sItemIconTilesBuffer;
    *ptr1 = Alloc(0x120);
    if (*ptr1 == NULL)
        return FALSE;
    ptr2 = &sItemIconTilesBufferPadded;
    *ptr2 = AllocZeroed(0x200);
    if (*ptr2 == NULL)
    {
        Free(*ptr1);
        return FALSE;
    }
    return TRUE;
}

void CopyItemIconPicTo4x4Buffer(const void * src, void * dest)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        CpuCopy16(src + 0x60 * i, dest + 0x80 * i, 0x60);
    }
}

u8 AddItemIconObject(u16 tilesTag, u16 paletteTag, u16 itemId)
{
    struct SpriteTemplate template;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 spriteId;

    if (!TryAllocItemIconTilesBuffers())
        return MAX_SPRITES;

    LZDecompressWram(GetItemIconGfxPtr(itemId, 0), sItemIconTilesBuffer);
    CopyItemIconPicTo4x4Buffer(sItemIconTilesBuffer, sItemIconTilesBufferPadded);
    spriteSheet.data = sItemIconTilesBufferPadded;
    spriteSheet.size = 0x200;
    spriteSheet.tag = tilesTag;
    LoadSpriteSheet(&spriteSheet);

    spritePalette.data = GetItemIconGfxPtr(itemId, 1);
    spritePalette.tag = paletteTag;
    LoadCompressedSpritePalette(&spritePalette);

    CpuCopy16(&sSpriteTemplate_ItemIcon, &template, sizeof(struct SpriteTemplate));
    template.tileTag = tilesTag;
    template.paletteTag = paletteTag;
    spriteId = CreateSprite(&template, 0, 0, 0);

    Free(sItemIconTilesBuffer);
    Free(sItemIconTilesBufferPadded);
    return spriteId;
}

u8 AddItemIconObjectWithCustomObjectTemplate(const struct SpriteTemplate * origTemplate, u16 tilesTag, u16 paletteTag, u16 itemId)
{
    struct SpriteTemplate template;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 spriteId;

    if (!TryAllocItemIconTilesBuffers())
        return MAX_SPRITES;

    LZDecompressWram(GetItemIconGfxPtr(itemId, 0), sItemIconTilesBuffer);
    CopyItemIconPicTo4x4Buffer(sItemIconTilesBuffer, sItemIconTilesBufferPadded);
    spriteSheet.data = sItemIconTilesBufferPadded;
    spriteSheet.size = 0x200;
    spriteSheet.tag = tilesTag;
    LoadSpriteSheet(&spriteSheet);

    spritePalette.data = GetItemIconGfxPtr(itemId, 1);
    spritePalette.tag = paletteTag;
    LoadCompressedSpritePalette(&spritePalette);

    CpuCopy16(origTemplate, &template, sizeof(struct SpriteTemplate));
    template.tileTag = tilesTag;
    template.paletteTag = paletteTag;
    spriteId = CreateSprite(&template, 0, 0, 0);

    Free(sItemIconTilesBuffer);
    Free(sItemIconTilesBufferPadded);
    return spriteId;
}

void CreateItemMenuIcon(u16 itemId, u8 idx)
{
    u8 * ptr = &sItemMenuIconSpriteIds[10];
    u8 spriteId;

    if (ptr[idx] == 0xFF)
    {
        FreeSpriteTilesByTag(102 + idx);
        FreeSpritePaletteByTag(102 + idx);
        spriteId = AddItemIconObject(102 + idx, 102 + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            ptr[idx] = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 140;
        }
    }
}

void DestroyItemMenuIcon(u8 idx)
{
    u8 * ptr = &sItemMenuIconSpriteIds[10];

    if (ptr[idx] != 0xFF)
    {
        DestroySpriteAndFreeResources(&gSprites[ptr[idx]]);
        ptr[idx] = 0xFF;
    }
}

const void * GetItemIconGfxPtr(u16 itemId, u8 attrId)
{
    if (itemId > ITEM_N_A)
        itemId = ITEM_NONE;
    return sItemIconGfxPtrs[itemId][attrId];
}

void sub_80989A0(u16 itemId, u8 idx)
{
    u8 * ptr = &sItemMenuIconSpriteIds[10];
    u8 spriteId;

    if (ptr[idx] == 0xFF)
    {
        FreeSpriteTilesByTag(102 + idx);
        FreeSpritePaletteByTag(102 + idx);
        spriteId = AddItemIconObject(102 + idx, 102 + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            ptr[idx] = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 147;
        }
    }
}
