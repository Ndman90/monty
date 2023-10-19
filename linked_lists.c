#include "main.h"

/**
 * add_node -  add element to stack.
 * @head: the top of the stack
 * @n: the element to add
 *
 * Return: (void)
 */
void add_node(stack_t **head, const int n)
{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(), fclose(vars.file_s);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	new_node->next = *head;
	if (*head)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
 }
/**
 * add_node_end -  add element to queue.
 * @head: the front of the queue
 * @n: the element to add
 *
 * Return: (void)
 */
void add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *tmp;
	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(), fclose(vars.file_s);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		tmp = NULL;
	}
}
