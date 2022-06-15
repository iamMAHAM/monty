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
boolean is_empty_stack(stack_t **st)
{
	if (st == NULL)
		return (true);
	return (false);
}

/**
 * get_func - check for valid command
 * @commands: a command to check
 * Return: a pointer to the function
 */
void (*get_func(char **commands))(stack_t **, unsigned int)
{
	int length;
	int i;
	instruction_t p[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	length = 2;
	for (i = 0; i < length; i++)
	{
		if (strcmp(p[i].opcode, commands[0]) == 0)
		{
			return (p[i].f);
		}
	}
	return (NULL);
}

/**
 * add_dnodeint - adds a new node at the beginning of a list.
 * @st: the node
 * @n: number to add in a node
 * Return: the address of the new element
 */
stack_t *add_dnodeint(stack_t **st, unsigned int n)
{
	stack_t *new;

	if (!st)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *st;
	new->prev = NULL;

	if (*st)
		(*st)->prev = new;

	*st = new;

	return (new);
}

/**
 * add_dnodeint_end - add node end
 * @st: the st
 * @n: the number
 * Return: added node
 */
stack_t *add_dnodeint_end(stack_t **st, unsigned int n)
{
	stack_t *new;
	stack_t *current = *st;

	if (!st)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*st == NULL)
	{
		new->prev = NULL;
		*st = new;
		return (new);
	}

	while (current->next)
		current = current->next;

	current->next = new;
	new->prev = current;

	return (new);
}
