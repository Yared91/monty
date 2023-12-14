#include "monty.h"

/**
 * m_mod - computes the rest of the division of the second by the top element
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->n == 0 || (*stack)->next->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
}

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n = (*stack)->next->n % (*stack)->n;
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
}
