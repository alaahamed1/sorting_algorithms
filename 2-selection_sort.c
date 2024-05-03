#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array:array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (!array || !size)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
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
}
