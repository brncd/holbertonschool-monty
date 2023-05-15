#include "monty.h"

/**
 * exit_cleanup - Clean up allocated memory and exit the program.
 * @status: Exit status.
 * @stack: Doubly linked list.
 * @newNode: New node to be freed.
 */
void exit_cleanup(int status, stack_t **stack, stack_t *newNode)
{
    free(newNode);
    free_stack(*stack);
    exit(status);
}