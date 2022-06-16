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
