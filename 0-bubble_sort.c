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
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description:
 * This function uses the Bubble Sort algorithm to sort the given integer
 * array in ascending order. It compares adjacent elements, swaps them if
 * they are in the wrong order, and repeats this process until the array is
 * sorted. The function also prints the array after each swap.
 *
 * Return: No return value (void). The original array is sorted in place.
 */
void bubble_sort(int *array, size_t size)
{
	size_t a;
	bool bubb_sort = false;
	size_t length = size;

	if (array == NULL || size < 2)
	return;

	while (bubb_sort == false)
	{
	bubb_sort = true;
	for (a = 0; a < length - 1; a++)
	{
	if (array[a] > array[a + 1])
	{
	swap_integers(array + a, array + a + 1);
	print_array(array, size);
	bubb_sort = false;
	}
	}
	length--;
	}
}
