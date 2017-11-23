#include "largest_series_product.h"

long long largest_series_product(char *series, int size)
{	
	if (!charactersValid(series))
		return -1;

	int j = 0;
	char single_digit[2];
	long long num;
	long long total = 0;
	long long temp = 1;
	int length = strlen(series);

	if (size > length)
		return -1ll;

	do
	{
		for (int i = j; i < (j + size); i++)
		{
			single_digit[0] = series[i];
			single_digit[1] = '\0';
			num = atoll(single_digit);
			temp *= num;
		}
		if (temp > total)
			total = temp;

		j++;
		temp = 1;
	} while (j < (length - size + 1));

	return total;
}

int charactersValid(char *series)
{
	int length = strlen(series);
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(series[i]))
			return 0;
	}
	return 1;
}
