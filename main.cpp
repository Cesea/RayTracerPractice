#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "Image.h"

int main(int argc, char *argv[])
{
	const int width = 640;
	const int height = 480;

	Image image(width, height);
	image.GetTestPattern();
	image.WriteTga("WriteImage.tga");

	return 0;
}
