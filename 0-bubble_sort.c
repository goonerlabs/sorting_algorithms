#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int no_sort, tmp;

	while (i < size - 1)
	{
		no_sort = 1;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				no_sort = 0;
				print_array(array, size);
			}
			j++;
		}
		if (no_sort)
			break;
		i++;
		j = 0;
	}
}

