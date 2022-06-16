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
 * struct monty_global_s - monty global variable
 * @lineptr: pointer to a line of text
 * @montystack: stack
 * @fptr: file
 * @tokens: arrays of strings
 *
 * Description: structuring global variables
 */
typedef struct monty_global_s
{
	char *lineptr;
	stack_t *montystack;
	FILE *fptr;
	char **tokens;
} global_t;

extern global_t monty_g;

/* Macros */
#define UNKNOWN_INST "L%d: unknown instruction %s\n"

/* stringoperations */
int count(char *str);
char **tokenizer(char *str);

/* getfunctions */
void (*getfunc(char **str))(stack_t **stack, unsigned int line_number);

/* opcodes1 */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* listoperations */
size_t print_list(const stack_t *head);
stack_t *add_node_top(stack_t **top, int number);
size_t count_nodes(stack_t **h);
int remove_top(stack_t **h);

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

/* freefunctions2 */
void free_everything(void);
#endif
