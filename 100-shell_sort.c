#include <stdio.h>
#include "sort.h"

/**
 * calculate_initial_gap - Calculates the initial gap using Knuth sequence
 * @size: size of the array
 * Return: initial gap value
 */
size_t calculate_initial_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	return gap;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = calculate_initial_gap(size);
	size_t i, j;
	int temp;

	while (gap > 0)
	{
		printf("Gap = %lu\n", gap);
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
