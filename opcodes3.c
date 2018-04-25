#include "monty.h"

void no_op(__attribute__((unused))stack_t **stack,
           __attribute__((unused))unsigned int line_number)
{
}

void print_char(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

void print_string(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	ptr = *stack;

	while (ptr != NULL && ptr->n >= 1 && ptr->n <= 127)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
}

void rotate_left(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *end;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	end = *stack;

	while (end->next != NULL)
	{
		end = end->next;
	}

	end->next = *stack;
	*stack = (*stack)->next;
	end->next->next = NULL;
}

void rotate_right(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *end;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	end = *stack;

	while (end->next != NULL)
	{
		end = end->next;
	}

	end->prev->next = NULL;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = end;
}
