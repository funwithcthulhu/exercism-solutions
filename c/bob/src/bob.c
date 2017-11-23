#include "bob.h"

const char* hey_bob(char *phrase)
{
	char last = getLastChar(phrase);

	if (!noAlphas(phrase) && isAllCaps(phrase))
		return RESPONSE2;
	else if (last == '?')
		return RESPONSE1;
	else if (!last)
		return RESPONSE3;
	else
		return RESPONSE4;
}

char getLastChar(char *phrase)
{
	int length = strlen(phrase);
	int i = length - 1;
	char last;
	do
	{
		last = phrase[i];
		i--;
	} while (isspace(last));
	
	return last;
}

int noAlphas(char *phrase)
{
	int length = strlen(phrase);
	for (int i = 0; i < length; i++)
	{
		if (isalpha(phrase[i]))
			return 0;
	}
	return 1;
}

int isAllCaps(char *phrase)
{
	int length = strlen(phrase);
	for (int i = 0; i < length; i++)
	{
		char letter = phrase[i];
		if (isalpha(letter) && toupper(letter) != letter)
			return 0;
	}
	return 1;
}
