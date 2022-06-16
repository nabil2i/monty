#include "monty.h"

/**
 * print_list - prints a doubly linked list
 * @head: pointer to the stack
 *
 * Return: Nothing
 */
size_t print_list(const stack_t *head)
{
	size_t num_nodes;

	num_nodes = 0;
	if (head == NULL)
	{
		return (0);
	}
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		num_nodes++;
	}
	return (num_nodes);
}

/**
 * add_node_top - adds a note on top of a stack
 * @top: pointer to top of the stack
 * @number: data to add
 *
 * Return: Nothing
 */
stack_t *add_node_top(stack_t **top, int number)
{
	stack_t *new;

	if (!top)
	{
		return (NULL);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		return (NULL);
	}

	new->n = number;
	new->next = (*top);
	if (*top)
	{
		(*top)->prev = new;
	}
	new->prev = NULL;
	(*top) = new;

	return (new);
}

/**
 * count_nodes - counts the nodes in the list
 * @h: list
 *
 * Return: number of nodes
 */
size_t count_nodes(stack_t **h)
{
	stack_t *temp;
	size_t num_nodes;

	num_nodes = 0;
	temp = (*h);
	if (!temp)
	{
		return (0);
	}

	while (temp)
	{
		num_nodes++;
		temp = temp->next;
	}

	return (num_nodes);
}
/**
 * remove_top - deletes the top element
 * @h: list
 *
 * Return: data deleted
 */
int remove_top(stack_t **h)
{
	stack_t *temp;
	int num = 0;

	temp = (*h);
	num = temp->n;
	(*h) = (*h)->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	temp->next = NULL;
	free(temp);
	return (num);
}

/**
 * add_node_queue - adds a node at the queue
 * @h: list
 * @number: data to add
 * Return: address of the added node
 */
stack_t *add_node_queue(stack_t **h, int number)
{
	stack_t *new, *last;

	last = *h;
	if (!h)
	{
		return (NULL);

	}
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*h == NULL)
	{
		new->prev = NULL;
		*h = new;
		return (new);
	}
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
	new->prev = last;
	return (new);

}
