#include "sort.h"

void swap(int *x, int *y);
int part(int *arr, int l, int r);
void sort(int *arr, int l, int r, size_t size);

/**
 * quick_sort - Sort an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}

/**
 * swap - Swap values of two integers
 *
 * @x: First integer
 * @y: Second integer
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * part - Partition an array
 *
 * @arr: The array to be partitioned
 * @l: Left index
 * @r: Right index
 *
 * Return: The index of the pivot
 */
int part(int *arr, int l, int r)
{
	int p, i, j;

	p = arr[r];
	i = l - 1;
	j = l;
	while (j < r)
	{
		if (arr[j] < p)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

/**
 * sort - helper function for quick_sort
 *
 * @arr: The array to be sorted
 * @l: Left index
 * @r: Right index
 * @size: Size of the array
 */
void sort(int *arr, int l, int r, size_t size)
{
	int p;

	if (l < r)
	{
		p = part(arr, l, r);
		print_array(arr, size);
		sort(arr, l, p - 1, size);
		sort(arr, p + 1, r, size);
	}
}
