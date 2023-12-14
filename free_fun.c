#include "monty.h"

/**
*free_fun - free all linked list
*@stack: pointer to the first node
*/

void free_fun(stack_t **stack)
{
	stack_t *top;

	while (stack != NULL)
	{
		top = (*stack)->next;
		free(*stack);
		(*stack) = top;
	}
}
