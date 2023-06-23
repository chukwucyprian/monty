#include "monty.h"
/**
 * push - pushes an element to the stack
 * @head: linked list's head
 * @line_number: line number
 * Return: nothing
 */
void push(stack_t **head, unsigned int line_number)
{
	int data, i;
	stack_t *new, *ptr;

	if (strcmp(globv.arg, "") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_globv();
		exit(EXIT_FAILURE);
	}
	for (i = 0; globv.arg[i] != '\0'; i++)
	{
		if ((globv.arg[i] < '0' || globv.arg[i] > '9') && globv.arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_globv();
			exit(EXIT_FAILURE);
		}
	}
	data = atoi(globv.arg);
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
}
/**
 * pall - displays stack content
 * @head: linked list's head
 * @line: line number
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	(void)line;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - displays top element of a stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pint,  empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
/**
 * pop - pops the top most stack element
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*head = ptr->next;
	free(ptr);
}
/**
 * swap - swaps two top  most stack elements
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;

	if (!ptr || !(ptr->next))
	{
		fprintf(stderr, "L%d: can't swap", line_num);
		fprintf(stderr, ", stack too short\n");
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	ptr->next = (*head)->next;
	ptr->prev = *head;
	(*head)->next = ptr;
	(*head)->prev = NULL;
}

