#include "monty.h"

/**
 * free_lineptr_tokens - frees lineptr and tokens
 */
void free_lineptr_tokens(void)
{
	if (lineptr != NULL)
	{
		free(lineptr);
		lineptr = NULL;
		free_arrays(tokens);
		tokens = NULL;
	}
}

/**
 * free_montystack - frees the stack
 */
void free_montystack(void)
{
	if (montystack)
	{
		free_list(montystack);
		montystack = NULL;
	}
}

/**
 * free_fptr - frees fptr
 */
void free_fptr(void)
{
	if (fptr)
	{
		fclose(fptr);
		fptr = NULL;
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
