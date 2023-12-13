#include "monty.h"

/**
 * get_op_func - shows the opcode functions
 * @opcode: pointer funciton
 * Return: NULL
 */

op_instruction get_op_func(char *opcode)
{
	unsigned int j;

	instruction_t funcitons[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add,", m_add},
		{"nop", m_nop},
	};

	for (j = 0; functions[j].opcode; j++)
	{
		if (strcmp(op_code, functions[j].opcode) == 0)
			return (functions[j].f);

	}
	return (NULL);
}
