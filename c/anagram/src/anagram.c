#include "anagram.h"
// no unicode support

void anagrams_for(const char *word, struct candidates *candidates)
{
	char *temp;
	for (size_t i = 0; i < candidates->count; i++)
	{
		temp = strdup(candidates->candidate[i].candidate);
		candidates->candidate[i].is_anagram = isAnagram(word, temp);
	}

}

int isAnagram(const char *wword, char *comparator)
{
	char *word = strdup(wword);
	int length_word = strlen(word);
	int length_comparator = strlen(comparator);
	int word_letters[26] = {0};
	int temp_letters[26] = {0};

	if (length_word != length_comparator)
		return 0;
	if (sameWord(word, comparator, length_word))
		return 0;

	findLetters(word_letters, word, length_word);
	findLetters(temp_letters, comparator, length_comparator);

	return compareArrays(word_letters, temp_letters);	
}

void findLetters(int *letter_array, char *word, int word_length)
{
	char ch;
	for (int i = 0; i < word_length; i++)
	{
		ch = tolower(word[i]) - 'a';
		letter_array[(int)ch]++;
	}
}

int compareArrays(int *arrayone, int *arraytwo)
{
	for (int i = 0; i < 26; i++)
	{
		if (arrayone[i] != arraytwo[i])
			return 0;
	}
	return 1;
}

int sameWord(char *word, char *other_word, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (tolower(word[i]) != tolower(other_word[i]))
			return 0;
	}
	return 1;
}
