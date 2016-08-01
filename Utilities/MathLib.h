#ifndef __MATH_H__
#define __MATH_H__

#include <stdlib.h>
#include <math.h>

static int rand_int()
{
	return rand();
}

static float rand_float()
{
	return float(rand_int()) / float(RAND_MAX);
}

static double rand_double()
{
	return double(rand_int()) / double(RAND_MAX);
}
#endif
