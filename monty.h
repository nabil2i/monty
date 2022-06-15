#ifndef MONTY_H
#define MONTY_H

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
typedef struct args_s
{
	int argc;
	char *bcfile;
	int line_number;
} args_t;

extern char *line = NULL;
extern stack_t **montystack = NULL;
extern FILE *fptr = NULL;
extern **tokens = NULL;

/* monty.c */
void montymain(args_t *arg)
#endif
