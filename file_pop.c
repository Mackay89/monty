#include "monty.h"

/**
 * file_pop - Prints the top
 * @stack: stack head
 * @counter: line number
 */
void file_pop(stack_t **stack, unsigned int counter)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;
	free(top);
}
