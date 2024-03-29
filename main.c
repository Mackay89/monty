#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty that intepreter code
 * @argc: the number of arguments
 * @argv: Monty  file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0;
	size_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	char *content;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;

		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}

		free(content);
	}

	free_stack(stack);
	return 0;
}
