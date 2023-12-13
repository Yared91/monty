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

	if (new_file == NULL)
	{
		fpintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	char *size = NULL;
	char *get_line;
	size_t len = 0;
	size_t read_line;
	int i = 1;
	op_instruction func;

	while (1)
	{
		read_line = getline(&size, &len, new_file);
		if (read_line == -1)
			break;
		get_line = m_parse(size, stack, i);

		if (get_line[0] == '\n' || get_line[0] == '#')
		{
			i++;
			continue;
		}

		func = get_op_func(get_line);
		if (func == NULL)
		{
			printf("L%d: unknown instruction %s\n", i, get_line);
			exit("EXIT_FAILURE");

		}
		func(stack, i);
		i++;
	}
	free(size);
	fclose(new_file);
}