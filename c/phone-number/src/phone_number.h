#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>

#define FORMATTED_NUMBER_LENGTH 14
#define CLEAN_NUMBER_LEGTH 10
#define WITH_CNTRY_CODE_LENGTH 11

char* phone_number_clean(const char *number);
char* phone_number_get_area_code(const char *number);
char* phone_number_format(const char *number);
