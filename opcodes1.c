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
		free_everything();
		exit(EXIT_FAILURE);
	}

	for (i = 0; monty_g.tokens[1][i] != '\0'; i++)
	{
		if (isalpha(monty_g.tokens[1][i]) != 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_everything();
			exit(EXIT_FAILURE);
		}
	}

	number = atoi(monty_g.tokens[1]);
	if (monty_g.sq_mode == 1)
		new = add_node_top(top, number);
	else if (monty_g.sq_mode == 0)
		new = add_node_queue(top, number);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
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
 * monty_pint - print values at the top of stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * monty_pop - removes the top element
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}

	remove_top(stack);
}

/**
 * monty_swap - swap top two elements in stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1;
	size_t nodes;

	nodes = count_nodes(stack);
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->next;
	temp1 = (*stack)->next;
	(*stack)->next->next = (*stack);
	(*stack)->next->prev = (*stack)->prev;
	if (temp)
	{
		temp->prev = temp1->next;
	}
	temp1->next->prev = temp1;
	temp1->next->next = temp;
	(*stack) = temp1;
}
