#include "word_count.h"
#include <stdio.h>

int word_count(const char *input_text, word_count_word_t *words)
{
	// reset the structure 
	for (int k = 0; k < MAX_WORDS; k++)
	{
		strncpy(words[k].text, "", MAX_WORD_LENGTH);
		words[k].count = 0;
	}

	char *copy = sanitizeSentence(strdup(input_text));
	char *str;
	str = strtok(copy, " ");
	int counter = 0;
	int i;

	while (str != NULL)
	{
		if (strlen(str) > MAX_WORD_LENGTH)
			return -1;
		
		if (counter >= MAX_WORDS)
			return -2;

		if (counter > 0 && wordAlreadyExists(str, counter, words))
		{
			for (i = 0; i < counter; i++)
			{
				if (strncmp(str, words[i].text, MAX_WORD_LENGTH) == 0)
				{
					words[i].count++;
					strncpy(words[i].text, str, MAX_WORD_LENGTH);
					str = strtok(NULL, " ");
					break;
				}
			}
		}
		else
		{
			words[counter].count = 1;
			strncpy(words[counter++].text, str, MAX_WORD_LENGTH);
			str = strtok(NULL, " ");
		}
	}
	free(copy);
	return counter;
}

char* sanitizeSentence(char *string)
{
	char *sanitized = malloc(sizeof(string));
	int length = strlen(string);

	for (int i = 0; i < length; i++)
	{
		if (isalnum(string[i]) || wordWithApostrophe(string, i))
		{
			sanitized[i] = tolower(string[i]);
		}
		else
		{
			sanitized[i] = ' ';
		}
	}
	sanitized[length] = '\0';
	return sanitized;
}

int wordWithApostrophe(char *string, int i)
{
	return (string[i] == '\'' && isalpha(string[i - 1]) && isalpha(string[i + 1]));
}

int wordAlreadyExists(char *str, int size, word_count_word_t *words)
{
	for (int i = 0; i < size; i++)
	{
		if (strncmp(str, words[i].text, MAX_WORD_LENGTH) == 0)
			return 1;
	}
	return 0;
}
