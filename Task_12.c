#include "monty.h"

/**
 * m_pstr -  prints the string starting at the top of the stack
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *j;

	j = *stack;

	while ((j != NULL) && (j->n != 0) && (j->n >= 0) && (j->n <= 127))
	{
		printf("%c", j->n);
		j = j->next;
	}
	printf("\n");

	(void)line_number;
}
