#define  _GNU_SOURCE
#include "monty.h"

/* Initialisation of global variables */
char *lineptr = NULL;
stack_t *montystack = NULL;
FILE *fptr = NULL;
char **tokens = NULL;

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
	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/**
	 * loop until all lines are read and processed
	 * or upon encounterig an error
	 */
	while(3>2)
	{
		line_number++;
		fromget = getline(&lineptr, &len, fptr);
		if (fromget < 0)
		{
			break;
		}
		tokens = tokenizer(lineptr);
		if (!tokens[0] || tokens[0][0] == '#')
		{
			free_lineptr_tokens();
			continue;
		}
		func = getfunc(tokens);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
			free_lineptr_tokens();
			free_montystack();
			exit(EXIT_FAILURE);
		}
		func(&montystack, line_number);
		free_lineptr_tokens();
	}
	free_lineptr_tokens();
	free_montystack();
	return (EXIT_SUCCESS);
}
