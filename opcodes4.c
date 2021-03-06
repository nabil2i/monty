#include "monty.h"

/**
 * monty_stack - monty stack
 * @stack: double pointer to the stack
 * @line_number: current line
 *i
 * Return: Nothing
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty_g.sq_mode = 1;
}
/**
 * monty_queue - monty queue
 * @stack: double pointer to the stack
 * @line_number: current line
 *
 * Return: Nothing
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty_g.sq_mode = 0;
}
