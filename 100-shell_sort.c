#include <stdio.h>
#include "sort.h"

/**
 * calculate_initial_gap - Calculates the initial gap using Knuth sequence
 * @size: size of the array
 * Return: initial gap value
 */
void shell_sort(int *array, size_t size)
{
	int gap;

	for (gap = size / 3; gap > 0; gap /= 3)
	{
		gap = (gap % 2 == 0) ? gap + 1 : gap;
		for (int i = gap; i < size; i++)
		{
			int temp = array[i];
			int j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
	}
}