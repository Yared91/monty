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
	size_t len = 0;
	ssize_t read_line;
	unsigned int i = 0;

	new_file = fopen(name, "r");

	if (new_file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	 size = malloc(sizeof(char) * 2000);
	 if (!size)
		 return (0);
	 read_line = read(new_file, size, 2000);
			 if (readline == -1)
			 {
			 free(size);
			 fclose(new_file);
			 exit(EXIT_FAILURE);
			 }
}
