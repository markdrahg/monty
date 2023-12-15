#include "monty.h"

/**
 * exit_with_failure - Print error message and exit with EXIT_FAILURE.
 */
void exit_with_failure(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_with_failure();
	}

	printf("%d\n", (*stack)->n);
}

