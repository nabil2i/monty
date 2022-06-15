#include "monty.h"
#include <stdio.h>

/* Initialisation of global variables */
char *line = NULL;
stack_t **montystack = NULL;
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
	args_s args;

	args.ac = argc;
	args.bcfile = argv[1];
	args.line_number = 0;
	montymain(&args);
	return (EXIT_SUCCESS);

}

/**
 * montymain - proper main function
 * @arg: pointer to arguments of main build in struct
 *
 * Return: Nothing
 */
void montymain(args_t *arg)
{
	/* if more than 1 argument */
	if (arg->ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
}
