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
ssize_t read_line;
char *op;
int monty_push = 0;
unsigned int line_number = 1;

new_file = open(name, O_RDONLY);

if (new_file == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", name);
exit(EXIT_FAILURE);
}
size = malloc(sizeof(char) * 2000);
if (!size)
close(new_file);
return;
read_line = getline(new_file, size, stdin);
if (read_line == -1)
{
free(size);
close(new_file);
exit(EXIT_FAILURE);
}

op = strtok(size, "\n\t\r\a");

while (op != NULL)
{
if (op[0] == '#' || op[0] == '\0')
{
line_number++;
op = strtok(NULL, "\n\t\r\a");
continue;
}

if (monty_push == 1)
{
m_push(stack, line_number);
monty_push = 0;
line_number++;
op = strtok(NULL, "\n\t\r\a");
continue;
}
else
{
void (*func)(stack_t**, unsigned int);
func = get_op_func(op);
if (func != 0)
{
func(stack, line_number);
}
else
{
free_fun(stack);
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
exit(EXIT_FAILURE);
}
}
line_number++;
op = strtok(NULL, "\n\t\r\a");
}
free(size);
close(new_file);
free_fun(stack);
return;
}
