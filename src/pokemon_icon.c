#include "global.h"
#include "gflib.h"
#include "mail_data.h"
#include "pokemon_icon.h"
#include "graphics.h"

#define POKE_ICON_BASE_PAL_TAG 56000

struct MonIconSpriteTemplate
{
    const struct OamData * oam;
    const u8 *image;
    const union AnimCmd *const * anims;
    const union AffineAnimCmd *const * affineAnims;
    SpriteCallback callback;
    u16 paletteTag;
};

static u8 CreateMonIconSprite(const struct MonIconSpriteTemplate * template, s16 x, s16 y, u8 subpriority);
static void DestroyMonIconInternal(struct Sprite * sprite);

const u16 gMonIconPalettes[][16] = {
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_0.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_1.gbapal"),
    INCBIN_U16("graphics/pokemon/icon_palettes/icon_palette_2.gbapal")
};

const u8 *const gMonIconTable[] = {
    [SPECIES_NONE]        = gMonIcon_QuestionMark,
    [SPECIES_CREIMU] = gMonIcon_reimu_chibi,
    [SPECIES_REIMU] = gMonIcon_reimu_neutral,
    [SPECIES_AREIMU] = gMonIcon_reimu_attack,
    [SPECIES_DREIMU] = gMonIcon_reimu_defense,
    [SPECIES_CMARISA] = gMonIcon_marisa_chibi,
    [SPECIES_MARISA] = gMonIcon_marisa_neutral,
    [SPECIES_AMARISA] = gMonIcon_marisa_attack,
    [SPECIES_SMARISA] = gMonIcon_marisa_speed,
    [SPECIES_ADMARISA] = gMonIcon_marisa_advent,
    [SPECIES_LMARISA] = gMonIcon_marisa_lost,
    [SPECIES_CRUMIA] = gMonIcon_rumia_chibi,
    [SPECIES_RUMIA] = gMonIcon_rumia_neutral,
    [SPECIES_ARUMIA] = gMonIcon_rumia_attack,
    [SPECIES_SRUMIA] = gMonIcon_rumia_speed,
    [SPECIES_CDAIYOUSEI] = gMonIcon_daiyousei_chibi,
    [SPECIES_DAIYOUSEI] = gMonIcon_daiyousei_neutral,
    [SPECIES_ADAIYOUSEI] = gMonIcon_daiyousei_attack,
    [SPECIES_DDAIYOUSEI] = gMonIcon_daiyousei_defense,
    [SPECIES_CCIRNO] = gMonIcon_cirno_chibi,
    [SPECIES_CIRNO] = gMonIcon_cirno_neutral,
    [SPECIES_SCIRNO] = gMonIcon_cirno_speed,
    [SPECIES_TCIRNO] = gMonIcon_cirno_technical,
    [SPECIES_ADCIRNO] = gMonIcon_cirno_advent,
    [SPECIES_CMEILING] = gMonIcon_meiling_chibi,
    [SPECIES_MEILING] = gMonIcon_meiling_neutral,
    [SPECIES_DMEILING] = gMonIcon_meiling_defense,
    [SPECIES_SMEILING] = gMonIcon_meiling_speed,
    [SPECIES_ADMEILING] = gMonIcon_meiling_advent,
    [SPECIES_CKOAKUMA] = gMonIcon_koakuma_chibi,
    [SPECIES_KOAKUMA] = gMonIcon_koakuma_neutral,
    [SPECIES_HKOAKUMA] = gMonIcon_koakuma_helper,
    [SPECIES_CPATCHOULI] = gMonIcon_patchouli_chibi,
    [SPECIES_PATCHOULI] = gMonIcon_patchouli_neutral,
    [SPECIES_APATCHOULI] = gMonIcon_patchouli_attack,
    [SPECIES_DPATCHOULI] = gMonIcon_patchouli_defense,
    [SPECIES_CSAKUYA] = gMonIcon_sakuya_chibi,
    [SPECIES_SAKUYA] = gMonIcon_sakuya_neutral,
    [SPECIES_TSAKUYA] = gMonIcon_sakuya_technical,
    [SPECIES_HSAKUYA] = gMonIcon_sakuya_helper,
    [SPECIES_CREMILIA] = gMonIcon_remilia_chibi,
    [SPECIES_REMILIA] = gMonIcon_remilia_neutral,
    [SPECIES_AREMILIA] = gMonIcon_remilia_attack,
    [SPECIES_DREMILIA] = gMonIcon_remilia_defense,
    [SPECIES_CFLANDRE] = gMonIcon_flandre_chibi,
    [SPECIES_FLANDRE] = gMonIcon_flandre_neutral,
    [SPECIES_AFLANDRE] = gMonIcon_flandre_attack,
    [SPECIES_SFLANDRE] = gMonIcon_flandre_speed,
    [SPECIES_CLETTY] = gMonIcon_letty_chibi,
    [SPECIES_LETTY] = gMonIcon_letty_neutral,
    [SPECIES_DLETTY] = gMonIcon_letty_defense,
    [SPECIES_HLETTY] = gMonIcon_letty_helper,
    [SPECIES_ADLETTY] = gMonIcon_letty_advent,
    [SPECIES_CCHEN] = gMonIcon_chen_chibi,
    [SPECIES_CHEN] = gMonIcon_chen_neutral,
    [SPECIES_ACHEN] = gMonIcon_chen_attack,
    [SPECIES_TCHEN] = gMonIcon_chen_technical,
    [SPECIES_ADCHEN] = gMonIcon_chen_advent,
    [SPECIES_CALICE] = gMonIcon_alice_chibi,
    [SPECIES_ALICE] = gMonIcon_alice_neutral,
    [SPECIES_AALICE] = gMonIcon_alice_attack,
    [SPECIES_TALICE] = gMonIcon_alice_technical,
    [SPECIES_ADALICE] = gMonIcon_alice_advent,
    [SPECIES_DARK_ALICE] = gMonIcon_alice_dark,
    [SPECIES_CLILYWHITE] = gMonIcon_lilywhite_chibi,
    [SPECIES_LILYWHITE] = gMonIcon_lilywhite_neutral,
    [SPECIES_ALILYWHITE] = gMonIcon_lilywhite_attack,
    [SPECIES_HLILYWHITE] = gMonIcon_lilywhite_helper,
    [SPECIES_CLILYBLACK] = gMonIcon_lilyblack_chibi,
    [SPECIES_LILYBLACK] = gMonIcon_lilyblack_neutral,
    [SPECIES_ALILYBLACK] = gMonIcon_lilyblack_attack,
    [SPECIES_SLILYBLACK] = gMonIcon_lilyblack_speed,
    [SPECIES_CLUNASA] = gMonIcon_lunasa_chibi,
    [SPECIES_LUNASA] = gMonIcon_lunasa_neutral,
    [SPECIES_HLUNASA] = gMonIcon_lunasa_helper,
    [SPECIES_CMERLIN] = gMonIcon_merlin_chibi,
    [SPECIES_MERLIN] = gMonIcon_merlin_neutral,
    [SPECIES_HMERLIN] = gMonIcon_merlin_helper,
    [SPECIES_CLYRICA] = gMonIcon_lyrica_chibi,
    [SPECIES_LYRICA] = gMonIcon_lyrica_neutral,
    [SPECIES_HLYRICA] = gMonIcon_lyrica_helper,
    [SPECIES_CYOUMU] = gMonIcon_youmu_chibi,
    [SPECIES_YOUMU] = gMonIcon_youmu_neutral,
    [SPECIES_DYOUMU] = gMonIcon_youmu_defense,
    [SPECIES_SYOUMU] = gMonIcon_youmu_speed,
    [SPECIES_LYOUMU] = gMonIcon_youmu_lost,
    [SPECIES_CYUYUKO] = gMonIcon_yuyuko_chibi,
    [SPECIES_YUYUKO] = gMonIcon_yuyuko_neutral,
    [SPECIES_AYUYUKO] = gMonIcon_yuyuko_attack,
    [SPECIES_DYUYUKO] = gMonIcon_yuyuko_defense,
    [SPECIES_LYUYUKO] = gMonIcon_yuyuko_lost,
    [SPECIES_CRAN] = gMonIcon_ran_chibi,
    [SPECIES_RAN] = gMonIcon_ran_neutral,
    [SPECIES_ARAN] = gMonIcon_ran_attack,
    [SPECIES_HRAN] = gMonIcon_ran_helper,
    [SPECIES_ADRAN] = gMonIcon_ran_advent,
    [SPECIES_CYUKARI] = gMonIcon_yukari_chibi,
    [SPECIES_YUKARI] = gMonIcon_yukari_neutral,
    [SPECIES_DYUKARI] = gMonIcon_yukari_defense,
    [SPECIES_TYUKARI] = gMonIcon_yukari_technical,
    [SPECIES_ADYUKARI] = gMonIcon_yukari_advent,
    [SPECIES_CSUIKA] = gMonIcon_suika_chibi,
    [SPECIES_SUIKA] = gMonIcon_suika_neutral,
    [SPECIES_ASUIKA] = gMonIcon_suika_attack,
    [SPECIES_TSUIKA] = gMonIcon_suika_technical,
    [SPECIES_CWRIGGLE] = gMonIcon_wriggle_chibi,
    [SPECIES_WRIGGLE] = gMonIcon_wriggle_neutral,
    [SPECIES_DWRIGGLE] = gMonIcon_wriggle_defense,
    [SPECIES_SWRIGGLE] = gMonIcon_wriggle_speed,
    [SPECIES_CMYSTIA] = gMonIcon_mystia_chibi,
    [SPECIES_MYSTIA] = gMonIcon_mystia_neutral,
    [SPECIES_AMYSTIA] = gMonIcon_mystia_attack,
    [SPECIES_HMYSTIA] = gMonIcon_mystia_helper,
    [SPECIES_ADMYSTIA] = gMonIcon_mystia_advent,
    [SPECIES_CKEINE] = gMonIcon_keine_chibi,
    [SPECIES_KEINE] = gMonIcon_keine_neutral,
    [SPECIES_AKEINE] = gMonIcon_keine_attack,
    [SPECIES_DKEINE] = gMonIcon_keine_defense,
    [SPECIES_HKEINE] = gMonIcon_keine_helper,
    [SPECIES_CTEWI] = gMonIcon_tewi_chibi,
    [SPECIES_TEWI] = gMonIcon_tewi_neutral,
    [SPECIES_ATEWI] = gMonIcon_tewi_attack,
    [SPECIES_DTEWI] = gMonIcon_tewi_defense,
    [SPECIES_ADTEWI] = gMonIcon_tewi_advent,
    [SPECIES_CREISEN] = gMonIcon_reisen_chibi,
    [SPECIES_REISEN] = gMonIcon_reisen_neutral,
    [SPECIES_DREISEN] = gMonIcon_reisen_defense,
    [SPECIES_TREISEN] = gMonIcon_reisen_technical,
    [SPECIES_ADREISEN] = gMonIcon_reisen_advent,
    [SPECIES_CEIRIN] = gMonIcon_eirin_chibi,
    [SPECIES_EIRIN] = gMonIcon_eirin_neutral,
    [SPECIES_AEIRIN] = gMonIcon_eirin_attack,
    [SPECIES_HEIRIN] = gMonIcon_eirin_helper,
    [SPECIES_CKAGUYA] = gMonIcon_kaguya_chibi,
    [SPECIES_KAGUYA] = gMonIcon_kaguya_neutral,
    [SPECIES_AKAGUYA] = gMonIcon_kaguya_attack,
    [SPECIES_DKAGUYA] = gMonIcon_kaguya_defense,
    [SPECIES_CMOKOU] = gMonIcon_mokou_chibi,
    [SPECIES_MOKOU] = gMonIcon_mokou_neutral,
    [SPECIES_AMOKUO] = gMonIcon_mokou_attack,
    [SPECIES_DMOKOU] = gMonIcon_mokou_defense,
    [SPECIES_ADMOKOU] = gMonIcon_mokou_advent,
    [SPECIES_CAYA] = gMonIcon_aya_chibi,
    [SPECIES_AYA] = gMonIcon_aya_neutral,
    [SPECIES_SAYA] = gMonIcon_aya_speed,
    [SPECIES_TAYA] = gMonIcon_aya_technical,
    [SPECIES_CMEDICINE] = gMonIcon_medicine_chibi,
    [SPECIES_MEDICINE] = gMonIcon_medicine_neutral,
    [SPECIES_AMEDICINE] = gMonIcon_medicine_attack,
    [SPECIES_SMEDICINE] = gMonIcon_medicine_speed,
    [SPECIES_TMEDICINE] = gMonIcon_medicine_technical,
    [SPECIES_CYUUKA] = gMonIcon_yuuka_chibi,
    [SPECIES_YUUKA] = gMonIcon_yuuka_neutral,
    [SPECIES_AYUUKA] = gMonIcon_yuuka_attack,
    [SPECIES_TYUUKA] = gMonIcon_yuuka_technical,
    [SPECIES_CKOMACHI] = gMonIcon_komachi_chibi,
    [SPECIES_KOMACHI] = gMonIcon_komachi_neutral,
    [SPECIES_AKOMACHI] = gMonIcon_komachi_attack,
    [SPECIES_SKOMACHI] = gMonIcon_komachi_speed,
    [SPECIES_CEIKI] = gMonIcon_eiki_chibi,
    [SPECIES_EIKI] = gMonIcon_eiki_neutral,
    [SPECIES_AEIKI] = gMonIcon_eiki_attack,
    [SPECIES_DEIKI] = gMonIcon_eiki_defense,
    [SPECIES_AKYUU] = gMonIcon_akyuu,
    [SPECIES_CSHIZUHA] = gMonIcon_shizuha_chibi,
    [SPECIES_SHIZUHA] = gMonIcon_shizuha_neutral,
    [SPECIES_SSHIZUHA] = gMonIcon_shizuha_speed,
    [SPECIES_HSHIZUHA] = gMonIcon_shizuha_helper,
    [SPECIES_CMINORIKO] = gMonIcon_minoriko_chibi,
    [SPECIES_MINORIKO] = gMonIcon_minoriko_neutral,
    [SPECIES_AMINORIKO] = gMonIcon_minoriko_attack,
    [SPECIES_DMINORIKO] = gMonIcon_minoriko_defense,
    [SPECIES_AKISISTERS] = gMonIcon_aki_sisters,
    [SPECIES_CHINA] = gMonIcon_hina_chibi,
    [SPECIES_HINA] = gMonIcon_hina_neutral,
    [SPECIES_AHINA] = gMonIcon_hina_attack,
    [SPECIES_DHINA] = gMonIcon_hina_defense,
    [SPECIES_CNITORI] = gMonIcon_nitori_chibi,
    [SPECIES_NITORI] = gMonIcon_nitori_neutral,
    [SPECIES_ANITORI] = gMonIcon_nitori_attack,
    [SPECIES_TNITORI] = gMonIcon_nitori_technical,
    [SPECIES_CMOMIJI] = gMonIcon_momiji_neutral,
    [SPECIES_MOMIJI] = gMonIcon_momiji_chibi,
    [SPECIES_DMOMIJI] = gMonIcon_momiji_defense,
    [SPECIES_CSANAE] = gMonIcon_sanae_chibi,
    [SPECIES_SANAE] = gMonIcon_sanae_neutral,
    [SPECIES_ASANAE] = gMonIcon_sanae_attack,
    [SPECIES_TSANAE] = gMonIcon_sanae_technical,
    [SPECIES_JKSANAE] = gMonIcon_sanae_dumb,
    [SPECIES_CKANAKO] = gMonIcon_kanako_chibi,
    [SPECIES_KANAKO] = gMonIcon_kanako_neutral,
    [SPECIES_AKANAKO] = gMonIcon_kanako_attack,
    [SPECIES_DKANAKO] = gMonIcon_kanako_defense,
    [SPECIES_CSUWAKO] = gMonIcon_suwako_chibi,
    [SPECIES_SUWAKO] = gMonIcon_suwako_neutral,
    [SPECIES_ASUWAKO] = gMonIcon_suwako_attack,
    [SPECIES_DSUWAKO] = gMonIcon_suwako_defense,
    [SPECIES_REISEN_II] = gMonIcon_raysen,
    [SPECIES_CTOYOHIME] = gMonIcon_toyohime_chibi,
    [SPECIES_TOYOHIME] = gMonIcon_toyohime_neutral,
    [SPECIES_TTOYOHIME] = gMonIcon_toyohime_technical,
    [SPECIES_CYORIHIME] = gMonIcon_yorihime_chibi,
    [SPECIES_YORIHIME] = gMonIcon_yorihime_neutral,
    [SPECIES_SYORIHIME] = gMonIcon_yorihime_speed,
    [SPECIES_CIKU] = gMonIcon_iku_chibi,
    [SPECIES_IKU] = gMonIcon_iku_neutral,
    [SPECIES_DIKU] = gMonIcon_iku_defense,
    [SPECIES_TIKU] = gMonIcon_iku_technical,
    [SPECIES_CTENSHI] = gMonIcon_tenshi_chibi,
    [SPECIES_TENSHI] = gMonIcon_tenshi_neutral,
    [SPECIES_ATENSHI] = gMonIcon_tenshi_attack,
    [SPECIES_DTENSHI] = gMonIcon_tenshi_defense,
    [SPECIES_CKISUME] = gMonIcon_kisume_chibi,
    [SPECIES_KISUME] = gMonIcon_kisume_neutral,
    [SPECIES_TKISUME] = gMonIcon_kisume_technical,
    [SPECIES_CYAMAME] = gMonIcon_yamame_chibi,
    [SPECIES_YAMAME] = gMonIcon_yamame_neutral,
    [SPECIES_SYAMAME] = gMonIcon_yamame_speed,
    [SPECIES_TYAMAME] = gMonIcon_yamame_technical,
    [SPECIES_CPARSEE] = gMonIcon_parsee_chibi,
    [SPECIES_PARSEE] = gMonIcon_parsee_neutral,
    [SPECIES_DPARSEE] = gMonIcon_parsee_defense,
    [SPECIES_TPARSEE] = gMonIcon_parsee_technical,
    [SPECIES_CYUUGI] = gMonIcon_yuugi_chibi,
    [SPECIES_YUUGI] = gMonIcon_yuugi_neutral,
    [SPECIES_AYUUGI] = gMonIcon_yuugi_attack,
    [SPECIES_DYUUGI] = gMonIcon_yuugi_defense,
    [SPECIES_CSATORI] = gMonIcon_satori_chibi,
    [SPECIES_SATORI] = gMonIcon_satori_neutral,
    [SPECIES_DSATORI] = gMonIcon_satori_defense,
    [SPECIES_TSATORI] = gMonIcon_satori_technical,
    [SPECIES_CRIN] = gMonIcon_rin_chibi,
    [SPECIES_RIN] = gMonIcon_rin_neutral,
    [SPECIES_ARIN] = gMonIcon_rin_attack,
    [SPECIES_SRIN] = gMonIcon_rin_speed,
    [SPECIES_ZFAIRY] = gMonIcon_zombie_fairy,
    [SPECIES_CUTSUHO] = gMonIcon_utsuho_chibi,
    [SPECIES_UTSUHO] = gMonIcon_utsuho_neutral,
    [SPECIES_AUTSUHO] = gMonIcon_utsuho_attack,
    [SPECIES_SUTSUHO] = gMonIcon_utsuho_speed,
    [SPECIES_CKOISHI] = gMonIcon_koishi_chibi,
    [SPECIES_KOISHI] = gMonIcon_koishi_neutral,
    [SPECIES_AKOISHI] = gMonIcon_koishi_attack,
    [SPECIES_SKOISHI] = gMonIcon_koishi_speed,
    [SPECIES_CNAZRIN] = gMonIcon_nazrin_chibi,
    [SPECIES_NAZRIN] = gMonIcon_nazrin_neutral,
    [SPECIES_TNAZRIN] = gMonIcon_nazrin_technical,
    [SPECIES_HNAZRIN] = gMonIcon_nazrin_helper,
    [SPECIES_CKOGASA] = gMonIcon_kogasa_chibi,
    [SPECIES_KOGASA] = gMonIcon_kogasa_neutral,
    [SPECIES_SKOGASA] = gMonIcon_kogasa_speed,
    [SPECIES_TKOGASA] = gMonIcon_kogasa_technical,
    [SPECIES_CICHIRIN] = gMonIcon_ichirin_chibi,
    [SPECIES_ICHIRIN] = gMonIcon_ichirin_neutral,
    [SPECIES_DICHIRIN] = gMonIcon_ichirin_defense,
    [SPECIES_TICHIRIN] = gMonIcon_ichirin_technical,
    [SPECIES_CMURASA] = gMonIcon_murasa_chibi,
    [SPECIES_MURASA] = gMonIcon_murasa_neutral,
    [SPECIES_AMURASA] = gMonIcon_murasa_attack,
    [SPECIES_DMURASA] = gMonIcon_murasa_defense,
    [SPECIES_CSHOU] = gMonIcon_shou_chibi,
    [SPECIES_SHOU] = gMonIcon_shou_neutral,
    [SPECIES_ASHOU] = gMonIcon_shou_attack,
    [SPECIES_TSHOU] = gMonIcon_shou_technical,
    [SPECIES_CBYAKUREN] = gMonIcon_byakuren_chibi,
    [SPECIES_BYAKUREN] = gMonIcon_byakuren_neutral,
    [SPECIES_DBYAKUREN] = gMonIcon_byakuren_defense,
    [SPECIES_TBYAKUREN] = gMonIcon_byakuren_technical,
    [SPECIES_CNUE] = gMonIcon_nue_chibi,
    [SPECIES_NUE] = gMonIcon_nue_neutral,
    [SPECIES_ANUE] = gMonIcon_nue_attack,
    [SPECIES_TNUE] = gMonIcon_nue_technical,
    [SPECIES_TENSOKU] = gMonIcon_tensoku,
    [SPECIES_SHANGHAI] = gMonIcon_doll_shanghai,
    [SPECIES_HOURAI] = gMonIcon_doll_hourai,
    [SPECIES_GOLIATH] = gMonIcon_doll_goliath,
    [SPECIES_NAMAZU] = gMonIcon_namazu,
    [SPECIES_CHATATE] = gMonIcon_hatate_chibi,
    [SPECIES_HATATE] = gMonIcon_hatate_neutral,
    [SPECIES_DHATATE] = gMonIcon_hatate_defense,
    [SPECIES_THATATE] = gMonIcon_hatate_technical,
    [SPECIES_CSUNNY] = gMonIcon_sunnymilk_chibi,
    [SPECIES_SUNNY] = gMonIcon_sunnymilk_neutral,
    [SPECIES_ASUNNY] = gMonIcon_sunnymilk_attack,
    [SPECIES_DSUNNY] = gMonIcon_sunnymilk_defense,
    [SPECIES_CLUNA] = gMonIcon_lunachild_chibi,
    [SPECIES_LUNA] = gMonIcon_lunachild_neutral,
    [SPECIES_ALUNA] = gMonIcon_lunachild_attack,
    [SPECIES_TLUNA] = gMonIcon_lunachild_technical,
    [SPECIES_CSTAR] = gMonIcon_starsapphire_chibi,
    [SPECIES_STAR] = gMonIcon_starsapphire_neutral,
    [SPECIES_ASTAR] = gMonIcon_starsapphire_attack,
    [SPECIES_HSTAR] = gMonIcon_starsapphire_helper,
    [SPECIES_RINNOSUKE] = gMonIcon_rinnosuke,
    [SPECIES_CTOKIKO] = gMonIcon_tokiko_chibi,
    [SPECIES_TOKIKO] = gMonIcon_tokiko_neutral,
    [SPECIES_ATOKIKO] = gMonIcon_tokiko_attack,
    [SPECIES_CKYOUKO] = gMonIcon_kyouko_chibi,
    [SPECIES_KYOUKO] = gMonIcon_kyouko_neutral,
    [SPECIES_TKYOUKO] = gMonIcon_kyouko_technical,
    [SPECIES_CYOSHIKA] = gMonIcon_yoshika_chibi,
    [SPECIES_YOSHIKA] = gMonIcon_yoshika_neutral,
    [SPECIES_HYOSHIKA] = gMonIcon_yoshika_helper,
    [SPECIES_CSEIGA] = gMonIcon_seiga_chibi,
    [SPECIES_SEIGA] = gMonIcon_seiga_neutral,
    [SPECIES_SSEIGA] = gMonIcon_seiga_speed,
    [SPECIES_CTOJIKO] = gMonIcon_tojiko_chibi,
    [SPECIES_TOJIKO] = gMonIcon_tojiko_neutral,
    [SPECIES_STOJIKO] = gMonIcon_tojiko_speed,
    [SPECIES_CFUTO] = gMonIcon_futo_chibi,
    [SPECIES_FUTO] = gMonIcon_futo_neutral,
    [SPECIES_TFUTO] = gMonIcon_futo_technical,
    [SPECIES_CMIKO] = gMonIcon_miko_chibi,
    [SPECIES_MIKO] = gMonIcon_miko_neutral,
    [SPECIES_AMIKO] = gMonIcon_miko_attack,
    [SPECIES_DMIKO] = gMonIcon_miko_defense,
    [SPECIES_CMAMIZOU] = gMonIcon_mamizou_chibi,
    [SPECIES_MAMIZOU] = gMonIcon_mamizou_neutral,
    [SPECIES_DMAMIZOU] = gMonIcon_mamizou_defense,
    [SPECIES_CKOSUZU] = gMonIcon_kosuzu_chibi,
    [SPECIES_KOSUZU] = gMonIcon_kosuzu_neutral,
    [SPECIES_JINYOU] = gMonIcon_jinyou,
    [SPECIES_CKOKORO] = gMonIcon_kokoro_chibi,
    [SPECIES_KOKORO] = gMonIcon_kokoro_neutral,
    [SPECIES_AKOKORO] = gMonIcon_kokoro_attack,
    [SPECIES_TKOKORO] = gMonIcon_kokoro_technical,
    [SPECIES_CWAKASAGIHIME] = gMonIcon_wakasagihime_chibi,
    [SPECIES_WAKASAGIHIME] = gMonIcon_wakasagihime_neutral,
    [SPECIES_DWAKASAGIHIME] = gMonIcon_wakasagihime_defense,
    [SPECIES_CSEKIBANKI] = gMonIcon_sekibanki_chibi,
    [SPECIES_SEKIBANKI] = gMonIcon_sekibanki_neutral,
    [SPECIES_TSEKIBANKI] = gMonIcon_sekibanki_tech,
    [SPECIES_CKAGEROU] = gMonIcon_kagerou_chibi,
    [SPECIES_KAGEROU] = gMonIcon_kagerou_neutral,
    [SPECIES_HKAGEROU] = gMonIcon_kagerou_helper,
    [SPECIES_CBENBEN] = gMonIcon_benben_chibi,
    [SPECIES_BENBEN] = gMonIcon_benben_neutral,
    [SPECIES_CYATSUHASHI] = gMonIcon_yatsuhashi_chibi,
    [SPECIES_YATSUHASHI] = gMonIcon_yatsuhashi_neutral,
    [SPECIES_CSEIJA] = gMonIcon_seija_chibi,
    [SPECIES_SEIJA] = gMonIcon_seija_neutral,
    [SPECIES_DSEIJA] = gMonIcon_seija_defense,
    [SPECIES_CSHINMYOUMARU] = gMonIcon_sukuna_chibi,
    [SPECIES_SHINMYOUMARU] = gMonIcon_sukuna_neutral,
    [SPECIES_ASHINMYOUMARU] = gMonIcon_sukuna_attack,
    [SPECIES_CRAIKO] = gMonIcon_raiko_chibi,
    [SPECIES_RAIKO] = gMonIcon_raiko_neutral,
    [SPECIES_ARAIKO] = gMonIcon_raiko_attack,
    [SPECIES_CKASEN] = gMonIcon_kasen_chibi,
    [SPECIES_KASEN] = gMonIcon_kasen_neutral,
    [SPECIES_HKASEN] = gMonIcon_kasen_helper,
    [SPECIES_CSUMIREKO] = gMonIcon_sumireko_chibi,
    [SPECIES_SUMIREKO] = gMonIcon_sumireko_neutral,
    [SPECIES_CSEIRAN] = gMonIcon_seiran_chibi,
    [SPECIES_SEIRAN] = gMonIcon_seiran_neutral,
    [SPECIES_CRINGO] = gMonIcon_ringo_chibi,
    [SPECIES_RINGO] = gMonIcon_ringo_neutral,
    [SPECIES_CDOREMY] = gMonIcon_doremy_chibi,
    [SPECIES_DOREMY] = gMonIcon_doremy_neutral,
    [SPECIES_CSAGUME] = gMonIcon_sagume_chibi,
    [SPECIES_SAGUME] = gMonIcon_sagume_neutral,
    [SPECIES_CCLOWNPIECE] = gMonIcon_clownpiece_chibi,
    [SPECIES_CLOWNPIECE] = gMonIcon_clownpiece_neutral,
    [SPECIES_CJUNKO] = gMonIcon_junko_chibi,
    [SPECIES_JUNKO] = gMonIcon_junko_neutral,
    [SPECIES_CHECATIA] = gMonIcon_hecatia_chibi,
    [SPECIES_HECATIA] = gMonIcon_hecatia_neutral,
    [SPECIES_CHAKUREI] = gMonIcon_hakurei_chibi,
    [SPECIES_HAKUREI] = gMonIcon_hakurei_neutral,
    [SPECIES_CKIRISAME] = gMonIcon_kirisame_chibi,
    [SPECIES_KIRISAME] = gMonIcon_kirisame_neutral,
    [SPECIES_CSHINGYOKU] = gMonIcon_shingyoku_chibi,
    [SPECIES_SHINGYOKUF] = gMonIcon_shingyoku_female,
    [SPECIES_SHINGOKYUM] = gMonIcon_shingyoku_male,
    [SPECIES_SHINGYOKUO] = gMonIcon_shingyoku_orb,
    [SPECIES_CMAGAN] = gMonIcon_magan_chibi,
    [SPECIES_MAGAN] = gMonIcon_magan_neutral,
    [SPECIES_CMIMA] = gMonIcon_mima_chibi,
    [SPECIES_MIMA] = gMonIcon_mima_neutral,
    [SPECIES_CELIS] = gMonIcon_elis_chibi,
    [SPECIES_ELIS] = gMonIcon_elis_neutral,
    [SPECIES_CKIKURI] = gMonIcon_kikuri_chibi,
    [SPECIES_KIKURI] = gMonIcon_kikuri_neutral,
    [SPECIES_CKONNGARA] = gMonIcon_konngara_chibi,
    [SPECIES_KONNGARA] = gMonIcon_konngara_neutral,
    [SPECIES_CSARIEL] = gMonIcon_sariel_chibi,
    [SPECIES_SARIEL] = gMonIcon_sariel_neutral,
    [SPECIES_SSARIEL] = gMonIcon_sariel_speed,
    [SPECIES_GENJI] = gMonIcon_genji,
    [SPECIES_CRIKA] = gMonIcon_rika_chibi,
    [SPECIES_RIKA] = gMonIcon_rika_neutral,
    [SPECIES_CMEIRA] = gMonIcon_meira_chibi,
    [SPECIES_MEIRA] = gMonIcon_meira_neutral,
    [SPECIES_MAGISTONES] = gMonIcon_magicstones,
    [SPECIES_CELLEN] = gMonIcon_ellen_chibi,
    [SPECIES_ELLEN] = gMonIcon_ellen_neutral,
    [SPECIES_CKOTOHIME] = gMonIcon_kotohime_chibi,
    [SPECIES_KOTOHIME] = gMonIcon_kotohime_neutral,
    [SPECIES_CKANA] = gMonIcon_kana_chibi,
    [SPECIES_KANA] = gMonIcon_kana_neutral,
    [SPECIES_CRIKAKO] = gMonIcon_rikako_chibi,
    [SPECIES_RIKAKO] = gMonIcon_rikako_neutral,
    [SPECIES_CCHIYURI] = gMonIcon_chiyuri_chibi,
    [SPECIES_CHIYURI] = gMonIcon_chiyuri_neutral,
    [SPECIES_CYUMEMI] = gMonIcon_yumemi_chibi,
    [SPECIES_YUMEMI] = gMonIcon_yumemi_neutral,
    [SPECIES_RUUKOTO] = gMonIcon_ruukoto,
    [SPECIES_MIMI_CHAN] = gMonIcon_mimichan,
    [SPECIES_CORANGE] = gMonIcon_orange_chibi,
    [SPECIES_ORANGE] = gMonIcon_orange_neutral,
    [SPECIES_CKURUMI] = gMonIcon_kurumi_chibi,
    [SPECIES_KURUMI] = gMonIcon_kurumi_neutral,
    [SPECIES_CELLY] = gMonIcon_elly_chibi,
    [SPECIES_ELLY] = gMonIcon_elly_neutral,
    [SPECIES_CKAZAMI] = gMonIcon_kazami_chibi,
    [SPECIES_KAZAMI] = gMonIcon_kazami_neutral,
    [SPECIES_AKAZAMI] = gMonIcon_kazami_attack,
    [SPECIES_CMUGETSU] = gMonIcon_mugetsu_chibi,
    [SPECIES_MUGETSU] = gMonIcon_mugetsu_neutral,
    [SPECIES_CGENGETSU] = gMonIcon_gengetsu_chibi,
    [SPECIES_GENGETSU] = gMonIcon_gengetsu_neutral,
    [SPECIES_CSARA] = gMonIcon_sara_chibi,
    [SPECIES_SARA] = gMonIcon_sara_neutral,
    [SPECIES_CLOUISE] = gMonIcon_louise_chibi,
    [SPECIES_LOUISE] = gMonIcon_louise_neutral,
    [SPECIES_CARISU] = gMonIcon_arisu_chibi,
    [SPECIES_ARISU] = gMonIcon_arisu_neutral,
    [SPECIES_CYUKI] = gMonIcon_yuki_chibi,
    [SPECIES_YUKI] = gMonIcon_yuki_neutral,
    [SPECIES_CMAI] = gMonIcon_mai_chibi,
    [SPECIES_MAI] = gMonIcon_mai_neutral,
    [SPECIES_CYUMEKO] = gMonIcon_yumeko_chibi,
    [SPECIES_YUMEKO] = gMonIcon_yumeko_neutral,
    [SPECIES_CSHINKI] = gMonIcon_shinki_chibi,
    [SPECIES_SHINKI] = gMonIcon_shinki_neutral,
    [SPECIES_CSENDAI] = gMonIcon_sendai_chibi,
    [SPECIES_SENDAI] = gMonIcon_sendai_neutral,
    [SPECIES_CTENMA] = gMonIcon_tenma_chibi,
    [SPECIES_TENMA] = gMonIcon_tenma_neutral,
    [SPECIES_CLAYLA] = gMonIcon_layla_chibi,
    [SPECIES_LAYLA] = gMonIcon_layla_neutral,
    [SPECIES_DLAYLA] = gMonIcon_layla_defense,
    [SPECIES_YOUKI] = gMonIcon_youki,
    [SPECIES_TORI] = gMonIcon_tori,
    [SPECIES_2HU] = gMonIcon_2hu,
    [SPECIES_XSUWAKO] = gMonIcon_xsuwako,
    [SPECIES_XUTSUHO] = gMonIcon_xutsuho,
    [SPECIES_XTENSHI] = gMonIcon_xtenshi,
    [SPECIES_XTENMA] = gMonIcon_xtenma,
    [SPECIES_XSENDAI] = gMonIcon_xsendai,
    [SPECIES_EGG] = gMonIcon_Egg
};

const u8 gMonIconPaletteIndices[] = {
    [SPECIES_NONE]        = 0,
    [SPECIES_CREIMU] = 1,
    [SPECIES_REIMU] = 1,
    [SPECIES_AREIMU] = 1,
    [SPECIES_DREIMU] = 1,
    
    [SPECIES_CMARISA] = 1,
    [SPECIES_MARISA] = 1,
    [SPECIES_AMARISA] = 1,
    [SPECIES_SMARISA] = 1,
    [SPECIES_ADMARISA] = 1,
    [SPECIES_LMARISA] = 2,
    
    [SPECIES_CRUMIA] = 1,
    [SPECIES_RUMIA] = 1,
    [SPECIES_ARUMIA] = 1,
    [SPECIES_SRUMIA] = 1,
    
    [SPECIES_CDAIYOUSEI] = 0,
    [SPECIES_DAIYOUSEI] = 0,
    [SPECIES_ADAIYOUSEI] = 0,
    [SPECIES_DDAIYOUSEI] = 0,
    
    [SPECIES_CCIRNO] = 1,
    [SPECIES_CIRNO] = 1,
    [SPECIES_SCIRNO] = 1,
    [SPECIES_TCIRNO] = 1,
    [SPECIES_ADCIRNO] = 1,
    
    [SPECIES_CMEILING] = 0,
    [SPECIES_MEILING] = 0,
    [SPECIES_DMEILING] = 0,
    [SPECIES_SMEILING] = 0,
    [SPECIES_ADMEILING] = 0,
    
    [SPECIES_CKOAKUMA] = 1,
    [SPECIES_KOAKUMA] = 1,
    [SPECIES_HKOAKUMA] = 1,
    
    [SPECIES_CPATCHOULI] = 1,
    [SPECIES_PATCHOULI] = 1,
    [SPECIES_APATCHOULI] = 1,
    [SPECIES_DPATCHOULI] = 1,
    
    [SPECIES_CSAKUYA] = 1,
    [SPECIES_SAKUYA] = 1,
    [SPECIES_TSAKUYA] = 1,
    [SPECIES_HSAKUYA] = 1,
    
    [SPECIES_CREMILIA] = 0,
    [SPECIES_REMILIA] = 0,
    [SPECIES_AREMILIA] = 0,
    [SPECIES_DREMILIA] = 0,
    
    [SPECIES_CFLANDRE] = 1,
    [SPECIES_FLANDRE] = 1,
    [SPECIES_AFLANDRE] = 1,
    [SPECIES_SFLANDRE] = 1,
    
    [SPECIES_CLETTY] = 1,
    [SPECIES_LETTY] = 1,
    [SPECIES_DLETTY] = 1,
    [SPECIES_HLETTY] = 1,
    [SPECIES_ADLETTY] = 1,
    
    [SPECIES_CCHEN] = 2,
    [SPECIES_CHEN] = 2,
    [SPECIES_ACHEN] = 2,
    [SPECIES_TCHEN] = 2,
    [SPECIES_ADCHEN] = 2,
    
    [SPECIES_CALICE] = 1,
    [SPECIES_ALICE] = 1,
    [SPECIES_AALICE] = 1,
    [SPECIES_TALICE] = 1,
    [SPECIES_ADALICE] = 1,
    [SPECIES_DARK_ALICE] = 0,
    
    [SPECIES_CLILYWHITE] = 2,
    [SPECIES_LILYWHITE] = 2,
    [SPECIES_ALILYWHITE] = 2,
    [SPECIES_HLILYWHITE] = 2,
    
    [SPECIES_CLILYBLACK] = 2,
    [SPECIES_LILYBLACK] = 2,
    [SPECIES_ALILYBLACK] = 2,
    [SPECIES_SLILYBLACK] = 2,
    
    [SPECIES_CLUNASA] = 1,
    [SPECIES_LUNASA] = 1,
    [SPECIES_HLUNASA] = 1,
    
    [SPECIES_CMERLIN] = 0,
    [SPECIES_MERLIN] = 0,
    [SPECIES_HMERLIN] = 0,
    
    [SPECIES_CLYRICA] = 0,
    [SPECIES_LYRICA] = 0,
    [SPECIES_HLYRICA] = 0,
    
    [SPECIES_CYOUMU] = 0,
    [SPECIES_YOUMU] = 0,
    [SPECIES_DYOUMU] = 0,
    [SPECIES_SYOUMU] = 0,
    [SPECIES_LYOUMU] = 1,
    
    [SPECIES_CYUYUKO] = 0,
    [SPECIES_YUYUKO] = 0,
    [SPECIES_AYUYUKO] = 0,
    [SPECIES_DYUYUKO] = 0,
    [SPECIES_LYUYUKO] = 0,
    
    [SPECIES_CRAN] = 1,
    [SPECIES_RAN] = 1,
    [SPECIES_ARAN] = 1,
    [SPECIES_HRAN] = 1,
    [SPECIES_ADRAN] = 1,
    
    [SPECIES_CYUKARI] = 1,
    [SPECIES_YUKARI] = 1,
    [SPECIES_DYUKARI] = 1,
    [SPECIES_TYUKARI] = 1,
    [SPECIES_ADYUKARI] = 1,
    
    [SPECIES_CSUIKA] = 1,
    [SPECIES_SUIKA] = 1,
    [SPECIES_ASUIKA] = 1,
    [SPECIES_TSUIKA] = 1,
    
    [SPECIES_CWRIGGLE] = 0,
    [SPECIES_WRIGGLE] = 0,
    [SPECIES_DWRIGGLE] = 0,
    [SPECIES_SWRIGGLE] = 0,
    
    [SPECIES_CMYSTIA] = 0,
    [SPECIES_MYSTIA] = 0,
    [SPECIES_AMYSTIA] = 0,
    [SPECIES_HMYSTIA] = 0,
    [SPECIES_ADMYSTIA] = 0,
    
    [SPECIES_CKEINE] = 0,
    [SPECIES_KEINE] = 0,
    [SPECIES_AKEINE] = 0,
    [SPECIES_DKEINE] = 0,
    [SPECIES_HKEINE] = 0,
    
    [SPECIES_CTEWI] = 0,
    [SPECIES_TEWI] = 0,
    [SPECIES_ATEWI] = 0,
    [SPECIES_DTEWI] = 0,
    [SPECIES_ADTEWI] = 0,
    
    [SPECIES_CREISEN] = 1,
    [SPECIES_REISEN] = 1,
    [SPECIES_DREISEN] = 1,
    [SPECIES_TREISEN] = 1,
    [SPECIES_ADREISEN] = 1,
    
    [SPECIES_CEIRIN] = 1,
    [SPECIES_EIRIN] = 1,
    [SPECIES_AEIRIN] = 1,
    [SPECIES_HEIRIN] = 1,
    
    [SPECIES_CKAGUYA] = 0,
    [SPECIES_KAGUYA] = 0,
    [SPECIES_AKAGUYA] = 0,
    [SPECIES_DKAGUYA] = 0,
    
    [SPECIES_CMOKOU] = 1,
    [SPECIES_MOKOU] = 1,
    [SPECIES_AMOKUO] = 1,
    [SPECIES_DMOKOU] = 1,
    [SPECIES_ADMOKOU] = 1,
    
    [SPECIES_CAYA] = 1,
    [SPECIES_AYA] = 1,
    [SPECIES_SAYA] = 1,
    [SPECIES_TAYA] = 1,
    
    [SPECIES_CMEDICINE] = 1,
    [SPECIES_MEDICINE] = 1,
    [SPECIES_AMEDICINE] = 1,
    [SPECIES_SMEDICINE] = 1,
    [SPECIES_TMEDICINE] = 1,
    
    [SPECIES_CYUUKA] = 2,
    [SPECIES_YUUKA] = 2,
    [SPECIES_AYUUKA] = 2,
    [SPECIES_TYUUKA] = 2,
    
    [SPECIES_CKOMACHI] = 0,
    [SPECIES_KOMACHI] = 0,
    [SPECIES_AKOMACHI] = 0,
    [SPECIES_SKOMACHI] = 0,
    
    [SPECIES_CEIKI] = 0,
    [SPECIES_EIKI] = 0,
    [SPECIES_AEIKI] = 0,
    [SPECIES_DEIKI] = 0,
    
    [SPECIES_AKYUU] = 1,
    
    [SPECIES_CSHIZUHA] = 2,
    [SPECIES_SHIZUHA] = 2,
    [SPECIES_SSHIZUHA] = 2,
    [SPECIES_HSHIZUHA] = 2,
    
    [SPECIES_CMINORIKO] = 2,
    [SPECIES_MINORIKO] = 2,
    [SPECIES_AMINORIKO] = 2,
    [SPECIES_DMINORIKO] = 2,
    
    [SPECIES_AKISISTERS] = 2,
    
    [SPECIES_CHINA] = 0,
    [SPECIES_HINA] = 0,
    [SPECIES_AHINA] = 0,
    [SPECIES_DHINA] = 0,
    
    [SPECIES_CNITORI] = 0,
    [SPECIES_NITORI] = 0,
    [SPECIES_ANITORI] = 0,
    [SPECIES_TNITORI] = 0,
    
    [SPECIES_CMOMIJI] = 1,
    [SPECIES_MOMIJI] = 1,
    [SPECIES_DMOMIJI] = 1,
    
    [SPECIES_CSANAE] = 0,
    [SPECIES_SANAE] = 0,
    [SPECIES_ASANAE] = 0,
    [SPECIES_TSANAE] = 0,
    [SPECIES_JKSANAE] = 0,
    
    [SPECIES_CKANAKO] = 1,
    [SPECIES_KANAKO] = 1,
    [SPECIES_AKANAKO] = 1,
    [SPECIES_DKANAKO] = 1,
    
    [SPECIES_CSUWAKO] = 1,
    [SPECIES_SUWAKO] = 1,
    [SPECIES_ASUWAKO] = 1,
    [SPECIES_DSUWAKO] = 1,
    
    [SPECIES_REISEN_II] = 0,
    
    [SPECIES_CTOYOHIME] = 1,
    [SPECIES_TOYOHIME] = 1,
    [SPECIES_TTOYOHIME] = 1,
    
    [SPECIES_CYORIHIME] = 1,
    [SPECIES_YORIHIME] = 1,
    [SPECIES_SYORIHIME] = 1,
    
    [SPECIES_CIKU] = 0,
    [SPECIES_IKU] = 0,
    [SPECIES_DIKU] = 0,
    [SPECIES_TIKU] = 0,
    
    [SPECIES_CTENSHI] = 0,
    [SPECIES_TENSHI] = 0,
    [SPECIES_ATENSHI] = 0,
    [SPECIES_DTENSHI] = 0,
    
    [SPECIES_CKISUME] = 0,
    [SPECIES_KISUME] = 0,
    [SPECIES_TKISUME] = 0,
    
    [SPECIES_CYAMAME] = 2,
    [SPECIES_YAMAME] = 2,
    [SPECIES_SYAMAME] = 2,
    [SPECIES_TYAMAME] = 2,
    
    [SPECIES_CPARSEE] = 1,
    [SPECIES_PARSEE] = 1,
    [SPECIES_DPARSEE] = 1,
    [SPECIES_TPARSEE] = 1,
    
    [SPECIES_CYUUGI] = 1,
    [SPECIES_YUUGI] = 1,
    [SPECIES_AYUUGI] = 1,
    [SPECIES_DYUUGI] = 1,
    
    [SPECIES_CSATORI] = 1,
    [SPECIES_SATORI] = 1,
    [SPECIES_DSATORI] = 1,
    [SPECIES_TSATORI] = 1,
    
    [SPECIES_CRIN] = 0,
    [SPECIES_RIN] = 0,
    [SPECIES_ARIN] = 0,
    [SPECIES_SRIN] = 0,
    [SPECIES_ZFAIRY] = 1,
    
    [SPECIES_CUTSUHO] = 0,
    [SPECIES_UTSUHO] = 0,
    [SPECIES_AUTSUHO] = 0,
    [SPECIES_SUTSUHO] = 0,
    
    [SPECIES_CKOISHI] = 2,
    [SPECIES_KOISHI] = 2,
    [SPECIES_AKOISHI] = 2,
    [SPECIES_SKOISHI] = 2,
    
    [SPECIES_CNAZRIN] = 1,
    [SPECIES_NAZRIN] = 1,
    [SPECIES_TNAZRIN] = 1,
    [SPECIES_HNAZRIN] = 1,
    
    [SPECIES_CKOGASA] = 1,
    [SPECIES_KOGASA] = 1,
    [SPECIES_SKOGASA] = 1,
    [SPECIES_TKOGASA] = 1,
    
    [SPECIES_CICHIRIN] = 1,
    [SPECIES_ICHIRIN] = 1,
    [SPECIES_DICHIRIN] = 1,
    [SPECIES_TICHIRIN] = 1,
    
    [SPECIES_CMURASA] = 0,
    [SPECIES_MURASA] = 0,
    [SPECIES_AMURASA] = 0,
    [SPECIES_DMURASA] = 0,
    
    [SPECIES_CSHOU] = 1,
    [SPECIES_SHOU] = 1,
    [SPECIES_ASHOU] = 1,
    [SPECIES_TSHOU] = 1,
    
    [SPECIES_CBYAKUREN] = 1,
    [SPECIES_BYAKUREN] = 1,
    [SPECIES_DBYAKUREN] = 1,
    [SPECIES_TBYAKUREN] = 1,
    
    [SPECIES_CNUE] = 1,
    [SPECIES_NUE] = 1,
    [SPECIES_ANUE] = 1,
    [SPECIES_TNUE] = 1,
    
    [SPECIES_TENSOKU] = 1,
    [SPECIES_SHANGHAI] = 1,
    [SPECIES_HOURAI] = 1,
    [SPECIES_GOLIATH] = 1,
    [SPECIES_NAMAZU] = 1,
    
    [SPECIES_CHATATE] = 1,
    [SPECIES_HATATE] = 1,
    [SPECIES_DHATATE] = 1,
    [SPECIES_THATATE] = 1,
    
    [SPECIES_CSUNNY] = 2,
    [SPECIES_SUNNY] = 2,
    [SPECIES_ASUNNY] = 2,
    [SPECIES_DSUNNY] = 2,
    
    [SPECIES_CLUNA] = 1,
    [SPECIES_LUNA] = 1,
    [SPECIES_ALUNA] = 1,
    [SPECIES_TLUNA] = 1,
    
    [SPECIES_CSTAR] = 0,
    [SPECIES_STAR] = 0,
    [SPECIES_ASTAR] = 0,
    [SPECIES_HSTAR] = 0,
    
    [SPECIES_RINNOSUKE] = 0,
    
    [SPECIES_CTOKIKO] = 1,
    [SPECIES_TOKIKO] = 1,
    [SPECIES_ATOKIKO] = 1,
    
    [SPECIES_CKYOUKO] = 2,
    [SPECIES_KYOUKO] = 2,
    [SPECIES_TKYOUKO] = 2,
    
    [SPECIES_CYOSHIKA] = 1,
    [SPECIES_YOSHIKA] = 1,
    [SPECIES_HYOSHIKA] = 1,
    
    [SPECIES_CSEIGA] = 0,
    [SPECIES_SEIGA] = 0,
    [SPECIES_SSEIGA] = 0,
    
    [SPECIES_CTOJIKO] = 0,
    [SPECIES_TOJIKO] = 0,
    [SPECIES_STOJIKO] = 0,
    
    [SPECIES_CFUTO] = 0,
    [SPECIES_FUTO] = 0,
    [SPECIES_TFUTO] = 0,
    
    [SPECIES_CMIKO] = 1,
    [SPECIES_MIKO] = 1,
    [SPECIES_AMIKO] = 1,
    [SPECIES_DMIKO] = 1,
    
    [SPECIES_CMAMIZOU] = 2,
    [SPECIES_MAMIZOU] = 2,
    [SPECIES_DMAMIZOU] = 2,
    
    [SPECIES_CKOSUZU] = 2,
    [SPECIES_KOSUZU] = 2,
    
    [SPECIES_JINYOU] = 1,
    
    [SPECIES_CKOKORO] = 0,
    [SPECIES_KOKORO] = 0,
    [SPECIES_AKOKORO] = 0,
    [SPECIES_TKOKORO] = 0,
    
    [SPECIES_CWAKASAGIHIME] = 0,
    [SPECIES_WAKASAGIHIME] = 0,
    [SPECIES_DWAKASAGIHIME] = 0,
    
    [SPECIES_CSEKIBANKI] = 0,
    [SPECIES_SEKIBANKI] = 0,
    [SPECIES_TSEKIBANKI] = 0,
    
    [SPECIES_CKAGEROU] = 1,
    [SPECIES_KAGEROU] = 1,
    [SPECIES_HKAGEROU] = 1,
    
    [SPECIES_CBENBEN] = 1,
    [SPECIES_BENBEN] = 1,
    
    [SPECIES_CYATSUHASHI] = 0,
    [SPECIES_YATSUHASHI] = 0,
    
    [SPECIES_CSEIJA] = 0,
    [SPECIES_SEIJA] = 0,
    [SPECIES_DSEIJA] = 0,
    
    [SPECIES_CSHINMYOUMARU] = 1,
    [SPECIES_SHINMYOUMARU] = 1,
    [SPECIES_ASHINMYOUMARU] = 1,
    
    [SPECIES_CRAIKO] = 2,
    [SPECIES_RAIKO] = 2,
    [SPECIES_ARAIKO] = 2,
    
    [SPECIES_CKASEN] = 0,
    [SPECIES_KASEN] = 0,
    [SPECIES_HKASEN] = 0,
    
    [SPECIES_CSUMIREKO] = 1,
    [SPECIES_SUMIREKO] = 1,
    
    [SPECIES_CSEIRAN] = 0,
    [SPECIES_SEIRAN] = 0,
    
    [SPECIES_CRINGO] = 2,
    [SPECIES_RINGO] = 2,
    
    [SPECIES_CDOREMY] = 0,
    [SPECIES_DOREMY] = 0,
    
    [SPECIES_CSAGUME] = 0,
    [SPECIES_SAGUME] = 0,
    
    [SPECIES_CCLOWNPIECE] = 1,
    [SPECIES_CLOWNPIECE] = 1,
    
    [SPECIES_CJUNKO] = 2,
    [SPECIES_JUNKO] = 2,
    
    [SPECIES_CHECATIA] = 1,
    [SPECIES_HECATIA] = 1,
    
    [SPECIES_CHAKUREI] = 1,
    [SPECIES_HAKUREI] = 1,
    
    [SPECIES_CKIRISAME] = 1,
    [SPECIES_KIRISAME] = 1,
    
    [SPECIES_CSHINGYOKU] = 0,
    [SPECIES_SHINGYOKUF] = 0,
    [SPECIES_SHINGOKYUM] = 0,
    [SPECIES_SHINGYOKUO] = 0,
    
    [SPECIES_CMAGAN] = 1,
    [SPECIES_MAGAN] = 1,
    
    [SPECIES_CMIMA] = 0,
    [SPECIES_MIMA] = 0,
    
    [SPECIES_CELIS] = 1,
    [SPECIES_ELIS] = 1,
    
    [SPECIES_CKIKURI] = 1,
    [SPECIES_KIKURI] = 1,
    
    [SPECIES_CKONNGARA] = 1,
    [SPECIES_KONNGARA] = 1,
    
    [SPECIES_CSARIEL] = 1,
    [SPECIES_SARIEL] = 1,
    [SPECIES_SSARIEL] = 1,
    
    [SPECIES_GENJI] = 0,
    
    [SPECIES_CRIKA] = 1,
    [SPECIES_RIKA] = 0,
    
    [SPECIES_CMEIRA] = 1,
    [SPECIES_MEIRA] = 1,
    
    [SPECIES_MAGISTONES] = 0,
    
    [SPECIES_CELLEN] = 1,
    [SPECIES_ELLEN] = 1,
    
    [SPECIES_CKOTOHIME] = 1,
    [SPECIES_KOTOHIME] = 1,
    
    [SPECIES_CKANA] = 1,
    [SPECIES_KANA] = 1,
    
    [SPECIES_CRIKAKO] = 1,
    [SPECIES_RIKAKO] = 1,
    
    [SPECIES_CCHIYURI] = 1,
    [SPECIES_CHIYURI] = 1,
    
    [SPECIES_CYUMEMI] = 1,
    [SPECIES_YUMEMI] = 1,
    
    [SPECIES_RUUKOTO] = 0,
    
    [SPECIES_MIMI_CHAN] = 1,
    
    [SPECIES_CORANGE] = 2,
    [SPECIES_ORANGE] = 2,
    
    [SPECIES_CKURUMI] = 1,
    [SPECIES_KURUMI] = 1,
    
    [SPECIES_CELLY] = 1,
    [SPECIES_ELLY] = 1,
    
    [SPECIES_CKAZAMI] = 2,
    [SPECIES_KAZAMI] = 2,
    [SPECIES_AKAZAMI] = 2,
    
    [SPECIES_CMUGETSU] = 1,
    [SPECIES_MUGETSU] = 1,
    
    [SPECIES_CGENGETSU] = 1,
    [SPECIES_GENGETSU] = 1,
    
    [SPECIES_CSARA] = 0,
    [SPECIES_SARA] = 0,
    
    [SPECIES_CLOUISE] = 1,
    [SPECIES_LOUISE] = 1,
    
    [SPECIES_CARISU] = 1,
    [SPECIES_ARISU] = 1,
    
    [SPECIES_CYUKI] = 1,
    [SPECIES_YUKI] = 1,
    
    [SPECIES_CMAI] = 1,
    [SPECIES_MAI] = 1,
    
    [SPECIES_CYUMEKO] = 1,
    [SPECIES_YUMEKO] = 1,
    
    [SPECIES_CSHINKI] = 1,
    [SPECIES_SHINKI] = 1,
    [SPECIES_CSENDAI] = 1,
    [SPECIES_SENDAI] = 1,
    [SPECIES_CTENMA] = 1,
    [SPECIES_TENMA] = 1,
    [SPECIES_CLAYLA] = 0,
    [SPECIES_LAYLA] = 0,
    [SPECIES_DLAYLA] = 0,
    [SPECIES_YOUKI] = 0,
    [SPECIES_TORI] = 0,
    [SPECIES_2HU] = 0,
    [SPECIES_XSUWAKO] = 1,
    [SPECIES_XUTSUHO] = 0,
    [SPECIES_XTENSHI] = 0,
    [SPECIES_XTENMA] = 1,
    [SPECIES_XSENDAI] = 1,
    [SPECIES_EGG] = 0,
};

const struct SpritePalette gMonIconPaletteTable[] = {
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },
    // The following three point outside the gMonIconPalettes array
    // and are therefore invalid. Fortunately, they are never used.
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 }
};

static const struct OamData sMonIconOamData = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0x000,
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sMonIconAnim_Fast[] = {
    ANIMCMD_FRAME(0,  6),
    ANIMCMD_FRAME(1,  6),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sMonIconAnim_MediumFast[] = {
    ANIMCMD_FRAME(0,  8),
    ANIMCMD_FRAME(1,  8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sMonIconAnim_MediumSlow[] = {
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sMonIconAnim_Slow[] = {
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sMonIconAnim_Still[] = {
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sMonIconAnims[] = {
    sMonIconAnim_Fast,
    sMonIconAnim_MediumFast,
    sMonIconAnim_MediumSlow,
    sMonIconAnim_Slow,
    sMonIconAnim_Still
};

static const union AffineAnimCmd sMonIconAffineAnim_0[] = {
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sMonIconAffineAnim_1[] = {
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] = {
    sMonIconAffineAnim_0,
    sMonIconAffineAnim_1
};

static const u16 sSpriteImageSizes[][4] = {
    [ST_OAM_SQUARE] = {
        [ST_OAM_SIZE_0] = 0x020,
        [ST_OAM_SIZE_1] = 0x080,
        [ST_OAM_SIZE_2] = 0x200,
        [ST_OAM_SIZE_3] = 0x800,
    },
    [ST_OAM_H_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x040,
        [ST_OAM_SIZE_1] = 0x080,
        [ST_OAM_SIZE_2] = 0x100,
        [ST_OAM_SIZE_3] = 0x400,
    },
    [ST_OAM_V_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x040,
        [ST_OAM_SIZE_1] = 0x080,
        [ST_OAM_SIZE_2] = 0x100,
        [ST_OAM_SIZE_3] = 0x400,
    },
};

u8 CreateMonIcon(u16 species, SpriteCallback callback, s16 x, s16 y, u8 subpriority, u32 personality, bool32 extra)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
        {
            .oam = &sMonIconOamData,
            .image = GetMonIconPtr(species, personality, extra),
            .anims = sMonIconAnims,
            .affineAnims = sMonIconAffineAnims,
            .callback = callback,
            .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
        };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 CreateMonIcon_HandleDeoxys(u16 species, SpriteCallback callback, s16 x, s16 y, u8 subpriority, bool32 extra)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
        {
            .oam = &sMonIconOamData,
            .image = NULL,
            .anims = sMonIconAnims,
            .affineAnims = sMonIconAffineAnims,
            .callback = callback,
            .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
        };

    iconTemplate.image = GetMonIconTiles(species, extra);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;

    if (species > NUM_SPECIES)
        result = SPECIES_NONE;
    else
        result = species;

    return result;
}

u16 MailSpeciesToIconSpecies(u16 species)
{
    u16 value;

    return GetIconSpecies(species, 0);
}

const u8 *GetMonIconTiles(u16 species, bool32 extra)
{
    const u8 *iconSprite = gMonIconTable[species];
    return iconSprite;
}

const u8 *GetMonIconPtr(u16 species, u32 personality, bool32 extra)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), extra);
}

void DestroyMonIcon(struct Sprite * sprite)
{
    DestroyMonIconInternal(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < NELEMS(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = SPECIES_NONE;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = SPECIES_NONE;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite * sprite)
{
    UpdateMonIconFrame(sprite);
}

void LoadMonIconPalettesAt(u16 offset)
{
    int i;
    if (offset <= 0x100 - 0x60)
    {
        for (i = 0; i < (int)NELEMS(gMonIconPaletteTable); i++)
        {
            LoadPalette(gMonIconPaletteTable[i].data, offset, 0x20);
            offset += 0x10;
        }
    }
}

const u16 *GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = SPECIES_NONE;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = SPECIES_NONE;
    return gMonIconPaletteIndices[species];
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gMonIconPaletteIndices[species];
}

u8 UpdateMonIconFrame(struct Sprite * sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(const struct MonIconSpriteTemplate * iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void DestroyMonIconInternal(struct Sprite * sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite * sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
