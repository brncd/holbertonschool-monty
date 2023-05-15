#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: head
 * @line_number: information of the line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int n = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = head->n;
	head->next->n += n;
	head->next->prev = NULL;
	*stack = head->next;

	free(head);
}
