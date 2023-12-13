#include "monty.h"

/**
 * m_parse - splits the read_line file
 * @get_line: gets the arguments from stdin
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: parsed result
 */

char *m_parse(char *get_line, stack_t **stack, unsigned int line_number)
{
	char *op;
	char *add;
	char *args;

	add = "push";
	op = strtok(get_line, "\n");

	if (strcmp(op, add) == 0)
	{
		args = strtok(NULL, "\n");
		if (checknum(args))
		{
			monty_push = atoi(args);
		}
		else
		{
			printf("L%d usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else if (op == NULL)
	{
		return (NULL);

	}
		free(stack);
		return (op);
}
