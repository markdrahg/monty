#include "monty.h"

/**
 * execute_opcode - Responsible for executing the codes
 *
 * @stack: Double pointer to the beginning of the stack
 * @opcode: pointer to the opcode
 * @line_number: Line number in Monty byte code file
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
    instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}};

	int i = 0;
	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


/**
 * parse_file - Passes the command to it's monty
 *  language
 *
 * @file: pointer to the open file
 * @stack: the stack
 */
void parse_file(FILE *file, stack_t **stack)
{
	unsigned int line_number = 0;
	char *opcode;

	while (1)
	{
		char getline_result[1024];
		if (fgets(getline_result, sizeof(getline_result), file) == NULL)
		break;

		line_number++;

		opcode = strtok(getline_result, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			execute_opcode(stack, opcode, line_number);
		}
	}
}

/**
 * main - The main function that houses all operations
 * @argc: the arg count
 * @argv: the arg vector
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
