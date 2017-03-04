
BOOL DownloadFile(TCHAR *url, TCHAR *toFile, BOOL isDeleteCache);
BOOL DownloadTopSongsImages(void);
BOOL DownloadTopArtistsImages(void);
BOOL CreateRecursiveDirectory(TCHAR *folder_path);
BOOL CheckDownloadStatus(int state);