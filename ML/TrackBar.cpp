
#include "stdafx.h"
#include "TrackBar.h"

LRESULT CALLBACK trackbarMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

tTrackBar tbArray[MAX_TRACKBARS_COUNT];
int tbArraySize = 0;

ptTrackBar TrackBarCreate(HWND hWnd, HINSTANCE hInst, COLORREF bkgcolor, COLORREF trcolor, COLORREF slcolor,
	int x, int y, int width, int height, int slwidth, TrackBarProc proc)
{

	int index = tbArraySize++;

	tbArray[index].hWnd = CreateWindow(WC_BUTTON, TEXT(""), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
		x, y, width, height, hWnd, NULL, hInst, NULL);

	if (!tbArray[index].hWnd) {
		return NULL;
	}

	SetRect(&tbArray[index].coord, x, y, x + width, y + height);

	tbArray[index].slwidth = slwidth;
	tbArray[index].rwidth = tbArray[index].coord.right - tbArray[index].coord.left - tbArray[index].slwidth;

	tbArray[index].bkgcolor = bkgcolor;
	tbArray[index].trcolor = trcolor;
	tbArray[index].slcolor = slcolor;
	tbArray[index].tbPos = 0;
	tbArray[index].ismove = FALSE;
	tbArray[index].proc = proc;

	SetWindowLong(tbArray[index].hWnd, GWL_WNDPROC, (LONG)trackbarMainProc);

	return (&tbArray[index]);
}

ptTrackBar FindTrackBarInArray(HWND hWnd)
{
	for (int i = 0; i < tbArraySize; ++i) {
		if (hWnd == tbArray[i].hWnd) {
			return (&tbArray[i]);
		}
	}

	return NULL;
}

void TrackbarsUpdate(HWND hWnd, POINT pt)
{
	for (int i = 0; i < tbArraySize; ++i) {
		if (tbArray[i].ismove) {
			RECT rect;
			ScreenToClient(hWnd, &pt);
			if (pt.x < tbArray[i].coord.left) {
				SetRect(&rect, 0, 0, tbArray[i].coord.right - tbArray[i].coord.left, tbArray[i].coord.bottom - tbArray[i].coord.top);
				tbArray[i].tbPos = 0;
				InvalidateRect(tbArray[i].hWnd, &rect, FALSE);
				tbArray[i].proc(0);
				break;
			} else {
				if (pt.x > tbArray[i].coord.right) {
					SetRect(&rect, 0, 0, tbArray[i].coord.right - tbArray[i].coord.left, tbArray[i].coord.bottom - tbArray[i].coord.top);
					tbArray[i].tbPos = tbArray[i].coord.right - tbArray[i].coord.left - tbArray[i].slwidth;
					InvalidateRect(tbArray[i].hWnd, &rect, FALSE);
					tbArray[i].proc(100);
					break;
				}
				if (pt.x >= tbArray[i].coord.left && pt.x <= tbArray[i].coord.right) {
					SetRect(&rect, 0, 0, tbArray[i].coord.right - tbArray[i].coord.left, tbArray[i].coord.bottom - tbArray[i].coord.top);
					tbArray[i].tbPos = (pt.x - tbArray[i].coord.left) * (tbArray[i].coord.right - tbArray[i].coord.left - tbArray[i].slwidth) / (tbArray[i].coord.right - tbArray[i].coord.left);
					InvalidateRect(tbArray[i].hWnd, &rect, FALSE);
					tbArray[i].proc((int)((double)(tbArray[i].tbPos / (double)(tbArray[i].coord.right - tbArray[i].coord.left - tbArray[i].slwidth)) * 100));
					break;
				}
			}
		}
	}
}

void TrackbarsUpdateClick(HWND hWnd, POINT pt)
{
	for (int i = 0; i < tbArraySize; ++i) {
		if (tbArray[i].ismove) {
			tbArray[i].ismove = FALSE;
			TrackbarsUpdate(hWnd, pt);
			break;
		}
	}
}

LRESULT CALLBACK trackbarMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ptTrackBar trackBar;
	PAINTSTRUCT ps;
	HDC hdc;
	HPEN hPen;
	int xPos;
	RECT rect;
	HBRUSH hBrush;
	HDC hMemDC;
	HBITMAP hbmBitmap, holdBitmap;

	switch (uMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		trackBar = FindTrackBarInArray(hWnd);

		if (trackBar) {
			hMemDC = CreateCompatibleDC(hdc);
			hbmBitmap = CreateCompatibleBitmap(hdc, trackBar->coord.right - trackBar->coord.left, trackBar->coord.bottom - trackBar->coord.top);

			holdBitmap = SelectObject(hMemDC, hbmBitmap);

			hPen = CreatePen(PS_SOLID, 1, trackBar->bkgcolor);
			hBrush = CreateSolidBrush(trackBar->bkgcolor);

			SetBkColor(hMemDC, trackBar->bkgcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, 0, 0, trackBar->coord.right - trackBar->coord.left, trackBar->coord.bottom - trackBar->coord.top);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			hPen = CreatePen(PS_SOLID, 1, trackBar->trcolor);
			hBrush = CreateSolidBrush(trackBar->trcolor);

			SetBkColor(hMemDC, trackBar->trcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, 0, 0, trackBar->tbPos, trackBar->coord.bottom - trackBar->coord.top);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			hPen = CreatePen(PS_SOLID, 1, trackBar->slcolor);
			hBrush = CreateSolidBrush(trackBar->slcolor);

			SetBkColor(hMemDC, trackBar->slcolor);
			SelectObject(hMemDC, hPen);
			SelectObject(hMemDC, hBrush);

			Rectangle(hMemDC, trackBar->tbPos, 0, trackBar->tbPos + trackBar->slwidth, trackBar->coord.bottom - trackBar->coord.top);

			DeleteObject(hPen);
			DeleteObject(hBrush);

			BitBlt(hdc, 0, 0, trackBar->coord.right - trackBar->coord.left, trackBar->coord.bottom - trackBar->coord.top, hMemDC, 0, 0, SRCCOPY);

			SelectObject(hMemDC, holdBitmap);

			DeleteObject(hbmBitmap);
			DeleteDC(hMemDC);
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		trackBar = FindTrackBarInArray(hWnd);
		if (trackBar) {
			if (trackBar->ismove) {
				xPos = GET_X_LPARAM(lParam);
				SetRect(&rect, 0, 0, trackBar->coord.right - trackBar->coord.left, trackBar->coord.bottom - trackBar->coord.top);
				trackBar->tbPos = xPos * (trackBar->coord.right - trackBar->coord.left - trackBar->slwidth) / (trackBar->coord.right - trackBar->coord.left);
				InvalidateRect(hWnd, &rect, FALSE);
				trackBar->proc((int)((double)(trackBar->tbPos / (double)(trackBar->coord.right - trackBar->coord.left - trackBar->slwidth)) * 100));
			}
		}
		break;
	case WM_LBUTTONDOWN:
		trackBar = FindTrackBarInArray(hWnd);
		if (trackBar) {
			xPos = GET_X_LPARAM(lParam);
			SetRect(&rect, 0, 0, trackBar->coord.right - trackBar->coord.left, trackBar->coord.bottom - trackBar->coord.top);
			trackBar->tbPos = xPos * (trackBar->coord.right - trackBar->coord.left - trackBar->slwidth) / (trackBar->coord.right - trackBar->coord.left);
			InvalidateRect(hWnd, &rect, FALSE);
			trackBar->proc((int)((double)(trackBar->tbPos / (double)(trackBar->coord.right - trackBar->coord.left - trackBar->slwidth)) * 100));
			trackBar->ismove = TRUE;
		}
		break;
	case WM_LBUTTONUP:
		trackBar = FindTrackBarInArray(hWnd);
		if (trackBar) {
			//trackBar->proc(((double)(trackBar->tbPos / (double)(trackBar->coord.right - trackBar->coord.left - trackBar->slwidth)) * 100));
			trackBar->ismove = FALSE;
		}
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void TrackbarHide(ptTrackBar trackbar)
{
	ShowWindow(trackbar->hWnd, SW_HIDE);
}

void TrackbarShow(ptTrackBar trackbar)
{
	ShowWindow(trackbar->hWnd, SW_SHOW);
}

int TrackBarGetPosition(ptTrackBar trackbar)
{
	for (int i = 0; i < tbArraySize; ++i) {
		if (trackbar == (&tbArray[i])) {
			double percent = (tbArray[i].tbPos * 100.0 / tbArray[i].rwidth);
			return (percent - (int)percent >= 0.5) ? (int)percent + 1 : (int)percent;
		}
	}
	return 0;
}

void TrackBarSetPosition(ptTrackBar trackbar, int pos)
{
	for (int i = 0; i < tbArraySize; ++i) {
		if (trackbar == (&tbArray[i])) {
			double percent = (double)pos * (double)tbArray[i].rwidth / 100;
			RECT rect = { 0, 0, tbArray[i].coord.right - tbArray[i].coord.left, tbArray[i].coord.bottom - tbArray[i].coord.top };
			if (pos == 0) {
				tbArray[i].tbPos = 0;
			}
			else {
				if (pos == 100) {
					tbArray[i].tbPos = (int)percent;
				}
				else {
					tbArray[i].tbPos = (int)percent + 1;
				}
			}
			InvalidateRect(tbArray[i].hWnd, &rect, FALSE);
			break;
		}
	}
}