#include "monty.h"

/**
 * m_parse - parses the read file
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: the parsed result
 */

char *m_parse(char *get_line, stack_t **stack, unsigned int line_number)
{
char *op;
char *size;
int ispush = 0;
void (*func)(stack_t**, unsigned int);

line_number = 1;
size = malloc(sizeof(char) * 2000);

op = strtok(size, "\n\t\r\a");

while (op != NULL)
{
if (op == NULL || op[0] == '#')
{
line_number++;
continue;
}

if (ispush == 1)
{
m_push(&*stack, line_number);
ispush = 0;
op = strtok(NULL, "\n\t\r\a");
line_number++;
continue;
}
else if (strcmp(op, "m_push") == 0)
{
	ispush = 1;
	op = strtok(NULL, "\n\t\r\a");
	continue;
}
else
{
func = get_op_func(op);
if (func != 0)
{
func(stack, line_number);
}
else
{
free_fun(&*stack);
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
exit(EXIT_FAILURE);
}
}
line_number++;
op = strtok(NULL, "\n\t\r\a");
}
free_fun(stack);
free(size);
(void)get_line;
return (NULL);
}
