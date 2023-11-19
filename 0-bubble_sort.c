#include "sort.h"

/**
 * swap_integers - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool swapped;

	if (array == NULL || size < 2)
	return;

	do {
	swapped = false;
	for (i = 0; i < length - 1; i++)
	{
	if (array[i] > array[i + 1])
	{
	swap_integers(array + i, array + i + 1);
	print_array(array, size);
	swapped = true;
	}
	}
	length--;
	} while (swapped);
}
