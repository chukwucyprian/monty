#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void pchar(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_globv();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
/**
 * pstr - prints the string starting at the top of the stack
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	(void)line_num;

	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
		if (!temp || (temp->n <= 0 || temp->n > 127))
			printf("\n");
	}
}
/**
 * rotl - rotates the stack to the top
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	stack_t *last = *head;

	(void)line_num;

	if (*head && (*head)->next)
	{
		while (last->next)
			last = last->next;

		last->next = temp;
		temp->prev = last;
		*head = temp->next;
		(*head)->prev = NULL;
		temp->next = NULL;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @head: linked list's head
 * @line_num: line number
 * Return: nothing
 */
void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	stack_t *last = *head;

	(void)line_num;

	if (*head && (*head)->next)
	{
		while (last->next)
			last = last->next;

		last->next = temp;
		temp->prev = last;
		*head = last;
		last->prev->next = NULL;
		last->prev = NULL;
	}
}
/**
 * check_if_comment - checks wheter the string is a comment or not
 * @str: string
 * Return: nothing
 */
void check_if_comment(char *str)
{
	int i = 0;
	char const *buffer = "nop";

	if (str[i] == '#')
	{
		i = strlen(str) - 1;
		while (i >= 0)
			str[i--] = '\0';
		i = 0;
		while (buffer[i])
		{
			str[i] = buffer[i];
			i++;
		}
		str[i] = buffer[i];
	}
}

