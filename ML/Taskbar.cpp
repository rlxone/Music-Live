
#include "stdafx.h"
#include "TaskBar.h"

THUMBBUTTON TaskBarCreateButton(HINSTANCE hInst, int iconres, THUMBBUTTONMASK dwMask, WCHAR *hint, int id)
{
	THUMBBUTTON button;
	
	button.dwMask = dwMask;
	button.dwFlags = THBF_ENABLED;
	button.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(iconres));
	button.iId = id;
	wcscpy_s(button.szTip, sizeof(button.szTip), hint);

	return button;
}

void TaskBarChangeButtonFlags(LPTHUMBBUTTON buttons, int id, THUMBBUTTONFLAGS dwFlags)
{
	buttons[id - 1].dwFlags = dwFlags;
}

HRESULT InitializeTaskBarClass(ITaskbarList3 **iTaskBar)
{
	HRESULT hr = CoCreateInstance((const IID* const) &CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER,
		                          (const IID* const) &IID_ITaskbarList3,
		                          (LPVOID) &(*iTaskBar));
	return (*iTaskBar)->lpVtbl->HrInit(*iTaskBar);
}

void TaskBarChangeValue(HWND hWnd, int percent, ITaskbarList3 *iTaskBar)
{
	iTaskBar->lpVtbl->SetProgressValue(iTaskBar, hWnd, percent, 100);
}

void TaskBarChangeState(HWND hWnd, int value, ITaskbarList3 *iTaskBar)
{
	iTaskBar->lpVtbl->SetProgressState(iTaskBar, hWnd, value);	
}

void TaskBarChangeThumbnailClip(HWND hWnd, RECT rect, ITaskbarList3 *iTaskBar)
{
	iTaskBar->lpVtbl->SetThumbnailClip(iTaskBar, hWnd, &rect);
}

void TaskBarChangeOverlayIcon(HWND hWnd, int iconres, HINSTANCE hInst, ITaskbarList3 *ITaskBar)
{
	ITaskBar->lpVtbl->SetOverlayIcon(ITaskBar, hWnd, LoadIcon(hInst, MAKEINTRESOURCE(iconres)), L"");
}

void TaskBarAddThumbButtons(HWND hWnd, LPTHUMBBUTTON buttons, int bcount, ITaskbarList3 *ITaskBar)
{
	ITaskBar->lpVtbl->ThumbBarAddButtons(ITaskBar, hWnd, bcount, buttons);
}

void TaskBarUpdateButtons(HWND hWnd, LPTHUMBBUTTON buttons, int count, ITaskbarList3 *iTaskBar)
{
	iTaskBar->lpVtbl->ThumbBarUpdateButtons(iTaskBar, hWnd, count, buttons);
}

void TaskBarChangeIcon(HWND hWnd, LPTHUMBBUTTON buttons, int count, 
	                   int nicon, int iconres, HINSTANCE hInst, ITaskbarList3 *ITaskBar)
{
	DeleteObject(buttons[nicon - 1].hIcon);
	buttons[nicon - 1].hIcon = LoadIcon(hInst, MAKEINTRESOURCE(iconres));
	TaskBarUpdateButtons(hWnd, buttons, count, ITaskBar);
}

void DeinitializeTaskBarClass(ITaskbarList3 **iTaskBar)
{
	(*iTaskBar)->lpVtbl->Release(*iTaskBar);
}