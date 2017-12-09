#include "series.h"
#include <stdio.h>

series_results_t series(char *input_text, unsigned int substring_length)
{
	series_results_t results;
	results.substring_count = 0;
	results.substring = calloc(MAX_SERIES_RESULTS, sizeof(char*));
	char *temp = calloc(MAX_SERIES_LENGTH, sizeof(char));

	if (substring_length < 1)
		return results;

	for (size_t i = 0; i < strlen(input_text); i++)
	{
		memset(temp, '\0', substring_length);
		strncat(temp, &input_text[i], substring_length);

		if (strlen(temp) == substring_length)
		{
			results.substring[i] = calloc(MAX_SERIES_LENGTH, sizeof(char));
			strcpy(results.substring[i], temp);
			results.substring_count++;
		}
	}
	return results;
}
