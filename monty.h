#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* opcode token */
extern char **op_toks;

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


/*tools.c*/
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int monty(FILE *fd);

/*tools1.c*/
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/*tools2.c*/
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void set_op_tok_error(int error_code);


/*functions.c*/
void mpush(stack_t **stack, unsigned int line_number);
void mpall(stack_t **stack, unsigned int line_number);
void mpint(stack_t **stack, unsigned int line_number);
void mpop(stack_t **stack, unsigned int line_number);
void mswap(stack_t **stack, unsigned int line_number);

/*functions1.c*/
void madd(stack_t **stack, unsigned int line_number);
void msub(stack_t **stack, unsigned int line_number);
void mdiv(stack_t **stack, unsigned int line_number);
void mmul(stack_t **stack, unsigned int line_number);
void mmod(stack_t **stack, unsigned int line_number);

/*functions2.c*/
void mnop(stack_t **stack, unsigned int line_number);
void mpchar(stack_t **stack, unsigned int line_number);
void mpstr(stack_t **stack, unsigned int line_number);
void mrotl(stack_t **stack, unsigned int line_number);
void mrotr(stack_t **stack, unsigned int line_number);

/*functions3.c*/
void mstack(stack_t **stack, unsigned int line_number);
void mqueue(stack_t **stack, unsigned int line_number);

/*errors.c*/
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/*errors1.c*/
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/*aux.c*/
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);


#endif
