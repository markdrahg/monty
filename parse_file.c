#include "monty.h"

/**
 * parse_file - Passes the command to it's monty
 *  language
 *
 * @file: pointer to the open file
 * @stack: the stack
 *
 * Return: 0 on success, 1 on error
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
