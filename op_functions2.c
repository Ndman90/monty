#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void add(stack_t **stack, unsigned int line_number){
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		_free();
		fclose(vars.file_s);
		exit(EXIT_FAILURE);
	} else
	{
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		pop(stack, line_number);
	}
}
/**
 * nop - Nothing's happening here :(
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void nop(stack_t **stack, unsigned int line_number){
	(void) stack;
	(void) line_number;
}
