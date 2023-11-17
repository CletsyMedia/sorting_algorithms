#include "sort.h"

void swap_integers(int *a, int *b);
int lomuto_array_partition(int *array, size_t size, int left, int right);
void lomuto_array_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_array_partition - Lomuto partition scheme for quicksort.
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int lomuto_array_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int top = left;
	int bottom = left;

	/* Continue until bottom is strictly less than right */
	while (bottom < right)
	{
	if (array[bottom] < *pivot)
	{
	if (top != bottom)
	{
	swap_integers(array + bottom, array + top);
	print_array(array, size);
	}
	top++;
	}
	bottom++;
	}

	if (array[top] > *pivot)
	{
	swap_integers(array + top, pivot);
	print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_array_sort - Sorts an array of integers using the Lomuto partition.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: This function implements the quicksort algorithm through
 * recursion, utilizing the Lomuto partition scheme for efficient sorting.
 */
void lomuto_array_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
	partition = lomuto_array_partition(array, size, left, right);

	lomuto_array_sort(array, size, left, partition - 1);

	lomuto_array_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
	lomuto_array_sort(array, size, 0, size - 1);
	}
}
