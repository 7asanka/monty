#include "monty.h"
#include <ctype.h>
/**
 * get_argument - parses an integer argument from a string
 * @line: the line with the argument
 * @num: pointer to the integer result
 *
 * Return: 0 on success, -1 on failure
 */
int get_argument(char *line, int *num)
{
	if (line == NULL || (!isdigit(*line) && *line != '-'))
		return (-1);
	*num = atoi(line);
	return (0);
}

/**
 * handle_error - handles error message and exits
 * @message: error message
 * @line_number: the line number where the error occurred
 */
void handle_error(char *message, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}

