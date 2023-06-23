#include "monty.h"
/**
 * add - adds first two top elements of a stack
 * @head: head of a linked list
 * @line_num: line number
 * Return: nothing
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't add, stack too short\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	*head = temp->next;
	free(temp);
}

