#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 16

struct numeral_val
{
	int_fast16_t n;
	char *r;
};

char* to_roman_numeral(int_fast16_t number);
