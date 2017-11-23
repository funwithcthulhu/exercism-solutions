#include "grains.h"

unsigned long square(short int square)
{
	if (square < 1 || square > 64)
		return 0;

	unsigned long grains = 1;
	for (int i = 1; i < square; i++)
		grains *= 2;

	return grains;
}

unsigned long total(void)
{
	return TOTAL;
}
