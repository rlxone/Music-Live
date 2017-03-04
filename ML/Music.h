
#include "MODULES\bass\bass.h"
#include "MODULES\id3v2lib\id3v2lib.h"
#include "MLConvertImage.h"

#define MAX_MUSIC_TAG_PATH 30
#define MAX_PREV_SECONDS 5
#define MAX_GENRES_COUNT 191

typedef int(*SearchProc)(int);

typedef struct _tagPartID3v1 /* LAST SYMBOL FOR '\0' */{
	TCHAR artist[MAX_MUSIC_TAG_PATH + 1]; 
	TCHAR title[MAX_MUSIC_TAG_PATH + 1];
	TCHAR album[MAX_MUSIC_TAG_PATH + 1];
	TCHAR comment[MAX_MUSIC_TAG_PATH + 1];
	TCHAR year[5];
	TCHAR id[4];
	BYTE genre;
} tPartID3v1, *ptPartID3v1;

typedef struct _tagPartID3v2 {
	TCHAR artist[MAX_MUSIC_TAG_PATH];
	TCHAR title[MAX_MUSIC_TAG_PATH];
	ID3v2_frame_apic_content *apic;
} tPartID3v2, *ptPartID3v2;

typedef struct _tagListViewData {
	TCHAR number[10];
	TCHAR trackname[MAX_PATH];
	TCHAR bitrate[15];
	TCHAR length[12];
} tListViewData, *ptListViewData;

typedef struct _tagPlayListData {
	BOOL isvtags; //VALID TAGS
	int isaligment; //--TO STRIP
	WCHAR wfilename[MAX_PATH]; //WIDECHAR FILENAME
	TCHAR filename[MAX_PATH]; //CHAR FILENAME [UTF-8]
	TCHAR mfilename[MAX_PATH]; //CHAR FILENAME [MB]
	tListViewData ldata; //LISTVIEW DATA STRUCTURE
	tPartID3v1 id3v1; //ID3V1 TAGS STRUCTURE
	tPartID3v2 id3v2; //ID3V2 TAGS STRUCTURE
} tPlayListData, *ptPlayListData;

typedef struct _tagMLListView {
	HWND listView; //LISTVIEW HANDLE
	HFONT lfont; //LISTVIEW FONT
	int pos; //LISTVIEW POSITON [FOR SCROLLING]
	BOOL isscrollbar; //SCROLLBAR STATE
	int spos; //SCROLLBAR POSITION
	int cpos; //LAST PLAYED SONG POS IN LISTVIEW
} tMLListView;

typedef struct _tagPlaylist {
	ptPlayListData pdata; //PLAYLIST DATA STRUCTURE
	tMLListView mlListView; //LISTVIEW STRUCTURE
	int pcount; //SONGS COUNT
	long long int plength; //SONGS LENGTH
	TCHAR name[50]; //PLAYLIST NAME
} tPlayList, *ptPlayList;

typedef struct _tagTime {
	DWORD hours;
	DWORD minutes;
	DWORD seconds;
} tTime;

enum CreatePlaylistReturnCode {
	CP_EMPTY_STRING = 1,
	CP_COMPARE_STRING,
	CP_ALLOK
};

void SearchMusicInFolder(HWND hWnd, WCHAR *folder, SearchProc proc, int curr_playlist);
void SearchMusicInFile(HWND hWnd, WCHAR *filename, SearchProc proc, int curr_playlist);
ptPlayList GetPlayLists();
HSTREAM MusicPlay(HWND hWnd, WCHAR *filename, BOOL isBassInit, HSTREAM currentChannel);
HSYNC MusicSetSyncProc(HCHANNEL channel, SYNCPROC cproc, DWORD type);
BOOL GetThumbnailImage(WCHAR *filename, TCHAR *imagedata, int imagesize, int imagewidth, int imageheight);
BOOL GetMP3AlbumCover(WCHAR *filename, WCHAR *outfilename, int imagewidth);
void SecondsToTime(time_t seconds, TCHAR *time);
BOOL MusicSetPosition(HCHANNEL channel, int percent);
int CreatePlaylist(TCHAR *name, HWND hWnd, HINSTANCE hInst);
void GetMusicGenre(int genre, TCHAR *sgenre, int ssize);
int GetMusicGenreIndex(TCHAR *sgenre);
BOOL SetMP3ID3v1Tags(int curr_playlist, int curr_song, tPartID3v1 tags);
BOOL CheckValidTags(TCHAR *artist, TCHAR *title);