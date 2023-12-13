#include "monty.h"

/**
*m_swap - swaps the top two elements of the stack
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_swap(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = val;
}
