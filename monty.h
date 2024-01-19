#ifndef MONTY_H_
#define MONTY_H_

#define _GNU_SOURCE_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -arg, file, line content
 * @arg: value
 * @file:The pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: Carries value through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

size_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void file_push(stack_t **stack, unsigned int counter);
void file_pall(stack_t **stack, unsigned int counter);
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void file_pint(stack_t **stack, unsigned int number);
void free_stack(stack_t *stack);
void file_pop(stack_t **stack, unsigned int counter);
void swap(stack_t **stack, unsigned int counter);
void f_add(stack_t **stack, unsigned int counter);
void nop(stack_t **stack, unsigned int counter);
void f_sub(stack_t **stack, unsigned int counter);
void f_div(stack_t **stack, unsigned int counter);
void f_mul(stack_t **stack, unsigned int counter);
void f_mod(stack_t **stack, unsigned int counter);
void file_pchar(stack_t **stack, unsigned int counter);
void file_pstr(stack_t **stack, unsigned int counter);
void file_rotl(stack_t **stack, unsigned int counter);
void file_rottr(stack_t **stack, __attribute__((unused)) unsigned int counter);
void add_queue(stack_t **stack, int n);
void add_node(stack_t **stack, int n);
void file_queue(stack_t **stack, unsigned int counter);

void file_stack(stack_t **stack, unsigned int counter);

#endif 
