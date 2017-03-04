
#define MAX_BUTTONS_COUNT 50

typedef int (*ButtonProc)(void);

typedef struct _tagButton {
	HWND hWnd; //1
	HBITMAP bmp[3]; //2
	HDC mem_hdc[3]; //3
	HFONT font; //4
	TCHAR caption[MAX_PATH]; //5
	RECT coord; //6
	RECT rcoord; //7
	RECT tdcoord; //8
	COLORREF color; //9
	BOOL repaint[4]; //10
	ButtonProc proc; //11
} tButton, *ptButton;

typedef struct _tagMenuButton {
	ptButton menuTab;
	ptButton menuActive;
} tMenuButton;

ptButton ButtonCreate(HWND hWnd, HINSTANCE hInst, TCHAR* caption, COLORREF color, TCHAR* fontname,
	int fontsize, int fontstyle, int x, int y, int width, int height, int tdelta_x, int tdelta_y,
	int btnDefault, int btnMove, int btnClick, ButtonProc btnProc);

void ButtonsUpdate(HWND hWnd, POINT pt);
void ButtonsFree(void);
void ButtonChangeText(ptButton btn, TCHAR* caption);
void ButtonChangeProc(ptButton button, ButtonProc proc);
void ButtonHide(ptButton btn);
void ButtonShow(ptButton btn);
BOOL ButtonGetVisiblity(ptButton btn);