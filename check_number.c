#include "monty.h"

/**
*checknum - checks if the args are number
*@op: pointer function
*Return: 0 if not digit, 1 if digit.
*/

int checknum(char *op)
{
for (unsigned int a = 0; op[a]; a++)
{
	if (!isdigit(op[a]))
		return (0);
}
return (1);
}
