#include "monty.h"

/**
 * push - pushs the integer to stack
 * @st: the stack
 * @n: the integer to add
 * Return: the new stack
 */
void push(stack_t **st, unsigned int n)
{
	add_dnodeint(st, n);
}

void pall(stack_t **stack, unsigned int n)
{
	if (*stack)
		print_stack(*stack);
}
