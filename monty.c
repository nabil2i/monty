#define  _GNU_SOURCE
#include "monty.h"

/* Initialisation of global variables */
global_t monty_g = {NULL, NULL, NULL, NULL, 1};

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
	int fromget = 0, line_number = 0;
	size_t len = 0;
	void (*func)(stack_t **, unsigned int);


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_g.fptr = fopen(argv[1], "r");
	if (!monty_g.fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (5)
	{
		line_number++;
		fromget = getline(&monty_g.lineptr, &len, monty_g.fptr);
		if (fromget < 0)
			break;
		monty_g.tokens = tokenizer(monty_g.lineptr);
		if (!monty_g.tokens[0] || monty_g.tokens[0][0] == '#')
		{
			free_lineptr_tokens();
			continue;
		}
		func = getfunc(monty_g.tokens);
		if (func == NULL)
		{
			fprintf(stderr, UNKNOWN_INST, line_number, monty_g.tokens[0]);
			free_everything();
			exit(EXIT_FAILURE);
		}
		func(&monty_g.montystack, line_number);
		free_lineptr_tokens();
	}
	free_everything();
	return (EXIT_SUCCESS);
}
