#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	prev = current;

	/* Traverse express lane to find the range */
	while (current->express != NULL)
	{
		prev = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		if (current->n >= value)
			break;
	}

	/* If we reached end of express lane without finding >= value */
	if (current->express == NULL && current->n < value)
	{
		prev = current;
		/* Go to the last node */
		while (current->next != NULL)
			current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, current->index);

	/* Linear search between prev and current */
	while (prev != NULL && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		if (prev->n > value)
			return (NULL);

		prev = prev->next;
	}

	return (NULL);
}
