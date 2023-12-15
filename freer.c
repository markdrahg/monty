#include "monty.h"

/**
 * freer - Frees a doubly linked list.
 * @head: Pointer to the head of the stack
 */
void freer(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
