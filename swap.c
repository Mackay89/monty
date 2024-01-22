#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stock
 * @stack: stack head
 * @counter:line_number
 * Return: no return
 */
void f_swap(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack;
	int aux;

	if (!h || !(h->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
