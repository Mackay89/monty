#include "monty.h"

/**
 * file_pstr - Prints the string starting at the top of the stack
 * followed by a newline
 * @stack: The pointer to the stack
 * @counter: line_number
 */
void file_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *stack;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
