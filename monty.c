#include "monty.h"

/**
*main - runs the monty program
*@argc: counts argument
*@argv: gets argument value fron stdin
*Return: 0 Always success
*/


int main(int argc, char **argv)
{
	stack_t **stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_read(argv[1], &(*stack));
	free_fun(stack);
	exit(EXIT_FAILURE);
}
