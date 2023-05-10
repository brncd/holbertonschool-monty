#include "monty.h"

int push(stack_t **stack, unsigned int line_number)
{
    char* numchar = NULL;
    int num = 0;
    stack_t *newNode = NULL;

    numchar = strtok(NULL, " \t\n");
    if (!numchar)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        return 1;
    }

    num = atoi(numchar);

    newNode = malloc(sizeof(stack_t));
    if (!newNode)
    {
        fprintf(stderr, "Error: unable to allocate memory\n");
        return 1;
    }

    newNode->n = num;
    newNode->next = *stack;
    newNode->prev = NULL;

    if (*stack != NULL)
    {
        (*stack)->prev = newNode;
    }
    fprintf(stdout, "Node %d\n", newNode->n);
    *stack = newNode;

    return 0;
}
