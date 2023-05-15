#include "monty.h"

/**
 * process_file - Process the Monty file
 * @file: Pointer to the Monty file
 * @stack: Pointer to the stack
 * Return: Exit status
 */
int process_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			void (*op_func)(stack_t **stack,
				unsigned int line_number) = get_opcode_function(opcode);
			if (op_func == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
				free(line);
				return (EXIT_FAILURE);
			}
			op_func(stack, line_number);
		}
	}

	free(line);
	return (EXIT_SUCCESS);
}

/**
 * run_monty - Run the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Exit status
 */
int run_monty(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	int exit_status = process_file(file, &stack);

	fclose(file);
	free_stack(stack);

	return (exit_status);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	int exit_status = run_monty(argc, argv);

	return (exit_status);
}
