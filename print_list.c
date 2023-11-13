#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int a = 0;

	for (; list; list = list->next, ++a)
	{
	if (a > 0)

	printf(", ");

	printf("%d", list->n);
	}

	printf("\n");
}
