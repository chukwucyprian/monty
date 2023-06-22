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
 * free_stack - frees a stack
 * @head: stack top element
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *ptr = head;

	while (head)
	{
		head = head->next;
		free(ptr);
		ptr = head;
	}
}

