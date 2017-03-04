
/*ALIGMENT на ALIGNMENT*/

#define MAX_LABELS_COUNT 50

typedef struct _tagLabel {
	HDC mem_dc;
	HBITMAP bmp;
	HWND parent;
	HFONT font;
	RECT coord;
	TCHAR caption[MAX_PATH];
	COLORREF color;
	COLORREF bkgcolor;
	int aligment;
	BOOL alalign;
	BOOL ishide;
	DWORD timer;
	int delta;
	int width;
} tLabel, *ptLabel;

ptLabel LabelCreate(HWND hWnd, HINSTANCE hInst, TCHAR* caption, COLORREF color, COLORREF bkgcolor, TCHAR* fontname, int fontsize, int alignment,
	int fnHeight, int x, int y, int width, int height, int bkgres);
void LabelChangeText(ptLabel label, TCHAR *text);
void LabelsUpdate(HDC hdc);
void LabelHide(ptLabel label);
void LabelShow(ptLabel label);