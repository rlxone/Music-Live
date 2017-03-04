
/*--------------------------------*/
#include "stdafx.h"
#include "Buttons.h"
/*--------------------------------*/

/*--------------------------------*/
tButton btnArray[MAX_BUTTONS_COUNT];
int btnArraySize = 0;
/*--------------------------------*/

/*--------------------------------*/
LRESULT CALLBACK btnMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
/*--------------------------------*/



ptButton ButtonCreate(HWND hWnd, HINSTANCE hInst, TCHAR* caption, COLORREF color, TCHAR* fontname,
	int fontsize, int fontstyle, int x, int y, int width, int height, int tdelta_x, int tdelta_y,
	int btnDefault, int btnMove, int btnClick, ButtonProc btnProc)
{
	int index = btnArraySize;

	btnArraySize++;

	btnArray[index].hWnd = CreateWindow(WC_BUTTON, TEXT(""), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
		x, y, width, height, hWnd, NULL, hInst, NULL);

	if (!btnArray[index].hWnd) {
		return NULL;
	}

	btnArray[index].bmp[0] = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(btnDefault));
	btnArray[index].bmp[1] = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(btnMove));
	btnArray[index].bmp[2] = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(btnClick));
	
	for (int i = 0; i < 3; ++i) {
		if (!btnArray[index].bmp[i]) {
			return NULL;
		}
	}

	btnArray[index].font = CreateFont(fontsize, 0, 0, 0, fontstyle, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, fontname);

	_tcscpy_s(btnArray[index].caption, MAX_PATH, caption);

	btnArray[index].coord.left = x; btnArray[index].coord.top = y;
	btnArray[index].coord.right = x + width; btnArray[index].coord.bottom = y + height;

	btnArray[index].rcoord.left = 0; btnArray[index].rcoord.top = 0;
	btnArray[index].rcoord.right = width; btnArray[index].rcoord.bottom = height;

	btnArray[index].tdcoord.left = 0; btnArray[index].tdcoord.top = tdelta_y;
	btnArray[index].tdcoord.right = width - tdelta_x; btnArray[index].tdcoord.bottom = height;

	btnArray[index].color = color;

	for (int i = 0; i < 4; ++i) {
		btnArray[index].repaint[i] = FALSE;
	}

	btnArray[index].proc = btnProc;

	SetWindowLong(btnArray[index].hWnd, GWL_WNDPROC, (LONG)btnMainProc);

	return &btnArray[index];
}

ptButton FindButtonHandle(HWND hWnd)
{
	for (int i = 0; i < btnArraySize; ++i) {
		if (btnArray[i].hWnd == hWnd) {
			return &(btnArray[i]);
		}
	}
	return NULL;
}

LRESULT CALLBACK btnMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	ptButton btn;
	HBITMAP hbmOld;

	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		btn = FindButtonHandle(hWnd);
		if (btn != NULL && !btn->repaint[1] && !btn->repaint[3]) {
			btn->repaint[0] = TRUE; btn->repaint[1] = TRUE; btn->repaint[2] = FALSE;
			InvalidateRect(hWnd, &btn->rcoord, TRUE);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		btn = FindButtonHandle(hWnd);

		if (btn != NULL) {
			if (btn->repaint[3]) {
				btn->mem_hdc[2] = CreateCompatibleDC(hdc);
				hbmOld = SelectObject(btn->mem_hdc[2], btn->bmp[2]);
				BitBlt(hdc, 0, 0, btn->rcoord.right, btn->rcoord.bottom, btn->mem_hdc[2], 0, 0, SRCCOPY);
				SelectObject(btn->mem_hdc[2], hbmOld);
				DeleteDC(btn->mem_hdc[2]);
			} else {
				if (btn->repaint[1]) {
					btn->mem_hdc[1] = CreateCompatibleDC(hdc);
					hbmOld = SelectObject(btn->mem_hdc[1], btn->bmp[1]);
					BitBlt(hdc, 0, 0, btn->rcoord.right, btn->rcoord.bottom, btn->mem_hdc[1], 0, 0, SRCCOPY);
					SelectObject(btn->mem_hdc[1], hbmOld); 
					DeleteDC(btn->mem_hdc[1]);
				}
				else {
					if (!btn->repaint[0]) {
						btn->mem_hdc[0] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(btn->mem_hdc[0], btn->bmp[0]);
						BitBlt(hdc, 0, 0, btn->rcoord.right, btn->rcoord.bottom, btn->mem_hdc[0], 0, 0, SRCCOPY);
						SelectObject(btn->mem_hdc[0], hbmOld);
						DeleteDC(btn->mem_hdc[0]);
					}
					else {
						btn->mem_hdc[2] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(btn->mem_hdc[2], btn->bmp[2]);
						BitBlt(hdc, 0, 0, btn->rcoord.right, btn->rcoord.bottom, btn->mem_hdc[2], 0, 0, SRCCOPY);
						SelectObject(btn->mem_hdc[2], hbmOld);
						DeleteDC(btn->mem_hdc[2]);
					}
				}
			}
		} else {
			return 0;
		}

		if (_tcscmp(btn->caption, TEXT("")) != 0) {
			SetTextColor(hdc, btn->color); SetBkMode(hdc, TRANSPARENT); SelectObject(hdc, btn->font);
			DrawText(hdc, btn->caption, _tcslen(btn->caption), &btn->tdcoord, DT_NOCLIP | DT_SINGLELINE | DT_CENTER);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		btn = FindButtonHandle(hWnd);
		if (btn != NULL) {
			btn->repaint[0] = TRUE; btn->repaint[1] = FALSE; btn->repaint[2] = TRUE; btn->repaint[3] = TRUE;
			InvalidateRect(hWnd, &btn->rcoord, TRUE);
		}
		break;
	case WM_LBUTTONUP:
		btn = FindButtonHandle(hWnd);
		if (btn != NULL) {
			btn->repaint[0] = TRUE; btn->repaint[1] = TRUE; btn->repaint[2] = FALSE; btn->repaint[3] = FALSE;
			InvalidateRect(hWnd, &btn->rcoord, TRUE);
		}
		if (btn->proc) {
			btn->proc();
		}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void ButtonChangeText(ptButton btn, TCHAR* caption)
{
	_tcscpy_s(btn->caption, MAX_PATH, caption);
	btn->repaint[0] = TRUE;
	InvalidateRect(btn->hWnd, &btn->coord, FALSE);
}

void ButtonHide(ptButton btn)
{
	ShowWindow(btn->hWnd, SW_HIDE);
}

void ButtonShow(ptButton btn)
{
	ShowWindow(btn->hWnd, SW_SHOW);
}

BOOL ButtonGetVisiblity(ptButton btn)
{
	return IsWindowVisible(btn->hWnd);
}

void ButtonChangeProc(ptButton button, ButtonProc proc)
{
	for (int i = 0; i < btnArraySize; ++i) {
		if (&btnArray[i] == button) {
			btnArray[i].proc = proc;
			break;
		}
	}
}

void ButtonsUpdate(HWND hWnd, POINT pt)
{
	for (int i = 0; i < btnArraySize; ++i) {
		if (btnArray[i].repaint[0]) {
			ScreenToClient(hWnd, &pt);
			if (!PtInRect(&btnArray[i].coord, pt)) {
				for (int j = 0; j < 4; ++j) {
					btnArray[i].repaint[j] = FALSE;
				}
				InvalidateRect(btnArray[i].hWnd, NULL, FALSE);
			}
		}
	}
}

void ButtonsFree(void)
{
	for (int i = 0; i < btnArraySize; ++i) {
		for (int j = 0; j < 3; ++j) {
			DeleteObject(btnArray[i].bmp[j]);
			DeleteDC(btnArray[i].mem_hdc[j]);
		}
		DeleteObject(btnArray[i].font);
	}
}