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
