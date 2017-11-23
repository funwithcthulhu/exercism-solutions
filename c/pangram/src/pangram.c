#include "pangram.h"

int is_pangram(const char *sentence)
{
	if (!sentence)
		return 0;
		
	char letters[26] = {0};
	int length = strlen(sentence);

	for (int i = 0; i < length; i++)
	{
		if (isalpha(sentence[i]))
		{
			letters[tolower(sentence[i]) % 97]++;
		}
	}
	return checkLetters(letters);
}

int checkLetters(char *letters)
{
	for (int i = 0; i < 26; i++)
	{
		if (letters[i] < 1)
			return 0;
	}
	return 1;
}
