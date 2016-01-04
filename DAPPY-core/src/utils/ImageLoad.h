#pragma once

#include<FreeImage.h>
#include<string>
#include<GL\glew.h>

namespace dappy {
	static BYTE* load_image(const char *filename,  GLsizei* width, GLsizei* height)
	{
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP *dib = nullptr;
		BYTE* bits = nullptr;
		
		fif = FreeImage_GetFileType(filename, 0);
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(filename);
		if (fif == FIF_UNKNOWN)
			return nullptr;

		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);
		if (!dib)
			return nullptr;

		bits = FreeImage_GetBits(dib);
		*width = (GLsizei)FreeImage_GetWidth(dib);
		*height = (GLsizei)FreeImage_GetHeight(dib);
		
		

		
		return bits;

	}
}