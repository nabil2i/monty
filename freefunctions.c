#include "monty.h"

/**
 * free_lineptr_tokens - frees lineptr and tokens
 */
void free_lineptr_tokens(void)
{
	if (monty_g.lineptr != NULL)
	{
		free(monty_g.lineptr);
		monty_g.lineptr = NULL;
		free_arrays(monty_g.tokens);
		monty_g.tokens = NULL;
	}
}

/**
 * free_montystack - frees the stack
 */
void free_montystack(void)
{
	if (monty_g.montystack)
	{
		free_list(monty_g.montystack);
		monty_g.montystack = NULL;
	}
}

/**
 * free_fptr - frees fptr
 */
void free_fptr(void)
{
	if (monty_g.fptr)
	{
		fclose(monty_g.fptr);
		monty_g.fptr = NULL;
	}
}

/**
 * free_arrays - frees arrays
 * @ar_str: arrays of strings
 */
void free_arrays(char **ar_str)
{
	int i;

	if (ar_str == NULL)
	{
		return;
	}
	for (i = 0; ar_str[i]; i++)
	{
		free(ar_str[i]);
	}
	free(ar_str);

}

/**
 * free_list - frees a list
 * @h: doubly linked list
 */
void free_list(stack_t *h)
{
	stack_t *temp;

	while (h != NULL)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}
