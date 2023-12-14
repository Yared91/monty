#include "monty.h"
#include <stdio.h>

/**
 * m_read - reads from the stdin
 * @name: opening of newfile
 * @stack: pointer to the stack_t list
 * Return: void
 */


void m_read(char *name, stack_t **stack)
{
	FILE *new_file;
	char *size = NULL;
	char *get_line;
	size_t len = 0;
	unsigned int i = 0;
	void (*func)(stack_t**, unsigned int);

	new_file = fopen(name, "r");

	if (new_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	while (fgets((char *)&size, (size_t)&len, new_file) != NULL)
	{
		get_line = m_parse(size, stack, i);

		if (get_line == NULL || get_line[0] == '#')
		{
			i++;
			continue;
		}

		func = get_op_func(get_line);
		if (func == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i, get_line);
			exit(EXIT_FAILURE);

		}
		func(stack, i);
		i++;
	}
	free(size);
	free(get_line);
	fclose(new_file);
}
