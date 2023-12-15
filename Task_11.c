#include "monty.h"

/**
 * m_pchar -  prints the char at the top of the stack, followed by a new line
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
		line_number);
		exit(EXIT_FAILURE);
	}
	val = *stack->n;

	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n')
}
