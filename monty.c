#include "main.h"
Data vars;

/**
 * main - Monty main program
 * @argc: arguments counter
 * @argv: arguments
 *
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
	char *opcode;
	ssize_t nread;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initVars();
	vars.file_s = fopen(argv[1], "r");
	if (!(vars.file_s))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&vars.buffer, &vars.buf_size, vars.file_s)) != -1)
	{
		opcode = strtok(vars.buffer, " \t\n");
		if (!opcode)
		{
			vars.line_number++;
			continue;
		}
		if (exec_op(opcode) == EXIT_FAILURE)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					vars.line_number, opcode);
			_free();
			fclose(vars.file_s);
			exit(EXIT_FAILURE);
		}
		vars.line_number++;
	}
	fclose(vars.file_s);
	_free();
	exit(EXIT_SUCCESS);
}
