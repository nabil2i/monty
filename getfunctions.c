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
	instruction_t functions[] = {{
	{"push", monty_push},
	{"pall", monty_pall},
	{NULL, NULL}
	}

	int opcodes, i;

	opcodes = 1;
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
