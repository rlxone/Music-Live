
#define MAX_TRACKBARS_COUNT 5

typedef int (*TrackBarProc)(int);

typedef struct _tagTrackBar {
	HWND hWnd;
	RECT coord;
	int slwidth;
	int rwidth;
	COLORREF bkgcolor;
	COLORREF trcolor;
	COLORREF slcolor;
	int tbPos;
	BOOL ismove;
	TrackBarProc proc;
} tTrackBar, *ptTrackBar;

ptTrackBar TrackBarCreate(HWND hWnd, HINSTANCE hInst, COLORREF bkgcolor, COLORREF trcolor, COLORREF slcolor,
	int x, int y, int width, int height, int slwidth, TrackBarProc proc);
int TrackBarGetPosition(ptTrackBar trackbar);
void TrackBarSetPosition(ptTrackBar trackbar, int pos);
void TrackbarsUpdate(HWND hWnd, POINT pt);
void TrackbarsUpdateClick(HWND hWnd, POINT pt);
void TrackbarHide(ptTrackBar trackbar);
void TrackbarShow(ptTrackBar trackbar);