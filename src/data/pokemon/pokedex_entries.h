const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
        .categoryName = _("UNKNOWN"),
        .height = 0,
        .weight = 0,
        .description = gDummyPokedexText,
        .unusedDescription = gDummyPokedexTextUnused,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CREIMU] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = gcreimuPokedexText,
    },

    [NATIONAL_DEX_REIMU] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = greimuPokedexText,
    },

    [NATIONAL_DEX_AREIMU] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = gareimuPokedexText,
    },

    [NATIONAL_DEX_DREIMU] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = gdreimuPokedexText,
    },

    [NATIONAL_DEX_CMARISA] = 
    {
        .categoryName = _("Ordinary Witch"),
        .description = gcmarisaPokedexText,
    },

    [NATIONAL_DEX_MARISA] = 
    {
        .categoryName = _("Ordinary Witch"),
        .description = gmarisaPokedexText,
    },

    [NATIONAL_DEX_AMARISA] = 
    {
        .categoryName = _("Very Ordinary"),
        .description = gamarisaPokedexText,
    },

    [NATIONAL_DEX_SMARISA] = 
    {
        .categoryName = _("Ordinary Witch"),
        .description = gsmarisaPokedexText,
    },

    [NATIONAL_DEX_ADMARISA] = 
    {
        .categoryName = _("Advent"),
        .description = gadmarisaPokedexText,
    },

    [NATIONAL_DEX_LMARISA] = 
    {
        .categoryName = _("Lost"),
        .description = glmarisaPokedexText,
    },

    [NATIONAL_DEX_CRUMIA] = 
    {
        .categoryName = _("Darkness"),
        .description = gcrumiaPokedexText,
    },

    [NATIONAL_DEX_RUMIA] = 
    {
        .categoryName = _("Darkness"),
        .description = grumiaPokedexText,
    },

    [NATIONAL_DEX_ARUMIA] = 
    {
        .categoryName = _("Darkness"),
        .description = garumiaPokedexText,
    },

    [NATIONAL_DEX_SRUMIA] = 
    {
        .categoryName = _("Darkness"),
        .description = gsrumiaPokedexText,
    },

    [NATIONAL_DEX_CDAIYOUSEI] = 
    {
        .categoryName = _("Fairy"),
        .description = gcdaiyouseiPokedexText,
    },

    [NATIONAL_DEX_DAIYOUSEI] = 
    {
        .categoryName = _("Great Fairy"),
        .description = gdaiyouseiPokedexText,
    },

    [NATIONAL_DEX_ADAIYOUSEI] = 
    {
        .categoryName = _("Great Fairy"),
        .description = gadaiyouseiPokedexText,
    },

    [NATIONAL_DEX_DDAIYOUSEI] = 
    {
        .categoryName = _("Great Fairy"),
        .description = gddaiyouseiPokedexText,
    },

    [NATIONAL_DEX_CCIRNO] = 
    {
        .categoryName = _("Ice Fairy"),
        .description = gccirnoPokedexText,
    },

    [NATIONAL_DEX_CIRNO] = 
    {
        .categoryName = _("Ice Fairy"),
        .description = gcirnoPokedexText,
    },

    [NATIONAL_DEX_SCIRNO] = 
    {
        .categoryName = _("Ice Fairy"),
        .description = gscirnoPokedexText,
    },

    [NATIONAL_DEX_TCIRNO] = 
    {
        .categoryName = _("Unmelting Fairy"),
        .description = gtcirnoPokedexText,
    },

    [NATIONAL_DEX_ADCIRNO] = 
    {
        .categoryName = _("Advent"),
        .description = gadcirnoPokedexText,
    },

    [NATIONAL_DEX_CMEILING] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gcmeilingPokedexText,
    },

    [NATIONAL_DEX_MEILING] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gmeilingPokedexText,
    },

    [NATIONAL_DEX_DMEILING] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gdmeilingPokedexText,
    },

    [NATIONAL_DEX_SMEILING] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gsmeilingPokedexText,
    },

    [NATIONAL_DEX_ADMEILING] = 
    {
        .categoryName = _("Advent"),
        .description = gadmeilingPokedexText,
    },

    [NATIONAL_DEX_CKOAKUMA] = 
    {
        .categoryName = _("Devil"),
        .description = gckoakumaPokedexText,
    },

    [NATIONAL_DEX_KOAKUMA] = 
    {
        .categoryName = _("Devil"),
        .description = gkoakumaPokedexText,
    },

    [NATIONAL_DEX_HKOAKUMA] = 
    {
        .categoryName = _("Devil"),
        .description = ghkoakumaPokedexText,
    },

    [NATIONAL_DEX_CPATCHOULI] = 
    {
        .categoryName = _("Magician"),
        .description = gcpatchouliPokedexText,
    },

    [NATIONAL_DEX_PATCHOULI] = 
    {
        .categoryName = _("Magician"),
        .description = gpatchouliPokedexText,
    },

    [NATIONAL_DEX_APATCHOULI] = 
    {
        .categoryName = _("Magician"),
        .description = gapatchouliPokedexText,
    },

    [NATIONAL_DEX_DPATCHOULI] = 
    {
        .categoryName = _("Magician"),
        .description = gdpatchouliPokedexText,
    },

    [NATIONAL_DEX_CSAKUYA] = 
    {
        .categoryName = _("Maid"),
        .description = gcsakuyaPokedexText,
    },

    [NATIONAL_DEX_SAKUYA] = 
    {
        .categoryName = _("Maid"),
        .description = gsakuyaPokedexText,
    },

    [NATIONAL_DEX_TSAKUYA] = 
    {
        .categoryName = _("Maid"),
        .description = gtsakuyaPokedexText,
    },

    [NATIONAL_DEX_HSAKUYA] = 
    {
        .categoryName = _("Maid"),
        .description = ghsakuyaPokedexText,
    },

    [NATIONAL_DEX_CREMILIA] = 
    {
        .categoryName = _("Vampire"),
        .description = gcremiliaPokedexText,
    },

    [NATIONAL_DEX_REMILIA] = 
    {
        .categoryName = _("Vampire"),
        .description = gremiliaPokedexText,
    },

    [NATIONAL_DEX_AREMILIA] = 
    {
        .categoryName = _("Vampire"),
        .description = garemiliaPokedexText,
    },

    [NATIONAL_DEX_DREMILIA] = 
    {
        .categoryName = _("Charismatic"),
        .description = gdremiliaPokedexText,
    },

    [NATIONAL_DEX_CFLANDRE] = 
    {
        .categoryName = _("Vampire"),
        .description = gcflandrePokedexText,
    },

    [NATIONAL_DEX_FLANDRE] = 
    {
        .categoryName = _("Recluse"),
        .description = gflandrePokedexText,
    },

    [NATIONAL_DEX_AFLANDRE] = 
    {
        .categoryName = _("Destructive"),
        .description = gaflandrePokedexText,
    },

    [NATIONAL_DEX_SFLANDRE] = 
    {
        .categoryName = _("Vampire"),
        .description = gsflandrePokedexText,
    },

    [NATIONAL_DEX_CLETTY] = 
    {
        .categoryName = _("Yuki-onna"),
        .description = gclettyPokedexText,
    },

    [NATIONAL_DEX_LETTY] = 
    {
        .categoryName = _("Yuki-onna"),
        .description = glettyPokedexText,
    },

    [NATIONAL_DEX_DLETTY] = 
    {
        .categoryName = _("Yuki-onna"),
        .description = gdlettyPokedexText,
    },

    [NATIONAL_DEX_HLETTY] = 
    {
        .categoryName = _("Yuki-onna"),
        .description = ghlettyPokedexText,
    },

    [NATIONAL_DEX_ADLETTY] = 
    {
        .categoryName = _("Advent"),
        .description = gadlettyPokedexText,
    },

    [NATIONAL_DEX_CCHEN] = 
    {
        .categoryName = _("Cat"),
        .description = gcchenPokedexText,
    },

    [NATIONAL_DEX_CHEN] = 
    {
        .categoryName = _("Cat"),
        .description = gchenPokedexText,
    },

    [NATIONAL_DEX_ACHEN] = 
    {
        .categoryName = _("Cat"),
        .description = gachenPokedexText,
    },

    [NATIONAL_DEX_TCHEN] = 
    {
        .categoryName = _("Cat"),
        .description = gtchenPokedexText,
    },

    [NATIONAL_DEX_ADCHEN] = 
    {
        .categoryName = _("Advent"),
        .description = gadchenPokedexText,
    },

    [NATIONAL_DEX_CALICE] = 
    {
        .categoryName = _("Puppeteer"),
        .description = gcalicePokedexText,
    },

    [NATIONAL_DEX_ALICE] = 
    {
        .categoryName = _("Puppeteer"),
        .description = galicePokedexText,
    },

    [NATIONAL_DEX_AALICE] = 
    {
        .categoryName = _("Puppeteer"),
        .description = gaalicePokedexText,
    },

    [NATIONAL_DEX_TALICE] = 
    {
        .categoryName = _("Puppeteer"),
        .description = gtalicePokedexText,
    },

    [NATIONAL_DEX_ADALICE] = 
    {
        .categoryName = _("Advent"),
        .description = gadalicePokedexText,
    },

    [NATIONAL_DEX_DARK_ALICE] = 
    {
        .categoryName = _("Puppet"),
        .description = gdark_alicePokedexText,
    },

    [NATIONAL_DEX_CLILYWHITE] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = gclilywhitePokedexText,
    },

    [NATIONAL_DEX_LILYWHITE] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = glilywhitePokedexText,
    },

    [NATIONAL_DEX_ALILYWHITE] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = galilywhitePokedexText,
    },

    [NATIONAL_DEX_HLILYWHITE] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = ghlilywhitePokedexText,
    },

    [NATIONAL_DEX_CLILYBLACK] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = gclilyblackPokedexText,
    },

    [NATIONAL_DEX_LILYBLACK] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = glilyblackPokedexText,
    },

    [NATIONAL_DEX_ALILYBLACK] = 
    {
        .categoryName = _("Heroic Fairy"),
        .description = galilyblackPokedexText,
    },

    [NATIONAL_DEX_SLILYBLACK] = 
    {
        .categoryName = _("Spring Fairy"),
        .description = gslilyblackPokedexText,
    },

    [NATIONAL_DEX_CLUNASA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gclunasaPokedexText,
    },

    [NATIONAL_DEX_LUNASA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = glunasaPokedexText,
    },

    [NATIONAL_DEX_HLUNASA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = ghlunasaPokedexText,
    },

    [NATIONAL_DEX_CMERLIN] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gcmerlinPokedexText,
    },

    [NATIONAL_DEX_MERLIN] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gmerlinPokedexText,
    },

    [NATIONAL_DEX_HMERLIN] = 
    {
        .categoryName = _("Poltergeist"),
        .description = ghmerlinPokedexText,
    },

    [NATIONAL_DEX_CLYRICA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gclyricaPokedexText,
    },

    [NATIONAL_DEX_LYRICA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = glyricaPokedexText,
    },

    [NATIONAL_DEX_HLYRICA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = ghlyricaPokedexText,
    },

    [NATIONAL_DEX_CYOUMU] = 
    {
        .categoryName = _("Half-Baked"),
        .description = gcyoumuPokedexText,
    },

    [NATIONAL_DEX_YOUMU] = 
    {
        .categoryName = _("Half-Phantom"),
        .description = gyoumuPokedexText,
    },

    [NATIONAL_DEX_DYOUMU] = 
    {
        .categoryName = _("Half-Phantom"),
        .description = gdyoumuPokedexText,
    },

    [NATIONAL_DEX_SYOUMU] = 
    {
        .categoryName = _("Half-Phantom"),
        .description = gsyoumuPokedexText,
    },

    [NATIONAL_DEX_LYOUMU] = 
    {
        .categoryName = _("Lost"),
        .description = glyoumuPokedexText,
    },

    [NATIONAL_DEX_CYUYUKO] = 
    {
        .categoryName = _("Ghost"),
        .description = gcyuyukoPokedexText,
    },

    [NATIONAL_DEX_YUYUKO] = 
    {
        .categoryName = _("Ghost"),
        .description = gyuyukoPokedexText,
    },

    [NATIONAL_DEX_AYUYUKO] = 
    {
        .categoryName = _("Ghost"),
        .description = gayuyukoPokedexText,
    },

    [NATIONAL_DEX_DYUYUKO] = 
    {
        .categoryName = _("Ghost"),
        .description = gdyuyukoPokedexText,
    },

    [NATIONAL_DEX_LYUYUKO] = 
    {
        .categoryName = _("Lost"),
        .description = glyuyukoPokedexText,
    },

    [NATIONAL_DEX_CRAN] = 
    {
        .categoryName = _("Shikigami"),
        .description = gcranPokedexText,
    },

    [NATIONAL_DEX_RAN] = 
    {
        .categoryName = _("Shikigami"),
        .description = granPokedexText,
    },

    [NATIONAL_DEX_ARAN] = 
    {
        .categoryName = _("Shikigami"),
        .description = garanPokedexText,
    },

    [NATIONAL_DEX_HRAN] = 
    {
        .categoryName = _("Shikigami"),
        .description = ghranPokedexText,
    },

    [NATIONAL_DEX_ADRAN] = 
    {
        .categoryName = _("Advent"),
        .description = gadranPokedexText,
    },

    [NATIONAL_DEX_CYUKARI] = 
    {
        .categoryName = _("Gap Youkai"),
        .description = gcyukariPokedexText,
    },

    [NATIONAL_DEX_YUKARI] = 
    {
        .categoryName = _("Gap Youkai"),
        .description = gyukariPokedexText,
    },

    [NATIONAL_DEX_DYUKARI] = 
    {
        .categoryName = _("Gap Youkai"),
        .description = gdyukariPokedexText,
    },

    [NATIONAL_DEX_TYUKARI] = 
    {
        .categoryName = _("Gap Youkai"),
        .description = gtyukariPokedexText,
    },

    [NATIONAL_DEX_ADYUKARI] = 
    {
        .categoryName = _("Advent"),
        .description = gadyukariPokedexText,
    },

    [NATIONAL_DEX_CSUIKA] = 
    {
        .categoryName = _("Drunk Oni"),
        .description = gcsuikaPokedexText,
    },

    [NATIONAL_DEX_SUIKA] = 
    {
        .categoryName = _("Drunk Oni"),
        .description = gsuikaPokedexText,
    },

    [NATIONAL_DEX_ASUIKA] = 
    {
        .categoryName = _("Drunk Oni"),
        .description = gasuikaPokedexText,
    },

    [NATIONAL_DEX_TSUIKA] = 
    {
        .categoryName = _("Drunk Oni"),
        .description = gtsuikaPokedexText,
    },

    [NATIONAL_DEX_CWRIGGLE] = 
    {
        .categoryName = _("Firefly"),
        .description = gcwrigglePokedexText,
    },

    [NATIONAL_DEX_WRIGGLE] = 
    {
        .categoryName = _("Firefly"),
        .description = gwrigglePokedexText,
    },

    [NATIONAL_DEX_DWRIGGLE] = 
    {
        .categoryName = _("Firefly"),
        .description = gdwrigglePokedexText,
    },

    [NATIONAL_DEX_SWRIGGLE] = 
    {
        .categoryName = _("Firefly"),
        .description = gswrigglePokedexText,
    },

    [NATIONAL_DEX_CMYSTIA] = 
    {
        .categoryName = _("Night Sparrow"),
        .description = gcmystiaPokedexText,
    },

    [NATIONAL_DEX_MYSTIA] = 
    {
        .categoryName = _("Night Sparrow"),
        .description = gmystiaPokedexText,
    },

    [NATIONAL_DEX_AMYSTIA] = 
    {
        .categoryName = _("Night Sparrow"),
        .description = gamystiaPokedexText,
    },

    [NATIONAL_DEX_HMYSTIA] = 
    {
        .categoryName = _("Night Sparrow"),
        .description = ghmystiaPokedexText,
    },

    [NATIONAL_DEX_ADMYSTIA] = 
    {
        .categoryName = _("Advent"),
        .description = gadmystiaPokedexText,
    },

    [NATIONAL_DEX_CKEINE] = 
    {
        .categoryName = _("Teacher"),
        .description = gckeinePokedexText,
    },

    [NATIONAL_DEX_KEINE] = 
    {
        .categoryName = _("Teacher"),
        .description = gkeinePokedexText,
    },

    [NATIONAL_DEX_AKEINE] = 
    {
        .categoryName = _("Hakutaku"),
        .description = gakeinePokedexText,
    },

    [NATIONAL_DEX_DKEINE] = 
    {
        .categoryName = _("Hakutaku"),
        .description = gdkeinePokedexText,
    },

    [NATIONAL_DEX_HKEINE] = 
    {
        .categoryName = _("Teacher"),
        .description = ghkeinePokedexText,
    },

    [NATIONAL_DEX_CTEWI] = 
    {
        .categoryName = _("Rabbit"),
        .description = gctewiPokedexText,
    },

    [NATIONAL_DEX_TEWI] = 
    {
        .categoryName = _("Rabbit"),
        .description = gtewiPokedexText,
    },

    [NATIONAL_DEX_ATEWI] = 
    {
        .categoryName = _("Rabbit"),
        .description = gatewiPokedexText,
    },

    [NATIONAL_DEX_DTEWI] = 
    {
        .categoryName = _("Rabbit"),
        .description = gdtewiPokedexText,
    },

    [NATIONAL_DEX_ADTEWI] = 
    {
        .categoryName = _("Advent"),
        .description = gadtewiPokedexText,
    },

    [NATIONAL_DEX_CREISEN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gcreisenPokedexText,
    },

    [NATIONAL_DEX_REISEN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = greisenPokedexText,
    },

    [NATIONAL_DEX_DREISEN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gdreisenPokedexText,
    },

    [NATIONAL_DEX_TREISEN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gtreisenPokedexText,
    },

    [NATIONAL_DEX_ADREISEN] = 
    {
        .categoryName = _("Advent"),
        .description = gadreisenPokedexText,
    },

    [NATIONAL_DEX_CEIRIN] = 
    {
        .categoryName = _("Moon Pharmacist"),
        .description = gceirinPokedexText,
    },

    [NATIONAL_DEX_EIRIN] = 
    {
        .categoryName = _("Moon Pharmacist"),
        .description = geirinPokedexText,
    },

    [NATIONAL_DEX_AEIRIN] = 
    {
        .categoryName = _("Moon Pharmacist"),
        .description = gaeirinPokedexText,
    },

    [NATIONAL_DEX_HEIRIN] = 
    {
        .categoryName = _("Moon Pharmacist"),
        .description = gheirinPokedexText,
    },

    [NATIONAL_DEX_CKAGUYA] = 
    {
        .categoryName = _("Moon Princess"),
        .description = gckaguyaPokedexText,
    },

    [NATIONAL_DEX_KAGUYA] = 
    {
        .categoryName = _("Moon Princess"),
        .description = gkaguyaPokedexText,
    },

    [NATIONAL_DEX_AKAGUYA] = 
    {
        .categoryName = _("Moon Princess"),
        .description = gakaguyaPokedexText,
    },

    [NATIONAL_DEX_DKAGUYA] = 
    {
        .categoryName = _("Moon Princess"),
        .description = gdkaguyaPokedexText,
    },

    [NATIONAL_DEX_CMOKOU] = 
    {
        .categoryName = _("Immortal"),
        .description = gcmokouPokedexText,
    },

    [NATIONAL_DEX_MOKOU] = 
    {
        .categoryName = _("Immortal"),
        .description = gmokouPokedexText,
    },

    [NATIONAL_DEX_AMOKOU] = 
    {
        .categoryName = _("Immortal"),
        .description = gamokouPokedexText,
    },

    [NATIONAL_DEX_DMOKOU] = 
    {
        .categoryName = _("Immortal"),
        .description = gdmokouPokedexText,
    },

    [NATIONAL_DEX_ADMOKOU] = 
    {
        .categoryName = _("Advent"),
        .description = gadmokouPokedexText,
    },

    [NATIONAL_DEX_CAYA] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gcayaPokedexText,
    },

    [NATIONAL_DEX_AYA] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gayaPokedexText,
    },

    [NATIONAL_DEX_SAYA] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gsayaPokedexText,
    },

    [NATIONAL_DEX_TAYA] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gtayaPokedexText,
    },

    [NATIONAL_DEX_CMEDICINE] = 
    {
        .categoryName = _("Poison Doll"),
        .description = gcmedicinePokedexText,
    },

    [NATIONAL_DEX_MEDICINE] = 
    {
        .categoryName = _("Poison Doll"),
        .description = gmedicinePokedexText,
    },

    [NATIONAL_DEX_AMEDICINE] = 
    {
        .categoryName = _("Poison Doll"),
        .description = gamedicinePokedexText,
    },

    [NATIONAL_DEX_SMEDICINE] = 
    {
        .categoryName = _("Poison Doll"),
        .description = gsmedicinePokedexText,
    },

    [NATIONAL_DEX_TMEDICINE] = 
    {
        .categoryName = _("Poison Doll"),
        .description = gtmedicinePokedexText,
    },

    [NATIONAL_DEX_CYUUKA] = 
    {
        .categoryName = _("Flowering"),
        .description = gcyuukaPokedexText,
    },

    [NATIONAL_DEX_YUUKA] = 
    {
        .categoryName = _("Flowering"),
        .description = gyuukaPokedexText,
    },

    [NATIONAL_DEX_AYUUKA] = 
    {
        .categoryName = _("Flowering"),
        .description = gayuukaPokedexText,
    },

    [NATIONAL_DEX_TYUUKA] = 
    {
        .categoryName = _("Flowering"),
        .description = gtyuukaPokedexText,
    },

    [NATIONAL_DEX_CKOMACHI] = 
    {
        .categoryName = _("Shinigami"),
        .description = gckomachiPokedexText,
    },

    [NATIONAL_DEX_KOMACHI] = 
    {
        .categoryName = _("Shinigami"),
        .description = gkomachiPokedexText,
    },

    [NATIONAL_DEX_AKOMACHI] = 
    {
        .categoryName = _("Shinigami"),
        .description = gakomachiPokedexText,
    },

    [NATIONAL_DEX_SKOMACHI] = 
    {
        .categoryName = _("Shinigami"),
        .description = gskomachiPokedexText,
    },

    [NATIONAL_DEX_CEIKI] = 
    {
        .categoryName = _("Supreme Judge"),
        .description = gceikiPokedexText,
    },

    [NATIONAL_DEX_EIKI] = 
    {
        .categoryName = _("Supreme Judge"),
        .description = geikiPokedexText,
    },

    [NATIONAL_DEX_AEIKI] = 
    {
        .categoryName = _("Supreme Judge"),
        .description = gaeikiPokedexText,
    },

    [NATIONAL_DEX_DEIKI] = 
    {
        .categoryName = _("Supreme Judge"),
        .description = gdeikiPokedexText,
    },

    [NATIONAL_DEX_AKYUU] = 
    {
        .categoryName = _("Chronicler"),
        .description = gakyuuPokedexText,
    },

    [NATIONAL_DEX_CSHIZUHA] = 
    {
        .categoryName = _("Fall Leaves"),
        .description = gcshizuhaPokedexText,
    },

    [NATIONAL_DEX_SHIZUHA] = 
    {
        .categoryName = _("Fall Leaves"),
        .description = gshizuhaPokedexText,
    },

    [NATIONAL_DEX_SSHIZUHA] = 
    {
        .categoryName = _("Fall Leaves"),
        .description = gsshizuhaPokedexText,
    },

    [NATIONAL_DEX_HSHIZUHA] = 
    {
        .categoryName = _("Fall Leaves"),
        .description = ghshizuhaPokedexText,
    },

    [NATIONAL_DEX_CMINORIKO] = 
    {
        .categoryName = _("Harvest"),
        .description = gcminorikoPokedexText,
    },

    [NATIONAL_DEX_MINORIKO] = 
    {
        .categoryName = _("Harvest"),
        .description = gminorikoPokedexText,
    },

    [NATIONAL_DEX_AMINORIKO] = 
    {
        .categoryName = _("Harvest"),
        .description = gaminorikoPokedexText,
    },

    [NATIONAL_DEX_DMINORIKO] = 
    {
        .categoryName = _("Harvest"),
        .description = gdminorikoPokedexText,
    },

    [NATIONAL_DEX_AKI_SISTERS] = 
    {
        .categoryName = _("Autumn"),
        .description = gaki_sistersPokedexText,
    },

    [NATIONAL_DEX_CHINA] = 
    {
        .categoryName = _("Misfortune"),
        .description = gchinaPokedexText,
    },

    [NATIONAL_DEX_HINA] = 
    {
        .categoryName = _("Misfortune"),
        .description = ghinaPokedexText,
    },

    [NATIONAL_DEX_AHINA] = 
    {
        .categoryName = _("Misfortune"),
        .description = gahinaPokedexText,
    },

    [NATIONAL_DEX_DHINA] = 
    {
        .categoryName = _("Misfortune"),
        .description = gdhinaPokedexText,
    },

    [NATIONAL_DEX_CNITORI] = 
    {
        .categoryName = _("Kappa"),
        .description = gcnitoriPokedexText,
    },

    [NATIONAL_DEX_NITORI] = 
    {
        .categoryName = _("Kappa"),
        .description = gnitoriPokedexText,
    },

    [NATIONAL_DEX_ANITORI] = 
    {
        .categoryName = _("Kappa"),
        .description = ganitoriPokedexText,
    },

    [NATIONAL_DEX_TNITORI] = 
    {
        .categoryName = _("Kappa"),
        .description = gtnitoriPokedexText,
    },

    [NATIONAL_DEX_CMOMIJI] = 
    {
        .categoryName = _("Wolf Tengu"),
        .description = gcmomijiPokedexText,
    },

    [NATIONAL_DEX_MOMIJI] = 
    {
        .categoryName = _("Wolf Tengu"),
        .description = gmomijiPokedexText,
    },

    [NATIONAL_DEX_DMOMIJI] = 
    {
        .categoryName = _("Wolf Tengu"),
        .description = gdmomijiPokedexText,
    },

    [NATIONAL_DEX_CSANAE] = 
    {
        .categoryName = _("Wind Priestess"),
        .description = gcsanaePokedexText,
    },

    [NATIONAL_DEX_SANAE] = 
    {
        .categoryName = _("Wind Priestess"),
        .description = gsanaePokedexText,
    },

    [NATIONAL_DEX_ASANAE] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = gasanaePokedexText,
    },

    [NATIONAL_DEX_TSANAE] = 
    {
        .categoryName = _("Shrine Maiden"),
        .description = gtsanaePokedexText,
    },

    [NATIONAL_DEX_JKSANAE] = 
    {
        .categoryName = _("Schoolgirl"),
        .description = gjksanaePokedexText,
    },

    [NATIONAL_DEX_CKANAKO] = 
    {
        .categoryName = _("Wind Goddess"),
        .description = gckanakoPokedexText,
    },

    [NATIONAL_DEX_KANAKO] = 
    {
        .categoryName = _("Wind Goddess"),
        .description = gkanakoPokedexText,
    },

    [NATIONAL_DEX_AKANAKO] = 
    {
        .categoryName = _("Wind Goddess"),
        .description = gakanakoPokedexText,
    },

    [NATIONAL_DEX_DKANAKO] = 
    {
        .categoryName = _("Wind Goddess"),
        .description = gdkanakoPokedexText,
    },

    [NATIONAL_DEX_CSUWAKO] = 
    {
        .categoryName = _("Earth Goddess"),
        .description = gcsuwakoPokedexText,
    },

    [NATIONAL_DEX_SUWAKO] = 
    {
        .categoryName = _("Earth Goddess"),
        .description = gsuwakoPokedexText,
    },

    [NATIONAL_DEX_ASUWAKO] = 
    {
        .categoryName = _("Earth Goddess"),
        .description = gasuwakoPokedexText,
    },

    [NATIONAL_DEX_DSUWAKO] = 
    {
        .categoryName = _("Earth Goddess"),
        .description = gdsuwakoPokedexText,
    },

    [NATIONAL_DEX_CREISEN_II] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gcreisen_iiPokedexText,
    },

    [NATIONAL_DEX_REISEN_II] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = greisen_iiPokedexText,
    },

    [NATIONAL_DEX_CTOYOHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gctoyohimePokedexText,
    },

    [NATIONAL_DEX_TOYOHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gtoyohimePokedexText,
    },

    [NATIONAL_DEX_TTOYOHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gttoyohimePokedexText,
    },

    [NATIONAL_DEX_CYORIHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gcyorihimePokedexText,
    },

    [NATIONAL_DEX_YORIHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gyorihimePokedexText,
    },

    [NATIONAL_DEX_SYORIHIME] = 
    {
        .categoryName = _("Lunarian"),
        .description = gsyorihimePokedexText,
    },

    [NATIONAL_DEX_CIKU] = 
    {
        .categoryName = _("Oarfish"),
        .description = gcikuPokedexText,
    },

    [NATIONAL_DEX_IKU] = 
    {
        .categoryName = _("Oarfish"),
        .description = gikuPokedexText,
    },

    [NATIONAL_DEX_DIKU] = 
    {
        .categoryName = _("Oarfish"),
        .description = gdikuPokedexText,
    },

    [NATIONAL_DEX_TIKU] = 
    {
        .categoryName = _("Oarfish"),
        .description = gtikuPokedexText,
    },

    [NATIONAL_DEX_CTENSHI] = 
    {
        .categoryName = _("Celestial"),
        .description = gctenshiPokedexText,
    },

    [NATIONAL_DEX_TENSHI] = 
    {
        .categoryName = _("Celestial"),
        .description = gtenshiPokedexText,
    },

    [NATIONAL_DEX_ATENSHI] = 
    {
        .categoryName = _("Celestial"),
        .description = gatenshiPokedexText,
    },

    [NATIONAL_DEX_DTENSHI] = 
    {
        .categoryName = _("Celestial"),
        .description = gdtenshiPokedexText,
    },

    [NATIONAL_DEX_CKISUME] = 
    {
        .categoryName = _("Bucket"),
        .description = gckisumePokedexText,
    },

    [NATIONAL_DEX_KISUME] = 
    {
        .categoryName = _("Bucket"),
        .description = gkisumePokedexText,
    },

    [NATIONAL_DEX_TKISUME] = 
    {
        .categoryName = _("Bucket"),
        .description = gtkisumePokedexText,
    },

    [NATIONAL_DEX_CYAMAME] = 
    {
        .categoryName = _("Earth Spider"),
        .description = gcyamamePokedexText,
    },

    [NATIONAL_DEX_YAMAME] = 
    {
        .categoryName = _("Earth Spider"),
        .description = gyamamePokedexText,
    },

    [NATIONAL_DEX_SYAMAME] = 
    {
        .categoryName = _("Earth Spider"),
        .description = gsyamamePokedexText,
    },

    [NATIONAL_DEX_TYAMAME] = 
    {
        .categoryName = _("Earth Spider"),
        .description = gtyamamePokedexText,
    },

    [NATIONAL_DEX_CPARSEE] = 
    {
        .categoryName = _("Jealousy"),
        .description = gcparseePokedexText,
    },

    [NATIONAL_DEX_PARSEE] = 
    {
        .categoryName = _("Jealousy"),
        .description = gparseePokedexText,
    },

    [NATIONAL_DEX_DPARSEE] = 
    {
        .categoryName = _("Jealousy"),
        .description = gdparseePokedexText,
    },

    [NATIONAL_DEX_TPARSEE] = 
    {
        .categoryName = _("Jealousy"),
        .description = gtparseePokedexText,
    },

    [NATIONAL_DEX_CYUUGI] = 
    {
        .categoryName = _("Oni"),
        .description = gcyuugiPokedexText,
    },

    [NATIONAL_DEX_YUUGI] = 
    {
        .categoryName = _("Oni"),
        .description = gyuugiPokedexText,
    },

    [NATIONAL_DEX_AYUUGI] = 
    {
        .categoryName = _("Oni"),
        .description = gayuugiPokedexText,
    },

    [NATIONAL_DEX_DYUUGI] = 
    {
        .categoryName = _("Oni"),
        .description = gdyuugiPokedexText,
    },

    [NATIONAL_DEX_CSATORI] = 
    {
        .categoryName = _("Satori"),
        .description = gcsatoriPokedexText,
    },

    [NATIONAL_DEX_SATORI] = 
    {
        .categoryName = _("Satori"),
        .description = gsatoriPokedexText,
    },

    [NATIONAL_DEX_DSATORI] = 
    {
        .categoryName = _("Satori"),
        .description = gdsatoriPokedexText,
    },

    [NATIONAL_DEX_TSATORI] = 
    {
        .categoryName = _("Satori"),
        .description = gtsatoriPokedexText,
    },

    [NATIONAL_DEX_CRIN] = 
    {
        .categoryName = _("Kasha"),
        .description = gcrinPokedexText,
    },

    [NATIONAL_DEX_RIN] = 
    {
        .categoryName = _("Kasha"),
        .description = grinPokedexText,
    },

    [NATIONAL_DEX_ARIN] = 
    {
        .categoryName = _("Kasha"),
        .description = garinPokedexText,
    },

    [NATIONAL_DEX_SRIN] = 
    {
        .categoryName = _("Hell Cat"),
        .description = gsrinPokedexText,
    },

    [NATIONAL_DEX_ZFAIRY] = 
    {
        .categoryName = _("Fairy"),
        .description = gzfairyPokedexText,
    },

    [NATIONAL_DEX_CUTSUHO] = 
    {
        .categoryName = _("Hell Raven"),
        .description = gcutsuhoPokedexText,
    },

    [NATIONAL_DEX_UTSUHO] = 
    {
        .categoryName = _("Nuclear"),
        .description = gutsuhoPokedexText,
    },

    [NATIONAL_DEX_AUTSUHO] = 
    {
        .categoryName = _("Nuclear"),
        .description = gautsuhoPokedexText,
    },

    [NATIONAL_DEX_SUTSUHO] = 
    {
        .categoryName = _("Nuclear"),
        .description = gsutsuhoPokedexText,
    },

    [NATIONAL_DEX_CKOISHI] = 
    {
        .categoryName = _("Satori"),
        .description = gckoishiPokedexText,
    },

    [NATIONAL_DEX_KOISHI] = 
    {
        .categoryName = _("Satori"),
        .description = gkoishiPokedexText,
    },

    [NATIONAL_DEX_AKOISHI] = 
    {
        .categoryName = _("Satori"),
        .description = gakoishiPokedexText,
    },

    [NATIONAL_DEX_SKOISHI] = 
    {
        .categoryName = _("Satori"),
        .description = gskoishiPokedexText,
    },

    [NATIONAL_DEX_CNAZRIN] = 
    {
        .categoryName = _("Dowsing Mouse"),
        .description = gcnazrinPokedexText,
    },

    [NATIONAL_DEX_NAZRIN] = 
    {
        .categoryName = _("Dowsing Mouse"),
        .description = gnazrinPokedexText,
    },

    [NATIONAL_DEX_TNAZRIN] = 
    {
        .categoryName = _("Dowsing Mouse"),
        .description = gtnazrinPokedexText,
    },

    [NATIONAL_DEX_HNAZRIN] = 
    {
        .categoryName = _("Dowsing Mouse"),
        .description = ghnazrinPokedexText,
    },

    [NATIONAL_DEX_CKOGASA] = 
    {
        .categoryName = _("Umbrella"),
        .description = gckogasaPokedexText,
    },

    [NATIONAL_DEX_KOGASA] = 
    {
        .categoryName = _("Umbrella"),
        .description = gkogasaPokedexText,
    },

    [NATIONAL_DEX_SKOGASA] = 
    {
        .categoryName = _("Umbrella"),
        .description = gskogasaPokedexText,
    },

    [NATIONAL_DEX_TKOGASA] = 
    {
        .categoryName = _("Umbrella"),
        .description = gtkogasaPokedexText,
    },

    [NATIONAL_DEX_CICHIRIN] = 
    {
        .categoryName = _("Nun"),
        .description = gcichirinPokedexText,
    },

    [NATIONAL_DEX_ICHIRIN] = 
    {
        .categoryName = _("Nyuudou User"),
        .description = gichirinPokedexText,
    },

    [NATIONAL_DEX_DICHIRIN] = 
    {
        .categoryName = _("Nun"),
        .description = gdichirinPokedexText,
    },

    [NATIONAL_DEX_TICHIRIN] = 
    {
        .categoryName = _("Nun"),
        .description = gtichirinPokedexText,
    },

    [NATIONAL_DEX_CMURASA] = 
    {
        .categoryName = _("Shipwrecker"),
        .description = gcmurasaPokedexText,
    },

    [NATIONAL_DEX_MURASA] = 
    {
        .categoryName = _("Shipwrecker"),
        .description = gmurasaPokedexText,
    },

    [NATIONAL_DEX_AMURASA] = 
    {
        .categoryName = _("Captain"),
        .description = gamurasaPokedexText,
    },

    [NATIONAL_DEX_DMURASA] = 
    {
        .categoryName = _("Shipwrecker"),
        .description = gdmurasaPokedexText,
    },

    [NATIONAL_DEX_CSHOU] = 
    {
        .categoryName = _("Tiger"),
        .description = gcshouPokedexText,
    },

    [NATIONAL_DEX_SHOU] = 
    {
        .categoryName = _("Bishamonten"),
        .description = gshouPokedexText,
    },

    [NATIONAL_DEX_ASHOU] = 
    {
        .categoryName = _("Bishamonten"),
        .description = gashouPokedexText,
    },

    [NATIONAL_DEX_TSHOU] = 
    {
        .categoryName = _("Tiger"),
        .description = gtshouPokedexText,
    },

    [NATIONAL_DEX_CBYAKUREN] = 
    {
        .categoryName = _("Buddhist"),
        .description = gcbyakurenPokedexText,
    },

    [NATIONAL_DEX_BYAKUREN] = 
    {
        .categoryName = _("Buddhist"),
        .description = gbyakurenPokedexText,
    },

    [NATIONAL_DEX_DBYAKUREN] = 
    {
        .categoryName = _("Buddhist"),
        .description = gdbyakurenPokedexText,
    },

    [NATIONAL_DEX_TBYAKUREN] = 
    {
        .categoryName = _("Buddhist"),
        .description = gtbyakurenPokedexText,
    },

    [NATIONAL_DEX_CNUE] = 
    {
        .categoryName = _("Nue"),
        .description = gcnuePokedexText,
    },

    [NATIONAL_DEX_NUE] = 
    {
        .categoryName = _("Nue"),
        .description = gnuePokedexText,
    },

    [NATIONAL_DEX_ANUE] = 
    {
        .categoryName = _("Nue"),
        .description = ganuePokedexText,
    },

    [NATIONAL_DEX_TNUE] = 
    {
        .categoryName = _("Nue"),
        .description = gtnuePokedexText,
    },

    [NATIONAL_DEX_TENSOKU] = 
    {
        .categoryName = _("Giant Robot"),
        .description = gtensokuPokedexText,
    },

    [NATIONAL_DEX_SHANGHAI] = 
    {
        .categoryName = _("Doll"),
        .description = gshanghaiPokedexText,
    },

    [NATIONAL_DEX_HOURAI] = 
    {
        .categoryName = _("Doll"),
        .description = ghouraiPokedexText,
    },

    [NATIONAL_DEX_GOLIATH] = 
    {
        .categoryName = _("Prototype"),
        .description = ggoliathPokedexText,
    },

    [NATIONAL_DEX_NAMAZU] = 
    {
        .categoryName = _("Great Catfish"),
        .description = gnamazuPokedexText,
    },

    [NATIONAL_DEX_CHATATE] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gchatatePokedexText,
    },

    [NATIONAL_DEX_HATATE] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = ghatatePokedexText,
    },

    [NATIONAL_DEX_DHATATE] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gdhatatePokedexText,
    },

    [NATIONAL_DEX_THATATE] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gthatatePokedexText,
    },

    [NATIONAL_DEX_CSUNNY] = 
    {
        .categoryName = _("Sunlight Fairy"),
        .description = gcsunnyPokedexText,
    },

    [NATIONAL_DEX_SUNNY] = 
    {
        .categoryName = _("Sunlight Fairy"),
        .description = gsunnyPokedexText,
    },

    [NATIONAL_DEX_ASUNNY] = 
    {
        .categoryName = _("Sunlight Fairy"),
        .description = gasunnyPokedexText,
    },

    [NATIONAL_DEX_DSUNNY] = 
    {
        .categoryName = _("Sunlight Fairy"),
        .description = gdsunnyPokedexText,
    },

    [NATIONAL_DEX_CLUNA] = 
    {
        .categoryName = _("Moonlight Fairy"),
        .description = gclunaPokedexText,
    },

    [NATIONAL_DEX_LUNA] = 
    {
        .categoryName = _("Moonlight Fairy"),
        .description = glunaPokedexText,
    },

    [NATIONAL_DEX_ALUNA] = 
    {
        .categoryName = _("Moonlight Fairy"),
        .description = galunaPokedexText,
    },

    [NATIONAL_DEX_TLUNA] = 
    {
        .categoryName = _("Moonlight Fairy"),
        .description = gtlunaPokedexText,
    },

    [NATIONAL_DEX_CSTAR] = 
    {
        .categoryName = _("Starlight Fairy"),
        .description = gcstarPokedexText,
    },

    [NATIONAL_DEX_STAR] = 
    {
        .categoryName = _("Starlight Fairy"),
        .description = gstarPokedexText,
    },

    [NATIONAL_DEX_ASTAR] = 
    {
        .categoryName = _("Starlight Fairy"),
        .description = gastarPokedexText,
    },

    [NATIONAL_DEX_HSTAR] = 
    {
        .categoryName = _("Starlight Fairy"),
        .description = ghstarPokedexText,
    },

    [NATIONAL_DEX_RINNOSUKE] = 
    {
        .categoryName = _("Antiquarian"),
        .description = grinnosukePokedexText,
    },

    [NATIONAL_DEX_CTOKIKO] = 
    {
        .categoryName = _("Ibis"),
        .description = gctokikoPokedexText,
    },

    [NATIONAL_DEX_TOKIKO] = 
    {
        .categoryName = _("Ibis"),
        .description = gtokikoPokedexText,
    },

    [NATIONAL_DEX_ATOKIKO] = 
    {
        .categoryName = _("Ibis"),
        .description = gatokikoPokedexText,
    },

    [NATIONAL_DEX_CKYOUKO] = 
    {
        .categoryName = _("Echo"),
        .description = gckyoukoPokedexText,
    },

    [NATIONAL_DEX_KYOUKO] = 
    {
        .categoryName = _("Echo"),
        .description = gkyoukoPokedexText,
    },

    [NATIONAL_DEX_TKYOUKO] = 
    {
        .categoryName = _("Echo"),
        .description = gtkyoukoPokedexText,
    },

    [NATIONAL_DEX_CYOSHIKA] = 
    {
        .categoryName = _("Walking Corpse"),
        .description = gcyoshikaPokedexText,
    },

    [NATIONAL_DEX_YOSHIKA] = 
    {
        .categoryName = _("Walking Corpse"),
        .description = gyoshikaPokedexText,
    },

    [NATIONAL_DEX_HYOSHIKA] = 
    {
        .categoryName = _("Walking Corpse"),
        .description = ghyoshikaPokedexText,
    },

    [NATIONAL_DEX_CSEIGA] = 
    {
        .categoryName = _("Wicked Hermit"),
        .description = gcseigaPokedexText,
    },

    [NATIONAL_DEX_SEIGA] = 
    {
        .categoryName = _("Wicked Hermit"),
        .description = gseigaPokedexText,
    },

    [NATIONAL_DEX_SSEIGA] = 
    {
        .categoryName = _("Wicked Hermit"),
        .description = gsseigaPokedexText,
    },

    [NATIONAL_DEX_CTOJIKO] = 
    {
        .categoryName = _("Thunder Ghost"),
        .description = gctojikoPokedexText,
    },

    [NATIONAL_DEX_TOJIKO] = 
    {
        .categoryName = _("Thunder Ghost"),
        .description = gtojikoPokedexText,
    },

    [NATIONAL_DEX_STOJIKO] = 
    {
        .categoryName = _("Thunder Ghost"),
        .description = gstojikoPokedexText,
    },

    [NATIONAL_DEX_CFUTO] = 
    {
        .categoryName = _("Shikaisen"),
        .description = gcfutoPokedexText,
    },

    [NATIONAL_DEX_FUTO] = 
    {
        .categoryName = _("Shikaisen"),
        .description = gfutoPokedexText,
    },

    [NATIONAL_DEX_TFUTO] = 
    {
        .categoryName = _("Shikaisen"),
        .description = gtfutoPokedexText,
    },

    [NATIONAL_DEX_CMIKO] = 
    {
        .categoryName = _("Taoist"),
        .description = gcmikoPokedexText,
    },

    [NATIONAL_DEX_MIKO] = 
    {
        .categoryName = _("Taoist"),
        .description = gmikoPokedexText,
    },

    [NATIONAL_DEX_AMIKO] = 
    {
        .categoryName = _("Taoist"),
        .description = gamikoPokedexText,
    },

    [NATIONAL_DEX_DMIKO] = 
    {
        .categoryName = _("Taoist"),
        .description = gdmikoPokedexText,
    },

    [NATIONAL_DEX_CMAMIZOU] = 
    {
        .categoryName = _("Tanuki"),
        .description = gcmamizouPokedexText,
    },

    [NATIONAL_DEX_MAMIZOU] = 
    {
        .categoryName = _("Tanuki"),
        .description = gmamizouPokedexText,
    },

    [NATIONAL_DEX_DMAMIZOU] = 
    {
        .categoryName = _("Just a Human"),
        .description = gdmamizouPokedexText,
    },

    [NATIONAL_DEX_CKOSUZU] = 
    {
        .categoryName = _("Bookworm"),
        .description = gckosuzuPokedexText,
    },

    [NATIONAL_DEX_KOSUZU] = 
    {
        .categoryName = _("Bookworm"),
        .description = gkosuzuPokedexText,
    },

    [NATIONAL_DEX_JINYOU] = 
    {
        .categoryName = _("Diviner"),
        .description = gjinyouPokedexText,
    },

    [NATIONAL_DEX_CKOKORO] = 
    {
        .categoryName = _("Menreiki"),
        .description = gckokoroPokedexText,
    },

    [NATIONAL_DEX_KOKORO] = 
    {
        .categoryName = _("Menreiki"),
        .description = gkokoroPokedexText,
    },

    [NATIONAL_DEX_AKOKORO] = 
    {
        .categoryName = _("Menreiki"),
        .description = gakokoroPokedexText,
    },

    [NATIONAL_DEX_TKOKORO] = 
    {
        .categoryName = _("Menreiki"),
        .description = gtkokoroPokedexText,
    },

    [NATIONAL_DEX_CWAKASAGIHIME] = 
    {
        .categoryName = _("Mermaid"),
        .description = gcwakasagihimePokedexText,
    },

    [NATIONAL_DEX_WAKASAGIHIME] = 
    {
        .categoryName = _("Mermaid"),
        .description = gwakasagihimePokedexText,
    },

    [NATIONAL_DEX_DWAKASAGIHIME] = 
    {
        .categoryName = _("Mermaid"),
        .description = gdwakasagihimePokedexText,
    },

    [NATIONAL_DEX_CSEKIBANKI] = 
    {
        .categoryName = _("Dullahan"),
        .description = gcsekibankiPokedexText,
    },

    [NATIONAL_DEX_SEKIBANKI] = 
    {
        .categoryName = _("Dullahan"),
        .description = gsekibankiPokedexText,
    },

    [NATIONAL_DEX_TSEKIBANKI] = 
    {
        .categoryName = _("Dullahan"),
        .description = gtsekibankiPokedexText,
    },

    [NATIONAL_DEX_CKAGEROU] = 
    {
        .categoryName = _("Werewolf"),
        .description = gckagerouPokedexText,
    },

    [NATIONAL_DEX_KAGEROU] = 
    {
        .categoryName = _("Werewolf"),
        .description = gkagerouPokedexText,
    },

    [NATIONAL_DEX_HKAGEROU] = 
    {
        .categoryName = _("Werewolf"),
        .description = ghkagerouPokedexText,
    },

    [NATIONAL_DEX_CBENBEN] = 
    {
        .categoryName = _("Biwa"),
        .description = gcbenbenPokedexText,
    },

    [NATIONAL_DEX_BENBEN] = 
    {
        .categoryName = _("Biwa"),
        .description = gbenbenPokedexText,
    },

    [NATIONAL_DEX_CYATSUHASHI] = 
    {
        .categoryName = _("Koto"),
        .description = gcyatsuhashiPokedexText,
    },

    [NATIONAL_DEX_YATSUHASHI] = 
    {
        .categoryName = _("Koto"),
        .description = gyatsuhashiPokedexText,
    },

    [NATIONAL_DEX_CSEIJA] = 
    {
        .categoryName = _("Upending"),
        .description = gcseijaPokedexText,
    },

    [NATIONAL_DEX_SEIJA] = 
    {
        .categoryName = _("Upending"),
        .description = gseijaPokedexText,
    },

    [NATIONAL_DEX_DSEIJA] = 
    {
        .categoryName = _("Upending"),
        .description = gdseijaPokedexText,
    },

    [NATIONAL_DEX_CSHINMYOUMARU] = 
    {
        .categoryName = _("Inchling"),
        .description = gcshinmyoumaruPokedexText,
    },

    [NATIONAL_DEX_SHINMYOUMARU] = 
    {
        .categoryName = _("Inchling"),
        .description = gshinmyoumaruPokedexText,
    },

    [NATIONAL_DEX_ASHINMYOUMARU] = 
    {
        .categoryName = _("Inchling"),
        .description = gashinmyoumaruPokedexText,
    },

    [NATIONAL_DEX_CRAIKO] = 
    {
        .categoryName = _("Taiko Drum"),
        .description = gcraikoPokedexText,
    },

    [NATIONAL_DEX_RAIKO] = 
    {
        .categoryName = _("Modern Drumset"),
        .description = graikoPokedexText,
    },

    [NATIONAL_DEX_ARAIKO] = 
    {
        .categoryName = _("Modern Drumset"),
        .description = garaikoPokedexText,
    },

    [NATIONAL_DEX_CKASEN] = 
    {
        .categoryName = _("Hermit"),
        .description = gckasenPokedexText,
    },

    [NATIONAL_DEX_KASEN] = 
    {
        .categoryName = _("Hermit"),
        .description = gkasenPokedexText,
    },

    [NATIONAL_DEX_HKASEN] = 
    {
        .categoryName = _("Hermit"),
        .description = ghkasenPokedexText,
    },

    [NATIONAL_DEX_CSUMIREKO] = 
    {
        .categoryName = _("Grade School"),
        .description = gcsumirekoPokedexText,
    },

    [NATIONAL_DEX_SUMIREKO] = 
    {
        .categoryName = _("High School"),
        .description = gsumirekoPokedexText,
    },

    [NATIONAL_DEX_CSEIRAN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gcseiranPokedexText,
    },

    [NATIONAL_DEX_SEIRAN] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gseiranPokedexText,
    },

    [NATIONAL_DEX_CRINGO] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gcringoPokedexText,
    },

    [NATIONAL_DEX_RINGO] = 
    {
        .categoryName = _("Moon Rabbit"),
        .description = gringoPokedexText,
    },

    [NATIONAL_DEX_CDOREMY] = 
    {
        .categoryName = _("Baku"),
        .description = gcdoremyPokedexText,
    },

    [NATIONAL_DEX_DOREMY] = 
    {
        .categoryName = _("Baku"),
        .description = gdoremyPokedexText,
    },

    [NATIONAL_DEX_CSAGUME] = 
    {
        .categoryName = _("Lunar Goddess"),
        .description = gcsagumePokedexText,
    },

    [NATIONAL_DEX_SAGUME] = 
    {
        .categoryName = _("Lunar Goddess"),
        .description = gsagumePokedexText,
    },

    [NATIONAL_DEX_CCLOWNPIECE] = 
    {
        .categoryName = _("Hell Fairy"),
        .description = gcclownpiecePokedexText,
    },

    [NATIONAL_DEX_CLOWNPIECE] = 
    {
        .categoryName = _("Hell Fairy"),
        .description = gclownpiecePokedexText,
    },

    [NATIONAL_DEX_CJUNKO] = 
    {
        .categoryName = _("Pure"),
        .description = gcjunkoPokedexText,
    },

    [NATIONAL_DEX_JUNKO] = 
    {
        .categoryName = _("Pure"),
        .description = gjunkoPokedexText,
    },

    [NATIONAL_DEX_CHECATIA] = 
    {
        .categoryName = _("Hell Goddess"),
        .description = gchecatiaPokedexText,
    },

    [NATIONAL_DEX_HECATIA] = 
    {
        .categoryName = _("Hell Goddess"),
        .description = ghecatiaPokedexText,
    },

    [NATIONAL_DEX_CJOON] = 
    {
        .categoryName = _("Thrifty"),
        .description = gcjoonPokedexText,
    },

    [NATIONAL_DEX_JOON] = 
    {
        .categoryName = _("Thrifty"),
        .description = gjoonPokedexText,
    },

    [NATIONAL_DEX_CSHION] = 
    {
        .categoryName = _("Poverty"),
        .description = gcshionPokedexText,
    },

    [NATIONAL_DEX_SHION] = 
    {
        .categoryName = _("Poverty"),
        .description = gshionPokedexText,
    },

    [NATIONAL_DEX_CETERNITY] = 
    {
        .categoryName = _("Insect Fairy"),
        .description = gceternityPokedexText,
    },

    [NATIONAL_DEX_ETERNITY] = 
    {
        .categoryName = _("Insect Fairy"),
        .description = geternityPokedexText,
    },

    [NATIONAL_DEX_CNEMUNO] = 
    {
        .categoryName = _("Yamanba"),
        .description = gcnemunoPokedexText,
    },

    [NATIONAL_DEX_NEMUNO] = 
    {
        .categoryName = _("Yamanba"),
        .description = gnemunoPokedexText,
    },

    [NATIONAL_DEX_CAUNN] = 
    {
        .categoryName = _("Komainu"),
        .description = gcaunnPokedexText,
    },

    [NATIONAL_DEX_AUNN] = 
    {
        .categoryName = _("Komainu"),
        .description = gaunnPokedexText,
    },

    [NATIONAL_DEX_CNARUMI] = 
    {
        .categoryName = _("Magician"),
        .description = gcnarumiPokedexText,
    },

    [NATIONAL_DEX_NARUMI] = 
    {
        .categoryName = _("Magician"),
        .description = gnarumiPokedexText,
    },

    [NATIONAL_DEX_CMAI_AND_SATONO] = 
    {
        .categoryName = _("Dancing"),
        .description = gcmai_and_satonoPokedexText,
    },

    [NATIONAL_DEX_MAI_AND_SATONO] = 
    {
        .categoryName = _("Dancing"),
        .description = gmai_and_satonoPokedexText,
    },

    [NATIONAL_DEX_COKINA] = 
    {
        .categoryName = _("Secret God"),
        .description = gcokinaPokedexText,
    },

    [NATIONAL_DEX_OKINA] = 
    {
        .categoryName = _("Secret God"),
        .description = gokinaPokedexText,
    },

    [NATIONAL_DEX_CEIKA] = 
    {
        .categoryName = _("Stillborn"),
        .description = gceikaPokedexText,
    },

    [NATIONAL_DEX_EIKA] = 
    {
        .categoryName = _("Stillborn"),
        .description = geikaPokedexText,
    },

    [NATIONAL_DEX_CURUMI] = 
    {
        .categoryName = _("Cow Oni"),
        .description = gcurumiPokedexText,
    },

    [NATIONAL_DEX_URUMI] = 
    {
        .categoryName = _("Cow Oni"),
        .description = gurumiPokedexText,
    },

    [NATIONAL_DEX_CKUTAKA] = 
    {
        .categoryName = _("Chicken God"),
        .description = gckutakaPokedexText,
    },

    [NATIONAL_DEX_KUTAKA] = 
    {
        .categoryName = _("Chicken God"),
        .description = gkutakaPokedexText,
    },

    [NATIONAL_DEX_CYACHIE] = 
    {
        .categoryName = _("Dragon Turtle"),
        .description = gcyachiePokedexText,
    },

    [NATIONAL_DEX_YACHIE] = 
    {
        .categoryName = _("Dragon Turtle"),
        .description = gyachiePokedexText,
    },

    [NATIONAL_DEX_CMAYUMI] = 
    {
        .categoryName = _("Haniwa"),
        .description = gcmayumiPokedexText,
    },

    [NATIONAL_DEX_MAYUMI] = 
    {
        .categoryName = _("Haniwa"),
        .description = gmayumiPokedexText,
    },

    [NATIONAL_DEX_CKEIKI] = 
    {
        .categoryName = _("Sculptor"),
        .description = gckeikiPokedexText,
    },

    [NATIONAL_DEX_KEIKI] = 
    {
        .categoryName = _("Sculptor"),
        .description = gkeikiPokedexText,
    },

    [NATIONAL_DEX_CSAKI] = 
    {
        .categoryName = _("Pegasus"),
        .description = gcsakiPokedexText,
    },

    [NATIONAL_DEX_SAKI] = 
    {
        .categoryName = _("Pegasus"),
        .description = gsakiPokedexText,
    },

    [NATIONAL_DEX_CYUUMA] = 
    {
        .categoryName = _("Taotie"),
        .description = gcyuumaPokedexText,
    },

    [NATIONAL_DEX_YUUMA] = 
    {
        .categoryName = _("Taotie"),
        .description = gyuumaPokedexText,
    },

    [NATIONAL_DEX_CMIKE] = 
    {
        .categoryName = _("Cat"),
        .description = gcmikePokedexText,
    },

    [NATIONAL_DEX_MIKE] = 
    {
        .categoryName = _("Cat"),
        .description = gmikePokedexText,
    },

    [NATIONAL_DEX_CTAKANE] = 
    {
        .categoryName = _("Yamawaro"),
        .description = gctakanePokedexText,
    },

    [NATIONAL_DEX_TAKANE] = 
    {
        .categoryName = _("Yamawaro"),
        .description = gtakanePokedexText,
    },

    [NATIONAL_DEX_CSANNYO] = 
    {
        .categoryName = _("Bookmaker"),
        .description = gcsannyoPokedexText,
    },

    [NATIONAL_DEX_SANNYO] = 
    {
        .categoryName = _("Bookmaker"),
        .description = gsannyoPokedexText,
    },

    [NATIONAL_DEX_CMISUMARU] = 
    {
        .categoryName = _("Artisan"),
        .description = gcmisumaruPokedexText,
    },

    [NATIONAL_DEX_MISUMARU] = 
    {
        .categoryName = _("Artisan"),
        .description = gmisumaruPokedexText,
    },

    [NATIONAL_DEX_CTSUKASA] = 
    {
        .categoryName = _("Pipe Fox"),
        .description = gctsukasaPokedexText,
    },

    [NATIONAL_DEX_TSUKASA] = 
    {
        .categoryName = _("Pipe Fox"),
        .description = gtsukasaPokedexText,
    },

    [NATIONAL_DEX_CMEGUMU] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gcmegumuPokedexText,
    },

    [NATIONAL_DEX_MEGUMU] = 
    {
        .categoryName = _("Crow Tengu"),
        .description = gmegumuPokedexText,
    },

    [NATIONAL_DEX_CCHIMATA] = 
    {
        .categoryName = _("Commerce"),
        .description = gcchimataPokedexText,
    },

    [NATIONAL_DEX_CHIMATA] = 
    {
        .categoryName = _("Commerce"),
        .description = gchimataPokedexText,
    },

    [NATIONAL_DEX_CMOMOYO] = 
    {
        .categoryName = _("Excavator"),
        .description = gcmomoyoPokedexText,
    },

    [NATIONAL_DEX_MOMOYO] = 
    {
        .categoryName = _("Excavator"),
        .description = gmomoyoPokedexText,
    },

    [NATIONAL_DEX_CMIYOI] = 
    {
        .categoryName = _("Waitress"),
        .description = gcmiyoiPokedexText,
    },

    [NATIONAL_DEX_MIYOI] = 
    {
        .categoryName = _("Waitress"),
        .description = gmiyoiPokedexText,
    },

    [NATIONAL_DEX_CHAKUREI] = 
    {
        .categoryName = _("Miko"),
        .description = gchakureiPokedexText,
    },

    [NATIONAL_DEX_HAKUREI] = 
    {
        .categoryName = _("Miko"),
        .description = ghakureiPokedexText,
    },

    [NATIONAL_DEX_CKIRISAME] = 
    {
        .categoryName = _("Witch"),
        .description = gckirisamePokedexText,
    },

    [NATIONAL_DEX_KIRISAME] = 
    {
        .categoryName = _("Witch"),
        .description = gkirisamePokedexText,
    },

    [NATIONAL_DEX_CSHINGYOKU] = 
    {
        .categoryName = _("Guardian"),
        .description = gcshingyokuPokedexText,
    },

    [NATIONAL_DEX_SHINGYOKUF] = 
    {
        .categoryName = _("Guardian"),
        .description = gshingyokufPokedexText,
    },

    [NATIONAL_DEX_SHINGYOKUM] = 
    {
        .categoryName = _("Guardian"),
        .description = gshingyokumPokedexText,
    },

    [NATIONAL_DEX_SHINGYOKUO] = 
    {
        .categoryName = _("Guardian"),
        .description = gshingyokuoPokedexText,
    },

    [NATIONAL_DEX_CMAGAN] = 
    {
        .categoryName = _("Evil Eye"),
        .description = gcmaganPokedexText,
    },

    [NATIONAL_DEX_MAGAN] = 
    {
        .categoryName = _("Evil Eyes"),
        .description = gmaganPokedexText,
    },

    [NATIONAL_DEX_CMIMA] = 
    {
        .categoryName = _("Malicious"),
        .description = gcmimaPokedexText,
    },

    [NATIONAL_DEX_MIMA] = 
    {
        .categoryName = _("Malicious"),
        .description = gmimaPokedexText,
    },

    [NATIONAL_DEX_CELIS] = 
    {
        .categoryName = _("Devil"),
        .description = gcelisPokedexText,
    },

    [NATIONAL_DEX_ELIS] = 
    {
        .categoryName = _("Devil"),
        .description = gelisPokedexText,
    },

    [NATIONAL_DEX_CKIKURI] = 
    {
        .categoryName = _("Magic Disc"),
        .description = gckikuriPokedexText,
    },

    [NATIONAL_DEX_KIKURI] = 
    {
        .categoryName = _("Magic Disc"),
        .description = gkikuriPokedexText,
    },

    [NATIONAL_DEX_CKONNGARA] = 
    {
        .categoryName = _("Yaksha"),
        .description = gckonngaraPokedexText,
    },

    [NATIONAL_DEX_KONNGARA] = 
    {
        .categoryName = _("Yaksha"),
        .description = gkonngaraPokedexText,
    },

    [NATIONAL_DEX_CSARIEL] = 
    {
        .categoryName = _("Angel"),
        .description = gcsarielPokedexText,
    },

    [NATIONAL_DEX_SARIEL] = 
    {
        .categoryName = _("Angel"),
        .description = gsarielPokedexText,
    },

    [NATIONAL_DEX_SSARIEL] = 
    {
        .categoryName = _("Oblivion"),
        .description = gssarielPokedexText,
    },

    [NATIONAL_DEX_GENJI] = 
    {
        .categoryName = _("Turtle"),
        .description = ggenjiPokedexText,
    },

    [NATIONAL_DEX_CRIKA] = 
    {
        .categoryName = _("Engineer"),
        .description = gcrikaPokedexText,
    },

    [NATIONAL_DEX_RIKA] = 
    {
        .categoryName = _("Engineer"),
        .description = grikaPokedexText,
    },

    [NATIONAL_DEX_CMEIRA] = 
    {
        .categoryName = _("Samurai"),
        .description = gcmeiraPokedexText,
    },

    [NATIONAL_DEX_MEIRA] = 
    {
        .categoryName = _("Samurai"),
        .description = gmeiraPokedexText,
    },

    [NATIONAL_DEX_MAGIC_STONES] = 
    {
        .categoryName = _("Construct"),
        .description = gmagic_stonesPokedexText,
    },

    [NATIONAL_DEX_CELLEN] = 
    {
        .categoryName = _("Youthful Witch"),
        .description = gcellenPokedexText,
    },

    [NATIONAL_DEX_ELLEN] = 
    {
        .categoryName = _("Youthful Witch"),
        .description = gellenPokedexText,
    },

    [NATIONAL_DEX_CKOTOHIME] = 
    {
        .categoryName = _("Princess"),
        .description = gckotohimePokedexText,
    },

    [NATIONAL_DEX_KOTOHIME] = 
    {
        .categoryName = _("Princess"),
        .description = gkotohimePokedexText,
    },

    [NATIONAL_DEX_CKANA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gckanaPokedexText,
    },

    [NATIONAL_DEX_KANA] = 
    {
        .categoryName = _("Poltergeist"),
        .description = gkanaPokedexText,
    },

    [NATIONAL_DEX_CRIKAKO] = 
    {
        .categoryName = _("Scientist"),
        .description = gcrikakoPokedexText,
    },

    [NATIONAL_DEX_RIKAKO] = 
    {
        .categoryName = _("Scientist"),
        .description = grikakoPokedexText,
    },

    [NATIONAL_DEX_CCHIYURI] = 
    {
        .categoryName = _("Assistant"),
        .description = gcchiyuriPokedexText,
    },

    [NATIONAL_DEX_CHIYURI] = 
    {
        .categoryName = _("Assistant"),
        .description = gchiyuriPokedexText,
    },

    [NATIONAL_DEX_CYUMEMI] = 
    {
        .categoryName = _("Professor"),
        .description = gcyumemiPokedexText,
    },

    [NATIONAL_DEX_YUMEMI] = 
    {
        .categoryName = _("Professor"),
        .description = gyumemiPokedexText,
    },

    [NATIONAL_DEX_RUUKOTO] = 
    {
        .categoryName = _("Robot Maid"),
        .description = gruukotoPokedexText,
    },

    [NATIONAL_DEX_MIMI_CHAN] = 
    {
        .categoryName = _("Missile"),
        .description = gmimi_chanPokedexText,
    },

    [NATIONAL_DEX_CORANGE] = 
    {
        .categoryName = _("Youkai"),
        .description = gcorangePokedexText,
    },

    [NATIONAL_DEX_ORANGE] = 
    {
        .categoryName = _("Youkai"),
        .description = gorangePokedexText,
    },

    [NATIONAL_DEX_CKURUMI] = 
    {
        .categoryName = _("Vampire"),
        .description = gckurumiPokedexText,
    },

    [NATIONAL_DEX_KURUMI] = 
    {
        .categoryName = _("Vampire"),
        .description = gkurumiPokedexText,
    },

    [NATIONAL_DEX_CELLY] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gcellyPokedexText,
    },

    [NATIONAL_DEX_ELLY] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gellyPokedexText,
    },

    [NATIONAL_DEX_CKAZAMI] = 
    {
        .categoryName = _("Sleepy"),
        .description = gckazamiPokedexText,
    },

    [NATIONAL_DEX_KAZAMI] = 
    {
        .categoryName = _("Flowering"),
        .description = gkazamiPokedexText,
    },

    [NATIONAL_DEX_AKAZAMI] = 
    {
        .categoryName = _("Flowering"),
        .description = gakazamiPokedexText,
    },

    [NATIONAL_DEX_CMUGETSU] = 
    {
        .categoryName = _("Demon"),
        .description = gcmugetsuPokedexText,
    },

    [NATIONAL_DEX_MUGETSU] = 
    {
        .categoryName = _("Demon"),
        .description = gmugetsuPokedexText,
    },

    [NATIONAL_DEX_CGENGETSU] = 
    {
        .categoryName = _("Demon"),
        .description = gcgengetsuPokedexText,
    },

    [NATIONAL_DEX_GENGETSU] = 
    {
        .categoryName = _("Demon"),
        .description = ggengetsuPokedexText,
    },

    [NATIONAL_DEX_CSARA] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gcsaraPokedexText,
    },

    [NATIONAL_DEX_SARA] = 
    {
        .categoryName = _("Gatekeeper"),
        .description = gsaraPokedexText,
    },

    [NATIONAL_DEX_CLOUISE] = 
    {
        .categoryName = _("Demon Tourist"),
        .description = gclouisePokedexText,
    },

    [NATIONAL_DEX_LOUISE] = 
    {
        .categoryName = _("Demon Tourist"),
        .description = glouisePokedexText,
    },

    [NATIONAL_DEX_CARISU] = 
    {
        .categoryName = _("Young Magician"),
        .description = gcarisuPokedexText,
    },

    [NATIONAL_DEX_ARISU] = 
    {
        .categoryName = _("Young Magician"),
        .description = garisuPokedexText,
    },

    [NATIONAL_DEX_CYUKI] = 
    {
        .categoryName = _("Fire Magician"),
        .description = gcyukiPokedexText,
    },

    [NATIONAL_DEX_YUKI] = 
    {
        .categoryName = _("Fire Magician"),
        .description = gyukiPokedexText,
    },

    [NATIONAL_DEX_CMAI] = 
    {
        .categoryName = _("Ice Magician"),
        .description = gcmaiPokedexText,
    },

    [NATIONAL_DEX_MAI] = 
    {
        .categoryName = _("Ice Magician"),
        .description = gmaiPokedexText,
    },

    [NATIONAL_DEX_CYUMEKO] = 
    {
        .categoryName = _("Maid"),
        .description = gcyumekoPokedexText,
    },

    [NATIONAL_DEX_YUMEKO] = 
    {
        .categoryName = _("Maid"),
        .description = gyumekoPokedexText,
    },

    [NATIONAL_DEX_CSHINKI] = 
    {
        .categoryName = _("Goddess"),
        .description = gcshinkiPokedexText,
    },

    [NATIONAL_DEX_SHINKI] = 
    {
        .categoryName = _("Goddess"),
        .description = gshinkiPokedexText,
    },

    [NATIONAL_DEX_CSENDAI] = 
    {
        .categoryName = _("Ancestor"),
        .description = gcsendaiPokedexText,
    },

    [NATIONAL_DEX_SENDAI] = 
    {
        .categoryName = _("Ancestor"),
        .description = gsendaiPokedexText,
    },

    [NATIONAL_DEX_CTENMA] = 
    {
        .categoryName = _("Tengu Prince"),
        .description = gctenmaPokedexText,
    },

    [NATIONAL_DEX_TENMA] = 
    {
        .categoryName = _("Tengu Lord"),
        .description = gtenmaPokedexText,
    },

    [NATIONAL_DEX_CLAYLA] = 
    {
        .categoryName = _("Memory"),
        .description = gclaylaPokedexText,
    },

    [NATIONAL_DEX_LAYLA] = 
    {
        .categoryName = _("Memory"),
        .description = glaylaPokedexText,
    },

    [NATIONAL_DEX_DLAYLA] = 
    {
        .categoryName = _("Memory"),
        .description = gdlaylaPokedexText,
    },

    [NATIONAL_DEX_YOUKI] = 
    {
        .categoryName = _("Half-Phantom"),
        .description = gyoukiPokedexText,
    },

    [NATIONAL_DEX_TORI] = 
    {
        .categoryName = _("Birds"),
        .description = gtoriPokedexText,
    },

    [NATIONAL_DEX_2HU] = 
    {
        .categoryName = _("ZUN Art Lesson"),
        .description = g2huPokedexText,
    },

    [NATIONAL_DEX_XSUWAKO] = 
    {
        .categoryName = _("Calamity Ruler"),
        .description = gxsuwakoPokedexText,
    },

    [NATIONAL_DEX_XUTSUHO] = 
    {
        .categoryName = _("Infernal Abyss"),
        .description = gxutsuhoPokedexText,
    },

    [NATIONAL_DEX_XTENSHI] = 
    {
        .categoryName = _("Divine Blight"),
        .description = gxtenshiPokedexText,
    },

    [NATIONAL_DEX_XTENMA] = 
    {
        .categoryName = _("Tengu Conqueror"),
        .description = gxtenmaPokedexText,
    },

    [NATIONAL_DEX_XSENDAI] = 
    {
        .categoryName = _("Fantasy Crusade"),
        .description = gxsendaiPokedexText,
    },
};
