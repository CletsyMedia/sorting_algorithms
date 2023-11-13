#include "sort.h"

void swap_integers(int *a, int *b);
void maxim_heaper(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * maxim_heaper - Rearranges elements in an array to form a max heap
 * @array: Pointer to the array of integers
 * @size: The size of the array
 * @base: Index of the base element (starting point)
 * @root: Index of the root element (current position)
 *
 * Description:
 * This function modifies the input array to create a max heap.
 * It ensures that the value at the root index is greater than or equal
 * to its child nodes' values, recursively adjusting the heap structure.
 */
void maxim_heaper(int *array, size_t size, size_t base, size_t root)
{
	size_t child1, child2, large;

	child1 = 2 * root + 1;
	child2 = 2 * root + 2;
	large = root;

	if (child1 < base && array[child1] > array[large])
	large = child1;
	if (child2 < base && array[child2] > array[large])
	large = child2;

	if (large != root)
	{
	swap_integers(array + root, array + large);
	print_array(array, size);
	maxim_heaper(array, size, base, large);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: pointer to the array of integers to sort
 * @size: the number of elements in the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int a = size / 2 - 1;

	if (array == NULL || size < 2)
	return;

	while (a >= 0)
	{
	maxim_heaper(array, size, size, a);
	a--;
	}

	a = size - 1;

	while (a > 0)
	{
	swap_integers(array, array + a);
	print_array(array, size);
	maxim_heaper(array, size, a, 0);
	a--;
	}
}
