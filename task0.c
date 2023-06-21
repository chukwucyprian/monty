#include "monty.h"
/**
 * push - pushes an element to the stack
 * @head: linked list's head
 * @line_number: line number
 * Return: nothing
 */
void push(stack_t **head, unsigned int line_number)
{
	int data, i = 0;

	if (strcmp(glob_var.func, "") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	while (glob_var.func[i] != '\0')
	{
		if (!isdigit(glob_var.func[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_glob_var();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data = atoi(glob_var.func);
	addnode(head, data);
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
	stack_t *temp = *head;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
	*head = temp->next;
	free(temp);
}
/**
 * swap - swaps two top  most stack elements
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head, *tmp;

	if (!temp || !(temp->next))
	{
		fprintf(stderr, "L%d: can't swap", line_num);
		fprintf(stderr, ", stack too short\n");
	}
	tmp = temp->next;
	temp->next = tmp->next;
	tmp->next = temp;
	temp->prev = tmp;
	tmp->prev = NULL;
}
