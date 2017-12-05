#include "nth_prime.h"

int nth(size_t nth)
{
	if (nth < 1)
		return 0;

	size_t count = 0;
	int prime = 1;
	
	while (count < nth)
	{
		if (isPrime(++prime))
		{
			count++;
		}
	}
	return prime;
}

int isPrime(int n)
{
	if (n == 1)
		return 0;
	else if (n < 4)
		return 1;
	else if (n % 2 == 0)
		return 0;
	else if (n < 9)
		return 1;
	else if (n % 3 == 0)
		return 0;
	else
	{
		int r = floor(sqrt(n));
		int f = 5;
		while (f <= r)
		{
			if (n % f == 0)
				return 0;
			else if (n % (f + 2) == 0)
				return 0;
			f += 6;
		}
		return 1;
	}
}
