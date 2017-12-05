#include "roman_numerals.h"

struct numeral_val dict[13] = { {1000, "M"}, {900, "CM"}, {500, "D"},
								{400, "CD"}, {100, "C"}, {90, "XC"},
								{50, "L"}, {40, "XL"}, {10, "X"},
								{9, "IX"}, {5, "V"}, {4, "IV"},
								{1, "I"} };

char* to_roman_numeral(int_fast16_t number)
{
	char *numerals = malloc(BUFFER * sizeof(char));
	numerals[0] = '\0';
	int_fast8_t np = 0;

	while (number > 0)
	{
		for (size_t i = 0; i < 13; i++)
		{
			if (number >= dict[i].n)
			{
				strcat(numerals, dict[i].r);
				np += strlen(dict[i].r);
				numerals[np] = '\0';
				number -= dict[i].n;
				break;
			}
		}
	}
	return numerals;
}
