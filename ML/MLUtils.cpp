
#include "stdafx.h"
#include "MLUtils.h"

void SecondsToTime(time_t seconds, TCHAR *time)
{
	struct tm timeinfo;

	if (seconds < 0) {
		_tcscpy_s(time, sizeof(*time), "00:00");
	} else {
		timeinfo.tm_mday = (int)((seconds / 60 / 60 / 24));
		timeinfo.tm_hour = (int)((seconds / 60 / 60) % 24);
		timeinfo.tm_min = (int)((seconds / 60) % 60);
		timeinfo.tm_sec = (int)(seconds % 60);
		if (timeinfo.tm_hour == 0 && timeinfo.tm_mday == 0) {
			strftime(time, MAX_PATH, "%M:%S", &timeinfo);
		}
		else {
			if (timeinfo.tm_mday < 1) {
				strftime(time, MAX_PATH, "%H:%M:%S", &timeinfo);
			}
			else {
				strftime(time, MAX_PATH, "%d:%H:%M:%S", &timeinfo);
			}
		}
	}
}

void GetNameFromTrackName(TCHAR *filename, TCHAR *trackname)
{
	int count;

	for (count = _tcslen(filename) - 1; count >= 0; --count) {
		if (filename[count] == '.') {
			break;
		}
	}

	_tcsncpy_s(trackname, MAX_PATH, filename, count);
}

void GetNameFromPathName(TCHAR *filename, TCHAR *trackname)
{
	TCHAR exname[MAX_PATH];
	int count;

	GetNameFromTrackName(filename, exname);

	for (count = _tcslen(exname) - 1; count >= 0; --count) {
		if (exname[count] == '\\') {
			break;
		}
	}

	_tcsncpy_s(trackname, MAX_PATH, exname + count + 1, _tcslen(exname) - count);
}

void NormalizeTagString(TCHAR *str)
{
	for (int i = _tcslen(str) - 1; i >= 0; --i) {
		if (str[i] == '\0') {
			continue;
		}
		if (str[i] == ' ') {
			str[i] = '\0';
		}
		else {
			break;
		}
	}
}

BOOL FileExistsA(TCHAR *filename)
{
	FILE *file = NULL;
	_tfopen_s(&file, filename, "r");

	if (file) {
		fclose(file);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

BOOL FileExistsW(WCHAR *filename)
{
	FILE *file = NULL;
	_wfopen_s(&file, filename, L"r");

	if (file) {
		fclose(file);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

BOOL CreateRecursiveDirectory(TCHAR *folder_path)
{
	TCHAR directory[MAX_PATH] = "", temp[MAX_PATH];
	TCHAR *token = NULL, *next_token = NULL;

	if (!folder_path) {
		return FALSE;
	}

	_tcscpy_s(temp, MAX_PATH, folder_path);

	token = _tcstok_s(temp, TEXT("\\"), &next_token);

	if (!token)
		return FALSE;

	while (token) {
		_stprintf_s(directory, MAX_PATH, "%s%s\\", directory, token);
		CreateDirectory(directory, NULL);
		token = _tcstok_s(NULL, TEXT("\\"), &next_token);
	}

	return TRUE;
}

BOOL CompareExtension(TCHAR *str, TCHAR* ext)
{
	for (int i = _tcslen(str) - 1; i >= 0; --i) {
		if (str[i] == '.') {
			return (_tcscmp(str + i + 1, ext) == 0);
		}
	}

	return FALSE;
}

BOOL RectInRect(RECT rect1, RECT rect2)
{
	if (rect1.left < rect2.right && rect1.right > rect2.left &&
		rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
		return TRUE;
	}

	return FALSE;
}

int GetTextWidth(TCHAR *text, HFONT font)
{
	SIZE sz;
	HDC hdc = GetDC(NULL);

	SelectObject(hdc, font);
	GetTextExtentPoint32(hdc, text, _tcslen(text), &sz);

	ReleaseDC(NULL, hdc);

	return sz.cx;
}

void MinimizeTextName(TCHAR *text, HFONT font, int width)
{
	int length = _tcslen(text);

	while (GetTextWidth(text, font) >= width - 10 && length > 0) {
		text[--length] = '\0';
	}

	for (int i = length - 3; i < length; ++i) {
		text[i] = '.';
	}
}

RECT ClientToCenter(int x, int y)
{
	RECT rect;

	GetClientRect(GetDesktopWindow(), &rect);
	rect.left = (rect.right / 2) - (x / 2);
	rect.top = (rect.bottom / 2) - (y / 2);
	return rect;
}

BOOL BrowseForFolder(HWND hWnd, WCHAR *folder, int size, WCHAR *startDir, WCHAR *text, BFFCALLBACK clckProc)
{
	WCHAR temp[MAX_PATH];
	LPITEMIDLIST lpItemID;

	LPBROWSEINFOW binfo = malloc(sizeof(BROWSEINFOW));

	ZeroMemory(binfo, sizeof(BROWSEINFOW));

	binfo->lParam = (LPARAM)startDir;
	binfo->lpfn = clckProc;
	binfo->ulFlags = BIF_NEWDIALOGSTYLE;
	binfo->lpszTitle = text;
	binfo->hwndOwner = hWnd;
	lpItemID = SHBrowseForFolderW(binfo);

	if (lpItemID) {
		SHGetPathFromIDListW(lpItemID, temp);
		wcscpy_s(folder, sizeof(WCHAR)* size, temp);
	}
	else {
		free(binfo);
		return FALSE;
	}

	free(binfo);

	return TRUE;
}

BOOL BrowseForFileA(HWND hWnd, TCHAR *filename, int size, TCHAR *lpstrFilter)
{
	LPOPENFILENAMEA ofn = malloc(sizeof(OPENFILENAMEA));

	ZeroMemory(ofn, sizeof(OPENFILENAMEA));

	ofn->lStructSize = sizeof(OPENFILENAMEA);
	ofn->hwndOwner = hWnd;
	ofn->lpstrFile = filename;
	ofn->lpstrFile[0] = '\0';
	ofn->nMaxFile = MAX_PATH;
	ofn->lpstrFilter = lpstrFilter;
	ofn->nFilterIndex = 1;
	ofn->lpstrFileTitle = NULL;
	ofn->nMaxFileTitle = 0;
	ofn->lpstrInitialDir = NULL;
	ofn->Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA(ofn)) {
		strcpy_s(filename, size, ofn->lpstrFile);
	} else {
		free(ofn);
		return FALSE;
	}

	free(ofn);

	return TRUE;
}


BOOL BrowseForFileW(HWND hWnd, WCHAR *filename, int size, WCHAR *lpstrFilter)
{
	LPOPENFILENAMEW ofn = malloc(sizeof(OPENFILENAMEW));

	ZeroMemory(ofn, sizeof(OPENFILENAMEW));

	ofn->lStructSize = sizeof(OPENFILENAMEW);
	ofn->hwndOwner = hWnd;
	ofn->lpstrFile = filename;
	ofn->lpstrFile[0] = '\0';
	ofn->nMaxFile = sizeof(WCHAR)* MAX_PATH;
	ofn->lpstrFilter = lpstrFilter;
	ofn->nFilterIndex = 1;
	ofn->lpstrFileTitle = NULL;
	ofn->nMaxFileTitle = 0;
	ofn->lpstrInitialDir = NULL;
	ofn->Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameW(ofn)) {
		wcscpy_s(filename, sizeof(WCHAR)* size, ofn->lpstrFile);
	}
	else {
		free(ofn);
		return FALSE;
	}

	free(ofn);

	return TRUE;
}

BOOL BrowseForSaveFile(HWND hWnd, TCHAR *filename, int size, TCHAR *lpstrFilter)
{
	LPOPENFILENAME ofn = malloc(sizeof(OPENFILENAME));

	ZeroMemory(ofn, sizeof(OPENFILENAME));

	ofn->lStructSize = sizeof(OPENFILENAME);
	ofn->hwndOwner = hWnd;
	ofn->lpstrFile = filename;
	ofn->nMaxFile = sizeof(TCHAR)* MAX_PATH;
	ofn->lpstrFilter = lpstrFilter;
	ofn->nFilterIndex = 1;
	ofn->lpstrFileTitle = NULL;
	ofn->nMaxFileTitle = 0;
	ofn->lpstrInitialDir = NULL;
	ofn->Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetSaveFileName(ofn)) {
		_tcscpy_s(filename, size, ofn->lpstrFile);
	} else {
		free(ofn);
		return FALSE;
	}

	free(ofn);

	return TRUE;
}

void AddListViewColumn(HWND lhWnd, TCHAR *text, int width, int number)
{
	LVCOLUMN lvc;

	lvc.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.iSubItem = 0;
	lvc.cx = width;
	lvc.fmt = LVCFMT_CENTER;
	lvc.pszText = text;
	ListView_InsertColumn(lhWnd, number, &lvc);
}

void AddListViewItem(HWND lhWnd, TCHAR *text, int item, int subitem)
{
	LVITEM lvItem;

	lvItem.mask = LVIF_TEXT;
	lvItem.pszText = text;
	lvItem.iItem = item;
	lvItem.iSubItem = subitem;

	if (subitem == 0) {
		ListView_InsertItem(lhWnd, &lvItem);
	}
	else {
		ListView_SetItem(lhWnd, &lvItem);
	}
}