
#include "MODULES\libxml\parser.h"
#include "MODULES\libxml\tree.h"
#include "MODULES\libxml\encoding.h"
#include "MODULES\libxml\xmlwriter.h"

#define TOP_SONGS_COUNT 20
#define TOP_ARTISTS_COUNT 20

#define XML_LASTFM_DONE_STATUS "ok"
#define XML_LASTFM_STATUS "status"

#define XML_TOPSONGS_SONG_TAG "name"
#define XML_TOPSONGS_URL_TAG "url"
#define XML_TOPSONGS_IMAGE_TAG "image"

#define XML_TOPARTISTS_SONG_TAG "name"
#define XML_TOPARTISTS_URL_TAG "url"
#define XML_TOPARTISTS_IMAGE_TAG "image"

#define DEFAULT_ENCODING "UTF-8"

typedef struct _tagTopSongs {
	TCHAR artist[MAX_PATH];
	TCHAR song[MAX_PATH];
	TCHAR fullsong[MAX_PATH];
	TCHAR url[MAX_PATH];
	TCHAR image[4][MAX_PATH];
	TCHAR filename[MAX_PATH];
	int number;
} tTopSongs, *ptTopSongs;

typedef struct _tagTopArtists {
	TCHAR artist[MAX_PATH];
	TCHAR url[MAX_PATH];
	TCHAR image[5][MAX_PATH];
	TCHAR filename[MAX_PATH];
	int number;
	int rheigth;
} tTopArtists, *ptTopArtists;

typedef struct _tagPlaylistFiles{
	WCHAR **filenames;
	int fcount;
	TCHAR pname[50];
} tPlaylistFiles, *ptPlaylistFiles;

BOOL ParseTopSongs(TCHAR *filename);
BOOL ParseTopArtists(TCHAR *filename);

BOOL CreatePlayListFile(TCHAR *filename, int curr_playlist);
BOOL OpenPlayListFile(TCHAR *filename, HWND hWnd, HINSTANCE hInst, ptPlaylistFiles files);
BOOL CheckPlaylistsFile(xmlNodePtr root);

ptTopSongs getTopSongsArray(void);
ptTopArtists getTopArtistsArray(void);