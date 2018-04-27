#include "monty.h"

/**
 * push_to_stack - pushes a value onto the top of a stack / head of queue
 * @stack: linked list representing stack
 * @n: value to be added
 * @s_or_q: bool indicating if linked list is treated as a stack or as a queue
 *
 * Return: 0 or EXIT_FAILURE
 */
int push_to_stack(stack_t **stack, int n, int s_or_q)
{
	stack_t *ptr;
	stack_t *end;

	if (stack == NULL)
		return (EXIT_FAILURE);

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		return (EXIT_FAILURE);
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
		ptr->prev = end;
		ptr->next = NULL;
	}

	return (0);
}

/**
 * print_all - prints entire stack / queue
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int print_all(stack_t **stack,
	       __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL)
		return (0);

	ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}

	return (0);
}

/**
 * print_int - prints value on top of stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int print_int(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

	return (0);
}

/**
 * pop_int - removes value from top of stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int pop_int(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (tmp != NULL)
		tmp->prev = NULL;

	return (0);
}

/**
 * swap_ints - swaps first two values from top of stack
 * @stack: link list representing a stack
 * @line_number: line number of command in bytecode file (used for error)
 *
 * Return: 0 or EXIT_FAILURE
 */
int swap_ints(stack_t **stack, unsigned int line_number)
{
	int tmp_int;
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n",
			line_number);
		return (EXIT_FAILURE);
	}

	ptr = *stack;
	tmp_int = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = tmp_int;

	return (0);
}
