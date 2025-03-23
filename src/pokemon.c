#define IS_POKEMON_C

#include "global.h"
#include "gflib.h"
#include "random.h"
#include "text.h"
#include "data.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "item.h"
#include "event_data.h"
#include "util.h"
#include "pokemon_storage_system.h"
#include "battle_gfx_sfx_util.h"
#include "battle_controllers.h"
#include "evolution_scene.h"
#include "battle_message.h"
#include "battle_util.h"
#include "link.h"
#include "m4a.h"
#include "pokedex.h"
#include "strings.h"
#include "overworld.h"
#include "party_menu.h"
#include "field_specials.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/hoenn_cries.h"
#include "constants/pokemon.h"
#include "constants/abilities.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/item_effects.h"
#include "constants/trainers.h"
#include "constants/hold_effects.h"
#include "constants/battle_move_effects.h"

#define SPECIES_TO_NATIONAL(name)   [SPECIES_##name - 1] = NATIONAL_DEX_##name

struct OakSpeechNidoranFStruct
{
    u8 spriteCount:4;
    u8 battlePosition:4;
    u8 frameCount;
    u8 enable;
    bool8 enable2;
    u32 sizePerSprite;
    u8 *dataBuffer;
    u8 **bufferPtrs;
    struct SpriteTemplate *templates;
    struct SpriteFrameImage *frameImages;
};

static EWRAM_DATA u8 sLearningMoveTableID = 0;
EWRAM_DATA u8 gPlayerPartyCount = 0;
EWRAM_DATA u8 gEnemyPartyCount = 0;
EWRAM_DATA struct Pokemon gEnemyParty[PARTY_SIZE] = {};
EWRAM_DATA struct Pokemon gPlayerParty[PARTY_SIZE] = {};
EWRAM_DATA struct SpriteTemplate gMultiuseSpriteTemplate = {0};
static EWRAM_DATA struct OakSpeechNidoranFStruct *sOakSpeechNidoranResources = NULL;

static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType);
static bool8 IsShinyOtIdPersonality(u32 otId, u32 personality);
static bool8 PartyMonHasStatus(struct Pokemon *mon, u32 unused, u32 healMask, u8 battleId);
static bool8 HealStatusConditions(struct Pokemon *mon, u32 unused, u32 healMask, u8 battleId);
static bool8 IsPokemonStorageFull(void);
static u8 SendMonToPC(struct Pokemon* mon);
static void EncryptBoxMon(struct BoxPokemon *boxMon);
static void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move);
static void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
static u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move);
static u8 GetLevelFromMonExp(struct Pokemon *mon);
static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon);

#include "data/battle_moves.h"
#include "data/pokemon/egg_moves.h"
#include "data/pokemon/egg_move_pointers.h"

// Used in an unreferenced function in RS.
// Unreferenced here and in Emerald.
struct CombinedMove
{
    u16 move1;
    u16 move2;
    u16 newMove;
};

static const struct CombinedMove sCombinedMoves[2] =
{
    {MOVE_EMBER, MOVE_GUST, MOVE_HEAT_WAVE},
    {0xFFFF, 0xFFFF, 0xFFFF}
};

static const u16 sSpeciesToNationalPokedexNum[] = // Assigns all species to the National Dex Index (Summary No. for National Dex)
{
    NATIONAL_DEX_CREIMU,
    NATIONAL_DEX_REIMU,
    NATIONAL_DEX_AREIMU,
    NATIONAL_DEX_DREIMU,
    NATIONAL_DEX_CMARISA,
    NATIONAL_DEX_MARISA,
    NATIONAL_DEX_AMARISA,
    NATIONAL_DEX_SMARISA,
    NATIONAL_DEX_ADMARISA,
    NATIONAL_DEX_CRUMIA,
    NATIONAL_DEX_RUMIA,
    NATIONAL_DEX_ARUMIA,
    NATIONAL_DEX_SRUMIA,
    NATIONAL_DEX_CDAIYOUSEI,
    NATIONAL_DEX_DAIYOUSEI,
    NATIONAL_DEX_ADAIYOUSEI,
    NATIONAL_DEX_DDAIYOUSEI,
    NATIONAL_DEX_CCIRNO,
    NATIONAL_DEX_CIRNO,
    NATIONAL_DEX_SCIRNO,
    NATIONAL_DEX_TCIRNO,
    NATIONAL_DEX_ADCIRNO,
    NATIONAL_DEX_CMEILING,
    NATIONAL_DEX_MEILING,
    NATIONAL_DEX_DMEILING,
    NATIONAL_DEX_SMEILING,
    NATIONAL_DEX_ADMEILING,
    NATIONAL_DEX_CKOAKUMA,
    NATIONAL_DEX_KOAKUMA,
    NATIONAL_DEX_HKOAKUMA,
    NATIONAL_DEX_CPATCHOULI,
    NATIONAL_DEX_PATCHOULI,
    NATIONAL_DEX_APATCHOULI,
    NATIONAL_DEX_DPATCHOULI,
    NATIONAL_DEX_CSAKUYA,
    NATIONAL_DEX_SAKUYA,
    NATIONAL_DEX_TSAKUYA,
    NATIONAL_DEX_HSAKUYA,
    NATIONAL_DEX_CREMILIA,
    NATIONAL_DEX_REMILIA,
    NATIONAL_DEX_AREMILIA,
    NATIONAL_DEX_DREMILIA,
    NATIONAL_DEX_CFLANDRE,
    NATIONAL_DEX_FLANDRE,
    NATIONAL_DEX_AFLANDRE,
    NATIONAL_DEX_SFLANDRE,
    NATIONAL_DEX_CLETTY,
    NATIONAL_DEX_LETTY,
    NATIONAL_DEX_DLETTY,
    NATIONAL_DEX_HLETTY,
    NATIONAL_DEX_ADLETTY,
    NATIONAL_DEX_CCHEN,
    NATIONAL_DEX_CHEN,
    NATIONAL_DEX_ACHEN,
    NATIONAL_DEX_TCHEN,
    NATIONAL_DEX_ADCHEN,
    NATIONAL_DEX_CALICE,
    NATIONAL_DEX_ALICE,
    NATIONAL_DEX_AALICE,
    NATIONAL_DEX_TALICE,
    NATIONAL_DEX_ADALICE,
    NATIONAL_DEX_DARK_ALICE,
    NATIONAL_DEX_CLILYWHITE,
    NATIONAL_DEX_LILYWHITE,
    NATIONAL_DEX_ALILYWHITE,
    NATIONAL_DEX_HLILYWHITE,
    NATIONAL_DEX_CLILYBLACK,
    NATIONAL_DEX_LILYBLACK,
    NATIONAL_DEX_ALILYBLACK,
    NATIONAL_DEX_SLILYBLACK,
    NATIONAL_DEX_CLUNASA,
    NATIONAL_DEX_LUNASA,
    NATIONAL_DEX_HLUNASA,
    NATIONAL_DEX_CMERLIN,
    NATIONAL_DEX_MERLIN,
    NATIONAL_DEX_HMERLIN,
    NATIONAL_DEX_CLYRICA,
    NATIONAL_DEX_LYRICA,
    NATIONAL_DEX_HLYRICA,
    NATIONAL_DEX_CYOUMU,
    NATIONAL_DEX_YOUMU,
    NATIONAL_DEX_AYOUMU,
    NATIONAL_DEX_DYOUMU,
    NATIONAL_DEX_SYOUMU,
    NATIONAL_DEX_CYUYUKO,
    NATIONAL_DEX_YUYUKO,
    NATIONAL_DEX_AYUYUKO,
    NATIONAL_DEX_DYUYUKO,
    NATIONAL_DEX_CRAN,
    NATIONAL_DEX_RAN,
    NATIONAL_DEX_ARAN,
    NATIONAL_DEX_HRAN,
    NATIONAL_DEX_ADRAN,
    NATIONAL_DEX_CYUKARI,
    NATIONAL_DEX_YUKARI,
    NATIONAL_DEX_DYUKARI,
    NATIONAL_DEX_TYUKARI,
    NATIONAL_DEX_ADYUKARI,
    NATIONAL_DEX_CSUIKA,
    NATIONAL_DEX_SUIKA,
    NATIONAL_DEX_ASUIKA,
    NATIONAL_DEX_TSUIKA,
    NATIONAL_DEX_MPSUIKA,
    NATIONAL_DEX_CWRIGGLE,
    NATIONAL_DEX_WRIGGLE,
    NATIONAL_DEX_DWRIGGLE,
    NATIONAL_DEX_SWRIGGLE,
    NATIONAL_DEX_CMYSTIA,
    NATIONAL_DEX_MYSTIA,
    NATIONAL_DEX_AMYSTIA,
    NATIONAL_DEX_HMYSTIA,
    NATIONAL_DEX_ADMYSTIA,
    NATIONAL_DEX_CKEINE,
    NATIONAL_DEX_KEINE,
    NATIONAL_DEX_AKEINE,
    NATIONAL_DEX_DKEINE,
    NATIONAL_DEX_HKEINE,
    NATIONAL_DEX_CTEWI,
    NATIONAL_DEX_TEWI,
    NATIONAL_DEX_ATEWI,
    NATIONAL_DEX_DTEWI,
    NATIONAL_DEX_ADTEWI,
    NATIONAL_DEX_CREISEN,
    NATIONAL_DEX_REISEN,
    NATIONAL_DEX_DREISEN,
    NATIONAL_DEX_TREISEN,
    NATIONAL_DEX_ADREISEN,
    NATIONAL_DEX_CEIRIN,
    NATIONAL_DEX_EIRIN,
    NATIONAL_DEX_AEIRIN,
    NATIONAL_DEX_HEIRIN,
    NATIONAL_DEX_CKAGUYA,
    NATIONAL_DEX_KAGUYA,
    NATIONAL_DEX_AKAGUYA,
    NATIONAL_DEX_DKAGUYA,
    NATIONAL_DEX_CMOKOU,
    NATIONAL_DEX_MOKOU,
    NATIONAL_DEX_AMOKOU,
    NATIONAL_DEX_DMOKOU,
    NATIONAL_DEX_ADMOKOU,
    NATIONAL_DEX_CAYA,
    NATIONAL_DEX_AYA,
    NATIONAL_DEX_SAYA,
    NATIONAL_DEX_TAYA,
    NATIONAL_DEX_CMEDICINE,
    NATIONAL_DEX_MEDICINE,
    NATIONAL_DEX_AMEDICINE,
    NATIONAL_DEX_SMEDICINE,
    NATIONAL_DEX_TMEDICINE,
    NATIONAL_DEX_CYUUKA,
    NATIONAL_DEX_YUUKA,
    NATIONAL_DEX_AYUUKA,
    NATIONAL_DEX_TYUUKA,
    NATIONAL_DEX_CKOMACHI,
    NATIONAL_DEX_KOMACHI,
    NATIONAL_DEX_AKOMACHI,
    NATIONAL_DEX_SKOMACHI,
    NATIONAL_DEX_CEIKI,
    NATIONAL_DEX_EIKI,
    NATIONAL_DEX_AEIKI,
    NATIONAL_DEX_DEIKI,
    NATIONAL_DEX_AKYUU,
    NATIONAL_DEX_CSHIZUHA,
    NATIONAL_DEX_SHIZUHA,
    NATIONAL_DEX_SSHIZUHA,
    NATIONAL_DEX_HSHIZUHA,
    NATIONAL_DEX_CMINORIKO,
    NATIONAL_DEX_MINORIKO,
    NATIONAL_DEX_AMINORIKO,
    NATIONAL_DEX_DMINORIKO,
    NATIONAL_DEX_AKI_SISTERS,
    NATIONAL_DEX_CHINA,
    NATIONAL_DEX_HINA,
    NATIONAL_DEX_AHINA,
    NATIONAL_DEX_DHINA,
    NATIONAL_DEX_CNITORI,
    NATIONAL_DEX_NITORI,
    NATIONAL_DEX_ANITORI,
    NATIONAL_DEX_TNITORI,
    NATIONAL_DEX_CMOMIJI,
    NATIONAL_DEX_MOMIJI,
    NATIONAL_DEX_DMOMIJI,
    NATIONAL_DEX_CSANAE,
    NATIONAL_DEX_SANAE,
    NATIONAL_DEX_ASANAE,
    NATIONAL_DEX_TSANAE,
    NATIONAL_DEX_JKSANAE,
    NATIONAL_DEX_CKANAKO,
    NATIONAL_DEX_KANAKO,
    NATIONAL_DEX_AKANAKO,
    NATIONAL_DEX_DKANAKO,
    NATIONAL_DEX_CSUWAKO,
    NATIONAL_DEX_SUWAKO,
    NATIONAL_DEX_ASUWAKO,
    NATIONAL_DEX_DSUWAKO,
    NATIONAL_DEX_CREISEN_II,
    NATIONAL_DEX_REISEN_II,
    NATIONAL_DEX_CTOYOHIME,
    NATIONAL_DEX_TOYOHIME,
    NATIONAL_DEX_TTOYOHIME,
    NATIONAL_DEX_CYORIHIME,
    NATIONAL_DEX_YORIHIME,
    NATIONAL_DEX_SYORIHIME,
    NATIONAL_DEX_CIKU,
    NATIONAL_DEX_IKU,
    NATIONAL_DEX_DIKU,
    NATIONAL_DEX_TIKU,
    NATIONAL_DEX_CTENSHI,
    NATIONAL_DEX_TENSHI,
    NATIONAL_DEX_ATENSHI,
    NATIONAL_DEX_DTENSHI,
    NATIONAL_DEX_CKISUME,
    NATIONAL_DEX_KISUME,
    NATIONAL_DEX_TKISUME,
    NATIONAL_DEX_CYAMAME,
    NATIONAL_DEX_YAMAME,
    NATIONAL_DEX_SYAMAME,
    NATIONAL_DEX_TYAMAME,
    NATIONAL_DEX_CPARSEE,
    NATIONAL_DEX_PARSEE,
    NATIONAL_DEX_DPARSEE,
    NATIONAL_DEX_TPARSEE,
    NATIONAL_DEX_CYUUGI,
    NATIONAL_DEX_YUUGI,
    NATIONAL_DEX_AYUUGI,
    NATIONAL_DEX_DYUUGI,
    NATIONAL_DEX_CSATORI,
    NATIONAL_DEX_SATORI,
    NATIONAL_DEX_DSATORI,
    NATIONAL_DEX_TSATORI,
    NATIONAL_DEX_CRIN,
    NATIONAL_DEX_RIN,
    NATIONAL_DEX_ARIN,
    NATIONAL_DEX_SRIN,
    NATIONAL_DEX_ZFAIRY,
    NATIONAL_DEX_CUTSUHO,
    NATIONAL_DEX_UTSUHO,
    NATIONAL_DEX_AUTSUHO,
    NATIONAL_DEX_SUTSUHO,
    NATIONAL_DEX_CKOISHI,
    NATIONAL_DEX_KOISHI,
    NATIONAL_DEX_AKOISHI,
    NATIONAL_DEX_SKOISHI,
    NATIONAL_DEX_CNAZRIN,
    NATIONAL_DEX_NAZRIN,
    NATIONAL_DEX_TNAZRIN,
    NATIONAL_DEX_HNAZRIN,
    NATIONAL_DEX_CKOGASA,
    NATIONAL_DEX_KOGASA,
    NATIONAL_DEX_SKOGASA,
    NATIONAL_DEX_TKOGASA,
    NATIONAL_DEX_CICHIRIN,
    NATIONAL_DEX_ICHIRIN,
    NATIONAL_DEX_DICHIRIN,
    NATIONAL_DEX_TICHIRIN,
    NATIONAL_DEX_CMURASA,
    NATIONAL_DEX_MURASA,
    NATIONAL_DEX_AMURASA,
    NATIONAL_DEX_DMURASA,
    NATIONAL_DEX_CSHOU,
    NATIONAL_DEX_SHOU,
    NATIONAL_DEX_ASHOU,
    NATIONAL_DEX_TSHOU,
    NATIONAL_DEX_CBYAKUREN,
    NATIONAL_DEX_BYAKUREN,
    NATIONAL_DEX_HBYAKUREN,
    NATIONAL_DEX_TBYAKUREN,
    NATIONAL_DEX_CNUE,
    NATIONAL_DEX_NUE,
    NATIONAL_DEX_ANUE,
    NATIONAL_DEX_TNUE,
    NATIONAL_DEX_TENSOKU,
    NATIONAL_DEX_SHANGHAI,
    NATIONAL_DEX_HOURAI,
    NATIONAL_DEX_GOLIATH,
    NATIONAL_DEX_NAMAZU,
    NATIONAL_DEX_CHATATE,
    NATIONAL_DEX_HATATE,
    NATIONAL_DEX_DHATATE,
    NATIONAL_DEX_THATATE,
    NATIONAL_DEX_CSUNNY,
    NATIONAL_DEX_SUNNY,
    NATIONAL_DEX_ASUNNY,
    NATIONAL_DEX_DSUNNY,
    NATIONAL_DEX_CLUNA,
    NATIONAL_DEX_LUNA,
    NATIONAL_DEX_ALUNA,
    NATIONAL_DEX_TLUNA,
    NATIONAL_DEX_CSTAR,
    NATIONAL_DEX_STAR,
    NATIONAL_DEX_ASTAR,
    NATIONAL_DEX_HSTAR,
    NATIONAL_DEX_RINNOSUKE,
    NATIONAL_DEX_CTOKIKO,
    NATIONAL_DEX_TOKIKO,
    NATIONAL_DEX_ATOKIKO,
    NATIONAL_DEX_CKYOUKO,
    NATIONAL_DEX_KYOUKO,
    NATIONAL_DEX_TKYOUKO,
    NATIONAL_DEX_CYOSHIKA,
    NATIONAL_DEX_YOSHIKA,
    NATIONAL_DEX_HYOSHIKA,
    NATIONAL_DEX_CSEIGA,
    NATIONAL_DEX_SEIGA,
    NATIONAL_DEX_SSEIGA,
    NATIONAL_DEX_CTOJIKO,
    NATIONAL_DEX_TOJIKO,
    NATIONAL_DEX_STOJIKO,
    NATIONAL_DEX_CFUTO,
    NATIONAL_DEX_FUTO,
    NATIONAL_DEX_AFUTO,
    NATIONAL_DEX_TFUTO,
    NATIONAL_DEX_CMIKO,
    NATIONAL_DEX_MIKO,
    NATIONAL_DEX_AMIKO,
    NATIONAL_DEX_DMIKO,
    NATIONAL_DEX_CMAMIZOU,
    NATIONAL_DEX_MAMIZOU,
    NATIONAL_DEX_DMAMIZOU,
    NATIONAL_DEX_CKOSUZU,
    NATIONAL_DEX_KOSUZU,
    NATIONAL_DEX_JINYOU,
    NATIONAL_DEX_CKOKORO,
    NATIONAL_DEX_KOKORO,
    NATIONAL_DEX_AKOKORO,
    NATIONAL_DEX_TKOKORO,
    NATIONAL_DEX_CWAKASAGIHIME,
    NATIONAL_DEX_WAKASAGIHIME,
    NATIONAL_DEX_DWAKASAGIHIME,
    NATIONAL_DEX_CSEKIBANKI,
    NATIONAL_DEX_SEKIBANKI,
    NATIONAL_DEX_TSEKIBANKI,
    NATIONAL_DEX_CKAGEROU,
    NATIONAL_DEX_KAGEROU,
    NATIONAL_DEX_HKAGEROU,
    NATIONAL_DEX_CBENBEN,
    NATIONAL_DEX_BENBEN,
    NATIONAL_DEX_CYATSUHASHI,
    NATIONAL_DEX_YATSUHASHI,
    NATIONAL_DEX_CSEIJA,
    NATIONAL_DEX_SEIJA,
    NATIONAL_DEX_DSEIJA,
    NATIONAL_DEX_CSHINMYOUMARU,
    NATIONAL_DEX_SHINMYOUMARU,
    NATIONAL_DEX_ASHINMYOUMARU,
    NATIONAL_DEX_CRAIKO,
    NATIONAL_DEX_RAIKO,
    NATIONAL_DEX_ARAIKO,
    NATIONAL_DEX_CKASEN,
    NATIONAL_DEX_KASEN,
    NATIONAL_DEX_HKASEN,
    NATIONAL_DEX_CSUMIREKO,
    NATIONAL_DEX_SUMIREKO,
    NATIONAL_DEX_SSUMIREKO,
    NATIONAL_DEX_TSUMIREKO,
    NATIONAL_DEX_CSEIRAN,
    NATIONAL_DEX_SEIRAN,
    NATIONAL_DEX_CRINGO,
    NATIONAL_DEX_RINGO,
    NATIONAL_DEX_CDOREMY,
    NATIONAL_DEX_DOREMY,
    NATIONAL_DEX_CSAGUME,
    NATIONAL_DEX_SAGUME,
    NATIONAL_DEX_CCLOWNPIECE,
    NATIONAL_DEX_CLOWNPIECE,
    NATIONAL_DEX_CJUNKO,
    NATIONAL_DEX_JUNKO,
    NATIONAL_DEX_CHECATIA,
    NATIONAL_DEX_HECATIA,
    NATIONAL_DEX_CJOON,
    NATIONAL_DEX_JOON,
    NATIONAL_DEX_CSHION,
    NATIONAL_DEX_SHION,
    NATIONAL_DEX_CETERNITY,
    NATIONAL_DEX_ETERNITY,
    NATIONAL_DEX_CNEMUNO,
    NATIONAL_DEX_NEMUNO,
    NATIONAL_DEX_CAUNN,
    NATIONAL_DEX_AUNN,
    NATIONAL_DEX_CNARUMI,
    NATIONAL_DEX_NARUMI,
    NATIONAL_DEX_ANARUMI,
    NATIONAL_DEX_CMAI_AND_SATONO,
    NATIONAL_DEX_MAI_AND_SATONO,
    NATIONAL_DEX_COKINA,
    NATIONAL_DEX_OKINA,
    NATIONAL_DEX_CEIKA,
    NATIONAL_DEX_EIKA,
    NATIONAL_DEX_CURUMI,
    NATIONAL_DEX_URUMI,
    NATIONAL_DEX_CKUTAKA,
    NATIONAL_DEX_KUTAKA,
    NATIONAL_DEX_CYACHIE,
    NATIONAL_DEX_YACHIE,
    NATIONAL_DEX_CMAYUMI,
    NATIONAL_DEX_MAYUMI,
    NATIONAL_DEX_CKEIKI,
    NATIONAL_DEX_KEIKI,
    NATIONAL_DEX_CSAKI,
    NATIONAL_DEX_SAKI,
    NATIONAL_DEX_CYUUMA,
    NATIONAL_DEX_YUUMA,
    NATIONAL_DEX_CMIKE,
    NATIONAL_DEX_MIKE,
    NATIONAL_DEX_CTAKANE,
    NATIONAL_DEX_TAKANE,
    NATIONAL_DEX_CSANNYO,
    NATIONAL_DEX_SANNYO,
    NATIONAL_DEX_CMISUMARU,
    NATIONAL_DEX_MISUMARU,
    NATIONAL_DEX_CTSUKASA,
    NATIONAL_DEX_TSUKASA,
    NATIONAL_DEX_CMEGUMU,
    NATIONAL_DEX_MEGUMU,
    NATIONAL_DEX_CCHIMATA,
    NATIONAL_DEX_CHIMATA,
    NATIONAL_DEX_CMOMOYO,
    NATIONAL_DEX_MOMOYO,
    NATIONAL_DEX_CMIYOI,
    NATIONAL_DEX_MIYOI,
    NATIONAL_DEX_CMIZUCHI,
    NATIONAL_DEX_MIZUCHI,
    NATIONAL_DEX_CBITEN,
    NATIONAL_DEX_BITEN,
    NATIONAL_DEX_CENOKO,
    NATIONAL_DEX_ENOKO,
    NATIONAL_DEX_CCHIYARI,
    NATIONAL_DEX_CHIYARI,
    NATIONAL_DEX_CHISAMI,
    NATIONAL_DEX_HISAMI,
    NATIONAL_DEX_CZANMU,
    NATIONAL_DEX_ZANMU,
    NATIONAL_DEX_CHAKUREI,
    NATIONAL_DEX_HAKUREI,
    NATIONAL_DEX_CKIRISAME,
    NATIONAL_DEX_KIRISAME,
    NATIONAL_DEX_CSHINGYOKU,
    NATIONAL_DEX_SHINGYOKUF,
    NATIONAL_DEX_SHINGYOKUM,
    NATIONAL_DEX_SHINGYOKUO,
    NATIONAL_DEX_CMAGAN,
    NATIONAL_DEX_MAGAN,
    NATIONAL_DEX_CMIMA,
    NATIONAL_DEX_MIMA,
    NATIONAL_DEX_CELIS,
    NATIONAL_DEX_ELIS,
    NATIONAL_DEX_CKIKURI,
    NATIONAL_DEX_KIKURI,
    NATIONAL_DEX_CKONNGARA,
    NATIONAL_DEX_KONNGARA,
    NATIONAL_DEX_CSARIEL,
    NATIONAL_DEX_SARIEL,
    NATIONAL_DEX_SSARIEL,
    NATIONAL_DEX_GENJI,
    NATIONAL_DEX_CRIKA,
    NATIONAL_DEX_RIKA,
    NATIONAL_DEX_TRIKA,
    NATIONAL_DEX_CMEIRA,
    NATIONAL_DEX_MEIRA,
    NATIONAL_DEX_MAGIC_STONES,
    NATIONAL_DEX_CELLEN,
    NATIONAL_DEX_ELLEN,
    NATIONAL_DEX_CKOTOHIME,
    NATIONAL_DEX_KOTOHIME,
    NATIONAL_DEX_CKANA,
    NATIONAL_DEX_KANA,
    NATIONAL_DEX_CRIKAKO,
    NATIONAL_DEX_RIKAKO,
    NATIONAL_DEX_CCHIYURI,
    NATIONAL_DEX_CHIYURI,
    NATIONAL_DEX_CYUMEMI,
    NATIONAL_DEX_YUMEMI,
    NATIONAL_DEX_TYUMEMI,
    NATIONAL_DEX_RUUKOTO,
    NATIONAL_DEX_MIMI_CHAN,
    NATIONAL_DEX_CORANGE,
    NATIONAL_DEX_ORANGE,
    NATIONAL_DEX_CKURUMI,
    NATIONAL_DEX_KURUMI,
    NATIONAL_DEX_CELLY,
    NATIONAL_DEX_ELLY,
    NATIONAL_DEX_CKAZAMI,
    NATIONAL_DEX_KAZAMI,
    NATIONAL_DEX_AKAZAMI,
    NATIONAL_DEX_CMUGETSU,
    NATIONAL_DEX_MUGETSU,
    NATIONAL_DEX_CGENGETSU,
    NATIONAL_DEX_GENGETSU,
    NATIONAL_DEX_CSARA,
    NATIONAL_DEX_SARA,
    NATIONAL_DEX_CLOUISE,
    NATIONAL_DEX_LOUISE,
    NATIONAL_DEX_CARISU,
    NATIONAL_DEX_ARISU,
    NATIONAL_DEX_CYUKI,
    NATIONAL_DEX_YUKI,
    NATIONAL_DEX_CMAI,
    NATIONAL_DEX_MAI,
    NATIONAL_DEX_CYUMEKO,
    NATIONAL_DEX_YUMEKO,
    NATIONAL_DEX_CSHINKI,
    NATIONAL_DEX_SHINKI,
    NATIONAL_DEX_ASHINKI,
    NATIONAL_DEX_CSENDAI,
    NATIONAL_DEX_SENDAI,
    NATIONAL_DEX_CTENMA,
    NATIONAL_DEX_TENMA,
    NATIONAL_DEX_CLAYLA,
    NATIONAL_DEX_LAYLA,
    NATIONAL_DEX_DLAYLA,
    NATIONAL_DEX_CYOUKI,
    NATIONAL_DEX_YOUKI,
    NATIONAL_DEX_TORI,
    NATIONAL_DEX_2HU,
	NATIONAL_DEX_CRENKO,
	NATIONAL_DEX_TRRENKO,
	NATIONAL_DEX_CMARIBEL,
	NATIONAL_DEX_TRMARIBEL,
    NATIONAL_DEX_XSUWAKO,
    NATIONAL_DEX_XUTSUHO,
    NATIONAL_DEX_XTENSHI,
    NATIONAL_DEX_XTENMA,
    NATIONAL_DEX_XSENDAI,
    NATIONAL_DEX_TSEKIBANKI,
	NATIONAL_DEX_TENSOKU,
};

#include "data/pokemon/item_effects.h"

const s8 gNatureStatTable[][5] =
{
    // Atk Def Spd Sp.Atk Sp.Def
    {    0,  0,  0,     0,     0}, // Hardy
    {   +1, -1,  0,     0,     0}, // Lonely
    {   +1,  0, -1,     0,     0}, // Brave
    {   +1,  0,  0,    -1,     0}, // Adamant
    {   +1,  0,  0,     0,    -1}, // Naughty
    {   -1, +1,  0,     0,     0}, // Bold
    {    0,  0,  0,     0,     0}, // Docile
    {    0, +1, -1,     0,     0}, // Relaxed
    {    0, +1,  0,    -1,     0}, // Impish
    {    0, +1,  0,     0,    -1}, // Lax
    {   -1,  0, +1,     0,     0}, // Timid
    {    0, -1, +1,     0,     0}, // Hasty
    {    0,  0,  0,     0,     0}, // Serious
    {    0,  0, +1,    -1,     0}, // Jolly
    {    0,  0, +1,     0,    -1}, // Naive
    {   -1,  0,  0,    +1,     0}, // Modest
    {    0, -1,  0,    +1,     0}, // Mild
    {    0,  0, -1,    +1,     0}, // Quiet
    {    0,  0,  0,     0,     0}, // Bashful
    {    0,  0,  0,    +1,    -1}, // Rash
    {   -1,  0,  0,     0,    +1}, // Calm
    {    0, -1,  0,     0,    +1}, // Gentle
    {    0,  0, -1,     0,    +1}, // Sassy
    {    0,  0,  0,    -1,    +1}, // Careful
    {    0,  0,  0,     0,     0}, // Quirky
};

#include "data/pokemon/tmhm_learnsets.h"
#include "data/pokemon/trainer_class_lookups.h"
#include "data/pokemon/cry_ids.h"
#include "data/pokemon/experience_tables.h"
#include "data/pokemon/base_stats.h"
#include "data/pokemon/level_up_learnsets.h"
#include "data/pokemon/evolution.h"
#include "data/pokemon/level_up_learnset_pointers.h"

static const s8 sPokeblockFlavorCompatibilityTable[] =
{
    // Cool, Beauty, Cute, Smart, Tough
          0,      0,    0,     0,     0, // Hardy
          1,      0,    0,     0,    -1, // Lonely
          1,      0,   -1,     0,     0, // Brave
          1,     -1,    0,     0,     0, // Adamant
          1,      0,    0,    -1,     0, // Naughty
         -1,      0,    0,     0,     1, // Bold
          0,      0,    0,     0,     0, // Docile
          0,      0,   -1,     0,     1, // Relaxed
          0,     -1,    0,     0,     1, // Impish
          0,      0,    0,    -1,     1, // Lax
         -1,      0,    1,     0,     0, // Timid
          0,      0,    1,     0,    -1, // Hasty
          0,      0,    0,     0,     0, // Serious
          0,     -1,    1,     0,     0, // Jolly
          0,      0,    1,    -1,     0, // Naive
         -1,      1,    0,     0,     0, // Modest
          0,      1,    0,     0,    -1, // Mild
          0,      1,   -1,     0,     0, // Quiet
          0,      0,    0,     0,     0, // Bashful
          0,      1,    0,    -1,     0, // Rash
         -1,      0,    0,     1,     0, // Calm
          0,      0,    0,     1,    -1, // Gentle
          0,      0,   -1,     1,     0, // Sassy
          0,     -1,    0,     1,     0, // Careful
          0,      0,    0,     0,     0  // Quirky
};

const u8 gPPUpGetMask[] = { 0x03, 0x0c, 0x30, 0xc0 }; // Masks for getting PP Up count, also PP Max values

const u8 gPPUpSetMask[] = { 0xfc, 0xf3, 0xcf, 0x3f }; // Masks for setting PP Up count

const u8 gPPUpAddMask[] = { 0x01, 0x04, 0x10, 0x40 }; // Values added to PP Up count

const u8 gStatStageRatios[][2] =
{
    { 10, 40 },
    { 10, 35 },
    { 10, 30 },
    { 10, 25 },
    { 10, 20 }, 
    { 10, 15 },
    { 10, 10 },
    { 15, 10 },
    { 20, 10 },
    { 25, 10 },
    { 30, 10 },
    { 35, 10 },
    { 40, 10 },
    { 138, 174 },
    { 108, 120 },
};

static const u8 sFiller = _("");

static const u8 sHoldEffectToType[][2] = 
{
    {HOLD_EFFECT_HEART_POWER, TYPE_HEART},
    {HOLD_EFFECT_STEEL_POWER, TYPE_STEEL},
    {HOLD_EFFECT_EARTH_POWER, TYPE_EARTH},
    {HOLD_EFFECT_BEAST_POWER, TYPE_BEAST},
    {HOLD_EFFECT_GRASS_POWER, TYPE_GRASS},
    {HOLD_EFFECT_DARK_POWER, TYPE_DARK},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_FIGHTING},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELECTRIC},
    {HOLD_EFFECT_WATER_POWER, TYPE_WATER},
    {HOLD_EFFECT_WIND_POWER, TYPE_WIND},
    {HOLD_EFFECT_MIASMA_POWER, TYPE_MIASMA},
    {HOLD_EFFECT_ICE_POWER, TYPE_ICE},
    {HOLD_EFFECT_GHOST_POWER, TYPE_GHOST},
    {HOLD_EFFECT_REASON_POWER, TYPE_REASON},
    {HOLD_EFFECT_FIRE_POWER, TYPE_FIRE},
    {HOLD_EFFECT_FAITH_POWER, TYPE_FAITH},
    {HOLD_EFFECT_ILLUSION_POWER, TYPE_ILLUSION},
    {HOLD_EFFECT_NORMAL_POWER, TYPE_NORMAL},
};

const struct SpriteTemplate gSpriteTemplates_Battlers[] = 
{
    [B_POSITION_PLAYER_LEFT] = {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gSpriteImages_BattlerPlayerLeft,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    [B_POSITION_OPPONENT_LEFT] = {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerOpponent,
        .anims = NULL, 
        .images = gSpriteImages_BattlerOpponentLeft,
        .affineAnims = gSpriteAffineAnimTable_BattlerOpponent,
        .callback = SpriteCB_EnemyMon,
    },
    [B_POSITION_PLAYER_RIGHT] = {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gSpriteImages_BattlerPlayerRight,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    [B_POSITION_OPPONENT_RIGHT] = {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerOpponent,
        .anims = NULL, 
        .images = gSpriteImages_BattlerOpponentRight,
        .affineAnims = gSpriteAffineAnimTable_BattlerOpponent,
        .callback = SpriteCB_EnemyMon,
    },
};

const struct SpriteTemplate gSpriteTemplates_TrainerBackpics[] = 
{
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_Red,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_Leaf,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_RSBrendan,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_RSMay,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_Pokedude,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
    {
        .tileTag = SPRITE_INVALID_TAG,
        .paletteTag = 0,
        .oam = &gOamData_BattlerPlayer,
        .anims = NULL, 
        .images = gTrainerBackPicTable_OldMan,
        .affineAnims = gSpriteAffineAnimTable_BattlerPlayer,
        .callback = SpriteCB_AllyMon,
    },
};

// Classes dummied out
static const u8 sSecretBaseFacilityClasses[][5] = 
{
    [MALE] = {
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER
    },
    [FEMALE] = {
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_YOUNGSTER
    },
};

static const u8 sGetMonDataEVConstants[] = 
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPATK_EV
};

static const u8 sGetMonDataIVConstants[] = 
{
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPEED_IV,
    MON_DATA_SPDEF_IV,
    MON_DATA_SPATK_IV
};

static const u8 sStatsToRaise[] = 
{
    STAT_ATK, STAT_ATK, STAT_SPEED, STAT_DEF, STAT_SPATK, STAT_ACC
};

static const s8 sFriendshipEventDeltas[][3] = 
{
    [FRIENDSHIP_EVENT_GROW_LEVEL]           = { 5,  3,  2 },
    [FRIENDSHIP_EVENT_VITAMIN]              = { 5,  3,  2 },
    [FRIENDSHIP_EVENT_BATTLE_ITEM]          = { 1,  1,  0 },
    [FRIENDSHIP_EVENT_LEAGUE_BATTLE]        = { 3,  2,  1 },
    [FRIENDSHIP_EVENT_LEARN_TMHM]           = { 1,  1,  0 },
    [FRIENDSHIP_EVENT_WALKING]              = { 1,  1,  1 },
    [FRIENDSHIP_EVENT_MASSAGE]              = { 3,  3,  3 },
    [FRIENDSHIP_EVENT_FAINT_SMALL]          = {-1, -1, -1 },
    [FRIENDSHIP_EVENT_FAINT_OUTSIDE_BATTLE] = {-5, -5, -10 },
    [FRIENDSHIP_EVENT_FAINT_LARGE]          = {-5, -5, -10 },
};

static const u16 sHMMoves[] = 
{
    MOVE_CUT, MOVE_FLY, MOVE_SURF, MOVE_STRENGTH, MOVE_FLASH,
    MOVE_ROCK_SMASH, MOVE_WATERFALL, 0xFFFF
};

const u16 gLinkPlayerFacilityClasses[] = 
{
    // Male
    FACILITY_CLASS_COOLTRAINER_M,
    FACILITY_CLASS_BLACK_BELT,
    FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_YOUNGSTER,
    FACILITY_CLASS_PSYCHIC_M,
    FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_TAMER,
    FACILITY_CLASS_JUGGLER,
    // Female
    FACILITY_CLASS_COOLTRAINER_F,
    FACILITY_CLASS_CHANNELER,
    FACILITY_CLASS_PICNICKER,
    FACILITY_CLASS_LASS,
    FACILITY_CLASS_PSYCHIC_F,
    FACILITY_CLASS_CRUSH_GIRL,
    FACILITY_CLASS_PKMN_BREEDER,
    FACILITY_CLASS_BEAUTY,
};

static const struct OamData sOakSpeechNidoranFDummyOamData = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteTemplate sOakSpeechNidoranFDummyTemplate = 
{
    .tileTag = SPRITE_INVALID_TAG,
    .paletteTag = SPRITE_INVALID_TAG,
    .oam = &sOakSpeechNidoranFDummyOamData,
    .anims = gDummySpriteAnimTable, 
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// code
void ZeroBoxMonData(struct BoxPokemon *boxMon)
{
    u8 *raw = (u8 *)boxMon;
    u32 i;
    for (i = 0; i < sizeof(struct BoxPokemon); i++)
        raw[i] = 0;
}

void ZeroMonData(struct Pokemon *mon)
{
    u32 arg;
    ZeroBoxMonData(&mon->box);
    arg = 0;
    SetMonData(mon, MON_DATA_STATUS, &arg);
    SetMonData(mon, MON_DATA_LEVEL, &arg);
    SetMonData(mon, MON_DATA_HP, &arg);
    SetMonData(mon, MON_DATA_MAX_HP, &arg);
    SetMonData(mon, MON_DATA_ATK, &arg);
    SetMonData(mon, MON_DATA_DEF, &arg);
    SetMonData(mon, MON_DATA_SPEED, &arg);
    SetMonData(mon, MON_DATA_SPATK, &arg);
    SetMonData(mon, MON_DATA_SPDEF, &arg);
    arg = 255;
    SetMonData(mon, MON_DATA_MAIL, &arg);
}

void ZeroPlayerPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);
}

void ZeroEnemyPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gEnemyParty[i]);
}

void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 arg;
    ZeroMonData(mon);
    CreateBoxMon(&mon->box, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    arg = 255;
    SetMonData(mon, MON_DATA_MAIL, &arg);
    CalculateMonStats(mon);
}

void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 personality;
    u32 value;
    u16 checksum;

    ZeroBoxMonData(boxMon);

    if (hasFixedPersonality)
        personality = fixedPersonality;
    else
        personality = Random32();

    SetBoxMonData(boxMon, MON_DATA_PERSONALITY, &personality);

    //Determine original trainer ID
    if (otIdType == OT_ID_RANDOM_NO_SHINY) //Pokemon cannot be shiny
    {
        u32 shinyValue;
        do
        {
            value = Random32();
            shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
        } while (shinyValue < SHINY_ODDS);
    }
    else if (otIdType == OT_ID_PRESET) //Pokemon has a preset OT ID
    {
        value = fixedOtId;
    }
    else //Player is the OT
    {
        value = gSaveBlock2Ptr->playerTrainerId[0]
              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    }

    SetBoxMonData(boxMon, MON_DATA_OT_ID, &value);

    checksum = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &checksum);
    EncryptBoxMon(boxMon);
    GetSpeciesName(speciesName, species);
    SetBoxMonData(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData(boxMon, MON_DATA_EXP, &gExperienceTables[gBaseStats[species].growthRate][level]);
    SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &gBaseStats[species].friendship);
    value = GetCurrentRegionMapSectionId();
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = ITEM_POKE_BALL;
    SetBoxMonData(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    if (fixedIV < 32)
    {
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &fixedIV);
    }
    else
    {
        u32 iv;
        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);

        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);
        
        if (Random() % 10 == 0)
        {
            iv = 1;
            SetBoxMonData(boxMon, MON_DATA_HIDDEN_ABILITY, &iv);
        }
    }

    if (gBaseStats[species].abilities[1])
    {
        value = personality & 1;
        SetBoxMonData(boxMon, MON_DATA_ABILITY_NUM, &value);
    }

    GiveBoxMonInitialMoveset(boxMon);
}

void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature)
{
    u32 personality;

    do
    {
        personality = Random32();
    }
    while (nature != GetNatureFromPersonality(personality));

    CreateMon(mon, species, level, fixedIV, 1, personality, OT_ID_PLAYER_ID, 0);
}

void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter)
{
    u32 personality;

    if ((u8)(unownLetter - 1) < 28)
    {
        u16 actualLetter;

        do
        {
            personality = Random32();
            actualLetter = ((((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 28);
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality)
            || actualLetter != unownLetter - 1);
    }
    else
    {
        do
        {
            personality = Random32();
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality));
    }

    CreateMon(mon, species, level, fixedIV, 1, personality, OT_ID_PLAYER_ID, 0);
}

// Used to create the Old Man's Weedle?
void CreateMaleMon(struct Pokemon *mon, u16 species, u8 level)
{
    u32 personality;
    u32 otId;

    do
    {
        otId = Random32();
        personality = Random32();
    }
    while (GetGenderFromSpeciesAndPersonality(species, personality) != MON_MALE);
    CreateMon(mon, species, level, 32, 1, personality, OT_ID_PRESET, otId);
}

void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality)
{
    CreateMon(mon, species, level, 0, 1, personality, OT_ID_PLAYER_ID, 0);
    SetMonData(mon, MON_DATA_IVS, &ivs);
    CalculateMonStats(mon);
}

static void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId)
{
    CreateMon(mon, species, level, 0, 0, 0, OT_ID_PRESET, otId);
    SetMonData(mon, MON_DATA_HP_IV, &ivs[0]);
    SetMonData(mon, MON_DATA_ATK_IV, &ivs[1]);
    SetMonData(mon, MON_DATA_DEF_IV, &ivs[2]);
    SetMonData(mon, MON_DATA_SPEED_IV, &ivs[3]);
    SetMonData(mon, MON_DATA_SPATK_IV, &ivs[4]);
    SetMonData(mon, MON_DATA_SPDEF_IV, &ivs[5]);
    CalculateMonStats(mon);
}

void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread)
{
    s32 i;
    s32 statCount = 0;
    u16 evAmount;
    u8 evsBits;

    CreateMon(mon, species, level, fixedIV, 0, 0, 0, 0);

    evsBits = evSpread;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evsBits & 1)
            statCount++;
        evsBits >>= 1;
    }

    evAmount = MAX_TOTAL_EVS / statCount;

    evsBits = 1;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evSpread & evsBits)
            SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);
        evsBits <<= 1;
    }

    CalculateMonStats(mon);
}

void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src)
{
    s32 i;
    u8 value;

    CreateMon(mon, src->species, src->level, 0, 1, src->personality, 1, src->otId);

    for (i = 0; i < 4; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);

    // Why is this commented out in FR/LG?
    /*
    StringCopy(nickname, src->nickname);

    if (nickname[0] == 0xFC && nickname[1] == 0x15)
        language = LANGUAGE_JAPANESE;
    else
        language = GAME_LANGUAGE;

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    Text_StripExtCtrlCodes(nickname);
    */

    SetMonData(mon, MON_DATA_NICKNAME, &src->nickname);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->abilityNum;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    CalculateMonStats(mon);
}

static void CreateEventLegalMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    bool32 isEventLegal = TRUE;

    CreateMon(mon, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_EVENT_LEGAL, &isEventLegal);
}

void ConvertPokemonToBattleTowerPokemon(struct Pokemon *mon, struct BattleTowerPokemon *dest)
{
    s32 i;
    u16 heldItem;

    dest->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);

    if (heldItem == ITEM_ENIGMA_BERRY)
        heldItem = 0;

    dest->heldItem = heldItem;

    for (i = 0; i < 4; i++)
        dest->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);

    dest->level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    dest->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    dest->otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    dest->hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    dest->attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    dest->defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    dest->speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    dest->spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    dest->spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    dest->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    dest->hpIV = GetMonData(mon, MON_DATA_HP_IV, NULL);
    dest->attackIV = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    dest->defenseIV = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    dest->speedIV  = GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    dest->spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    dest->spDefenseIV  = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    dest->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    dest->personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    GetMonData(mon, MON_DATA_NICKNAME, dest->nickname);
}

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon)
{
    u16 checksum = 0;
    union PokemonSubstruct *substruct0 = GetSubstruct(boxMon, boxMon->personality, 0);
    union PokemonSubstruct *substruct1 = GetSubstruct(boxMon, boxMon->personality, 1);
    union PokemonSubstruct *substruct2 = GetSubstruct(boxMon, boxMon->personality, 2);
    union PokemonSubstruct *substruct3 = GetSubstruct(boxMon, boxMon->personality, 3);
    s32 i;

    for (i = 0; i < 6; i++)
        checksum += substruct0->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct1->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct2->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct3->raw[i];

    return checksum;
}

#define CALC_STAT(base, iv, ev, statIndex, field)               \
{                                                               \
    u8 baseStat = gBaseStats[species].base;                     \
    s32 n = (((2 * baseStat + iv + ev) * level) / 100) + 5; \
    u8 nature = GetNature(mon);                                 \
    n = ModifyStatByNature(nature, n, statIndex);               \
    SetMonData(mon, field, &n);                                 \
}

void CalculateMonStats(struct Pokemon *mon)
{
    s32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP, NULL);
    s32 currentHP = GetMonData(mon, MON_DATA_HP, NULL);
    s32 hpIV = GetMonData(mon, MON_DATA_HP_IV, NULL);
    s32 hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    s32 attackIV = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    s32 attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    s32 defenseIV = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    s32 defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    s32 speedIV = GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    s32 speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    s32 spAttackIV = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    s32 spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    s32 spDefenseIV = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    s32 spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromMonExp(mon);
    s32 newMaxHP;

    SetMonData(mon, MON_DATA_LEVEL, &level);

    if (species == SPECIES_ZFAIRY)
    {
        newMaxHP = 1;
    }
    else
    {
        s32 n = 2 * gBaseStats[species].baseHP + hpIV;
        newMaxHP = (((n + hpEV) * level) / 100) + level + 10;
    }

    gBattleScripting.field_23 = newMaxHP - oldMaxHP;
    if (gBattleScripting.field_23 == 0)
        gBattleScripting.field_23 = 1;

    SetMonData(mon, MON_DATA_MAX_HP, &newMaxHP);

    CALC_STAT(baseAttack, attackIV, attackEV, STAT_ATK, MON_DATA_ATK)
    CALC_STAT(baseDefense, defenseIV, defenseEV, STAT_DEF, MON_DATA_DEF)
    CALC_STAT(baseSpeed, speedIV, speedEV, STAT_SPEED, MON_DATA_SPEED)
    CALC_STAT(baseSpAttack, spAttackIV, spAttackEV, STAT_SPATK, MON_DATA_SPATK)
    CALC_STAT(baseSpDefense, spDefenseIV, spDefenseEV, STAT_SPDEF, MON_DATA_SPDEF)

    if (species == SPECIES_ZFAIRY)
    {
        if (currentHP != 0 || oldMaxHP == 0)
            currentHP = 1;
        else
            return;
    }
    else
    {
        if (currentHP == 0 && oldMaxHP == 0)
            currentHP = newMaxHP;
        else if (currentHP != 0) {
            // BUG: currentHP is unintentionally able to become <= 0 after the instruction below.
            currentHP += newMaxHP - oldMaxHP;
            #ifdef BUGFIX
            if (currentHP <= 0)
                currentHP = 1;
            #endif
        }
        else
            return;
    }

    SetMonData(mon, MON_DATA_HP, &currentHP);
}

void BoxMonToMon(struct BoxPokemon *src, struct Pokemon *dest)
{
    u32 value = 0;
    dest->box = *src;
    SetMonData(dest, MON_DATA_STATUS, &value);
    SetMonData(dest, MON_DATA_HP, &value);
    SetMonData(dest, MON_DATA_MAX_HP, &value);
    value = 255;
    SetMonData(dest, MON_DATA_MAIL, &value);
    CalculateMonStats(dest);
}

static u8 GetLevelFromMonExp(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gBaseStats[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 exp = GetBoxMonData(boxMon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gBaseStats[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u16 GiveMoveToMon(struct Pokemon *mon, u16 move)
{
    return GiveMoveToBoxMon(&mon->box, move);
}

static u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        u16 existingMove = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, NULL);
        if (!existingMove)
        {
            SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &move);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &gBattleMoves[move].pp);
            return move;
        }
        if (existingMove == move)
            return -2;
    }
    return -1;
}

u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (!mon->moves[i])
        {
            mon->moves[i] = move;
            mon->pp[i] = gBattleMoves[move].pp;
            return move;
        }
    }

    return -1;
}

void SetMonMoveSlot(struct Pokemon *mon, u16 move, u8 slot)
{
    SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
    SetMonData(mon, MON_DATA_PP1 + slot, &gBattleMoves[move].pp);
}

void SetBattleMonMoveSlot(struct BattlePokemon *mon, u16 move, u8 slot)
{
    mon->moves[slot] = move;
    mon->pp[slot] = gBattleMoves[move].pp;
}

void GiveMonInitialMoveset(struct Pokemon *mon)
{
    GiveBoxMonInitialMoveset(&mon->box);
}

static void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    s32 i;
	
	switch (species)
	{
		case SPECIES_XUTSUHO:
			GiveMoveToBoxMon(boxMon, MOVE_FLAMETHROWER);
			GiveMoveToBoxMon(boxMon, MOVE_SKY_ATTACK);
			GiveMoveToBoxMon(boxMon, MOVE_SACRED_FIRE);
			GiveMoveToBoxMon(boxMon, MOVE_ROOST);
			return;
		case SPECIES_XSUWAKO:
			GiveMoveToBoxMon(boxMon, MOVE_EARTHQUAKE);
			GiveMoveToBoxMon(boxMon, MOVE_SPLASHBACK);
			GiveMoveToBoxMon(boxMon, MOVE_MISHAGUJI);
			GiveMoveToBoxMon(boxMon, MOVE_AQUA_RING);
			return;
		case SPECIES_XTENSHI:
			GiveMoveToBoxMon(boxMon, MOVE_EARTHQUAKE);
			GiveMoveToBoxMon(boxMon, MOVE_DRAWN_LINE);
			GiveMoveToBoxMon(boxMon, MOVE_SWORDS_DANCE);
			GiveMoveToBoxMon(boxMon, MOVE_AEGIS_MERGE);
			return;
		case SPECIES_XTENMA:
			GiveMoveToBoxMon(boxMon, MOVE_OBLIVION_WING);
			GiveMoveToBoxMon(boxMon, MOVE_DISCHARGE);
			GiveMoveToBoxMon(boxMon, MOVE_SILVER_WIND);
			GiveMoveToBoxMon(boxMon, MOVE_NASTY_PLOT);
			return;
		case SPECIES_XSENDAI:
			GiveMoveToBoxMon(boxMon, MOVE_EXTERMINATE);
			GiveMoveToBoxMon(boxMon, MOVE_CLOSE_COMBAT);
			GiveMoveToBoxMon(boxMon, MOVE_GALE_DANCE);
			GiveMoveToBoxMon(boxMon, MOVE_REST);
			return;
	}
		

    for (i = 0; gLevelUpLearnsets[species][i] != LEVEL_UP_END; i++)
    {
        u16 moveLevel;
        u16 move;

        moveLevel = (gLevelUpLearnsets[species][i] & 0xFE00);

        if (moveLevel > (level << 9))
            break;

        move = (gLevelUpLearnsets[species][i] & 0x1FF);

        if (GiveMoveToBoxMon(boxMon, move) == 0xFFFF)
            DeleteFirstMoveAndGiveMoveToBoxMon(boxMon, move);
    }
}

u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove)
{
    u32 retVal = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);

    // since you can learn more than one move per level
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again
    if (firstMove)
    {
        sLearningMoveTableID = 0;

        while ((gLevelUpLearnsets[species][sLearningMoveTableID] & 0xFE00) != (level << 9))
        {
            sLearningMoveTableID++;
            if (gLevelUpLearnsets[species][sLearningMoveTableID] == LEVEL_UP_END)
                return 0;
        }
    }

    if ((gLevelUpLearnsets[species][sLearningMoveTableID] & 0xFE00) == (level << 9))
    {
        gMoveToLearn = (gLevelUpLearnsets[species][sLearningMoveTableID] & 0x1FF);
        sLearningMoveTableID++;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
    }

    return retVal;
}

void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move)
{
    s32 i;
    u16 moves[4];
    u8 pp[4];
    u8 ppBonuses;

    for (i = 0; i < 3; i++)
    {
        moves[i] = GetMonData(mon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetMonData(mon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[3] = move;
    pp[3] = gBattleMoves[move].pp;

    for (i = 0; i < 4; i++)
    {
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

static void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    u16 moves[4];
    u8 pp[4];
    u8 ppBonuses;

    for (i = 0; i < 3; i++)
    {
        moves[i] = GetBoxMonData(boxMon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetBoxMonData(boxMon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[3] = move;
    pp[3] = gBattleMoves[move].pp;

    for (i = 0; i < 4; i++)
    {
        SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &moves[i]);
        SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetBoxMonData(boxMon, MON_DATA_PP_BONUSES, &ppBonuses);
}

#define APPLY_STAT_MOD(var, stat, statValue)                  \
{                                                             \
    (var) = (stat) * (gStatStageRatios[statValue][0]);        \
    (var) /= (gStatStageRatios[statValue][1]);                \
}

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 50,
    48, 40
};


u32 getVariableBasePower(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u8 battlerIdAtk, u8 battlerIdDef)
{
    u32 power = 0;
    u8 i;

    switch (move)
    {
        case MOVE_STOMP:
            if (gStatuses3[battlerIdDef] & STATUS3_MINIMIZED)
                return 120;
            return 60;
        case MOVE_NATURE_POWER:
        case MOVE_MIND_BOMB:
        case MOVE_HEAT_CLAW:
            return gBaseStats[defender->species].cost;
        case MOVE_FLAIL:
        case MOVE_REVERSAL:
        {
            s32 hpFraction = GetScaledHPFraction(gBattleMons[battlerIdAtk].hp, gBattleMons[battlerIdAtk].maxHP, 48);
            for (i = 0; i < (s32)sizeof(sFlailHpScaleToPowerTable); i += 2)
            {
                if (hpFraction <= sFlailHpScaleToPowerTable[i])
                    break;
            }
            power = sFlailHpScaleToPowerTable[i + 1];
            return power;
        }
        case MOVE_ERUPTION:
        case MOVE_AQUA_SHOWER:
            power = gBattleMoves[move].power;
            power = gBattleMons[battlerIdAtk].hp * power / gBattleMons[battlerIdAtk].maxHP;
            return power;
        case MOVE_FACADE:
            power = gBattleMoves[move].power;
            if (gBattleMons[battlerIdAtk].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON))
                power *= 2;
            return power;
        case MOVE_HEX:
            power = gBattleMoves[move].power;
            if (gBattleMons[battlerIdDef].status1)
                power *= 2;
            return power;
		case MOVE_PUNISHMENT:
			power = gBattleMoves[move].power;
			for (i = 1; i < 8; i++)
			{
				if (gBattleMons[battlerIdDef].statStages[i] > 6)
					power += (20 * (gBattleMons[battlerIdDef].statStages[i] - 6));
			}
			return power;
    }
    
    return 0;
}

s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 battlerIdAtk, u8 battlerIdDef)
{
    u32 i;
    s32 damage = 0;
    s32 damageHelper;
    u8 type;
    u8 moveClass;
    u16 attack, defense;
    u16 spAttack, spDefense;
    u8 defenderHoldEffect;
    u8 defenderHoldEffectParam;
    u8 attackerHoldEffect;
    u8 attackerHoldEffectParam;
    u8 defenderAbility;
    u8 atkStatMod;
    u8 defStatMod;
    u8 variablePower = getVariableBasePower(attacker, defender, move, battlerIdAtk, battlerIdDef);
    u8 weatherHasEffect = WEATHER_HAS_EFFECT2;

    if (variablePower)
        gBattleMovePower = variablePower;
    else if (!powerOverride)
        gBattleMovePower = gBattleMoves[move].power;
    else
        gBattleMovePower = powerOverride;

    if (!typeOverride)
        type = gBattleMoves[move].type;
    else
        type = typeOverride & 0x3F;

    moveClass = gBattleMoves[move].moveClass;

    attack = attacker->attack;
    defense = defender->defense;
    spAttack = attacker->spAttack;
    spDefense = defender->spDefense;
    if (move == MOVE_FOUL_PLAY && attacker->ability == ABILITY_PERVERSION)
        attack = defender->spAttack;
	else if (move == MOVE_TAKE_OVER && attacker->ability == ABILITY_PERVERSION)
		spAttack = defender->attack;
    else if (move == MOVE_FOUL_PLAY)
        attack = defender->attack;
	else if (move == MOVE_TAKE_OVER)
		spAttack = defender->spAttack;
    else if (attacker->ability == ABILITY_PERVERSION)
    {
        u16 buffer = spAttack;
        spAttack = buffer;
        attack = buffer;
    }
    else if (move == MOVE_EARTH_PRESS)
        attack = attacker->defense;
    
    if (attacker->ability == ABILITY_PURE_FURIES ||
        attacker->ability == ABILITY_MOLD_BREAKER)
        defenderAbility = ABILITY_NONE;
    else
        defenderAbility = defender->ability;

    if (attacker->item == ITEM_ENIGMA_BERRY)
    {
        attackerHoldEffect = gEnigmaBerries[battlerIdAtk].holdEffect;
        attackerHoldEffectParam = gEnigmaBerries[battlerIdAtk].holdEffectParam;
    }
    else
    {
        attackerHoldEffect = ItemId_GetHoldEffect(attacker->item);
        attackerHoldEffectParam = ItemId_GetHoldEffectParam(attacker->item);
    }

    if (defender->item == ITEM_ENIGMA_BERRY)
    {
        defenderHoldEffect = gEnigmaBerries[battlerIdDef].holdEffect;
        defenderHoldEffectParam = gEnigmaBerries[battlerIdDef].holdEffectParam;
    }
    else
    {
        defenderHoldEffect = ItemId_GetHoldEffect(defender->item);
        defenderHoldEffectParam = ItemId_GetHoldEffectParam(defender->item);
    }
	
	if (attacker->ability == ABILITY_KLUTZ)
		attackerHoldEffect = 0;
	if (defender->ability == ABILITY_KLUTZ) // mold breaker shouldn't pierce klutz
		defenderHoldEffect = 0;

    if (attacker->ability == ABILITY_UNZAN || attacker->ability == ABILITY_PURE_POWER)
        attack *= 2;

    for (i = 0; i < NELEMS(sHoldEffectToType); i++)
    {
        if (attackerHoldEffect == sHoldEffectToType[i][0]
            && type == sHoldEffectToType[i][1])
        {
            attack = (attack * (attackerHoldEffectParam + 100)) / 100;
            spAttack = (spAttack * (attackerHoldEffectParam + 100)) / 100;
        }
    }
    
    // do this before other boosts!
    if (attacker->ability == ABILITY_YIN_AND_YANG)
    {
        if (attack == spAttack)
        {
            attack = (attack * 13) / 10;
            spAttack = (spAttack * 13) / 10;
        }
        else if (attack > spAttack)
            spAttack = (spAttack * 13) / 10;
        else
            attack = (attack * 13) / 10;
    }

    if (attackerHoldEffect == HOLD_EFFECT_CHOICE_BAND)
        attack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER)) && (attacker->species == SPECIES_LATIAS || attacker->species == SPECIES_LATIOS))
        spAttack = (150 * spAttack) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_BATTLE_TOWER)) && (defender->species == SPECIES_LATIAS || defender->species == SPECIES_LATIOS))
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_DEEP_SEA_TOOTH && attacker->species == SPECIES_RINNOSUKE)
    {
        attack *= 2;
        spAttack *= 2;
    }
    if (defenderHoldEffect == HOLD_EFFECT_DEEP_SEA_SCALE && defender->species == SPECIES_RINNOSUKE)
    {
        defense *= 2;
        spDefense *= 2;
    }
    if (attackerHoldEffect == HOLD_EFFECT_LIGHT_BALL && attacker->species == SPECIES_CCIRNO)
    {
        attack *= 2;
        spAttack *= 2;
    }
    if (attackerHoldEffect == HOLD_EFFECT_HANIWA_SWORD && (attacker->species == SPECIES_CMAYUMI || attacker->species == SPECIES_MAYUMI) &&
        (type == TYPE_EARTH || type == TYPE_STEEL))
    {
        attack = (attack * 12) / 10;
        spAttack = (spAttack * 12) / 10;
    }
	if (attackerHoldEffect == HOLD_EFFECT_OLD_PLATE)
	{
		attack = (attack * 11) / 10;
		spAttack = (spAttack * 11) / 10;
	}
	if (attackerHoldEffect == HOLD_EFFECT_ROUKANKEN && 
		(attacker->species == SPECIES_CYOUMU || attacker->species == SPECIES_YOUMU ||
		 attacker->species == SPECIES_AYOUMU || attacker->species == SPECIES_DYOUMU ||
		 attacker->species == SPECIES_SYOUMU ||
		 attacker->species == SPECIES_CYOUKI || attacker->species == SPECIES_YOUKI) &&
		(type == TYPE_STEEL || type == TYPE_GHOST))
	{
		attack = (attack * (100 + attackerHoldEffectParam)) / 100;
		spAttack = (spAttack * (100 + attackerHoldEffectParam)) / 100;
	}
    /*
    if (defenderHoldEffect == HOLD_EFFECT_METAL_POWDER && defender->species == SPECIES_DITTO)
        defense *= 2; */
    if (attackerHoldEffect == HOLD_EFFECT_THICK_CLUB && 
        (attacker->species == SPECIES_CHINA || attacker->species == SPECIES_HINA))
        attack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_HANIWA_GUARD && (defender->species == SPECIES_CMAYUMI || defender->species == SPECIES_MAYUMI))
        defense = (150 * defense) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_HANIWA_CHARM && (defender->species == SPECIES_CMAYUMI || defender->species == SPECIES_MAYUMI))
        spDefense = (150 * spDefense) / 100;
    if (defenderAbility == ABILITY_WALL_OF_ICE && (type == TYPE_FIRE || type == TYPE_ICE))
    {
        attack /= 2;
        spAttack /= 2;
    }
    if (defenderAbility == ABILITY_ATHEISM && (type == TYPE_FAITH))
    {
        attack /= 4;
        spAttack /= 4;
    }
    if (attacker->ability == ABILITY_HUSTLE)
        attack = (150 * attack) / 100;
    if (attacker->ability == ABILITY_GUTS && attacker->status1)
        attack = (150 * attack) / 100;
    if (defenderAbility == ABILITY_SPRING_CHARM && defender->status1)
        defense = (150 * defense) / 100;
    if (gBattleStruct->meFirstTracker)
    {
        gBattleMovePower *= 15;
        gBattleMovePower /= 10;
    }
    if (attacker->ability == ABILITY_INNER_POWER && attacker->hp <= (attacker->maxHP / 3) &&
        (type == attacker->type1 || type == attacker->type2))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (attacker->ability == ABILITY_STONEWORKER && type == TYPE_EARTH)
    {
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    }
    if (attacker->ability == ABILITY_ARSONIST && type == TYPE_FIRE)
    {
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    }
    if (attacker->ability == ABILITY_LOGICIAN && type == TYPE_REASON)
    {
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    }
    if (attacker->ability == ABILITY_TOXICOLOGIST && type == TYPE_POISON)
    {
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    }
	if (attacker->ability == ABILITY_SWORDMASTER && gBattleMoves[move].priority > 0)
	{
        gBattleMovePower = (150 * gBattleMovePower) / 100;
	}
	if (attacker->ability == ABILITY_CHARISMATIC && attacker->hp <= (attacker->maxHP / 2))
	{
		gBattleMovePower = (50 * gBattleMovePower) / 100;
	}
	if (attacker->ability == ABILITY_IRON_FIST && gBattleMoves[move].flags & FLAG_PUNCHING)
	{
		gBattleMovePower = (120 * gBattleMovePower) / 100;
	}
	if (attacker->ability == ABILITY_ANALYTIC)
	{
		for (i = 0; i < gBattlersCount; i++)
		{
			if (gBattlerByTurnOrder[i] == battlerIdDef)
			{
				gBattleMovePower = (130 * gBattleMovePower) / 100;
				i = gBattlersCount;
			}
			else if (gBattlerByTurnOrder[i] == battlerIdAtk)
				i = gBattlersCount;
		}
	}
	if (attacker->ability == ABILITY_TWIN_SPARK)
	{
		gBattleMovePower = (60 * gBattleMovePower) / 100;
	}
    if (defenderAbility == ABILITY_CHEERFUL && defender->hp == defender->maxHP)
    {
        defense *= 2;
        spDefense *= 2;
    }
    if (defenderAbility == ABILITY_JEALOUSY && defender->item == ITEM_NONE && attacker->item != ITEM_NONE)
    {
        defense = (150 * defense) / 100;
        spDefense = (150 * defense) / 100;
    }
    if (attacker->ability == ABILITY_PURE_ENIGMA)
    {
        if (attacker->species == SPECIES_OKINA)
        {
            attack *= 2;
            spAttack *= 2;
        }
        else
        {
            defense = (defense * 150) / 100;
            spDefense = (spDefense * 150) / 100;
        }
    }
    if (defenderAbility == ABILITY_PURE_ENIGMA)
    {
        if (defender->species == SPECIES_OKINA)
        {
            defense *= 2;
            spDefense *= 2;
        }
        else
        {
            defense = (defense * 150) / 100;
            spDefense = (spDefense * 150) / 100;
        }
    }
    if (attacker->ability == ABILITY_HARMONIZE)
    {
        u8 i = 0;
        u8 boost = 0;
		u8 partysize = 0;
        struct Pokemon *party;
        //oh fuckin' boy here we go
        if (GET_BATTLER_SIDE(battlerIdAtk) != B_SIDE_PLAYER)
		{
			party = gEnemyParty;
			partysize = gEnemyPartyCount;
		}
        else
		{
			party = gPlayerParty;
			partysize = PARTY_SIZE;
		}
        for (i = 0; i < partysize; i++)
        {
            if (i != gBattlerPartyIndexes[battlerIdAtk])
            {
                if (GetMonData(&party[i], MON_DATA_IS_EGG, NULL) || !GetMonData(&party[i], MON_DATA_SPECIES, NULL))
                    continue;
                if (GetMonData(&party[i], MON_DATA_MOVE1, NULL) == move ||
                    GetMonData(&party[i], MON_DATA_MOVE2, NULL) == move ||
                    GetMonData(&party[i], MON_DATA_MOVE3, NULL) == move ||
                    GetMonData(&party[i], MON_DATA_MOVE4, NULL) == move)
                    boost += 10;
            }
        }
        gBattleMovePower = (gBattleMovePower * (100 + boost)) / 100;
    }
    if (attacker->ability == ABILITY_MASTERMIND)
    {
        u8 i = 0;
        u8 boost = 0;
		u8 partysize = 0;
        struct Pokemon *party;
        //oh fuckin' boy here we go
        if (GET_BATTLER_SIDE(battlerIdAtk) != B_SIDE_PLAYER)
        {
			party = gEnemyParty;
			partysize = gEnemyPartyCount;
		}
        else
        {
			party = gPlayerParty;
			partysize = PARTY_SIZE;
		}
        for (i = 0; i < partysize && !boost; i++)
        {
            if (i != gBattlerPartyIndexes[battlerIdAtk])
            {
                u16 monspecies = GetMonData(&party[i], MON_DATA_SPECIES, NULL);
                if (!monspecies || GetMonData(&party[i], MON_DATA_IS_EGG, NULL)
                    || GetMonData(&party[i], MON_DATA_HP, NULL) != 0)
                    continue;
                if (gBaseStats[monspecies].type1 == type ||
                    gBaseStats[monspecies].type2 == type)
                    boost = 33;
            }
        }
		if (boost > 0 && type != attacker->type1 && type != attacker->type2)
				boost = 100;
        gBattleMovePower = (gBattleMovePower * (100 + boost)) / 100;
    }
    if (attacker->ability == ABILITY_RECKLESS && (gBattleMoves[move].effect == EFFECT_RECOIL
        || gBattleMoves[move].effect == EFFECT_RECOIL_IF_MISS 
        || gBattleMoves[move].effect == EFFECT_DOUBLE_EDGE))
    {
        gBattleMovePower *= 12;
        gBattleMovePower /= 10;
    }
	if (attacker->ability == ABILITY_TECHNICIAN && gBattleMovePower <= 60)
	{
		gBattleMovePower *= 150;
		gBattleMovePower /= 100;
	}
    
    if (weatherHasEffect)
    {
        if (attacker->ability == ABILITY_SOLAR_POWER && gBattleWeather & WEATHER_SUN_ANY)
        {
			attack = (attack * 150) / 100;
			spAttack = (spAttack * 150) / 100;
		}
		if (gBattleWeather & WEATHER_SUN_ANY)
		{
            if (attacker->ability == ABILITY_FLOWER_GIFT)
            {
                spAttack *= 3;
                spAttack /= 2;
            }
            if (defenderAbility == ABILITY_FLOWER_GIFT)
            {
                spDefense *= 3;
				spDefense /= 2;
            }
		}
        if (gBattleWeather & WEATHER_HAIL)
        {
            if (attacker->ability == ABILITY_WINTER_GIFT)
            {
                spAttack *= 3;
                spAttack /= 2;
            }
            if (defenderAbility == ABILITY_WINTER_GIFT)
            {
                spDefense *= 3;
				spDefense /= 2;
            }
        }
        if (gBattleWeather && defenderAbility == ABILITY_STORM_SHAWL)
            spDefense = (spDefense * 15) / 10;
    }
        
        
    if ((attacker->status1 & STATUS1_BURN) && attacker->ability != ABILITY_GUTS && move != MOVE_FACADE)
        attack /= 2;

    if (moveClass == CLASS_PHYSICAL)
    {
        atkStatMod = attacker->statStages[STAT_ATK];
        defStatMod = defender->statStages[STAT_DEF];
        if (move == MOVE_FOUL_PLAY && attacker->ability == ABILITY_PERVERSION)
            atkStatMod = defender->statStages[STAT_SPATK];
        else if (move == MOVE_FOUL_PLAY)
            atkStatMod = defender->statStages[STAT_ATK];
        else if (attacker->ability == ABILITY_PERVERSION)
            atkStatMod = attacker->statStages[STAT_SPATK];
        else if (move == MOVE_EARTH_PRESS)
            atkStatMod = attacker->statStages[STAT_DEF];
        
        if (defenderAbility == ABILITY_UNAWARE)
            atkStatMod = 6;
        if (attacker->ability == ABILITY_UNAWARE)
            defStatMod = 6;
        
        if (gCritMultiplier > 1 && atkStatMod < 6)
        {
            damage = attack;
        }
        else
            APPLY_STAT_MOD(damage, attack, atkStatMod)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier > 1 && defStatMod > 6)
        {
            damageHelper = defense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defense, defStatMod)
    }
    else
    {
        u8 atkStatMod = attacker->statStages[STAT_SPATK];
        u8 defStatMod = defender->statStages[STAT_SPDEF];
		if (move == MOVE_TAKE_OVER && attacker->ability == ABILITY_PERVERSION)
			atkStatMod = defender->statStages[STAT_ATK];
		else if (move == MOVE_TAKE_OVER)
			atkStatMod = defender->statStages[STAT_SPATK];
        else if (attacker->ability == ABILITY_PERVERSION)
            atkStatMod = attacker->statStages[STAT_ATK];
        if (move == MOVE_MANASHOCK)
        {
            defStatMod = defender->statStages[STAT_DEF];
            spDefense = defense;
        }
        
        if (defenderAbility == ABILITY_UNAWARE)
            atkStatMod = 6;
        if (attacker->ability == ABILITY_UNAWARE)
            defStatMod = 6;
        
        if (gCritMultiplier > 1 && atkStatMod < 6)
        {
            damage = spAttack;
        }
        else
            APPLY_STAT_MOD(damage, spAttack, atkStatMod)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier > 1 && defStatMod > 6)
        {
            damageHelper = spDefense;
        }
        else
            APPLY_STAT_MOD(damageHelper, spDefense, defStatMod);
    }

    damage = (damage / damageHelper);
    damage /= 50;

    if (((moveClass == CLASS_PHYSICAL && sideStatus & SIDE_STATUS_REFLECT) ||
        (moveClass == CLASS_SPECIAL && sideStatus & SIDE_STATUS_LIGHTSCREEN)) 
        && gCritMultiplier == 1
        && attacker->ability != ABILITY_INFILTRATOR)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMonsInBattle(BATTLE_ALIVE_DEF_SIDE) == 2)
            damage = 2 * (damage / 3);
        else
            damage /= 2;
    }

    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMoves[move].target == 8 && CountAliveMonsInBattle(BATTLE_ALIVE_DEF_SIDE) == 2)
        damage /= 2;

    // are effects of weather negated with cloud nine or air lock
    if (weatherHasEffect)
    {
        if (gBattleWeather & WEATHER_RAIN_TEMPORARY)
        {
            switch (type)
            {
            case TYPE_FIRE:
                damage /= 2;
                break;
            case TYPE_WATER:
                damage = (15 * damage) / 10;
                break;
            }
        }

        // any weather except sun weakens solar beam
        if ((gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_HAIL)) && gCurrentMove == MOVE_SOLAR_BEAM)
            damage /= 2;

        // sunny
        if (gBattleWeather & WEATHER_SUN_ANY)
        {
            switch (type)
            {
            case TYPE_FIRE:
                damage = (15 * damage) / 10;
                break;
            case TYPE_WATER:
                damage /= 2;
                break;
            }
        }
    }

    // flash fire triggered
    if ((gBattleResources->flags->flags[battlerIdAtk] & RESOURCE_FLAG_FLASH_FIRE) && type == TYPE_FIRE)
        damage = (15 * damage) / 10;
    
    if (gStatuses3[battlerIdDef] & STATUS3_GLAIVE_RUSH)
        damage *= 2;

    return damage + 2;
}

u8 CountAliveMonsInBattle(u8 caseId)
{
    s32 i;
    u8 retVal = 0;

    switch (caseId)
    {
    case BATTLE_ALIVE_EXCEPT_ACTIVE:
        for (i = 0; i < 4; i++)
        {
            if (i != gActiveBattler && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_ATK_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBattlerSide(i) == GetBattlerSide(gBattlerAttacker) && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_DEF_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBattlerSide(i) == GetBattlerSide(gBattlerTarget) && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    }

    return retVal;
}

u8 GetDefaultMoveTarget(u8 battlerId)
{
    u8 opposing = BATTLE_OPPOSITE(GetBattlerPosition(battlerId) & BIT_SIDE);

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return GetBattlerAtPosition(opposing);
    if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ACTIVE) > 1)
    {
        u8 position;

        if ((Random() & 1) == 0)
            position = BATTLE_PARTNER(opposing);
        else
            position = opposing;
        return GetBattlerAtPosition(position);
    }
    else
    {
        if ((gAbsentBattlerFlags & gBitTable[opposing]))
            return GetBattlerAtPosition(BATTLE_PARTNER(opposing));
        else
            return GetBattlerAtPosition(opposing);
    }
}

u8 GetMonGender(struct Pokemon *mon)
{
    return GetBoxMonGender(&mon->box);
}

u8 GetBoxMonGender(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY, NULL);

    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gBaseStats[species].genderRatio;
    }

    if (gBaseStats[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality)
{
    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gBaseStats[species].genderRatio;
    }

    if (gBaseStats[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

void SetMultiuseSpriteTemplateToPokemon(u16 speciesTag, u8 battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
    {
        if (battlerPosition >= 4)
            battlerPosition = 0;

        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    }
    else
    {
        if (sOakSpeechNidoranResources)
        {
            if (battlerPosition >= (s8)sOakSpeechNidoranResources->battlePosition) // why a cast?!? changing the unk0_2 type to s8 causes extra shifts, but a cast is the correct fix. why, compiler?
                battlerPosition = 0;

            gMultiuseSpriteTemplate = sOakSpeechNidoranResources->templates[battlerPosition];
        }
        else
        {
            if (battlerPosition >= 4)
                battlerPosition = 0;

            gMultiuseSpriteTemplate = gSpriteTemplates_Battlers[battlerPosition];
        }
    }
    gMultiuseSpriteTemplate.paletteTag = speciesTag;
    gMultiuseSpriteTemplate.anims = gSpriteAnimTable_82349BC;
}

void SetMultiuseSpriteTemplateToTrainerBack(u16 trainerSpriteId, u8 battlerPosition)
{
    gMultiuseSpriteTemplate.paletteTag = trainerSpriteId;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
    {
        gMultiuseSpriteTemplate = gSpriteTemplates_TrainerBackpics[trainerSpriteId];
        gMultiuseSpriteTemplate.anims = gTrainerBackAnimsPtrTable[trainerSpriteId];
    }
    else
    {
        if (gMonSpritesGfxPtr != NULL)
            gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
        else
            gMultiuseSpriteTemplate = gSpriteTemplates_Battlers[battlerPosition];
        gMultiuseSpriteTemplate.anims = gTrainerFrontAnimsPtrTable[trainerSpriteId];
    }
}

static void EncryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < 12; i++)
    {
        boxMon->secure.raw[i] ^= boxMon->personality;
        boxMon->secure.raw[i] ^= boxMon->otId;
    }
}

static void DecryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < 12; i++)
    {
        boxMon->secure.raw[i] ^= boxMon->otId;
        boxMon->secure.raw[i] ^= boxMon->personality;
    }
}

#define SUBSTRUCT_CASE(n, v1, v2, v3, v4)                               \
case n:                                                                 \
    {                                                                   \
    union PokemonSubstruct *substructs0 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs1 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs2 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs3 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs4 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs5 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs6 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs7 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs8 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs9 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs10 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs11 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs12 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs13 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs14 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs15 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs16 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs17 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs18 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs19 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs20 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs21 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs22 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs23 = boxMon->secure.substructs;   \
                                                                        \
        switch (substructType)                                          \
        {                                                               \
        case 0:                                                         \
            substruct = &substructs ## n [v1];                          \
            break;                                                      \
        case 1:                                                         \
            substruct = &substructs ## n [v2];                          \
            break;                                                      \
        case 2:                                                         \
            substruct = &substructs ## n [v3];                          \
            break;                                                      \
        case 3:                                                         \
            substruct = &substructs ## n [v4];                          \
            break;                                                      \
        }                                                               \
        break;                                                          \
    }                                                                   \

static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType)
{
    union PokemonSubstruct *substruct = NULL;

    switch (personality % 24)
    {
        SUBSTRUCT_CASE( 0,0,1,2,3)
        SUBSTRUCT_CASE( 1,0,1,3,2)
        SUBSTRUCT_CASE( 2,0,2,1,3)
        SUBSTRUCT_CASE( 3,0,3,1,2)
        SUBSTRUCT_CASE( 4,0,2,3,1)
        SUBSTRUCT_CASE( 5,0,3,2,1)
        SUBSTRUCT_CASE( 6,1,0,2,3)
        SUBSTRUCT_CASE( 7,1,0,3,2)
        SUBSTRUCT_CASE( 8,2,0,1,3)
        SUBSTRUCT_CASE( 9,3,0,1,2)
        SUBSTRUCT_CASE(10,2,0,3,1)
        SUBSTRUCT_CASE(11,3,0,2,1)
        SUBSTRUCT_CASE(12,1,2,0,3)
        SUBSTRUCT_CASE(13,1,3,0,2)
        SUBSTRUCT_CASE(14,2,1,0,3)
        SUBSTRUCT_CASE(15,3,1,0,2)
        SUBSTRUCT_CASE(16,2,3,0,1)
        SUBSTRUCT_CASE(17,3,2,0,1)
        SUBSTRUCT_CASE(18,1,2,3,0)
        SUBSTRUCT_CASE(19,1,3,2,0)
        SUBSTRUCT_CASE(20,2,1,3,0)
        SUBSTRUCT_CASE(21,3,1,2,0)
        SUBSTRUCT_CASE(22,2,3,1,0)
        SUBSTRUCT_CASE(23,3,2,1,0)
    }

    return substruct;
}

u32 GetMonData(struct Pokemon *mon, s32 field, u8* data)
{
    u32 ret;

    switch (field)
    {
    case MON_DATA_STATUS:
        ret = mon->status;
        break;
    case MON_DATA_LEVEL:
        ret = mon->level;
        break;
    case MON_DATA_HP:
        ret = mon->hp;
        break;
    case MON_DATA_MAX_HP:
        ret = mon->maxHP;
        break;
    case MON_DATA_ATK:
        ret = mon->attack;
        break;
    case MON_DATA_DEF:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF:
        ret = mon->spDefense;
        break;
    case MON_DATA_ATK2:
        ret = mon->attack;
        break;
    case MON_DATA_DEF2:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED2:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK2:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF2:
        ret = mon->spDefense;
        break;
    case MON_DATA_MAIL:
        ret = mon->mail;
        break;
    default:
        ret = GetBoxMonData(&mon->box, field, data);
        break;
    }
    return ret;
}

u32 GetBoxMonData(struct BoxPokemon *boxMon, s32 field, u8 *data)
{
    s32 i;
    u32 retVal = 0;
    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = 1;
            boxMon->isEgg = 1;
            substruct3->isEgg = 1;
        }
    }

    switch (field)
    {
    case MON_DATA_PERSONALITY:
        retVal = boxMon->personality;
        break;
    case MON_DATA_OT_ID:
        retVal = boxMon->otId;
        break;
    case MON_DATA_NICKNAME:
    {
        if (boxMon->isBadEgg)
        {
            for (retVal = 0;
                retVal < POKEMON_NAME_LENGTH && gText_BadEgg[retVal] != EOS;
                data[retVal] = gText_BadEgg[retVal], retVal++) {}

            data[retVal] = EOS;
        }
        else if (boxMon->isEgg)
        {
            StringCopy(data, gText_EggNickname);
            retVal = StringLength(data);
        }
        else if (boxMon->language == LANGUAGE_JAPANESE)
        {
            data[0] = EXT_CTRL_CODE_BEGIN;
            data[1] = EXT_CTRL_CODE_JPN;

            // FRLG changed i < 7 to i < 6
            for (retVal = 2, i = 0;
                i < 6 && boxMon->nickname[i] != EOS;
                data[retVal] = boxMon->nickname[i], retVal++, i++) {}

            data[retVal++] = EXT_CTRL_CODE_BEGIN;
            data[retVal++] = EXT_CTRL_CODE_ENG;
            data[retVal] = EOS;
        }
        else
        {
            for (retVal = 0;
                retVal < POKEMON_NAME_LENGTH;
                data[retVal] = boxMon->nickname[retVal], retVal++){}

            data[retVal] = EOS;
        }
        break;
    }
    case MON_DATA_LANGUAGE:
        retVal = boxMon->language;
        break;
    case MON_DATA_SANITY_IS_BAD_EGG:
        retVal = boxMon->isBadEgg;
        break;
    case MON_DATA_SANITY_HAS_SPECIES:
        retVal = boxMon->hasSpecies;
        break;
    case MON_DATA_SANITY_IS_EGG:
        retVal = boxMon->isEgg;
        break;
    case MON_DATA_OT_NAME:
    {
        retVal = 0;

        // FRLG changed this to 7 which used to be PLAYER_NAME_LENGTH + 1
        while (retVal < 7)
        {
            data[retVal] = boxMon->otName[retVal];
            retVal++;
        }

        data[retVal] = EOS;
        break;
    }
    case MON_DATA_MARKINGS:
        retVal = boxMon->markings;
        break;
    case MON_DATA_CHECKSUM:
        retVal = boxMon->checksum;
        break;
    case MON_DATA_ENCRYPT_SEPARATOR:
        // retVal = boxMon->unknown;
        break;
    case MON_DATA_SPECIES:
        retVal = boxMon->isBadEgg ? SPECIES_EGG : substruct0->species;
        break;
    case MON_DATA_HELD_ITEM:
        retVal = substruct0->heldItem;
        break;
    case MON_DATA_EXP:
        retVal = substruct0->experience;
        break;
    case MON_DATA_PP_BONUSES:
        retVal = substruct0->ppBonuses;
        break;
    case MON_DATA_FRIENDSHIP:
        retVal = substruct0->friendship;
        break;
    case MON_DATA_MOVE1:
    case MON_DATA_MOVE2:
    case MON_DATA_MOVE3:
    case MON_DATA_MOVE4:
        retVal = substruct1->moves[field - MON_DATA_MOVE1];
        break;
    case MON_DATA_PP1:
    case MON_DATA_PP2:
    case MON_DATA_PP3:
    case MON_DATA_PP4:
        retVal = substruct1->pp[field - MON_DATA_PP1];
        break;
    case MON_DATA_HP_EV:
        retVal = substruct2->hpEV;
        break;
    case MON_DATA_ATK_EV:
        retVal = substruct2->attackEV;
        break;
    case MON_DATA_DEF_EV:
        retVal = substruct2->defenseEV;
        break;
    case MON_DATA_SPEED_EV:
        retVal = substruct2->speedEV;
        break;
    case MON_DATA_SPATK_EV:
        retVal = substruct2->spAttackEV;
        break;
    case MON_DATA_SPDEF_EV:
        retVal = substruct2->spDefenseEV;
        break;
    case MON_DATA_NATURE_OVERRIDE:
        retVal = substruct2->natureOverride;
        break;
    case MON_DATA_FREE_EV:
        retVal = substruct2->freeEVs;
        break;
    case MON_DATA_SMART:
        retVal = substruct2->smart;
        break;
    case MON_DATA_TOUGH:
        retVal = substruct2->tough;
        break;
    case MON_DATA_SHEEN:
        retVal = substruct2->sheen;
        break;
    case MON_DATA_POKERUS:
        retVal = substruct3->pokerus;
        break;
    case MON_DATA_MET_LOCATION:
        retVal = substruct3->metLocation;
        break;
    case MON_DATA_MET_LEVEL:
        retVal = substruct3->metLevel;
        break;
    case MON_DATA_MET_GAME:
        retVal = substruct3->metGame;
        break;
    case MON_DATA_POKEBALL:
        retVal = substruct3->pokeball;
        break;
    case MON_DATA_OT_GENDER:
        retVal = substruct3->otGender;
        break;
    case MON_DATA_HP_IV:
        retVal = substruct3->hpIV;
        break;
    case MON_DATA_ATK_IV:
        retVal = substruct3->attackIV;
        break;
    case MON_DATA_DEF_IV:
        retVal = substruct3->defenseIV;
        break;
    case MON_DATA_SPEED_IV:
        retVal = substruct3->speedIV;
        break;
    case MON_DATA_SPATK_IV:
        retVal = substruct3->spAttackIV;
        break;
    case MON_DATA_SPDEF_IV:
        retVal = substruct3->spDefenseIV;
        break;
    case MON_DATA_IS_EGG:
        retVal = substruct3->isEgg;
        break;
    case MON_DATA_ABILITY_NUM:
        retVal = substruct3->abilityNum;
        break;
    case MON_DATA_COOL_RIBBON:
        retVal = substruct3->coolRibbon;
        break;
    case MON_DATA_BEAUTY_RIBBON:
        retVal = substruct3->beautyRibbon;
        break;
    case MON_DATA_CUTE_RIBBON:
        retVal = substruct3->cuteRibbon;
        break;
    case MON_DATA_SMART_RIBBON:
        retVal = substruct3->smartRibbon;
        break;
    case MON_DATA_TOUGH_RIBBON:
        retVal = substruct3->toughRibbon;
        break;
    case MON_DATA_CHAMPION_RIBBON:
        retVal = substruct3->championRibbon;
        break;
    case MON_DATA_WINNING_RIBBON:
        retVal = substruct3->winningRibbon;
        break;
    case MON_DATA_VICTORY_RIBBON:
        retVal = substruct3->victoryRibbon;
        break;
    case MON_DATA_ARTIST_RIBBON:
        retVal = substruct3->artistRibbon;
        break;
    case MON_DATA_EFFORT_RIBBON:
        retVal = substruct3->effortRibbon;
        break;
    case MON_DATA_MARINE_RIBBON:
        retVal = substruct3->marineRibbon;
        break;
    case MON_DATA_LAND_RIBBON:
        retVal = substruct3->landRibbon;
        break;
    case MON_DATA_SKY_RIBBON:
        retVal = substruct3->skyRibbon;
        break;
    case MON_DATA_COUNTRY_RIBBON:
        retVal = substruct3->countryRibbon;
        break;
    case MON_DATA_NATIONAL_RIBBON:
        retVal = substruct3->nationalRibbon;
        break;
    case MON_DATA_EARTH_RIBBON:
        retVal = substruct3->earthRibbon;
        break;
    case MON_DATA_WORLD_RIBBON:
        retVal = substruct3->worldRibbon;
        break;
    case MON_DATA_HIDDEN_ABILITY:
        retVal = substruct3->hiddenAbility;
        break;
    case MON_DATA_FILLER:
        retVal = substruct3->filler;
        break;
    case MON_DATA_EVENT_LEGAL:
        retVal = substruct3->eventLegal;
        break;
    case MON_DATA_SPECIES2:
        retVal = substruct0->species;
        if (substruct0->species && (substruct3->isEgg || boxMon->isBadEgg))
            retVal = SPECIES_EGG;
        break;
    case MON_DATA_IVS:
        retVal = substruct3->hpIV | (substruct3->attackIV << 5) | (substruct3->defenseIV << 10) | (substruct3->speedIV << 15) | (substruct3->spAttackIV << 20) | (substruct3->spDefenseIV << 25);
        break;
    case MON_DATA_KNOWN_MOVES:
        if (substruct0->species && !substruct3->isEgg)
        {
            u16 *moves = (u16 *)data;
            s32 i = 0;

            while (moves[i] != MOVES_COUNT)
            {
                u16 move = moves[i];
                if (substruct1->moves[0] == move
                    || substruct1->moves[1] == move
                    || substruct1->moves[2] == move
                    || substruct1->moves[3] == move)
                    retVal |= gBitTable[i];
                i++;
            }
        }
        break;
    case MON_DATA_RIBBON_COUNT:
        retVal = 0;
        if (substruct0->species && !substruct3->isEgg)
        {
            retVal += substruct3->coolRibbon;
            retVal += substruct3->beautyRibbon;
            retVal += substruct3->cuteRibbon;
            retVal += substruct3->smartRibbon;
            retVal += substruct3->toughRibbon;
            retVal += substruct3->championRibbon;
            retVal += substruct3->winningRibbon;
            retVal += substruct3->victoryRibbon;
            retVal += substruct3->artistRibbon;
            retVal += substruct3->effortRibbon;
            retVal += substruct3->marineRibbon;
            retVal += substruct3->landRibbon;
            retVal += substruct3->skyRibbon;
            retVal += substruct3->countryRibbon;
            retVal += substruct3->nationalRibbon;
            retVal += substruct3->earthRibbon;
            retVal += substruct3->worldRibbon;
        }
        break;
    case MON_DATA_RIBBONS:
        retVal = 0;
        if (substruct0->species && !substruct3->isEgg)
        {
            retVal = substruct3->championRibbon
                | (substruct3->coolRibbon << 1)
                | (substruct3->beautyRibbon << 4)
                | (substruct3->cuteRibbon << 7)
                | (substruct3->smartRibbon << 10)
                | (substruct3->toughRibbon << 13)
                | (substruct3->winningRibbon << 16)
                | (substruct3->victoryRibbon << 17)
                | (substruct3->artistRibbon << 18)
                | (substruct3->effortRibbon << 19)
                | (substruct3->marineRibbon << 20)
                | (substruct3->landRibbon << 21)
                | (substruct3->skyRibbon << 22)
                | (substruct3->countryRibbon << 23)
                | (substruct3->nationalRibbon << 24)
                | (substruct3->earthRibbon << 25)
                | (substruct3->worldRibbon << 26);
        }
        break;
    default:
        break;
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
        EncryptBoxMon(boxMon);

    return retVal;
}

#define SET8(lhs) (lhs) = *data
#define SET16(lhs) (lhs) = data[0] + (data[1] << 8)
#define SET32(lhs) (lhs) = data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24)

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    switch (field)
    {
    case MON_DATA_STATUS:
        SET32(mon->status);
        break;
    case MON_DATA_LEVEL:
        SET8(mon->level);
        break;
    case MON_DATA_HP:
        SET16(mon->hp);
        break;
    case MON_DATA_MAX_HP:
        SET16(mon->maxHP);
        break;
    case MON_DATA_ATK:
    case MON_DATA_ATK2:
        SET16(mon->attack);
        break;
    case MON_DATA_DEF:
    case MON_DATA_DEF2:
        SET16(mon->defense);
        break;
    case MON_DATA_SPEED:
    case MON_DATA_SPEED2:
        SET16(mon->speed);
        break;
    case MON_DATA_SPATK:
    case MON_DATA_SPATK2:
        SET16(mon->spAttack);
        break;
    case MON_DATA_SPDEF:
    case MON_DATA_SPDEF2:
        SET16(mon->spDefense);
        break;
    case MON_DATA_MAIL:
        SET8(mon->mail);
        break;
    case MON_DATA_SPECIES2:
        break;
    // why did FRLG go out of its way to specify all of these for default?
    case MON_DATA_IVS:
    case MON_DATA_CHAMPION_RIBBON:
    case MON_DATA_WINNING_RIBBON:
    case MON_DATA_VICTORY_RIBBON:
    case MON_DATA_ARTIST_RIBBON:
    case MON_DATA_EFFORT_RIBBON:
    case MON_DATA_MARINE_RIBBON:
    case MON_DATA_LAND_RIBBON:
    case MON_DATA_SKY_RIBBON:
    case MON_DATA_COUNTRY_RIBBON:
    case MON_DATA_NATIONAL_RIBBON:
    case MON_DATA_EARTH_RIBBON:
    case MON_DATA_WORLD_RIBBON:
    case MON_DATA_FILLER:
    case MON_DATA_EVENT_LEGAL:
    case MON_DATA_KNOWN_MOVES:
    case MON_DATA_RIBBON_COUNT:
    case MON_DATA_RIBBONS:
    default:
        SetBoxMonData(&mon->box, field, data);
        break;
    }
}

void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = 1;
            boxMon->isEgg = 1;
            substruct3->isEgg = 1;
            EncryptBoxMon(boxMon);
            return;
        }
    }

    switch (field)
    {
    case MON_DATA_PERSONALITY:
        SET32(boxMon->personality);
        break;
    case MON_DATA_OT_ID:
        SET32(boxMon->otId);
        break;
    case MON_DATA_NICKNAME:
    {
        s32 i;
        for (i = 0; i < POKEMON_NAME_LENGTH; i++)
            boxMon->nickname[i] = data[i];
        break;
    }
    case MON_DATA_LANGUAGE:
        SET8(boxMon->language);
        break;
    case MON_DATA_SANITY_IS_BAD_EGG:
        SET8(boxMon->isBadEgg);
        break;
    case MON_DATA_SANITY_HAS_SPECIES:
        SET8(boxMon->hasSpecies);
        break;
    case MON_DATA_SANITY_IS_EGG:
        SET8(boxMon->isEgg);
        break;
    case MON_DATA_OT_NAME:
    {
        s32 i;
        for (i = 0; i < 7; i++)
            boxMon->otName[i] = data[i];
        break;
    }
    case MON_DATA_MARKINGS:
        SET8(boxMon->markings);
        break;
    case MON_DATA_CHECKSUM:
        SET16(boxMon->checksum);
        break;
    case MON_DATA_ENCRYPT_SEPARATOR:
        //SET16(boxMon->unknown);
        // should be unused?
        break;
    case MON_DATA_SPECIES:
    {
        SET16(substruct0->species);
        if (substruct0->species)
            boxMon->hasSpecies = 1;
        else
            boxMon->hasSpecies = 0;
        break;
    }
    case MON_DATA_HELD_ITEM:
        SET16(substruct0->heldItem);
        break;
    case MON_DATA_EXP:
        SET32(substruct0->experience);
        break;
    case MON_DATA_PP_BONUSES:
        SET8(substruct0->ppBonuses);
        break;
    case MON_DATA_FRIENDSHIP:
        SET8(substruct0->friendship);
        break;
    case MON_DATA_MOVE1:
    case MON_DATA_MOVE2:
    case MON_DATA_MOVE3:
    case MON_DATA_MOVE4:
        SET16(substruct1->moves[field - MON_DATA_MOVE1]);
        break;
    case MON_DATA_PP1:
    case MON_DATA_PP2:
    case MON_DATA_PP3:
    case MON_DATA_PP4:
        SET8(substruct1->pp[field - MON_DATA_PP1]);
        break;
    case MON_DATA_HP_EV:
        SET8(substruct2->hpEV);
        break;
    case MON_DATA_ATK_EV:
        SET8(substruct2->attackEV);
        break;
    case MON_DATA_DEF_EV:
        SET8(substruct2->defenseEV);
        break;
    case MON_DATA_SPEED_EV:
        SET8(substruct2->speedEV);
        break;
    case MON_DATA_SPATK_EV:
        SET8(substruct2->spAttackEV);
        break;
    case MON_DATA_SPDEF_EV:
        SET8(substruct2->spDefenseEV);
        break;
    case MON_DATA_NATURE_OVERRIDE:
        SET8(substruct2->natureOverride);
        break;
    case MON_DATA_FREE_EV:
        SET16(substruct2->freeEVs);
        break;
    case MON_DATA_SMART:
        SET8(substruct2->smart);
        break;
    case MON_DATA_TOUGH:
        SET8(substruct2->tough);
        break;
    case MON_DATA_SHEEN:
        SET8(substruct2->sheen);
        break;
    case MON_DATA_POKERUS:
        SET8(substruct3->pokerus);
        break;
    case MON_DATA_MET_LOCATION:
        SET8(substruct3->metLocation);
        break;
    case MON_DATA_MET_LEVEL:
    {
        u8 metLevel = *data;
        substruct3->metLevel = metLevel;
        break;
    }
    case MON_DATA_MET_GAME:
        SET8(substruct3->metGame);
        break;
    case MON_DATA_POKEBALL:
    {
        u8 pokeball = *data;
        substruct3->pokeball = pokeball;
        break;
    }
    case MON_DATA_OT_GENDER:
        SET8(substruct3->otGender);
        break;
    case MON_DATA_HP_IV:
        SET8(substruct3->hpIV);
        break;
    case MON_DATA_ATK_IV:
        SET8(substruct3->attackIV);
        break;
    case MON_DATA_DEF_IV:
        SET8(substruct3->defenseIV);
        break;
    case MON_DATA_SPEED_IV:
        SET8(substruct3->speedIV);
        break;
    case MON_DATA_SPATK_IV:
        SET8(substruct3->spAttackIV);
        break;
    case MON_DATA_SPDEF_IV:
        SET8(substruct3->spDefenseIV);
        break;
    case MON_DATA_IS_EGG:
        SET8(substruct3->isEgg);
        if (substruct3->isEgg)
            boxMon->isEgg = 1;
        else
            boxMon->isEgg = 0;
        break;
    case MON_DATA_ABILITY_NUM:
        SET8(substruct3->abilityNum);
        break;
    case MON_DATA_COOL_RIBBON:
        SET8(substruct3->coolRibbon);
        break;
    case MON_DATA_BEAUTY_RIBBON:
        SET8(substruct3->beautyRibbon);
        break;
    case MON_DATA_CUTE_RIBBON:
        SET8(substruct3->cuteRibbon);
        break;
    case MON_DATA_SMART_RIBBON:
        SET8(substruct3->smartRibbon);
        break;
    case MON_DATA_TOUGH_RIBBON:
        SET8(substruct3->toughRibbon);
        break;
    case MON_DATA_CHAMPION_RIBBON:
        SET8(substruct3->championRibbon);
        break;
    case MON_DATA_WINNING_RIBBON:
        SET8(substruct3->winningRibbon);
        break;
    case MON_DATA_VICTORY_RIBBON:
        SET8(substruct3->victoryRibbon);
        break;
    case MON_DATA_ARTIST_RIBBON:
        SET8(substruct3->artistRibbon);
        break;
    case MON_DATA_EFFORT_RIBBON:
        SET8(substruct3->effortRibbon);
        break;
    case MON_DATA_MARINE_RIBBON:
        SET8(substruct3->marineRibbon);
        break;
    case MON_DATA_LAND_RIBBON:
        SET8(substruct3->landRibbon);
        break;
    case MON_DATA_SKY_RIBBON:
        SET8(substruct3->skyRibbon);
        break;
    case MON_DATA_COUNTRY_RIBBON:
        SET8(substruct3->countryRibbon);
        break;
    case MON_DATA_NATIONAL_RIBBON:
        SET8(substruct3->nationalRibbon);
        break;
    case MON_DATA_EARTH_RIBBON:
        SET8(substruct3->earthRibbon);
        break;
    case MON_DATA_WORLD_RIBBON:
        SET8(substruct3->worldRibbon);
        break;
    case MON_DATA_HIDDEN_ABILITY:
        SET8(substruct3->hiddenAbility);
        break;
    case MON_DATA_FILLER:
        SET8(substruct3->filler);
        break;
    case MON_DATA_EVENT_LEGAL:
        SET8(substruct3->eventLegal);
        break;
    case MON_DATA_IVS:
    {
        u32 ivs = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
        substruct3->hpIV = ivs & 0x1F;
        substruct3->attackIV = (ivs >> 5) & 0x1F;
        substruct3->defenseIV = (ivs >> 10) & 0x1F;
        substruct3->speedIV = (ivs >> 15) & 0x1F;
        substruct3->spAttackIV = (ivs >> 20) & 0x1F;
        substruct3->spDefenseIV = (ivs >> 25) & 0x1F;
        break;
    }
    default:
        break;
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        boxMon->checksum = CalculateBoxMonChecksum(boxMon);
        EncryptBoxMon(boxMon);
    }
}

void CopyMon(void *dest, void *src, size_t size)
{
    memcpy(dest, src, size);
}

u8 GiveMonToPlayer(struct Pokemon *mon)
{
    s32 i;

    SetMonData(mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetMonData(mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
    SetMonData(mon, MON_DATA_OT_ID, gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }

    if (i >= PARTY_SIZE)
        return SendMonToPC(mon);

    CopyMon(&gPlayerParty[i], mon, sizeof(*mon));
    gPlayerPartyCount = i + 1;
    return MON_GIVEN_TO_PARTY;
}

static u8 SendMonToPC(struct Pokemon* mon)
{
    s32 boxNo, boxPos;

    SetPCBoxToSendMon(VarGet(VAR_PC_BOX_TO_SEND_MON));

    boxNo = StorageGetCurrentBox();

    do
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon* checkingMon = GetBoxedMonPtr(boxNo, boxPos);
            if (GetBoxMonData(checkingMon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            {
                MonRestorePP(mon);
                CopyMon(checkingMon, &mon->box, sizeof(mon->box));
                gSpecialVar_MonBoxId = boxNo;
                gSpecialVar_MonBoxPos = boxPos;
                if (GetPCBoxToSendMon() != boxNo)
                    FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
                VarSet(VAR_PC_BOX_TO_SEND_MON, boxNo);
                return MON_GIVEN_TO_PC;
            }
        }

        boxNo++;
        if (boxNo == TOTAL_BOXES_COUNT)
            boxNo = 0;
    } while (boxNo != StorageGetCurrentBox());

    return MON_CANT_GIVE;
}

u8 CalculatePlayerPartyCount(void)
{
    gPlayerPartyCount = 0;

    while (gPlayerPartyCount < PARTY_SIZE
        && GetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
    {
        gPlayerPartyCount++;
    }

    return gPlayerPartyCount;
}


u8 CalculateEnemyPartyCount(void)
{
    gEnemyPartyCount = 0;

    while (gEnemyPartyCount < PARTY_SIZE
        && GetMonData(&gEnemyParty[gEnemyPartyCount], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
    {
        gEnemyPartyCount++;
    }

    return gEnemyPartyCount;
}

u8 GetMonsStateToDoubles(void)
{
    s32 aliveCount = 0;
    s32 i;
    CalculatePlayerPartyCount();

    if (gPlayerPartyCount == 1)
        return gPlayerPartyCount; // PLAYER_HAS_ONE_MON

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        // FRLG changed the order of these checks, but there's no point to doing that
        // because of the requirement of all 3 of these checks.
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) != 0
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_NONE
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_EGG)
            aliveCount++;
    }

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u8 GetAbilityBySpecies(u16 species, bool8 abilityNum, bool8 hiddenAbility)
{
    if (hiddenAbility)
        gLastUsedAbility = gBaseStats[species].hiddenAbility;
    else if (abilityNum)
        gLastUsedAbility = gBaseStats[species].abilities[1];
    else
        gLastUsedAbility = gBaseStats[species].abilities[0];

    return gLastUsedAbility;
}

u8 GetMonAbility(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    u8 hiddenAbilityNum = GetMonData(mon, MON_DATA_HIDDEN_ABILITY, NULL);
    return GetAbilityBySpecies(species, abilityNum, hiddenAbilityNum);
}

static void CreateSecretBaseEnemyParty(struct SecretBaseRecord *secretBaseRecord)
{
    s32 i, j;

    ZeroEnemyPartyMons();
    *gBattleResources->secretBase = *secretBaseRecord;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleResources->secretBase->party.species[i])
        {
            CreateMon(&gEnemyParty[i],
                gBattleResources->secretBase->party.species[i],
                gBattleResources->secretBase->party.levels[i],
                15,
                1,
                gBattleResources->secretBase->party.personality[i],
                2,
                0);

            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleResources->secretBase->party.heldItems[i]);

            for (j = 0; j < 6; j++)
                SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &gBattleResources->secretBase->party.EVs[i]);

            for (j = 0; j < 4; j++)
            {
                SetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j, &gBattleResources->secretBase->party.moves[i * 4 + j]);
                SetMonData(&gEnemyParty[i], MON_DATA_PP1 + j, &gBattleMoves[gBattleResources->secretBase->party.moves[i * 4 + j]].pp);
            }
        }
    }
    gBattleTypeFlags = 8;
    gTrainerBattleOpponent_A = SECRET_BASE_OPPONENT;
}

u8 GetSecretBaseTrainerPicIndex(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gFacilityClassToPicIndex[facilityClass];
}

u8 GetSecretBaseTrainerNameIndex(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gFacilityClassToTrainerClass[facilityClass];
}

bool8 IsPlayerPartyAndPokemonStorageFull(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            return FALSE;

    return IsPokemonStorageFull();
}

static bool8 IsPokemonStorageFull(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
        for (j = 0; j < IN_BOX_COUNT; j++)
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
                return FALSE;

    return TRUE;
}

void GetSpeciesName(u8 *name, u16 species)
{
    s32 i;

    // Hmm? FRLG has < while Ruby/Emerald has <=
    for (i = 0; i < POKEMON_NAME_LENGTH; i++)
    {
        if (species > NUM_SPECIES)
            name[i] = gSpeciesNames[0][i];
        else
            name[i] = gSpeciesNames[species][i];

        if (name[i] == EOS)
            break;
    }

    name[i] = EOS;
}

u8 CalculatePPWithBonus(u16 move, u8 ppBonuses, u8 moveIndex)
{
    u8 basePP = gBattleMoves[move].pp;
    return basePP + ((basePP * 20 * ((gPPUpGetMask[moveIndex] & ppBonuses) >> (2 * moveIndex))) / 100);
}

void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex)
{
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses &= gPPUpSetMask[moveIndex];
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex)
{
    mon->ppBonuses &= gPPUpSetMask[moveIndex];
}

static void CopyPlayerPartyMonToBattleData(u8 battlerId, u8 partyIndex)
{
    u16* hpSwitchout;
    s32 i;
    u8 nickname[POKEMON_NAME_LENGTH * 2]; // Why is the nickname array here longer in FR/LG?

    gBattleMons[battlerId].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    gBattleMons[battlerId].item = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HELD_ITEM, NULL);

    for (i = 0; i < 4; i++)
    {
        gBattleMons[battlerId].moves[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE1 + i, NULL);
        gBattleMons[battlerId].pp[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP1 + i, NULL);
    }

    gBattleMons[battlerId].ppBonuses = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP_BONUSES, NULL);
    gBattleMons[battlerId].friendship = GetMonData(&gPlayerParty[partyIndex], MON_DATA_FRIENDSHIP, NULL);
    gBattleMons[battlerId].experience = GetMonData(&gPlayerParty[partyIndex], MON_DATA_EXP, NULL);
    gBattleMons[battlerId].hpIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP_IV, NULL);
    gBattleMons[battlerId].attackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK_IV, NULL);
    gBattleMons[battlerId].defenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF_IV, NULL);
    gBattleMons[battlerId].speedIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED_IV, NULL);
    gBattleMons[battlerId].spAttackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK_IV, NULL);
    gBattleMons[battlerId].spDefenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF_IV, NULL);
    gBattleMons[battlerId].personality = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PERSONALITY, NULL);
    gBattleMons[battlerId].status1 = GetMonData(&gPlayerParty[partyIndex], MON_DATA_STATUS, NULL);
    gBattleMons[battlerId].level = GetMonData(&gPlayerParty[partyIndex], MON_DATA_LEVEL, NULL);
    gBattleMons[battlerId].hp = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP, NULL);
    gBattleMons[battlerId].maxHP = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MAX_HP, NULL);
    gBattleMons[battlerId].attack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK, NULL);
    gBattleMons[battlerId].defense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF, NULL);
    gBattleMons[battlerId].speed = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED, NULL);
    gBattleMons[battlerId].spAttack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK, NULL);
    gBattleMons[battlerId].spDefense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF, NULL);
    gBattleMons[battlerId].isEgg = GetMonData(&gPlayerParty[partyIndex], MON_DATA_IS_EGG, NULL);
    gBattleMons[battlerId].abilityNum = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ABILITY_NUM, NULL);
    gBattleMons[battlerId].ability = GetMonAbility(&gPlayerParty[partyIndex]);
    gBattleMons[battlerId].otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID, NULL);
    gBattleMons[battlerId].type1 = gBaseStats[gBattleMons[battlerId].species].type1;
    gBattleMons[battlerId].type2 = gBaseStats[gBattleMons[battlerId].species].type2;
    gBattleMons[battlerId].ability = GetMonAbility(&gPlayerParty[partyIndex]);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, nickname);
    StringCopyN(gBattleMons[battlerId].nickname, nickname, POKEMON_NAME_LENGTH);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_NAME, gBattleMons[battlerId].otName);

    hpSwitchout = &gBattleStruct->hpOnSwitchout[GetBattlerSide(battlerId)];
    *hpSwitchout = gBattleMons[battlerId].hp;

    for (i = 0; i < 8; i++)
        gBattleMons[battlerId].statStages[i] = 6;

    gBattleMons[battlerId].status2 = 0;
    UpdateSentPokesToOpponentValue(battlerId);
    ClearTemporarySpeciesSpriteData(battlerId, FALSE);
}

bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex)
{
    return PokemonUseItemEffects(mon, item, partyIndex, moveIndex, 0);
}

bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, u8 e)
{
    u32 data;
    s32 friendship;
    s32 cmdIndex;
    bool8 retVal = TRUE;
    const u8 *itemEffect;
    u8 idx = 6;
    u32 i;
    s8 friendshipDelta = 0;
    u8 holdEffect;
    u8 battleMonId = 4;
    u16 heldItem;
    u8 val;
    u32 evDelta;

    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    if (heldItem == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[gBattlerInMenuId].holdEffect;
        else
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    gPotentialItemEffectBattler = gBattlerInMenuId;
    if (gMain.inBattle)
    {
        gActiveBattler = gBattlerInMenuId;
        cmdIndex = (GetBattlerSide(gActiveBattler) != B_SIDE_PLAYER);
        while (cmdIndex < gBattlersCount)
        {
            if (gBattlerPartyIndexes[cmdIndex] == partyIndex)
            {
                battleMonId = cmdIndex;
                break;
            }
            cmdIndex += 2;
        }
    }
    else
    {
        gActiveBattler = 0;
        battleMonId = 4;
    }

    if (!IS_POKEMON_ITEM(item))
        return TRUE;
    if (gItemEffectTable[item - ITEM_POTION] == NULL && item != ITEM_ENIGMA_BERRY)
        return TRUE;

    if (item == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            itemEffect = gEnigmaBerries[gActiveBattler].itemEffect;
        else
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    }
    else
    {
        itemEffect = gItemEffectTable[item - ITEM_POTION];
    }

    for (cmdIndex = 0; cmdIndex < 6; cmdIndex++)
    {
        switch (cmdIndex)
        {
        // status healing effects
        case 0:
            if ((itemEffect[cmdIndex] & ITEM0_INFATUATION)
                && gMain.inBattle && battleMonId != 4 && (gBattleMons[battleMonId].status2 & STATUS2_INFATUATION))
            {
                gBattleMons[battleMonId].status2 &= ~STATUS2_INFATUATION;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM0_HIGH_CRIT)
             && !(gBattleMons[gActiveBattler].status2 & STATUS2_FOCUS_ENERGY))
            {
                gBattleMons[gActiveBattler].status2 |= STATUS2_FOCUS_ENERGY;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM0_X_ATTACK)
             && gBattleMons[gActiveBattler].statStages[STAT_ATK] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_ATK] += itemEffect[cmdIndex] & ITEM0_X_ATTACK;
                if (gBattleMons[gActiveBattler].statStages[STAT_ATK] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_ATK] = 12;
                retVal = FALSE;
            }
            break;
        // in-battle stat boosting effects?
        case 1:
            if ((itemEffect[cmdIndex] & ITEM1_X_DEFEND)
             && gBattleMons[gActiveBattler].statStages[STAT_DEF] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_DEF] += (itemEffect[cmdIndex] & ITEM1_X_DEFEND) >> 4;
                if (gBattleMons[gActiveBattler].statStages[STAT_DEF] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_DEF] = 12;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM1_X_SPEED)
             && gBattleMons[gActiveBattler].statStages[STAT_SPEED] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_SPEED] += itemEffect[cmdIndex] & ITEM1_X_SPEED;
                if (gBattleMons[gActiveBattler].statStages[STAT_SPEED] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_SPEED] = 12;
                retVal = FALSE;
            }
            break;
        // more stat boosting effects?
        case 2:
            if ((itemEffect[cmdIndex] & ITEM2_X_ACCURACY)
             && gBattleMons[gActiveBattler].statStages[STAT_ACC] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_ACC] += (itemEffect[cmdIndex] & ITEM2_X_ACCURACY) >> 4;
                if (gBattleMons[gActiveBattler].statStages[STAT_ACC] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_ACC] = 12;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM2_X_SPATK)
             && gBattleMons[gActiveBattler].statStages[STAT_SPATK] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_SPATK] += itemEffect[cmdIndex] & ITEM2_X_SPATK;
                if (gBattleMons[gActiveBattler].statStages[STAT_SPATK] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_SPATK] = 12;
                retVal = FALSE;
            }
            break;
        case 3:
            if ((itemEffect[cmdIndex] & ITEM3_MIST)
             && gSideTimers[GetBattlerSide(gActiveBattler)].mistTimer == 0)
            {
                gSideTimers[GetBattlerSide(gActiveBattler)].mistTimer = 5;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM3_LEVEL_UP)  // raise level
             && GetMonData(mon, MON_DATA_LEVEL, NULL) != 100)
            {
                data = gExperienceTables[gBaseStats[GetMonData(mon, MON_DATA_SPECIES, NULL)].growthRate][GetMonData(mon, MON_DATA_LEVEL, NULL) + 1];
                SetMonData(mon, MON_DATA_EXP, &data);
                CalculateMonStats(mon);
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM3_SLEEP)
             && HealStatusConditions(mon, partyIndex, STATUS1_SLEEP, battleMonId) == 0)
            {
                if (battleMonId != 4)
                    gBattleMons[battleMonId].status2 &= ~STATUS2_NIGHTMARE;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & ITEM3_POISON) && HealStatusConditions(mon, partyIndex, STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER, battleMonId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_BURN) && HealStatusConditions(mon, partyIndex, STATUS1_BURN, battleMonId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_FREEZE) && HealStatusConditions(mon, partyIndex, STATUS1_FREEZE, battleMonId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_PARALYSIS) && HealStatusConditions(mon, partyIndex, STATUS1_PARALYSIS, battleMonId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_CONFUSION)  // heal confusion
             && gMain.inBattle && battleMonId != 4 && (gBattleMons[battleMonId].status2 & STATUS2_CONFUSION))
            {
                gBattleMons[battleMonId].status2 &= ~STATUS2_CONFUSION;
                retVal = FALSE;
            }
            break;
        // EV, HP, and PP raising effects
        case 4:
            val = itemEffect[cmdIndex];
            if (val & ITEM4_PP_UP)
            {
                val &= ~ITEM4_PP_UP;
                data = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                i = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                if (data < 3 && i > 4)
                {
                    data = GetMonData(mon, MON_DATA_PP_BONUSES, NULL) + gPPUpAddMask[moveIndex];
                    SetMonData(mon, MON_DATA_PP_BONUSES, &data);

                    data = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), data, moveIndex) - i;
                    data = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + data;
                    SetMonData(mon, MON_DATA_PP1 + moveIndex, &data);
                    retVal = FALSE;
                }
            }
            i = 0;
            while (val != 0)
            {
                if (val & 1)
                {
                    u16 evCount;
                    s32 r5;
     
                    switch (i)
                    {
                    case 0: // EV_HP
                    case 1: // EV_ATK
                        data = GetMonData(mon, sGetMonDataIVConstants[i], NULL);
                        if (data < 31)
                        {
                            if (data + itemEffect[idx] > 31)
                                evDelta = 31 - data;
                            else
                                evDelta = itemEffect[idx];
                            data += evDelta;
                            SetMonData(mon, sGetMonDataIVConstants[i], &data);
                            CalculateMonStats(mon);
                            idx++;
                            retVal = FALSE;
                        }
                        break;
                    case 2: // HEAL_HP
                        // revive?
                        if (val & (ITEM4_REVIVE >> 2))
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) != 0)
                            {
                                idx++;
                                break;
                            }
                            if (gMain.inBattle)
                            {
                                if (battleMonId != 4)
                                {
                                    gAbsentBattlerFlags &= ~gBitTable[battleMonId];
                                    CopyPlayerPartyMonToBattleData(battleMonId, GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battleMonId]));
                                    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleResults.numRevivesUsed < 255)
                                        gBattleResults.numRevivesUsed++;
                                }
                                else
                                {
                                    gAbsentBattlerFlags &= ~gBitTable[gActiveBattler ^ 2];
                                    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleResults.numRevivesUsed < 255)
                                        gBattleResults.numRevivesUsed++;
                                }
                            }
                        }
                        else
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) == 0)
                            {
                                idx++;
                                break;
                            }
                        }
                        data = itemEffect[idx++];
                        switch (data)
                        {
                        case 0xFF:
                            data = GetMonData(mon, MON_DATA_MAX_HP, NULL) - GetMonData(mon, MON_DATA_HP, NULL);
                            break;
                        case 0xFE:
                            data = GetMonData(mon, MON_DATA_MAX_HP, NULL) / 2;
                            if (data == 0)
                                data = 1;
                            break;
                        case 0xFD:
                            data = gBattleScripting.field_23;
                            break;
                        case 0xFC:
                            data = GetMonData(mon, MON_DATA_MAX_HP, NULL) / 4;
                            if (data == 0)
                                data = 1;
                            break;
                        }
                        if (GetMonData(mon, MON_DATA_MAX_HP, NULL) != GetMonData(mon, MON_DATA_HP, NULL))
                        {
                            if (e == 0)
                            {
                                data = GetMonData(mon, MON_DATA_HP, NULL) + data;
                                if (data > GetMonData(mon, MON_DATA_MAX_HP, NULL))
                                    data = GetMonData(mon, MON_DATA_MAX_HP, NULL);
                                SetMonData(mon, MON_DATA_HP, &data);
                                if (gMain.inBattle && battleMonId != 4)
                                {
                                    gBattleMons[battleMonId].hp = data;
                                    if (!(val & (ITEM4_REVIVE >> 2)) && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                                    {
                                        if (gBattleResults.numHealingItemsUsed < 255)
                                            gBattleResults.numHealingItemsUsed++;
                                        // I have to re-use this variable to match.
                                        r5 = gActiveBattler;
                                        gActiveBattler = battleMonId;
                                        BtlController_EmitGetMonData(0, 0, 0);
                                        MarkBattlerForControllerExec(gActiveBattler);
                                        gActiveBattler = r5;
                                    }
                                }
                            }
                            else
                            {
                                gBattleMoveDamage = -data;
                            }
                            retVal = FALSE;
                        }
                        val &= ~(ITEM4_REVIVE >> 2);
                        break;
                    case 3: // HEAL_PP_ALL
                        if (!(val & (ITEM4_HEAL_PP_ONE >> 3)))
                        {
                            for (r5 = 0; r5 < 4; r5++)
                            {
                                u16 move_id;

                                data = GetMonData(mon, MON_DATA_PP1 + r5, NULL);
                                move_id = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                if (data != CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5))
                                {
                                    data += itemEffect[idx];
                                    move_id = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                    if (data > CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5))
                                    {
                                        move_id = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                        data = CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5);
                                    }
                                    SetMonData(mon, MON_DATA_PP1 + r5, &data);
                                    if (gMain.inBattle
                                        && battleMonId != 4 && !(gBattleMons[battleMonId].status2 & STATUS2_TRANSFORMED)
                                        && !(gDisableStructs[battleMonId].mimickedMoves & gBitTable[r5]))
                                        gBattleMons[battleMonId].pp[r5] = data;
                                    retVal = FALSE;
                                }
                            }
                            idx++;
                        }
                        else
                        {
                            u16 move_id;

                            data = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL);
                            move_id = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                            if (data != CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                            {
                                data += itemEffect[idx++];
                                move_id = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                                if (data > CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                                {
                                    move_id = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                                    data = CalculatePPWithBonus(move_id, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                                }
                                SetMonData(mon, MON_DATA_PP1 + moveIndex, &data);
                                if (gMain.inBattle
                                    && battleMonId != 4 && !(gBattleMons[battleMonId].status2 & STATUS2_TRANSFORMED)
                                    && !(gDisableStructs[battleMonId].mimickedMoves & gBitTable[moveIndex]))
                                    gBattleMons[battleMonId].pp[moveIndex] = data;
                                retVal = FALSE;
                            }
                        }
                        break;
                    case 7: // EVO_STONE
                        {
                            u16 targetSpecies = GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item);

                            if (targetSpecies != SPECIES_NONE)
                            {
                                BeginEvolutionScene(mon, targetSpecies, 0, partyIndex);
                                return FALSE;
                            }
                        }
                        break;
                    }
                }
                i++;
                val >>= 1;
            }
            break;
        case 5:
            val = itemEffect[cmdIndex];
            i = 0;
            while (val != 0)
            {
                if (val & 1)
                {
                    u16 evCount;

                    switch (i)
                    {
                    case 0: // EV_DEF
                    case 1: // EV_SPEED
                    case 2: // EV_SPDEF
                    case 3: // EV_SPATK
                        data = GetMonData(mon, sGetMonDataIVConstants[i + 2], NULL);
                        if (data < 31)
                        {
                            if (data + itemEffect[idx] > 31)
                                evDelta = 31 - data;
                            else
                                evDelta = itemEffect[idx];
                            data += evDelta;
                            SetMonData(mon, sGetMonDataIVConstants[i + 2], &data);
                            CalculateMonStats(mon);
                            retVal = FALSE;
                            idx++;
                        }
                        break;
                    case 4: // PP_MAX
                        data = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                        if (data < 3)
                        {
                            evDelta = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                            data = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
                            data &= gPPUpSetMask[moveIndex];
                            data += gPPUpAddMask[moveIndex] * 3;

                            SetMonData(mon, MON_DATA_PP_BONUSES, &data);
                            data = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), data, moveIndex) - evDelta;
                            data = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + data;
                            SetMonData(mon, MON_DATA_PP1 + moveIndex, &data);
                            retVal = FALSE;
                        }
                        break;
                    case 5: // EFFORT_CLEAR
						evDelta = 0;
						{
							u8 whichEv = 0;
							for (whichEv = 0; whichEv < 6; whichEv++)
							{
								data = GetMonData(mon, MON_DATA_HP_EV + whichEv, NULL);
								if (data > 0)
								{
									evDelta += data;
									data = 0;
									SetMonData(mon, MON_DATA_HP_EV + whichEv, &data);
								}
							}
						}
						if (evDelta > 0)
						{
							data = GetMonData(mon, MON_DATA_FREE_EV, NULL);
							data += evDelta;
							if (data > 999)
								data = 999;
							SetMonData(mon, MON_DATA_FREE_EV, &data);
							retVal = FALSE;
						}
                        break;
                    case 6: // FRIENDSHIP_MID
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 100 && GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 200
                            && retVal == 0 && friendshipDelta == 0)
                        {
                            friendshipDelta = itemEffect[idx];
                            friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
                            if (friendshipDelta > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                                friendship += 150 * friendshipDelta / 100;
                            else
                                friendship += friendshipDelta;
                            if (friendshipDelta > 0)
                            {
                                if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == 11)
                                    friendship++;
                                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == GetCurrentRegionMapSectionId())
                                    friendship++;
                            }
                            if (friendship < 0)
                                friendship = 0;
                            if (friendship > 255)
                                friendship = 255;
                            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
                        }
                        idx++;
                        break;
                    case 7: // FRIENDSHIP_HIGH
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 200 && retVal == 0 && friendshipDelta == 0)
                        {
                            friendshipDelta = itemEffect[idx];
                            friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
                            if (friendshipDelta > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                                friendship += 150 * friendshipDelta / 100;
                            else
                                friendship += friendshipDelta;
                            if (friendshipDelta > 0)
                            {
                                if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == 11)
                                    friendship++;
                                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == GetCurrentRegionMapSectionId())
                                    friendship++;
                            }
                            if (friendship < 0)
                                friendship = 0;
                            if (friendship > 255)
                                friendship = 255;
                            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
                        }
                        idx++;
                        break;
                    }
                }
                i++;
                val >>= 1;
            }
            break;
        }
    }
    return retVal;
}

static bool8 HealStatusConditions(struct Pokemon *mon, u32 unused, u32 healMask, u8 battleId)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS, NULL);

    if (status & healMask)
    {
        status &= ~healMask;
        SetMonData(mon, MON_DATA_STATUS, &status);
        if (gMain.inBattle && battleId != 4)
            gBattleMons[battleId].status1 &= ~healMask;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool8 PokemonItemUseNoEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex)
{
    u32 data;
    s32 tmp;
    s32 cmdIndex;
    bool8 retVal = TRUE;
    const u8 *itemEffect;
    u8 idx = 6;
    u32 i;
    s32 sp18 = 0;
    u8 holdEffect;
    u8 battlerId = 4;
    u16 heldItem;
    u8 curEffect;
    u32 curMoveId;

    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    // you have to write as such, because otherwise gMain.inBattle will lose its u8 cast
    if (heldItem == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[gBattlerInMenuId].holdEffect;
        else
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }
    gPotentialItemEffectBattler = gBattlerInMenuId;
    if (gMain.inBattle)
    {
        gActiveBattler = gBattlerInMenuId;
        for (cmdIndex = GetBattlerSide(gActiveBattler) != B_SIDE_PLAYER;
             cmdIndex < gBattlersCount;
             cmdIndex += 2)
        {
            if (gBattlerPartyIndexes[cmdIndex] == partyIndex) 
            {
                battlerId = cmdIndex;
                break;
            }
        }
    }
    else
    {
        gActiveBattler = 0;
        battlerId = 4;
    }
    if (!IS_POKEMON_ITEM(item))
        return TRUE;
    if (gItemEffectTable[item - ITEM_POTION] == NULL && item != ITEM_ENIGMA_BERRY)
        return TRUE;
    if (item == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            itemEffect = gEnigmaBerries[gActiveBattler].itemEffect;
        else
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    }
    else
    {
        itemEffect = gItemEffectTable[item - 13];
    }
    for (cmdIndex = 0; cmdIndex < 6; cmdIndex++)
    {
        switch (cmdIndex)
        {
        // status healing effects
        case 0:
            if (itemEffect[cmdIndex] & ITEM0_INFATUATION
             && gMain.inBattle
             && battlerId != 4
             && gBattleMons[battlerId].status2 & STATUS2_INFATUATION)
                retVal = FALSE;
            if (itemEffect[cmdIndex] & ITEM0_HIGH_CRIT
             && !(gBattleMons[gActiveBattler].status2 & STATUS2_FOCUS_ENERGY))
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM0_X_ATTACK)
             && gBattleMons[gActiveBattler].statStages[STAT_ATK] < 12)
                retVal = FALSE;
            break;
        // in-battle stat boosting effects?
        case 1:
            if ((itemEffect[cmdIndex] & ITEM1_X_DEFEND)
             && gBattleMons[gActiveBattler].statStages[STAT_DEF] < 12)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM1_X_SPEED)
             && gBattleMons[gActiveBattler].statStages[STAT_SPEED] < 12)
                retVal = FALSE;
            break;
        // more stat boosting effects?
        case 2:
            if ((itemEffect[cmdIndex] & ITEM2_X_ACCURACY)
             && gBattleMons[gActiveBattler].statStages[STAT_ACC] < 12)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM2_X_SPATK)
             && gBattleMons[gActiveBattler].statStages[STAT_SPATK] < 12)
                retVal = FALSE;
            break;
        case 3:
            if ((itemEffect[cmdIndex] & ITEM3_MIST)
             && gSideTimers[GetBattlerSide(gActiveBattler)].mistTimer == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_LEVEL_UP)  // raise level
             && GetMonData(mon, MON_DATA_LEVEL, NULL) != 100)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_SLEEP)
             && PartyMonHasStatus(mon, partyIndex, STATUS1_SLEEP, battlerId))
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_POISON) && PartyMonHasStatus(mon, partyIndex, STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER, battlerId))
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_BURN) && PartyMonHasStatus(mon, partyIndex, STATUS1_BURN, battlerId))
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_FREEZE) && PartyMonHasStatus(mon, partyIndex, STATUS1_FREEZE, battlerId))
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & ITEM3_PARALYSIS) && PartyMonHasStatus(mon, partyIndex, STATUS1_PARALYSIS, battlerId))
                retVal = FALSE;
            if (itemEffect[cmdIndex] & ITEM3_CONFUSION // heal confusion
             && gMain.inBattle && battlerId != 4 && (gBattleMons[battlerId].status2 & STATUS2_CONFUSION))
                retVal = FALSE;
            break;
        // EV, HP, and PP raising effects
        case 4:
            curEffect = itemEffect[cmdIndex];
            if (curEffect & ITEM4_PP_UP)
            {
                curEffect &= ~ITEM4_PP_UP;
                data = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                i = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                if (data < 3 && i > 4)
                    retVal = FALSE;
            }
            i = 0;
            while (curEffect) // _080428C0
            {
                if (curEffect & 1)
                {
                    switch (i)
                    {
                    case 0: // EV_HP
                    case 1: // EV_ATK
                        if (GetMonEVCount(mon) >= 510)
                            return TRUE;
                        data = GetMonData(mon, sGetMonDataEVConstants[i], NULL);
                        if (data < 100)
                        {
                            idx++;
                            retVal = FALSE;
                        }
                        break;
                    case 2: // HEAL_HP
                        // revive?
                        if (curEffect & (ITEM4_REVIVE >> 2))
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) != 0)
                            {
                                idx++;
                                break;
                            }
                        }
                        else
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) == 0)
                            {
                                idx++;
                                break;
                            }
                        }
                        if (GetMonData(mon, MON_DATA_MAX_HP, NULL) != GetMonData(mon, MON_DATA_HP, NULL))
                            retVal = FALSE;
                        idx++;
                        curEffect &= ~(ITEM4_REVIVE >> 2);
                        break;
                    case 3:
                        if (!(curEffect & (ITEM4_HEAL_PP_ONE >> 3)))
                        {
                            for (tmp = 0; tmp < MAX_MON_MOVES; tmp++)
                            {
                                data = GetMonData(mon, MON_DATA_PP1 + tmp, NULL);
                                if (data != CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + tmp, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), tmp))
                                    retVal = FALSE;
                            }
                            idx++;
                        }
                        else // _080429FA
                        {
                            data = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL);
                            curMoveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                            if (data != CalculatePPWithBonus(curMoveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                            {
                                idx++;
                                retVal = FALSE;
                            }
                        }
                        break;
                    case 7:
                        if (GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item) != SPECIES_NONE)
                            return FALSE;
                        break;
                    }
                }
                i++;
                curEffect >>= 1;
            }
            break;
        case 5:
            curEffect = itemEffect[cmdIndex];
            i = 0;
            while (curEffect)
            {
                if (curEffect & 1)
                {
                    switch (i)
                    {
                    case 0: // EV_DEF
                    case 1: // EV_SPEED
                    case 2: // EV_SPDEF
                    case 3: // EV_SPATK
                        if (GetMonEVCount(mon) >= 510)
                            return TRUE;
                        data = GetMonData(mon, sGetMonDataEVConstants[i + 2], NULL);
                        if (data < 100)
                        {
                            retVal = FALSE;
                            idx++;
                        }
                        break;
                    case 4: // PP_MAX
                        data = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                        tmp = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                        if (data < 3 && tmp > 4)
                            retVal = FALSE;
                        break;
                    case 5: // EFFORT_CLEAR
						{
							u8 whichEv;
							data = 0;
							for (whichEv = 0; whichEv < 6; whichEv++)
							{
								data = GetMonData(mon, MON_DATA_HP_EV + whichEv, NULL);
								if (data)
								{
									whichEv = 6;
									retVal = FALSE;
								}
							}
						}
                        break;
                    case 6: // FRIENDSHIP_MID
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 100
                         && GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 200
                         && retVal == FALSE
                         && sp18 == 0)
                            sp18 = itemEffect[idx];
                        idx++;
                        break;
                    case 7: // FRIENDSHIP_HIGH
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 200
                         && retVal == FALSE
                         && sp18 == 0)
                            sp18 = itemEffect[idx];
                        idx++;
                        break;
                    }
                }
                i++;
                curEffect >>= 1;
            }
            break;
        }
    }
    return retVal;
}

static bool8 PartyMonHasStatus(struct Pokemon *mon, u32 unused, u32 healMask, u8 battleId)
{
    if ((GetMonData(mon, MON_DATA_STATUS, NULL) & healMask) != 0)
        return TRUE;
    else
        return FALSE;
}

u8 GetItemEffectParamOffset(u16 itemId, u8 effectByte, u8 effectBit)
{
    const u8 *temp;
    const u8 *itemEffect;
    u8 offset;
    int i;
    u8 j;
    u8 val;

    offset = 6;

    temp = gItemEffectTable[itemId - 13];

    if (!temp && itemId != ITEM_ENIGMA_BERRY)
        return 0;

    if (itemId == ITEM_ENIGMA_BERRY)
    {
        temp = gEnigmaBerries[gActiveBattler].itemEffect;
    }

    itemEffect = temp;

    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            if (i == effectByte)
                return 0;
            break;
        case 4:
            val = itemEffect[4];
            if (val & 0x20)
                val &= 0xDF;
            j = 0;
            while (val)
            {
                if (val & 1)
                {
                    switch (j)
                    {
                    case 2:
                        if (val & 0x10)
                            val &= 0xEF;
                    case 0:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 1:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 3:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7:
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                val >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        case 5:
            val = itemEffect[5];
            j = 0;
            while (val)
            {
                if (val & 1)
                {
                    switch (j)
                    {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7:
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                val >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        }
    }

    return offset;
}

static void BufferStatRoseMessage(int stat)
{
    gBattlerTarget = gBattlerInMenuId;
    StringCopy(gBattleTextBuff1, gStatNamesTable[sStatsToRaise[stat]]);
    StringCopy(gBattleTextBuff2, gBattleText_Rose);
    BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnsStatChanged2);
}

const u8 *Battle_PrintStatBoosterEffectMessage(u16 itemId)
{
    int i;
    const u8 *itemEffect;

    if (itemId == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
        {
            itemEffect = gEnigmaBerries[gBattlerInMenuId].itemEffect;
        }
        else
        {
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        }
    }
    else
    {
        itemEffect = gItemEffectTable[itemId - 13];
    }

    gPotentialItemEffectBattler = gBattlerInMenuId;

    for (i = 0; i < 3; i++)
    {
        if (itemEffect[i] & 0xF)
            BufferStatRoseMessage(i * 2);
        if (itemEffect[i] & 0xF0)
        {
            if (i)
            {
                BufferStatRoseMessage(i * 2 + 1);
            }
            else
            {
                gBattlerAttacker = gBattlerInMenuId;
                BattleStringExpandPlaceholdersToDisplayedString(gBattleText_GetPumped);
            }
        }
    }

    if (itemEffect[3] & 0x80)
    {
        gBattlerAttacker = gBattlerInMenuId;
        BattleStringExpandPlaceholdersToDisplayedString(gBattleText_MistShroud);
    }

    return gDisplayedStringBattle;
}

u8 GetNature(struct Pokemon *mon)
{
    u8 natureOverride = GetMonData(mon, MON_DATA_NATURE_OVERRIDE, NULL);
    if (natureOverride)
        return natureOverride;
    return GetMonData(mon, MON_DATA_PERSONALITY, NULL) % 25;
}

u8 GetUnderlyingNature(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_PERSONALITY, NULL) % 25;
}

u8 GetNatureFromPersonality(u32 personality)
{
    return personality % 25;
}

u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u8 type, u16 evolutionItem)
{
    int i;
    u16 targetSpecies = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    u8 level;
    u16 friendship;
    u16 upperPersonality = personality >> 16;
    u8 holdEffect;

    if (heldItem == ITEM_ENIGMA_BERRY)
        holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(heldItem);

    if (holdEffect == HOLD_EFFECT_PREVENT_EVOLVE && type != EVO_MODE_ITEM_CHECK)
        return 0;

    switch (type)
    {
    case EVO_MODE_NORMAL:
        level = GetMonData(mon, MON_DATA_LEVEL, NULL);
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);

        for (i = 0; i < 5; i++)
        {
            switch (gEvolutionTable[species][i].method)
            {
            case EVO_FRIENDSHIP:
                if (friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            // FR/LG removed the time of day evolutions due to having no RTC.
            case EVO_FRIENDSHIP_DAY:
                /*
                RtcCalcLocalTime();
                if (gLocalTime.hours >= 12 && gLocalTime.hours < 24 && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                */
                break;
            case EVO_FRIENDSHIP_NIGHT:
                /*
                RtcCalcLocalTime();
                if (gLocalTime.hours >= 0 && gLocalTime.hours < 12 && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                */
                break;
            case EVO_LEVEL:
                if (gEvolutionTable[species][i].levelReq <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_HELD_ITEM:
                if (gEvolutionTable[species][i].levelReq <= level &&
                    gEvolutionTable[species][i].param == heldItem)
                {
                    heldItem = 0;
                    SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                }
                break;
            case EVO_LEVEL_ATK_GT_DEF:
                if (gEvolutionTable[species][i].levelReq <= level)
                    if (GetMonData(mon, MON_DATA_ATK, NULL) > GetMonData(mon, MON_DATA_DEF, NULL))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_EQ_DEF:
                if (gEvolutionTable[species][i].levelReq <= level)
                    if (GetMonData(mon, MON_DATA_ATK, NULL) == GetMonData(mon, MON_DATA_DEF, NULL))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_LT_DEF:
                if (gEvolutionTable[species][i].levelReq <= level)
                    if (GetMonData(mon, MON_DATA_ATK, NULL) < GetMonData(mon, MON_DATA_DEF, NULL))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_SILCOON:
                if (gEvolutionTable[species][i].levelReq <= level && (upperPersonality % 10) <= 4)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_CASCOON:
                if (gEvolutionTable[species][i].levelReq <= level && (upperPersonality % 10) > 4)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_NINJASK:
                if (gEvolutionTable[species][i].levelReq <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_BEAUTY:
                //if (gEvolutionTable[species][i].param <= beauty)
                    //targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_TRADE:
        for (i = 0; i < 5; i++)
        {
            switch (gEvolutionTable[species][i].method)
            {
            case EVO_TRADE:
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_TRADE_ITEM:
                if (gEvolutionTable[species][i].param == heldItem)
                {
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                    if (IsNationalPokedexEnabled() || targetSpecies <= 151)
                    {
                        heldItem = 0;
                        SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                    }
                }
                break;
            }
        }
        break;
    case EVO_MODE_ITEM_USE:
    case EVO_MODE_ITEM_CHECK:
        for (i = 0; i < 5; i++)
        {
            if (gEvolutionTable[species][i].method == EVO_ITEM
             && gEvolutionTable[species][i].param == evolutionItem)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            }
        }
        break;
    }

    return targetSpecies;
}


u16 NationalPokedexNumToSpecies(u16 nationalNum)
{
    u16 species;

    if (!nationalNum)
        return 0;

    species = 0;

    while (species < NUM_SPECIES - 1 && sSpeciesToNationalPokedexNum[species] != nationalNum)
        species++;

    if (species == NUM_SPECIES - 1)
        return 0;

    return species + 1;
}

u16 SpeciesToNationalPokedexNum(u16 species)
{
    if (!species)
        return 0;

    return sSpeciesToNationalPokedexNum[species - 1];
}

u16 SpeciesToCryId(u16 species)
{
    return species;
}

void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies)
{
    u8 language;
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
    language = GetMonData(mon, MON_DATA_LANGUAGE, &language);
    if (language == GAME_LANGUAGE && !StringCompare(gSpeciesNames[oldSpecies], gStringVar1))
        SetMonData(mon, MON_DATA_NICKNAME, gSpeciesNames[newSpecies]);
}

bool8 GetPlayerFlankId(void)
{
    bool8 retVal = FALSE;
    switch (gLinkPlayers[GetMultiplayerId()].id)
    {
    case 0:
    case 3:
        retVal = FALSE;
        break;
    case 1:
    case 2:
        retVal = TRUE;
        break;
    }
    return retVal;
}

bool16 GetLinkTrainerFlankId(u8 linkPlayerId)
{
    bool16 retVal = FALSE;
    switch (gLinkPlayers[linkPlayerId].id)
    {
    case 0:
    case 3:
        retVal = FALSE;
        break;
    case 1:
    case 2:
        retVal = TRUE;
        break;
    }
    return retVal;
}

s32 GetBattlerMultiplayerId(u16 a1)
{
    s32 id;
    for (id = 0; id < MAX_LINK_PLAYERS; id++)
        if (gLinkPlayers[id].id == a1)
            break;
    return id;
}

u8 GetTrainerEncounterMusicId(u16 trainer)
{
    return gTrainers[trainer].encounterMusic_gender & 0x7F;
}

u16 ModifyStatByNature(u8 nature, u16 n, u8 statIndex)
{
    if (statIndex < 1 || statIndex > 5)
    {
        // should just be "return n", but it wouldn't match without this
        u16 retVal = n;
        retVal++;
        retVal--;
        return retVal;
    }

    switch (gNatureStatTable[nature][statIndex - 1])
    {
    case 1:
        return (u16)(n * 110) / 100;
    case -1:
        return (u16)(n * 90) / 100;
    }

    return n;
}

void AdjustFriendship(struct Pokemon *mon, u8 event)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    u8 holdEffect;

    if (heldItem == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[0].holdEffect;
        else
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    if (species && species != SPECIES_EGG)
    {
        s8 delta;
        // Friendship level refers to the column in sFriendshipEventDeltas.
        // 0-99: Level 0 (maximum increase, typically)
        // 100-199: Level 1
        // 200-255: Level 2
        u8 friendshipLevel = 0;
        s16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
        if (friendship >= 100)
            friendshipLevel++;
        if (friendship >= 200)
            friendshipLevel++;

        if (event == FRIENDSHIP_EVENT_WALKING)
        {
            // 50% chance every 128 steps
            if (Random() & 1)
                return;
        }
        if (event == FRIENDSHIP_EVENT_LEAGUE_BATTLE)
        {
            // Only if it's a trainer battle with league progression significance
            if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
                return;
            if (!(gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_LEADER
                || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_ELITE_FOUR
                || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_CHAMPION))
                return;
        }

        delta = sFriendshipEventDeltas[event][friendshipLevel];
        if (delta > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
            // 50% increase, rounding down
            delta = (150 * delta) / 100;

        friendship += delta;
        if (delta > 0)
        {
            if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == ITEM_LUXURY_BALL)
                friendship++;
            if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == GetCurrentRegionMapSectionId())
                friendship++;
        }

        // Clamp to u8
        if (friendship < 0)
            friendship = 0;
        if (friendship > 255)
            friendship = 255;

        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
    }
}

void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies)
{
    u16 currentFreeEVs = GetMonData(mon, MON_DATA_FREE_EV, NULL);
    u16 heldItem;
    u8 holdEffect;
    
    currentFreeEVs += 1;
    
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    holdEffect = ItemId_GetHoldEffect(heldItem);
    
    if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
        currentFreeEVs++;
    
    if (CheckPartyHasHadPokerus(mon, 0))
        currentFreeEVs++;
    
    if (currentFreeEVs > 999)
        currentFreeEVs = 999;
    
    SetMonData(mon, MON_DATA_FREE_EV, &currentFreeEVs);
    
    /*
    u8 evs[NUM_STATS];
    u16 evIncrease = 0;
    u16 totalEVs = 0;
    u16 heldItem;
    u8 holdEffect;
    int i;

    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = GetMonData(mon, MON_DATA_HP_EV + i, NULL);
        totalEVs += evs[i];
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        u8 hasHadPokerus;
        int multiplier;

        if (totalEVs >= MAX_TOTAL_EVS)
            break;

        hasHadPokerus = CheckPartyHasHadPokerus(mon, 0);

        if (hasHadPokerus)
            multiplier = 2;
        else
            multiplier = 1;

        switch (i)
        {
        case 0:
            evIncrease = gBaseStats[defeatedSpecies].evYield_HP * multiplier;
            break;
        case 1:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Attack * multiplier;
            break;
        case 2:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Defense * multiplier;
            break;
        case 3:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Speed * multiplier;
            break;
        case 4:
            evIncrease = gBaseStats[defeatedSpecies].evYield_SpAttack * multiplier;
            break;
        case 5:
            evIncrease = gBaseStats[defeatedSpecies].evYield_SpDefense * multiplier;
            break;
        }

        heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);

        if (heldItem == ITEM_ENIGMA_BERRY)
        {
            if (gMain.inBattle)
                holdEffect = gEnigmaBerries[0].holdEffect;
            else
                holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        }
        else
        {
            holdEffect = ItemId_GetHoldEffect(heldItem);
        }

        if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
            evIncrease *= 2;

        if (totalEVs + (s16)evIncrease > MAX_TOTAL_EVS)
            evIncrease = ((s16)evIncrease + MAX_TOTAL_EVS) - (totalEVs + evIncrease);

        if (evs[i] + (s16)evIncrease > 255)
        {
            int val1 = (s16)evIncrease + 255;
            int val2 = evs[i] + evIncrease;
            evIncrease = val1 - val2;
        }

        evs[i] += evIncrease;
        totalEVs += evIncrease;
        SetMonData(mon, MON_DATA_HP_EV + i, &evs[i]);
    } */
}

u16 GetMonEVCount(struct Pokemon *mon)
{
    int i;
    u16 count = 0;

    for (i = 0; i < NUM_STATS; i++)
        count += GetMonData(mon, MON_DATA_HP_EV + i, NULL);

    return count;
}

// This function was stubbed from RS, but it is stubbed badly.
// This variable is likely the u8 passed to SetMonData in RSE.
// The pointer reference causes agbcc to reserve it on the stack before even checking
// whether it's used.
void RandomlyGivePartyPokerus(struct Pokemon *party)
{
    u8 foo;
    &foo;
}

u8 CheckPartyPokerus(struct Pokemon *party, u8 party_bm)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (party_bm != 0) // Check mons in party based on bitmask, LSB = first mon
    {
        do
        {
            if ((party_bm & 1) && (GetMonData(&party[partyIndex], MON_DATA_POKERUS, NULL) & 0xF))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            party_bm >>= 1;
        }
        while (party_bm);
    }
    else // Single Pokemon
    {
        if (GetMonData(&party[0], MON_DATA_POKERUS, NULL) & 0xF)
        {
            retVal = 1;
        }
    }
    return retVal;
}

u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && GetMonData(&party[partyIndex], MON_DATA_POKERUS, NULL))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS, NULL))
    {
        retVal = 1;
    }

    return retVal;
}

// These two functions are stubbed from RS, but they're stubbed badly.
// See note on RandomlyGivePartyPokerus above.
static void UpdatePartyPokerusTime(void)
{
    u8 foo;
    &foo;
}

void PartySpreadPokerus(struct Pokemon *party)
{
    u8 foo;
    &foo;
}

static void SetMonExpWithMaxLevelCheck(struct Pokemon *mon, int species, u8 unused, u32 data)
{
    if (data > gExperienceTables[gBaseStats[species].growthRate][100])
    {
        data = gExperienceTables[gBaseStats[species].growthRate][100];
        SetMonData(mon, MON_DATA_EXP, &data);
    }
}

bool8 TryIncrementMonLevel(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    u8 newLevel = level + 1;
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);

    if (level < 100)
    {
        if (exp > gExperienceTables[gBaseStats[species].growthRate][newLevel])
        {
            SetMonData(mon, MON_DATA_LEVEL, &newLevel);
            SetMonExpWithMaxLevelCheck(mon, species, newLevel, exp);
            return TRUE;
        }
        else
            return FALSE;
    }
    else
    {
        SetMonExpWithMaxLevelCheck(mon, species, level, exp);
        return FALSE;
    }
}

u32 CanMonLearnTMHM(struct Pokemon *mon, u8 tm)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    if (species == SPECIES_EGG)
    {
        return 0;
    }
    else
    {
        u32 mask = 1 << (tm % 32);
        return sTMHMLearnsets[species][tm / 32] & mask;
    }
}

u8 GetMoveRelearnerMoves(struct Pokemon *mon, u16 *moves)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    int i, j, k;

    for (i = 0; i < 4; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);

    for (i = 0; i < 20; i++)
    {
        u16 moveLevel;

        if (gLevelUpLearnsets[species][i] == 0xFFFF)
            break;

        moveLevel = gLevelUpLearnsets[species][i] & 0xFE00;

        if (moveLevel <= (level << 9))
        {
            for (j = 0; j < 4 && learnedMoves[j] != (gLevelUpLearnsets[species][i] & 0x1FF); j++)
                ;

            if (j == 4)
            {
                for (k = 0; k < numMoves && moves[k] != (gLevelUpLearnsets[species][i] & 0x1FF); k++)
                    ;

                if (k == numMoves)
                    moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;
            }
        }
    }

    return numMoves;
}

u8 GetEggRelearnerMoves(struct Pokemon *mon, u16 *moves)
{
	u8 i = 0;
	u8 movesindex = 0;
	u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
	u16 knownmoves[4];
	u16 currMove;
	
	knownmoves[0] = GetMonData(mon, MON_DATA_MOVE1, 0);
	knownmoves[1] = GetMonData(mon, MON_DATA_MOVE2, 0);
	knownmoves[2] = GetMonData(mon, MON_DATA_MOVE3, 0);
	knownmoves[3] = GetMonData(mon, MON_DATA_MOVE4, 0);
	
	if (species == SPECIES_AKYUU)
	{
		u8 j;
		u8 k;
		for (j = 0; j < 6; j++)
		{
			for (k = 0; k < 4; k++)
			{
				currMove = GetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + k, 0);
				if (currMove && currMove != knownmoves[0] && currMove != knownmoves[1] && currMove != knownmoves[2] && currMove != knownmoves[3])
				{
					moves[movesindex] = currMove;
					movesindex++;
				}
			}
		}
	}
	else
	{
		while (gEggMoveLearnsets[species][i] != 0)
		{
			currMove = gEggMoveLearnsets[species][i];
			if (currMove != knownmoves[0] && currMove != knownmoves[1] && currMove != knownmoves[2] && currMove != knownmoves[3])
			{
				moves[movesindex] = gEggMoveLearnsets[species][i];
				movesindex++;
			}
			i++;
		}
	}
	
	
	return movesindex;
}

u8 GetLevelUpMovesBySpecies(u16 species, u16 *moves)
{
    u8 numMoves = 0;
    int i;

    for (i = 0; i < 20 && gLevelUpLearnsets[species][i] != 0xFFFF; i++)
         moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;

     return numMoves;
}

u8 GetNumberOfRelearnableMoves(struct Pokemon *mon)
{
    u16 learnedMoves[4];
    u16 moves[20];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    int i, j, k;

    if (species == SPECIES_EGG)
        return 0;

    for (i = 0; i < 4; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);

    for (i = 0; i < 20; i++)
    {
        u16 moveLevel;

        if (gLevelUpLearnsets[species][i] == 0xFFFF)
            break;

        moveLevel = gLevelUpLearnsets[species][i] & 0xFE00;

        if (moveLevel <= (level << 9))
        {
            for (j = 0; j < 4 && learnedMoves[j] != (gLevelUpLearnsets[species][i] & 0x1FF); j++)
                ;

            if (j == 4)
            {
                for (k = 0; k < numMoves && moves[k] != (gLevelUpLearnsets[species][i] & 0x1FF); k++)
                    ;

                if (k == numMoves)
                    moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;
            }
        }
    }

    return numMoves;
}

u8 GetNumberOfEggLearnableMoves(struct Pokemon *mon)
{
	u8 i = 0;
	u8 movesindex = 0;
	u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
	u16 knownmoves[4];
	u16 currMove;
	
	knownmoves[0] = GetMonData(mon, MON_DATA_MOVE1, 0);
	knownmoves[1] = GetMonData(mon, MON_DATA_MOVE2, 0);
	knownmoves[2] = GetMonData(mon, MON_DATA_MOVE3, 0);
	knownmoves[3] = GetMonData(mon, MON_DATA_MOVE4, 0);
	
	if (species == SPECIES_AKYUU)
	{
		u8 j;
		u8 k;
		for (j = 0; j < 6; j++)
		{
			for (k = 0; k < 4; k++)
			{
				currMove = GetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + k, 0);
				if (currMove && currMove != knownmoves[0] && currMove != knownmoves[1] && currMove != knownmoves[2] && currMove != knownmoves[3])
				{
					movesindex++;
				}
			}
		}
	}
	else
	{
		while (gEggMoveLearnsets[species][i] != 0)
		{
			currMove = gEggMoveLearnsets[species][i];
			if (currMove != knownmoves[0] && currMove != knownmoves[1] && currMove != knownmoves[2] && currMove != knownmoves[3])
			{
				movesindex++;
			}
			i++;
		}
	}
	return movesindex;
}

u16 SpeciesToPokedexNum(u16 species)
{
    species = SpeciesToNationalPokedexNum(species);
    return species;
}

void ClearBattleMonForms(void)
{
    int i;
    for (i = 0; i < 4; i++)
        gBattleMonForms[i] = 0;
}

static u16 GetBattleBGM(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        return MUS_VS_WILD;
    if (gBattleTypeFlags & BATTLE_TYPE_REGI)
        return MUS_RS_VS_TRAINER;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        return MUS_RS_VS_TRAINER;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        switch (gTrainers[gTrainerBattleOpponent_A].trainerClass)
        {
        case TRAINER_CLASS_CHAMPION:
            return MUS_VS_CHAMPION;
        case TRAINER_CLASS_LEADER:
        case TRAINER_CLASS_ELITE_FOUR:
            return MUS_VS_GYM_LEADER;
        case TRAINER_CLASS_STRANGER:
        case TRAINER_CLASS_WILD:
		case TRAINER_CLASS_BLACK_BELT_IMAKUNI:
		case TRAINER_CLASS_STRANGEST:
            gBattleTypeFlags |= BATTLE_TYPE_IMAKUNI;
            return MUS_VS_IMAKUNI;
        case TRAINER_CLASS_BOSS:
        case TRAINER_CLASS_ROCKET_ADMIN:
		case TRAINER_CLASS_FAKE_ACE:
			return MUS_RS_VS_GYM_LEADER;
        case TRAINER_CLASS_TEAM_ROCKET:
        case TRAINER_CLASS_COOLTRAINER:
        case TRAINER_CLASS_GENTLEMAN:
        case TRAINER_CLASS_RIVAL_LATE:
        default:
            return MUS_VS_TRAINER;
        }
    }
    return MUS_VS_WILD;
}

void PlayBattleBGM(void)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    PlayBGM(GetBattleBGM());
}

void PlayMapChosenOrBattleBGM(u16 songId)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    if (songId)
        PlayNewMapMusic(songId);
    else
        PlayNewMapMusic(GetBattleBGM());
}

const u32 *GetMonFrontSpritePal(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    return GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality);
}

const u32 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, u32 otId, u32 personality)
{
    u32 shinyValue;

    if (species > SPECIES_EGG)
        return gMonPaletteTable[0].data;

    shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < SHINY_ODDS)
        return gMonShinyPaletteTable[species].data;
    else
        return gMonPaletteTable[species].data;
}

const struct CompressedSpritePalette *GetMonSpritePalStruct(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    return GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
}

const struct CompressedSpritePalette *GetMonSpritePalStructFromOtIdPersonality(u16 species, u32 otId , u32 personality)
{
    u32 shinyValue;

    shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < SHINY_ODDS)
        return &gMonShinyPaletteTable[species];
    else
        return &gMonPaletteTable[species];
}

bool32 IsHMMove2(u16 move)
{
    int i = 0;
    while (sHMMoves[i] != 0xFFFF)
    {
        if (sHMMoves[i++] == move)
            return TRUE;
    }
    return FALSE;
}

bool8 IsPokeSpriteNotFlipped(u16 species)
{
    return gBaseStats[species].noFlip;
}

static s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor)
{
    u8 nature = GetNature(mon);
    return sPokeblockFlavorCompatibilityTable[nature * 5 + flavor];
}

s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor)
{
    u8 nature = GetNatureFromPersonality(personality);
    return sPokeblockFlavorCompatibilityTable[nature * 5 + flavor];
}

bool8 IsTradedMon(struct Pokemon *mon)
{
    u8 otName[PLAYER_NAME_LENGTH];
    u32 otId;
    GetMonData(mon, MON_DATA_OT_NAME, otName);
    otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    return IsOtherTrainer(otId, otName);
}

bool8 IsOtherTrainer(u32 otId, u8 *otName)
{
    if (otId ==
        (gSaveBlock2Ptr->playerTrainerId[0]
         | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
         | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
         | (gSaveBlock2Ptr->playerTrainerId[3] << 24)))
    {
        int i;

        for (i = 0; otName[i] != EOS; i++)
            if (otName[i] != gSaveBlock2Ptr->playerName[i])
                return TRUE;
        return FALSE;
    }

    return TRUE;
}

void MonRestorePP(struct Pokemon *mon)
{
    BoxMonRestorePP(&mon->box);
}

void BoxMonRestorePP(struct BoxPokemon *boxMon)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0))
        {
            u16 move = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0);
            u16 bonus = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, 0);
            u8 pp = CalculatePPWithBonus(move, bonus, i);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
        }
    }
}

void SetMonPreventsSwitchingString(void)
{
    gLastUsedAbility = gBattleStruct -> abilityPreventingSwitchout;
    gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
    gBattleTextBuff1[1] = B_BUFF_MON_NICK_WITH_PREFIX;
    gBattleTextBuff1[2] = gBattleStruct->battlerPreventingSwitchout;
    gBattleTextBuff1[4] = B_BUFF_EOS;

    if (GetBattlerSide(gBattleStruct->battlerPreventingSwitchout) == B_SIDE_PLAYER)
        gBattleTextBuff1[3] = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout]);
    else
        gBattleTextBuff1[3] = gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout];

    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff2, gBattlerInMenuId, GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattlerInMenuId]))

    BattleStringExpandPlaceholders(gText_PkmnsXPreventsSwitching, gStringVar4);
}

void SetWildMonHeldItem(void)
{
    if (!(gBattleTypeFlags & (BATTLE_TYPE_POKEDUDE | BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_TRAINER)))
    {
        u16 rnd = Random() % 100;
        u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL);
        if (gBaseStats[species].item1 == gBaseStats[species].item2)
        {
            SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item1);
            return;
        }

        if (rnd > 44)
        {
            if (rnd <= 94)
                SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item1);
            else
                SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item2);
        }
    }
}

bool8 IsMonShiny(struct Pokemon *mon)
{
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    return IsShinyOtIdPersonality(otId, personality);
}

static bool8 IsShinyOtIdPersonality(u32 otId, u32 personality)
{
    bool8 retVal = FALSE;
    u32 shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < SHINY_ODDS)
        retVal = TRUE;
    return retVal;
}

u8 *GetTrainerPartnerName(void)
{
    u8 id = GetMultiplayerId();
    return gLinkPlayers[GetBattlerMultiplayerId(gLinkPlayers[id].id ^ 2)].name;
}

u8 GetPlayerPartyHighestLevel(void)
{
    s32 slot;
    u8 level, monLevel;

    level = 1;
    for (slot = 0; slot < PARTY_SIZE; ++slot)
    {
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SANITY_HAS_SPECIES, NULL) == 1 && !GetMonData(&gPlayerParty[slot], MON_DATA_SANITY_IS_EGG, NULL))
        {
            monLevel = GetMonData(&gPlayerParty[slot], MON_DATA_LEVEL, NULL);
            if (monLevel > level)
                level = monLevel;
        }
    }
    return level;
}

u16 FacilityClassToPicIndex(u16 facilityClass)
{
    return gFacilityClassToPicIndex[facilityClass];
}

bool8 ShouldIgnoreDeoxysForm(u8 caseId, u8 battlerId)
{
    return TRUE;
}

u16 GetUnionRoomTrainerPic(void)
{
    u8 linkId = GetMultiplayerId() ^ 1;
    u32 arrId = gLinkPlayers[linkId].trainerId & 7;

    arrId |= gLinkPlayers[linkId].gender << 3;
    return FacilityClassToPicIndex(gLinkPlayerFacilityClasses[arrId]);
}

u16 GetUnionRoomTrainerClass(void)
{
    u8 linkId = GetMultiplayerId() ^ 1;
    u32 arrId = gLinkPlayers[linkId].trainerId & 7;

    arrId |= gLinkPlayers[linkId].gender << 3;
    return gFacilityClassToTrainerClass[gLinkPlayerFacilityClasses[arrId]];
}

void CreateEventLegalEnemyMon(void)
{
    s32 species = gSpecialVar_0x8004;
    s32 level = gSpecialVar_0x8005;
    s32 itemId = gSpecialVar_0x8006;

    ZeroEnemyPartyMons();
    CreateEventLegalMon(&gEnemyParty[0], species, level, 32, 0, 0, 0, 0);
    if (itemId)
    {
        u8 heldItem[2];
        
        heldItem[0] = itemId;
        heldItem[1] = itemId >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void HandleSetPokedexFlag(u16 nationalNum, u8 caseId, u32 personality)
{
    u8 getFlagCaseId = (caseId == FLAG_SET_SEEN) ? FLAG_GET_SEEN : FLAG_GET_CAUGHT;
    
    if (!GetSetPokedexFlag(nationalNum, getFlagCaseId))
    {
        GetSetPokedexFlag(nationalNum, caseId);
    }
}

bool8 CheckBattleTypeGhost(struct Pokemon *mon, u8 battlerId)
{
    u8 buffer[12];

    if (gBattleTypeFlags & BATTLE_TYPE_GHOST && GetBattlerSide(battlerId) != B_SIDE_PLAYER)
    {
        GetMonData(mon, MON_DATA_NICKNAME, buffer);
        StringGetEndN(buffer, POKEMON_NAME_LENGTH);
        if (!StringCompare(buffer, gText_Ghost))
            return TRUE;
    }
    return FALSE;
}

static void OakSpeechNidoranFSetupTemplate(struct OakSpeechNidoranFStruct *structPtr, u8 battlePosition)
{
    u16 i = 0, j = 0;

    if (battlePosition > 3)
    {
        for (i = 0; i < (s8)structPtr->spriteCount; ++i)
        {
            structPtr->templates[i] = gSpriteTemplates_Battlers[i];
            for (j = 0; j < structPtr->frameCount; ++j)
                structPtr->frameImages[i * structPtr->frameCount + j].data = &structPtr->bufferPtrs[i][j * 0x800];
            structPtr->templates[i].images = &structPtr->frameImages[i * structPtr->frameCount];
        }
    }
    else
    {
        const struct SpriteTemplate *template = &gSpriteTemplates_Battlers[battlePosition];
        
        structPtr->templates[0] = *template;
        for (j = 0; j < structPtr->frameCount; ++j)
                structPtr->frameImages[j].data = &structPtr->bufferPtrs[0][j * 0x800];
        structPtr->templates[0].images = structPtr->frameImages;
    }
}

// not used
static void OakSpeechNidoranFSetupTemplateDummy(struct OakSpeechNidoranFStruct *structPtr)
{
    u16 i, j;

    for (i = 0; i < (s8)structPtr->spriteCount; ++i)
    {
        structPtr->templates[i] = sOakSpeechNidoranFDummyTemplate;
        for (j = 0; j < structPtr->frameCount; ++j)
            structPtr->frameImages[i * structPtr->spriteCount + j].data = &structPtr->bufferPtrs[i][j * 0x800];
        structPtr->templates[i].images = &structPtr->frameImages[i * structPtr->spriteCount]; // should be frameCount logically
        structPtr->templates[i].anims = gSpriteAnimTable_82349BC;
        structPtr->templates[i].paletteTag = i;
    }
}

struct OakSpeechNidoranFStruct *OakSpeechNidoranFSetup(u8 battlePosition, bool8 enable)
{
    s32 size;
    u8 i, flags = 0;

    if (sOakSpeechNidoranResources != NULL)
    {
        if (sOakSpeechNidoranResources->enable == 0xA3)
            return NULL;
        memset(sOakSpeechNidoranResources, 0, sizeof(struct OakSpeechNidoranFStruct));
        sOakSpeechNidoranResources = NULL;
    }
    sOakSpeechNidoranResources = AllocZeroed(0x18);
    if (sOakSpeechNidoranResources == NULL)
        return NULL;
    switch (enable)
    {
    case TRUE:
        if (battlePosition == 4)
        {
            sOakSpeechNidoranResources->spriteCount = 4;
            sOakSpeechNidoranResources->battlePosition = 4;
        }
        else
        {
            if (battlePosition > 4)
                battlePosition = 0;
            sOakSpeechNidoranResources->spriteCount = 1;
            sOakSpeechNidoranResources->battlePosition = 1;
        }
        sOakSpeechNidoranResources->frameCount = 4;
        sOakSpeechNidoranResources->enable2 = TRUE;
        break;
    case FALSE:
    default:
        if (!battlePosition)
            battlePosition = 1;
        if (battlePosition > 8)
            battlePosition = 8;
        sOakSpeechNidoranResources->spriteCount = (battlePosition << 16) >> 16;
        sOakSpeechNidoranResources->battlePosition = battlePosition;
        sOakSpeechNidoranResources->frameCount = 4;
        sOakSpeechNidoranResources->enable2 = FALSE;
        break;
    }
    size = sOakSpeechNidoranResources->frameCount * 0x800;
    sOakSpeechNidoranResources->sizePerSprite = size;
    sOakSpeechNidoranResources->dataBuffer = AllocZeroed(sOakSpeechNidoranResources->spriteCount * size);
    sOakSpeechNidoranResources->bufferPtrs = AllocZeroed(sOakSpeechNidoranResources->spriteCount * 0x20);
    if (sOakSpeechNidoranResources->dataBuffer == NULL ||  sOakSpeechNidoranResources->bufferPtrs == NULL)
    {
        flags |= 1;
    }
    else
    {
        do
        {
            for (i = 0; i < (s8)sOakSpeechNidoranResources->spriteCount; ++i)
                sOakSpeechNidoranResources->bufferPtrs[i] = &sOakSpeechNidoranResources->dataBuffer[sOakSpeechNidoranResources->sizePerSprite * i];
        } while (0);
    }
    sOakSpeechNidoranResources->templates = AllocZeroed(sizeof(struct SpriteTemplate) * sOakSpeechNidoranResources->spriteCount);
    sOakSpeechNidoranResources->frameImages = AllocZeroed(sOakSpeechNidoranResources->spriteCount * sizeof(struct SpriteFrameImage) * sOakSpeechNidoranResources->frameCount);
    if (sOakSpeechNidoranResources->templates == NULL || sOakSpeechNidoranResources->frameImages == NULL)
    {
        flags |= 2;
    }
    else
    {
        for (i = 0; i < sOakSpeechNidoranResources->frameCount * sOakSpeechNidoranResources->spriteCount; ++i)
                sOakSpeechNidoranResources->frameImages[i].size = 0x800;
        switch (sOakSpeechNidoranResources->enable2)
        {
        case TRUE:
            OakSpeechNidoranFSetupTemplate(sOakSpeechNidoranResources, battlePosition);
            break;
        case FALSE:
        default:
            OakSpeechNidoranFSetupTemplateDummy(sOakSpeechNidoranResources);
            break;
        }
    }
    if (flags & 2)
    {
        if (sOakSpeechNidoranResources->frameImages != NULL)
            FREE_AND_SET_NULL(sOakSpeechNidoranResources->frameImages);
        if (sOakSpeechNidoranResources->templates != NULL)
            FREE_AND_SET_NULL(sOakSpeechNidoranResources->templates);
    }
    if (flags & 1)
    {
        if (sOakSpeechNidoranResources->bufferPtrs != NULL)
            FREE_AND_SET_NULL(sOakSpeechNidoranResources->bufferPtrs);
        if (sOakSpeechNidoranResources->dataBuffer != NULL)
            FREE_AND_SET_NULL(sOakSpeechNidoranResources->dataBuffer);
    }
    if (flags)
    {
        memset(sOakSpeechNidoranResources, 0, sizeof(struct OakSpeechNidoranFStruct));
        FREE_AND_SET_NULL(sOakSpeechNidoranResources);
    }
    else
    {
        sOakSpeechNidoranResources->enable = 0xA3;
    }
    return sOakSpeechNidoranResources;
}

void OakSpeechNidoranFFreeResources(void)
{
    if (sOakSpeechNidoranResources != NULL)
    {
        if (sOakSpeechNidoranResources->enable != 0xA3)
        {
            memset(sOakSpeechNidoranResources, 0, sizeof(struct OakSpeechNidoranFStruct));
            sOakSpeechNidoranResources = NULL;
        }
        else
        {
            if (sOakSpeechNidoranResources->frameImages != NULL)
                FREE_AND_SET_NULL(sOakSpeechNidoranResources->frameImages);
            if (sOakSpeechNidoranResources->templates != NULL)
                FREE_AND_SET_NULL(sOakSpeechNidoranResources->templates);
            if (sOakSpeechNidoranResources->bufferPtrs != NULL)
                FREE_AND_SET_NULL(sOakSpeechNidoranResources->bufferPtrs);                    
            if (sOakSpeechNidoranResources->dataBuffer != NULL)
                FREE_AND_SET_NULL(sOakSpeechNidoranResources->dataBuffer);
            memset(sOakSpeechNidoranResources, 0, sizeof(struct OakSpeechNidoranFStruct));
            FREE_AND_SET_NULL(sOakSpeechNidoranResources);
        }

    }
}

void *OakSpeechNidoranFGetBuffer(u8 bufferId)
{
    if (sOakSpeechNidoranResources->enable != 0xA3)
    {
        return NULL;
    }
    else
    {
        if (bufferId >= (s8)sOakSpeechNidoranResources->spriteCount)
            bufferId = 0;
        return sOakSpeechNidoranResources->bufferPtrs[bufferId];
    }
}

static const u16 sZunStarters[] = 
{
    SPECIES_CREIMU,
    SPECIES_CMARISA,
    SPECIES_CRUMIA,
    SPECIES_CDAIYOUSEI,
    SPECIES_CCIRNO,
    SPECIES_CMEILING,
    SPECIES_CKOAKUMA,
    SPECIES_CPATCHOULI,
    
    SPECIES_CSAKUYA,
    SPECIES_CREMILIA,
    SPECIES_CFLANDRE,
    SPECIES_CLETTY,
    SPECIES_CCHEN,
    SPECIES_CALICE,
    SPECIES_CLILYWHITE,
    SPECIES_CLILYBLACK,
    
    SPECIES_CLUNASA,
    SPECIES_CMERLIN,
    SPECIES_CLYRICA,
    SPECIES_CYOUMU,
    SPECIES_CYUYUKO,
    SPECIES_CRAN,
    SPECIES_CYUKARI,
    SPECIES_CSUIKA,
    
    SPECIES_CWRIGGLE,
    SPECIES_CMYSTIA,
    SPECIES_CKEINE,
    SPECIES_CTEWI,
    SPECIES_CREISEN,
    SPECIES_CEIRIN,
    SPECIES_CKAGUYA,
    SPECIES_CMOKOU,
    
    SPECIES_CAYA,
    SPECIES_CMEDICINE,
    SPECIES_CYUUKA,
    SPECIES_CKOMACHI,
    SPECIES_CEIKI,
    SPECIES_AKYUU,
    SPECIES_CSHIZUHA,
    SPECIES_CMINORIKO,
    
    SPECIES_CHINA,
    SPECIES_CNITORI,
    SPECIES_CMOMIJI,
    SPECIES_CSANAE,
    SPECIES_CKANAKO,
    SPECIES_CSUWAKO,
    SPECIES_CREISEN_II,
    SPECIES_CTOYOHIME,
    
    SPECIES_CYORIHIME,
    SPECIES_CIKU,
    SPECIES_CTENSHI,
    SPECIES_CKISUME,
    SPECIES_CYAMAME,
    SPECIES_CPARSEE,
    SPECIES_CYUUGI,
    SPECIES_CSATORI,
    
    SPECIES_CRIN,
    SPECIES_CUTSUHO,
    SPECIES_CKOISHI,
    SPECIES_CNAZRIN,
    SPECIES_CKOGASA,
    SPECIES_CICHIRIN,
    SPECIES_CMURASA,
    SPECIES_CSHOU,
    
    SPECIES_CBYAKUREN,
    SPECIES_CNUE,
    SPECIES_SHANGHAI,
    SPECIES_HOURAI,
    SPECIES_CHATATE,
    SPECIES_CSUNNY,
    SPECIES_CLUNA,
    SPECIES_CSTAR,
    
    SPECIES_RINNOSUKE,
    SPECIES_CTOKIKO,
    SPECIES_CKYOUKO,
    SPECIES_CYOSHIKA,
    SPECIES_CSEIGA,
    SPECIES_CTOJIKO,
    SPECIES_CFUTO,
    SPECIES_CMIKO,
    
    SPECIES_CMAMIZOU,
    SPECIES_CKOSUZU,
    SPECIES_CKOKORO,
    SPECIES_CWAKASAGIHIME,
    SPECIES_CSEKIBANKI,
    SPECIES_CKAGEROU,
    SPECIES_CBENBEN,
    SPECIES_CYATSUHASHI,
    
    SPECIES_CSEIJA,
    SPECIES_CSHINMYOUMARU,
    SPECIES_CRAIKO,
    SPECIES_CKASEN,
    SPECIES_CSUMIREKO,
    SPECIES_CSEIRAN,
    SPECIES_CRINGO,
    SPECIES_CDOREMY,
    
    SPECIES_CSAGUME,
    SPECIES_CCLOWNPIECE,
    SPECIES_CJUNKO,
    SPECIES_CHECATIA,
    SPECIES_CJOON,
    SPECIES_CSHION,
    SPECIES_CETERNITY,
    SPECIES_CNEMUNO,
    
    SPECIES_CAUNN,
    SPECIES_CNARUMI,
    SPECIES_CMAI_AND_SATONO,
    SPECIES_CMAI_AND_SATONO,
    SPECIES_COKINA,
    SPECIES_CEIKA,
    SPECIES_CURUMI,
    SPECIES_CKUTAKA,
    
    SPECIES_CYACHIE,
    SPECIES_CMAYUMI,
    SPECIES_CKEIKI,
    SPECIES_CSAKI,
    SPECIES_CYUUMA,
    SPECIES_CMIKE,
    SPECIES_CTAKANE,
    SPECIES_CSANNYO,
    
    SPECIES_CMISUMARU,
    SPECIES_CTSUKASA,
    SPECIES_CMEGUMU,
    SPECIES_CCHIMATA,
    SPECIES_CMOMOYO,
    SPECIES_CMIYOI,
	SPECIES_CMIZUCHI,
    SPECIES_CBITEN,
	
    SPECIES_CENOKO,
    SPECIES_CCHIYARI,
    SPECIES_CHISAMI,
    SPECIES_CZANMU,
    SPECIES_CHAKUREI,
    SPECIES_CKIRISAME,
    SPECIES_CSHINGYOKU,
    SPECIES_CMAGAN,
	
    SPECIES_CMIMA,
    SPECIES_CELIS,
    SPECIES_CKIKURI,
    SPECIES_CKONNGARA,
    SPECIES_CSARIEL,
    SPECIES_CRIKA,
    SPECIES_CMEIRA,
    SPECIES_CELLEN,
    
    SPECIES_CKOTOHIME,
    SPECIES_CKANA,
    SPECIES_CRIKAKO,
    SPECIES_CCHIYURI,
    SPECIES_CYUMEMI,
    SPECIES_RUUKOTO,
    SPECIES_CORANGE,
    SPECIES_CKURUMI,
    
    SPECIES_CELLY,
    SPECIES_CKAZAMI,
    SPECIES_CMUGETSU,
    SPECIES_CGENGETSU,
    SPECIES_CSARA,
    SPECIES_CLOUISE,
    SPECIES_CARISU,
    SPECIES_CYUKI,
    
    SPECIES_CMAI,
    SPECIES_CYUMEKO,
    SPECIES_CSHINKI,
    SPECIES_CSENDAI,
    SPECIES_CTENMA,
    SPECIES_CLAYLA,
    SPECIES_CYOUKI,
    0,
    
};

u16 SelectZunStarter(void)
{
    u16 index = (VarGet(VAR_TEMP_5) * 8) + (VarGet(VAR_TEMP_6) - 1);
    u16 value = sZunStarters[index];
    
    while (value == 0)
        value = sZunStarters[Random() % (NELEMS(sZunStarters))];
    
    return value;
}

u16 GetZunStarterEvolution(void)
{
	u16 zunstarter = VarGet(VAR_ZUN_STARTER_SPECIES);
	
	if (gEvolutionTable[zunstarter][0].targetSpecies != 0)
		return gEvolutionTable[zunstarter][0].targetSpecies;
	else
		return zunstarter;
}

u8 GetNatureStringIndex(struct Pokemon *mon)
{
    u32 nature = GetMonData(mon, MON_DATA_NATURE_OVERRIDE, 0);
    if (nature)
        return nature + 25;
    return GetMonData(mon, MON_DATA_PERSONALITY, 0) % 25;
}

void SetNatureOverride(void)
{
    if (gSpecialVar_0x8001 != GetNature(&gPlayerParty[gSpecialVar_0x8004]))
    {
        SetMonData(&(gPlayerParty[gSpecialVar_0x8004]), MON_DATA_NATURE_OVERRIDE, &gSpecialVar_0x8001);
        CalculateMonStats(&(gPlayerParty[gSpecialVar_0x8004]));
        gSpecialVar_Result = 1;
        //AdjustFriendship(&(gPlayerParty[gSpecialVar_0x8004]), FRIENDSHIP_EVENT_NATURE_CHANGE);
    }
    else
        gSpecialVar_Result = 0;
}

