#include "monty.h"

/**
 * file_rotl - Rotates the stack to the top 
 * @stack: The pointer to the stack head
 * @counter: line_number (unused)
 */
void file_rotl(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	aux = (*stack)->next;
	aux->prev = NULL;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = aux;
}
