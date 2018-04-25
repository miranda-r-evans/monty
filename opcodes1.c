#include "monty.h"

int s_or_q;

void push_to_stack(stack_t **stack, int n)
{
	stack_t *ptr;
	stack_t *end;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	ptr->n = n;

	if (*stack == NULL)
	{
		*stack = ptr;
		ptr->next = NULL;
		ptr->prev = NULL;
	}
	else if (s_or_q == STACK)
	{
		ptr->prev = NULL;
		ptr->next = *stack;
		(*stack)->prev = ptr;
		*stack = ptr;
	}
	else
	{
		end = *stack;
		while (end->next != NULL)
			end = end->next;

		end->next = ptr;
		ptr->next = NULL;
	}
}

void print_all(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL)
		return;

	ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

void print_int(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

void pop_int(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (tmp != NULL)
		tmp->prev = NULL;
}

void swap_ints(stack_t **stack, unsigned int line_number)
{
	int tmp_int;
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	tmp_int = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = tmp_int;
}
