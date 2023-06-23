#include "monty.h"
/**
 * mod - finds modulus of the second top element from top element of the stack
 * @head: stack head
 * @line_num: line number
 * Return: nothing
 */
void mod(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't mod, stack too short\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	*head = temp->next;
	free(temp);
}

