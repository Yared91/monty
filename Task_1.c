#include "monty.h"

/**
 * m_pint - prints the value at the top of the stack, followed by a new line
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
