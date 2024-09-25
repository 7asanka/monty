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
	char line[1024];
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

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
