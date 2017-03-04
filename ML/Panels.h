
#define RECT_LEFT_TOP	  { 65, 162, 300, 151 }
#define RECT_RIGHT_TOP    { 390, 162, 300, 151 }
#define RECT_LEFT_BOTTOM  { 65, 330, 300, 151 }
#define RECT_RIGHT_BOTTOM { 390, 330, 300, 151 }

#define RECT_SONG_NUMBER  { 8, 129, 70, 146 }
#define RECT_SONG_TIMER   { 0, 0, 300, 125 }

#define COUNT_ONE_PANELS_PAGE 4

typedef int (*PanelProc)(void);

typedef struct _tagPanel {
	HWND hWnd;
	HDC back_mem_hdc[3];
	HDC bring_mem_hdc;
	HFONT font;
	char number[10];
	char caption[MAX_PATH];
	HBITMAP back_comp_dc[3];
	HBITMAP bring_comp_dc;
	HBITMAP back_bmp[3];
	HBITMAP bring_bmp;
	RECT coord;
	RECT rcoord;
	RECT tdcoord;
	PanelProc proc;
	BOOL repaint[3];
	COLORREF color;
	int delta;
	BOOL up;
	UINT_PTR timer;
	char url[MAX_PATH];
	int rheight;
} tPanel, *ptPanel;

tPanel CreatePanel(HWND hWnd, HINSTANCE hInst, int fontsize, int x, int y, int width, int height,
	char *bmp_file, int btnDefault, int btnMove, int btnClick, int number, char *song_caption, char *fontname,
	int tdelta_x, int tdelta_y, COLORREF color, PanelProc proc, char *url, int rheight);

void CreateTopSongsPanels(HINSTANCE hInst, HWND hWnd);
void CreateTopArtistsPanels(HINSTANCE hInst, HWND hWnd);
void DeleteTopSongsPanels();
void DeleteTopArtistsPanels();

void UpdatePanels(HWND hWnd, POINT pt);
void HidePanel(ptPanel btn);
void ShowPanel(ptPanel btn);
void ShowSlidePanels(int state, int current, int new_btn);
void HideSlidePanels(int state, int current);
int  GetSlidePanelsState(int state);