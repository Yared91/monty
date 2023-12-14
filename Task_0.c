#include "monty.h"

/**
*m_push - It adds a new element to the stack_t linked list
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*@abc: character pointer
*Return: void
*/

void m_push(stack_t **stack, unsigned int line_number)
{
	char abc;

	if (!isdigit(abc))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_fun(stack);
		exit(EXIT_FAILURE);
	}
		if (add_dnodeint_end(stack, atoi(&abc) == 0))
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_fun(stack);
			exit(EXIT_FAILURE);
			}
		(void)line_number;
}

/**
*m_pall - prints all the values starting from the top of the stack
*@stack: is a pointer to the top most element in the stack
*@line_number: working line number of monty
*Return: void
*/

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t **top = stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_fun(top);
		exit(EXIT_FAILURE);
	}
	else
	{
		delete_dnodeint_at_index(top);
	(void)line_number;
	}
}
