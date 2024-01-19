#include "monty.h"

/**
 * file_rotr - Rotates the stack to the bottom
 * @stack: stack head
 * @counter: line_number
 * Return: none
 */
void file_rotr(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy = *stack;

	if (!(*stack) || !((*stack)->next))
	{
		return;
	}

	while (copy->next)
	{
		copy = copy->next;
	}

	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
