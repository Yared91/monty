#include "monty.h"

/**
 * m_div - divides the top element by the second top element of stack
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->n == 0 || (*stack)->next->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
}

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n = (*stack)->next->n / (*stack)->n;
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
}
