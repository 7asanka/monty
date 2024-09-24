#include "monty.h"
#include <stdio.h>

/**
 * main - entry point for the Monty interpreter
 * @argc: argument count
 * @argv: argument array
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 1;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (read > 0)
	{
		read = getline(&line, &len, file);
		line_number++;
		if (read > 0)
		{
			execute_line(line, &stack, line_number);
		}
		free(line)
	}

	free_stack(stack);
	fclose(file);
	return (0);
}

