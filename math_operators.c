#include "monty.h"

/**
 * sub - subtracts the top element from the second top element of the stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	*head = temp->next;
	free(temp);
}
/* mul- multiplies the second top element by the top element of the stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void mul(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	*head = temp->next;
	free(temp);
}
/**
 * mod - computes the rest of the division of the second top element
 *        by the top element of the stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void mod(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	*head = temp->next;
	free(temp);
}

