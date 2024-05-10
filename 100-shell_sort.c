#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending order
 * using the shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, g = 1;
	int tmp;

	if (!array || size < 2)
		return;

	while (g < size / 3)
		g = g * 3 + 1;

	while (g >= 1)
	{
		j = g;
		while (j < size)
		{
			i = j - g;
			while (i < size)
			{
				if (i + g >= size || array[i + g] >= array[i])
					break;
				tmp = array[i];
				array[i] = array[i + g];
				array[i + g] = tmp;
				if (i < g)
					break;
				i -= g;
			}
			j++;
		}
		print_array(array, size);
		g /= 3;
	}
}


