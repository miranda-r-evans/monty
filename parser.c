#include "monty.h"

unsigned int line_number;

/**
 * parse_line - parses a line from bytecode file
 * @line: line from file
 *
 * Return: a struct pointer containing an opcode and an argument
 */
command_arg *parse_line(char *line)
{
	command_arg *ret;
	const char *delim = " \t\n";
	char *num_str;

	while (*line == ' ' || *line == '\t')
		line++;

	if (*line == '#' || *line == '\n' || *line == '\0')
		return (NULL);

	ret = malloc(sizeof(command_arg));
	ret->command = strtok(line, delim);

	num_str = strtok(NULL, delim);

	if (strcmp(ret->command, "push") == 0)
	{
		if (num_str != NULL)
			ret->arg = atoi(num_str);
		else
			ret->command = NULL;
	}

	return (ret);
}
