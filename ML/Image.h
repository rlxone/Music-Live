
typedef struct _tagImage {
	HWND parent;
	HBITMAP bmp;
	HDC mem_hdc;
	RECT coord;
	BOOL ishide;
} tImage, *ptImage;

ptImage ImageCreate(HWND hWnd, HINSTANCE hInst, int imageres, int x, int y, int width, int height);
void ImagesUpdate(HDC hdc);
void ImageHide(ptImage image);
void ImageShow(ptImage image);
void ImageChangeDynamicBitmap(ptImage image, WCHAR *filename, BOOL isorginal, HINSTANCE hInst, int imageres);
void ImageChangeStaticBitmap(ptImage image, HINSTANCE hInst, int imageres);