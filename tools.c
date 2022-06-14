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

/**
 * get_func - check for valid specifier
 * @format: a character to check
 * Return: a pointer to the function
 */
int (*get_func(const char *format))(va_list)
{
	int i;
	instruction_t p[] = {
		{"push", push},
		{"pall", print_stack},
		{NULL, NULL}
	};

	for (i = 0; p[i].opcode; i++)
	{
		if (*format == *(p[i].opcode))
		{
			return (p[i].f);
		}
	}
	return (NULL);
}
