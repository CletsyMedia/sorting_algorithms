#include "sort.h"

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
 * counting_sort - Arrange an array of integers in ascending order
 *	using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Display the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sorter, maxim, a;

	if (array == NULL || size < 2)
		return;

	sorter = malloc(sizeof(int) * size);
	if (sorter == NULL)
		return;
	maxim = get_maximum(array, size);
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(sorter);
		return;
	}

	for (a = 0; a < (maxim + 1); a++)
		counter[a] = 0;
	for (a = 0; a < (int)size; a++)
		counter[array[a]] += 1;
	for (a = 0; a < (maxim + 1); a++)
		counter[a] += counter[a - 1];
	print_array(counter, maxim + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorter[counter[array[a]] - 1] = array[a];
		counter[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorter[a];

	free(sorter);
	free(counter);
}
