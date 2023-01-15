#include "global.h"
#include "berry.h"
#include "text.h"
#include "constants/items.h"

static const u8 sBerryDescriptionPart1_Cheri[] = _("とても かわいい はなが さく.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("まっかな みは とても からい.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("そとの かわの ぶぶんも なかみも すべてが");
static const u8 sBerryDescriptionPart2_Chesto[] = _("かたい. どこを たべても しぶい.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("とても あまくて おいしい.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("やわらかいので はこぶときは ちゅうい.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("はっぱの ぶぶんが ながく まるまっていると");
static const u8 sBerryDescriptionPart2_Rawst[] = _("みが とても にがく なるらしい.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("かたい みの なかには すいぶんが とても");
static const u8 sBerryDescriptionPart2_Aspear[] = _("おおく ふくまれている. かなり すっぱい.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("クラボなどに くらべて すこし そだつのが");
static const u8 sBerryDescriptionPart2_Leppa[] = _("おそい. みが ちいさいほど おいしい.");
static const u8 sBerryDescriptionPart1_Oran[] = _("いろいろな あじが まざった ふしぎな み.");
static const u8 sBerryDescriptionPart2_Oran[] = _("みを つけるのに はんにち かかる.");
static const u8 sBerryDescriptionPart1_Persim[] = _("たいようが だいすき. ひに あたると");
static const u8 sBerryDescriptionPart2_Persim[] = _("どんどん いろが あざやかに なる.");
static const u8 sBerryDescriptionPart1_Lum[] = _("そだつのに じかんが かかるが たいせつに");
static const u8 sBerryDescriptionPart2_Lum[] = _("そだてると みが 2つ つくことも ある.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("オレンとは きょうだいの ような そんざい.");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("おおきくて あじも ととのっている.");
static const u8 sBerryDescriptionPart1_Figy[] = _("たべられた あとのような かたちの なかには");
static const u8 sBerryDescriptionPart2_Figy[] = _("からい せいぶんが つまっている.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("まわりに ついている イボイボは ポケモンが");
static const u8 sBerryDescriptionPart2_Wiki[] = _("もちやすいように できたと いわれている.");
static const u8 sBerryDescriptionPart1_Mago[] = _("おおきく なれば なるほど みが まがる.");
static const u8 sBerryDescriptionPart2_Mago[] = _("まがるほど あまくて おいしい.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("ちいさい サイズの はなで しかも ひかりを");
static const u8 sBerryDescriptionPart2_Aguav[] = _("ひつようと しない めずらしい きのみ.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("とても おおきな すっぱい きのみ.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("そだてるには みじかくても 1にち かかる.");
static const u8 sBerryDescriptionPart1_Razz[] = _("あかい みは たべると ちょっぴり からい.");
static const u8 sBerryDescriptionPart2_Razz[] = _("そだつのが はやく 4じかんで みを つける");
static const u8 sBerryDescriptionPart1_Bluk[] = _("そとがわは あおいいろだが たべると");
static const u8 sBerryDescriptionPart2_Bluk[] = _("くちの なかが まっくろに なる.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("せかいで 7ばんめに はっけん されたので");
static const u8 sBerryDescriptionPart2_Nanab[] = _("ナナという せつが ゆうりょく. あまい.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("ちいさな しろい はなが さく. にがさと");
static const u8 sBerryDescriptionPart2_Wepear[] = _("すっぱさが まざりあった びみょうな あじ.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("かぜに よわく さむさにも よわい.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("みの なかが からく そとがわが すっぱい.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("どんなに みずを あげても えいようが");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("あっても 6つの み しか つけない.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("ねっこの ような かたちの めずらしい");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("しゅるい. とても おおきな はなが さく.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("みずが だいすき. ずっと あめが ふる");
static const u8 sBerryDescriptionPart2_Qualot[] = _("ばしょでも しっかりと そだつ.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("とても こうかで なかなか めに することが");
static const u8 sBerryDescriptionPart2_Hondew[] = _("できない きのみ. とても おいしい.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("やわらかさと まるい かたちからは");
static const u8 sBerryDescriptionPart2_Grepa[] = _("そうぞうが できないほど すっぱい.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("くちびるが まがって しまうほど からい.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("そだてるにも じかんが かかる.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("おおむかしから はえていた. たくさん");
static const u8 sBerryDescriptionPart2_Cornn[] = _("うえないと みが つかないときも ある.");
static const u8 sBerryDescriptionPart1_Magost[] = _("とても あじの バランスが よいと");
static const u8 sBerryDescriptionPart2_Magost[] = _("ひょうばんの きのみ.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("たくさんの けが はえている めずらしい");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("しゅるい. かなり にがい.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("かなり すっぱい. 1くち たべると");
static const u8 sBerryDescriptionPart2_Nomel[] = _("3にちかん ほかの あじが しなくなる.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("まっかになった みは とてつもなく からい.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("イボからも からい せいぶんが でている.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("どこからともなく うみを ただよってくる.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("せかいの どこかで そだっている らしい.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("とても おおきく 50センチを こえるものも");
static const u8 sBerryDescriptionPart2_Watmel[] = _("はっけん された. ものすごく あまい.");
static const u8 sBerryDescriptionPart1_Durin[] = _("みただけで にがい. あまりにも にがいので");
static const u8 sBerryDescriptionPart2_Durin[] = _("そのままで たべたひとは だれもいない.");
static const u8 sBerryDescriptionPart1_Belue[] = _("つるつるとして おいしそうだが とてつもなく");
static const u8 sBerryDescriptionPart2_Belue[] = _("すっぱい. そだてるにも じかんが かかる.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("なぞのタネ. チイラのみには うみの");
static const u8 sBerryDescriptionPart2_Liechi[] = _("ちからが やどるという うわさが ある.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("なぞのタネ. リュガのみには りくの");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("ちからが やどるという うわさが ある.");
static const u8 sBerryDescriptionPart1_Salac[] = _("なぞのタネ. カムラのみには そらの");
static const u8 sBerryDescriptionPart2_Salac[] = _("ちからが やどるという うわさが ある.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("なぞのタネ. ヤタピのみには すべての");
static const u8 sBerryDescriptionPart2_Petaya[] = _("いきものの ちからが やどると いわれている");
static const u8 sBerryDescriptionPart1_Apicot[] = _("ふしぎな ふしぎな きのみ. なにが");
static const u8 sBerryDescriptionPart2_Apicot[] = _("おこるのか なにが できるのか わからない.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("でんせつのみ と いわれている. この みを");
static const u8 sBerryDescriptionPart2_Lansat[] = _("もつと とても しあわせに なるらしい.");
static const u8 sBerryDescriptionPart1_Starf[] = _("あまりにも ちからが つよすぎるため");
static const u8 sBerryDescriptionPart2_Starf[] = _("せかいの はてに すてた まぼろしのみ.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("しょうたい ふめいの きのみ.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("ほしの ちからを もっている らしい.");

const struct Berry gBerries[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("CHERI"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 20,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Cheri,
            .description2 = sBerryDescriptionPart2_Cheri,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        }, // oops

};

const struct BerryCrushStats gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY  - FIRST_BERRY_INDEX] = { 50,  20},
};

// Leftover from R/S
const struct BerryTree gBlankBerryTree = {};

#define ENIGMA_BERRY_STRUCT ({ \
    const struct Berry2 * berries = (const struct Berry2 *)gBerries; \
    berries[ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX]; \
})

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *);

void InitEnigmaBerry(void)
{
    s32 i;

    gSaveBlock1Ptr->enigmaBerry.berry = ENIGMA_BERRY_STRUCT;
    for (i = 0; i < 18; i++)
        gSaveBlock1Ptr->enigmaBerry.itemEffect[i] = 0;
    gSaveBlock1Ptr->enigmaBerry.holdEffect = 0;
    gSaveBlock1Ptr->enigmaBerry.holdEffectParam = 0;
    gSaveBlock1Ptr->enigmaBerry.checksum = GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry);
}

void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
    InitEnigmaBerry();
}

struct ReceivedEnigmaBerry
{
    struct Berry2 berry;
    u8 unk_001C[0x4FA];
    u8 itemEffect[18];
    u8 holdEffect;
    u8 holdEffectParam;
};

void SetEnigmaBerry(u8 * berry)
{
    struct EnigmaBerry * enigmaBerry;
    struct ReceivedEnigmaBerry * src2;
    s32 i;

    ClearEnigmaBerries();

    src2 = (struct ReceivedEnigmaBerry *)berry;
    enigmaBerry = &gSaveBlock1Ptr->enigmaBerry;

    enigmaBerry->berry = src2->berry;
    for (i = 0; i < 18; i++)
        enigmaBerry->itemEffect[i] = src2->itemEffect[i];
    enigmaBerry->holdEffect = src2->holdEffect;
    enigmaBerry->holdEffectParam = src2->holdEffectParam;
    enigmaBerry->checksum = GetEnigmaBerryChecksum(enigmaBerry);
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry * enigmaBerry)
{
    const u8 * src = (const u8 *)enigmaBerry;
    u32 result = 0;
    u32 i;

    for (i = 0; i < offsetof(struct EnigmaBerry, checksum); i++)
        result += src[i];

    return result;
}

bool32 IsEnigmaBerryValid(void)
{
    if (gSaveBlock1Ptr->enigmaBerry.berry.stageDuration == 0)
        return FALSE;
    if (gSaveBlock1Ptr->enigmaBerry.berry.maxYield == 0)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;

    return TRUE;
}

const struct Berry * GetBerryInfo(u8 berryIdx)
{
    if (berryIdx == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) && IsEnigmaBerryValid())
        return (struct Berry *)&gSaveBlock1Ptr->enigmaBerry.berry;

    if (berryIdx == 0 || berryIdx > ITEM_TO_BERRY(ITEM_ENIGMA_BERRY))
        berryIdx = 1;

    return &gBerries[berryIdx - 1];
}

u8 ItemIdToBerryType(u16 itemId)
{
    if (itemId - FIRST_BERRY_INDEX < 0 || itemId - FIRST_BERRY_INDEX > ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX)
        return 1;

    return ITEM_TO_BERRY(itemId);
}

u16 BerryTypeToItemId(u16 berryType)
{
    if (berryType - 1 < 0 || berryType - 1 > ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;

    return berryType + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berryType, u8 * dest)
{
    const struct Berry * berry = GetBerryInfo(berryType);
    memcpy(dest, berry->name, 6);
    dest[6] = EOS;
}
