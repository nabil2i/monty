#include "monty.h"
/**
 * monty_push - handles opcode push
 * @stack: double pointer to stack to push to
 * @line_num: line number of the opcode in the file
 */
void monty_push(stack_t **top, unsigned_int line_num)
{

	stack_t *new, *temp;
	int i, number;

	if (tokens[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; tokens[1][i] != '\0'; i++)
	{
		if (isalpha(tokens[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	number = atoi(token[1][i]);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}

	new->n = number;
	new->next = *top;
	new->prev = NULL;

	return (new);
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
