#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#ifndef ANAGRAM_H
#define ANAGRAM_H

#define MAX_STR_LEN 20

enum anagram_status {
   UNCHECKED = -1,
   NOT_ANAGRAM,
   IS_ANAGRAM
};

struct candidate {
   enum anagram_status is_anagram;
   const char *candidate;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for word.  Word buffer and candidate structures may be modified.
 */
void anagrams_for(const char *word, struct candidates *candidates);
int isAnagram(const char *word, char *comparator);
void findLetters(int *letter_array, char *word, int word_length);
int compareArrays(int *arrayone, int *arraytwo);
int sameWord(char *word, char *other_word, int length);

#endif
