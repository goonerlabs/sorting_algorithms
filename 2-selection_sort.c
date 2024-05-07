#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, n;
	int tmp;

	if (!array || size < 2)
		return;

	while (i < size - 1)
	{
		n = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[n])
				n = j;
			j++;
		}
		if (n != i)
		{
			tmp = array[i];
			array[i] = array[n];
			array[n] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
