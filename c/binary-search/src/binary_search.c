#include "binary_search.h"

int* binary_search(int target, int arr[], size_t length)
{
	if (!arr || !length)
		return NULL;

	int middle;
	int max = length - 1;
	int min = 0;

	do
	{
		middle = (max + min) / 2;

		if (arr[middle] == target)
			return &arr[middle];
		else if (arr[middle] > target)
			max = middle - 1;
		else if (arr[middle] < target)
			min = middle + 1;
		
		if (max < min)
			break;
			
	} while (1);

	return 0;
}
