
#include "resource.h"

/*
	
	--- LASTFM API [http://ws.audioscrobbler.com/] ---

	- chart.getTopArtists [Get the top tracks chart] [http://www.lastfm.ru/api/show/chart.getTopArtists]
		+ page (Optional) : The page number to fetch. Defaults to first page.
		+ limit (Optional) : The number of results to fetch per page. Defaults to 50.
		+ api_key (Required) : A Last.fm API key.

	- chart.chart.getTopTracks [Get the top artists chart] [http://www.lastfm.ru/api/show/chart.getTopTracks]

		+ page (Optional) : The page number to fetch. Defaults to first page.
		+ limit (Optional) : The number of results to fetch per page. Defaults to 50.
		+ api_key (Required) : A Last.fm API key.


	*** UNIC API KEY FOR NONCOMMERCIAL USING OF LASTFM API: [bce36cf9fc8190169d4391174a3d8967]

*/

#define PRNAME_SIZE 20
#define CLNAME_SIZE 50

/*------------------------------*/

typedef struct _tagbDownloadThread {
	BOOL isArtists; // ARTISTS FLAG
	BOOL isSongs; // SONGS FLAG
} tbDownloadThread;

typedef struct _tagWindowInfo {
	HINSTANCE hInst; // HINSTANCE
	HWND hWnd; // WINDOW HANDLE
	HHOOK wndMouseHook; // MOUSE HOOK
	int activeTab; // ACTIVE MENU TAB
	TCHAR szTitle[PRNAME_SIZE]; // MAIN WINDOW TITLE
	TCHAR szWindowClass[CLNAME_SIZE]; // MAIN WINDOW CLASS NAME
	tbDownloadThread bdThread; // DOWNLOAD THREAD FLAGS
	HANDLE hMutex; // MUTEX FOR ONE COPY OF APP
} tWindowInfo;

typedef struct _tagMusicInfo {
	BOOL ismp; // PAUSE
	int lpos; // LISTVIEW POSITION
	int pcount; // PLAYLISTS COUNT
	int pcurrent; // CURRENT PLAYLIST
	DWORD cchannel; // CURRENT CHANNEL
	int pscurrent; // CURRENT PLAYING PLAYLIST SONG
	int cchannel_length; // CURRENT CHANNEL LENGTH
	int cchannel_current; // CURRENT CHANNEL POSITION
	UINT_PTR mtimer; // TIMER
	BOOL isorigthumb; // ORIGINAL ALBUM COVER
	double tpercent; // SONG POSITION IN PERCENTS
	int vpos; // VOICE TRACKBAR POSITION
	TCHAR cpname[50]; // PLAYLIST NAME
	BOOL isrepeat; // REPEAT PLAYING
	BOOL israndom; // RANDOM PLAYING
	BOOL isvolume; // PRESSED VOLUME BUTTON
	BOOL ispnew; // CREATED NEW PLAYLIST
	BOOL isstart; // FIRST TRACK PLAYED
	tPlaylistFiles files; // FILES WHEN PLAYLIST LOADS FROM FILE
	int bpopen; // OPEN PLAYLIST RETURN VALUE
} tMusicInfo;
/*------------------------------*/