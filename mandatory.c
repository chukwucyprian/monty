#include "monty.h"
/**
 * gen_opcodes - chooses corresponding function
 * @opc: opcode
 * Return: pointer to the corresponding function
 */
void (*gen_opcodes(char *opc))(stack_t **linear_stack, unsigned int line_idx)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
			break;
		i++;
	}

	return (instruct[i].f);
}
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
		free_glob_var();
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
 * free_stack - frees a stack
 * @head: stack top element
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	while (head)
	{
		head = head->next;
		free(head->prev);
	}
}
/**
 * addnode - adds a node at the begining of stack
 * @head: stack top
 * @data: integer
 * Return: new address
 */
stack_t *addnode(stack_t **head, int data)
{
	stack_t *new_elem;

	new_elem = malloc(sizeof(stack_t));
	if (!new_elem)
	{
		fprintf(stderr, "memory allacation error\n");
		exit(EXIT_FAILURE);
	}
	new_elem->n = data;
	if (*head == NULL)
	{
		new_elem->next = *head;
		new_elem->prev = NULL;
		*head = new_elem;
	}
	else
	{
		(*head)->prev = new_elem;
		new_elem->next = *head;
		new_elem->prev = NULL;
		*head = new_elem;
	}
	return (*head);
}

