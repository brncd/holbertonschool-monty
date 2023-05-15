#include "monty.h"

/**
 * get_opcode_function - Gets the corresponding function for an opcode.
 * @line_number: Line number
 * Return: The corresponding function or NULL.
 */
void (*get_opcode_function(char *opcode))(stack_t **stack,
unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL},
	};

	int i = 0;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}
