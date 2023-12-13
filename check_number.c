#include "monty.h"

/**
*checknum - checks if the args are number
*@op: pointer function
*Return: 0 if not digit, 1 if digit.
*/

int checknum(char *op)
{
unsigned int a = 0;
while (op[a])
{
	if (!isdigit(op[a]))
		return (0);
	a++;
}
return (1);
}
