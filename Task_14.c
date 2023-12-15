#include "monty.h"

/**
*m_rotr - rotates the stack to the bottom
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	else if ((*stack)->next != NULL)
	{
		while (top->next != NULL)
		{
			top = top->next;
			(*stack)->prev = top;
			top->next = *stack;

			top->prev->next = NULL;
			top->prev = NULL;
			*stack = (*stack)->prev;
		}
	}
	(void)line_number;
}
