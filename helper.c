#include "monty.h"

/**
 * initVars - initialize variables
 *
 * Return: void
 */
void initVars(void)
{
	vars.buffer = NULL;
	vars.buf_size = 0;
	vars.line_number = 1;
	vars.stack = NULL;
	vars.format = "LIFO"; /* stack */
	vars.instruct[0].opcode = "push",
		vars.instruct[0].f = push;
	vars.instruct[1].opcode = "pall",
		vars.instruct[1].f = pall;
	vars.instruct[2].opcode = "pint",
		vars.instruct[2].f = pint;
	vars.instruct[3].opcode = "pop",
		vars.instruct[3].f = pop;
	vars.instruct[4].opcode = "swap",
		vars.instruct[4].f = swap;
	vars.instruct[5].opcode = "add",
		vars.instruct[5].f = add;
	vars.instruct[6].opcode = "nop",
		vars.instruct[6].f = nop;
	vars.instruct[7].opcode = "sub",
		vars.instruct[7].f = sub;
	vars.instruct[8].opcode = "div",
		vars.instruct[8].f = divid;
	vars.instruct[9].opcode = "mul",
		vars.instruct[9].f = mul;
	vars.instruct[10].opcode = "mod",
		vars.instruct[10].f = mod;
	vars.instruct[11].opcode = "pchar",
		vars.instruct[11].f = pchar;
	vars.instruct[12].opcode = "pstr",
		vars.instruct[12].f = pstr;
	vars.instruct[13].opcode = "rotl",
		vars.instruct[13].f = rotl;
	vars.instruct[14].opcode = "rotr",
		vars.instruct[14].f = rotr;
	vars.instruct[15].opcode = "stack",
		vars.instruct[15].f = stack;
	vars.instruct[16].opcode = "queue",
		vars.instruct[16].f = queue;
	vars.instruct[17].opcode = NULL,
		vars.instruct[17].f = NULL;
}
/**
 * _free - free allocated memory
 *
 * Return: void
 */
void _free(void)
{
	if (vars.buffer)
		free(vars.buffer);
	if (vars.stack)
	{
		while (vars.stack->next)
		{
			vars.stack = vars.stack->next;
			free(vars.stack->prev);
		}
		free(vars.stack);
	}
}
/**
 * is_digit - check if string is digit
 * @str: string to check
 *
 * Return: 0 if success otherwise return EXIT_FAILURE
 */
int is_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			continue;
		if (str[i] < 48 || str[i] > 57)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
