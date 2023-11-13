#include "sort.h"

void swap_integers(int *a, int *b);
void bitonic_merger(int *array, size_t size, size_t start, size_t seq,
	char flow);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merger - Merges sub-sequences in a bitonic sequence.
 *
 * @array: Pointer to the array of integers to be merged.
 * @size: The total number of elements in the array.
 * @start: Starting index of the sub-sequence to be merged.
 * @seq: Size of the sub-sequence to be merged.
 * @flow: Merging direction ('1' for ascending, '0' for descending).
 *
 * Description: This function merges two sub-sequences within a bitonic
 * sequence, starting from the specified index and with the given size.
 * The merging direction is determined by the 'flow' parameter, where '1'
 * represents ascending and '0'
 * represents descending order.
 */
void bitonic_merger(int *array, size_t size, size_t start, size_t seq,
	char flow)
{
	size_t a, jumper = seq / 2;

	if (seq > 1)
	{
	for (a = start; a < start + jumper; a++)
	{
	if ((flow == UP && array[a] > array[a + jumper]) ||
	(flow == DOWN && array[a] < array[a + jumper]))
	swap_integers(array + a, array + a + jumper);
	}
	bitonic_merger(array, size, start, jumper, flow);
	bitonic_merger(array, size, start + jumper, jumper, flow);
	}
}

/**
 * bitonic_sequence - Generates a bitonic sequence within an array.
 *
 * @array: Pointer to the array of integers to form the bitonic sequence.
 * @size: The total number of elements in the array.
 * @start: Starting index of the sub-sequence to be bitonically ordered.
 * @seq: Size of the sub-sequence to be bitonically ordered.
 * @flow: Ordering direction ('1' for ascending, '0' for descending).
 *
 * Description: This function arranges a sub-sequence within an array into a
 * bitonic sequence, starting from the specified index and with the given size.
 * The ordering direction is determined by the 'flow' parameter, where '1'
 * represents ascending order, and '0' represents descending order.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
char flow)
{
	size_t cutter = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
	printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + start, seq);

	bitonic_sequence(array, size, start, cutter, UP);
	bitonic_sequence(array, size, start + cutter, cutter, DOWN);
	bitonic_merger(array, size, start, seq, flow);

	printf("Result [%lu/%lu] (%s):\n", seq, size, str);
	print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic Sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The total number of elements in the array.
 *
 * Description: This function applies the Bitonic Sort algorithm to arrange
 * the elements of the input array in ascending order. The sorting is performed
 * in bitonic order, leading to a sorted array at the end of the process.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	bitonic_sequence(array, size, 0, size, UP);
}
