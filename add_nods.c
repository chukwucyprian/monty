#include "monty.h"
/**
 * add_to_stack - adds a node in the stack
 * @head: stack head
 * @data: node data part (integer)
 * Return: new head's address
 */
stack_t *add_to_stack(stack_t **head, int data)
{
	stack_t *ptr = *head, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "memory allacation error\n");
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	new->n = data;
	new->prev = NULL;
	if (!ptr)
		new->next = NULL;
	else
	{
		new->next = ptr;
		ptr->prev = new;
	}
	(*head) = new;
	return (*head);
}
/**
 * add_to_queue - adds a node in the queue
 * @head: queue head
 * @data: node data part (integer)
 * Return: address of a new node
 */
stack_t *add_to_queue(stack_t **head, int data)
{
	stack_t *ptr = *head, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = data;
	if (!ptr)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		new->next = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	return (new);
}
/**
 * stack - uses linked list stac_t as a stack
 * @head: stack head
 * @line_num: line number
 * Return: no return
 */
void stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	globv.type = 1;
}
/**
 * queue - uses linked list stac_t as a queue
 * @head: stack head
 * @line_num: line number
 * Return: no return
 */
void queue(stack_t **head, unsigned int line_num)
{
	(void) head;
	(void) line_num;

	globv.type = 0;
}
