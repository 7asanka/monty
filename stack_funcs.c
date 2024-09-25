#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: The stack (doubly linked list)
 * @line_number: The line number of the instruction
 * @n: The integer to push
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void) line_number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: The stack (doubly linked list)
 * @line_number: The line number of the instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number of the instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: the line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		handle_error("can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * free_stack - Frees the stack
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
