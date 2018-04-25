#include "monty.h"

unsigned int line_number = 1;

/**
 * main - program to interpret monty bytecode
 * @ac: number of arguments from command line
 * @av: arguments from command line
 *
 * Return: 0, or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	stack_t *my_stack = NULL;
	char *buf;
	FILE *fp;
	size_t buf_size;
	ssize_t chars_read;
	command_arg *my_command;
	int s_or_q = STACK;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (access(av[1], R_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");

	chars_read = getline(&buf, &buf_size, fp);
	while (chars_read > 0)
	{
		my_command = parse_line(buf);

		if (my_command == NULL)
		{
			line_number++;
			chars_read = getline(&buf, &buf_size, fp);
			continue;
		}
		else if (strcmp(my_command->command, "push") == 0)
			push_to_stack(&my_stack, my_command->arg, s_or_q);
		else if (strcmp(my_command->command, "stack") == 0)
			s_or_q = STACK;
		else if (strcmp(my_command->command, "queue") == 0)
			s_or_q = QUEUE;
		else
			(get_func(my_command->command))(&my_stack, line_number);

		line_number++;
		chars_read = getline(&buf, &buf_size, fp);

		free(my_command);
	}

	free(buf);

	fclose(fp);

	return (0);
}
