#include "global.h"
#include "gflib.h"
#include "task.h"
#include "wild_encounter.h"

static void Task_SmoothBlendLayers(u8 taskId);

// 0: x position of forehead
// 1: y position of forehead
// 2: 
// 3: x position of mouth
// 4: y position of mouth

static const u8 sMonSpriteAnchorCoords[][5] = {
    [SPECIES_CREIMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_REIMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AREIMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DREIMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SMARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADMARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LMARISA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRUMIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RUMIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ARUMIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SRUMIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CDAIYOUSEI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DAIYOUSEI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADAIYOUSEI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DDAIYOUSEI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCIRNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CIRNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SCIRNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TCIRNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADCIRNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMEILING - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MEILING - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMEILING - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SMEILING - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADMEILING - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOAKUMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOAKUMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HKOAKUMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CPATCHOULI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_PATCHOULI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_APATCHOULI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DPATCHOULI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSAKUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SAKUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSAKUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HSAKUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CREMILIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_REMILIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AREMILIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DREMILIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CFLANDRE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_FLANDRE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AFLANDRE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SFLANDRE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLETTY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LETTY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DLETTY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HLETTY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADLETTY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCHEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ACHEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TCHEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADCHEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DARK_ALICE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLILYWHITE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LILYWHITE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ALILYWHITE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HLILYWHITE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLILYBLACK - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LILYBLACK - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ALILYBLACK - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SLILYBLACK - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLUNASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LUNASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HLUNASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMERLIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MERLIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HMERLIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLYRICA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LYRICA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HLYRICA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYOUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YOUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DYOUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SYOUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LYOUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUYUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUYUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AYUYUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DYUYUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LYUYUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ARAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HRAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADRAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUKARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUKARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DYUKARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TYUKARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADYUKARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSUIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SUIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASUIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSUIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CWRIGGLE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_WRIGGLE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DWRIGGLE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SWRIGGLE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMYSTIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MYSTIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMYSTIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HMYSTIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADMYSTIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKEINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KEINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKEINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DKEINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HKEINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTEWI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TEWI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ATEWI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DTEWI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADTEWI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CREISEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_REISEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DREISEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TREISEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADREISEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CEIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_EIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AEIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HEIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKAGUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KAGUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKAGUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DKAGUYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMOKOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MOKOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMOKOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMOKOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ADMOKOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CAYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SAYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TAYA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMEDICINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MEDICINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMEDICINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SMEDICINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TMEDICINE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUUKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUUKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AYUUKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TYUUKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOMACHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOMACHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKOMACHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SKOMACHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CEIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_EIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AEIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DEIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKYUU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHIZUHA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHIZUHA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SSHIZUHA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HSHIZUHA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMINORIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MINORIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMINORIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMINORIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKI_SISTERS - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AHINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DHINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CNITORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NITORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ANITORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TNITORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMOMIJI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MOMIJI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMOMIJI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSANAE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SANAE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASANAE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSANAE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_JKSANAE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKANAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KANAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKANAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DKANAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSUWAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SUWAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASUWAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DSUWAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CREISEN_II - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_REISEN_II - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTOYOHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TOYOHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TTOYOHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYORIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YORIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SYORIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CIKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_IKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DIKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TIKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTENSHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TENSHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ATENSHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DTENSHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKISUME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KISUME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TKISUME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYAMAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YAMAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SYAMAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TYAMAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CPARSEE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_PARSEE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DPARSEE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TPARSEE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUUGI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUUGI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AYUUGI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DYUUGI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSATORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SATORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DSATORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSATORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ARIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ZFAIRY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CUTSUHO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_UTSUHO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AUTSUHO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SUTSUHO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOISHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOISHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKOISHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SKOISHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CNAZRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NAZRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TNAZRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HNAZRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOGASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOGASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SKOGASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TKOGASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CICHIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ICHIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DICHIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TICHIRIN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMURASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MURASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMURASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMURASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASHOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSHOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CBYAKUREN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_BYAKUREN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HBYAKUREN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TBYAKUREN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CNUE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NUE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ANUE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TNUE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TENSOKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHANGHAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HOURAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_GOLIATH - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NAMAZU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHATATE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HATATE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DHATATE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_THATATE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSUNNY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SUNNY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASUNNY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DSUNNY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLUNA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LUNA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ALUNA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TLUNA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSTAR - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_STAR - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASTAR - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HSTAR - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RINNOSUKE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTOKIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TOKIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ATOKIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKYOUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KYOUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TKYOUKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYOSHIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YOSHIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HYOSHIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSEIGA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SEIGA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SSEIGA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTOJIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TOJIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_STOJIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CFUTO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_FUTO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TFUTO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AMIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMAMIZOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAMIZOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DMAMIZOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOSUZU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOSUZU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_JINYOU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOKORO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOKORO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKOKORO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TKOKORO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CWAKASAGIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_WAKASAGIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DWAKASAGIHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSEKIBANKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SEKIBANKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSEKIBANKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKAGEROU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KAGEROU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HKAGEROU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CBENBEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_BENBEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYATSUHASHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YATSUHASHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSEIJA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SEIJA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DSEIJA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHINMYOUMARU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHINMYOUMARU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ASHINMYOUMARU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRAIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RAIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ARAIKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKASEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KASEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HKASEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSUMIREKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SUMIREKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSEIRAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SEIRAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRINGO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RINGO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CDOREMY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DOREMY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSAGUME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SAGUME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCLOWNPIECE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLOWNPIECE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CJUNKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_JUNKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHECATIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HECATIA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CJOON - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_JOON - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHION - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHION - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CETERNITY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ETERNITY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CNEMUNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NEMUNO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CAUNN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AUNN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CNARUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_NARUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMAI_AND_SATONO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAI_AND_SATONO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_COKINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_OKINA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CEIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_EIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CURUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_URUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKUTAKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KUTAKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYACHIE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YACHIE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMAYUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAYUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKEIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KEIKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSAKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SAKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUUMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUUMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMIKE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MIKE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTAKANE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TAKANE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSANNYO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SANNYO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMISUMARU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MISUMARU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTSUKASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TSUKASA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMEGUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MEGUMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCHIMATA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHIMATA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMOMOYO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MOMOYO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMIYOI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MIYOI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CBITEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_BITEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CENOKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ENOKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCHIYARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHIYARI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHISAMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HISAMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CZANMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ZANMU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHAKUREI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_HAKUREI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKIRISAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KIRISAME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHINGYOKU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHINGYOKUF - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHINGYOKUM - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHINGYOKUO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMAGAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAGAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMIMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MIMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CELIS - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ELIS - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKIKURI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KIKURI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKONNGARA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KONNGARA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSARIEL - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SARIEL - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SSARIEL - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_GENJI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TRIKA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMEIRA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MEIRA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAGIC_STONES - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CELLEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ELLEN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKOTOHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KOTOHIME - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKANA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KANA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRIKAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RIKAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CCHIYURI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CHIYURI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUMEMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUMEMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_RUUKOTO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MIMI_CHAN - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CORANGE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ORANGE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKURUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KURUMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CELLY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ELLY - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CKAZAMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_KAZAMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_AKAZAMI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMUGETSU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MUGETSU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CGENGETSU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_GENGETSU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSARA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SARA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLOUISE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LOUISE - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CARISU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_ARISU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_MAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYUMEKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YUMEKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSHINKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SHINKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CSENDAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SENDAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CTENMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TENMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CLAYLA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_LAYLA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_DLAYLA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CYOUKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_YOUKI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TORI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_2HU - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CRENKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TRRENKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_CMARIBEL - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TRMARIBEL - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_XSUWAKO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_XUTSUHO - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_XTENSHI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_XTENMA - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_XSENDAI - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_SEKI_HEAD - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
    [SPECIES_TENSOKUG - 1] = {0x20, 0x20, 0x1f, 0x20, 0x20},
};

void AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 x, u8 y, const u8 * color, s8 speed, const u8 * str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = GetFontAttribute(fontId, 2);
    printer.lineSpacing = GetFontAttribute(fontId, 3);
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];
    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = color[1];
    printer.bgColor = color[0];
    printer.shadowColor = color[2];
    AddTextPrinter(&printer, speed, NULL);
}

void AddTextPrinterParameterized5(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 letterSpacing, u8 lineSpacing)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = str;
    printer.windowId = windowId;
    printer.fontId = fontId;
    printer.x = x;
    printer.y = y;
    printer.currentX = x;
    printer.currentY = y;
    printer.letterSpacing = letterSpacing;
    printer.lineSpacing = lineSpacing;
    printer.unk = 0;
    printer.fgColor = GetFontAttribute(fontId, 5);
    printer.bgColor = GetFontAttribute(fontId, 6);
    printer.shadowColor = GetFontAttribute(fontId, 7);
    AddTextPrinter(&printer, speed, callback);
}

void Menu_PrintFormatIntlPlayerName(u8 windowId, const u8 * src, u16 x, u16 y)
{
    s32 i;

    for (i = 0; gSaveBlock2Ptr->playerName[i] != EOS; i++)
        ;

    StringExpandPlaceholders(gStringVar4, src);
    if (i != 5)
    {
        AddTextPrinterParameterized(windowId, 2, gStringVar4, x, y, 0xFF, NULL);
    }
    else
    {
        AddTextPrinterParameterized5(windowId, 2, gStringVar4, x, y, 0xFF, NULL, 0, 0);
    }
}

static void sub_812E768(const struct Bitmap *src, struct Bitmap *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 width, u16 height)
{
    s32 loopSrcY, loopDstY, loopSrcX, loopDstX, xEnd, yEnd, multiplierSrcY, multiplierDstY;
    u16 toOrr;
    u8 *pixelsSrc;
    u8 *pixelsDst;

    if (dst->width - dstX < width)
        xEnd = dst->width - dstX + srcX;
    else
        xEnd = width + srcX;

    if (dst->height - dstY < height)
        yEnd = srcY + dst->height - dstY;
    else
        yEnd = srcY + height;
    multiplierSrcY = (src->width + (src->width & 7)) >> 3;
    multiplierDstY = (dst->width + (dst->width & 7)) >> 3;
    for (loopSrcY = srcY, loopDstY = dstY; loopSrcY < yEnd; loopSrcY++, loopDstY++)
    {
        for (loopSrcX = srcX, loopDstX = dstX; loopSrcX < xEnd; loopSrcX++, loopDstX++)
        {
            pixelsSrc = (u8 *)(src->pixels + ((loopSrcX >> 1) & 3) + ((loopSrcX >> 3) << 5) + (((loopSrcY >> 3) * multiplierSrcY) << 5) + ((u32)(loopSrcY << 0x1d) >> 0x1B));
            pixelsDst = (u8 *)(dst->pixels + ((loopDstX >> 1) & 3) + ((loopDstX >> 3) << 5) + ((( loopDstY >> 3) * multiplierDstY) << 5) + ((u32)( loopDstY << 0x1d) >> 0x1B));

            if ((u32)pixelsDst & 0x1)
            {
                pixelsDst--;
                if (loopDstX & 0x1)
                {
                    toOrr = *(vu16 *)pixelsDst & 0x0fff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 8);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 12);
                }
                else
                {
                    toOrr = *(vu16 *)pixelsDst & 0xf0ff;
                    if (loopSrcX & 0x1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 8);
                }
            }
            else
            {
                if (loopDstX & 1)
                {
                    toOrr = *(vu16 *)pixelsDst & 0xff0f;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) << 0);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) << 4);
                }
                else
                {
                    toOrr = *(vu16 *)pixelsDst & 0xfff0;
                    if (loopSrcX & 1)
                        toOrr |= ((*pixelsSrc & 0xf0) >> 4);
                    else
                        toOrr |= ((*pixelsSrc & 0x0f) >> 0);
                }
            }
            *(vu16 *)pixelsDst = toOrr;
        }
    }
}

#define tEvA data[0]
#define tEvB data[1]
#define tEvAEnd data[2]
#define tEvBEnd data[3]
#define tEvADelta data[4]
#define tEvBDelta data[5]
#define tEvWhich data[6]
#define tEvStepCount data[8]

void StartBlendTask(u8 eva_start, u8 evb_start, u8 eva_end, u8 evb_end, u8 ev_step, u8 priority)
{
    u8 taskId = CreateTask(Task_SmoothBlendLayers, priority);
    gTasks[taskId].tEvA = eva_start << 8;
    gTasks[taskId].tEvB = evb_start << 8;
    gTasks[taskId].tEvAEnd = eva_end;
    gTasks[taskId].tEvBEnd = evb_end;
    gTasks[taskId].tEvADelta = (eva_end - eva_start) * 256 / ev_step;
    gTasks[taskId].tEvBDelta = (evb_end - evb_start) * 256 / ev_step;
    gTasks[taskId].tEvStepCount = ev_step;
    SetGpuReg(REG_OFFSET_BLDALPHA, (evb_start << 8) | eva_start);
}

bool8 IsBlendTaskActive(void)
{
    return FuncIsActiveTask(Task_SmoothBlendLayers);
}

static void Task_SmoothBlendLayers(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (tEvStepCount != 0)
    {
        if (tEvWhich == 0)
        {
            tEvA += tEvADelta;
            tEvWhich = 1;
        }
        else
        {
            if (--tEvStepCount != 0)
            {
                tEvB += tEvBDelta;
            }
            else
            {
                tEvA = tEvAEnd << 8;
                tEvB = tEvBEnd << 8;
            }
            tEvWhich = 0;
        }
        SetGpuReg(REG_OFFSET_BLDALPHA, (tEvB & ~0xFF) | ((u16)tEvA >> 8));
        if (tEvStepCount == 0)
            DestroyTask(taskId);
    }
}

u8 Menu2_GetMonSpriteAnchorCoord(u16 species, u32 personality, u8 a2)
{
    if (species != SPECIES_NONE && a2 < 5)
    {
        species--;
        if (sMonSpriteAnchorCoords[species][a2] != 0xFF)
            return sMonSpriteAnchorCoords[species][a2];
    }
    return 32;
}

s8 Menu2_GetMonSpriteAnchorCoordMinusx20(u16 species, u32 personality, u8 a2)
{
    return Menu2_GetMonSpriteAnchorCoord(species, personality, a2) - 32;
}
