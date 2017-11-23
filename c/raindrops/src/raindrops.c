#include "raindrops.h"

char convert(char *result, int number)
{
	char *str;
	
	if (number % 3 == 0)
		strcat(result, "Pling");
	if (number % 5 == 0)
		strcat(result, "Plang");
	if (number % 7 == 0)
		strcat(result, "Plong");

	if (strlen(result) == 0)
	{
		asprintf(&str, "%d", number);
		strcat(result, str);
	}
		
	return *result;
}
