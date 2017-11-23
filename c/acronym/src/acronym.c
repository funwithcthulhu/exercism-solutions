#include "acronym.h"

char* abbreviate(char *phrase)
{
	if (phrase == NULL || !phrase[0])
		return NULL;

	int length = strlen(phrase);
	int memsize = getMemSize(phrase);
	char *acronym = malloc(sizeof(char) * memsize);
	int j = 0;

	// sets the first character of the acronym to the first character
	// of phrase, then increments the counter by 1;
	acronym[j++] = phrase[0];

	// adds characters which follow spaces or the '-' sign
	// to the acronym string ('-' is a special case in the tests)
	for (int i = 0; i < length; i++ )
	{
		if (isspace(phrase[i]) || phrase[i] == '-')
		{
			acronym[j] = toupper(phrase[i + 1]);
			j++;
		}
	}
	acronym[j] = '\0';

	return acronym;
}

/* Starts at 2: 1 for the first character of the phrase
which won't be caught by the function, and one for the null
terminator. Increments the size by 1 for every space or '-'
character, assuming that the character that follows will be 
included in the acronym
*/
int getMemSize(char *phrase)
{
	int length = strlen(phrase);
	int size = 2;
	for (int i = 0; i < length; i++)
	{
		if (isspace(phrase[i]) || phrase[i])
		{
			size++;
		}
	}
	return size;
}
