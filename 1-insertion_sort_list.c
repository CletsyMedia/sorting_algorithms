#include "sort.h"

/**
 * swapping_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @nd1: A pointer to the first node to swap.
 * @nd2: The second node to swap.
 *
 * Description:
 * This function swaps the positions of two nodes in a doubly-linked list.
 * It takes as input the head pointer 'h' of the list and two pointers
 * nd1' and 'nd2' to the nodes that need to be swapped. After the swap,
 * 'nd1' and 'nd2' switch positions in the list, and all necessary pointers
 * and connections are updated accordingly.
 *
 */
void swapping_nodes(listint_t **h, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;

	if (nd2->next != NULL)

	nd2->next->prev = *nd1;

	nd2->prev = (*nd1)->prev;

	nd2->next = *nd1;

	if ((*nd1)->prev != NULL)

	(*nd1)->prev->next = nd2;

	else
	*h = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description:
 * This function sorts a doubly linked list of integers in ascending order
 * using the insertion sort algorithm. It takes a pointer to the head of the
 * list as input, and it rearranges the elements within the list to achieve a
 * sorted order. After each swap operation, then prints the updated list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *integer, *insert, *tempo;

	if (!list || !*list || !((*list)->next))
	return;

	for (integer = (*list)->next; integer; integer = tempo)
	{
	tempo = integer->next;
	insert = integer->prev;
	while (insert && integer->n < insert->n)
	{
	swapping_nodes(list, &insert, integer);
	print_list((const listint_t *)*list);
	}
	}
}
