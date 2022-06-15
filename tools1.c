#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @st: the st
 * Return: none
 */
void free_stack(stack_t *st)
{
	stack_t *current_node;
	stack_t *next_node;

	if (st)
	{
		current_node = st;
		next_node = st->next;
		while (next_node)
		{
			free(current_node);
			current_node = next_node;
			next_node = next_node->next;
		}
		free(current_node);
	}
}

/**
 * print_stack - prints all the elements of a stack_t list.
 * @st: the stack
 * Return: the number of elements
 */
void print_stack(stack_t *st)
{

	if (!st)
	{}

	while (st)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}
