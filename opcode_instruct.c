#include "monty.h"

/**
 * get_op_func - shows the opcode functions
 * @opcode: pointer funciton
 * Return: opcodes
 */

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	unsigned int j;

	instruction_t functions[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add,", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{NULL, NULL},
	};

	for (j = 0; functions[j].opcode; j++)
	{
		if (strcmp(opcode, functions[j].opcode) == 0)
			return (functions[j].f);

	}
	return (NULL);
}
