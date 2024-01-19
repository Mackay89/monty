#include "monty.h"

/**
 * file_pint - Prinys the top
 * @stack: stack head 
 * @counter: line_number
 */
void file_pint(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
