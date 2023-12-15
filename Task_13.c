#include "monty.h"

/**
*m_rotl - rotates the stack to the top
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_rotl(stack_t **stack, unsigned int line_number)
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

			(*stack)->next->prev = NULL;
			*stack = (*stack)->next;
			top->next->next = NULL;
		}
	}
	(void)line_number;
}

