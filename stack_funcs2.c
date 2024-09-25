#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the number of the current line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i = 0;

	if (stack == NULL || *stack == NULL)
	{
		handle_error("can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		i++;
		current = current->next;
	}

	if (i < 2)
	{
		handle_error("can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;
	current->next = (*stack)->next;
	(*stack)->next = current;
	current->prev = *stack;
	(*stack)->prev = NULL;
}

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: number of the current line
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i = 0;

	if (stack == NULL || *stack == NULL)
	{
		handle_error("can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}

	if (i < 2)
	{
		handle_error("can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n = (*stack)->n + current->n;
	pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: the stack
 * @line_number: number of the current line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
