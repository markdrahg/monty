#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = (*stack)->prev;

	if ((*stack)->next != NULL)
	(*stack)->next->prev = *stack;

	(*stack)->prev = temp;
	temp->next = *stack;

	*stack = temp;
}
