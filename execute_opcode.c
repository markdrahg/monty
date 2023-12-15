#include "monty.h"

/**
 * execute_opcode - Responsible for executing the codes
 *
 * @stack: Double pointer to the beginning of the stack
 * @opcode: pointer to the opcode
 * @line_number: Line number in Monty byte code file
 *
 * Return: 0 on success, 1 on error
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
