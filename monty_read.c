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
unsigned int line_number = 1;

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
if (read_line == -1)
{
free(size);
close(new_file);
exit(EXIT_FAILURE);
m_parse(size, stack, line_number);
}
}
