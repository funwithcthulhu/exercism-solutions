#include "atbash_cipher.h"

char* atbash_encode(char *input)
{
	int length = strlen(input);
	char *encoded = calloc(length, sizeof(char));
	int counter = 0;
	int check = 5;

	for (int i = 0; i < length; i++)
	{
		if (counter % check == 0 && counter > 0 && input[i + 1])
		{
			encoded[counter++] = ' ';
			check += 6;
		}
		if (isalpha(input[i]))
			encoded[counter++] = (219 - tolower(input[i]));
		else if (isdigit(input[i]))
			encoded[counter++] = input[i];
	}

	return encoded;
}

char* atbash_decode(char *input)
{
	int length = strlen(input);
	char *decoded = calloc(length, sizeof(char));
	int counter = 0;

	for (int i = 0; i < length; i++)
	{
		if (isalpha(input[i]))
			decoded[counter++] = (219 - tolower(input[i]));
		else if (isdigit(input[i]))
			decoded[counter++] = input[i];
	}
	return decoded;
}

