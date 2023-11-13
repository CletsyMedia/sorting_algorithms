#include "sort.h"

void swapping_node_fward(listint_t **list, listint_t **tail, listint_t **curr);
void swapping_node_bward(listint_t **list, listint_t **tail, listint_t **curr);
void cocktail_sort_list(listint_t **list);

/**
 * swapping_node_fward - Swap a node in a listint_t doubly-linked list
 *	list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node of the cocktail curr algo.
 */
void swapping_node_fward(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	if ((*curr)->prev)
	(*curr)->prev->next = temp;
	else
	*list = temp;

	temp->prev = (*curr)->prev;
	(*curr)->next = temp->next;

	if (temp->next)
	temp->next->prev = *curr;
	else
	*tail = *curr;

	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swapping_node_bward - Swap a node in a listint_t doubly-linked
 *	list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node.
 */
void swapping_node_bward(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *tempo = (*curr)->prev;

	if ((*curr)->next != NULL)
	(*curr)->next->prev = tempo;
	else
	*tail = tempo;
	tempo->next = (*curr)->next;
	(*curr)->prev = tempo->prev;
	if (tempo->prev != NULL)
	tempo->prev->next = *curr;
	else
	*list = *curr;
	(*curr)->next = tempo;
	tempo->prev = *curr;
	*curr = tempo;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *	ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail;
	listint_t *curr;
	bool curr_but_prev = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (tail = *list; tail->next != NULL;)
	tail = tail->next;

	while (curr_but_prev == false)
	{
	curr_but_prev = true;
	for (curr = *list; curr != tail; curr = curr->next)
	{
	if (curr->n > curr->next->n)
	{
	swapping_node_fward(list, &tail, &curr);
	print_list((const listint_t *)*list);
	curr_but_prev = false;
	}
	}
	for (curr = curr->prev; curr != *list;
	curr = curr->prev)
	{
	if (curr->n < curr->prev->n)
	{
	swapping_node_bward(list, &tail, &curr);
	print_list((const listint_t *)*list);
	curr_but_prev = false;
	}
	}
	}
}
