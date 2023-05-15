#include "monty.h"
/**
 * pall - prints the value in stack
 * @stack: stack head
 * @line_number: information of the line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;
	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}