#include "monty.h"
/**
 * add_node - adds a new node at the of a stack
 * @head: linked stack_t list head
 * @n: new node data
 * Return: the address of the new element
 */
stack_t *add_node(stack_t **head, int n)
{
	stack_t *ptr, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "memory allacation error\n");
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	new->n = n;
	new->prev = NULL;
	if (!ptr)
		new->next = NULL;
	else
	{
		new->next = ptr;
		ptr->prev = new;
	}
	*head = new;

	return (new);
}

