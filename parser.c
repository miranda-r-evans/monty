#include "monty.h"

command_arg *parse_line(char *line, unsigned int line_number)
{
	char *end_ptr;
	command_arg *ret = malloc(sizeof(command_arg));

	while (*line == '#')
	{
		while (*line != '\n' && *line != '\0')
			line++;

		if (*line == '\n')
			line++;
	}

	while (*line == ' ' || *line == '\t')
		line++;

	if (*line == '\0' || *line == '\n')
		return (NULL);

	end_ptr = line;
	while (*end_ptr != ' ' && *end_ptr != '\t' &&
	       *end_ptr != '\n' && *end_ptr != '\0')
		end_ptr++;

	if (*end_ptr == '\0' || *end_ptr == '\n')
	{
		*end_ptr = '\0';
		ret->command = strdup(line);
		return (ret);
	}

	*end_ptr = '\0';
	ret->command = strdup(line);

	line = end_ptr + 1;

	while (*line == ' ' || *line == '\t')
		line++;

	end_ptr = line;
	while (*end_ptr != ' ' && *end_ptr != '\t' &&
               *end_ptr != '\n' && *end_ptr != '\0')
                end_ptr++;

	if (end_ptr != line)
	{
		*end_ptr = '\0';
		ret->arg = atoi(line);
	}
	else if (strcmp("push", ret->command) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	return ret;
}
