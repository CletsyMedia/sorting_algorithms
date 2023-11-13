#include "sort.h"

/**
 * swap_integers - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
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
 * selection_sort - Sorts an array of integers using the Selection Sort
 *	algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: This function applies the Selection Sort algorithm to arrange
 * the elements of the input array in ascending order. The algorithm
 * iteratively selects the smallest element and swaps it with the element at
 * the current index. The process is repeated until the entire array is sorted.
 */
void selection_sort(int *array, size_t size)
{
	int *min_idx;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min_idx = array + a;
		for (b = a + 1; b < size; b++)
			min_idx = (array[b] < *min_idx) ? (array + b) : min_idx;

		if ((array + a) != min_idx)
		{
			swap_integers(array + a, min_idx);
			print_array(array, size);
		}
	}
}
