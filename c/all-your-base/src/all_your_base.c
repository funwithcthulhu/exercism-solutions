#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base,
			  int16_t output_base, size_t input_length)
{
	size_t n = 0;
	size_t output_length = 0;
	int8_t temp;
	int8_t digit;

	if (input_base < 0 || output_base <= 1)
		return 0;
	
	for (size_t i = 0; i < input_length; i++)
	{
		digit = digits[i];
		if (digit < 0 || digit >= input_base)
			return 0;
		if (n == 0 && digit == 0)
			return 0;
		n = n * input_base + digit;
	}

	while (n > 0)
	{
		digits[output_length] = n % output_base;
		n /= output_base;
		output_length++;
	}

	for (size_t j = 0; j < output_length / 2; j++)
	{
		temp = digits[j];
		digits[j] = digits[output_length - j - 1];
		digits[output_length - j - 1] = temp;
	}

	return output_length;
}

