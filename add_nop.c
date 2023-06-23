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
/**
 * nop - does nothing
 * @head: linked list's head
 * @idx: line number
 * Return: nothing
 */
void nop(stack_t **head, unsigned int idx)
{
	(void)head;
	(void)idx;
}
/**
 * sub - subtracts the top element from the second top element of the stack
 * @head: head of a linked list
 * @line_num: line number
 * Return: nothing
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't sub, stack too short\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	*head = temp->next;
	free(temp);
}
/**
 * _div -  divides the second top by the top element of the stack
 * @head: head of a linked list
 * @line_num: line number
 * Return: nothing
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't div, stack too short\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	*head = temp->next;
	free(temp);
}
/**
 * mul - multiplies the top element from the second top element of the stack
 * @head: head of a linked list
 * @line_num: line number
 * Return: nothing
 */
void mul(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: ", line_num);
		fprintf(stderr, "can't mul, stack too short\n");
		free_globv();
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	*head = temp->next;
	free(temp);
}

