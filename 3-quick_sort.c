#include <stdio.h>

/**
 * swap - Function to swap two elements
 * */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *partition -  Function to partition the array using Lomuto partition scheme
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 *quick_sort - Function to perform Quick sort
 */
void quick_sort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

/**
 * quick_sort_wrapper - Wrapper function for Quick sort
 */
void quick_sort_wrapper(int *array, size_t size)
{
	quick_sort(array, 0, size - 1);
}
