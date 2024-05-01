#include <stdio.h>
#include "sort.h"



void bubble_sort(int *array, size_t size)
{
    int temp;
    size_t i, j;
    i = 0;

    if(!array || !size)
    {
        return
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; i++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
