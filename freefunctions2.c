#include "monty.h"

/**
 * free_everything - frees all
 */
void free_everything(void)
{
	free_lineptr_tokens();
	free_montystack();
	free_fptr();
}
