#include "monty.h"

/**
 * m_read - reads from the stdin
 * @name: opening of newfile
 * @stack: pointer to the stack_t list
 * Return: void
 */


void m_read(char *name, stack_t **stack)
{
	FILE *new_file = fopen(name, "r");
	char *size = NULL;
	char *get_line;
	size_t len = 0;
	ssize_t read_line;
	int i = 1;
	void (*func)(stack_t**, unsigned int);


	if (new_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&size, &len, new_file)) != -1)
	{
		get_line = m_parse(size, stack, i);

		if (get_line[0] == '\n' || get_line[0] == '#')
		{
			i++;
			continue;
		}

		func = get_op_func(get_line);
		if (func == 0)
		{
			printf("L%d: unknown instruction %s\n", i, get_line);
			exit(EXIT_FAILURE);

		}
		func(stack, i);
		i++;
	}
	free(size);
	free(get_line);
	fclose(new_file);
}
