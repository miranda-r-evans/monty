#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	tmp = stack;

	while (stack != NULL)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
}
