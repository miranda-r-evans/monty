#include "monty.h"

#define STACK_SHUFFLE do {			\
	*stack = (*stack)->next;		\
	free((*stack)->prev);			\
	(*stack)->prev = NULL;			\
	} while (0)

/**
 * add_ints - adds first two ints from top of stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 */
void add_ints(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	STACK_SHUFFLE;
}

/**
 * sub_ints - subtracts value at top of stack from next value on stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 */
void sub_ints(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	STACK_SHUFFLE;
}

/**
 * div_ints - 2nd value on stack is divided by value on top of stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 */
void div_ints(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}

	(*stack)->next->n /= (*stack)->n;
	STACK_SHUFFLE;
}

/**
 * mul_ints - top two values on stack are multiplied
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 */
void mul_ints(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	STACK_SHUFFLE;
}

/**
 * mod_ints - 2nd value on stack is modulo'd by value on top
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 */
void mod_ints(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	STACK_SHUFFLE;
}
