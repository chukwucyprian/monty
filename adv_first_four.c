#include "monty.h"
/**
 * sub - subtracts top element from second top element of a stack
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
 * _div - divides the second top element by the top element of the stack
 * @head: stack head
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
 * mul - multiplies the second top element with the top element of the stack
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

