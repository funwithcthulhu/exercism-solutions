#include "sum_of_multiples.h"

int_fast32_t sum_of_multiples(const unsigned int multiples[],
                              size_t size, int_fast32_t n)
{
	if (!multiples)
		return 0;

	int_fast32_t sum = 0;
	int_fast32_t j;

	for (j = 1; j < n; j++)
	{
		if (eligibleMultiple(multiples, size, j))
			sum += j;
	}

	return sum;
}

int_fast8_t eligibleMultiple(const unsigned int multiples[],
                             size_t size, int_fast32_t candidate)
{
	for (size_t i = 0; i < size; i++)
	{
		if (multiples[0] == 0)
			continue;
		if (candidate % multiples[i] == 0)
			return 1;
	}
	return 0;
}
