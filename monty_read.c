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
int new_file;
char *size = NULL;
char *token;
ssize_t read_line;
unsigned int line_number = 1;
void (*func)(stack_t**, unsigned int);

new_file = open(name, O_RDONLY);

if (new_file == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", name);
exit(EXIT_FAILURE);
}
size = malloc(sizeof(char) * 2000);
if (!size)
return;
read_line = read(new_file, size, 2000);
while (read_line == -1)
{
token = m_parse(size, stack, line_number);

if (token == NULL || token[0] == '#')
{
	line_number++;
	continue;
}
func = get_op_func(token);
if (func != 0)
{
func(stack, line_number);
}
free_fun(stack);
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
exit(EXIT_FAILURE);
line_number++;
}
free(size);
close(new_file);
}
