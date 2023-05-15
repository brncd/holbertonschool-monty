#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: Doubly linked list.
 * @line_number: Number of the current line.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *numchar = NULL;
	int num = 0;
	stack_t *newNode = NULL;

	numchar = strtok(NULL, " \t\n");
	if (!numchar)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_cleanup(EXIT_FAILURE, stack, newNode);
	}

	char *endptr;
	num = strtol(numchar, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_cleanup(EXIT_FAILURE, stack, newNode);
	}

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: unable to allocate memory\n");
		exit_cleanup(EXIT_FAILURE, stack, newNode);
	}

	newNode->n = num;
	newNode->next = *stack;
	newNode->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
