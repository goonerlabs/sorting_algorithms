#include "sort.h"

void merge_arrs(int *arr, int *arr_cp, size_t l, size_t m, size_t r);

void div_arrs(int *arr_cp, int *arr, size_t s, size_t e);


/**
 * merge_sort - Sort an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr_cp;
	size_t i = 0;

	if (!array || size < 2)
		return;

	arr_cp = malloc(sizeof(int) * size);
	if (!arr_cp)
		return;

	while (i < size)
	{
		arr_cp[i] = array[i];
		i++;
	}
	div_arrs(arr_cp, array, 0, size);
	free(arr_cp);
}

/**
 * merge_arrs - merges two arrays
 * 
 * @arr: The array to be sorted
 * @arr_cp: copy of the array
 * @l: left index
 * @m: middle index
 * @r: right index
 */

void merge_arrs(int *arr, int *arr_cp, size_t l, size_t m, size_t r)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	for (i = l; i < m; i++)
		printf("%d%s", arr[i], (i < m - 1) ? ", " : "");
	printf("\n[right]: ");
	for (i = m; i < r; i++)
		printf("%d%s", arr[i], (i < r - 1) ? ", " : "");
	printf("\n");
	for (i = l, j = m, k = l; k < r; k++)
	{
		if (i < m && (j >= r || arr[i] <= arr[j]))
		{
			arr_cp[k] = arr[i];
			i++;
		}
		else
		{
			arr_cp[k] = arr[j];
			j++;
		}
	}
	for (k = l; k < r; k++)
		arr[k] = arr_cp[k];
	printf("[Done]: ");
	for (i = l; i < r; i++)
		printf("%d%s", arr[i], (i < r - 1) ? ", " : "");
	printf("\n");
}

/**
 * div_arrs - divides an array into smaller arrays
 * 
 * @arr_cp: copy of the array
 * @arr: The array to be sorted
 * @s: start index
 * @e: end index
 */

void div_arrs(int *arr_cp, int *arr, size_t s, size_t e)
{
	size_t m;

	if (e -s > 2)
		return;

	m = s + (e - s) / 2;
	div_arrs(arr, arr_cp, s, m);
	div_arrs(arr, arr_cp, m, e);
	merge_arrs(arr, arr_cp, s, m, e);
}






















	
