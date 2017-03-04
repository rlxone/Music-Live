
#include "stdafx.h"
#include "Panels.h"
#include "XML_Parsing.h"
#include "MLUtils.h"

tPanel pSongsPanels[TOP_SONGS_COUNT];
tPanel pArtistsPanels[TOP_ARTISTS_COUNT];
int curTopSongs = 0, curTopArtists = 0;

LRESULT CALLBACK panelMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void DeleteTopSongsPanels()
{
	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		if (pSongsPanels[i].hWnd != INVALID_HANDLE_VALUE) {
			if (pSongsPanels[i].bring_bmp) {
				DeleteObject(pSongsPanels[i].bring_bmp);
			}
			for (int j = 0; j < 3; ++j) {
				DeleteObject(pSongsPanels[i].back_bmp[j]);
				DeleteDC(pSongsPanels[i].back_mem_hdc[j]);
			}
			DeleteDC(pSongsPanels[i].bring_mem_hdc);
			DestroyWindow(pSongsPanels[i].hWnd);
		}
	}
}

void DeleteTopArtistsPanels()
{
	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		if (pArtistsPanels[i].hWnd != INVALID_HANDLE_VALUE) {
			if (pArtistsPanels[i].bring_bmp) {
				DeleteObject(pArtistsPanels[i].bring_bmp);
			}
			for (int j = 0; j < 3; ++j) {
				DeleteObject(pArtistsPanels[i].back_bmp[j]);
				DeleteDC(pArtistsPanels[i].back_mem_hdc[j]);
			}
			DeleteDC(pArtistsPanels[i].bring_mem_hdc);
			DestroyWindow(pArtistsPanels[i].hWnd);
		}
	}
}

void CreateTopSongsPanels(HINSTANCE hInst, HWND hWnd)
{
	const RECT rect[4] = { RECT_LEFT_TOP, RECT_RIGHT_TOP, RECT_LEFT_BOTTOM, RECT_RIGHT_BOTTOM };
	int ind = 0;
	BOOL isHide = FALSE;

	ptTopSongs pSongsArray = getTopSongsArray();

	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		pSongsPanels[i] = CreatePanel(hWnd, hInst,
			18, rect[ind].left, rect[ind].top, rect[ind].right, rect[ind].bottom,
			pSongsArray[i].filename, BMP_PANEL_DEFAULT, BMP_PANEL_MOVE, BMP_PANEL_CLICK, i + 1,
			pSongsArray[i].fullsong, "Segoe UI", 0, 129, 0xFFFFFF, NULL, pSongsArray[i].url, 300);
		if (isHide)
			HidePanel(&(pSongsPanels[i]));
		ind++;
		if (ind == 4) {
			ind = 0;
			isHide = TRUE;
		}
	}
}

void CreateTopArtistsPanels(HINSTANCE hInst, HWND hWnd)
{
	const RECT rect[4] = { RECT_LEFT_TOP, RECT_RIGHT_TOP, RECT_LEFT_BOTTOM, RECT_RIGHT_BOTTOM };
	int ind = 0;
	BOOL isHide = FALSE;

	ptTopArtists pArtistsArray = getTopArtistsArray();

	for (int i = 0; i < TOP_ARTISTS_COUNT; ++i) {
		pArtistsPanels[i] = CreatePanel(hWnd, hInst,
			18, rect[ind].left, rect[ind].top, rect[ind].right, rect[ind].bottom,
			pArtistsArray[i].filename, BMP_PANEL_DEFAULT, BMP_PANEL_MOVE, BMP_PANEL_CLICK, i + 1,
			pArtistsArray[i].artist, "Segoe UI", 0, 129, 0xFFFFFF, NULL, pArtistsArray[i].url,
			pArtistsArray[i].rheigth);
		if (isHide) {
			HidePanel(&(pArtistsPanels[i]));
		}
		ind++;
		if (ind == 4) {
			ind = 0;
			isHide = TRUE;
		}
	}
}

tPanel CreatePanel(HWND hWnd, HINSTANCE hInst, int fontsize, int x, int y, int width, int height,
	char *bmp_file, int btnDefault, int btnMove, int btnClick, int number, char *song_caption, char *fontname,
	int tdelta_x, int tdelta_y, COLORREF color, PanelProc proc, char *url, int rheight)
{
	tPanel result;

	result.hWnd = CreateWindow(TEXT("BUTTON"), TEXT(""), WS_CHILD | BS_OWNERDRAW,
		                       x, y, width, height, hWnd, NULL, hInst, NULL);

	result.back_bmp[0] = (HBITMAP) LoadBitmap(hInst, MAKEINTRESOURCE(btnDefault));
	result.back_bmp[1] = (HBITMAP) LoadBitmap(hInst, MAKEINTRESOURCE(btnMove));
	result.back_bmp[2] = (HBITMAP) LoadBitmap(hInst, MAKEINTRESOURCE(btnClick));
	result.bring_bmp   = (HBITMAP) LoadImage(hInst, bmp_file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	result.font = CreateFont(fontsize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, fontname);

	_tcscpy_s(result.caption, MAX_PATH, song_caption);

	//MinimizeTextName(result.caption, result.font, 500);

	_tcscpy_s(result.url, MAX_PATH, url);
	_stprintf_s(result.number, 10, "#%d", number);

	result.color = color;

	result.coord.left = x; result.coord.top = y;
	result.coord.right = x + width; result.coord.bottom = y + height;

	result.rcoord.left = 0; result.rcoord.top = 0;
	result.rcoord.right = width; result.rcoord.bottom = height;

	result.tdcoord.left = 30; result.tdcoord.top = tdelta_y;
	result.tdcoord.right = width - tdelta_x - 30; result.tdcoord.bottom = height;

	result.delta = 0;
	result.rheight = rheight;

	result.proc = proc;

	for (int i = 0; i < 3; ++i) {
		result.repaint[i] = FALSE;
	}

	SetWindowLong(result.hWnd, GWL_WNDPROC, (LONG) panelMainProc);

	return result;
}

ptPanel FindPanelHandle(HWND hWnd)
{
	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		if (pSongsPanels[i].hWnd == hWnd) {
			return &(pSongsPanels[i]);
		}
	}
	for (int i = 0; i < TOP_ARTISTS_COUNT; ++i) {
		if (pArtistsPanels[i].hWnd == hWnd) {
			return &(pArtistsPanels[i]);
		}
	}
	return NULL;
}

LRESULT CALLBACK panelMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	ptPanel panel;
	const RECT rnumber = RECT_SONG_NUMBER, rtimer = RECT_SONG_TIMER;
	HBITMAP hbmOld;

	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		panel = FindPanelHandle(hWnd);
		if (panel != NULL && !panel->repaint[1]) {
			panel->repaint[0] = TRUE; panel->repaint[1] = TRUE; panel->repaint[2] = FALSE;
			InvalidateRect(hWnd, &panel->rcoord, TRUE);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		panel = FindPanelHandle(hWnd);

		if (panel) {
			if (panel->repaint[1]) {
				if (panel->bring_bmp) {
					panel->back_mem_hdc[1] = CreateCompatibleDC(hdc);
					hbmOld = SelectObject(panel->back_mem_hdc[1], panel->back_bmp[1]);
					BitBlt(hdc, 0, 125, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[1], 0, 125, SRCCOPY);
					SelectObject(panel->back_mem_hdc[1], hbmOld);
					DeleteDC(panel->back_mem_hdc[1]);

					panel->bring_mem_hdc = CreateCompatibleDC(hdc);
					hbmOld = SelectObject(panel->bring_mem_hdc, panel->bring_bmp);
					BitBlt(hdc, 0, 0, 300, 125, panel->bring_mem_hdc, 0, panel->delta, SRCCOPY);
					SelectObject(panel->bring_mem_hdc, hbmOld);
					DeleteDC(panel->bring_mem_hdc);

					panel->timer = SetTimer(panel->hWnd, 0, 40, (TIMERPROC)NULL);
				} else {

					panel->back_mem_hdc[1] = CreateCompatibleDC(hdc);
					hbmOld = SelectObject(panel->back_mem_hdc[1], panel->back_bmp[1]);
					BitBlt(hdc, 0, 0, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[1], 0, 0, SRCCOPY);
					SelectObject(panel->back_mem_hdc[1], hbmOld);
					DeleteDC(panel->back_mem_hdc[1]);
				}
			} else {
				if (!panel->repaint[0]) {
					if (panel->bring_bmp) {
						panel->back_mem_hdc[0] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->back_mem_hdc[0], panel->back_bmp[0]);
						BitBlt(hdc, 0, 125, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[0], 0, 125, SRCCOPY);
						SelectObject(panel->back_mem_hdc[0], hbmOld);
						DeleteDC(panel->back_mem_hdc[0]);

						panel->bring_mem_hdc = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->bring_mem_hdc, panel->bring_bmp);
						BitBlt(hdc, 0, 0, 300, 125, panel->bring_mem_hdc, 0, panel->delta, SRCCOPY);
						SelectObject(panel->bring_mem_hdc, hbmOld);
						DeleteDC(panel->bring_mem_hdc);
					} else {
						panel->back_mem_hdc[0] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->back_mem_hdc[0], panel->back_bmp[0]);
						BitBlt(hdc, 0, 0, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[0], 0, 0, SRCCOPY);
						SelectObject(panel->back_mem_hdc[0], hbmOld);
						DeleteDC(panel->back_mem_hdc[0]);
					}
				} else {
					if (panel->bring_bmp) {

						panel->back_mem_hdc[2] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->back_mem_hdc[2], panel->back_bmp[2]);
						BitBlt(hdc, 0, 125, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[2], 0, 125, SRCCOPY);
						SelectObject(panel->back_mem_hdc[2], hbmOld);
						DeleteDC(panel->back_mem_hdc[2]);

						panel->bring_mem_hdc = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->bring_mem_hdc, panel->bring_bmp);
						BitBlt(hdc, 0, 0, 300, 125, panel->bring_mem_hdc, 0, panel->delta, SRCCOPY);
						SelectObject(panel->bring_mem_hdc, hbmOld);
						DeleteDC(panel->bring_mem_hdc);
					} else {

						panel->back_mem_hdc[2] = CreateCompatibleDC(hdc);
						hbmOld = SelectObject(panel->back_mem_hdc[2], panel->back_bmp[2]);
						BitBlt(hdc, 0, 125, panel->rcoord.right, panel->rcoord.bottom, panel->back_mem_hdc[2], 0, 125, SRCCOPY);
						SelectObject(panel->back_mem_hdc[2], hbmOld);
						DeleteDC(panel->back_mem_hdc[2]);
					}

				}
			}
		} else {
			return 0;
		}

		SetTextColor(hdc, panel->color); SetBkMode(hdc, TRANSPARENT); SelectObject(hdc, panel->font);
		DrawText(hdc, panel->caption, _tcslen(panel->caption), &panel->tdcoord, DT_SINGLELINE | DT_CENTER);
		DrawText(hdc, panel->number, _tcslen(panel->number), (LPRECT)&rnumber, DT_SINGLELINE);
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		panel = FindPanelHandle(hWnd);
		if (panel) {
			panel->repaint[0] = TRUE; panel->repaint[1] = FALSE; panel->repaint[2] = TRUE;
			InvalidateRect(hWnd, &panel->rcoord, TRUE);
		}
		break;
	case WM_LBUTTONUP:
		panel = FindPanelHandle(hWnd);
		if (panel) {
			panel->repaint[0] = TRUE; panel->repaint[1] = TRUE; panel->repaint[2] = FALSE;
			InvalidateRect(hWnd, &panel->rcoord, TRUE);
		}
		ShellExecute(NULL, "open", panel->url, NULL, NULL, SW_SHOWNORMAL);
	case WM_TIMER:
		panel = FindPanelHandle(hWnd);
		if (panel->delta == 0) {
			panel->up = TRUE;
		} else if (panel->delta == panel->rheight - 125) {
			panel->up = FALSE;
		}
		if (panel->up) { panel->delta++; } else { panel->delta--; }
		InvalidateRect(hWnd, &rtimer, FALSE);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void UpdatePanels(HWND hWnd, POINT pt)
{
	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		if (pSongsPanels[i].repaint[0]) {
			ScreenToClient(hWnd, &pt);
			if (!PtInRect(&pSongsPanels[i].coord, pt)) {
				pSongsPanels[i].repaint[0] = FALSE;
				pSongsPanels[i].repaint[1] = FALSE;
				pSongsPanels[i].repaint[2] = FALSE;
				InvalidateRect(pSongsPanels[i].hWnd, NULL, TRUE);
				if (pSongsPanels[i].timer) {
					KillTimer(pSongsPanels[i].hWnd, 0);
				}
			}
		}
		if (pArtistsPanels[i].repaint[0]) {
			ScreenToClient(hWnd, &pt);
			if (!PtInRect(&pArtistsPanels[i].coord, pt)) {
				pArtistsPanels[i].repaint[0] = FALSE;
				pArtistsPanels[i].repaint[1] = FALSE;
				pArtistsPanels[i].repaint[2] = FALSE;
				InvalidateRect(pArtistsPanels[i].hWnd, NULL, TRUE);
				if (pArtistsPanels[i].timer) {
					KillTimer(pArtistsPanels[i].hWnd, 0);
				}
			}
		}
	}
}

void HidePanel(ptPanel btn)
{
	ShowWindow(btn->hWnd, SW_HIDE);
}

void ShowPanel(ptPanel btn)
{
	ShowWindow(btn->hWnd, SW_SHOW);
}

/*int x = -300;
int _x = 756;
BOOL tmr = TRUE;

void TimerProc(HWND hWnd, UINT u, UINT_PTR up, DWORD dw)
{
	x += 15;
	_x -= 15;

	MoveWindow(pSongsPanels[0].hWnd, x, pSongsPanels[0].coord.top, 300, 151, TRUE);
	MoveWindow(pSongsPanels[1].hWnd, _x, pSongsPanels[1].coord.top, 300, 151, TRUE);
	MoveWindow(pSongsPanels[2].hWnd, x, pSongsPanels[2].coord.top, 300, 151, TRUE);
	MoveWindow(pSongsPanels[3].hWnd, _x, pSongsPanels[3].coord.top, 300, 151, TRUE);

	if (x >= pSongsPanels[0].coord.left) {
		KillTimer(pSongsPanels[0].hWnd, 1);
		MoveWindow(pSongsPanels[0].hWnd, pSongsPanels[0].coord.left, pSongsPanels[0].coord.top, 300, 151, TRUE);
		MoveWindow(pSongsPanels[1].hWnd, pSongsPanels[1].coord.left, pSongsPanels[1].coord.top, 300, 151, TRUE);
		MoveWindow(pSongsPanels[2].hWnd, pSongsPanels[2].coord.left, pSongsPanels[2].coord.top, 300, 151, TRUE);
		MoveWindow(pSongsPanels[3].hWnd, pSongsPanels[3].coord.left, pSongsPanels[3].coord.top, 300, 151, TRUE);
	}
}*/

void HideSlidePanels(int state, int current)
{
	for (int i = current * COUNT_ONE_PANELS_PAGE;
		i < current * COUNT_ONE_PANELS_PAGE + COUNT_ONE_PANELS_PAGE; ++i) {
		switch (state)
		{
		case STATE_TOP_SONGS:
			HidePanel(&pSongsPanels[i]);
			break;
		case STATE_TOP_ARTISTS:
			HidePanel(&pArtistsPanels[i]);
			break;
		}
	}
}

void ShowSlidePanels(int state, int current, int new_btn)
{
	if (new_btn == -1) {
		new_btn = COUNT_ONE_PANELS_PAGE;
	} else if (new_btn == COUNT_ONE_PANELS_PAGE + 1) {
		new_btn = 0;
	}

	switch (state) {
	case STATE_TOP_SONGS:
		curTopSongs = new_btn;
		break;
	case STATE_TOP_ARTISTS:
		curTopArtists = new_btn;
		break;
	}

	for (int i = current * COUNT_ONE_PANELS_PAGE;
		i < current * COUNT_ONE_PANELS_PAGE + COUNT_ONE_PANELS_PAGE; ++i) {
		switch (state)
		{
		case STATE_TOP_SONGS:
			HidePanel(&pSongsPanels[i]);
			break;
		case STATE_TOP_ARTISTS:
			HidePanel(&pArtistsPanels[i]);
			break;
		}
	}

	for (int i = new_btn * COUNT_ONE_PANELS_PAGE;
		i < (new_btn * COUNT_ONE_PANELS_PAGE) + COUNT_ONE_PANELS_PAGE; ++i) {
		switch (state) {
		case STATE_TOP_SONGS:
			ShowPanel(&pSongsPanels[i]);
			break;
		case STATE_TOP_ARTISTS:
			ShowPanel(&pArtistsPanels[i]);
			break;
		}
	}
}

int GetSlidePanelsState(int state)
{
	switch (state) {
	case STATE_TOP_SONGS:
		return curTopSongs;
	case STATE_TOP_ARTISTS:
		return curTopArtists;
	default:
		return 0;
	}
}