
#include "stdafx.h"
#include "Labels.h"
#include "MLUtils.h"

tLabel lblArray[MAX_LABELS_COUNT];
int lblArraySize = 0;

ptLabel LabelCreate(HWND hWnd, HINSTANCE hInst, TCHAR* caption, COLORREF color, COLORREF bkgcolor, TCHAR* fontname, int fontsize, int alignment,
	int fnHeight, int x, int y, int width, int height, int bkgres)
{
	int index = lblArraySize;

	lblArray[index].parent = hWnd;

	lblArray[index].bmp = LoadBitmap(hInst, MAKEINTRESOURCE(bkgres));

	if (!lblArray[index].bmp) {
		return NULL;
	}

	HDC hdc = GetDC(hWnd);

	lblArray[index].mem_dc = CreateCompatibleDC(hdc);
	HBITMAP hOldDC = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(lblArray[index].mem_dc, hOldDC);

	HDC hMemDC = CreateCompatibleDC(hdc);
	SelectObject(hMemDC, lblArray[index].bmp);

	BitBlt(lblArray[index].mem_dc, 0, 0, width, height, hMemDC, x, y, SRCCOPY);

	DeleteDC(hMemDC);

	lblArray[index].font = CreateFont(fontsize, 0, 0, 0, fnHeight, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_QUALITY, fontname);
	
	lblArray[index].coord.left = x; lblArray[index].coord.top = y;
	lblArray[index].coord.right = x + width; lblArray[index].coord.bottom = y + height;

	_tcscpy_s(lblArray[index].caption, MAX_PATH, caption);
	lblArray[index].color = color;
	lblArray[index].bkgcolor = bkgcolor;
	if (GetTextWidth(lblArray[index].caption, lblArray[index].font) > lblArray[index].coord.right - lblArray[index].coord.left) {
		lblArray[index].aligment = DT_LEFT;
		lblArray[index].alalign = TRUE;
	} else {
		lblArray[index].aligment = alignment;
		lblArray[index].alalign = FALSE;
	}
	lblArray[index].ishide = FALSE;
	lblArray[index].delta = 0;
	lblArray[index].width = 0;

	lblArraySize++;

	return &(lblArray[index]);
}

void LabelsUpdate(HDC hdc)
{
	for (int i = 0; i < lblArraySize; ++i) {
		if (!lblArray[i].ishide) {

			/*TRIPLE BUFFERED*/
			HDC hMemDC = CreateCompatibleDC(hdc);
			HBITMAP hbmp = CreateCompatibleBitmap(hdc, lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top);
			SelectObject(hMemDC, hbmp);

			BitBlt(hMemDC, 0, 0, lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top,
				lblArray[i].mem_dc, 0, 0, SRCCOPY);

			SelectObject(hMemDC, lblArray[i].font);

			SetTextColor(hMemDC, lblArray[i].color);

			if (lblArray[i].bkgcolor == COLOR_TRANSPARENT) {
				SetBkMode(hMemDC, TRANSPARENT);
			} else {
				SetBkMode(hMemDC, OPAQUE);
				SetBkColor(hMemDC, lblArray[i].bkgcolor);
			}

			RECT rect = { 0, 0, lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top };

			DrawText(hMemDC, lblArray[i].caption, _tcslen(lblArray[i].caption), &rect,
				lblArray[i].aligment);
			
			BitBlt(hdc, lblArray[i].coord.left, lblArray[i].coord.top,
				lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top,
				hMemDC, 0, 0, SRCCOPY);

			DeleteObject(hbmp);
			DeleteDC(hMemDC);

			/*DOUBLE DUFFERED*/
			
			/*HDC hMemDC = CreateCompatibleDC(hdc);

			HBITMAP hbmMem = CreateCompatibleBitmap(hdc,
				lblArray[i].coord.right - lblArray[i].coord.left,
				lblArray[i].coord.bottom - lblArray[i].coord.top);

			HBITMAP hOldBmp = SelectObject(hMemDC, hbmMem);

			BitBlt(hMemDC, 0, 0,
				lblArray[i].coord.right,
				lblArray[i].coord.bottom, hdc, lblArray[i].coord.left, lblArray[i].coord.top, SRCCOPY);

			HFONT hOldFont = SelectObject(hMemDC, lblArray[i].font);

			SetTextColor(hMemDC, lblArray[i].color);

			if (lblArray[i].bkgcolor == COLOR_TRANSPARENT) {
				SetBkMode(hMemDC, TRANSPARENT);
			} else {
				SetBkMode(hMemDC, OPAQUE);
				SetBkColor(hMemDC, lblArray[i].bkgcolor);
			}

			RECT rect = { lblArray[i].delta, 0, lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top };

			DrawText(hMemDC, lblArray[i].caption, _tcslen(lblArray[i].caption), &rect,
				DT_SINGLELINE | lblArray[i].aligment);

			SelectObject(hMemDC, hOldFont);

			BitBlt(hdc, lblArray[i].coord.left, lblArray[i].coord.top,
				lblArray[i].coord.right - lblArray[i].coord.left, lblArray[i].coord.bottom - lblArray[i].coord.top,
				hMemDC, 0, 0, SRCCOPY);

			SelectObject(hMemDC, hOldBmp);
			DeleteObject(hbmMem);
			DeleteDC(hMemDC);*/
		}
	}
}

void CALLBACK LabelsSlideProc(HWND hWnd, UINT u, UINT_PTR up, DWORD d)
{
	--lblArray[up - 1].delta;
	InvalidateRect(lblArray[up - 1].parent, &lblArray[up - 1].coord, TRUE);
}

void LabelChangeText(ptLabel label, TCHAR *text)
{
	for (int i = 0; i < lblArraySize; ++i) {
		if (&(lblArray[i]) == label) {
			int width = GetTextWidth(text, lblArray[i].font);
			if (width > lblArray[i].coord.right - lblArray[i].coord.left && lblArray[i].bkgcolor == COLOR_TRANSPARENT) {
				MinimizeTextName(text, lblArray[i].font, lblArray[i].coord.right - lblArray[i].coord.left);
			}
			if (lblArray[i].bkgcolor != COLOR_TRANSPARENT) {
				InvalidateRect(lblArray[i].parent, &lblArray[i].coord, FALSE);
				_tcscpy_s(lblArray[i].caption, MAX_PATH - 1, text);
				width = GetTextWidth(lblArray[i].caption, lblArray[i].font);
				lblArray[i].coord.left = lblArray[i].coord.right - width - 20;
				InvalidateRect(lblArray[i].parent, &lblArray[i].coord, FALSE);
			} else {
				_tcscpy_s(lblArray[i].caption, MAX_PATH - 1, text);
			    InvalidateRect(lblArray[i].parent, &lblArray[i].coord, FALSE);
			}
			break;
		}
	}
}

void LabelHide(ptLabel label)
{
	for (int i = 0; i < lblArraySize; ++i) {
		if (!lblArray[i].ishide) {
			if (&(lblArray[i]) == label) {
				lblArray[i].ishide = TRUE;
				InvalidateRect(lblArray[i].parent, &lblArray[i].coord, FALSE);
				break;
			}
		}
	}
}

void LabelShow(ptLabel label)
{
	for (int i = 0; i < lblArraySize; ++i) {
		if (lblArray[i].ishide) {
			if (&(lblArray[i]) == label) {
				lblArray[i].ishide = FALSE;
				InvalidateRect(lblArray[i].parent, &lblArray[i].coord, FALSE);
				break;
			}
		}
	}
}