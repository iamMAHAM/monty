#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*---------------------------- STRUCTURES -------------------------------*/

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
 * enum boolean - true or false
 * @false: 0
 * @true: 1
 */
typedef enum boolean
{
	false,
	true
} boolean;

/*---------------------------- PROTOTYPES -------------------------------*/
boolean is_empty_stack(stack_t **st);
int check_malloc(stack_t *st);
void push(stack_t **st, unsigned int n);
void pall(stack_t **st, unsigned int n);
void print_stack(stack_t *st);
stack_t *add_dnodeint(stack_t **st, unsigned int n);
stack_t *add_dnodeint_end(stack_t **st, unsigned int n);
void free_stack(stack_t *st);
#endif