#include "monty.h"

/**
 * file_pall - Prints the stack
 * @stack: stack head
 * @counter: unused parameter
 */
void file_pall(stack_t **stack, unsigned int counter)
{
	stack_t *current = *stack;

	(void)counter;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
