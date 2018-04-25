#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct command_arg
{
	char *command;
	int arg;
} command_arg;

extern int s_or_q;

void (*get_func(char *command, unsigned int line_number))(stack_t **stack, unsigned int line_number);

command_arg *parse_line(char *line, unsigned int line_number);

void push_to_stack(stack_t **stack, int n);

void print_all(stack_t **stack, unsigned int line_number);

void print_int(stack_t **stack, unsigned int line_number);

void pop_int(stack_t **stack, unsigned int line_number);

void swap_ints(stack_t **stack, unsigned int line_number);

void add_ints(stack_t **stack, unsigned int line_number);

void no_op(stack_t **stack, unsigned int line_number);

void sub_ints(stack_t **stack, unsigned int line_number);

void div_ints(stack_t **stack, unsigned int line_number);

void mul_ints(stack_t **stack, unsigned int line_number);

void mod_ints(stack_t **stack, unsigned int line_number);

void print_char(stack_t **stack, unsigned int line_number);

void print_string(stack_t **stack, unsigned int line_number);

void rotate_left(stack_t **stack, unsigned int line_number);

void rotate_right(stack_t **stack, unsigned int line_number);

#endif
