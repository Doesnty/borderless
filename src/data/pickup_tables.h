
struct PickupItem
{
    u16 itemId;
    u8 chance;
};


static const struct PickupItem sPickupItems[] =
{
    { ITEM_SUPER_POTION, 25 },
    { ITEM_HYPER_POTION, 35 },
    { ITEM_MAX_POTION, 40 },
    { ITEM_FULL_RESTORE, 45 },
    { ITEM_GREAT_BALL, 60 },
    { ITEM_ULTRA_BALL, 70 },
    { ITEM_FULL_HEAL, 80 },
    { ITEM_REVIVE, 88 },
    { ITEM_MAX_REVIVE, 92 },
    { ITEM_RARE_CANDY, 95 },
    { ITEM_LEFTOVERS, 96 },
    { ITEM_PP_UP, 99 },
    { ITEM_PP_MAX, 250 },
};

// uses mon's level + total levels gained under player
// e.g. fresh lv 15 catch is 15, but a lv15 starter counts as 25
// breakpoints are 20 and 50
// novice: 20% oran, 5% sitrus, 60% status cure, 5% leppa, 10% figy
// vet: 25% sitrus, 30% status cure, 18% lum, 10% leppa, 10% figy, 7% pinch
// elite: 25% sitrus, 10% status cure, 5% chesto, 20% lum, 11% leppa, 15% figy, 14% pinch
static const struct PickupItem sPickupBerriesNovice[] =
{
    { ITEM_ORAN_BERRY, 20 },
    { ITEM_SITRUS_BERRY, 25 },
    { ITEM_CHERI_BERRY, 35 },
    { ITEM_PECHA_BERRY, 45 },
    { ITEM_CHESTO_BERRY, 55 },
    { ITEM_ASPEAR_BERRY, 65 },
    { ITEM_RAWST_BERRY, 75 },
    { ITEM_PERSIM_BERRY, 85 },
    { ITEM_LEPPA_BERRY, 90 },
    { ITEM_FIGY_BERRY, 92 },
    { ITEM_WIKI_BERRY, 94 },
    { ITEM_MAGO_BERRY, 96 },
    { ITEM_AGUAV_BERRY, 98 },
    { ITEM_IAPAPA_BERRY, 250 },
};

static const struct PickupItem sPickupBerriesVeteran[] =
{
    { ITEM_SITRUS_BERRY, 20 },
	{ ITEM_OCCA_BERRY, 25 },
    { ITEM_CHERI_BERRY, 30 },
    { ITEM_PECHA_BERRY, 35 },
    { ITEM_CHESTO_BERRY, 40 },
    { ITEM_ASPEAR_BERRY, 45 },
    { ITEM_RAWST_BERRY, 50 },
    { ITEM_PERSIM_BERRY, 55 },
    { ITEM_LUM_BERRY, 73 },
    { ITEM_LEPPA_BERRY, 83 },
    { ITEM_FIGY_BERRY, 85 },
    { ITEM_WIKI_BERRY, 87 },
    { ITEM_MAGO_BERRY, 89 },
    { ITEM_AGUAV_BERRY, 91 },
    { ITEM_IAPAPA_BERRY, 93 },
    { ITEM_LIECHI_BERRY, 94 },
    { ITEM_GANLON_BERRY, 95 },
    { ITEM_PETAYA_BERRY, 96 },
    { ITEM_APICOT_BERRY, 97 },
    { ITEM_SALAC_BERRY, 98 },
    { ITEM_LANSAT_BERRY, 99 },
    { ITEM_STARF_BERRY, 250 },
};

static const struct PickupItem sPickupBerriesElite[] =
{
    { ITEM_SITRUS_BERRY, 25 },
    { ITEM_OCCA_BERRY, 35 },
    { ITEM_CHESTO_BERRY, 40 },
    { ITEM_LUM_BERRY, 60 },
    { ITEM_LEPPA_BERRY, 71 },
    { ITEM_FIGY_BERRY, 74 },
    { ITEM_WIKI_BERRY, 77 },
    { ITEM_MAGO_BERRY, 80 },
    { ITEM_AGUAV_BERRY, 83 },
    { ITEM_IAPAPA_BERRY, 86 },
    { ITEM_LIECHI_BERRY, 88 },
    { ITEM_GANLON_BERRY, 90 },
    { ITEM_PETAYA_BERRY, 92 },
    { ITEM_APICOT_BERRY, 94 },
    { ITEM_SALAC_BERRY, 96 },
    { ITEM_LANSAT_BERRY, 98 },
    { ITEM_STARF_BERRY, 250 },
};

static const struct PickupItem sPickupItemsNothing[] = 
{
	{ ITEM_NONE, 250},
};

static const struct PickupItem sPickupItemsMushrooms[] = 
{
	{ ITEM_TINY_MUSHROOM, 80 },
	{ ITEM_BIG_MUSHROOM, 250 },
};

static const struct PickupItem sPickupItemsIceBall[] = 
{
	{ ITEM_ICE_BALL, 10 },
	{ ITEM_NONE, 250},
};

static const struct PickupItem sPickupItemsPechaBerry[] = 
{
	{ ITEM_PECHA_BERRY, 250 },
};

static const struct PickupItem sPickupItemsOldPlate[] = 
{
	{ ITEM_OLD_PLATE, 25 },
	{ ITEM_NONE, 250},
};

static const struct PickupItem sPickupItemsHopeMask[] = 
{
	{ ITEM_HOPE_MASK, 25 },
	{ ITEM_NONE, 250},
};

static const struct PickupItem sPickupItemsZenerCards[] = 
{
	{ ITEM_ZENER_CARDS, 25 },
	{ ITEM_NONE, 250},
};

static const struct PickupItem sPickupItemsJunk[] = 
{
	{ ITEM_RAWST_BERRY, 10 },
	{ ITEM_ASPEAR_BERRY, 20 },
	{ ITEM_ORAN_BERRY, 30 },
	{ ITEM_REPEL, 40 },
	{ ITEM_DIRE_HIT, 50 },
	{ ITEM_GUARD_SPEC, 60 },
	{ ITEM_PERSIM_BERRY, 70 },
	{ ITEM_DURIN_BERRY, 80 },
	{ ITEM_CLEANSE_TAG, 90 },
	{ ITEM_BLOOMERS, 250 },
};

static const struct PickupItem sPickupItemsBeverages[] = 
{
	{ ITEM_FRESH_WATER, 25 },
	{ ITEM_SODA_POP, 50 },
	{ ITEM_LEMONADE, 75 },
	{ ITEM_MOOMOO_MILK, 250 },
};

static const struct PickupItem sPickupItemsRegalia[] = 
{
	{ ITEM_KUSANAGI, 5 },
	{ ITEM_YATA_MIRROR, 10 },
	{ ITEM_NONE, 250 },
};

static const struct PickupItem sPickupItemsRareOrbs[] = 
{
	{ ITEM_LUXURY_BALL, 30 },
	{ ITEM_ULTRA_BALL, 50 },
	{ ITEM_PREMIER_BALL, 250 },
};

static const struct PickupItem sPickupItemsNuggets[] = 
{
	{ ITEM_NUGGET, 50 },
	{ ITEM_NONE, 250 },
};

static const struct PickupItem sPickupItemsRope[] = 
{
	{ ITEM_ESCAPE_ROPE, 25 },
	{ ITEM_NONE, 250 },
};

static const struct PickupItem sPickupItemsRareMedicine[] = 
{
	{ ITEM_FULL_HEAL, 50 },
	{ ITEM_FULL_RESTORE, 70 },
	{ ITEM_REVIVE, 90 },
	{ ITEM_MAX_REVIVE, 250 },
};

static const struct PickupItem * const sSpeciesPickupTables[] = 
{
    [TOUHOU_NONE] = sPickupItemsNothing,
    [TOUHOU_REIMU] = sPickupItemsNothing,
    [TOUHOU_MARISA] = sPickupItemsMushrooms,
    [TOUHOU_RUMIA] = sPickupItemsNothing,
    [TOUHOU_DAIYOUSEI] = sPickupItemsIceBall,
    [TOUHOU_CIRNO] = sPickupItemsIceBall,
    [TOUHOU_MEILING] = sPickupItemsNothing,
    [TOUHOU_KOAKUMA] = sPickupItemsNothing,
    [TOUHOU_PATCHOULI] = sPickupItemsNothing,
    [TOUHOU_SAKUYA] = sPickupItemsNothing,
    [TOUHOU_REMILIA] = sPickupItemsNothing,
    [TOUHOU_FLANDRE] = sPickupItemsNothing,
    [TOUHOU_LETTY] = sPickupItemsNothing,
    [TOUHOU_CHEN] = sPickupItemsNothing,
    [TOUHOU_ALICE] = sPickupItemsNothing,
    [TOUHOU_LILY_WHITE] = sPickupItemsNothing,
    [TOUHOU_LUNASA] = sPickupItemsNothing,
    [TOUHOU_MERLIN] = sPickupItemsNothing,
    [TOUHOU_LYRICA] = sPickupItemsNothing,
    [TOUHOU_YOUMU] = sPickupItemsNothing,
    [TOUHOU_YUYUKO] = sPickupItemsNothing,
    [TOUHOU_RAN] = sPickupItemsNothing,
    [TOUHOU_YUKARI] = sPickupItemsNothing,
    [TOUHOU_SUIKA] = sPickupItemsNothing,
    [TOUHOU_WRIGGLE] = sPickupItemsNothing,
    [TOUHOU_MYSTIA] = sPickupItemsNothing,
    [TOUHOU_KEINE] = sPickupItemsRegalia,
    [TOUHOU_TEWI] = sPickupItemsNothing,
    [TOUHOU_REISEN] = sPickupItemsNothing,
    [TOUHOU_EIRIN] = sPickupItemsRareMedicine,
    [TOUHOU_KAGUYA] = sPickupItemsNothing,
    [TOUHOU_MOKOU] = sPickupItemsNothing,
    [TOUHOU_AYA] = sPickupItemsNothing,
    [TOUHOU_MEDICINE] = sPickupItemsNothing,
    [TOUHOU_YUUKA] = sPickupItemsNothing,
    [TOUHOU_KOMACHI] = sPickupItemsNothing,
    [TOUHOU_EIKI] = sPickupItemsNothing,
    [TOUHOU_AKYUU] = sPickupItemsNothing,
    [TOUHOU_SHIZUHA] = sPickupItemsNothing,
    [TOUHOU_MINORIKO] = sPickupItemsNothing,
    [TOUHOU_AKI_SISTERS] = sPickupItemsNothing,
    [TOUHOU_HINA] = sPickupItemsNothing,
    [TOUHOU_NITORI] = sPickupItemsNothing,
    [TOUHOU_MOMIJI] = sPickupItemsNothing,
    [TOUHOU_SANAE] = sPickupItemsNothing,
    [TOUHOU_KANAKO] = sPickupItemsNothing,
    [TOUHOU_SUWAKO] = sPickupItemsNothing,
    [TOUHOU_REISEN_II] = sPickupItemsNothing,
    [TOUHOU_TOYOHIME] = sPickupItemsPechaBerry,
    [TOUHOU_YORIHIME] = sPickupItemsNothing,
    [TOUHOU_IKU] = sPickupItemsNothing,
    [TOUHOU_TENSHI] = sPickupItemsPechaBerry,
    [TOUHOU_KISUME] = sPickupItemsRope,
    [TOUHOU_YAMAME] = sPickupItemsNothing,
    [TOUHOU_PARSEE] = sPickupItemsNothing,
    [TOUHOU_YUUGI] = sPickupItemsNothing,
    [TOUHOU_SATORI] = sPickupItemsNothing,
    [TOUHOU_RIN] = sPickupItemsNothing,
    [TOUHOU_ZFAIRY] = sPickupItemsNothing,
    [TOUHOU_UTSUHO] = sPickupItemsNothing,
    [TOUHOU_KOISHI] = sPickupItemsNothing,
    [TOUHOU_NAZRIN] = sPickupItemsNothing,
    [TOUHOU_KOGASA] = sPickupItemsNothing,
    [TOUHOU_ICHIRIN] = sPickupItemsNothing,
    [TOUHOU_MURASA] = sPickupItemsNothing,
    [TOUHOU_SHOU] = sPickupItemsNothing,
    [TOUHOU_BYAKUREN] = sPickupItemsNothing,
    [TOUHOU_NUE] = sPickupItemsNothing,
    [TOUHOU_TENSOKU] = sPickupItemsNothing,
    [TOUHOU_DOLL] = sPickupItemsNothing,
    [TOUHOU_NAMAZU] = sPickupItemsNothing,
    [TOUHOU_HATATE] = sPickupItemsNothing,
    [TOUHOU_SUNNY] = sPickupItemsMushrooms,
    [TOUHOU_LUNA] = sPickupItemsMushrooms,
    [TOUHOU_STAR] = sPickupItemsMushrooms,
    [TOUHOU_RINNOSUKE] = sPickupItemsNothing,
    [TOUHOU_TOKIKO] = sPickupItemsNothing,
    [TOUHOU_KYOUKO] = sPickupItemsNothing,
    [TOUHOU_YOSHIKA] = sPickupItemsNothing,
    [TOUHOU_SEIGA] = sPickupItemsNothing,
    [TOUHOU_TOJIKO] = sPickupItemsNothing,
    [TOUHOU_FUTO] = sPickupItemsOldPlate,
    [TOUHOU_MIKO] = sPickupItemsNothing,
    [TOUHOU_MAMIZOU] = sPickupItemsNothing,
    [TOUHOU_KOSUZU] = sPickupItemsNothing,
    [TOUHOU_JINYOU] = sPickupItemsNothing,
    [TOUHOU_KOKORO] = sPickupItemsHopeMask,
    [TOUHOU_WAKASAGIHIME] = sPickupItemsNothing,
    [TOUHOU_SEKIBANKI] = sPickupItemsNothing,
    [TOUHOU_KAGEROU] = sPickupItemsNothing,
    [TOUHOU_BENBEN] = sPickupItemsNothing,
    [TOUHOU_YATSUHASHI] = sPickupItemsNothing,
    [TOUHOU_SEIJA] = sPickupItemsNothing,
    [TOUHOU_SHINMYOUMARU] = sPickupItemsNothing,
    [TOUHOU_RAIKO] = sPickupItemsNothing,
    [TOUHOU_KASEN] = sPickupItemsNothing,
    [TOUHOU_SUMIREKO] = sPickupItemsZenerCards,
    [TOUHOU_SEIRAN] = sPickupItemsNothing,
    [TOUHOU_RINGO] = sPickupItemsNothing,
    [TOUHOU_DOREMY] = sPickupItemsNothing,
    [TOUHOU_SAGUME] = sPickupItemsNothing,
    [TOUHOU_CLOWNPIECE] = sPickupItemsNothing,
    [TOUHOU_JUNKO] = sPickupItemsNothing,
    [TOUHOU_HECATIA] = sPickupItemsNothing,
    [TOUHOU_JOON] = sPickupItemsNothing,
    [TOUHOU_SHION] = sPickupItemsJunk,
    [TOUHOU_ETERNITY] = sPickupItemsNothing,
    [TOUHOU_NEMUNO] = sPickupItemsNothing,
    [TOUHOU_AUNN] = sPickupItemsNothing,
    [TOUHOU_NARUMI] = sPickupItemsNothing,
    [TOUHOU_MAI_AND_SATONO] = sPickupItemsNothing,
    [TOUHOU_OKINA] = sPickupItemsNothing,
    [TOUHOU_EIKA] = sPickupItemsNothing,
    [TOUHOU_URUMI] = sPickupItemsNothing, // no
    [TOUHOU_KUTAKA] = sPickupItemsNothing,
    [TOUHOU_YACHIE] = sPickupItemsNothing,
    [TOUHOU_MAYUMI] = sPickupItemsNothing,
    [TOUHOU_KEIKI] = sPickupItemsNothing,
    [TOUHOU_SAKI] = sPickupItemsNothing,
    [TOUHOU_YUUMA] = sPickupItemsNothing,
    [TOUHOU_MIKE] = sPickupItemsNuggets,
    [TOUHOU_TAKANE] = sPickupItemsNothing,
    [TOUHOU_SANNYO] = sPickupItemsNothing,
    [TOUHOU_MISUMARU] = sPickupItemsRareOrbs,
    [TOUHOU_TSUKASA] = sPickupItemsNothing,
    [TOUHOU_MEGUMU] = sPickupItemsNothing,
    [TOUHOU_CHIMATA] = sPickupItemsNothing,
    [TOUHOU_MOMOYO] = sPickupItemsNothing,
    [TOUHOU_MIYOI] = sPickupItemsBeverages,
    [TOUHOU_MIZUCHI] = sPickupItemsNothing,
    [TOUHOU_BITEN] = sPickupItemsNothing,
    [TOUHOU_ENOKO] = sPickupItemsNothing,
    [TOUHOU_CHIYARI] = sPickupItemsNothing,
    [TOUHOU_HISAMI] = sPickupItemsNothing,
    [TOUHOU_ZANMU] = sPickupItemsNothing,
    [TOUHOU_SHINGYOKU] = sPickupItemsNothing,
    [TOUHOU_YUUGENMAGAN] = sPickupItemsNothing,
    [TOUHOU_MIMA] = sPickupItemsNothing,
    [TOUHOU_ELIS] = sPickupItemsNothing,
    [TOUHOU_KIKURI] = sPickupItemsNothing,
    [TOUHOU_KONNGARA] = sPickupItemsNothing,
    [TOUHOU_SARIEL] = sPickupItemsNothing,
    [TOUHOU_GENJI] = sPickupItemsNothing,
    [TOUHOU_RIKA] = sPickupItemsNothing,
    [TOUHOU_MEIRA] = sPickupItemsNothing,
    [TOUHOU_MAGIC_STONES] = sPickupItemsNothing,
    [TOUHOU_ELLEN] = sPickupItemsNothing,
    [TOUHOU_KOTOHIME] = sPickupItemsNothing,
    [TOUHOU_KANA] = sPickupItemsNothing,
    [TOUHOU_RIKAKO] = sPickupItemsNothing,
    [TOUHOU_CHIYURI] = sPickupItemsNothing,
    [TOUHOU_YUMEMI] = sPickupItemsNothing,
    [TOUHOU_RUUKOTO] = sPickupItemsNothing,
    [TOUHOU_MIMICHAN] = sPickupItemsNothing,
    [TOUHOU_ORANGE] = sPickupItemsNothing,
    [TOUHOU_KURUMI] = sPickupItemsNothing,
    [TOUHOU_ELLY] = sPickupItemsNothing,
    [TOUHOU_MUGETSU] = sPickupItemsNothing,
    [TOUHOU_GENGETSU] = sPickupItemsNothing,
    [TOUHOU_SARA] = sPickupItemsNothing,
    [TOUHOU_LOUISE] = sPickupItemsNothing,
    [TOUHOU_YUKI] = sPickupItemsNothing,
    [TOUHOU_MAI] = sPickupItemsNothing,
    [TOUHOU_YUMEKO] = sPickupItemsNothing,
    [TOUHOU_SHINKI] = sPickupItemsNothing,
    [TOUHOU_SENDAI] = sPickupItemsNothing,
    [TOUHOU_TENMA] = sPickupItemsNothing,
    [TOUHOU_LAYLA] = sPickupItemsNothing,
    [TOUHOU_YOUKI] = sPickupItemsNothing,
    [TOUHOU_BIRDS] = sPickupItemsNothing,
    [TOUHOU_2HU] = sPickupItemsNothing,
    [TOUHOU_RENKO] = sPickupItemsNothing,
    [TOUHOU_MARIBEL] = sPickupItemsNothing,
};
