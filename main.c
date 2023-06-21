#include "monty.h"

get_opc_t glob_var;

/**
 * init_glob_var - initializes the global variables
 * @fd: file descriptor
 * Return: nothing
 */
void init_glob_var(FILE *fd)
{
	glob_var.func = NULL;
	glob_var.linear = 1;
	glob_var.line_idx = 1;
	glob_var.top = NULL;
	glob_var.fd = fd;
}
/**
 * free_glob_var - frees the global variables
 * Return: nothing
 */
void free_glob_var(void)
{
	free_stack(glob_var.top);
	fclose(glob_var.fd);
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
	FILE *fd;
	int size = 250;
	char *arr_str[2] = {NULL, NULL};

	fd = check_args(argc, argv);
	init_glob_var(fd);

	while (fgets(glob_var.first_arg, size, fd))
	{
		arr_str[0] = strtok(glob_var.first_arg, "\n ");
		if (arr_str[0] && arr_str[0][0] != '#')
		{
			f = gen_opcodes(arr_str[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", glob_var.line_idx);
				fprintf(stderr, "unknown instruction %s\n", arr_str[0]);
				free_glob_var();
				exit(EXIT_FAILURE);
			}
			glob_var.func = strtok(NULL, "\n ");
			f(&glob_var.top, glob_var.line_idx);
		}
		glob_var.line_idx++;
	}

	free_glob_var();

	return (0);
}
