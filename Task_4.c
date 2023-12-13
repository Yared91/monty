#include "monty.h"

/**
 * m_add - adds the top two elements of the stack
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	m_pop(stack, line_number);
}
