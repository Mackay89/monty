#include "monty.h"

/**
 * file_pall - Prints all the value on the stack
 * @stack: stack head
 * @counter: line_number
 * Return: no return
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
