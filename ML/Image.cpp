
#include "stdafx.h"
#include "Image.h"

tImage imageArray[20];
int imageArraySize = 0;

ptImage ImageCreate(HWND hWnd, HINSTANCE hInst, int imageres, int x, int y, int width, int height)
{
	int index = ++imageArraySize - 1;

	imageArray[index].bmp = LoadBitmap(hInst, MAKEINTRESOURCE(imageres));

	HDC hdc = GetDC(hWnd);

	imageArray[index].mem_hdc = CreateCompatibleDC(hdc);

	SelectObject(imageArray[index].mem_hdc, imageArray[index].bmp);

	ReleaseDC(hWnd, hdc);

	imageArray[index].coord.left = x; imageArray[index].coord.top = y;
	imageArray[index].coord.right = x + width; imageArray[index].coord.bottom = y + height;

	imageArray[index].parent = hWnd;
	imageArray[index].ishide = FALSE;

	return &(imageArray[index]);
}

void ImagesUpdate(HDC hdc)
{
	for (int i = 0; i < imageArraySize; ++i) {
		if (!imageArray[i].ishide) {
			BitBlt(hdc, imageArray[i].coord.left, imageArray[i].coord.top,
				imageArray[i].coord.right - imageArray[i].coord.left, imageArray[i].coord.bottom - imageArray[i].coord.top,
				imageArray[i].mem_hdc, 0, 0, SRCCOPY);
		}
	}
}

void ImageHide(ptImage image)
{
	for (int i = 0; i < imageArraySize; ++i) {
		if (&imageArray[i] == image) {
			imageArray[i].ishide = TRUE;
			InvalidateRect(imageArray[i].parent, &imageArray[i].coord, FALSE);
			break;
		}
	}
}

void ImageShow(ptImage image)
{
	for (int i = 0; i < imageArraySize; ++i) {
		if (&imageArray[i] == image) {
			imageArray[i].ishide = FALSE;
			InvalidateRect(imageArray[i].parent, &imageArray[i].coord, FALSE);
			break;
		}
	}
}

void ImageChangeStaticBitmap(ptImage image, HINSTANCE hInst, int imageres)
{
	for (int i = 0; i < imageArraySize; ++i) {
		if (&imageArray[i] == image) {
			DeleteObject(imageArray[i].bmp);
			imageArray[i].bmp = LoadBitmap(hInst, MAKEINTRESOURCE(imageres));
			SelectObject(imageArray[i].mem_hdc, imageArray[i].bmp);
			InvalidateRect(image[i].parent, &imageArray[i].coord, FALSE);
		}
	}
}

void ImageChangeDynamicBitmap(ptImage image, WCHAR *filename, BOOL isorginal, HINSTANCE hInst, int imageres)
{
	for (int i = 0; i < imageArraySize; ++i) {
		if (&imageArray[i] == image) {
			DeleteObject(image[i].bmp);
			if (isorginal) {
				imageArray[i].bmp = LoadBitmap(hInst, MAKEINTRESOURCE(imageres));
			} else {
				imageArray[i].bmp = LoadImageW(GetModuleHandle(NULL), filename, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
			}
			SelectObject(imageArray[i].mem_hdc, imageArray[i].bmp);
			InvalidateRect(imageArray[i].parent, &imageArray[i].coord, FALSE);
			break;
		}
	}
}