#include "monty.h"

/**
 * execute - Execute the opcode
 * @stack: Head stack 
 * @counter: line_number
 * @file: The pointer to monty file 
 * @content: line_content
 * Return: No return 
 */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", file_push}, {"pall", file_pall}, {"pint", file_pint},
		{"pop", file_pop},
		{"swap", swap},
		{"add", f_add},
		{"nop", nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", file_pchar},
		{"pstr", file_pstr},
		{"rotl", file_rotl},
		{"rotr", file_rottr},
		{"queue", file_queue},
		{"stack", file_stack},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && op[0] == '#')
		return;

	bus.arg = strtok(NULL, "\n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return;
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
