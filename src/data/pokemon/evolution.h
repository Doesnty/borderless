const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =
{
    [SPECIES_CREIMU]     = {{EVO_LEVEL, 0, 39, SPECIES_REIMU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AREIMU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DREIMU}},

    [SPECIES_CMARISA]    = {{EVO_LEVEL, 0, 35, SPECIES_CMARISA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 35, SPECIES_AMARISA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 35, SPECIES_SMARISA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 35, SPECIES_ADMARISA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SEAL_CRYSTAL, 35, SPECIES_LMARISA}},

    [SPECIES_CRUMIA]     = {{EVO_LEVEL, 0, 31, SPECIES_RUMIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 31, SPECIES_ARUMIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 31, SPECIES_SRUMIA}},

    [SPECIES_CDAIYOUSEI] = {{EVO_LEVEL, 0, 25, SPECIES_DAIYOUSEI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ADAIYOUSEI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 25, SPECIES_DDAIYOUSEI}},

    [SPECIES_CCIRNO]     = {{EVO_LEVEL, 0, 29, SPECIES_CIRNO},
                            {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 29, SPECIES_SCIRNO},
                            {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 29, SPECIES_TCIRNO},
                            {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 29, SPECIES_ADCIRNO}},

    [SPECIES_CMEILING]   = {{EVO_LEVEL, 0, 31, SPECIES_MEILING},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 31, SPECIES_DMEILING},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 31, SPECIES_SMEILING},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 31, SPECIES_ADMEILING}},

    [SPECIES_CKOAKUMA]   = {{EVO_LEVEL, 0, 25, SPECIES_KOAKUMA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HKOAKUMA}},

    [SPECIES_CPATCHOULI] = {{EVO_LEVEL, 0, 33, SPECIES_PATCHOULI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 33, SPECIES_APATCHOULI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 33, SPECIES_DPATCHOULI}},

    [SPECIES_CSAKUYA]    = {{EVO_LEVEL, 0, 35, SPECIES_CSAKUYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TSAKUYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 35, SPECIES_HSAKUYA}},

    [SPECIES_CREMILIA]   = {{EVO_LEVEL, 0, 39, SPECIES_REMILIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AREMILIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DREMILIA}},

    [SPECIES_CFLANDRE]   = {{EVO_LEVEL, 0, 41, SPECIES_FLANDRE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 41, SPECIES_AFLANDRE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 41, SPECIES_SFLANDRE}},

    [SPECIES_CLETTY]     = {{EVO_LEVEL, 0, 29, SPECIES_LETTY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 29, SPECIES_DLETTY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 29, SPECIES_HLETTY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 29, SPECIES_ADLETTY}},

    [SPECIES_CCHEN]      = {{EVO_LEVEL, 27, SPECIES_CHEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, SPECIES_ACHEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, SPECIES_TCHEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, SPECIES_ADCHEN}},

    [SPECIES_CALICE]     = {{EVO_LEVEL, 0, 35, SPECIES_ALICE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 35, SPECIES_AALICE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TALICE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 35, SPECIES_ADALICE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_DUBIOUS_TOME, 35, SPECIES_DARK_ALICE}},

    [SPECIES_CLILYWHITE] = {{EVO_LEVEL, 0, 25, SPECIES_LILYWHITE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ALILYWHITE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HLILYWHITE}},

    [SPECIES_CLILYBLACK] = {{EVO_LEVEL, 0, 25, SPECIES_LILYBLACK},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ALILYBLACK},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 25, SPECIES_SLILYBLACK}},

    [SPECIES_CLUNASA]    = {{EVO_LEVEL, 0, 29, SPECIES_LUNASA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 29, SPECIES_HLUNASA}},

    [SPECIES_CMERLIN]    = {{EVO_LEVEL, 0, 29, SPECIES_MERLIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 29, SPECIES_HMERLIN}},

    [SPECIES_CLYRICA]    = {{EVO_LEVEL, 0, 29, SPECIES_LYRICA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 29, SPECIES_HLYRICA}},

    [SPECIES_CYOUMU]     = {{EVO_LEVEL, 0, 35, SPECIES_YOUMU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DYOUMU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 35, SPECIES_SYOUMU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SEAL_CRYSTAL, 35, SPECIES_LYOUMU}},

    [SPECIES_CYUYUKO]    = {{EVO_LEVEL, 0, 39, SPECIES_YUYUKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AYUYUKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DYUYUKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SEAL_CRYSTAL, 39, SPECIES_LYUYUKO}},

    [SPECIES_CRAN]       = {{EVO_LEVEL, 0, 39, SPECIES_RAN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_ARAN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 39, SPECIES_HRAN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 39, SPECIES_ADRAN}},

    [SPECIES_CYUKARI]    = {{EVO_LEVEL, 0, 41, SPECIES_YUKARI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 41, SPECIES_DYUKARI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 41, SPECIES_TYUKARI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 41, SPECIES_ADYUKARI}},

    [SPECIES_CSUIKA]     = {{EVO_LEVEL, 0, 39, SPECIES_SUIKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_ASUIKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 39, SPECIES_TSUIKA}},

    [SPECIES_CWRIGGLE]   = {{EVO_LEVEL, 0, 29, SPECIES_WRIGGLE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 29, SPECIES_DWRIGGLE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 29, SPECIES_SWRIGGLE}},

    [SPECIES_CMYSTIA]    = {{EVO_LEVEL, 0, 25, SPECIES_MYSTIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_AMYSTIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HMYSTIA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 25, SPECIES_ADMYSTIA}},

    [SPECIES_CKEINE]     = {{EVO_LEVEL, 0, 31, SPECIES_KEINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 31, SPECIES_AKEINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 31, SPECIES_DKEINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 31, SPECIES_HKEINE}},

    [SPECIES_CTEWI]      = {{EVO_LEVEL, 0, 25, SPECIES_TEWI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ATEWI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 25, SPECIES_DTEWI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 25, SPECIES_ADTEWI}},
    [SPECIES_ATEWI]      = {{EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 25, SPECIES_DTEWI}},
    [SPECIES_DTEWI]      = {{EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ATEWI}},

    [SPECIES_CREISEN]    = {{EVO_LEVEL, 0, 35, SPECIES_REISEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DREISEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TREISEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 35, SPECIES_ADREISEN}},

    [SPECIES_CEIRIN]     = {{EVO_LEVEL, 0, 39, SPECIES_EIRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AEIRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 39, SPECIES_HEIRIN}},

    [SPECIES_CKAGUYA]    = {{EVO_LEVEL, 0, 39, SPECIES_KAGUYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AKAGUYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DKAGUYA}},

    [SPECIES_CMOKOU]     = {{EVO_LEVEL, 0, 41, SPECIES_MOKOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 41, SPECIES_AMOKOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 41, SPECIES_DMOKOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SOLAR_SHARD, 41, SPECIES_ADMOKOU}},

    [SPECIES_CAYA]       = {{EVO_LEVEL, 0, 35, SPECIES_AYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 35, SPECIES_SAYA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TAYA}},

    [SPECIES_CMEDICINE]  = {{EVO_LEVEL, 0, 27, SPECIES_MEDICINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 27, SPECIES_AMEDICINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 27, SPECIES_SMEDICINE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 27, SPECIES_TMEDICINE}},

    [SPECIES_CYUUKA]     = {{EVO_LEVEL, 0, 37, SPECIES_YUUKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_AYUUKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 37, SPECIES_TYUUKA}},

    [SPECIES_CKOMACHI]   = {{EVO_LEVEL, 0, 35, SPECIES_KOMACHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 35, SPECIES_AKOMACHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 35, SPECIES_SKOMACHI}},

    [SPECIES_CEIKI]      = {{EVO_LEVEL, 0, 41, SPECIES_EIKI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 41, SPECIES_AEIKI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 41, SPECIES_DEIKI}},

    [SPECIES_CSHIZUHA]   = {{EVO_LEVEL, 0, 25, SPECIES_SHIZUHA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 25, SPECIES_SSHIZUHA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HSHIZUHA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_AUTUMN_LEAF, 25, SPECIES_AKI_SISTERS}},

    [SPECIES_CMINORIKO]  = {{EVO_LEVEL, 0, 25, SPECIES_MINORIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_AMINORIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 25, SPECIES_DMINORIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_AUTUMN_LEAF, 25, SPECIES_AKI_SISTERS}},

    [SPECIES_CHINA]      = {{EVO_LEVEL, 0, 27, SPECIES_HINA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 27, SPECIES_AHINA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 27, SPECIES_DHINA}},

    [SPECIES_CNITORI]    = {{EVO_LEVEL, 0, 33, SPECIES_NITORI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 33, SPECIES_ANITORI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 33, SPECIES_TNITORI}},

    [SPECIES_CMOMIJI]    = {{EVO_LEVEL, 0, 29, SPECIES_MOMIJI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 29, SPECIES_DMOMIJI}},

    [SPECIES_CSANAE]     = {{EVO_LEVEL, 0, 35, SPECIES_SANAE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 35, SPECIES_ASANAE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TSANAE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_OLD_TEXTBOOK, 35, SPECIES_JKSANAE}},

    [SPECIES_CKANAKO]    = {{EVO_LEVEL, 0, 39, SPECIES_KANAKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AKANAKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DKANAKO}},

    [SPECIES_CSUWAKO]    = {{EVO_LEVEL, 0, 39, SPECIES_SUWAKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_ASUWAKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DSUWAKO}},

    [SPECIES_CREISEN_II] = {{EVO_LEVEL, 0, 25, SPECIES_REISEN_II}},

    [SPECIES_CTOYOHIME]  = {{EVO_LEVEL, 0, 39, SPECIES_TOYOHIME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 39, SPECIES_TTOYOHIME}},

    [SPECIES_CYORIHIME]  = {{EVO_LEVEL, 0, 39, SPECIES_YORIHIME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 39, SPECIES_SYORIHIME}},

    [SPECIES_CIKU]       = {{EVO_LEVEL, 0, 35, SPECIES_IKU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DIKU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TIKU}},

    [SPECIES_CTENSHI]    = {{EVO_LEVEL, 0, 37, SPECIES_TENSHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_ATENSHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 37, SPECIES_DTENSHI}},

    [SPECIES_CKISUME]    = {{EVO_LEVEL, 0, 25, SPECIES_KISUME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 25, SPECIES_TKISUME}},

    [SPECIES_CYAMAME]    = {{EVO_LEVEL, 0, 27, SPECIES_YAMAME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 27, SPECIES_SYAMAME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 27, SPECIES_TYAMAME}},

    [SPECIES_CPARSEE]    = {{EVO_LEVEL, 0, 31, SPECIES_PARSEE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 31, SPECIES_DPARSEE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 31, SPECIES_TPARSEE}},

    [SPECIES_CYUUGI]     = {{EVO_LEVEL, 0, 37, SPECIES_YUUGI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_AYUUGI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 37, SPECIES_DYUUGI}},

    [SPECIES_CSATORI]    = {{EVO_LEVEL, 0, 35, SPECIES_SATORI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DSATORI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TSATORI}},

    [SPECIES_CRIN]       = {{EVO_LEVEL_NINJASK, 0, 33, SPECIES_RIN},
                             {EVO_LEVEL_SHEDINJA, 0, 33, SPECIES_ZFAIRY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 33, SPECIES_ARIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 33, SPECIES_SRIN}},

    [SPECIES_CUTSUHO]    = {{EVO_LEVEL, 0, 37, SPECIES_UTSUHO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_AUTSUHO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 37, SPECIES_SUTSUHO}},

    [SPECIES_CKOISHI]    = {{EVO_LEVEL, 0, 39, SPECIES_KOISHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AKOISHI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 39, SPECIES_SKOISHI}},

    [SPECIES_CNAZRIN]    = {{EVO_LEVEL, 0, 25, SPECIES_NAZRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 25, SPECIES_TNAZRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HNAZRIN}},

    [SPECIES_CKOGASA]    = {{EVO_LEVEL, 0, 29, SPECIES_KOGASA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 29, SPECIES_SKOGASA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 29, SPECIES_TKOGASA}},

    [SPECIES_CICHIRIN]   = {{EVO_LEVEL, 0, 31, SPECIES_ICHIRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 31, SPECIES_DICHIRIN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 31, SPECIES_TICHIRIN}},

    [SPECIES_CMURASA]    = {{EVO_LEVEL, 0, 33, SPECIES_MURASA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 33, SPECIES_AMURASA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 33, SPECIES_DMURASA}},

    [SPECIES_CSHOU]      = {{EVO_LEVEL, 0, 37, SPECIES_SHOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_ASHOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 37, SPECIES_TSHOU}},

    [SPECIES_CBYAKUREN]  = {{EVO_LEVEL, 0, 39, SPECIES_BYAKUREN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 39, SPECIES_HBYAKUREN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 39, SPECIES_TBYAKUREN}},

    [SPECIES_CNUE]       = {{EVO_LEVEL, 0, 39, SPECIES_NUE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_ANUE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 39, SPECIES_TNUE}},

    [SPECIES_SHANGHAI]   = {{EVO_LEVEL, 0, 29, SPECIES_GOLIATH}},
    [SPECIES_HOURAI]     = {{EVO_LEVEL, 0, 29, SPECIES_GOLIATH}},

    [SPECIES_CHATATE]    = {{EVO_LEVEL, 0, 35, SPECIES_HATATE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DHATATE},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_THATATE}},

    [SPECIES_CSUNNY]     = {{EVO_LEVEL, 0, 25, SPECIES_SUNNY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ASUNNY},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 25, SPECIES_DSUNNY}},

    [SPECIES_CLUNA]      = {{EVO_LEVEL, 0, 25, SPECIES_LUNA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ALUNA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 25, SPECIES_TLUNA}},

    [SPECIES_CSTAR]      = {{EVO_LEVEL, 0, 25, SPECIES_STAR},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ASTAR},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 25, SPECIES_HSTAR}},

    [SPECIES_CTOKIKO]    = {{EVO_LEVEL, 0, 25, SPECIES_TOKIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 25, SPECIES_ATOKIKO}},

    [SPECIES_CKYOUKO]    = {{EVO_LEVEL, 0, 27, SPECIES_KYOUKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 27, SPECIES_TKYOUKO}},

    [SPECIES_CYOSHIKA]   = {{EVO_LEVEL, 0, 31, SPECIES_YOSHIKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 31, SPECIES_HYOSHIKA}},

    [SPECIES_CSEIGA]     = {{EVO_LEVEL, 0, 33, SPECIES_SEIGA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 33, SPECIES_SSEIGA}},

    [SPECIES_CTOJIKO]    = {{EVO_LEVEL, 0, 33, SPECIES_TOJIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 33, SPECIES_STOJIKO}},

    [SPECIES_CFUTO]      = {{EVO_LEVEL, 0, 35, SPECIES_FUTO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TFUTO}},

    [SPECIES_CMIKO]      = {{EVO_LEVEL, 0, 39, SPECIES_MIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_AMIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DMIKO}},

    [SPECIES_CMAMIZOU]   = {{EVO_LEVEL, 0, 39, SPECIES_MAMIZOU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 39, SPECIES_DMAMIZOU}},

    [SPECIES_CKOSUZU]    = {{EVO_LEVEL, 0, 25, SPECIES_KOSUZU}},

    [SPECIES_CKOKORO]    = {{EVO_LEVEL, 0, 35, SPECIES_KOKORO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 35, SPECIES_AKOKORO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TKOKORO}},

    [SPECIES_CWAKASAGIHIME] = {{EVO_LEVEL, 0, 27, SPECIES_WAKASAGIHIME},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 27, SPECIES_DWAKASAGIHIME}},

    [SPECIES_CSEKIBANKI] = {{EVO_LEVEL, 0, 29, SPECIES_SEKIBANKI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 29, SPECIES_TSEKIBANKI}},

    [SPECIES_CKAGEROU]   = {{EVO_LEVEL, 0, 31, SPECIES_KAGEROU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 31, SPECIES_HKAGEROU}},

    [SPECIES_CBENBEN]    = {{EVO_LEVEL, 0, 29, SPECIES_BENBEN}},
    
    [SPECIES_CYATSUHASHI] = {{EVO_LEVEL, 0, 29, SPECIES_YATSUHASHI}},

    [SPECIES_CSEIJA]     = {{EVO_LEVEL, 0, 35, SPECIES_SEIJA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 35, SPECIES_DSEIJA}},

    [SPECIES_CSHINMYOUMARU] = {{EVO_LEVEL, 0, 39, SPECIES_SHINMYOUMARU},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 39, SPECIES_ASHINMYOUMARU}},

    [SPECIES_CRAIKO]     = {{EVO_LEVEL, 0, 37, SPECIES_RAIKO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_ARAIKO}},

    [SPECIES_CKASEN]     = {{EVO_LEVEL, 0, 41, SPECIES_KASEN},
                             {EVO_LEVEL_HELD_ITEM, ITEM_ASSIST_SHARD, 41, SPECIES_HKASEN}},

    [SPECIES_CSUMIREKO]  = {{EVO_LEVEL, 0, 35, SPECIES_SUMIREKO}},

    [SPECIES_CSEIRAN]    = {{EVO_LEVEL, 0, 25, SPECIES_SEIRAN}},
    [SPECIES_CRINGO]     = {{EVO_LEVEL, 0, 27, SPECIES_RINGO}},
    [SPECIES_CDOREMY]    = {{EVO_LEVEL, 0, 35, SPECIES_DOREMY}},
    [SPECIES_CSAGUME]    = {{EVO_LEVEL, 0, 37, SPECIES_SAGUME}},
    [SPECIES_CCLOWNPIECE] = {{EVO_LEVEL, 0, 33, SPECIES_CLOWNPIECE}},
    [SPECIES_CJUNKO]     = {{EVO_LEVEL, 0, 39, SPECIES_JUNKO}},
    [SPECIES_CHECATIA]   = {{EVO_LEVEL, 0, 41, SPECIES_HECATIA}},

    [SPECIES_CJOON]      = {{EVO_LEVEL, 0, 33, SPECIES_JOON}},
    [SPECIES_CSHION]     = {{EVO_LEVEL, 0, 33, SPECIES_SHION}},

    [SPECIES_CETERNITY]  = {{EVO_LEVEL, 0, 25, SPECIES_ETERNITY}},
    [SPECIES_CNEMUNO]    = {{EVO_LEVEL, 0, 29, SPECIES_NEMUNO}},
    [SPECIES_CAUNN]      = {{EVO_LEVEL, 0, 27, SPECIES_AUNN}},
    [SPECIES_NARUMI]     = {{EVO_LEVEL, 0, 31, SPECIES_NARUMI}},
    [SPECIES_CMAI_AND_SATONO] = {{EVO_LEVEL, 0, 31, SPECIES_MAI_AND_SATONO}},
    [SPECIES_COKINA]     = {{EVO_LEVEL, 0, 41, SPECIES_OKINA}},
    
    [SPECIES_CEIKA]      = {{EVO_LEVEL, 0, 27, SPECIES_EIKA}},
    [SPECIES_CURUMI]     = {{EVO_LEVEL, 0, 29, SPECIES_URUMI}},
    [SPECIES_CKUTAKA]    = {{EVO_LEVEL, 0, 29, SPECIES_KUTAKA}},
    [SPECIES_CYACHIE]    = {{EVO_LEVEL, 0, 33, SPECIES_YACHIE}},
    [SPECIES_CMAYUMI]    = {{EVO_LEVEL, 0, 35, SPECIES_MAYUMI}},
    [SPECIES_CKEIKI]     = {{EVO_LEVEL, 0, 39, SPECIES_KEIKI}},
    [SPECIES_CSAKI]      = {{EVO_LEVEL, 0, 39, SPECIES_SAKI}},
    [SPECIES_CYUUMA]     = {{EVO_LEVEL, 0, 37, SPECIES_YUUMA}},
    
    [SPECIES_CMIKE]      = {{EVO_LEVEL, 0, 27, SPECIES_MIKE}},
    [SPECIES_CTAKANE]    = {{EVO_LEVEL, 0, 33, SPECIES_TAKANE}},
    [SPECIES_CSANNYO]    = {{EVO_LEVEL, 0, 29, SPECIES_SANNYO}},
    [SPECIES_CMISUMARU]  = {{EVO_LEVEL, 0, 33, SPECIES_MISUMARU}},
    [SPECIES_CTSUKASA]   = {{EVO_LEVEL, 0, 31, SPECIES_TSUKASA}},
    [SPECIES_CMEGUMU]    = {{EVO_LEVEL, 0, 35, SPECIES_MEGUMU}},
    [SPECIES_CCHIMATA]   = {{EVO_LEVEL, 0, 39, SPECIES_CHIMATA}},
    [SPECIES_CMOMOYO]    = {{EVO_LEVEL, 0, 39, SPECIES_MOMOYO}},
    
    [SPECIES_CMIYOI]     = {{EVO_LEVEL, 0, 25, SPECIES_MIYOI}},
    
    [SPECIES_CBITEN]     = {{EVO_LEVEL, 0, 29, SPECIES_BITEN}},
    [SPECIES_CENOKO]     = {{EVO_LEVEL, 0, 29, SPECIES_ENOKO}},
    [SPECIES_CCHIYARI]   = {{EVO_LEVEL, 0, 29, SPECIES_CHIYARI}},
    [SPECIES_CHISAMI]    = {{EVO_LEVEL, 0, 29, SPECIES_HISAMI}},
    [SPECIES_CZANMU]     = {{EVO_LEVEL, 0, 37, SPECIES_ZANMU}},

    [SPECIES_CHAKUREI]   = {{EVO_LEVEL, 0, 39, SPECIES_HAKUREI}},
    [SPECIES_CKIRISAME]  = {{EVO_LEVEL, 0, 37, SPECIES_KIRISAME}},
    
    [SPECIES_CSHINGYOKU] = {{EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_SHINGYOKUO},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 37, SPECIES_SHINGYOKUM},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 37, SPECIES_SHINGYOKUF}},
    [SPECIES_CMAGAN]     = {{EVO_LEVEL, 0, 39, SPECIES_MAGAN}},
    [SPECIES_CMIMA]      = {{EVO_LEVEL, 0, 39, SPECIES_MIMA}},
    [SPECIES_CELIS]      = {{EVO_LEVEL, 0, 39, SPECIES_ELIS}},
    [SPECIES_CKIKURI]    = {{EVO_LEVEL, 0, 39, SPECIES_KIKURI}},
    [SPECIES_CKONNGARA]   = {{EVO_LEVEL, 0, 39, SPECIES_KONNGARA}},
    [SPECIES_CSARIEL]    = {{EVO_LEVEL, 0, 41, SPECIES_SARIEL},
                             {EVO_LEVEL_HELD_ITEM, ITEM_SWIFT_SHARD, 41, SPECIES_SSARIEL}},

    [SPECIES_CRIKA]      = {{EVO_LEVEL, 0, 35, SPECIES_RIKA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_TECH_SHARD, 35, SPECIES_TRIKA}},
    [SPECIES_CMEIRA]     = {{EVO_LEVEL, 0, 31, SPECIES_MEIRA}},
    
    [SPECIES_CELLEN]     = {{EVO_LEVEL, 0, 27, SPECIES_ELLEN}},
    [SPECIES_CKOTOHIME]  = {{EVO_LEVEL, 0, 27, SPECIES_KOTOHIME}},
    [SPECIES_CKANA]      = {{EVO_LEVEL, 0, 29, SPECIES_KANA}},
    [SPECIES_CRIKAKO]    = {{EVO_LEVEL, 0, 29, SPECIES_RIKAKO}},
    [SPECIES_CCHIYURI]   = {{EVO_LEVEL, 0, 33, SPECIES_CHIYURI}},
    [SPECIES_CYUMEMI]    = {{EVO_LEVEL, 0, 41, SPECIES_YUMEMI}},
    
    [SPECIES_CORANGE]    = {{EVO_LEVEL, 0, 25, SPECIES_ORANGE}},
    [SPECIES_CKURUMI]    = {{EVO_LEVEL, 0, 27, SPECIES_KURUMI}},
    [SPECIES_CELLY]      = {{EVO_LEVEL, 0, 33, SPECIES_ELLY}},
    [SPECIES_CKAZAMI]    = {{EVO_LEVEL, 0, 37, SPECIES_KAZAMI},
                             {EVO_LEVEL_HELD_ITEM, ITEM_POWER_SHARD, 37, SPECIES_AKAZAMI}},
    [SPECIES_CMUGETSU]   = {{EVO_LEVEL, 0, 39, SPECIES_MUGETSU}},
    [SPECIES_CGENGETSU]  = {{EVO_LEVEL, 0, 39, SPECIES_GENGETSU}},

    [SPECIES_CSARA]      = {{EVO_LEVEL, 0, 29, SPECIES_SARA}},
    [SPECIES_CLOUISE]    = {{EVO_LEVEL, 0, 31, SPECIES_LOUISE}},
    [SPECIES_CARISU]     = {{EVO_LEVEL, 0, 35, SPECIES_ARISU}},
    [SPECIES_CYUKI]      = {{EVO_LEVEL, 0, 33, SPECIES_YUKI}},
    [SPECIES_CMAI]       = {{EVO_LEVEL, 0, 33, SPECIES_MAI}},
    [SPECIES_CYUMEKO]    = {{EVO_LEVEL, 0, 37, SPECIES_YUMEKO}},
    [SPECIES_CSHINKI]    = {{EVO_LEVEL, 0, 41, SPECIES_SHINKI}},
    
    [SPECIES_CYOUKI]     = {{EVO_LEVEL, 0, 41, SPECIES_YOUKI}},
    [SPECIES_CSENDAI]    = {{EVO_LEVEL, 0, 41, SPECIES_SENDAI}},
    [SPECIES_CTENMA]     = {{EVO_LEVEL, 0, 39, SPECIES_TENMA}},
    [SPECIES_CLAYLA]     = {{EVO_LEVEL, 0, 29, SPECIES_LAYLA},
                             {EVO_LEVEL_HELD_ITEM, ITEM_GUARD_SHARD, 29, SPECIES_DLAYLA}},
};
