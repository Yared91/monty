#include "monty.h"

/**
*m_push - It adds a new element to the stack_t linked list
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	(void)line_number;

	if (*stack == NULL)
	{
		node->n = monty_push;
		node->next = NULL;
		node->prev = NULL;
		*stack = node;
		return;
	}

	(*stack)->prev = node;
	node->n = monty_push;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

/**
*m_pall - prints all the values starting from the top of the stack
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
	(void)line_number;
}
