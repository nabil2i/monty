#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - main arguments
 * @argc: arguments count
 * @bcfile: name of the monty byte code file
 * @line_number: current line number in the file
 *
 * Description: restructuring the arguments passed to main
 */

/*
typedef struct args_s
{
	int argc;
	char *bcfile;
	int line_number;
} args_t;
*/

extern char *lineptr;
extern stack_t *montystack;
extern FILE *fptr;
extern char **tokens;

/* monty.c
void montymain(args_t *arg)*/

/* stringoperations */
int count(char *str);
char **tokenizer(char *str);

/* getfunctions */
void (*getfunc(char **str))(stack_t **stack, unsigned int line_number);

/* opcode functions */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* listoperations */
size_t print_list(const stack_t *head);
stack_t *add_node_top(stack_t **top, int number);

/* opcodes2 */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);

/* opcodes3 */
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/* opcodes4 */
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/* freefunctions */
void free_lineptr_tokens(void);
void free_montystack(void);
void free_fptr(void);
void free_arrays(char **ar_str);
void free_list(stack_t *h);

#endif
