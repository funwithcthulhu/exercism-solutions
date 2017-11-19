#include "isogram.h"

//int main(int argc, char *argv[])
//{
//	is_isogram(argv[1]);
//}
int is_isogram(char *string)
{
	int size = strlen(string);
	//printf("%i\n", size);
	int letters[26] = {0};
	for (int i = 0; i < size; i++)
	{
		letters[tolower(string[i]) % 97]++;
	}
	for (int j = 0; j < 26; j++)
	{
		if (letters[j] > 1)
		{
			return 0;
		}
	}
	return 1;
}
