#include "monty.h"

/**
*main - runs the monty program
*@argc: counts argument
*@argv: gets argument value fron stdin
*Return: 0 Always success
*/

int monty_push = 0;

int main(char argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	m_read(argv[1], &stack);
	return (0);
}
