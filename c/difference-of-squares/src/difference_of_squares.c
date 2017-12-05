#include "difference_of_squares.h"

int_fast32_t square_of_sum(int_fast32_t n)
{
	int_fast32_t result = 0;
	for (int_fast32_t i = 1; i <= n; i++)
	{
		result += i;
	}
	return result * result;
}

int_fast32_t sum_of_squares(int_fast32_t n)
{
	int_fast32_t result = 0;
	for (int_fast32_t i = 1; i <= n; i++)
	{
		result += (i * i);
	}
	return result;
}

int_fast32_t difference_of_squares(int_fast32_t n)
{
	return square_of_sum(n) - sum_of_squares(n);
}
