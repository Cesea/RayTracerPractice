#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Color.h"

/*
	Image class will contain Color buffer range 0.0 ~ 1.0
	When it Write to file it will convert that range to 0 ~ 255 unsigned char 
*/

class Image
{
	public :
		Image();
		Image(int width_, int height);
		~Image();

		void WritePPM(const char *outfile);
		void Clear(Color& color);

		//propertry accessors
		Color pixel(int x, int y);
		void pixel(int x, int y, Color pxl);
		void clamp(double d);

	private :
		int width;
		int height;
		Color *buffer;
};


#endif
