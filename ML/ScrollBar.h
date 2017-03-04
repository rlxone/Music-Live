
#define MAX_SCROLLBARS_COUNT 5

typedef int(*ScrollBarProc)(int);

typedef struct _tagScrollBar {
	HWND hWnd;
	RECT coord;
	int slwidth;
	int slheight;
	int rheigth;
	COLORREF bkgcolor;
	COLORREF trcolor;
	COLORREF slcolor;
	int scPos;
	BOOL ismove;
	ScrollBarProc proc;
} tScrollBar, *ptScrollBar;

ptScrollBar ScrollBarCreate(HWND hWnd, HINSTANCE hInst, COLORREF bkgcolor, COLORREF trcolor, COLORREF slcolor,
	int x, int y, int width, int height, int slheight, ScrollBarProc proc);
int ScrollBarGetPosition(ptScrollBar scrollbar);
void ScrollBarSetPosition(ptScrollBar scrollbar, int pos);
void ScrollBarsUpdate(HWND hWnd, POINT pt);
void ScrollBarsUpdateClick(HWND hWnd, POINT pt);
void ScrollBarHide(ptScrollBar scrollbar);
void ScrollBarShow(ptScrollBar scrollbar);