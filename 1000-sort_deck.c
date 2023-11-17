#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_val(deck_node_t *card);
void inserting_sort_deck_kind(deck_node_t **deck);
void inserting_sort_deck_val(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: An integer less than, equal to, or greater than zero
 *
 * Description: This function compares the two strings @s1 and @s2 and returns
 * an integer value based on the comparison result. The comparison is performed
 * using ASCII values of the characters in the strings.
 */
int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
		;

	return ((*s1 != *s2) ? (*s1 - *s2) : 0);
}

/**
 * get_val - Retrieves the value of a card from a deck node.
 *
 * @card: Pointer to the deck node containing the card.
 *
 * Return: The value of the card.
 *
 * Description: This func retrieves and returns the value of a card from the
 * specified deck node @card. The value is determined based on the card's rank.
 */
char get_val(deck_node_t *card)
{
	const char *values[] = {"Ace", "1", "2", "3", "4", "5",
													"6", "7", "8", "9", "10", "Jack", "Queen"};
	const size_t num_values = sizeof(values) / sizeof(values[0]);

	size_t a;

	for (a = 0; a < num_values; a++)
	{
		if (_strcmp(card->card->value, values[a]) == 0)
			return ((char)a);
	}
	/* Default value for unmatched strings (e.g., "King") */
	return ((char)num_values);
}

/**
 * inserting_sort_deck_kind - Sorts a deck of cards by their kinds using
 *	the insertion sort algorithm.
 *
 * @deck: Pointer to the head of the deck of cards.
 *
 * Description: This function applies the insertion sort algorithm to sort a
 * deck of cards by their kinds. The sorting is performed in-place on the
 * input deck.
 */
void inserting_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterator, *insert, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL && insert->card->kind > iterator->card->kind)
		{
			insert->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insert;
			iterator->prev = insert->prev;
			iterator->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterator;
			else
				*deck = iterator;
			insert->prev = iterator;
			insert = iterator->prev;
		}
	}
}

/**
 * inserting_sort_deck_val - Sorts a deck of cards by their values using
 *	the insertion sort algorithm.
 *
 * @deck: Pointer to the head of the deck of cards.
 *
 * Description: This function applies the insertion sort algorithm to sort a
 * deck of cards by their values. The sorting is performed in-place on the
 * input deck.
 */
void inserting_sort_deck_val(deck_node_t **deck)
{
	deck_node_t *iterator, *insert, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL &&
					 insert->card->kind == iterator->card->kind &&
					 get_val(insert) > get_val(iterator))
		{
			insert->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = insert;
			iterator->prev = insert->prev;
			iterator->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterator;
			else
				*deck = iterator;
			insert->prev = iterator;
			insert = iterator->prev;
		}
	}
}

/**
 * sort_deck - Sorts a deck of cards using a combination of sorting algorithms.
 *
 * @deck: Pointer to the head of the deck of cards.
 *
 * Description: This function sorts a deck of cards using a combination of
 * sorting algorithms based on the card values and kinds. It applies specific
 * sorting functions to achieve the desired order.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	inserting_sort_deck_kind(deck);
	inserting_sort_deck_val(deck);
}
