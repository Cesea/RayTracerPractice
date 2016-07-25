#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include "Color.h"
#include <float.h>

static Color black(0);
static Color white(0);
static Color red(1.0, 0.0, 0.0);
static Color green(0.0, 1.0, 0.0);
static Color blue(0.0, 0.0, 1.0);

static double EPSILON = 0.0000001;
static double MAX = DBL_MAX;

#endif