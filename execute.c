#include "monty.h"

/**
 * execute_line - executes the opcode
 * @line: the current line from the bytecode file
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: 0 on success, -1 on failure
 */
int execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	char *opcode;
	unsigned int i;
	int argument;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return (0);

	if (strcmp(opcode, "push") == 0)
	{
		if (get_argument(strtok(NULL, " \t\n"), &argument) == -1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			return (-1);
		}
		push(stack, line_number, argument);
		return (0);
	}

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (-1);
}
