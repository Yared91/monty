#include "monty.h"

/**
*m_swap - swaps the top two elements of the stack
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->next;

	if (top->next != NULL)
	{
		(*stack)->next = top->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		top->prev->prev = top;
		top->prev->next = NULL;
	}
	top->prev = NULL;
	top->next = *stack;
	(*stack) = top;
}
