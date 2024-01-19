#include "monty.h"

/**
 * free_stack - Frees a doubly link list
 * @stack: stack head
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next_node;

	current = stack;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
