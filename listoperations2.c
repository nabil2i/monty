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
	secondlast = *h;

	while (last->next)
	{
		secondlast = last;
		last = last->next;
	}

	num = last->n;
	secondlast->next = NULL;
	last->prev = NULL;
	free(last);
	return (num);
}
