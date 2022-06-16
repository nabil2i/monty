#include "monty.h"
/**
 * monty_push - handles opcode push
 * @top: double pointer to stack to push to
 * @line_number: line number of the opcode in the file
 */
void monty_push(stack_t **top, unsigned int line_number)
{

	stack_t *new;
	int i, number;

	if (monty_g.tokens[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_lineptr_tokens();
		free_montystack();
		free_fptr();
		exit(EXIT_FAILURE);
	}

	for (i = 0; monty_g.tokens[1][i] != '\0'; i++)
	{
		if (isalpha(monty_g.tokens[1][i]) != 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_lineptr_tokens();
			free_montystack();
			free_fptr();
			exit(EXIT_FAILURE);
		}
	}

	number = atoi(monty_g.tokens[1]);
	new = add_node_top(top, number);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_lineptr_tokens();
		free_montystack();
		free_fptr();
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_pall - prints all the values on the stack
 *	starting from the top
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack != NULL)
	{
		print_list(*stack);
	}
	else
	{
		;
	}
}

/**
 * monty_pint - print vales at the top of stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L %d:  can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}

/**
 * monty_swap - lorem
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
