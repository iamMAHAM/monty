#include "monty.h"

/**
 * check_malloc - checks if malloc failed
 * @st: the stack to check malloc
 * Return: 0 if not failed detected otherwise exit the program
 */
int check_malloc(stack_t *st)
{
	if (st == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * is_empty_stack - checks if stack is empty
 * @st: the stack to check
 * Return: true if empty, otherwise false
 */
boolean is_empty_stack(stack_t *st)
{
	if (st == NULL)
		return (true);
	return (false);
}

