
#include "stdafx.h"
#include "ScrollBar.h"

LRESULT CALLBACK scrollbarMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

tScrollBar scArray[MAX_SCROLLBARS_COUNT];
int scArraySize = 0;

ptScrollBar ScrollBarCreate(HWND hWnd, HINSTANCE hInst, COLORREF bkgcolor, COLORREF trcolor, COLORREF slcolor,
	int x, int y, int width, int height, int slheight, ScrollBarProc proc)
{

	int index = scArraySize++;

	scArray[index].hWnd = CreateWindow(WC_BUTTON, TEXT(""), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
		x, y, width, height, hWnd, NULL, hInst, NULL);

	if (!scArray[index].hWnd) {
		return NULL;
	}

	SetRect(&scArray[index].coord, x, y, x + width, y + height);

	scArray[index].slheight = slheight;
	scArray[index].rheigth = scArray[index].coord.bottom - scArray[index].coord.top - scArray[index].slheight;

	scArray[index].bkgcolor = bkgcolor;
	scArray[index].trcolor = trcolor;
	scArray[index].slcolor = slcolor;
	scArray[index].scPos = 0;
	scArray[index].ismove = FALSE;
	scArray[index].proc = proc;

	SetWindowLong(scArray[index].hWnd, GWL_WNDPROC, (LONG)scrollbarMainProc);

	return (&scArray[index]);
}

ptScrollBar FindScrollBarInArray(HWND hWnd)
{
	for (int i = 0; i < scArraySize; ++i) {
		if (hWnd == scArray[i].hWnd) {
			return (&scArray[i]);
		}
	}

	return NULL;
}

void ScrollBarsUpdate(HWND hWnd, POINT pt)
{
	for (int i = 0; i < scArraySize; ++i) {
		if (scArray[i].ismove) {
			RECT rect;
			ScreenToClient(hWnd, &pt);
			if (pt.y < scArray[i].coord.top) {
				SetRect(&rect, 0, 0, scArray[i].coord.right - scArray[i].coord.left, scArray[i].coord.bottom - scArray[i].coord.top);
				scArray[i].scPos = 0;
				InvalidateRect(scArray[i].hWnd, &rect, FALSE);
				scArray[i].proc(0);
				break;
			}
			else {
				if (pt.y > scArray[i].coord.bottom) {
					SetRect(&rect, 0, 0, scArray[i].coord.right - scArray[i].coord.left, scArray[i].coord.bottom - scArray[i].coord.top);
					scArray[i].scPos = scArray[i].coord.bottom - scArray[i].coord.top - scArray[i].slheight;
					InvalidateRect(scArray[i].hWnd, &rect, FALSE);
					scArray[i].proc(100);
					break;
				}
				if (pt.y >= scArray[i].coord.top && pt.y <= scArray[i].coord.bottom) {
					SetRect(&rect, 0, 0, scArray[i].coord.right - scArray[i].coord.left, scArray[i].coord.bottom - scArray[i].coord.top);
					scArray[i].scPos = (pt.y - scArray[i].coord.top) * (scArray[i].coord.bottom - scArray[i].coord.top - scArray[i].slheight) / (scArray[i].coord.bottom - scArray[i].coord.top);
					InvalidateRect(scArray[i].hWnd, &rect, FALSE);
					scArray[i].proc((int)((double)(scArray[i].scPos / (double)(scArray[i].coord.bottom - scArray[i].coord.top - scArray[i].slheight)) * 100));
					break;
				}
			}
		}
	}
}

void ScrollBarsUpdateClick(HWND hWnd, POINT pt)
{
	for (int i = 0; i < scArraySize; ++i) {
		if (scArray[i].ismove) {
			scArray[i].ismove = FALSE;
			ScrollBarsUpdate(hWnd, pt);
			break;
		}
	}
}

void ScrollBarSetPosition(ptScrollBar trackbar, int pos)
{
	for (int i = 0; i < scArraySize; ++i) {
		if (trackbar == (&scArray[i])) {
			double percent = (double)pos * (double)scArray[i].rheigth / 100.0;
			RECT rect = { 0, 0, scArray[i].coord.right - scArray[i].coord.left, scArray[i].coord.bottom - scArray[i].coord.top };
			if (pos < 0) {
				scArray[i].scPos = 0;
			}
			else {
				if (pos >= 100) {
					scArray[i].scPos = (int) percent;
				}
				else {
					scArray[i].scPos = (int) percent + 1;
				}
			}
			InvalidateRect(scArray[i].hWnd, &rect, FALSE);
			break;
		}
	}
}

int ScrollBarGetPosition(ptScrollBar scrollbar)
{
	for (int i = 0; i < scArraySize; ++i) {
		if (scrollbar == (&scArray[i])) {
			double percent = (scArray[i].scPos * 100.0 / scArray[i].rheigth);
			return  (percent - (int)percent >= 0.5) ? (int)percent + 1 : (int)percent;
		}
	}
	return 0;
}

LRESULT CALLBACK scrollbarMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ptScrollBar scrollBar;
	PAINTSTRUCT ps;
	HDC hdc;
	HPEN hPen;
	int yPos;
	RECT rect;
	HBRUSH hBrush;
	HDC hMemDC;
	HBITMAP hbmBitmap, holdBitmap;

	switch (uMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		scrollBar = FindScrollBarInArray(hWnd);

		if (scrollBar) {
			hMemDC = CreateCompatibleDC(hdc);
			hbmBitmap = CreateCompatibleBitmap(hdc, scrollBar->coord.right - scrollBar->coord.left, scrollBar->coord.bottom - scrollBar->coord.top);

			holdBitmap = SelectObject(hMemDC, hbmBitmap);

			hPen = CreatePen(PS_SOLID, 1, scrollBar->bkgcolor);
			hBrush = CreateSolidBrush(scrollBar->bkgcolor);

			SetBkColor(hMemDC, scrollBar->bkgcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, 0, 0, scrollBar->coord.right - scrollBar->coord.left, scrollBar->coord.bottom - scrollBar->coord.top);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			hPen = CreatePen(PS_SOLID, 1, scrollBar->trcolor);
			hBrush = CreateSolidBrush(scrollBar->trcolor);

			SetBkColor(hMemDC, scrollBar->trcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, 0, 0, scrollBar->coord.right - scrollBar->coord.left, scrollBar->scPos);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			hPen = CreatePen(PS_SOLID, 1, scrollBar->slcolor);
			hBrush = CreateSolidBrush(scrollBar->slcolor);

			SetBkColor(hMemDC, scrollBar->slcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, 0, scrollBar->scPos, scrollBar->coord.right - scrollBar->coord.left, scrollBar->scPos + scrollBar->slheight);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			BitBlt(hdc, 0, 0, scrollBar->coord.right - scrollBar->coord.left, scrollBar->coord.bottom - scrollBar->coord.top, hMemDC, 0, 0, SRCCOPY);

			SelectObject(hMemDC, holdBitmap);

			DeleteObject(hbmBitmap);
			DeleteDC(hMemDC);
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		scrollBar = FindScrollBarInArray(hWnd);
		if (scrollBar) {
			if (scrollBar->ismove) {
				yPos = GET_Y_LPARAM(lParam);
				SetRect(&rect, 0, 0, scrollBar->coord.right - scrollBar->coord.left, scrollBar->coord.bottom - scrollBar->coord.top);
				scrollBar->scPos = yPos * (scrollBar->coord.bottom - scrollBar->coord.top - scrollBar->slheight) / (scrollBar->coord.bottom - scrollBar->coord.top);
				InvalidateRect(hWnd, &rect, FALSE);
				scrollBar->proc((int)(((double)(scrollBar->scPos / (double)(scrollBar->coord.bottom - scrollBar->coord.top - scrollBar->slheight)) * 100)));
			}
		}
		break;
	case WM_LBUTTONDOWN:
		scrollBar = FindScrollBarInArray(hWnd);
		if (scrollBar) {
			yPos = GET_Y_LPARAM(lParam);
			SetRect(&rect, 0, 0, scrollBar->coord.right - scrollBar->coord.left, scrollBar->coord.bottom - scrollBar->coord.top);
			scrollBar->scPos = yPos * (scrollBar->coord.bottom - scrollBar->coord.top - scrollBar->slheight) / (scrollBar->coord.bottom - scrollBar->coord.top);
			InvalidateRect(hWnd, &rect, FALSE);
			scrollBar->proc((int)((double)(scrollBar->scPos / (double)(scrollBar->coord.bottom - scrollBar->coord.top - scrollBar->slheight)) * 100));
			scrollBar->ismove = TRUE;
		}
		break;
	case WM_LBUTTONUP:
		scrollBar = FindScrollBarInArray(hWnd);
		if (scrollBar) {
			scrollBar->ismove = FALSE;
		}
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void ScrollBarHide(ptScrollBar scrollbar)
{
	ShowWindow(scrollbar->hWnd, SW_HIDE);
}

void ScrollBarShow(ptScrollBar scrollbar)
{
	ShowWindow(scrollbar->hWnd, SW_SHOW);
}