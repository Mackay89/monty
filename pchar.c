#include "monty.h"

/**
 * file_pchar -Prints the char at the top of the stack
 * followed by new line
 * @stack: stack head
 * @counter: line number in the monty bytecode file
 */
void file_pchar(stack_t **stack, unsigned int counter)
{
	stack_t *aux;

	aux = *stack;
	if (!aux)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (aux->n > 127 || aux->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", aux->n);
}
