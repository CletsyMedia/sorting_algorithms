#include "sort.h"

void swap_integers(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Implements Hoare's partition scheme for quicksort.
 *
 * @array: Pointer to integers for partitioning.
 * @size: Total number of elements.
 * @left: Leftmost index of partition range.
 * @right: Rightmost index of partition range.
 *
 * Return: Final position of the pivot after partitioning.
 *
 * Description: Uses Hoare's scheme to rearrange elements in the specified
 * range of the array during quicksort. Selects a pivot and partitions
 * elements, placing smaller ones on the left and greater ones on the right.
 * Returns final pivot position.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, top, bottom;

	pivot = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
	do {
	top++;
	} while (array[top] < pivot);
	do {
	bottom--;
	} while (array[bottom] > pivot);

	if (top < bottom)
	{
	swap_integers(array + top, array + bottom);
	print_array(array, size);
	}
	}

	return (top);
}

/**
 * hoare_sort - Applies Hoare's quicksort algorithm to sort an array.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The total number of elements in the array.
 * @left: The leftmost index of the sorting range.
 * @right: The rightmost index of the sorting range.
 *
 * Description: This function utilizes Hoare's partition scheme in the
 * quicksort algorithm to efficiently sort the elements within the specified
 * range of the array. The sorting is performed in-place, and the final sorted
 * array is obtained after the function call.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
	partition = hoare_partition(array, size, left, right);
	hoare_sort(array, size, left, partition - 1);
	hoare_sort(array, size, partition, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers using Hoare's quicksort.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The total number of elements in the array.
 *
 * Description: This function applies Hoare's partition scheme within the
 * quicksort algorithm to efficiently sort the elements of the input array.
 * The sorting is performed in-place, resulting in a fully sorted array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	hoare_sort(array, size, 0, size - 1);
}
