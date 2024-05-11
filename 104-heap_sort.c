#include "sort.h"

void swap(int *x, int *y);
void max_heap(int *arr, size_t s, size_t e, size_t size);
void heapify(int *arr, size_t size);

/**
 * heap_sort - Sort an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t e;

	if (!array || size < 2)
		return;

	heapify(array, size);
	e = size - 1;
	while (e > 0)
	{
		swap(&array[e], &array[0]);
		print_array(array, size);
		e--;
		max_heap(array, 0, e, size);
	}
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
 * max_heap - ensures correct heap order
 *
 * @arr: The array to be sorted
 * @s: start index
 * @e: end index
 * @size: Number of elements in the array
 */
void max_heap(int *arr, size_t s, size_t e, size_t size)
{
	size_t r = s, c, i;

	while ((r * 2 + 1) <= e)
	{
		c = r * 2 + 1;
		i = r;
		if (arr[i] < arr[c])
			i = c;
		if ((c + 1) <= e && arr[i] < arr[c + 1])
			i = c + 1;
		if (i == r)
			return;
		swap(&arr[i], &arr[r]);
		print_array(arr, size);
		r = i;
	}
}

/**
 * heapify - heapifies an array
 *
 * @arr: The array to be sorted
 * @size: Number of elements in @array
 */

void heapify(int *arr, size_t size)
{
	size_t s = (size - 2) / 2;

	while (1)
	{
		max_heap(arr, s, size - 1, size);
		if (s == 0)
			break;
		s--;
	}
}
