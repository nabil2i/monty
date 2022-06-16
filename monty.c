#define  _GNU_SOURCE
#include "monty.h"

/* Initialisation of global variables */
global_t monty_g = {NULL, NULL, NULL, NULL};

/**
 * main - entry point of the monty interpreter
 * @argc: arguments counts
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS if success and
 *	EXIT_FAILURE if failure
 */
int main(int argc, char *argv[])
{
	int fromget;
	size_t len;
	void (*func)(stack_t **, unsigned int);
	int line_number;

	fromget = 0;
	len = 0;
	line_number = 0;

	/* if more than 1 argument */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/**
	 * opening the monty bytecode file
	 */
	monty_g.fptr = fopen(argv[1], "r");
	if (!monty_g.fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/**
	 * loop until all lines are read and processed
	 * or upon encounterig an error
	 */
	while (5)
	{
		line_number++;
		fromget = getline(&monty_g.lineptr, &len, monty_g.fptr);
		if (fromget < 0)
		{
			break;
		}
		monty_g.tokens = tokenizer(monty_g.lineptr);
		if (!monty_g.tokens[0] || monty_g.tokens[0][0] == '#')
		{
			free_lineptr_tokens();
			continue;
		}
		func = getfunc(monty_g.tokens);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown ", line_number);
			fprintf(stderr, "instruction %s\n", monty_g.tokens[0]);
			free_lineptr_tokens();
			free_montystack();
			free_fptr();
			exit(EXIT_FAILURE);
		}
		func(&monty_g.montystack, line_number);
		free_lineptr_tokens();
	}
	free_lineptr_tokens();
	free_montystack();
	free_fptr();
	return (EXIT_SUCCESS);
}
