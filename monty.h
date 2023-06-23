#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
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
 * struct get_opc - structure used to generate opcodes
 * @func: second main argument
 * @first_arg: third argument of main function
 * @line_idx: line number
 * @list: stack_t variable
 * @fd: file descriptor
 */
typedef struct get_opc
{
	char *arg;
	char *opcode;
	unsigned int line_idx;
	stack_t *top;
	FILE *fd;
} get_opc_t;

extern get_opc_t globv;
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_number);
void (*gen_opcodes(char *opc))(stack_t **linear_stack, unsigned int line_idx);
void free_stack(stack_t *head);
void free_globv();
stack_t *add_node(stack_t **head, int data);
void remove_new_line(char str[]);
void space_handle(char str[]);
void sub(stack_t **head, unsigned int line_num);
void f_div(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);
#endif

