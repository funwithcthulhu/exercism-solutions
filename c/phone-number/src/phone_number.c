#include "phone_number.h"

char* phone_number_clean(const char *number)
{
	char *clean_number = calloc(CLEAN_NUMBER_LEGTH, sizeof(char));
	char *replacement = calloc(CLEAN_NUMBER_LEGTH, sizeof(char));
	size_t i, j = 0;

	for (i = 0; i < strlen(number); i++) {
		if (isalpha(number[i])) {
			memset(clean_number, '0', CLEAN_NUMBER_LEGTH);
			clean_number[CLEAN_NUMBER_LEGTH] = '\0';
			break;
		}
		if (isdigit(number[i])) {
			clean_number[j++] = number[i];
		}
	}

	if (strlen(clean_number) == 11 && (clean_number[0] == '1')) {
		strncpy(replacement, clean_number + 1, CLEAN_NUMBER_LEGTH);
		return replacement;
	}

	if (strlen(clean_number) != CLEAN_NUMBER_LEGTH) {
		memset(clean_number, '0', CLEAN_NUMBER_LEGTH);
		clean_number[CLEAN_NUMBER_LEGTH] = '\0';
	}

	return clean_number;
}

char* phone_number_get_area_code(const char *number)
{
	char *clean_number = phone_number_clean(number);
	char *area_code = calloc(3, sizeof(char));
	strncpy(area_code, clean_number, 3);

	return area_code;
}

char* phone_number_format(const char *number)
{
	char *clean_number = phone_number_clean(number);
	char *formatted_number = calloc(FORMATTED_NUMBER_LENGTH, sizeof(char));
	size_t i, j = 0;
	formatted_number[0] = '(';
	formatted_number[4] = ')';
	formatted_number[5] = ' ';
	formatted_number[9] = '-';
	for (i = 0; i < FORMATTED_NUMBER_LENGTH; i++) {
		if (i == 0 || i == 4 || i == 5 || i == 9) {
			continue;
		}
		formatted_number[i] = clean_number[j++];
	}
	return formatted_number;
}
