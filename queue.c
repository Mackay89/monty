#include "monty.h"

/**
 * file_queue - Sets the data structure to queue mode
 * @stack: The pointer to the stack head
 * @counter: line_number
 * Return: no return
 */
void file_queue(stack_t **stack, unsigned int counter)
{
	(void)*stack;
	(void)counter;
	bus.lifi = 1;
}

/**
 * add_queue - Adds a node to the tail of the stack
 * @stack: The pointer to the head of the stack
 * @n: New value to be added
 * Return: no return
 */
void add_queue(stack_t **stack, int n)
{
	stack_t *new_node, *h;

	h = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (h)
	{
		while (h->next)
			h = h->next;
	}

	if (!h)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		h->next = new_node;
		new_node->prev = h;
	}
}

