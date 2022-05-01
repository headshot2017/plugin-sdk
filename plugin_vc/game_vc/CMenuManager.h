/*
    Plugin-SDK (Grand Theft Auto Vice City) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "CSprite2d.h"
#include "CPlayerSkin.h"

enum eMenuPageAlignment {
    MENU_ALIGN_NONE = 0,
    MENU_ALIGN_CENTER = 1,
    MENU_ALIGN_LEFT = 2,
    MENU_ALIGN_RIGHT
};

enum eMenuScreen {
    MENUPAGE_NONE = -1,
    MENUPAGE_STATS = 0,
    MENUPAGE_NEW_GAME = 1,
    MENUPAGE_BRIEFS = 2,
    MENUPAGE_SOUND_SETTINGS = 3,
    MENUPAGE_DISPLAY_SETTINGS = 4,
    MENUPAGE_LANGUAGE_SETTINGS = 5,
    MENUPAGE_MAP = 6,
    MENUPAGE_NEW_GAME_RELOAD = 7,
    MENUPAGE_CHOOSE_LOAD_SLOT = 8,
    MENUPAGE_CHOOSE_DELETE_SLOT = 9,
    MENUPAGE_LOAD_SLOT_CONFIRM = 10,
    MENUPAGE_DELETE_SLOT_CONFIRM = 11,
    MENUPAGE_LOADING_IN_PROGRESS = 12,
    MENUPAGE_DELETING_IN_PROGRESS = 13,
    MENUPAGE_DELETE_SUCCESSFUL = 14,
    MENUPAGE_CHOOSE_SAVE_SLOT = 15,
    MENUPAGE_SAVE_OVERWRITE_CONFIRM = 16,
    MENUPAGE_SAVING_IN_PROGRESS = 17,
    MENUPAGE_SAVE_SUCCESSFUL = 18,
    MENUPAGE_SAVE_CUSTOM_WARNING = 19,
    MENUPAGE_SAVE_CHEAT_WARNING = 20,
    MENUPAGE_SKIN_SELECT = 21,
    MENUPAGE_SAVE_UNUSED = 22,
    MENUPAGE_SAVE_FAILED = 23,
    MENUPAGE_SAVE_FAILED_2 = 24,
    MENUPAGE_LOAD_FAILED = 25,
    MENUPAGE_CONTROLLER_PC = 26,
    MENUPAGE_OPTIONS = 27,
    MENUPAGE_EXIT = 28,
    MENUPAGE_START_MENU = 29,
    MENUPAGE_KEYBOARD_CONTROLS = 30,
    MENUPAGE_MOUSE_CONTROLS = 31,
    MENUPAGE_PAUSE_MENU = 32,
    MENUPAGE_34 = 33,
};

enum eMenuAction {
    MENUACTION_NOTHING,
    MENUACTION_LABEL,
    MENUACTION_YES,
    MENUACTION_NO,
    MENUACTION_CHANGEMENU,
    MENUACTION_INVERTPADY,
    MENUACTION_CTRLDISPLAY,
    MENUACTION_FRAMESYNC,
    MENUACTION_FRAMELIMIT,
    MENUACTION_TRAILS,
    MENUACTION_SUBTITLES,
    MENUACTION_WIDESCREEN,
    MENUACTION_BRIGHTNESS,
    MENUACTION_MUSICVOLUME,
    MENUACTION_SFXVOLUME,
    MENUACTION_RADIO,
    MENUACTION_LANG_ENG,
    MENUACTION_LANG_FRE,
    MENUACTION_LANG_GER,
    MENUACTION_LANG_ITA,
    MENUACTION_LANG_SPA,
    MENUACTION_POPULATESLOTS_CHANGEMENU,
    MENUACTION_CHECKSAVE,
    MENUACTION_NEWGAME,
    MENUACTION_RESUME_FROM_SAVEZONE,
    MENUACTION_RELOADIDE,
    MENUACTION_SETDBGFLAG,
    MENUACTION_LOADRADIO,
    MENUACTION_SAVEGAME,
    MENUACTION_29,
    MENUACTION_30,
    MENUACTION_LEGEND,
    MENUACTION_RADARMODE,
    MENUACTION_HUD,
    MENUACTION_GOBACK,
    MENUACTION_REDEFCTRL,
    MENUACTION_GETKEY,
    MENUACTION_SHOWHEADBOB,
    MENUACTION_38,
    MENUACTION_INVVERT,
    MENUACTION_CANCELGAME,
    MENUACTION_RESUME,
    MENUACTION_DONTCANCEL,
    MENUACTION_SCREENRES,
    MENUACTION_AUDIOHW,
    MENUACTION_SPEAKERCONF,
    MENUACTION_PLAYERSETUP,
    MENUACTION_RESTOREDEF,
    MENUACTION_CTRLMETHOD,
    MENUACTION_DYNAMICACOUSTIC,
    MENUACTION_MOUSESTEER,
    MENUACTION_DRAWDIST,
    MENUACTION_MOUSESENS,
    MENUACTION_MP3VOLUMEBOOST
};

enum eMenuSprites {
    MENUSPRITE_BACKGROUND,
    MENUSPRITE_VCLOGO,
    MENUSPRITE_MOUSE,
    MENUSPRITE_MAPTOP01,
    MENUSPRITE_MAPTOP02,
    MENUSPRITE_MAPTOP03,
    MENUSPRITE_MAPMID01,
    MENUSPRITE_MAPMID02,
    MENUSPRITE_MAPMID03,
    MENUSPRITE_MAPBOT01,
    MENUSPRITE_MAPBOT02,
    MENUSPRITE_MAPBOT03,
    MENUSPRITE_WILDSTYLE,
    MENUSPRITE_FLASH,
    MENUSPRITE_KCHAT,
    MENUSPRITE_FEVER,
    MENUSPRITE_VROCK,
    MENUSPRITE_VCPR,
    MENUSPRITE_ESPANTOSO,
    MENUSPRITE_EMOTION,
    MENUSPRITE_WAVE,
    MENUSPRITE_MP3,
    MENUSPRITE_DOWNOFF,
    MENUSPRITE_DOWNON,
    MENUSPRITE_UPOFF,
    MENUSPRITE_UPON,
};

struct PLUGIN_API CMenuScreen {
    char m_ScreenName[8];
    unsigned char m_nPreviousPage;
    unsigned char m_nParentEntry;

    struct CMenuEntry {
        unsigned short m_Action;
        char m_EntryName[8];
        unsigned char m_nSaveSlot;
        unsigned char m_nTargetMenu;
        unsigned short m_nX;
        unsigned short m_nY;
        unsigned short m_nAlign;
    } m_aEntries[12];
};

class CMenuManager {
public:
    char m_nStatsScrollUp;
    char field_1[3];
    float m_fStatsScrollSpeed;
    char field_8;
    bool m_bVibration;
    bool m_bHudOn;
    char field_B;
    int m_nRadarMode;
    char field_10;
    bool m_bShutdownFrontEndRequested;
    bool m_bStartupFrontEndRequested;
    char field_13;
    int field_14;
    int m_nBrightness;
    float m_fDrawDistance;
    bool m_bSubtitles;
    bool m_bMapLegend;
    bool m_bWidescreen;
    char m_bTrailsOn;
    char field_20;
    bool m_bFrameLimiter;
    char m_nAudioHardware;
    char m_nAudio3DProviderIndex;
    char field_28;
    char m_nSfxVolume;
    char m_nMusicVolume;
    char m_nRadioStation;
    char field_2C;
    char field_2D[3];
    int m_nCurrentOption;
    bool m_bQuitGame;
    bool m_bDrawRadarOrMap;
    char field_36;
    bool m_bStreamingDone;
    bool m_bMenuActive;
    bool m_bDemoQuit;
    char field_3A;
    bool m_bIsSaveDone;
    bool m_bLoadingData;
    char field_3D[3];
    float m_fMapZoom;
    float m_fMapBaseX;
    float m_fMapBaseY;
    int m_nLanguage;
    int field_50;
    int field_54;
    bool m_bLanguageLoaded;
    bool m_bAllowNastyGame;
    bool m_bMp3BoostVolume;
    char m_nControlMethod;
    int m_nAppliedResolution;
    int m_nResolution;
    int m_nMouseTempPosX;
    int m_nMouseTempPosY;
    bool m_bGameStarted;
    char m_nPreviousAudioIndex;
    char m_bFrontEnd_ReloadObrTxtGxt;
    char field_6F;
    int* pEditString;
    char field_74[4];
    int* pControlEdit;
    bool m_bOnlySaveMenu;
    char field_7D[3];
    int field_80;
    CSprite2d m_apMenuSprites[26];
    int m_bSpritesLoaded;
    int m_nRadioIconsLeftPosition;
    int m_nScrollRadioOffset;
    int m_nCurrentMenuScreen;
    int m_nPreviousMenuScreen;
    int m_nCurrentSaveSlot;
    int field_BC;
    int m_nMenuFadeAlpha;
    int m_nOptionHighlightTransitionBlend;
    bool m_bMenuChangeOngoing;
    int m_nMouseButtonJustClicked;
    int m_nJoyButtonJustClicked;
    bool m_bDisplayComboButtonErrMsg;
    bool m_bNoEmptyBinding;
    bool m_bShowEmptyBindingError;
    int m_nHelperTextAlpha;
    bool m_bPressedPgUpOnList;
    bool m_bPressedPgDnOnList;
    bool m_bPressedUpOnList;
    bool m_bPressedDownOnList;
    bool m_bPressedScrollButton;
    char field_129;
    char field_12A;
    char field_12B;
    int m_nMousePosX;
    int m_nMousePosY;
    int m_nMouseOldPosX;
    int m_nMouseOldPosY;
    int m_nHoverOption;
    bool m_bShowMouse;
    int m_nOptionMouseHovering;
    bool m_bStartWaitingForKeyBind;
    bool m_bWaitingForNewKeyBind;
    bool m_bKeyChangeNotProcessed;
    int m_nCurrCntrlAction;
    char field_150;
    char field_151;
    char field_152;
    char field_153;
    int m_nSelectedCtrlColumn;
    bool field_158;
    bool field_159;
    char m_nCurrExLayer;
    char m_PrefsSkinFile[256];
    char m_aSkinName[256];
    char field_35B;
    int m_nHelperTextMsgId;
    CPlayerSkinData m_pSkinListHead;
    CPlayerSkinData* m_pSelectedSkin;
    int m_nFirstVisibleRowOnList;
    float m_nScrollbarTopMargin;
    int m_nTotalListRow;
    int m_nSkinsTotal;
    int m_nSelectedListRow;
    bool m_bSkinsEnumerated;

public:
    void MessageScreen(const char* pText, bool bFullscreen);
    int FadeIn(int alpha);
    bool CheckHover(int x1, int x2, int y1, int y2);
};


VALIDATE_SIZE(CMenuManager, 0x684);

extern CMenuManager &FrontEndMenuManager;
extern unsigned int MAX_MENU_PAGES; // default 35
extern CMenuScreen *gMenuPages; // tMenuPage gMenuPages[MAX_MENU_PAGES]
