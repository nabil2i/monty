#include "monty.h"

/**
 * remove_queue - removes an element at the bottom
 * @h: list
 *
 * Return: data removed
 */
int remove_queue(stack_t **h)
{

	stack_t *last;
	int num = 0;

	last = *h;
	if (*h == NULL)
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

/**
 * remove_at_index - removes a node at index idx
 * @idx: index
 * @h: list
 *
 * Return: 1 if success and 0 if failure
 */
int remove_at_index(stack_t **h, unsigned int idx)
{
	stack_t *temp = *h;
	unsigned int i = 0;

	if (!idx)
	{
		(*h) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < idx)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);

}

/**
 * get_node - get the node at the index
 * @h: list
 * @idx: index
 *
 * Return: address of the node
 */
stack_t *get_node(stack_t *h, unsigned int idx)
{
	unsigned int i = 0;

	if (!h)
	{
		return (NULL);
	}
	while (h && i < idx)
	{
		h = h->next;
		i++;
	}

	if (h)
		return (h);
	else
		return (NULL);
}
