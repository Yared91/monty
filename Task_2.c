#include "monty.h"

/**
*m_pop - removes the top element of the stack
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = (*stack)->next;
		free(*stack);
	}
	if (top)
	{
		top->prev = NULL;
	}
}