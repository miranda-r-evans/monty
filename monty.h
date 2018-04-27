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
        int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_arg - a command and its argument (used in parsing and push)
 * @command: a command/opcode
 * @arg: an integer argument of the command (used for push)
 *
 * Description: if command is push, arg is pushed onto the stack/queue
 * pushing is the only time this is used
 */
typedef struct command_arg
{
	char *command;
	int arg;
} command_arg;

extern unsigned int line_number;

int (*get_func(char *command))(stack_t **stack, unsigned int line_number);

command_arg *parse_line(char *line);

void free_stack(stack_t *stack);

int push_to_stack(stack_t **stack, int n, int s_or_q);

int print_all(stack_t **stack, unsigned int line_number);

int print_int(stack_t **stack, unsigned int line_number);

int pop_int(stack_t **stack, unsigned int line_number);

int swap_ints(stack_t **stack, unsigned int line_number);

int add_ints(stack_t **stack, unsigned int line_number);

int no_op(stack_t **stack, unsigned int line_number);

int sub_ints(stack_t **stack, unsigned int line_number);

int div_ints(stack_t **stack, unsigned int line_number);

int  mul_ints(stack_t **stack, unsigned int line_number);

int mod_ints(stack_t **stack, unsigned int line_number);

int print_char(stack_t **stack, unsigned int line_number);

int print_string(stack_t **stack, unsigned int line_number);

int rotate_left(stack_t **stack, unsigned int line_number);

int rotate_right(stack_t **stack, unsigned int line_number);

#endif
