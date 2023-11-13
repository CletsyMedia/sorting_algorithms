#include "sort.h"

int get_maximum(int *array, int size);
void radix_counter_sort(int *array, size_t size, int sig_dig, int *buffs);
void radix_sort(int *array, size_t size);

/**
 * get_maximum - Get the maximum value in the array
 * @array: the array to get the maximum value
 * @size: the size of the array to get the maximum value
 *
 * Return: the maximum value in the array
 */
int get_maximum(int *array, int size)
{
	int a = 1;
	int maximum = array[0];

	while (a < size)
	{
	if (array[a] > maximum)
	maximum = array[a];

	a++;
	}

	return (maximum);
}

/**
 * radix_counter_sort - Sorts an array of integers using the Radix Counting
 *	Sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * @sig_dig: The current significant digit during the sort.
 * @buffs: Pointer to an auxiliary buffer for temporary storage.
 *
 * Description: This function performs Radix Counting Sort on the input array,
 * considering the specified significant digit. It utilizes an auxiliary buffer
 * for temporary storage during the sorting process.
 */
void radix_counter_sort(int *array, size_t size, int sig_dig, int *buffs)
{
	int counter[10] = {0};

	/* Count occurrences of each digit at the current significant digit */
	for (size_t i = 0; i < size; i++)
	counter[(array[i] / sig_dig) % 10]++;

	/* Update counter array to store the actual position of each digit */
	for (int i = 1; i < 10; i++)
	counter[i] += counter[i - 1];

	/* Build the sorted array using the counter array */
	for (int i = size - 1; i >= 0; i--)
	{
	int digit = (array[i] / sig_dig) % 10;

	buffs[--counter[digit]] = array[i];
	}

	/* Copy the sorted elements back to the original array */
	for (size_t i = 0; i < size; i++)
	array[i] = buffs[i];
}

/**
 * radix_sort - Sorts an array of integers using the Radix Sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: This function applies the Radix Sort algorithm to arrange the
 * elements of the input array in ascending order. It operates based on the
 * individual digits of the numbers, starting from the least significant digit.
 */

void radix_sort(int *array, size_t size)
{
	int maxim, sig_dig, *buffs;

	if (array == NULL || size < 2)
		return;

	buffs = malloc(sizeof(int) * size);
	if (buffs == NULL)
		return;

	maxim = get_maximum(array, size);
	for (sig_dig = 1; maxim / sig_dig > 0; sig_dig *= 10)
	{
		radix_counter_sort(array, size, sig_dig, buffs);
		print_array(array, size);
	}

	free(buffs);
}
