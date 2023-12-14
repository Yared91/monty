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
	int monty_push = 0;
	line_number = 1;

	op = strtok(get_line, "\n\t\r\a");

	while (op != NULL)
	{
		if (monty_push == 1)
		{
			m_push(&(*stack), line_number, op);
			monty_push = 0;
			op = strtok(get_line, "\n\t\r\a");
			line_number++;
			continue;
		}
		else
		{
			if (get_op_func(op) != 0)
			{
				get_op_func(op)(stack, line_number);
			}
			free_fun(&stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
			exit(EXIT_FAILURE);
		}
		line_number++;
		op = strtok(get_line, "\n\t\r\a");
	}
	 free_fun(&(*stack));
	 return (0);
}
