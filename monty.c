#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: void
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode != NULL && opcode[0] != '#')
        {
            void (*op_func)(stack_t **stack, unsigned int line_number) = get_opcode_function(opcode);
            if (op_func == NULL)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free(line);
                fclose(file);
                free_stack(stack);
                return EXIT_FAILURE;
            }
            op_func(&stack, line_number);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return EXIT_SUCCESS;
}
