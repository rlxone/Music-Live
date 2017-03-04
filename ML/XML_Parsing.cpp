
#include "stdafx.h"
#include "XML_Parsing.h"
#include "Music.h"
#include "MLUtils.h"
#include "MLMessages.h"

tTopSongs pSongsArray[TOP_SONGS_COUNT];
tTopArtists pArtistsArray[TOP_ARTISTS_COUNT];
int repeat_img = 0, pSongsArraySize = 0, pArtistsArraySize = 0;
BOOL repeat_name = FALSE;

BOOL CreatePlayListFile(TCHAR *filename, int curr_playlist)
{
	ptPlayList playslists = GetPlayLists();
	
	TCHAR temp[MAX_PATH];

	if (FileExistsA(filename)) {
		DeleteFile(filename);
	}

	xmlTextWriter *xmlWriter = xmlNewTextWriterFilename(filename, 0);

	if (!xmlWriter) {
		return FALSE;
	}

	xmlTextWriterStartDocument(xmlWriter, NULL, NULL, NULL);
	
	xmlTextWriterSetIndent(xmlWriter, 1);

	xmlTextWriterWriteComment(xmlWriter, XML_PLAYLIST_HEADER);

	xmlTextWriterStartElement(xmlWriter, "playlist");

	xmlTextWriterWriteElement(xmlWriter, "name", playslists[curr_playlist - 1].name);
	
	sprintf_s(temp, sizeof(temp), "%d", playslists[curr_playlist - 1].pcount);
	xmlTextWriterWriteElement(xmlWriter, "total_songs", temp);

	sprintf_s(temp, sizeof(temp), "%lld", playslists[curr_playlist - 1].plength);
	xmlTextWriterWriteElement(xmlWriter, "total_length", temp);

	for (int i = 0; i < playslists[curr_playlist - 1].pcount; ++i) {
		xmlTextWriterStartElement(xmlWriter, "song");

		//xmlTextWriterWriteElement(xmlWriter, "number", playslists[curr_playlist - 1].pdata[i].ldata.number);
		//xmlTextWriterWriteElement(xmlWriter, "trackname", playslists[curr_playlist - 1].pdata[i].ldata.trackname);
		//xmlTextWriterWriteElement(xmlWriter, "bitrate", playslists[curr_playlist - 1].pdata[i].ldata.bitrate);
		//xmlTextWriterWriteElement(xmlWriter, "length", playslists[curr_playlist - 1].pdata[i].ldata.length);
		xmlTextWriterWriteElement(xmlWriter, "filename", playslists[curr_playlist - 1].pdata[i].filename);

		xmlTextWriterEndElement(xmlWriter);
	}

	xmlTextWriterEndDocument(xmlWriter);

	xmlFreeTextWriter(xmlWriter);

	return TRUE;
}

void XMLParsePlaylistName(xmlNode *a_node, TCHAR *pname, int psize)
{
	xmlNode *cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			if (_tcscmp(cur_node->name, "name") == 0) {
				_tcscpy_s(pname, psize, (TCHAR*) cur_node->children->content);
				break;
			}
		}

		XMLParsePlaylistName(cur_node->children, pname, psize);
	}
}

void XMLParsePlaylist(xmlNode *a_node, ptPlaylistFiles files)
{
	xmlNode *cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			if (_tcscmp(cur_node->name, "filename") == 0) {
				if (files->fcount == 0) {
					files->filenames = (WCHAR**) malloc(sizeof(WCHAR*) * ++files->fcount);
				} else {
					files->filenames = (WCHAR**) realloc(files->filenames, sizeof(WCHAR*) * ++files->fcount);
				}
				files->filenames[files->fcount - 1] = (WCHAR*)malloc(sizeof(WCHAR)* MAX_PATH);
				MultiByteToWideChar(CP_UTF8, 0, cur_node->children->content, MAX_PATH, files->filenames[files->fcount - 1], MAX_PATH);
			}
		}

		XMLParsePlaylist(cur_node->children, files);
	}
}

BOOL OpenPlayListFile(TCHAR *filename, HWND hWnd, HINSTANCE hInst, ptPlaylistFiles files)
{
	xmlDocPtr doc;
	xmlNode *root;

	doc = xmlReadFile(filename, NULL, 0);
	if (!doc) {
		return FALSE;
	}
	
	root = xmlDocGetRootElement(doc);
	if (!root) {
		return FALSE;
	}

	if (CheckPlaylistsFile(root)) {
		XMLParsePlaylistName(root, files->pname, 50);
		XMLParsePlaylist(root, files);
		xmlFreeDoc(doc);
		return TRUE;
	}

	return FALSE;
}

BOOL CheckPlaylistsFile(xmlNodePtr root)
{
	if (root->prev) {
		if (root->prev->content) {
			return (_tcscmp(root->prev->content, XML_PLAYLIST_HEADER) == 0);
		}
		return FALSE;
	}
	return FALSE;
}

BOOL CheckLastFMFile(xmlNodePtr root)
{
	return (_tcscmp((TCHAR*)xmlGetProp(root, (xmlChar*)XML_LASTFM_STATUS), XML_LASTFM_DONE_STATUS) == 0);
}

void XMLParseTopSongs(xmlNode *a_node)
{
	xmlNode *cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_SONG_TAG)) == 0) {
				if (repeat_name) {
					_tcscpy_s(pSongsArray[pSongsArraySize].artist, MAX_PATH, (TCHAR*)cur_node->children->content);
					_stprintf_s(pSongsArray[pSongsArraySize].fullsong, MAX_PATH, "%s - %s",
						pSongsArray[pSongsArraySize].artist, pSongsArray[pSongsArraySize].song);
					pSongsArray[pSongsArraySize].number = ++pSongsArraySize;
				} else {
					_tcscpy_s(pSongsArray[pSongsArraySize].song, MAX_PATH, (TCHAR*)cur_node->children->content);
				}
				repeat_name = !repeat_name;
			}
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_URL_TAG)) == 0) {
				if (pSongsArraySize != 20) {
					_tcscpy_s(pSongsArray[pSongsArraySize].url, MAX_PATH, (TCHAR*)cur_node->children->content);
				}
			}
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_IMAGE_TAG)) == 0) {
				_tcscpy_s(pSongsArray[pSongsArraySize - 1].image[repeat_img], MAX_PATH, (TCHAR*)cur_node->children->content);
				repeat_img++;
				if (repeat_img == 4) {
					repeat_img = 0;
				}
			}
		}

		XMLParseTopSongs(cur_node->children);
	}
}

BOOL ParseTopSongs(TCHAR *filename)
{
	xmlDocPtr doc;
	xmlNode *root;

	doc = xmlReadFile(filename, NULL, 0);
	if (!doc) {
		return FALSE;
	}

	root = xmlDocGetRootElement(doc);
	if (!root) {
		return FALSE;
	}

	if (CheckLastFMFile(root)) {
		pSongsArraySize = 0;
		repeat_img = 0;
		XMLParseTopSongs(root);
		xmlFreeDoc(doc);
		return TRUE;
	}

	return FALSE;
}

void XMLParseTopArtists(xmlNode *a_node)
{
	xmlNode *cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_SONG_TAG)) == 0) {
				_tcscpy_s(pArtistsArray[pArtistsArraySize].artist, MAX_PATH, (TCHAR*)cur_node->children->content);
			}
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_URL_TAG)) == 0) {
				_tcscpy_s(pArtistsArray[pArtistsArraySize].url, MAX_PATH, (TCHAR*)cur_node->children->content);
			}
			if (_tcscmp((TCHAR*)cur_node->name, TEXT(XML_TOPSONGS_IMAGE_TAG)) == 0) {
				_tcscpy_s(pArtistsArray[pArtistsArraySize].image[repeat_img], MAX_PATH, (TCHAR*)cur_node->children->content);
				repeat_img++;
				if (repeat_img == 5) {
					pArtistsArray[pArtistsArraySize].number = ++pArtistsArraySize;
					repeat_img = 0;
				}
			}
		}

		XMLParseTopArtists(cur_node->children);
	}
}

BOOL ParseTopArtists(TCHAR *filename)
{
	xmlDocPtr doc;
	xmlNode *root;

	doc = xmlReadFile(filename, NULL, 0);
	if (!doc) {
		return FALSE;
	}

	root = xmlDocGetRootElement(doc);
	if (!root) {
		return FALSE;
	}

	if (CheckLastFMFile(root)) {
		pArtistsArraySize = 0;
		repeat_img = 0;
		XMLParseTopArtists(root);
		xmlFreeDoc(doc);
		return TRUE;
	}

	return FALSE;
}

ptTopSongs getTopSongsArray(void)
{
	return pSongsArray;
}

ptTopArtists getTopArtistsArray(void)
{
	return pArtistsArray;
}