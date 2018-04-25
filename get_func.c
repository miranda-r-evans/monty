#include "monty.h"

void (*get_func(char *command, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_array[] = {
		{"pall", print_all},
		{"pint", print_int},
		{"pop", pop_int},
		{"swap", swap_ints},
		{"add", add_ints},
		{"nop", no_op},
		{"sub", sub_ints},
		{"div", div_ints},
		{"mul", mul_ints},
		{"mod", mod_ints},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{"", NULL}
	};

	instruction_t *opcode_ptr = opcode_array;

	while (opcode_ptr->f != NULL)
	{
		if (strcmp(command, opcode_ptr->opcode) == 0)
			return (opcode_ptr->f);

		opcode_ptr++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}
