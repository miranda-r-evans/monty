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

	ret = malloc(sizeof(command_arg));
	if (ret == NULL)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}

	while (*line == ' ' || *line == '\t')
		line++;

	if (*line == '#' || *line == '\n' || *line == '\0')
	{
		ret->command = NULL;
		return (ret);
	}

	ret->command = strtok(line, delim);

	if (strcmp(ret->command, "push") == 0)
	{
		num_str = strtok(NULL, delim);

		if (num_str != NULL)
		{
			ret->arg = atoi(num_str);
			while (*num_str != '\0')
			{
				if (*num_str != '-' && (*num_str > '9' ||
							*num_str < '0'))
				{
					printf("L%d: usage: push integer\n", line_number);
					free(ret);
					return (NULL);
				}
				num_str++;
			}
		}
		else
		{
			printf("L%d: usage: push integer\n", line_number);
			free(ret);
			return (NULL);
		}
	}

	return (ret);
}
