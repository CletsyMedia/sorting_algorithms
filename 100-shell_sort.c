#include "sort.h"

/**
 * swap_integers - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * Description:
 * This function swaps the values stored in the memory locations
 * pointed to by @a and @b.
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description:
 * This function implements the shell sort algorithm with the Knuth interval
 * sequence to sort the given array of integers in ascending order. It adjusts
 * the intervals and compares and swaps elements as needed to sort the array
 * efficiently.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t a;
	size_t b;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_integers(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
