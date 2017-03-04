
#include "stdafx.h"

#include <Urlmon.h>
#include <Wininet.h>

#include "XML_Parsing.h"
#include "Download.h"
#include "MLConvertImage.h"
#include "MLUtils.h"
#include "MLMessages.h"

BOOL isTopSongsDownload = FALSE, isTopArtistsDownload = FALSE;


void DeleteCacheImages()
{
	// DO THIS -_-
}

BOOL DownloadFile(TCHAR *url, TCHAR *toFile, BOOL isDeleteCache)
{
	if (isDeleteCache) {
		DeleteUrlCacheEntry(url);
	}

	return (URLDownloadToFile(NULL, url, toFile, 0, NULL) == S_OK);
}

BOOL DownloadTopSongsImages(void)
{
	TCHAR filename[MAX_PATH];
	WCHAR wfilename[MAX_PATH], woutfilename[MAX_PATH];

	ptTopSongs pSongsArray = getTopSongsArray();

	for (int i = 0; i < TOP_SONGS_COUNT; ++i) {
		if (_tcscmp(pSongsArray[i].image[3], "") != 0) {
			_stprintf_s(filename, MAX_PATH, "%s\\%d.image", CACHE_TOP_TRACK_DIR_DOWNLOAD, i + 1);
			_stprintf_s(pSongsArray[i].filename, MAX_PATH, "%s\\%d.bmp", CACHE_TOP_TRACK_DIR_IMAGES, i + 1);
			if (DownloadFile(pSongsArray[i].image[3], filename, FALSE)) {
				MultiByteToWideChar(CP_UTF8, 0, filename, MAX_PATH, wfilename, MAX_PATH);
				MultiByteToWideChar(CP_UTF8, 0, pSongsArray[i].filename, MAX_PATH, woutfilename, MAX_PATH);
				MLConvertImage(wfilename, woutfilename, 0, 0, FALSE, TRUE);
			} else {
				return FALSE;
			}
		}
	}

	isTopSongsDownload = TRUE;

	return TRUE;
}

BOOL DownloadTopArtistsImages(void)
{
	TCHAR filename[MAX_PATH];
	WCHAR wfilename[MAX_PATH], woutfilename[MAX_PATH];

	ptTopArtists pTopArtists = getTopArtistsArray();

	for (int i = 0; i < TOP_ARTISTS_COUNT; ++i) {
		if (strcmp(pTopArtists[i].image[4], "") != 0) {
			_stprintf_s(filename, MAX_PATH, "%s\\%d.image", CACHE_TOP_ARTISTS_DIR_DOWNLOAD, i + 1);
			_stprintf_s(pTopArtists[i].filename, MAX_PATH, "%s\\%d.bmp", CACHE_TOP_ARTISTS_DIR_IMAGES, i + 1);
			if (DownloadFile(pTopArtists[i].image[4], filename, FALSE)) {
				MultiByteToWideChar(CP_UTF8, 0, filename, MAX_PATH, wfilename, MAX_PATH);
				MultiByteToWideChar(CP_UTF8, 0, pTopArtists[i].filename, MAX_PATH, woutfilename, MAX_PATH);
				pTopArtists[i].rheigth = MLConvertImage(wfilename, woutfilename, 300, 0, TRUE, TRUE);
			} else {
				return FALSE;
			}
		}
	}

	isTopArtistsDownload = TRUE;

	return TRUE;
}

BOOL CheckDownloadStatus(int state)
{
	switch (state)
	{
	case STATE_TOP_SONGS:
		return isTopSongsDownload;
	case STATE_TOP_ARTISTS:
		return isTopArtistsDownload;
	default:
		return FALSE;
	}
}