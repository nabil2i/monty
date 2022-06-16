#include "monty.h"

/**
 * monty_add - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Description: lorem
 * Return: Nothing
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	size_t nodes;
	int sum = 0;
	stack_t *new;

	nodes = count_nodes(stack);
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	remove_top(stack);
	remove_top(stack);

	new = add_node_top(stack, sum);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_nop - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Description: lorem
 * Return: Nothing
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_sub - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Description: lorem
 * Return: Nothing
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_div - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Description: lorem
 * Return: Nothing
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_mul - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Description: lorem
 * Return: Nothing
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
