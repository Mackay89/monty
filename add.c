#include "monty.h"

/**
 * f_add - adds the top two element of the stack
 * @stack: stack head
 * @counter: line_number
 */
void f_add(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack;

	if (!h || !(h->next))

	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h->next->n += h->n;
	*stack = h->next;
	free(h);
}

/**
 * f_sub - Subtraction
 * @stack: Stack head
 * @counter: line _number
 */
void f_sub(stack_t **stack, unsigned int counter)
{
	stack_t *aux = *stack;

	if (!aux || !(aux->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	aux->next->n -= aux->n;
	*stack = aux->next;
	free(aux);
}

/**
 * f_div - Divids the top two elements of the stack
 * @stack: stack head
 * @counter: line_number
 */
void f_div(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack;

	if (!h || !(h->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h->next->n /= h->n;
	*stack = h->next;
	free(h);
}

/**
 * f_mul - multiplies the top two elements of the stack
 * @stack: stack head
 * @counter: line_number
 */
void f_mul(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack;

	if (!h || !(h->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h->next->n *= h->n;
	*stack = h->next;
	free(h);
}

/**
 * f_mod - computes the rest of the division of the second top
 * elements of the stack
 * @stack: stack head
 * @counter: line_number
 */
void f_mod(stack_t **stack, unsigned int counter)
{
	stack_t *h = *stack;

	if (!h || !(h->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	h->next->n %= h->n;
	*stack = h->next;
	free(h);
}
