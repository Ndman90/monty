#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Data - struct of datas to be used as global variable
 * @buffer: getline buffer
 * @buf_size: getline buffer size
 * @file_s: file stream
 * @line_number: line number
 * @stack: head of the stack
 * @instruct: array of instructions
 * @format: string format
 */
typedef struct Data
{
	char *buffer;
	size_t buf_size;
	FILE *file_s;
	int line_number;
	stack_t *stack;
	instruction_t instruct[18];
	char *format;
} Data;

extern Data vars;


/* op_functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* exec_op */
int exec_op(char *opcode);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* helper functions*/
void initVars(void);
int is_digit(char *str);

/* linked_lists functions */
void _free(void);
void add_node(stack_t **head, const int n);
void add_node_end(stack_t **head, const int n);

#endif
