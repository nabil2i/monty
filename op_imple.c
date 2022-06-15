#include "monty.h"
/**
 * monty_push - handles opcode push
 * @stack: double pointer to stack to push to
 * @line_num: line number of the opcode in the file
 */
void monty_push(stack_t **stack, unsigned_int line_num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}

	new->n = ;
	new->prev = top;
	new->next = NULL;
}

/**
 * pall - prints all the values on the stack
 *	starting from the top
 * @stack: double pointer to the stack
 * @line_number - current line
 *
 * Return: Nothing
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		print_list(*stack);
	}
	else
	{
		;
	}
}
