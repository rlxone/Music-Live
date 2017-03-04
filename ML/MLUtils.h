
/*FONTS*/
#define FONT_NAME	    "Segoe UI"
/*------------------------------*/

/*COLORS*/
#define COLOR_PINK          0x4204e3
#define COLOR_WHITE         0xFFFFFF
#define COLOR_GRAY          0x4d4d4d
#define COLOR_LISTVIEW_TEXT 0x4e4e4e
#define COLOR_LISTVIEW_BKG  0xb7b7b7
#define COLOR_TRANSPARENT   0x000001
/*------------------------------*/

/*STATES*/
#define STATE_TOP_SONGS 1
#define STATE_TOP_ARTISTS 2
/*------------------------------*/

#define SC_DRAG 0xF012

#define MENU_TABS_COUNT   3
#define MENU_TAB_MUSIC    1
#define MENU_TAB_SONGS    2
#define MENU_TAB_SINGERS  3
#define MENU_TAB_NOACTIVE 0

#define CLIENT_WIDTH 756
#define CLIENT_HEIGHT 500
#define CLIENT_FRAME_HEIGTH 36

#define LISTVIEW_ONE_PAGE_ITEMS 15

#define MAX_TAGS_STRING 30

#define TEST_MSG(x) MessageBox(NULL, x, "", MB_OK);

void SecondsToTime(time_t seconds, TCHAR *time);
void GetNameFromTrackName(TCHAR *filename, TCHAR *trackname);
void GetNameFromPathName(TCHAR *filename, TCHAR *trackname);
void NormalizeTagString(TCHAR *str);
BOOL FileExistsA(TCHAR *filename);
BOOL FileExistsW(WCHAR *filename);
BOOL CreateRecursiveDirectory(TCHAR *folder_path);
BOOL CompareExtension(TCHAR *str, TCHAR* ext);
BOOL RectInRect(RECT rect1, RECT rect2);
int GetTextWidth(TCHAR *text, HFONT font);
void MinimizeTextName(TCHAR *text, HFONT font, int width);
RECT ClientToCenter(int x, int y);
BOOL BrowseForFolder(HWND hWnd, WCHAR *folder, int size, WCHAR *startDir, WCHAR *text, BFFCALLBACK clckProc);
BOOL BrowseForFileA(HWND hWnd, TCHAR *filename, int size, TCHAR *lpstrFilter);
BOOL BrowseForFileW(HWND hWnd, WCHAR *filename, int size, WCHAR *lpstrFilter);
BOOL BrowseForSaveFile(HWND hWnd, TCHAR *filename, int size, TCHAR *lpstrFilter);
void AddListViewColumn(HWND lhWnd, TCHAR *text, int width, int number);
void AddListViewItem(HWND lhWnd, TCHAR *text, int item, int subitem);