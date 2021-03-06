#include "monty.h"

/**
 * monty_mod - multiply the second top element with
 *	the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	size_t nodes;
	int mod = 0;
	stack_t *new;

	nodes = count_nodes(stack);
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	remove_top(stack);
	remove_top(stack);

	new = add_node_top(stack, mod);
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_pchar - prints the char at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	putchar(temp->n);
	putchar('\n');
}

/**
 * monty_pstr - prints the string starting at the top
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = (*stack);
	if (temp == NULL)
	{
		printf("\n");
		return;
	}
	while (temp && temp->n != 0 && temp->n >= 0 && temp->n <= 127)
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * monty_rotl - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	stack_t *temp;

	(void)line_number;
	temp = *stack;

	if (temp == NULL)
	{
		return;
	}
	num = remove_top(stack);
	add_node_queue(stack, num);
}

/**
 * monty_rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	size_t nodes = 0;
	stack_t *temp;

	temp = *stack;
	nodes = count_nodes(stack);
	(void)line_number;

	if (temp == NULL)
	{
		return;
	}
	temp = get_node(temp, nodes - 1);
	num = temp->n;
	remove_at_index(stack, nodes - 1);
	add_node_top(stack, num);
}
