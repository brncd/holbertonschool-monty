#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: head
 * @line_number: information of the line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int n = head->n;

	head->n = head->next->n;
	head->next->n = n;
}
