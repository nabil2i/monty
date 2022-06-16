#include "monty.h"

/**
 * remove_queue - removes an element at the bottom
 * @h: list
 *
 * Return: data removed
 */
int remove_queue(stack_t **h)
{

	stack_t *last, *secondlast;
	int num = 0;

	last = *h;
	if (h == NULL)
	{
		return (0);
	}
	if ((*h)->next == NULL)
	{
		num = (*h)->n;
		*h = NULL;
		free(h);
		return (num);
	}
	while (last->next)
	{
		last = last->next;
	}

	num = last->n;
	last->prev->next = NULL;
	free(last);
	return (num);
}
