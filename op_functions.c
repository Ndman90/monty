#include "main.h"

/**
 * push - pushes an element to the stack
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void push(stack_t **stack, unsigned int line_number)
{
	Data vars;
	char *num;

	num = strtok(NULL, " \t\n");
	if (!num || is_digit(num) == EXIT_FAILURE)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		_free();
		fclose(vars.file_s);
		exit(EXIT_FAILURE);
	}
	if (strcmp(vars.format, "FIFO") == 0) /* Queue */
		add_node_end(stack, atoi(num));
	else /* Stack */
		add_node(stack, atoi(num));
}
/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	Data vars;
	stack_t *ptr = *stack;
	(void) line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	Data vars;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		_free();
		fclose(vars.file_s);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void pop(stack_t **stack, unsigned int line_number)
{
	Data vars;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free();
		fclose(vars.file_s);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	} else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void swap(stack_t **stack, unsigned int line_number)
{
	Data vars;
	int tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free();
		fclose(vars.file_s);
		exit(EXIT_FAILURE);
	} else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
