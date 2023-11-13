#include "sort.h"

void merge_sort(int *array, size_t size);
void merger_subarray(int *subarray, int *buffs, size_t top, size_t mid,
	size_t bottom);
void merger_sort_recurse(int *subarray, int *buffs, size_t top, size_t bottom);

/**
 * merge_sort - Sorts an array of integers using the merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: The size of the array
 *
 * Description:
 * This function applies the merge sort algorithm to the input array.
 * It divides the array into smaller halves, sorts each half recursively,
 * and then merges them back together to form a sorted array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffs;

	if (array == NULL || size < 2)
	return;
	buffs = malloc(sizeof(int) * size);
	if (buffs == NULL)
	return;
	merger_sort_recurse(array, buffs, 0, size);

	free(buffs);
}

/**
 * merger_subarray - Merges two subarrays within a larger array
 * @subarray: Pointer to the main subarray
 * @buffs: Pointer to the auxiliary buffer array
 * @top: Index of the start of the first subarray
 * @mid: Index of the middle element (split point)
 * @bottom: Index of the end of the second subarray
 *
 * Description:
 * This function merges two subarrays (from top to mid and mid+1 to bottom)
 * into a single sorted subarray within the main array.
 */
void merger_subarray(int *subarray, int *buffs, size_t top, size_t mid,
	size_t bottom)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + top, mid - top);

	printf("[right]: ");
	print_array(subarray + mid, bottom - mid);

	for (a = top, b = mid; a < mid && b < bottom; c++)
	buffs[c] = (subarray[a] < subarray[b]) ? subarray[a++] : subarray[b++];
	for (; a < mid; a++)
	buffs[c++] = subarray[a];
	for (; b < bottom; b++)
	buffs[c++] = subarray[b];
	for (a = top, c = 0; a < bottom; a++)
	subarray[a] = buffs[c++];

	printf("[Done]: ");
	print_array(subarray + top, bottom - top);
}

/**
 * merger_sort_recurse - Recursively sorts a subarray using the merge sort
 * algorithm
 * @subarray: Pointer to the main subarray
 * @buffs: Pointer to the auxiliary buffer array
 * @top: Index of the start of the subarray
 * @bottom: Index of the end of the subarray
 *
 * Description:
 * This function recursively divides the subarray into smaller halves,
 * sorts each half, and then merges them back together to form a sorted
 * subarray.
 */
void merger_sort_recurse(int *subarray, int *buffs, size_t top, size_t bottom)
{
	size_t mid;

	if (bottom - top > 1)
	{
	mid = top + (bottom - top) / 2;
	merger_sort_recurse(subarray, buffs, top, mid);
	merger_sort_recurse(subarray, buffs, mid, bottom);
	merger_subarray(subarray, buffs, top, mid, bottom);
	}
}
