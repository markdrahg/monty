#include "monty.h"

/**
 * main - The main function that houses all operations
 * @argc: the arg count
 * @argv: the arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	parse_file(file, &stack);

	fclose(file);
	return (EXIT_SUCCESS);
}
