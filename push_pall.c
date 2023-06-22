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

