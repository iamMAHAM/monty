#include "monty.h"

/**
 * push - pushs the integer to stack
 * @st: the stack
 * @n: the integer to add
 * Return: the new stack
 */
stack_t *push(stack_t *st, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	check_malloc(new);
	new->n = n;
	new->prev = NULL;
	if (st)
		new->next = st;
	st = new;

	return (new);
}

/**
 * print_stack - prints all stack element
 *
 * @st: the stack
 */
void print_stack(stack_t *st)
{
	if (is_empty_stack(st))
	{}
	else
	{
		while (st)
		{
			printf("%d\n", st->n);
			st = st->next;
		}
	}
}
