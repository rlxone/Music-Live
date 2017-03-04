
enum TASKBAR_BUTTONS
{
	TASKBAR_BUTTON_PREV = 1,
	TASKBAR_BUTTON_PAUSE,
	TASKBAR_BUTTON_PLAY,
	TASKBAR_BUTTON_NEXT,
	TASKBAR_BUTTON_PRANDOM,
	TASKBAR_BUTTON_PNEXT
};

HRESULT InitializeTaskBarClass(ITaskbarList3 **iTaskBar);
void TaskBarChangeValue(HWND hWnd, int percent, ITaskbarList3 *iTaskBar);
void TaskBarChangeState(HWND hWnd, int value, ITaskbarList3 *iTaskBar);
void TaskBarChangeThumbnailClip(HWND hWnd, RECT rect, ITaskbarList3 *iTaskBar);
void TaskBarChangeOverlayIcon(HWND hWnd, int iconres, HINSTANCE hInst, ITaskbarList3 *ITaskBar);
void TaskBarAddThumbButtons(HWND hWnd, LPTHUMBBUTTON button, int bcount, ITaskbarList3 *ITaskBar);
void TaskBarUpdateButtons(HWND hWnd, LPTHUMBBUTTON buttons, int count, ITaskbarList3 *iTaskBar);
THUMBBUTTON TaskBarCreateButton(HINSTANCE hInst, int iconres, THUMBBUTTONMASK dwMask, WCHAR *hint, int id);
void TaskBarChangeButtonFlags(LPTHUMBBUTTON buttons, int id, THUMBBUTTONFLAGS dwFlags);
void TaskBarChangeIcon(HWND hWnd, LPTHUMBBUTTON buttons, int count,
	int nicon, int iconres, HINSTANCE hInst, ITaskbarList3 *ITaskBar);
void DeinitializeTaskBarClass(ITaskbarList3 **iTaskBar);