
#include "stdafx.h"
#include "Music.h"
#include "MLUtils.h"

/*
	PLAYLIST
		PLAYLIST_DATA
			TCHAR filename;
			WCHAR wfilename;
			tPlayListData pdata
		PLAYLIST_DATA_COUNT
*/

ptPlayList playlists = NULL;
int pcount = 0; 

const TCHAR *genres[MAX_GENRES_COUNT] = {
	/*DEFAULT GENRES*/
	"Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip - Hop", "Jazz", "Metal",
	"New Age", "Oldies", "Other", "Pop", "Rhythm and Blues", "Rap", "Reggae", "Rock", "Techno", "Industrial",
	"Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro - Techno", "Ambient", "Trip - Hop",
	"Vocal", "Jazz & Funk", "Fusion", "Trance", "Classical", "Instrumental", "Acid", "House", "Game", "Sound Clip",
	"Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk rock", "Space", "Meditative", "Instrumental Pop",
	"Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno - Industrial", "Electronic", "Pop - Folk",
	"Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop / Funk",
	"Jungle", "Native American", "Cabaret", "New Wave", "Psychedelic", "Rave", "Showtunes", "Trailer", "Lo - Fi",
	"Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock",
	/*WINAMP EXTENDED GENRES*/
	"Folk", "Folk - Rock", "National Folk", "Swing", "Fast Fusion", "Bebop", "Latin", "Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock",
	"Progressive Rock", "Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band", "Chorus", "Easy Listening", "Acoustic",
	"Humour", "Speech", "Chanson", "Opera", "Chamber Music", "Sonata", "Symphony", "Booty Bass", "Primus", "Porn groove",
	"Satire", "Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power Ballad", "Rhythmic Soul" "Freestyle",
	"Duet", "Punk rock", "Drum Solo", "A capella", "Euro - House", "Dance Hall", "Goa", "Drum & Bass", "Club - House", "Hardcore Techno",
	"Terror", "Indie", "BritPop", "Afro - punk", "Polsk Punk", "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover",
	"Contemporary Christian", "Christian Rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "Jpop", "Synthpop", "Abstract", "Art Rock",
	"Baroque", "Bhangra", "Big Beat", "Breakbeat", "Chillout", "Downtempo", "Dub", "EBM", "Eclectic", "Electro", "Electroclash", "Emo",
	"Experimental", "Garage", "Global", "IDM", "Illbient", "Industro - Goth", "Jam Band", "Krautrock", "Leftfield", "Lounge", "Math Rock",
	"New Romantic", "Nu - Breakz", "Post - Punk", "Post - Rock", "Psytrance", "Shoegaze", "Space Rock", "Trop Rock", "World Music",
	"Neoclassical", "Audiobook", "Audio Theatre", "Neue Deutsche Welle", "Podcast", "Indie Rock", "G - Funk", "Dubstep", "Garage Rock", "Psybient"
};

void GetMusicGenre(int genre, TCHAR *sgenre, int ssize)
{
	if (genre == 255) {
		_tcscpy_s(sgenre, ssize, "");
	}
	if (genre >= 0 && genre < MAX_GENRES_COUNT) {
		_tcscpy_s(sgenre, ssize, genres[genre]);
	}
}

int GetMusicGenreIndex(TCHAR *sgenre)
{
	for (int i = 0; i < MAX_GENRES_COUNT; ++i) {
		if (_tcscmp(sgenre, genres[i]) == 0) {
			return i;
		}
	}

	return -1;
}

HWND CreateMusicListView(HWND hWnd, HINSTANCE hInst, HFONT *hlfont)
{
	HWND lhWnd = CreateWindow(WC_LISTVIEW, "", WS_CHILD | LVS_REPORT | LVS_SINGLESEL | WS_VSCROLL,
		239, 158, 484, 334, hWnd, NULL, hInst, NULL);

	ListView_SetExtendedListViewStyle(lhWnd, LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER);

	HRGN rgn = CreateRectRgn(5, 25, 484, 317);
	SetWindowRgn(lhWnd, rgn, TRUE);
	DeleteRgn(rgn);

	HFONT font = CreateFont(16, 0, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Trebuchet MS");

	*hlfont = CreateFont(14, 0, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Segoe UI");

	SendMessage(lhWnd, WM_SETFONT, (WPARAM)font, (LPARAM)NULL);

	ListView_SetTextBkColor(lhWnd, COLOR_LISTVIEW_BKG);
	ListView_SetTextColor(lhWnd, COLOR_LISTVIEW_TEXT);
	ListView_SetBkColor(lhWnd, COLOR_LISTVIEW_BKG);

	AddListViewColumn(lhWnd, "№", 40, 0);
	AddListViewColumn(lhWnd, "Название", 300, 1);
	AddListViewColumn(lhWnd, "Битрейт", 74, 2);
	AddListViewColumn(lhWnd, "Длина", 70, 3);

	return lhWnd;
}

BOOL AddToMusicListView(HWND lhWnd, tListViewData data)
{
	LVITEM lvItem;
	
	lvItem.mask = LVIF_TEXT;
	lvItem.pszText = data.number;
	lvItem.iItem = atoi(data.number) - 1;
	lvItem.iSubItem = 0;
	ListView_InsertItem(lhWnd, &lvItem);
	lvItem.iSubItem = 1;
	lvItem.pszText = data.trackname;
	ListView_SetItem(lhWnd, &lvItem);
	lvItem.iSubItem = 2;
	lvItem.pszText = data.bitrate;
	ListView_SetItem(lhWnd, &lvItem);
	lvItem.iSubItem = 3;
	lvItem.pszText = data.length;
	ListView_SetItem(lhWnd, &lvItem);
	
	return TRUE;
}

DWORD GetMP3Bitrate(HSTREAM stream)
{
	double stime;
	DWORD length;

	stime = BASS_ChannelBytes2Seconds(stream, BASS_ChannelGetLength(stream, BASS_POS_BYTE));
	length = (DWORD) BASS_StreamGetFilePosition(stream, BASS_FILEPOS_END);

	return (DWORD)(length / (125 * stime) + 0.5);
}

DWORD GetMP3Length(HSTREAM stream)
{
	return (DWORD) BASS_ChannelBytes2Seconds(stream, BASS_ChannelGetLength(stream, BASS_POS_BYTE));
}

int CreatePlaylist(TCHAR *name, HWND hWnd, HINSTANCE hInst)
{
	if (_tcscmp(name, "") == 0) {
		return CP_EMPTY_STRING;
	}
	
	for (int i = 0; i < pcount; ++i) {
		if (_tcscmp(playlists[i].name, name) == 0) {
			return CP_COMPARE_STRING;
		}
	}
	
	if (pcount == 0) {
		playlists = malloc(sizeof(tPlayList));
	} else {
		playlists = realloc(playlists, sizeof(tPlayList)* (pcount + 1));
	}

	pcount++;

	playlists[pcount - 1].mlListView.listView = CreateMusicListView(hWnd, hInst, &playlists[pcount - 1].mlListView.lfont);
	_tcscpy_s(playlists[pcount - 1].name, sizeof(playlists[pcount - 1].name), name);
	playlists[pcount - 1].pcount = 0;
	playlists[pcount - 1].plength = 0;
	playlists[pcount - 1].mlListView.pos = 1;
	playlists[pcount - 1].mlListView.isscrollbar = FALSE;
	playlists[pcount - 1].mlListView.spos = 0;
	playlists[pcount - 1].mlListView.cpos = -1;

	return CP_ALLOK;
}

HSTREAM MusicPlay(HWND hWnd, WCHAR *filename, BOOL isBassInit, HSTREAM currentChannel)
{
	HSTREAM currentStream = currentChannel;

	if (!isBassInit) {
		BASS_StreamFree(currentChannel);
		currentStream = BASS_StreamCreateFile(FALSE, filename, 0, 0, BASS_UNICODE);
	}

	BASS_ChannelPlay(currentStream, FALSE);

	return (isBassInit) ? currentChannel : currentStream;
}

HSYNC MusicSetSyncProc(HCHANNEL channel, SYNCPROC cproc, DWORD type)
{
	return BASS_ChannelSetSync(channel, type, 0, cproc, 0);
}

BOOL MusicSetPosition(HCHANNEL channel, int percent)
{
	if (channel < 0) {
		return FALSE;
	}

	QWORD length = BASS_ChannelGetLength(channel, BASS_POS_BYTE);
	QWORD cpos = (QWORD) (length * ((double) percent / 100));

	BASS_ChannelSetPosition(channel, cpos, BASS_POS_BYTE);

	return TRUE;
}

BOOL SetMP3ID3v1Tags(int curr_playlist, int curr_song, tPartID3v1 tags)
{
	const TCHAR tag[] = "TAG";

	TAG_ID3 vtags;

	ZeroMemory(vtags.id, 3);
	ZeroMemory(vtags.artist, MAX_TAGS_STRING);
	ZeroMemory(vtags.title, MAX_TAGS_STRING);
	ZeroMemory(vtags.album, MAX_TAGS_STRING);
	ZeroMemory(vtags.comment, MAX_TAGS_STRING);
	ZeroMemory(vtags.year, 4);

	_tcsncpy(vtags.id, tag, sizeof(vtags.id));
	_tcsncpy(vtags.artist, tags.artist, sizeof(vtags.artist));
	_tcsncpy(vtags.title, tags.title, sizeof(vtags.title));
	_tcsncpy(vtags.album, tags.album, sizeof(vtags.album));
	_tcsncpy(vtags.comment, tags.comment, sizeof(vtags.comment));
	_tcsncpy(vtags.year, tags.year, sizeof(vtags.year));

	if (tags.genre != 255 || tags.genre != -1) {
		vtags.genre = tags.genre;
	} else {
		vtags.genre = 255;
	}

	FILE *stream;

	_wfopen_s(&stream, playlists[curr_playlist - 1].pdata[curr_song].wfilename, L"rb+");

	if (!stream) {
		return FALSE;
	}

	fseek(stream, -128, SEEK_END);

	fwrite(&vtags, sizeof(TAG_ID3), 1, stream);

	fclose(stream);

	return TRUE;
}

BOOL GetMP3ID3v1Tags(HCHANNEL hchannel, ptPartID3v1 pID3v1)
{
	TAG_ID3 *tags = (TAG_ID3*)BASS_ChannelGetTags(hchannel, BASS_TAG_ID3);

	if (tags) {
		//GET ARTIST
		memset(pID3v1->artist, '\0', sizeof(pID3v1->artist));
		_tcsncpy_s(pID3v1->artist, sizeof(pID3v1->artist), tags->artist, sizeof(tags->artist));
		NormalizeTagString(pID3v1->artist);
		//GET TITLE
		memset(pID3v1->title, '\0', sizeof(pID3v1->title));
		_tcsncpy_s(pID3v1->title, sizeof(pID3v1->title), tags->title, sizeof(tags->title));
		NormalizeTagString(pID3v1->title);
		//GET ALBUM
		memset(pID3v1->album, '\0', sizeof(pID3v1->album));
		_tcsncpy_s(pID3v1->album, sizeof(pID3v1->album), tags->album, sizeof(tags->album));
		NormalizeTagString(pID3v1->album);
		//GET COMMENT
		memset(pID3v1->comment, '\0', sizeof(pID3v1->comment));
		_tcsncpy_s(pID3v1->comment, sizeof(pID3v1->comment), tags->comment, sizeof(tags->comment));
		NormalizeTagString(pID3v1->comment);
		//GET YEAR
		memset(pID3v1->year, '\0', sizeof(pID3v1->year));
		_tcsncpy_s(pID3v1->year, sizeof(pID3v1->year), tags->year, sizeof(tags->year));
		NormalizeTagString(pID3v1->year);
		//GET ID
		memset(pID3v1->id, '\0', sizeof(pID3v1->id));
		_tcsncpy_s(pID3v1->id, sizeof(pID3v1->id), tags->id, sizeof(tags->id));
		NormalizeTagString(pID3v1->id);
		//GET GENRE
		pID3v1->genre = tags->genre;
	} else {
		return FALSE;
	}

	return TRUE;
}

BOOL GetThumbnailImage(WCHAR *filename, TCHAR *imagedata, int imagesize, int imagewidth, int imageheight)
{
	WCHAR temp[MAX_PATH];
	FILE *tfile;

	wsprintfW(temp, L"%s.temp", filename);

	_wfopen_s(&tfile, temp, L"w+b");

	if (tfile) {
		fwrite(imagedata, imagesize, 1, tfile);
		fclose(tfile);
		MLConvertImage(temp, filename, imagewidth, imageheight, TRUE, TRUE);
	} else {
		return FALSE;
	}

	return TRUE;
}

BOOL GetMP3AlbumCover(wchar_t *filename, WCHAR *outfilename, int imagewidth)
{
	ID3v2_tag *tags = load_tag(filename);

	if (tags) {
		ID3v2_frame *frame = tag_get_album_cover(tags);
		if (frame) {
			ID3v2_frame_apic_content *apic = parse_apic_frame_content(frame);
			if (apic) {
				GetThumbnailImage(outfilename, apic->data, apic->picture_size, imagewidth, imagewidth);
				free(apic->data);
				free_tag(tags);
				return TRUE;
			}
			return FALSE;
		}
		else {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

BOOL GetMP3ID3v2Tags(wchar_t *filename, ptPartID3v2 pID3v2)
{
	//ID3v2_frame_text_content *text = parse_text_frame_content(frame);
	//ID3v2_frame_text_content *text = parse_text_frame_content(frame);
	//MessageBox(NULL, text->, "", MB_OK);
	//ID3v2_frame_apic_content *pic = parse_apic_frame_content(frame);

	return TRUE;
}

BOOL CheckValidTags(TCHAR *artist, TCHAR *title)
{
	if (_tcscmp(artist, "") == 0) {
		return FALSE;
	}
	if (_tcscmp(title, "") == 0) {
		return FALSE;
	}

	return TRUE;
}


void SearchMusicInFolder(HWND hWnd, WCHAR *folder, SearchProc proc, int curr_playlist)
{
	HANDLE fff;
	WIN32_FIND_DATAW fdata;
	HSTREAM hStream;
	int count;
	WCHAR mask[MAX_PATH];
	TCHAR ttemp[MAX_PATH], temp[MAX_PATH], filename[MAX_PATH], mfilename[MAX_PATH];
	tPartID3v1 pID3v1;
	//tPartID3v2 pID3v2;
	tListViewData ldata;
	BOOL bfind = TRUE;

	swprintf_s(mask, sizeof(WCHAR)* MAX_PATH, L"%s\\*.mp3", folder);
	fff = FindFirstFileW(mask, &fdata);

	if (fff != INVALID_HANDLE_VALUE) {
		count = ListView_GetItemCount(hWnd);
		while (bfind) {
			swprintf_s(mask, MAX_PATH, L"%s\\%s", folder, fdata.cFileName);
			
			hStream = BASS_StreamCreateFile(FALSE, mask, 0, 0, BASS_UNICODE);

			if (hStream != 0) {
				if (playlists[curr_playlist - 1].pcount == 0) {
					playlists[curr_playlist - 1].pdata = malloc(sizeof(tPlayListData));
				}
				else {
					playlists[curr_playlist - 1].pdata = realloc(playlists[curr_playlist - 1].pdata,
						sizeof(tPlayListData)* (playlists[curr_playlist - 1].pcount + 1));
				}

				wcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount].wfilename,
					sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount].wfilename), mask);

				playlists[curr_playlist - 1].pcount++;

				/* GETS NUMBER */
				_stprintf_s(ldata.number, sizeof(ldata.number), " %d", count + 1);

				/* GETS BITRATE */
				_stprintf_s(ldata.bitrate, sizeof(ldata.bitrate), "%d kbps", GetMP3Bitrate(hStream));

				/* GETS LENGTH */
				DWORD slength = GetMP3Length(hStream);
				playlists[curr_playlist - 1].plength += slength;
				SecondsToTime(slength, ttemp);
				_tcscpy_s(ldata.length, sizeof(ldata.length), ttemp);

				/* PUTS FILENAME */
				WideCharToMultiByte(CP_UTF8, 0, mask, sizeof(mask), filename, sizeof(filename), NULL, NULL);

				_tcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].filename,
					sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].filename), filename);

				/* GETS ID3v1 TAGS */
				if (GetMP3ID3v1Tags(hStream, &pID3v1) && CheckValidTags(pID3v1.artist, pID3v1.title)) {
					playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].id3v1 = pID3v1;
					_stprintf_s(ttemp, MAX_PATH, "%s - %s", pID3v1.artist, pID3v1.title);
					playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].isvtags = TRUE;
				}
				else {
					WideCharToMultiByte(CP_ACP, 0, fdata.cFileName, sizeof(fdata.cFileName), mfilename, sizeof(mfilename), NULL, NULL);
					_tcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].mfilename,
						sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].mfilename), mfilename);
					GetNameFromTrackName(mfilename, temp);
					_tcscpy_s(ttemp, sizeof(ttemp), temp);
					playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].isvtags = FALSE;
				}

				_tcscpy_s(ldata.trackname, sizeof(ldata.trackname), ttemp);
				playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].ldata = ldata;

				AddToMusicListView(playlists[curr_playlist - 1].mlListView.listView, ldata);
				count++;

				BASS_StreamFree(hStream);

				proc(playlists[curr_playlist - 1].pcount);
			}

			bfind = FindNextFileW(fff, &fdata) != 0;
		}
		FindClose(fff);
	}
}

void SearchMusicInFile(HWND hWnd, WCHAR *filename, SearchProc proc, int curr_playlist)
{
	HSTREAM hStream;
	int count;
	TCHAR ttemp[MAX_PATH], temp[MAX_PATH], mfilename[MAX_PATH];
	tPartID3v1 pID3v1;
	tListViewData ldata;

	hStream = BASS_StreamCreateFile(FALSE, filename, 0, 0, BASS_UNICODE);

	if (hStream != 0) {
		count = ListView_GetItemCount(hWnd);

		if (playlists[curr_playlist - 1].pcount == 0) {
			playlists[curr_playlist - 1].pdata = malloc(sizeof(tPlayListData));
		} else {
			playlists[curr_playlist - 1].pdata = realloc(playlists[curr_playlist - 1].pdata,
				sizeof(tPlayListData)* (playlists[curr_playlist - 1].pcount + 1));
		}

		wcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount].wfilename,
			sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount].wfilename), filename);

		playlists[curr_playlist - 1].pcount++;

		/* GETS NUMBER */
		_stprintf_s(ldata.number, sizeof(ldata.number), " %d", count + 1);

		/* GETS BITRATE */
		_stprintf_s(ldata.bitrate, sizeof(ldata.bitrate), "%d kbps", GetMP3Bitrate(hStream));

		/* GETS LENGTH */
		DWORD slength = GetMP3Length(hStream);
		playlists[pcount - 1].plength += slength;
		SecondsToTime(slength, ttemp);
		_tcscpy_s(ldata.length, sizeof(ldata.length), ttemp);

		/* PUTS FILENAME */
		WideCharToMultiByte(CP_UTF8, 0, filename, sizeof(temp), temp, sizeof(temp), NULL, NULL);

		_tcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].filename,
			sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].filename), temp);

		WideCharToMultiByte(CP_ACP, 0, filename, sizeof(temp), mfilename, sizeof(mfilename), NULL, NULL);

		_tcscpy_s(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].mfilename,
			sizeof(playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].mfilename), mfilename);

		/* GETS ID3v1 TAGS */
		if (GetMP3ID3v1Tags(hStream, &pID3v1) && CheckValidTags(pID3v1.artist, pID3v1.title)) {
			playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].id3v1 = pID3v1;
			_stprintf_s(ttemp, MAX_PATH, "%s - %s", pID3v1.artist, pID3v1.title);
			playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].isvtags = TRUE;
		} else {
			GetNameFromPathName(mfilename, ttemp);
			playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].isvtags = FALSE;
		}

		_tcscpy_s(ldata.trackname, sizeof(ldata.trackname), ttemp);
		playlists[curr_playlist - 1].pdata[playlists[curr_playlist - 1].pcount - 1].ldata = ldata;

		AddToMusicListView(playlists[curr_playlist - 1].mlListView.listView, ldata);
		count++;

		BASS_StreamFree(hStream);
	}

	proc(playlists[curr_playlist - 1].pcount);
}

ptPlayList GetPlayLists()
{
	return playlists;
}