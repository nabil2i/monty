#include "monty.h"

/**
 * getfunc - chooses the function corresponding to the opcode
 * @str: the line got from the file
 *
 * Return: pointer to the opcode function
 *	NULL if failure
 */
void (*getfunc(char **str))(stack_t **stack, unsigned int line_number)
{
	instruction_t functions[] = {
	{"push", monty_push},
	{"pall", monty_pall},
	{"pint", monty_pint},
	{"pop", monty_pop},
	{"swap", monty_swap},
	{"add", monty_add},
	{"nop", monty_nop},
	{"sub", monty_sub},
	{"div", monty_div},
	{"mul", monty_mul},
	{"mod", monty_mod},
	{"pchar", monty_pchar},
	{"pstr", monty_pstr},
	{"rotl", monty_rotl},
	{"rotr", monty_rotr},
	{"stack", monty_stack},
	{"queue", monty_queue},
	{NULL, NULL}
	};

	int opcodes, i;

	opcodes = 17;
	i = 0;
	while (i < opcodes)
	{
		if (strcmp(functions[i].opcode, str[0]) == 0)
		{
			return (functions[i].f);
		}
		i++;
	}
	return (NULL);
}
