#include "monty.h"

/**
 * no_op - this does nothing
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int no_op(__attribute__((unused))stack_t **stack,
	   __attribute__((unused))unsigned int line_number)
{
	return (0);
}

/**
 * print_char - prints top value on stack as a char
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int print_char(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n",
			line_number);
		return (EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);

	return (0);
}

/**
 * print_string - prints stack as a string
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int print_string(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return (0);
	}

	ptr = *stack;

	while (ptr != NULL && ptr->n >= 1 && ptr->n <= 127)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");

	return (0);
}

/**
 * rotate_left - rotates the stack left
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int rotate_left(stack_t **stack,
		 __attribute__((unused))unsigned int line_number)
{
	stack_t *end;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);

	end = *stack;

	while (end->next != NULL)
	{
		end = end->next;
	}

	end->next = *stack;
	*stack = (*stack)->next;
	end->next->next = NULL;

	return (0);
}

/**
 * rotate_right - rotates the stack right
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int rotate_right(stack_t **stack,
		  __attribute__((unused))unsigned int line_number)
{
	stack_t *end;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);

	end = *stack;

	while (end->next != NULL)
	{
		end = end->next;
	}

	end->prev->next = NULL;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = end;

	return (0);
}
