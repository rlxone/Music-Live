
/*
			

					````````````````````````````````````````````````````````````````````````````````
					`¶¶```¶¶`¶¶``¶¶```¶¶¶¶```¶¶¶¶¶¶```¶¶¶¶```````````¶¶``````¶¶¶¶¶¶``¶¶``¶¶``¶¶¶¶¶¶`
					`¶¶¶`¶¶¶`¶¶``¶¶``¶¶````````¶¶````¶¶``¶¶``````````¶¶````````¶¶````¶¶``¶¶``¶¶`````
					`¶¶`¶`¶¶`¶¶``¶¶```¶¶¶¶`````¶¶````¶¶``````````````¶¶````````¶¶````¶¶``¶¶``¶¶¶¶```
					`¶¶```¶¶`¶¶``¶¶``````¶¶````¶¶````¶¶``¶¶``````````¶¶````````¶¶`````¶¶¶¶```¶¶`````
					`¶¶```¶¶``¶¶¶¶````¶¶¶¶```¶¶¶¶¶¶```¶¶¶¶```````````¶¶¶¶¶¶``¶¶¶¶¶¶````¶¶````¶¶¶¶¶``
					````````````````````````````````````````````````````````````````````````````````

									--------------------------------------------------
									<<	PETER GRIFFIN IS WATCHING YOU BRAINFU**ER!	>>
									--------------------------------------------------

					---------------------------------------:+=%%%=+*------------------------------
					---------------------------------+@#@@@@@@@@@@@@@####+------------------------
					-----------------------------*@#@@@@@@@@@@@@@@@@@@@@####%:--------------------
					---------------------------=#@####@#####@@@@@@@@@@@@@@@####%------------------
					--------------------------%**@=+*:::::::::*+%##@@##@@@@@######*---------------
					-------------------------==------*@*::::::::*===+**+=::::*#@###@--------------
					------------------------@:---------%+::::*@*------:%+::::@@@@@#@#:------------
					------------------------%----=#+---:@**+@%----------:@::*#####+*%#*-----------
					-------------------:%@+:@:---:%@%%@#@*::=*----*#@----@+::@@+::+%*@#:----------
					-----------------+%::::::@*-@*::::::::::*@----------:@::::::::::%+*@----------
					---------------+%::::::::::%+:::::::::::::@*-------:@::::::::::::***@---------
					--------------@*:::::::::::*%:::::::::::::::+@@%%@%:::::::::::::::**=*--------
					-------------@:::::::::::::::@+:::::::::::::::::::::::::::::::::::***@--------
					------------@*:::::::::::@%+*:::*+==+:::::::::::=@*:::::::::::::::***=+-------
					-----------*=:::::::::::::%@+:::::::::::::::::+@=:::::::::::::::::****@-------
					-----------@::::::::::::=@*:::**+=%@@@@@@@@%+*:::::::::::::::::::::***@:------
					----------*%::::::::::::*@*::::::::::::::::::::::::::::::::::::::::***+=------
					----------=+::::::::::::::*@*::::::::::::::::::::::::::::::::::::::****@------
					----------@:::::::::::::::::=+:::::::::::::::::::::::::::::::::::::****@------
					----------@::::::::::::::::::=+::::::::::::::::::::::::::::::::::::****@:-----
					----------@::::::::::::::::::*#::::::::::::::::::::::::::::::::::::****%:-----
					----------@:::::::::::::::+@+::::::::::::::::::::::::::::::::::::::****%*-----
					---------:@::::::::::::::@:::::::::::::::::@%::::::::::::::::::::::****=+-----
					---------:@:::::::::::::+=:::::::::::::::::::@:::::::::::::::::::::****==-----
					----------@::::::::::::::@:::::::::::::::::::%+::::::::::::::::::::****+=-----
					----------@:::::::::::::::=@*::::*@%::::::::*@:::::::::::::::::::::****==-----
					----------@:::::::::::::::::::**::::=@%+*+%@*::::::::::::::::::::::****=+-----
					----------@*:::::::::::::::::::::::::::::::::::::::::::::::::::::::****%*-----
					----------=+::::::::::::::::::::::::::::::::::::::::::::::::::::::****=@*%----
					----------==::::::::::::::::::::::::::::::::::::::::::::::::::::::**+@:--@----
					---------+=@::::::::::::::::::::::::::::::::::::::::::::::::::::::+@:---@=@*--
					---------%:-@*::::::::::::::::::::::::::::::::::::::::::::::::::@=----+%----*@
					--------:@@--=%::::::::::::::::::::::::::::::::::::::::::::::=@:-----@:-------
					------+%:--@---=%:::::::::::::::::::::::::::::::::::::::::=@*------%+---------
					---:@*------@:---*@*::::::::::::::::::::::::::::::::::+@=--------@+-----------
					-=%----------==-----%%:::::::::::::::::::::::::::*=@=---------:@:-------------
					--------------:@------:@+:::::::::::::::::::*=@=:-----------%=----------------
					----------------+=-------+@*::::::::::*=@%*-------------:%=-------------------
					------++----------@:----:=%@#*::::%%*----------------*@=----------------------
					------%:-----------+%-:@-----+%*@+:-:+@:---------:=@*-------------------------
					-----:=--------------*+-----#%%:-------++----+@=:-----------------------------
					-----@-----------------------%:--------+++@=----------------------------------
					---*%-----------------------+*---------*--------------------------------------
										
									
			-----|  VERSION:  1.00
			-----|	RELEASE DATE: 15.12.2014
			
			-----|  LIBRARIES:
			        -------|  BASS Project [Copyright (c) 1999-2013 Un4seen Developments Ltd.] [for non-commercial use] [v 2.4.10]
					-------|  LIBXML2 Project [Copyright (c) Daniel Veillard] [under MIT Licence] [v 2.7.8]
					-------|  id3v2lib Project [Copyright (c) 2013 Lorenzo Ruiz] [under MIT Licence] [v 1.0] [Rewrited for WCHAR type by reflex] -> deprecated in C++ future release
*/

/*
	WORK:

	исправить скролл в MLListView
	- ID3_V2 tags (C++)
	графический эквалайзер по частоте
	+ таскбар
	+ время песни
	+ minimizepathname
	повтор / в произвольном порядке
	свой класс для listview
	+ добавить создание папки для thumbnail
	перейти к текущей песне
	+ статус бар
	запуск программы только один раз
	+ таймер для строк > RECT
	уведомление о проигрываемой песне
	стек для кнопки назад при рандомном воспроизведении

	ПЛАНЫ (не в порядке приоритета):
	1. Переписать на C++ 
	2. Полноценные настройки
	   2.1 Горячие клавиши
	   ...
	3. Апдейпер программы
	4. Оценки / количество проигрываний / Рейтинг
	5. Интеграция с explorer.exe
	6. Графический эквалайзер
	7. Эквалайзер
	8. Инсталлятор
	9. Более углубленная интеграция с Last.fm

	СЕЙЧАС

	МЕНЮ
	ИКОНКИ ДЛЯ МЕНЮ
	НАРИСОВАТЬ ПОДСКАЗКИ
	ИКОНКИ ДЛЯ КНОПОК
	ОТКРЫТИЕ ПЛЕЙЛИСТОВ ИЗ ФАЙЛА

*/

/*------------------------------*/
#include "stdafx.h"
#include "Buttons.h"
#include "Labels.h"
#include "Thread.h"
#include "XML_Parsing.h"
#include "Download.h"
#include "Panels.h"
#include "Image.h"
#include "Music.h"
#include "MODULES\bass\bass.h"
#include "TaskBar.h"
#include "Trackbar.h"
#include "ScrollBar.h"
#include "MLUtils.h"
#include "MLMessages.h"
#include "ML.h"
/*------------------------------*/

/*------------------------------*/

/* MAIN PROCS */
ATOM				MLRegisterClass(HINSTANCE hInstance);
BOOL				MLInitInstance(HINSTANCE, int);
LRESULT CALLBACK	MLWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	MLWndMouseProc(int, WPARAM, LPARAM);
void				TaskBarButtonsClickProc(HWND, UINT, WPARAM, LPARAM);
void				MenuButtonsClickProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogCreatePlayListProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogChoisePlayListProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogEditTagsProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DialogAboutProc(HWND, UINT, WPARAM, LPARAM);

/* -- ADDITIONAL PROCS */

/* THREAD PROCS */
int					TimerThreadProc(LPVOID);
int					SongsThreadProc(LPVOID);
int					SearchFolderMusicThreadProc(LPVOID);
int					SearchFileMusicThreadProc(LPVOID);
int					SaveFilePlaylistThreadProc(LPVOID);
int					OpenFilePlayListThreadProc(LPVOID);
int					HideMusicPageThreadProc(LPVOID);
int					ArtistsThreadProc(LPVOID);
int					SongsThreadProc(LPVOID);
int					MusicThreadProc(LPVOID);

/* MUSIC PLAYER PROCS */
int					mpPlayButtonProc(void);
int					mpRepeatYesButtonProc(void);
int					mpRepeatNoButtonProc(void);
int					mpRandomYesButtonProc(void);
int					mpRandomNoButtonProc(void);
int					mpPrevButtonProc(void);
int					mpPauseButtonProc(void);
int					mpNextButtonProc(void);

/* MENU PROCS */
int					menuSaveButtonProc(void);
int					menuOpenPlaylistProc(void);
int					menuCreateButtonProc(void);
int					menuChoiseButtonProc(void);
int					menuBackButtonProc(void);
int					menuAddFolderButtonProc(void);
int					menuAddFileButtonProc(void);
int					menuAddButtonProc(void);

int					MusicTrackBarProc(int);
int					VolumeTrackBarProc(int);
void				ChangePlaylist(int);
void				MenuSetActiveTab(int);
int					SearchMusicProc(int);

int					ArtistsButtonProc(void);
int					ExitButtonProc(void);
int					MinimizeButtonProc(void);
int					SongsButtonProc(void);
int					MusicButtonProc(void);
int					TopSongsPanelFrameProc(void);
int					TopArtistsPanelFrameProc(void);
int					TopSongsLeftProc(void);
int					TopSongsRightProc(void);
int					TopArtistsLeftProc(void);
int					TopArtistsRightProc(void);
int					menuButtonProc(void);
void				HideMusicListView(void);
void				ShowMusicListView(void);
int					volumeYesButtonProc(void);
int					volumeNoButtonProc(void);
int					MusicScrollBarProc(int);
int					iconButtonProc(void);
void				HideMenuButtons(void);
int CALLBACK		BrowseFolderCallback(HWND, UINT, LPARAM, LPARAM);

/*------------------------------*/

/*------------------------------*/

/*WINDOW INFORMATION STRUCTURE*/
tWindowInfo wndInfo;
/*------------------------------*/

/*MUSIC INFORMATION STRUCTURE*/
tMusicInfo musicInfo;
/*------------------------------*/

/*PLAYLISTS*/
ptPlayList playlists;
/*------------------------------*/

/*CUSTOM BUTTONS*/
ptButton singersButton, exitButton, minimizeButton, songsButton, musicButton, panelsFrameButton,
panelsRightButton, panelsLeftButton, lvNumberButton, lvNameButton, lvBitrateButton, lvLengthButton,
mpPlayButton, mpPauseButton, mpPrevButton, mpNextButton, menuButton, mpRepeatYesButton, mpRepeatNoButton,
mpRandomYesButton, mpRandomNoButton, iconButton, volumeYesButton, volumeNoButton, menuCreateButton, menuAddButton, menuSaveButton,
menuChoiseButton, menuRenameButton, menuDeleteButton, menuBackButton, menuAddFolderButton, menuAddFileButton,
menuOpenPlaylistButton;
/*------------------------------*/

/*CUSTOM LABELS*/
ptLabel titleLabel, mpSongLabel, mpSingerLabel, mpBitrateLabel, mpLengthLabel, playlistLabel, countLabel, timeLabel,
statusLabel, menuLabel, quoteMusicLabel, quoteLastFMLabel;
/*------------------------------*/

/*CUSTOM IMAGES*/
ptImage MLImage, lvShadow, mpPanel, mpPlayTrackbar, mpPlayTrackbarBkg, thumbImage, bkgImage, mpVolumeTrackbarBkg,
quoteMusicImage, quoteLastFMImage;
/*------------------------------*/

/*CUSTOM TRACKBARS*/
ptTrackBar musicTrackBar, volumeTrackBar;
/*------------------------------*/

/*CUSTOM SCROLLBARS*/
ptScrollBar musicScrollBar;
/*------------------------------*/

/*CUSTOM TAB BUTTONS*/
tMenuButton tabButtons[MENU_TABS_COUNT];
/*------------------------------*/

/*TASKBAR INTERFACE POINTER*/
ITaskbarList3 *iTaskBar;
/*------------------------------*/

/*TASKBAR BUTTONS*/
THUMBBUTTON tbButtons[4];
/*------------------------------*/

BOOL InitializeControls(HWND hWnd)
{
	bkgImage = ImageCreate(hWnd, wndInfo.hInst, BMP_FRAME_QUOTE, 0, 0, 756, 500);

	tabButtons[0].menuTab = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_MUSIC), COLOR_PINK, TEXT("Segoe UI"),
		24, FW_NORMAL, 13, 51, 100, 35, 0, 5,
		BMP_MUSIC_DEFAULT, BMP_MUSIC_MOVE, BMP_MUSIC_CLICK, (ButtonProc)MusicButtonProc);

	if (!tabButtons[0].menuTab) {
		return FALSE;
	}

	tabButtons[0].menuActive = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_MUSIC), COLOR_WHITE, TEXT("Segoe UI"),
		24, FW_NORMAL, 13, 51, 100, 35, 0, 5,
		BMP_MUSIC_ACTIVE, BMP_MUSIC_ACTIVE, BMP_MUSIC_ACTIVE, (ButtonProc)NULL);

	if (!tabButtons[0].menuActive) {
		return FALSE;
	}

	tabButtons[1].menuTab = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_SONGS), COLOR_PINK, TEXT("Segoe UI"),
		24, FW_NORMAL, 469, 51, 137, 35, 0, 5,
		BMP_SONGS_DEFAULT, BMP_SONGS_MOVE, BMP_SONGS_CLICK, (ButtonProc)SongsButtonProc);

	if (!tabButtons[1].menuTab) {
		return FALSE;
	}

	tabButtons[1].menuActive = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_SONGS), COLOR_WHITE, TEXT("Segoe UI"),
		24, FW_NORMAL, 469, 51, 137, 35, 0, 5,
		BMP_SONGS_ACTIVE, BMP_SONGS_ACTIVE, BMP_SONGS_ACTIVE, (ButtonProc)NULL);

	if (!tabButtons[1].menuActive) {
		return FALSE;
	}

	tabButtons[2].menuTab = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_SINGERS), COLOR_PINK, TEXT("Segoe UI"),
		24, FW_NORMAL, 606, 51, 137, 35, 0, 5,
		BMP_SONGS_DEFAULT, BMP_SONGS_MOVE, BMP_SONGS_CLICK, (ButtonProc)ArtistsButtonProc);

	if (!tabButtons[2].menuTab) {
		return FALSE;
	}

	tabButtons[2].menuActive = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(CAPTION_BTN_SINGERS), COLOR_WHITE, TEXT("Segoe UI"),
		24, FW_NORMAL, 606, 51, 137, 35, 0, 5,
		BMP_SONGS_ACTIVE, BMP_SONGS_ACTIVE, BMP_SONGS_ACTIVE, (ButtonProc)NULL);

	if (!tabButtons[2].menuActive) {
		return FALSE;
	}

	exitButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_PINK, TEXT("Segoe UI"),
		0, FW_NORMAL, 731, 9, 20, 20, 0, 0,
		BMP_EXIT_DEFAULT, BMP_EXIT_MOVE, BMP_EXIT_CLICK, (ButtonProc)ExitButtonProc);

	if (!exitButton) {
		return FALSE;
	}

	minimizeButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_PINK, TEXT("Segoe UI"),
		0, FW_NORMAL, 711, 9, 20, 20, 0, 0,
		BMP_MINIMIZE_DEFAULT, BMP_MINIMIZE_MOVE, BMP_MINIMIZE_CLICK, (ButtonProc)MinimizeButtonProc);

	if (!exitButton) {
		return FALSE;
	}

	panelsFrameButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 65, 108, 304, 36, 2, 0,
		BMP_PANEL_FRAME_DEFAULT, BMP_PANEL_FRAME_MOVE, BMP_PANEL_FRAME_CLICK,
		(ButtonProc)TopSongsPanelFrameProc);

	if (!panelsFrameButton) {
		return FALSE;
	}

	panelsLeftButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 606, 108, 36, 36, 2, 0,
		BML_SLIDE_LEFT_DEFAULT, BML_SLIDE_LEFT_MOVE, BML_SLIDE_LEFT_CLICK,
		(ButtonProc)NULL);

	if (!panelsLeftButton) {
		return FALSE;
	}

	panelsRightButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 654, 108, 36, 36, 2, 0,
		BML_SLIDE_RIGHT_DEFAULT, BML_SLIDE_RIGHT_MOVE, BML_SLIDE_RIGHT_CLICK,
		(ButtonProc)NULL);

	if (!panelsRightButton) {
		return FALSE;
	}

	iconButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 3, 1, 40, 35, 2, 0,
		BMP_ICON_DEFAULT, BMP_ICON_MOVE, BMP_ICON_CLICK,
		(ButtonProc)iconButtonProc);

	if (!iconButton) {
		return FALSE;
	}

	menuCreateButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("СОЗДАТЬ ПЛЕЙЛИСТ"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 255, 220, 145, 100, 2, 82,
		BMP_MENU_CREATE_DEFAULT, BMP_MENU_CREATE_MOVE, BMP_MENU_CREATE_CLICK,
		(ButtonProc)menuCreateButtonProc);

	if (!menuCreateButton) {
		return FALSE;
	}

	menuAddButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ДОБАВИТЬ ..."), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 411, 220, 145, 100, 2, 82,
		BMP_MENU_ADD_DEFAULT, BMP_MENU_ADD_MOVE, BMP_MENU_ADD_CLICK,
		(ButtonProc)menuAddButtonProc);

	if (!menuAddButton) {
		return FALSE;
	}

	menuOpenPlaylistButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ОТКРЫТЬ ПЛЕЙЛИСТ"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 568, 220, 145, 100, 1, 82,
		BMP_MENU_OPEN_DEFAULT, BMP_MENU_OPEN_MOVE, BMP_MENU_OPEN_CLICK,
		(ButtonProc)menuOpenPlaylistProc);

	if (!menuOpenPlaylistButton) {
		return FALSE;
	}

	menuSaveButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("СОХРАНИТЬ ПЛЕЙЛИСТ"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 254, 337, 145, 100, 1, 82,
		BMP_MENU_SAVE_DEFAULT, BMP_MENU_SAVE_MOVE, BMP_MENU_SAVE_CLICK,
		(ButtonProc)menuSaveButtonProc);

	if (!menuSaveButton) {
		return FALSE;
	}

	menuChoiseButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ВЫБРАТЬ ПЛЕЙЛИСТ"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 411, 337, 145, 100, 2, 82,
		BMP_MENU_CHOISE_DEFAULT, BMP_MENU_CHOISE_MOVE, BMP_MENU_CHOISE_CLICK,
		(ButtonProc)menuChoiseButtonProc);

	if (!menuChoiseButton) {
		return FALSE;
	}

	menuAddFolderButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ПАПКА"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 411, 220, 72, 100, 2, 82,
		BMP_MENU_ADD_FOLDER_DEFAULT, BMP_MENU_ADD_FOLDER_MOVE, BMP_MENU_ADD_FOLDER_CLICK,
		(ButtonProc)menuAddFolderButtonProc);

	if (!menuAddFolderButton) {
		return FALSE;
	}

	menuAddFileButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ФАЙЛ"), COLOR_WHITE, TEXT("Segoe UI"),
		16, FW_NORMAL, 483, 220, 73, 100, 2, 82,
		BMP_MENU_ADD_FILE_DEFAULT, BMP_MENU_ADD_FILE_MOVE, BMP_MENU_ADD_FILE_CLICK,
		(ButtonProc)menuAddFileButtonProc);

	if (!menuAddFileButton) {
		return FALSE;
	}

	mpPanel = ImageCreate(hWnd, wndInfo.hInst, BMP_MUSIC_PANEL, 23, 103, 208, 377);
	thumbImage = ImageCreate(hWnd, wndInfo.hInst, BMP_NO_COVER_THUMB, 67, 147, 120, 120);
	MLImage = ImageCreate(hWnd, wndInfo.hInst, BMP_ML_LOGO, 246, 126, 256, 256);
	lvShadow = ImageCreate(hWnd, wndInfo.hInst, BMP_LISTVIEW_SHADOW, 239, 153, 489, 327);
	mpPlayTrackbarBkg = ImageCreate(hWnd, wndInfo.hInst, BMP_PLAY_TRACKBAR_BKG, 28, 385, 198, 35);
	mpVolumeTrackbarBkg = ImageCreate(hWnd, wndInfo.hInst, BMP_VOLUME_TRACKBAR_BKG, 67, 111, 120, 25);

	mpPlayButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 102, 412, 50, 50, 2, 0,
		BMP_PLAY_DEFAULT, BMP_PLAY_MOVE, BMP_PLAY_CLICK,
		(ButtonProc)mpPlayButtonProc);

	if (!mpPlayButton) {
		return FALSE;
	}

	mpPauseButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 102, 412, 50, 50, 2, 0,
		BMP_PAUSE_DEFAULT, BMP_PAUSE_MOVE, BMP_PAUSE_CLICK,
		(ButtonProc)mpPauseButtonProc);

	if (!mpPauseButton) {
		return FALSE;
	}

	mpPrevButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 55, 415, 44, 44, 2, 0,
		BMP_PREV_DEFAULT, BMP_PREV_MOVE, BMP_PREV_CLICK,
		(ButtonProc)mpPrevButtonProc);

	if (!mpPrevButton) {
		return FALSE;
	}

	mpNextButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 155, 415, 44, 44, 2, 0,
		BMP_NEXT_DEFAULT, BMP_NEXT_MOVE, BMP_NEXT_CLICK,
		(ButtonProc)mpNextButtonProc);

	if (!mpNextButton) {
		return FALSE;
	}

	mpRepeatNoButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 196, 111, 27, 23, 2, 0,
		BMP_REPEAT_NO_DEFAULT, BMP_REPEAT_NO_MOVE, BMP_REPEAT_NO_CLICK,
		(ButtonProc)mpRepeatNoButtonProc);

	if (!mpRepeatNoButton) {
		return FALSE;
	}

	mpRepeatYesButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 196, 111, 27, 23, 2, 0,
		BMP_REPEAT_YES_DEFAULT, BMP_REPEAT_YES_MOVE, BMP_REPEAT_YES_CLICK,
		(ButtonProc)mpRepeatYesButtonProc);

	if (!mpRepeatYesButton) {
		return FALSE;
	}

	mpRandomNoButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 197, 133, 25, 23, 2, 0,
		BMP_RANDOM_NO_DEFAULT, BMP_RANDOM_NO_MOVE, BMP_RANDOM_NO_CLICK,
		(ButtonProc)mpRandomNoButtonProc);

	if (!mpRandomNoButton) {
		return FALSE;
	}

	mpRandomYesButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 197, 133, 25, 23, 2, 0,
		BMP_RANDOM_YES_DEFAULT, BMP_RANDOM_YES_MOVE, BMP_RANDOM_YES_CLICK,
		(ButtonProc)mpRandomYesButtonProc);

	if (!mpRandomYesButton) {
		return FALSE;
	}

	volumeNoButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 31, 111, 25, 25, 2, 0,
		BMP_VOLUME_NO_DEFAULT, BMP_VOLUME_NO_MOVE, BMP_VOLUME_NO_CLICK,
		(ButtonProc)volumeNoButtonProc);

	if (!volumeNoButton) {
		return FALSE;
	}

	volumeYesButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 31, 111, 25, 25, 2, 0,
		BMP_VOLUME_YES_DEFAULT, BMP_VOLUME_YES_MOVE, BMP_VOLUME_YES_CLICK,
		(ButtonProc)volumeYesButtonProc);

	if (!volumeYesButton) {
		return FALSE;
	}

	menuButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 243, 108, 45, 38, 2, 0,
		BMP_MENU_DEFAULT, BMP_MENU_MOVE, BMP_MENU_CLICK,
		(ButtonProc)menuButtonProc);

	if (!menuButton) {
		return FALSE;
	}

	menuBackButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT(""), COLOR_WHITE, TEXT("Segoe UI"),
		28, FW_NORMAL, 243, 108, 45, 38, 2, 0,
		BMP_MENU_BACK_DEFAULT, BMP_MENU_BACK_MOVE, BMP_MENU_BACK_CLICK,
		(ButtonProc)menuBackButtonProc);

	if (!menuBackButton) {
		return FALSE;
	}

	lvNumberButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("№"), COLOR_GRAY, TEXT("Segoe UI"),
		16, FW_NORMAL, 244, 158, 40, 25, 0, 5,
		BMP_LISTVIEW_NUMBER_DEFAULT, BMP_LISTVIEW_NUMBER_MOVE, BMP_LISTVIEW_NUMBER_CLICK, (ButtonProc)NULL);

	if (!lvNumberButton) {
		return FALSE;
	}

	lvNameButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("НАЗВАНИЕ"), COLOR_GRAY, TEXT("Segoe UI"),
		16, FW_NORMAL, 284, 158, 296, 25, 0, 5,
		BMP_LISTVIEW_NAME_DEFAULT, BMP_LISTVIEW_NAME_MOVE, BMP_LISTVIEW_NAME_CLICK, (ButtonProc)NULL);

	if (!lvNameButton) {
		return FALSE;
	}

	lvBitrateButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("БИТРЕЙТ"), COLOR_GRAY, TEXT("Segoe UI"),
		16, FW_NORMAL, 580, 158, 74, 25, 0, 5,
		BMP_LISTVIEW_BITRATE_DEFAULT, BMP_LISTVIEW_BITRATE_MOVE, BMP_LISTVIEW_BITRATE_CLICK, (ButtonProc)NULL);

	if (!lvBitrateButton) {
		return FALSE;
	}

	lvLengthButton = ButtonCreate(hWnd, wndInfo.hInst,
		TEXT("ДЛИНА"), COLOR_GRAY, TEXT("Segoe UI"),
		16, FW_NORMAL, 654, 158, 69, 25, 0, 5,
		BMP_LISTVIEW_LENGTH_DEFAULT, BMP_LISTVIEW_LENGTH_MOVE, BMP_LISTVIEW_LENGTH_CLICK, (ButtonProc)NULL);

	if (!lvLengthButton) {
		return FALSE;
	}

	mpLengthLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("....."), COLOR_WHITE, COLOR_TRANSPARENT, TEXT("Segoe UI"),
		14, DT_CENTER, FW_BOLD, 82, 358, 89, 14, BMP_FRAME_MUSIC);

	if (!mpLengthLabel) {
		return FALSE;
	}

	timeLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("00:00"), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI Semibold"),
		22, DT_CENTER, FW_NORMAL, 624, 114, 99, 22, BMP_FRAME_MUSIC);

	if (!timeLabel) {
		return FALSE;
	}

	countLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("0"), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI Semibold"),
		22, DT_CENTER, FW_NORMAL, 526, 114, 61, 22, BMP_FRAME_MUSIC);

	if (!countLabel) {
		return FALSE;
	}

	mpSingerLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("....."), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI"),
		26, DT_CENTER, FW_BOLD, 38, 281, 178, 26, BMP_FRAME_MUSIC);

	if (!mpSingerLabel) {
		return FALSE;
	}

	mpSongLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("....."), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI"),
		18, DT_CENTER, FW_BOLD, 38, 308, 178, 18, BMP_FRAME_MUSIC);

	if (!mpSongLabel) {
		return FALSE;
	}

	mpBitrateLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("....."), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI"),
		14, DT_CENTER, FW_BOLD, 97, 340, 60, 14, BMP_FRAME_MUSIC);

	if (!mpBitrateLabel) {
		return FALSE;
	}

	titleLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT(CAPTION_LBL_PROGRAM_NAME), COLOR_PINK, COLOR_TRANSPARENT, TEXT(FONT_NAME),
		24, DT_LEFT, FW_NORMAL, 45, 7, CLIENT_WIDTH - 20, 25, BMP_FRAME);

	if (!titleLabel) {
		return FALSE;
	}

	statusLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT(MUSIC_LIVE_PROGRAM_VERSION), COLOR_WHITE, COLOR_PINK, TEXT("Trebuchet MS"),
		16, DT_RIGHT, FW_BOLD, 648, 478, 102, 16, BMP_FRAME);

	if (!statusLabel) {
		return FALSE;
	}

	playlistLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("DEFAULT PLAYLIST"), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI Semibold"),
		22, DT_CENTER, FW_NORMAL, 321, 114, 168, 22, BMP_FRAME_MUSIC);

	if (!playlistLabel) {
		return FALSE;
	}

	menuLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("МЕНЮ"), COLOR_WHITE, TRANSPARENT, TEXT("Segoe UI Semibold"),
		22, DT_CENTER, FW_NORMAL, 283, 173, 114, 22, BMP_FRAME_MUSIC);

	if (!menuLabel) {
		return FALSE;
	}

	quoteMusicLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("   Создавайте плейлисты,\n слушайте любимую музыку."), RGB(89, 89, 89), TRANSPARENT, TEXT("Segoe Script"),
		20, DT_CENTER, FW_BOLD, 37, 212, 210, 55, BMP_FRAME_QUOTE);

	if (!quoteMusicLabel) {
		return FALSE;
	}

	quoteLastFMLabel = LabelCreate(hWnd, wndInfo.hInst, TEXT("      Получайте последние чарты\n         лучших композиций и\n               исполнителей."), RGB(89, 89, 89), TRANSPARENT, TEXT("Segoe Script"),
		20, DT_CENTER, FW_BOLD, 467, 174, 265, 80, BMP_FRAME_QUOTE);

	if (!quoteLastFMLabel) {
		return FALSE;
	}

	musicTrackBar = TrackBarCreate(hWnd, wndInfo.hInst, COLOR_LISTVIEW_BKG, COLOR_WHITE, RGB(119, 119, 119),
		49, 395, 156, 5, 5, (TrackBarProc)MusicTrackBarProc);

	if (!musicTrackBar) {
		return FALSE;
	}

	volumeTrackBar = TrackBarCreate(hWnd, wndInfo.hInst, COLOR_LISTVIEW_BKG, COLOR_WHITE, RGB(119, 119, 119),
		77, 121, 100, 5, 5, (TrackBarProc)VolumeTrackBarProc);

	if (!volumeTrackBar) {
		return FALSE;
	}

	musicScrollBar = ScrollBarCreate(hWnd, wndInfo.hInst, COLOR_LISTVIEW_BKG, COLOR_LISTVIEW_BKG, RGB(119, 119, 119), 709, 185, 10, 277, 40, MusicScrollBarProc);

	wndInfo.wndMouseHook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)MLWndMouseProc, NULL, GetCurrentThreadId());

	ButtonHide(panelsFrameButton);
	ButtonHide(panelsLeftButton);
	ButtonHide(panelsRightButton);
	ButtonHide(mpPlayButton);
	ButtonHide(mpPauseButton);
	ButtonHide(mpPrevButton);
	ButtonHide(mpNextButton);
	ButtonHide(menuButton);
	ButtonHide(mpRepeatNoButton);
	ButtonHide(mpRepeatYesButton);
	ButtonHide(mpRandomNoButton);
	ButtonHide(mpRandomYesButton);
	ButtonHide(volumeNoButton);
	ButtonHide(volumeYesButton);
	ButtonHide(menuButton);
	ButtonHide(menuBackButton);
	ButtonHide(menuCreateButton);
	ButtonHide(menuAddButton);
	ButtonHide(menuOpenPlaylistButton);
	ButtonHide(menuSaveButton);
	ButtonHide(menuChoiseButton);
	ButtonHide(menuAddFolderButton);
	ButtonHide(menuAddFileButton);
	ButtonHide(lvNumberButton);
	ButtonHide(lvNameButton);
	ButtonHide(lvBitrateButton);
	ButtonHide(lvLengthButton);
	MenuSetActiveTab(MENU_TAB_NOACTIVE);
	LabelHide(menuLabel);
	ImageHide(MLImage);
	ImageHide(lvShadow);
	ImageHide(mpPanel);
	ImageHide(mpPlayTrackbarBkg);
	ImageHide(mpVolumeTrackbarBkg);
	ImageHide(thumbImage);
	LabelHide(mpLengthLabel);
	LabelHide(timeLabel);
	LabelHide(countLabel);
	LabelHide(mpSingerLabel);
	LabelHide(mpSongLabel);
	LabelHide(mpBitrateLabel);
	LabelHide(playlistLabel);

	TrackbarHide(musicTrackBar);
	TrackbarHide(volumeTrackBar);

	ScrollBarHide(musicScrollBar);

	return TRUE;
}

BOOL InitializeCommonControls(void)
{
	INITCOMMONCONTROLSEX icex;

	icex.dwICC = ICC_LISTVIEW_CLASSES;
	return InitCommonControlsEx(&icex);
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;

	MLRegisterClass(hInstance);

	if (!MLInitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

ATOM MLRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	_tcscpy_s(wndInfo.szWindowClass, sizeof(wndInfo.szWindowClass), MUSIC_LIVE_CLASS_NAME);
	_tcscpy_s(wndInfo.szTitle, sizeof(wndInfo.szTitle), MUSIC_LIVE_PROGRAM_NAME);

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_DROPSHADOW;
	wcex.lpfnWndProc = MLWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ML));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(COLOR_PINK);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = wndInfo.szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

LRESULT CALLBACK MLWndMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION) {
		if (wParam == WM_MOUSEMOVE) {
			LPMOUSEHOOKSTRUCT ptlParam = (LPMOUSEHOOKSTRUCT)lParam;
			UpdatePanels(wndInfo.hWnd, ptlParam->pt);
			ButtonsUpdate(wndInfo.hWnd, ptlParam->pt);
			TrackbarsUpdate(wndInfo.hWnd, ptlParam->pt);
			ScrollBarsUpdate(wndInfo.hWnd, ptlParam->pt);
			return CallNextHookEx(wndInfo.wndMouseHook, nCode, wParam, lParam);
		}
		if (wParam == WM_LBUTTONUP) {
			LPMOUSEHOOKSTRUCT ptlParam = (LPMOUSEHOOKSTRUCT)lParam;
			TrackbarsUpdateClick(wndInfo.hWnd, ptlParam->pt);
			ScrollBarsUpdateClick(wndInfo.hWnd, ptlParam->pt);
		}
	}

	return CallNextHookEx(wndInfo.wndMouseHook, nCode, wParam, lParam);
}

BOOL MLInitInstance(HINSTANCE hInstance, int nCmdShow)
{
	INITCOMMONCONTROLSEX icex;
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icex);

	wndInfo.hInst = hInstance;

	RECT rect = ClientToCenter(CLIENT_WIDTH, CLIENT_HEIGHT);

	wndInfo.hWnd = CreateWindow(wndInfo.szWindowClass, wndInfo.szTitle, WS_POPUP,
		rect.left, rect.top, CLIENT_WIDTH, CLIENT_HEIGHT, NULL, NULL, hInstance, NULL);

	if (!wndInfo.hWnd) {
		return FALSE;
	}

	ShowWindow(wndInfo.hWnd, nCmdShow);
	UpdateWindow(wndInfo.hWnd);

	return TRUE;
}

void InitializeMusicInfo(void)
{
	musicInfo.ismp = TRUE;
	musicInfo.lpos = -1;
	musicInfo.pcount = 1;
	musicInfo.pcurrent = 1;
	musicInfo.cchannel = 0;
	musicInfo.mtimer = 0;
	musicInfo.isorigthumb = TRUE;
	musicInfo.cchannel_current = 0;
	musicInfo.cchannel_length = -1;
	musicInfo.tpercent = 0;
	musicInfo.vpos = 100;
	strcpy_s(musicInfo.cpname, sizeof(musicInfo.cpname), "DEFAULT PLAYLIST");
	musicInfo.israndom = FALSE;
	musicInfo.isrepeat = FALSE;
	musicInfo.isvolume = FALSE;
	musicInfo.ispnew = FALSE;
	musicInfo.isstart = FALSE;
}

BOOL InitializeMusic(void)
{
	return BASS_Init(-1, 44100, 0, wndInfo.hWnd, NULL);
}

BOOL DeinitializeMusic(void)
{
	return BASS_Free();
}

BOOL InitializeDirectories(void)
{
	if (!CreateRecursiveDirectory(CACHE_XML_FILES_DIR)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_TOP_TRACK_DIR_DOWNLOAD)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_TOP_TRACK_DIR_IMAGES)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_TOP_ARTISTS_DIR_DOWNLOAD)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_TOP_ARTISTS_DIR_IMAGES)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_THUMBNAIL_IMAGES)) {
		return FALSE;
	}
	if (!CreateRecursiveDirectory(CACHE_PLAYLISTS)) {
		return FALSE;
	}
	return TRUE;
}

void InitializeRandomNumbers(void)
{
	srand((unsigned)time(NULL));
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	TCHAR appName[MAX_PATH];

	GetWindowText(hWnd, appName, sizeof(appName));

	if (_tcscmp(appName, MUSIC_LIVE_PROGRAM_NAME)) {
		//SetForegroundWindow(hWnd);
		return FALSE;
	}

	return TRUE;
}

BOOL InitializeMutex()
{
	wndInfo.hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, MUSIC_LIVE_PROGRAM_NAME);

	if (wndInfo.hMutex) {
		EnumWindows(EnumWindowsProc, (LPARAM)NULL);
		return FALSE;
	}
	else {
		wndInfo.hMutex = CreateMutex(NULL, FALSE, MUSIC_LIVE_PROGRAM_NAME);
	}

	return TRUE;
}

BOOL InitializeML(HWND hWnd)
{
	if (!InitializeMutex()) {
		DestroyWindow(hWnd);
	}
	//INITIALIZE COMMON CONTROLS
	if (CoInitialize(0) != S_OK) {
		return FALSE;
	}
	//INITIALIZE SUBDIRRECTORIES
	if (!InitializeDirectories()) {
		return FALSE;
	}
	//INITIALIZE MAIN CONTROLS
	if (!InitializeControls(hWnd)) {
		return FALSE;
	}
	//CREATE DEFAULT PLAYLIST
	if (CreatePlaylist("DEFAULT PLAYLIST", hWnd, wndInfo.hInst) != CP_ALLOK) {
		return FALSE;
	}
	//INITIALIZE MUSIC
	if (!InitializeMusic()) {
		return FALSE;
	}
	//INITIALIZE TASKBAR CLASS
	if (InitializeTaskBarClass(&iTaskBar) != S_OK) {
		return FALSE;
	} else {
		HideMusicListView();
	}
	//INITIALIZE XML PARSER
	xmlInitParser();
	//INITIALIZE MUSIC INFO STRUCTURE
	InitializeMusicInfo();
	//INITIALIZE RANDOM NUMBERS
	InitializeRandomNumbers();
	return TRUE;
}

BOOL DeinitializeML(void)
{
	//FREE BUTTONS MEMORY
	ButtonsFree();
	//FREE PANELS MEMORY
	DeleteTopSongsPanels();
	DeleteTopArtistsPanels();
	//UNHOOK MOUSE HOOK
	if (wndInfo.wndMouseHook) {
		UnhookWindowsHookEx(wndInfo.wndMouseHook);
	} else {
		return FALSE;
	}
	//DEINITIALIZE MUSIC
	if (!DeinitializeMusic()) {
		return FALSE;
	}
	//DEINITIALIZE COMMON CONTROLS
	CoUninitialize();
	//DEINITIALIZE OLE OBJECTS
	OleUninitialize();
	//DEINITIALIZE XML PARSER
	xmlCleanupParser();
	ReleaseMutex(wndInfo.hMutex);

	return TRUE;
}

void TaskBarButtonsClickProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case TASKBAR_BUTTON_PREV:
		mpPrevButtonProc();
		break;
	case TASKBAR_BUTTON_PLAY:
		if (ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED) != musicInfo.lpos) {
			ListView_RedrawItems(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, musicInfo.lpos);
			musicInfo.ismp = FALSE;
			mpPlayButtonProc();
		}
		else {
			musicInfo.ismp ? mpPlayButtonProc() : mpPauseButtonProc();
		}
		SetFocus(playlists[musicInfo.pcurrent - 1].mlListView.listView);
		break;
	case TASKBAR_BUTTON_NEXT:
		mpNextButtonProc();
		break;
	}
}

void MenuButtonsClickProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case MENU_PLAYLISTS_CREATE:
		DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_CREATE_PLAYLIST), wndInfo.hWnd, DialogCreatePlayListProc);
		break;
	case MENU_PLAYLISTS_OPEN:
		menuOpenPlaylistProc();
		break;
	case MENU_PLAYLISTS_SAVE:
		menuSaveButtonProc();
		break;
	case MENU_PLAYLISTS_CHOOSE:
		DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_CHOISE_PLAYLIST), wndInfo.hWnd, DialogChoisePlayListProc);
		break;
	case MENU_PLAYLISTS_OPEN_FILE:
		menuAddFileButtonProc();
		break;
	case MENU_PLAYLISTS_OPEN_FOLDER:
		menuAddFolderButtonProc();
		break;
	case MENU_PLAYLISTS_EDIT_TAGS:
		DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_EDIT_TAGS), wndInfo.hWnd, DialogEditTagsProc);
		break;
	}
}

LRESULT MLWndNotifyProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int lcurrent;

	LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)lParam;
	LPNMHDR lpNMHDR = (LPNMHDR)lParam;
	LPNMLVSCROLL lpNMVScroll = (LPNMLVSCROLL)lParam;
	LPNMLVKEYDOWN lpNMVKeydown = (LPNMLVKEYDOWN)lParam;

	if (lpNMVScroll->hdr.code == LVN_ENDSCROLL) {
		playlists[musicInfo.pcurrent - 1].mlListView.pos += lpNMVScroll->dy;
		if (playlists[musicInfo.pcurrent - 1].mlListView.pos <= 1) {
			playlists[musicInfo.pcurrent - 1].mlListView.pos = 0;
		}
		if (playlists[musicInfo.pcurrent - 1].mlListView.pos > playlists[musicInfo.pcurrent - 1].pcount - LISTVIEW_ONE_PAGE_ITEMS) {
			playlists[musicInfo.pcurrent - 1].mlListView.pos = playlists[musicInfo.pcurrent - 1].pcount - LISTVIEW_ONE_PAGE_ITEMS;
		}
		int spos = (int)(playlists[musicInfo.pcurrent - 1].mlListView.pos * 100.0 / (playlists[musicInfo.pcurrent - 1].pcount - LISTVIEW_ONE_PAGE_ITEMS));
		ScrollBarSetPosition(musicScrollBar, spos);
	}

	if (lpNMVKeydown->hdr.code == LVN_KEYDOWN) {
		switch (lpNMVKeydown->wVKey) {
		case VK_DOWN:
			lcurrent = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);
			if (lcurrent != -1) {
				playlists[musicInfo.pcurrent - 1].mlListView.pos = lcurrent;
				int spos = (int)(playlists[musicInfo.pcurrent - 1].mlListView.pos * 100.0 / (playlists[musicInfo.pcurrent - 1].pcount));
				ScrollBarSetPosition(musicScrollBar, spos);
			}
			break;
		case VK_UP:
			lcurrent = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);
			if (lcurrent != -1) {
				playlists[musicInfo.pcurrent - 1].mlListView.pos = lcurrent;
				int spos = (int)(playlists[musicInfo.pcurrent - 1].mlListView.pos * 100.0 / (playlists[musicInfo.pcurrent - 1].pcount));
				ScrollBarSetPosition(musicScrollBar, spos);
			}
			break;
		}
	}

	if (lpNMHDR->hwndFrom == playlists[musicInfo.pcurrent - 1].mlListView.listView) {
		switch (lpNMHDR->code) {
		case NM_RETURN:
			if (ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED) != musicInfo.lpos) {
				ListView_RedrawItems(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, musicInfo.lpos);
				musicInfo.ismp = FALSE;
				mpPlayButtonProc();
			}
			else {
				musicInfo.ismp ? mpPlayButtonProc() : mpPauseButtonProc();
			}
			break;
		case NM_RCLICK: {
			HMENU hMenu = LoadMenu(wndInfo.hInst, MAKEINTRESOURCE(MENU_PLAYLISTS));
			HMENU hSubMenu = GetSubMenu(hMenu, 0);

			POINT pt;
			GetCursorPos(&pt);

			MENUINFO mi = { 0 };
			mi.cbSize = sizeof(MENUINFO);
			mi.fMask = MIM_BACKGROUND | MIM_APPLYTOSUBMENUS;
			mi.hbrBack = CreateSolidBrush(COLOR_WHITE);
			//SetMenuItemBitmaps(hSubMenu, MENU_PLAYLISTS_CREATE, MF_BYCOMMAND, LoadIcon(wndInfo.hInst, MAKEINTRESOURCE(ICON_MENU_CREATE)), LoadBitmap(wndInfo.hInst, MAKEINTRESOURCE(ICON_MENU_CREATE)));
			SetMenuInfo(hSubMenu, &mi);

			lcurrent = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);

			if (lcurrent == -1) {
				DeleteMenu(hSubMenu, 6, MF_BYPOSITION); //SEPARATOR
				DeleteMenu(hSubMenu, MENU_PLAYLISTS_EDIT_TAGS, MF_BYCOMMAND); //TAGS
			}

			TrackPopupMenu(hSubMenu, TPM_LEFTALIGN, pt.x, pt.y, 0, hWnd, NULL);
			break;
		}
		case NM_DBLCLK:
			lcurrent = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);
			if (lcurrent != -1) {
				if (lcurrent != musicInfo.lpos) {
					ListView_RedrawItems(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, musicInfo.lpos);
					musicInfo.ismp = FALSE;
					mpPlayButtonProc();
				}
				else {
					musicInfo.ismp ? mpPlayButtonProc() : mpPauseButtonProc();
				}
			}
			break;
		case NM_CUSTOMDRAW:
			switch (lplvcd->nmcd.dwDrawStage) {
			case CDDS_PREPAINT:
				return CDRF_NOTIFYITEMDRAW;
			case CDDS_ITEMPREPAINT:
				if (((int)lplvcd->nmcd.dwItemSpec == playlists[musicInfo.pcurrent - 1].mlListView.cpos)) {
					if (!musicInfo.ispnew || (musicInfo.pscurrent == musicInfo.pcurrent)) {
						lplvcd->clrText = COLOR_WHITE;
						lplvcd->clrTextBk = 0x8f8f8f;
						SelectObject(lplvcd->nmcd.hdc, playlists[musicInfo.pcurrent - 1].mlListView.lfont);
					}
				}
				else {
					if (((int)lplvcd->nmcd.dwItemSpec % 2) == 0) {
						lplvcd->clrText = 0x585858;
						lplvcd->clrTextBk = 0xbebebe;
					}
				}
				return CDRF_NEWFONT;
				break;
			case CDDS_SUBITEM | CDDS_ITEMPREPAINT:
				return CDRF_NEWFONT;
			}
			return TRUE;
			break;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK MLWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect = { 0, 0, CLIENT_WIDTH, CLIENT_FRAME_HEIGTH }, rrect = { 49, 380, 49 + 156, 384 + 10 };
	POINT pt;

	switch (message) {
	case WM_CREATE:
		if (!InitializeML(hWnd)) {
			MessageBox(NULL, CAPTION_MSG_ERROR_MSG, CAPTION_MSG_ERROR, MB_ICONERROR);
			DestroyWindow(hWnd);
		}
		break;
	case WM_COMMAND:
		TaskBarButtonsClickProc(hWnd, message, wParam, lParam);
		MenuButtonsClickProc(hWnd, message, wParam, lParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		ImagesUpdate(hdc);
		LabelsUpdate(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		DeinitializeML();
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		if (PtInRect(&rect, pt)) {
			SendMessage(hWnd, WM_SYSCOMMAND, SC_DRAG, (LPARAM)NULL);
		}
		break;
	case WM_NOTIFY:
		return MLWndNotifyProc(hWnd, message, wParam, lParam);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

INT_PTR CALLBACK DialogAboutProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int hpId;
	HDC hdcStatic, hdc;
	PAINTSTRUCT ps;
	static HBRUSH bkgBrush;
	static HBITMAP hlogo;
	static HFONT hprFont, hmlFont, hvnFont;

	switch (message) {
	case WM_INITDIALOG:
		SetClassLong(hDlg, GCL_STYLE, GetWindowLong(hDlg, GCL_STYLE) | CS_DROPSHADOW);

		bkgBrush = CreateSolidBrush(COLOR_WHITE);
		hlogo = LoadBitmap(wndInfo.hInst, MAKEINTRESOURCE(BMP_LOGO_ABOUT));
		hprFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Segoe UI");
		hvnFont = CreateFont(22, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Segoe UI");
		hmlFont = CreateFont(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Segoe UI");

		SendMessage(GetDlgItem(hDlg, DIALOG_ABOUT_PROGRAM), WM_SETFONT, (WPARAM)hprFont, (LPARAM)TRUE);
		SendMessage(GetDlgItem(hDlg, DIALOG_ABOUT_VERSION), WM_SETFONT, (WPARAM)hvnFont, (LPARAM)TRUE);
		SendMessage(GetDlgItem(hDlg, DIALOG_ABOUT_MAIL), WM_SETFONT, (WPARAM)hmlFont, (LPARAM)TRUE);

		return (INT_PTR)TRUE;
	case WM_CTLCOLORDLG:
		return (INT_PTR)(bkgBrush);
	case WM_CTLCOLORSTATIC:
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, COLOR_GRAY);
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);

		HDC hMemDC = CreateCompatibleDC(hdc);
		HPEN hPen = CreatePen(PS_SOLID, 1, COLOR_PINK);

		SelectObject(hdc, hPen);
		Rectangle(hdc, 0, 0, 432, 393);

		SelectObject(hMemDC, hlogo);
		BitBlt(hdc, 120, 20, 217, 188, hMemDC, 0, 0, SRCCOPY);

		DeleteObject(hPen);
		DeleteDC(hMemDC);
		EndPaint(hDlg, &ps);
		break;
	case WM_CLOSE:
		DeleteObject(hlogo);
		DeleteObject(bkgBrush);
		DeleteObject(hprFont);
		DeleteObject(hvnFont);
		DeleteObject(hmlFont);
		break;
	case WM_COMMAND:
		hpId = LOWORD(wParam);

		switch (hpId) {
		case IDOK:
			EndDialog(hDlg, hpId);
			break;
		}
		break;
	}

	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DialogCreatePlayListProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int hpId;
	HWND hedit;
	TCHAR temp[50];
	HDC hdcStatic;
	static HBRUSH bkgBrush;

	switch (message) {
	case WM_INITDIALOG:
		bkgBrush = CreateSolidBrush(COLOR_WHITE);
		return (INT_PTR)TRUE;
	case WM_CTLCOLORDLG:
		return (INT_PTR)(bkgBrush);
	case WM_CTLCOLORSTATIC:
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	case WM_CLOSE:
		DeleteObject(bkgBrush);
		break;
	case WM_COMMAND:
		hpId = LOWORD(wParam);

		switch (hpId) {
		case DIALOG_CREATE_PLAYLIST_CREATE:
			hedit = GetDlgItem(hDlg, DIALOG_CREATE_PLAYLIST_EDIT);
			GetDlgItemText(hDlg, DIALOG_CREATE_PLAYLIST_EDIT, temp, sizeof(temp));

			switch (CreatePlaylist(temp, wndInfo.hWnd, wndInfo.hInst)) {
			case CP_EMPTY_STRING:
				MessageBox(hDlg, "Пожалуйста, введите имя плейлиста!", "Предупреждение", MB_OK | MB_ICONEXCLAMATION);
				break;
			case CP_COMPARE_STRING:
				MessageBox(hDlg, "Плейлист с таким именем уже существует!", "Предупреждение", MB_OK | MB_ICONEXCLAMATION);
				break;
			case CP_ALLOK:
				playlists = GetPlayLists();
				playlists[musicInfo.pcurrent - 1].mlListView.spos = ScrollBarGetPosition(musicScrollBar);
				_tcscpy_s(musicInfo.cpname, sizeof(musicInfo.cpname), temp);
				musicInfo.pcurrent = ++musicInfo.pcount;
				ChangePlaylist(musicInfo.pcurrent);
				if (ButtonGetVisiblity(menuButton)) {
					ShowMusicListView();
				}
				EndDialog(hDlg, hpId);
				break;
			}

			break;
		case IDCANCEL:
			EndDialog(hDlg, hpId);
			break;
		default:
			break;
		}
	}

	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DialogChoisePlayListProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int hpId;
	TCHAR temp[50];
	HWND plsListView;
	static HBRUSH bkgBrush;
	HDC hdcStatic;

	switch (message) {
	case WM_INITDIALOG:
		plsListView = GetDlgItem(hDlg, DIALOG_CHOISE_PLAYLIST_LISTVIEW);
		ListView_SetExtendedListViewStyle(plsListView, LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER);

		AddListViewColumn(plsListView, "№", 30, 0);
		AddListViewColumn(plsListView, "Плейлист", 170, 1);
		AddListViewColumn(plsListView, "Песен", 60, 2);
		AddListViewColumn(plsListView, "Длина", 80, 3);

		playlists = GetPlayLists();

		for (int i = 0; i < musicInfo.pcount; ++i) {
			_stprintf_s(temp, sizeof(temp), "%d", i + 1);
			AddListViewItem(plsListView, temp, i, 0);
			AddListViewItem(plsListView, playlists[i].name, i, 1);
			_stprintf_s(temp, sizeof(temp), "%d", playlists[i].pcount);
			AddListViewItem(plsListView, temp, i, 2);
			SecondsToTime(playlists[i].plength, temp);
			AddListViewItem(plsListView, temp, i, 3);
		}

		ListView_SetItemState(plsListView, musicInfo.pcurrent - 1, LVIS_FOCUSED | LVIS_SELECTED, 0x000F);

		bkgBrush = CreateSolidBrush(COLOR_WHITE);

		return (INT_PTR)TRUE;
	case WM_CTLCOLORDLG:
		return (INT_PTR)(bkgBrush);
	case WM_CTLCOLORSTATIC:
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	case WM_CLOSE:
		DeleteObject(bkgBrush);
		break;
	case WM_COMMAND:
		hpId = LOWORD(wParam);

		switch (hpId)
		{
		case DIALOG_CHOISE_PLAYLIST_OK:
			plsListView = GetDlgItem(hDlg, DIALOG_CHOISE_PLAYLIST_LISTVIEW);
			int lcurrent = ListView_GetNextItem(plsListView, -1, LVNI_SELECTED);
			if (lcurrent != -1) {
				playlists = GetPlayLists();
				playlists[musicInfo.pcurrent - 1].mlListView.spos = ScrollBarGetPosition(musicScrollBar);
				musicInfo.pcurrent = lcurrent + 1;
				musicInfo.ispnew = TRUE;
				ChangePlaylist(musicInfo.pcurrent);
			}
			EndDialog(hDlg, hpId);
			break;
		case IDCANCEL:
			EndDialog(hDlg, hpId);
			break;
		default:
			break;
		}
	}

	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DialogEditTagsProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int hpId;
	HDC hdcStatic;
	static HBRUSH bkgBrush;
	HDC hdc;
	PAINTSTRUCT ps;
	static HBITMAP halbumcover, halbumbkgcover;
	tPartID3v1 tags;
	static int lpos;

	switch (message) {
	case WM_INITDIALOG:
		bkgBrush = CreateSolidBrush(COLOR_WHITE);

		playlists = GetPlayLists();

		lpos = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);

		if (lpos == -1) {
			EndDialog(hDlg, 0);
			return (INT_PTR)FALSE;
		}

		Edit_LimitText(GetDlgItem(hDlg, DIALOG_EDIT_TAGS_ARTIST), MAX_TAGS_STRING);
		Edit_LimitText(GetDlgItem(hDlg, DIALOG_EDIT_TAGS_TITLE), MAX_TAGS_STRING);
		Edit_LimitText(GetDlgItem(hDlg, DIALOG_EDIT_TAGS_ALBUM), MAX_TAGS_STRING);
		Edit_LimitText(GetDlgItem(hDlg, DIALOG_EDIT_TAGS_COMMENT), MAX_TAGS_STRING);
		Edit_LimitText(GetDlgItem(hDlg, DIALOG_EDIT_TAGS_YEAR), 4);

		if (playlists[musicInfo.pcurrent - 1].pdata[lpos].isvtags) {
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ARTIST, playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.artist);
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_TITLE, playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.title);
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ALBUM, playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.album);
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_COMMENT, playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.comment);
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_YEAR, playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.year);
		} else {
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ARTIST, "");
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_TITLE, "");
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ALBUM, "");
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_COMMENT, "");
			SetDlgItemText(hDlg, DIALOG_EDIT_TAGS_YEAR, "");
		}

		HWND hgcBox = GetDlgItem(hDlg, DIALOG_EDIT_TAGS_YEAR_COMBO);
		ComboBox_LimitText(hgcBox, MAX_TAGS_STRING);

		TCHAR genre[MAX_MUSIC_TAG_PATH];

		for (int i = 0; i < MAX_GENRES_COUNT; ++i) {
			GetMusicGenre(i, genre, MAX_MUSIC_TAG_PATH);
			ComboBox_AddString(hgcBox, genre);
		}

		GetMusicGenre(playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.genre, genre, MAX_MUSIC_TAG_PATH);
		int index = ComboBox_FindString(hgcBox, 0, genre);

		if (index != CB_ERR) {
			if (playlists[musicInfo.pcurrent - 1].pdata[lpos].isvtags) {
				ComboBox_SetCurSel(hgcBox, index);
			}
		}

		BOOL ismp3cover = GetMP3AlbumCover(playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename, CACHE_THUMBNAIL_ALBUM, 150);

		if (ismp3cover) {
			halbumcover = LoadImageW(wndInfo.hInst, CACHE_THUMBNAIL_ALBUM, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
		}
		else {
			halbumcover = NULL;
		}

		halbumbkgcover = LoadBitmap(wndInfo.hInst, MAKEINTRESOURCE(BMP_ALBUM_NO_COVER));

		return (INT_PTR)TRUE;
	case WM_CTLCOLORDLG:
		return (INT_PTR)(bkgBrush);
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		HDC hMemDC = CreateCompatibleDC(hdc);
		SelectObject(hMemDC, halbumbkgcover);
		BitBlt(hdc, 329, 32, 200, 200, hMemDC, 0, 0, SRCCOPY);
		if (halbumcover) {
			SelectObject(hMemDC, halbumcover);
			BitBlt(hdc, 355, 58, 150, 150, hMemDC, 0, 0, SRCCOPY);
		}
		DeleteDC(hMemDC);
		EndPaint(hDlg, &ps);
		break;
	case WM_CTLCOLORSTATIC:
		hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkMode(hdcStatic, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	case WM_CLOSE:
		DeleteFileW(CACHE_THUMBNAIL_ALBUM);
		if (halbumcover) {
			DeleteObject(halbumcover);
		}
		DeleteObject(halbumbkgcover);
		DeleteObject(bkgBrush);
		break;
	case WM_COMMAND:
		hpId = LOWORD(wParam);

		switch (hpId) {
		case DIALOG_EDIT_TAGS_SAVE:

			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ARTIST, tags.artist, MAX_TAGS_STRING + 1);
			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_TITLE, tags.title, MAX_TAGS_STRING + 1);
			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_ALBUM, tags.album, MAX_TAGS_STRING + 1);
			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_COMMENT, tags.comment, MAX_TAGS_STRING + 1);
			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_YEAR, tags.year, 5);

			TCHAR genre[MAX_TAGS_STRING];
			GetDlgItemText(hDlg, DIALOG_EDIT_TAGS_YEAR_COMBO, genre, MAX_TAGS_STRING);
			tags.genre = GetMusicGenreIndex(genre);

			if (lpos == musicInfo.lpos) {
				mpPauseButtonProc();
				BASS_StreamFree(musicInfo.cchannel);
			}

			BOOL bset_tags = SetMP3ID3v1Tags(musicInfo.pcurrent, lpos, tags);
			TCHAR mpname[MAX_PATH];

			if (bset_tags) {
				playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1 = tags;

				if (lpos == musicInfo.lpos) {
					_tcscpy_s(mpname, sizeof(mpname), playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.artist);
					LabelChangeText(mpSingerLabel, mpname);
					_tcscpy_s(mpname, sizeof(mpname), playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.title);
					LabelChangeText(mpSongLabel, mpname);
				}

				if (CheckValidTags(playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.artist,
					playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.title)) {
					sprintf_s(playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.trackname,
						sizeof(playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.trackname), "%s - %s",
						playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.artist,
						playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.title);
					AddListViewItem(playlists[musicInfo.pcurrent - 1].mlListView.listView,
						playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.trackname, lpos, 1);
					playlists[musicInfo.pcurrent - 1].pdata[lpos].isvtags = TRUE;
				} 
			}

			if (lpos == musicInfo.lpos) {
				musicInfo.cchannel = MusicPlay(wndInfo.hWnd, playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename, FALSE, musicInfo.cchannel);
				mpPlayButtonProc();
				MusicSetPosition(musicInfo.cchannel, (int)musicInfo.tpercent);
			}

			if (bset_tags) {
				EndDialog(hDlg, hpId);
			}
			else {
				MessageBox(wndInfo.hWnd, MESSAGE_EDIT_TAGS_ERROR, MESSAGE_EDIT_TAGS_HEADER, MB_OK | MB_ICONINFORMATION);
			}

			break;
		case IDCANCEL:
			EndDialog(hDlg, hpId);
			break;
		default:
			break;
		}
	}

	return (INT_PTR)FALSE;
}

int TimerThreadProc(LPVOID lpParameter)
{
	QWORD currlength = BASS_ChannelGetLength(musicInfo.cchannel, BASS_POS_BYTE);
	QWORD currpos = BASS_ChannelGetPosition(musicInfo.cchannel, BASS_POS_BYTE);

	QWORD ttime = (QWORD)BASS_ChannelBytes2Seconds(musicInfo.cchannel, currlength);
	QWORD ntime = (QWORD)BASS_ChannelBytes2Seconds(musicInfo.cchannel, currpos);

	TCHAR sntime[20], sttime[20], total[40];

	SecondsToTime(ttime, sttime);
	SecondsToTime(ntime, sntime);

	_stprintf_s(total, sizeof(total), "%s/%s", sntime, sttime);

	musicInfo.cchannel_length = (DWORD)ttime;
	musicInfo.cchannel_current = (DWORD)ntime;

	musicInfo.tpercent = (double)musicInfo.cchannel_current / musicInfo.cchannel_length * 100;
	musicInfo.tpercent = (musicInfo.tpercent - (int)musicInfo.tpercent >= 0.5) ? musicInfo.tpercent + 1 : musicInfo.tpercent;
	TrackBarSetPosition(musicTrackBar, (int)musicInfo.tpercent);

	TaskBarChangeValue(wndInfo.hWnd, (int)musicInfo.tpercent, iTaskBar);
	TaskBarChangeState(wndInfo.hWnd, TBPF_NORMAL, iTaskBar);

	LabelChangeText(mpLengthLabel, total);

	return 0;
}

int SearchFolderMusicThreadProc(LPVOID lpParameter)
{
	WCHAR pfolder[MAX_PATH];
	TCHAR pname[50];

	if (BrowseForFolder(wndInfo.hWnd, pfolder, MAX_PATH, L"",
		L"Выберите папку, в которой расположены Ваши музыкальные файлы...", BrowseFolderCallback)) {
		SearchMusicInFolder(playlists[musicInfo.pcurrent - 1].mlListView.listView, pfolder, SearchMusicProc, musicInfo.pcurrent);
		sprintf_s(pname, sizeof(pname), "playlists\\%s.mlpls", musicInfo.cpname);
		//CreatePlayListFile(pname, musicInfo.pcurrent);
	}

	return 0;
}

int SearchFileMusicThreadProc(LPVOID lpParameter)
{
	WCHAR pfilename[MAX_PATH];
	
	if (BrowseForFileW(wndInfo.hWnd, pfilename, MAX_PATH, L"MPEG-1 Audio Layer 3 (*.mp3)\0*.mp3\0")) {
		SearchMusicInFile(playlists[musicInfo.pcurrent - 1].mlListView.listView, pfilename, SearchMusicProc, musicInfo.pcurrent);
	}

	return 0;
}

int SaveFilePlaylistThreadProc(LPVOID lpParameter)
{
	TCHAR pfilename[MAX_PATH];

	_stprintf_s(pfilename, sizeof(pfilename), "%s.mlpls", musicInfo.cpname);

	if (BrowseForSaveFile(wndInfo.hWnd, pfilename, sizeof(pfilename), "Music Live playlist file (*mlpls)\0*.mlpls\0")) {
		CreatePlayListFile(pfilename, musicInfo.pcurrent);
	}

	return 0;
}

int OpenFilePlayListThreadProc(LPVOID lpParameter)
{
	switch (musicInfo.bpopen) {
	case CP_COMPARE_STRING:
		for (int i = 0; i < musicInfo.pcount; ++i) {
			if (_tcscmp(musicInfo.files.pname, playlists[i].name) == 0) {
				playlists = GetPlayLists();
				playlists[musicInfo.pcurrent - 1].mlListView.spos = ScrollBarGetPosition(musicScrollBar);
				_tcscpy_s(musicInfo.cpname, sizeof(musicInfo.cpname), playlists[i].name);
				musicInfo.pcurrent = i + 1;
				ChangePlaylist(musicInfo.pcurrent);
				if (ButtonGetVisiblity(menuButton)) {
					ShowMusicListView();
				}
				for (int j = 0; j < musicInfo.files.fcount; ++j) {
					SearchMusicInFile(playlists[i].mlListView.listView, musicInfo.files.filenames[j], SearchMusicProc, i + 1);
					free(musicInfo.files.filenames[j]);
				}
				free(musicInfo.files.filenames);
			}
		}
		break;
	case CP_ALLOK:
		for (int i = 0; i < musicInfo.files.fcount; ++i) {
			SearchMusicInFile(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.files.filenames[i], SearchMusicProc, musicInfo.pcurrent);
			free(musicInfo.files.filenames[i]);
		}
		free(musicInfo.files.filenames);
		break;
	}

	return 0;
}

int HideMusicPageThreadProc(LPVOID lpParameter)
{
	ImageChangeStaticBitmap(bkgImage, wndInfo.hInst, BMP_FRAME);

	HideMusicListView();

	ImageHide(mpPlayTrackbarBkg);
	ImageHide(mpVolumeTrackbarBkg);
	ImageHide(thumbImage);

	HideMenuButtons();

	ButtonHide(mpPlayButton);
	ButtonHide(mpPauseButton);
	ButtonHide(mpPrevButton);
	ButtonHide(mpNextButton);
	ButtonHide(menuButton);
	ButtonHide(volumeNoButton);
	ButtonHide(volumeYesButton);
	ButtonHide(mpRepeatNoButton);
	ButtonHide(mpRepeatYesButton);
	ButtonHide(mpRandomNoButton);
	ButtonHide(mpRandomYesButton);

	TrackbarHide(volumeTrackBar);
	TrackbarHide(musicTrackBar);

	LabelHide(mpSingerLabel);
	LabelHide(mpSongLabel);
	LabelHide(mpBitrateLabel);
	LabelHide(mpLengthLabel);
	LabelHide(playlistLabel);
	LabelHide(countLabel);
	LabelHide(timeLabel);

	return 0;
}

int ArtistsThreadProc(LPVOID lpParameter)
{
	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_DATA));
	if (!DownloadFile(URL_TOP_ARTISTS, XML_TOP_ARTISTS_FILE, TRUE)) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_DATA_ERROR));
		wndInfo.bdThread.isArtists = FALSE;
		DeleteTopArtistsPanels();
		return 0;
	}

	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_APPLY_DATA));
	if (!ParseTopArtists(XML_TOP_ARTISTS_FILE)) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_APPLY_DATA_ERROR));
		wndInfo.bdThread.isArtists = FALSE;
		DeleteTopArtistsPanels();
		return 0;
	}

	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_IMAGES));
	if (!DownloadTopArtistsImages()) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_IMAGES_ERROR));
		wndInfo.bdThread.isArtists = FALSE;
		DeleteTopArtistsPanels();
		return 0;
	}

	LabelHide(statusLabel);

	return 0;
}

int SongsThreadProc(LPVOID lpParameter)
{
	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_DATA));
	if (!DownloadFile(TEXT(URL_TOP_TRACKS), TEXT(XML_TOP_TRACKS_FILE), TRUE)) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_DATA_ERROR));
		wndInfo.bdThread.isSongs = FALSE;
		DeleteTopSongsPanels();
		return 0;
	}

	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_APPLY_DATA));
	if (!ParseTopSongs(TEXT(XML_TOP_TRACKS_FILE))) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_APPLY_DATA_ERROR));
		wndInfo.bdThread.isSongs = FALSE;
		DeleteTopSongsPanels();
		return 0;
	}

	LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_IMAGES));
	if (!DownloadTopSongsImages()) {
		LabelChangeText(statusLabel, TEXT(MESSAGE_DOWNLOAD_IMAGES_ERROR));
		wndInfo.bdThread.isSongs = FALSE;
		DeleteTopSongsPanels();
		return 0;
	}

	LabelHide(statusLabel);

	return 0;
}

int MusicThreadProc(LPVOID lpParameter)
{
	const RECT trect = { 67, 147, 187, 267 };

	LabelHide(quoteMusicLabel);
	LabelHide(quoteLastFMLabel);
	LabelHide(statusLabel);

	ImageChangeStaticBitmap(bkgImage, wndInfo.hInst, BMP_FRAME_MUSIC);

	ShowMusicListView();

	LabelChangeText(titleLabel, "MUSIC LIVE | МУЗЫКА");

	ImageHide(MLImage);

	HideSlidePanels(STATE_TOP_SONGS, GetSlidePanelsState(STATE_TOP_SONGS));
	HideSlidePanels(STATE_TOP_ARTISTS, GetSlidePanelsState(STATE_TOP_ARTISTS));

	MenuSetActiveTab(MENU_TAB_MUSIC);

	ButtonHide(panelsFrameButton);
	ButtonHide(panelsLeftButton);
	ButtonHide(panelsRightButton);

	ImageShow(mpPlayTrackbarBkg);

	ImageShow(thumbImage);

	ButtonShow(mpPrevButton);
	ButtonShow(mpNextButton);
	ButtonShow(menuButton);

	ButtonShow(lvNumberButton);
	ButtonShow(lvNameButton);
	ButtonShow(lvBitrateButton);
	ButtonShow(lvLengthButton);

	LabelShow(mpSingerLabel);
	LabelShow(mpSongLabel);
	LabelShow(mpBitrateLabel);
	LabelShow(mpLengthLabel);
	LabelShow(playlistLabel);
	LabelShow(countLabel);
	LabelShow(timeLabel);

	if (musicInfo.isstart) {

		if (musicInfo.ismp) {
			ButtonShow(mpPlayButton);
		}
		else {
			ButtonShow(mpPauseButton);
		}

		if (musicInfo.israndom) {
			ButtonShow(mpRandomYesButton);
		}
		else {
			ButtonShow(mpRandomNoButton);
		}

		if (musicInfo.isrepeat) {
			ButtonShow(mpRepeatYesButton);
		}
		else {
			ButtonShow(mpRepeatNoButton);
		}

		if (musicInfo.isvolume) {
			volumeNoButtonProc();
		}
		else {
			volumeYesButtonProc();
		}

		TaskBarChangeThumbnailClip(wndInfo.hWnd, trect, iTaskBar);

		tbButtons[0] = TaskBarCreateButton(wndInfo.hInst, ICON_PREV, THB_ICON | THB_TOOLTIP | THB_FLAGS,
			L"« Предыдущая композиция", TASKBAR_BUTTON_PREV);
		tbButtons[1] = TaskBarCreateButton(wndInfo.hInst, ICON_PLAY, THB_ICON | THB_TOOLTIP | THB_FLAGS,
			L"Проиграть", TASKBAR_BUTTON_PLAY);
		tbButtons[2] = TaskBarCreateButton(wndInfo.hInst, ICON_NEXT, THB_ICON | THB_TOOLTIP | THB_FLAGS,
			L"Следующая композиция »", TASKBAR_BUTTON_NEXT);

		TaskBarAddThumbButtons(wndInfo.hWnd, tbButtons, 3, iTaskBar);
	}
	else {
		ButtonShow(mpPlayButton);
	}

	TrackbarShow(musicTrackBar);

	TrackBarSetPosition(volumeTrackBar, musicInfo.vpos);

	return 0;
}

void MenuSetActiveTab(int tubnum)
{
	for (int i = 0; i < MENU_TABS_COUNT; ++i) {
		if (i != tubnum - 1) {
			ButtonShow(tabButtons[i].menuTab);
		}
	}
	for (int i = 0; i < MENU_TABS_COUNT; ++i) {
		if (i != tubnum - 1) {
			ButtonHide(tabButtons[i].menuActive);
		}
	}
	if (tubnum != MENU_TAB_NOACTIVE) {
		ButtonShow(tabButtons[tubnum - 1].menuActive);
		ButtonHide(tabButtons[tubnum - 1].menuTab);
	}
	wndInfo.activeTab = tubnum;
}

void CALLBACK MusicProgressProc(HWND hWnd, UINT u, UINT_PTR up, DWORD d)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)TimerThreadProc);
}

int mpNextButtonProc(void)
{
	int rpos;

	SetFocus(playlists[musicInfo.pcurrent - 1].mlListView.listView);

	int lcount = ListView_GetItemCount(playlists[musicInfo.pcurrent - 1].mlListView.listView);

	if (musicInfo.lpos != -1 && lcount > 0) {
		ListView_RedrawItems(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, musicInfo.lpos);
		if (musicInfo.israndom) {
			do {
				rpos = (rand() % lcount);
			} while (musicInfo.lpos == rpos);
			musicInfo.lpos = rpos;
		} else {
			musicInfo.lpos++;
			if (musicInfo.lpos >= lcount) {
				musicInfo.lpos = 0;
			}
		}
		playlists[musicInfo.pcurrent - 1].mlListView.cpos = musicInfo.lpos;
		ListView_SetItemState(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, LVIS_FOCUSED | LVIS_SELECTED, 0x000F);
		if (musicInfo.ismp) {
			musicInfo.ismp = FALSE;
		}
		mpPlayButtonProc();
	}

	return 0;
}

void CALLBACK MusicSyncProc(HSYNC handle, DWORD channel, DWORD data, void *user)
{
	if (musicInfo.isrepeat) {
		ListView_SetItemState(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, LVIS_FOCUSED | LVIS_SELECTED, 0x000F);
		mpPlayButtonProc();
	} else {
		mpNextButtonProc();
	}
}

int mpPlayButtonProc(void)
{
	WCHAR temp[] = CACHE_THUMBNAIL_IMAGE;
	TCHAR ttime[20];
	TCHAR mpname[MAX_TAGS_STRING + 1];
	int lpos = -1;
	const RECT trect = { 67, 147, 187, 267 };

	int lcount = ListView_GetItemCount(playlists[musicInfo.pcurrent - 1].mlListView.listView);

	if (lcount > 0) {
		lpos = ListView_GetNextItem(playlists[musicInfo.pcurrent - 1].mlListView.listView, -1, LVNI_SELECTED);

		if (lpos != -1) {

			if (!musicInfo.isstart) {
				ButtonShow(mpRandomNoButton);
				ButtonShow(mpRepeatNoButton);
				volumeYesButtonProc();

				TaskBarChangeThumbnailClip(wndInfo.hWnd, trect, iTaskBar);

				tbButtons[0] = TaskBarCreateButton(wndInfo.hInst, ICON_PREV, THB_ICON | THB_TOOLTIP | THB_FLAGS,
					L"« Предыдущая композиция", TASKBAR_BUTTON_PREV);
				tbButtons[1] = TaskBarCreateButton(wndInfo.hInst, ICON_PLAY, THB_ICON | THB_TOOLTIP | THB_FLAGS,
					L"Проиграть", TASKBAR_BUTTON_PLAY);
				tbButtons[2] = TaskBarCreateButton(wndInfo.hInst, ICON_NEXT, THB_ICON | THB_TOOLTIP | THB_FLAGS,
					L"Следующая композиция »", TASKBAR_BUTTON_NEXT);

				TaskBarAddThumbButtons(wndInfo.hWnd, tbButtons, 3, iTaskBar);

				musicInfo.ismp = FALSE;
				musicInfo.isstart = TRUE;
			}

			KillTimer(wndInfo.hWnd, 0);

			if (FileExistsW(playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename)) {
				if (!musicInfo.ismp) {

					BOOL ismp3cover = GetMP3AlbumCover(playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename, temp, 120);

					if (!ismp3cover && !musicInfo.isorigthumb) {
						musicInfo.isorigthumb = TRUE;
						ImageChangeDynamicBitmap(thumbImage, temp, musicInfo.isorigthumb, wndInfo.hInst, BMP_NO_COVER_THUMB);
					}
					else {
						if (ismp3cover) {
							musicInfo.isorigthumb = FALSE;
							ImageChangeDynamicBitmap(thumbImage, temp, musicInfo.isorigthumb, wndInfo.hInst, BMP_NO_COVER_THUMB);
						}
					}

					if (playlists[musicInfo.pcurrent - 1].pdata[lpos].isvtags) {
						_tcscpy_s(mpname, sizeof(mpname), playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.artist);
						LabelChangeText(mpSingerLabel, mpname);
						_tcscpy_s(mpname, sizeof(mpname), playlists[musicInfo.pcurrent - 1].pdata[lpos].id3v1.title);
						LabelChangeText(mpSongLabel, mpname);
					}
					else {
						LabelChangeText(mpSingerLabel, "");
						LabelChangeText(mpSongLabel, playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.trackname);
					}
					LabelChangeText(mpBitrateLabel, playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.bitrate);
					_stprintf_s(ttime, sizeof(ttime), "00:00/%s", playlists[musicInfo.pcurrent - 1].pdata[lpos].ldata.length);
					LabelChangeText(mpLengthLabel, ttime);
					TrackBarSetPosition(musicTrackBar, 0);
					musicInfo.lpos = lpos;
					playlists[musicInfo.pcurrent - 1].mlListView.cpos = musicInfo.lpos;
				}

				musicInfo.cchannel = MusicPlay(wndInfo.hWnd, playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename, musicInfo.ismp, musicInfo.cchannel);
				BASS_ChannelSetAttribute(musicInfo.cchannel, BASS_ATTRIB_VOL, (float)(musicInfo.vpos / 100.0));
				musicInfo.mtimer = SetTimer(wndInfo.hWnd, 0, 500, (TIMERPROC)MusicProgressProc);

				MusicSetSyncProc(musicInfo.cchannel, MusicSyncProc, BASS_SYNC_END | BASS_SYNC_ONETIME);
				TaskBarChangeOverlayIcon(wndInfo.hWnd, ICON_OVER_PLAY, wndInfo.hInst, iTaskBar);
				TaskBarChangeIcon(wndInfo.hWnd, tbButtons, 3, 2, ICON_PAUSE, wndInfo.hInst, iTaskBar);
				musicInfo.ismp = FALSE;
				musicInfo.ispnew = FALSE;
				musicInfo.pscurrent = musicInfo.pcurrent;

				ButtonShow(mpPauseButton);
				ButtonHide(mpPlayButton);
			}
		} else {
			if (musicInfo.lpos != -1) {
				SetFocus(playlists[musicInfo.pcurrent - 1].mlListView.listView);
				ListView_SetItemState(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, LVIS_FOCUSED | LVIS_SELECTED, 0x000F);
				mpPlayButtonProc();
				ButtonShow(mpPauseButton);
				ButtonHide(mpPlayButton);
			}
		}
	} else {
		if (musicInfo.ispnew && musicInfo.ismp) {
			KillTimer(wndInfo.hWnd, 0);

			musicInfo.cchannel = MusicPlay(wndInfo.hWnd, playlists[musicInfo.pcurrent - 1].pdata[lpos].wfilename, musicInfo.ismp, musicInfo.cchannel);
			BASS_ChannelSetAttribute(musicInfo.cchannel, BASS_ATTRIB_VOL, (float)(musicInfo.vpos / 100.0));
			musicInfo.mtimer = SetTimer(wndInfo.hWnd, 0, 500, (TIMERPROC)MusicProgressProc);

			MusicSetSyncProc(musicInfo.cchannel, MusicSyncProc, BASS_SYNC_END | BASS_SYNC_ONETIME);
			TaskBarChangeOverlayIcon(wndInfo.hWnd, ICON_OVER_PLAY, wndInfo.hInst, iTaskBar);
			TaskBarChangeIcon(wndInfo.hWnd, tbButtons, 3, 2, ICON_PAUSE, wndInfo.hInst, iTaskBar);
			musicInfo.ismp = FALSE;
			ButtonShow(mpPauseButton);
			ButtonHide(mpPlayButton);
		}
	}

	return lpos;
}

int mpPauseButtonProc(void)
{
	ButtonShow(mpPlayButton);
	ButtonHide(mpPauseButton);
	BASS_ChannelPause(musicInfo.cchannel);
	KillTimer(wndInfo.hWnd, 0);
	TaskBarChangeState(wndInfo.hWnd, TBPF_PAUSED, iTaskBar);
	TaskBarChangeOverlayIcon(wndInfo.hWnd, ICON_OVER_PAUSE, wndInfo.hInst, iTaskBar);
	TaskBarChangeIcon(wndInfo.hWnd, tbButtons, 3, 2, ICON_PLAY, wndInfo.hInst, iTaskBar);
	musicInfo.ismp = TRUE;

	return 0;
}

int mpPrevButtonProc(void)
{
	int rpos;

	SetFocus(playlists[musicInfo.pcurrent - 1].mlListView.listView);

	int lcount = ListView_GetItemCount(playlists[musicInfo.pcurrent - 1].mlListView.listView);

	if (musicInfo.lpos != -1 && lcount > 0) {
		ListView_RedrawItems(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, musicInfo.lpos);
		if (!musicInfo.ismp) {
			if (musicInfo.cchannel_current < MAX_PREV_SECONDS) {
				if (musicInfo.israndom) {
					do {
						rpos = (rand() % lcount);
					} while (musicInfo.lpos == rpos);
					musicInfo.lpos = rpos;
				} else {
					musicInfo.lpos--;
					if (musicInfo.lpos == -1) {
						musicInfo.lpos = lcount - 1;
					}
				}
			}
		} else {
			musicInfo.ismp = FALSE;
		}
		ListView_SetItemState(playlists[musicInfo.pcurrent - 1].mlListView.listView, musicInfo.lpos, LVIS_FOCUSED | LVIS_SELECTED, 0x000F);
		mpPlayButtonProc();
	}

	return 0;
}

int menuButtonProc(void)
{
	HideMusicListView();

	ButtonShow(menuCreateButton);
	ButtonShow(menuAddButton);
	ButtonShow(menuOpenPlaylistButton);
	ButtonShow(menuSaveButton);
	ButtonShow(menuChoiseButton);
	LabelShow(menuLabel);
	ButtonShow(menuBackButton);
	ButtonHide(menuButton);

	return 0;
}

int SearchMusicProc(int count)
{
	TCHAR temp[50], stime[20];

	SecondsToTime(playlists[musicInfo.pcurrent - 1].plength, stime);
	_stprintf_s(temp, sizeof(temp), "%d", count);

	LabelChangeText(countLabel, temp);
	LabelChangeText(timeLabel, stime);

	if (playlists[musicInfo.pcurrent - 1].pcount > LISTVIEW_ONE_PAGE_ITEMS) {
		if (ButtonGetVisiblity(menuButton) && !playlists[musicInfo.pcurrent - 1].mlListView.isscrollbar) {
			ScrollBarShow(musicScrollBar);
		}
		HRGN rgn = CreateRectRgn(5, 25, 466, 317);
		SetWindowRgn(playlists[musicInfo.pcurrent - 1].mlListView.listView, rgn, TRUE);
		DeleteRgn(rgn);
		playlists[musicInfo.pcurrent - 1].mlListView.isscrollbar = TRUE;
	}

	return 0;
}

int CALLBACK BrowseFolderCallback(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	if (uMsg == BFFM_INITIALIZED) {
		LPCTSTR path = (LPCTSTR)(lpData);
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)path);
	}
	return 0;
}

void ChangePlaylist(int pwcurrent)
{
	TCHAR time[20], count[20];

	SecondsToTime(playlists[pwcurrent - 1].plength, time);
	_stprintf_s(count, sizeof(count), "%d", playlists[pwcurrent - 1].pcount);

	LabelChangeText(playlistLabel, playlists[pwcurrent - 1].name);
	LabelChangeText(countLabel, count);
	LabelChangeText(timeLabel, time);

	musicInfo.lpos = playlists[pwcurrent - 1].mlListView.cpos;
	musicInfo.ispnew = TRUE;

	ScrollBarSetPosition(musicScrollBar, playlists[pwcurrent - 1].mlListView.spos);
}

int OpenFilePlayListProc(void)
{
	TCHAR pfilename[MAX_PATH];

	if (BrowseForFileA(wndInfo.hWnd, pfilename, MAX_PATH, "Music Live playlist file (*mlpls)\0*.mlpls\0")) {
		musicInfo.files.fcount = 0;
		if (OpenPlayListFile(pfilename, wndInfo.hWnd, wndInfo.hInst, &musicInfo.files)) {

			switch (CreatePlaylist(musicInfo.files.pname, wndInfo.hWnd, wndInfo.hInst)) {
			case CP_EMPTY_STRING:
				MessageBox(wndInfo.hWnd, "Не удалось загрузить плейлист!", "Предупреждение", MB_OK | MB_ICONEXCLAMATION);
				return CP_EMPTY_STRING;
			case CP_COMPARE_STRING:
				//MessageBox(wndInfo.hWnd, "Плейлист с таким именем уже существует!", "Предупреждение", MB_OK | MB_ICONEXCLAMATION);
				return CP_COMPARE_STRING;
			case CP_ALLOK:
				playlists = GetPlayLists();
				playlists[musicInfo.pcurrent - 1].mlListView.spos = ScrollBarGetPosition(musicScrollBar);
				_tcscpy_s(musicInfo.cpname, sizeof(musicInfo.cpname), musicInfo.files.pname);
				musicInfo.pcurrent = ++musicInfo.pcount;
				ChangePlaylist(musicInfo.pcurrent);
				if (ButtonGetVisiblity(menuButton)) {
					ShowMusicListView();
				}
				return CP_ALLOK;
			}

		}
	}

	return 0;
}

int menuOpenPlaylistProc(void)
{
	musicInfo.bpopen = OpenFilePlayListProc();
	CreateSingleThread((LPTHREAD_START_ROUTINE)OpenFilePlayListThreadProc);
	return 0;
}

int mpRepeatNoButtonProc(void)
{
	musicInfo.isrepeat = TRUE;
	ButtonShow(mpRepeatYesButton);
	ButtonHide(mpRepeatNoButton);

	return 0;
}

int mpRepeatYesButtonProc(void)
{
	musicInfo.isrepeat = FALSE;
	ButtonShow(mpRepeatNoButton);
	ButtonHide(mpRepeatYesButton);

	return 0;
}

int mpRandomNoButtonProc(void)
{
	musicInfo.israndom = TRUE;
	ButtonShow(mpRandomYesButton);
	ButtonHide(mpRandomNoButton);

	return 0;
}

int mpRandomYesButtonProc(void)
{
	musicInfo.israndom = FALSE;
	ButtonShow(mpRandomNoButton);
	ButtonHide(mpRandomYesButton);

	return 0;
}

int volumeNoButtonProc(void)
{
	musicInfo.isvolume = TRUE;
	ImageShow(mpVolumeTrackbarBkg);
	TrackbarShow(volumeTrackBar);
	ButtonShow(volumeYesButton);
	ButtonHide(volumeNoButton);

	return 0;
}

int volumeYesButtonProc(void)
{
	musicInfo.isvolume = FALSE;
	ImageHide(mpVolumeTrackbarBkg);
	TrackbarHide(volumeTrackBar);
	ButtonShow(volumeNoButton);
	ButtonHide(volumeYesButton);

	return 0;
}

void HideMenuButtons(void)
{
	ButtonHide(menuCreateButton);
	ButtonHide(menuAddButton);
	ButtonHide(menuOpenPlaylistButton);
	ButtonHide(menuSaveButton);
	ButtonHide(menuChoiseButton);
	ButtonHide(menuAddFolderButton);
	ButtonHide(menuAddFileButton);
	LabelHide(menuLabel);
	ButtonHide(menuBackButton);
}

int menuBackButtonProc(void)
{
	ShowMusicListView();
	HideMenuButtons();
	ButtonShow(menuButton);

	return 0;
}

int menuAddButtonProc(void)
{
	ButtonShow(menuAddFolderButton);
	ButtonShow(menuAddFileButton);
	ButtonHide(menuAddButton);

	return 0;
}

int menuAddFolderButtonProc(void)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)SearchFolderMusicThreadProc);

	return 0;
}

int menuAddFileButtonProc(void)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)SearchFileMusicThreadProc);

	return 0;
}

int menuCreateButtonProc(void)
{
	DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_CREATE_PLAYLIST), wndInfo.hWnd, DialogCreatePlayListProc);

	return 0;
}

int menuSaveButtonProc(void)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)SaveFilePlaylistThreadProc);

	return 0;
}

int menuChoiseButtonProc(void)
{
	DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_CHOISE_PLAYLIST), wndInfo.hWnd, DialogChoisePlayListProc);

	return 0;
}

int iconButtonProc(void)
{
	DialogBox(wndInfo.hInst, MAKEINTRESOURCE(DIALOG_ABOUT), wndInfo.hWnd, DialogAboutProc);

	return 0;
}

int MusicScrollBarProc(int pos)
{
	int spos = (int)(pos * playlists[musicInfo.pcurrent - 1].pcount / 100.0);
    playlists[musicInfo.pcurrent - 1].mlListView.pos = (int) spos;

	if (spos >= playlists[musicInfo.pcurrent - 1].pcount) {
		spos = playlists[musicInfo.pcurrent - 1].pcount - 1;
	}

	ListView_EnsureVisible(playlists[musicInfo.pcurrent - 1].mlListView.listView, spos , FALSE);

	return 0;
}

int HideMusicPage(void)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)HideMusicPageThreadProc);

	return 0;
}

int ArtistsSubThreadProc(void)
{
	ImageHide(MLImage);
	ButtonChangeText(panelsFrameButton, TEXT(CAPTION_BTN_TOPARTISTS));
	ButtonChangeProc(panelsFrameButton, (ButtonProc)TopArtistsPanelFrameProc);
	ButtonChangeProc(panelsLeftButton, (ButtonProc)TopArtistsLeftProc);
	ButtonChangeProc(panelsRightButton, (ButtonProc)TopArtistsRightProc);
	ButtonShow(panelsFrameButton);
	ButtonShow(panelsLeftButton);
	ButtonShow(panelsRightButton);
	ShowSlidePanels(STATE_TOP_ARTISTS, 0, 0);

	return 0;
}

int ArtistsAfterThreadProc(void)
{
	if (wndInfo.bdThread.isArtists) {
		CreateTopArtistsPanels(wndInfo.hInst, wndInfo.hWnd);
		if (wndInfo.activeTab != MENU_TAB_SINGERS) {
			HideSlidePanels(STATE_TOP_ARTISTS, 0);
		} else {
			ArtistsSubThreadProc();
		}
	}
	wndInfo.bdThread.isArtists = FALSE;
	return 0;
}

int ArtistsButtonProc(void)
{
	RECT trect = { 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT };

	if (!wndInfo.bdThread.isSongs) {
		HideMusicPage();
		HideSlidePanels(STATE_TOP_SONGS, GetSlidePanelsState(STATE_TOP_SONGS));
		ButtonHide(panelsFrameButton);
		ButtonHide(panelsLeftButton);
		ButtonHide(panelsRightButton);
		LabelHide(quoteMusicLabel);
		LabelHide(quoteLastFMLabel);
		MenuSetActiveTab(MENU_TAB_SINGERS);
		LabelChangeText(titleLabel, "MUSIC LIVE | ИСПОЛНИТЕЛИ");
		ImageShow(MLImage);
		TaskBarChangeThumbnailClip(wndInfo.hWnd, trect, iTaskBar);
		if (!CheckDownloadStatus(STATE_TOP_ARTISTS)) {
			LabelShow(statusLabel);
			wndInfo.bdThread.isArtists = TRUE;
			CreateWaitThread(wndInfo.hWnd, (WaitThreadProc)ArtistsThreadProc, (WaitThreadProc)ArtistsAfterThreadProc);
		} else {
			ArtistsSubThreadProc();
		}
	}
	return 0;
}

int ExitButtonProc(void)
{
	SendMessage(wndInfo.hWnd, WM_DESTROY, (WPARAM) NULL, (LPARAM) NULL);
	return 0;
}

int MinimizeButtonProc(void)
{
	SendMessage(wndInfo.hWnd, WM_SYSCOMMAND, (WPARAM)SC_MINIMIZE, (LPARAM)NULL);
	return 0;
}

int SongsSubThreadProc(void)
{
	ImageHide(MLImage);

	ButtonChangeText(panelsFrameButton, TEXT(CAPTION_BTN_TOPSONGS));
	ButtonChangeProc(panelsFrameButton, (ButtonProc)TopSongsPanelFrameProc);
	ButtonChangeProc(panelsLeftButton, (ButtonProc)TopSongsLeftProc);
	ButtonChangeProc(panelsRightButton, (ButtonProc)TopSongsRightProc);

	ButtonShow(panelsFrameButton);
	ButtonShow(panelsLeftButton);
	ButtonShow(panelsRightButton);

	ShowSlidePanels(STATE_TOP_SONGS, 0, 0);

	return 0;
}

int SongsAfterThreadProc(void)
{
	if (wndInfo.bdThread.isSongs) {
		CreateTopSongsPanels(wndInfo.hInst, wndInfo.hWnd);
		if (wndInfo.activeTab != MENU_TAB_SONGS) {
			HideSlidePanels(STATE_TOP_SONGS, 0);
		}
		else {
			SongsSubThreadProc();
		}
	}
	wndInfo.bdThread.isSongs = FALSE;

	return 0;
}

int SongsButtonProc(void)
{
	RECT trect = { 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT };

	if (!wndInfo.bdThread.isArtists) {
		HideMusicPage();
		HideSlidePanels(STATE_TOP_ARTISTS, GetSlidePanelsState(STATE_TOP_ARTISTS));
		ButtonHide(panelsFrameButton);
		ButtonHide(panelsLeftButton);
		ButtonHide(panelsRightButton);
		LabelHide(quoteMusicLabel);
		LabelHide(quoteLastFMLabel);
		MenuSetActiveTab(MENU_TAB_SONGS);
		TaskBarChangeThumbnailClip(wndInfo.hWnd, trect, iTaskBar);
		LabelChangeText(titleLabel, "MUSIC LIVE | КОМПОЗИЦИИ");
		ImageShow(MLImage);
		if (!CheckDownloadStatus(STATE_TOP_SONGS)) {
			LabelShow(statusLabel);
			wndInfo.bdThread.isSongs = TRUE;
			CreateWaitThread(wndInfo.hWnd, (WaitThreadProc)SongsThreadProc, (WaitThreadProc)SongsAfterThreadProc);
		} else {
			SongsSubThreadProc();
		}
	}

	return 0;
}

void HideMusicListView()
{
	ShowWindow(playlists[musicInfo.pcurrent - 1].mlListView.listView, SW_HIDE);

	if (playlists[musicInfo.pcurrent - 1].mlListView.isscrollbar) {
		ScrollBarHide(musicScrollBar);
	}

	ButtonHide(lvNumberButton);
	ButtonHide(lvBitrateButton);
	ButtonHide(lvNameButton);
	ButtonHide(lvLengthButton);
}

int menuSetActiveListView(int lnum)
{
	for (int i = 0; i < musicInfo.pcount; ++i) {
		if (i != lnum - 1) {
			ShowWindow(playlists[i].mlListView.listView, SW_HIDE);
		}
	}
	if (lnum != MENU_TAB_NOACTIVE) {
		ShowWindow(playlists[lnum - 1].mlListView.listView, SW_SHOW);
	}

	return lnum;
}

void ShowMusicListView()
{
	menuSetActiveListView(musicInfo.pcurrent);
	
	if (playlists[musicInfo.pcurrent - 1].mlListView.isscrollbar) {
		ScrollBarShow(musicScrollBar);
	} else {
		ScrollBarHide(musicScrollBar);
	}

	ButtonShow(lvNumberButton);
	ButtonShow(lvBitrateButton);
	ButtonShow(lvNameButton);
	ButtonShow(lvLengthButton);
}

int MusicButtonProc(void)
{
	CreateSingleThread((LPTHREAD_START_ROUTINE)MusicThreadProc);

	return 0;
}

int TopArtistsPanelFrameProc(void)
{
	ShellExecute(NULL, "open", URL_TOP_ARTISTS_BROWSER, NULL, NULL, SW_SHOWNORMAL);
	return 0;
}

int TopSongsPanelFrameProc(void)
{
	ShellExecute(NULL, "open", URL_TOP_TRACKS_BROWSER, NULL, NULL, SW_SHOWNORMAL);
	return 0;
}

int TopSongsLeftProc(void)
{
	int current = GetSlidePanelsState(STATE_TOP_SONGS);
	ShowSlidePanels(STATE_TOP_SONGS, current, current - 1);
	return 0;
}

int TopSongsRightProc(void)
{
	int current = GetSlidePanelsState(STATE_TOP_SONGS);
	ShowSlidePanels(STATE_TOP_SONGS, current, current + 1);
	return 0;
}

int TopArtistsLeftProc(void)
{
	int current = GetSlidePanelsState(STATE_TOP_ARTISTS);
	ShowSlidePanels(STATE_TOP_ARTISTS, current, current - 1);
	return 0;
}

int TopArtistsRightProc(void)
{
	int current = GetSlidePanelsState(STATE_TOP_ARTISTS);
	ShowSlidePanels(STATE_TOP_ARTISTS, current, current + 1);
	return 0;
}

int MusicTrackBarProc(int pos)
{
	MusicSetPosition(musicInfo.cchannel, pos);

	return 0;
}

int VolumeTrackBarProc(int pos)
{
	musicInfo.vpos = pos;
	BASS_ChannelSetAttribute(musicInfo.cchannel, BASS_ATTRIB_VOL, (float)(musicInfo.vpos / 100.0));

	return 0;
}