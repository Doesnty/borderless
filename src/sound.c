#include "global.h"
#include "gba/m4a_internal.h"
#include "gflib.h"
#include "battle.h"
#include "quest_log.h"
#include "m4a.h"
#include "constants/songs.h"
#include "constants/fanfares.h"
#include "task.h"

struct Fanfare
{
    u16 songNum;
    u16 duration;
};

// TODO: what are these
extern u8 gDisableMapMusicChangeOnMapLoad;
extern u8 gDisableHelpSystemVolumeReduce;

// ewram
EWRAM_DATA struct MusicPlayerInfo* gMPlay_PokemonCry = NULL;
EWRAM_DATA u8 gPokemonCryBGMDuckingCounter = 0;

// iwram bss
static u16 sCurrentMapMusic;
static u16 sNextMapMusic;
static u8 sMapMusicState;
static u8 sMapMusicFadeInSpeed;
static u16 sFanfareCounter;

// iwram common
bool8 gDisableMusic;

extern u32 gBattleTypeFlags;
extern struct MusicPlayerInfo gMPlayInfo_BGM;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_SE3;
extern struct ToneData gCryTable[];
extern struct ToneData gCryTable2[];

static const struct Fanfare sFanfares[] = {
    [FANFARE_00]        = { MUS_LEVEL_UP,         80 },
    [FANFARE_01]        = { MUS_OBTAIN_ITEM,     160 },
    [FANFARE_02]        = { MUS_EVOLVED,         220 },
    [FANFARE_03]        = { MUS_OBTAIN_TMHM,     220 },
    [FANFARE_04]        = { MUS_HEAL,            160 },
    [FANFARE_05]        = { MUS_OBTAIN_BADGE,    340 },
    [FANFARE_06]        = { MUS_MOVE_DELETED,    180 },
    [FANFARE_07]        = { MUS_OBTAIN_BERRY,    120 },
    [FANFARE_08]        = { MUS_SLOTS_JACKPOT,   250 },
    [FANFARE_09]        = { MUS_SLOTS_WIN,       150 },
    [FANFARE_10]        = { MUS_TOO_BAD,         160 },
    [FANFARE_POKEFLUTE] = { MUS_POKE_FLUTE,      450 },
    [FANFARE_KEY_ITEM]  = { MUS_OBTAIN_KEY_ITEM, 170 },
    [FANFARE_DEX_EVAL]  = { MUS_DEX_RATING,      196 }
};

extern u16 SpeciesToCryId(u16);

static void Task_Fanfare(u8 taskId);
static void CreateFanfareTask(void);
static void Task_DuckBGMForPokemonCry(u8 taskId);
static void RestoreBGMVolumeAfterPokemonCry(void);

#define CRY_VOLUME  120 // was 125 in R/S

void InitMapMusic(void)
{
    gDisableMusic = FALSE;
    ResetMapMusic();
}

void MapMusicMain(void)
{
    switch (sMapMusicState)
    {
    case 0:
        break;
    case 1:
        sMapMusicState = 2;
        PlayBGM(sCurrentMapMusic);
        break;
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        if (IsBGMStopped())
        {
            sNextMapMusic = 0;
            sMapMusicState = 0;
        }
        break;
    case 6:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            PlayBGM(sCurrentMapMusic);
        }
        break;
    case 7:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            FadeInNewBGM(sNextMapMusic, sMapMusicFadeInSpeed);
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            sMapMusicFadeInSpeed = 0;
        }
        break;
    }
}

void ResetMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 0;
    sMapMusicFadeInSpeed = 0;
}

u16 GetCurrentMapMusic(void)
{
    return sCurrentMapMusic;
}

void PlayNewMapMusic(u16 songNum)
{
    sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void StopMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void FadeOutMapMusic(u8 speed)
{
    if (IsNotWaitingForBGMStop())
        FadeOutBGM(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 5;
}

void FadeOutAndPlayNewMapMusic(u16 songNum, u8 speed)
{
    FadeOutMapMusic(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 6;
}

void FadeOutAndFadeInNewMapMusic(u16 songNum, u8 fadeOutSpeed, u8 fadeInSpeed)
{
    FadeOutMapMusic(fadeOutSpeed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 7;
    sMapMusicFadeInSpeed = fadeInSpeed;
}

static void FadeInNewMapMusic(u16 songNum, u8 speed)
{
    FadeInNewBGM(songNum, speed);
    sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 2;
    sMapMusicFadeInSpeed = 0;
}

bool8 IsNotWaitingForBGMStop(void)
{
    if (sMapMusicState == 6)
        return FALSE;
    if (sMapMusicState == 5)
        return FALSE;
    if (sMapMusicState == 7)
        return FALSE;
    return TRUE;
}

void PlayFanfareByFanfareNum(u8 fanfareNum)
{
    u16 songNum;

    if(gQuestLogState == QL_STATE_PLAYBACK)
    {
        sFanfareCounter = 0xFF;
    }
    else
    {
        m4aMPlayStop(&gMPlayInfo_BGM);
        songNum = sFanfares[fanfareNum].songNum;
        sFanfareCounter = sFanfares[fanfareNum].duration;
        m4aSongNumStart(songNum);
    }
}

bool8 WaitFanfare(bool8 stop)
{
    if (sFanfareCounter)
    {
        sFanfareCounter--;
        return FALSE;
    }
    else
    {
        if (!stop)
            m4aMPlayContinue(&gMPlayInfo_BGM);
        else
            m4aSongNumStart(MUS_DUMMY);

        return TRUE;
    }
}

void StopFanfareByFanfareNum(u8 fanfareNum)
{
    m4aSongNumStop(sFanfares[fanfareNum].songNum);
}

void PlayFanfare(u16 songNum)
{
    s32 i;
    for (i = 0; (u32)i < 14; i++)
    {
        if (sFanfares[i].songNum == songNum)
        {
            PlayFanfareByFanfareNum(i);
            CreateFanfareTask();
            return;
        }
    }

    PlayFanfareByFanfareNum(0);
    CreateFanfareTask();
}

bool8 IsFanfareTaskInactive(void)
{
    if (FuncIsActiveTask(Task_Fanfare) == TRUE)
        return FALSE;
    return TRUE;
}

static void Task_Fanfare(u8 taskId)
{
    if (sFanfareCounter)
    {
        sFanfareCounter--;
    }
    else
    {
        m4aMPlayContinue(&gMPlayInfo_BGM);
        DestroyTask(taskId);
    }
}

static void CreateFanfareTask(void)
{
    if (FuncIsActiveTask(Task_Fanfare) != TRUE)
        CreateTask(Task_Fanfare, 80);
}

void FadeInNewBGM(u16 songNum, u8 speed)
{
    if (gDisableMusic)
        songNum = 0;
    if (songNum == 0xFFFF)
        songNum = 0;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_BGM);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0);
    m4aSongNumStop(songNum);
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGMTemporarily(u8 speed)
{
    m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMPausedOrStopped(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return TRUE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void FadeInBGM(u8 speed)
{
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGM(u8 speed)
{
    m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMStopped(void)
{
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void PlayCry1(u16 species, s8 pan)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
    PlayCryInternal(species, pan, CRY_VOLUME, 10, 0);
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

void PlayCry2(u16 species, s8 pan, s8 volume, u8 priority)
{
    PlayCryInternal(species, pan, volume, priority, 0);
}

void PlayCry3(u16 species, s8 pan, u8 mode)
{
    if (mode == 1)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, 10, 1);
    }
    else
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, 10, mode);
        gPokemonCryBGMDuckingCounter = 2;
        RestoreBGMVolumeAfterPokemonCry();
    }
}

void PlayCry4(u16 species, s8 pan, u8 mode)
{
    if (mode == 1)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, 10, 1);
    }
    else
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, 10, mode);
    }
}

// PlayCry5 and 6 are not in FR/LG.

void PlayCry7(u16 species, u8 mode) // exclusive to FR/LG
{
    if (!QL_IS_PLAYBACK_STATE)
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, 0, CRY_VOLUME, 10, mode);
    }
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

void PlayCryInternal(u16 species, s8 pan, s8 volume, u8 priority, u8 mode)
{
    bool32 v0;
    u32 release;
    u32 length;
    u32 pitch;
    u32 chorus;
    u32 index;
    u8 table;

    species--;
    length = 140;
    v0 = FALSE;
    release = 0;
    pitch = 15360;
    chorus = 0;

    switch (mode)
    {
    case 0:
        break;
    case 1:
        length = 20;
        release = 225;
        break;
    case 2:
        release = 225;
        pitch = 15600;
        chorus = 20;
        volume = 90;
        break;
    case 3:
        length = 50;
        release = 200;
        pitch = 15800;
        chorus = 20;
        volume = 90;
        break;
    case 4:
        length = 25;
        v0 = TRUE;
        release = 100;
        pitch = 15600;
        chorus = 192;
        volume = 90;
        break;
    case 5:
        release = 200;
        pitch = 14440;
        break;
    case 6: // _08072044
        release = 220;
        pitch = 15555;
        chorus = 192;
        volume = 90; // FR/LG changed this from 70 to 90
        break;
    case 7:
        length = 10;
        release = 100;
        pitch = 14848;
        break;
    case 8:
        length = 60;
        release = 225;
        pitch = 15616;
        break;
    case 9:
        length = 15;
        v0 = TRUE;
        release = 125;
        pitch = 15200;
        break;
    case 10:
        length = 100;
        release = 225;
        pitch = 15200;
        break;
    case 12:
        length = 20;
        release = 225;
    case 11:
        pitch = 15000;
        break;
    }

    SetPokemonCryVolume(volume);
    SetPokemonCryPanpot(pan);
    SetPokemonCryPitch(pitch);
    SetPokemonCryLength(length);
    SetPokemonCryProgress(0);
    SetPokemonCryRelease(release);
    SetPokemonCryChorus(chorus);
    SetPokemonCryPriority(priority);

    // This is a fancy way to get a cry of a pokemon.
    // It creates 4 sets of 128 mini cry tables.
    // If you wish to expand pokemon, you need to
    // append new cases to the switch.
    species = SpeciesToCryId(species);
    index = species & 0x7F;
    table = species / 128;

	gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[(128 * table) + index] : &gCryTable[(128 * table) + index]);
}

bool8 IsCryFinished(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) == TRUE)
    {
        return FALSE;
    }
    else
    {
        ClearPokemonCrySongs();
        return TRUE;
    }
}

void StopCryAndClearCrySongs(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
    ClearPokemonCrySongs();
}

void StopCry(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
}

bool8 IsCryPlayingOrClearCrySongs(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        return TRUE;
    }
    else
    {
        ClearPokemonCrySongs();
        return FALSE;
    }
}

bool8 IsCryPlaying(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
        return TRUE;
    else
        return FALSE;
}

static void Task_DuckBGMForPokemonCry(u8 taskId)
{
    if (gPokemonCryBGMDuckingCounter)
    {
        gPokemonCryBGMDuckingCounter--;
        return;
    }

    if (!IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        DestroyTask(taskId);
    }
}

static void RestoreBGMVolumeAfterPokemonCry(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) != TRUE)
        CreateTask(Task_DuckBGMForPokemonCry, 80);
}

void PlayBGM(u16 songNum)
{
    if (gDisableMusic)
        songNum = 0;
    if (songNum == 0xFFFF)
        songNum = 0;
    m4aSongNumStart(songNum);
}

void PlaySE(u16 songNum)
{
    if(gDisableMapMusicChangeOnMapLoad == 0 && gQuestLogState != QL_STATE_PLAYBACK)
        m4aSongNumStart(songNum);
}

void PlaySE12WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

void PlaySE1WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
}

void PlaySE2WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

void SE12PanpotControl(s8 pan)
{
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

bool8 IsSEPlaying(void)
{
    if ((gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_PAUSE) && (gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_PAUSE))
        return FALSE;
    if (!(gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_TRACK) && !(gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsBGMPlaying(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsSpecialSEPlaying(void)
{
    if (gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

void SetBGMVolume_SuppressHelpSystemReduction(u16 volume)
{
    gDisableHelpSystemVolumeReduce = TRUE;
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, volume);
}

void BGMVolumeMax_EnableHelpSystemReduction(void)
{
    gDisableHelpSystemVolumeReduce = FALSE;
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
}
