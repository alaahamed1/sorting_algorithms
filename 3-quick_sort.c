#include "sort.h"

/**
 * partition - partitions the array using Lomuto partition scheme
 * @array: array to partition
 * @size: size of the array
 * @start: start of the partition
 * @end: end of the partition
 * @print: pointer to the print function
 * Return: index of the pivot element
 */
size_t partition(int *array, size_t size, long start, long end,
				 void (*print)(const int *, size_t))
{
	long i, j;
	int tmp, pivot;

	pivot = array[end];
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print(array, size);
			}
		}
	}
	if (array[end] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print(array, size);
	}
	return (i + 1);
}

/**
 * recursive_quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @start: start of the partition
 * @end: end of the partition
 * @print: pointer to the print function
 */
void recursive_quick_sort(int *array, size_t size, long start, long end,
						  void (*print)(const int *, size_t))
{
	size_t pi;

	if (start < end)
	{
		pi = partition(array, size, start, end, print);
		recursive_quick_sort(array, size, start, pi - 1, print);
		recursive_quick_sort(array, size, pi + 1, end, print);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, size, 0, size - 1, print_array);
}
