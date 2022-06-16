#include "monty.h"

/**
 * main - the main program
 *
 * @argc: the arg count
 * @argv: the args
 * Return: int
 */
int main(int argc, char **argv)
{
	args_list *args;
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			args->arg = argv[i];
		}
	}

	while (args)
	{
		printf("args[%s]\n", args->arg);
		args = args->next;
	}
	
}