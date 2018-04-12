#ifndef BMP_H_
#define BMP_H_

// Windows BMP file structures
#ifndef WIN32
// Useful for non-windows compile targets
typedef struct
   __attribute__ ((packed)) /**** BMP file header structure ****/
   {
      unsigned short bfType; /* Magic number for file */
      unsigned int bfSize; /* Size of file */
      unsigned short bfReserved1; /* Reserved */
      unsigned short bfReserved2; /* ... */
      unsigned int bfOffBits; /* Offset to bitmap data */
   } BITMAPFILEHEADER;

typedef struct
   __attribute__ ((packed)) /**** BMP file info structure ****/
{
   unsigned int biSize; /* Size of info header */
   int biWidth; /* Width of image */
   int biHeight; /* Height of image */
   unsigned short biPlanes; /* Number of color planes */
   unsigned short biBitCount; /* Number of bits per pixel */
   unsigned int biCompression; /* Type of compression to use */
   unsigned int biSizeImage; /* Size of image data */
   int biXPelsPerMeter; /* X pixels per meter */
   int biYPelsPerMeter; /* Y pixels per meter */
   unsigned int biClrUsed; /* Number of colors used */
   unsigned int biClrImportant; /* Number of important colors */
} BITMAPINFOHEADER;

typedef struct
{
   unsigned char rgbBlue;
   unsigned char rgbGreen;
   unsigned char rgbRed;
   unsigned char rgbReserved;
} RGBQUAD;

typedef struct
{
   BITMAPINFOHEADER bmiHeader;
   RGBQUAD bmiColors[1];
} BITMAPINFO;
#else
#include <windows.h>
#endif /* !WIN32 */

#endif /*BMP_H_*/
