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
	new->
