#include "monty.h"

/**
 * m_pchar -  prints the char at the top of the stack, followed by a new line
 * @stack: is a pointer to the top most element in the stack
 * @line_number: working line number of monty
 * Return: void
 */

void m_pchar(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n",
line_number);
exit(EXIT_FAILURE);
}

if (((*stack)->n) >= 0 && ((*stack)->n) <= 127)
{
printf("%c\n", (*stack)->n);
}
else
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
}
