#include "monty.h"

get_opc_t globv;

/**
 * free_globv - frees the global variables
 * Return: nothing
 */
void free_globv(void)
{
	free_stack(globv.top);
	free(globv.opcode);
	fclose(globv.fd);
}
/**
 * check_args - checks file existance
 * @argc: argument count
 * @argv: arguments
 * Return: file structure
 */
FILE *check_args(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int idx);
	int size = 250;
	char *str;

	globv.fd = check_args(argc, argv);
	globv.top = NULL;
	globv.line_idx = 1;
	globv.opcode = malloc(250);
	if (globv.opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	globv.arg = NULL;

	while (fgets(globv.opcode, size, globv.fd))
	{
		remove_new_line(globv.opcode);
		space_handle(globv.opcode);
		str = strtok(globv.opcode, " ");
		if (str && str[0] != '#')
		{
			f = gen_opcodes(str);
			if (!f)
			{
				fprintf(stderr, "L%u: ", globv.line_idx);
				fprintf(stderr, "unknown instruction %s\n", str);
				free_globv();
				exit(EXIT_FAILURE);
			}
			globv.arg = strtok(NULL, " ");
			f(&globv.top, globv.line_idx);
		}
		globv.line_idx++;
	}

	free_globv();

	return (0);
}
