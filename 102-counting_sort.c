#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int k, *arr1, *arr2;
	size_t i;

	if (!array || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > k)
			k = array[i];

	arr1 = malloc(sizeof(int) * (k + 1));
	if (!arr1)
		return;

	for (i = 0; i <= (size_t)k; i++)
		arr1[i] = 0;

	for (i = 0; i < size; i++)
		arr1[array[i]]++;

	for (i = 1; i <= (size_t)k; i++)
		arr1[i] = arr1[i] + arr1[i - 1];
	print_array(arr1, k + 1);

	arr2 = malloc(sizeof(int) * size);
	if (!arr2)
	{
		free(arr1);
		return;
	}

	for (i = size - 1; i != (size_t)-1; i--)
		arr2[--arr1[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = arr2[i];

	free(arr1);
	free(arr2);
}














