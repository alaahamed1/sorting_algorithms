#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array:array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int i, j;
	int temp;
	int min = i;

	if (!array || !size)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size - 1 - i; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
	}
	if (min != i)
	{
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
