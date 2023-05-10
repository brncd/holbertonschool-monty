#include "monty.h"

int main(int argc, char **argv)
{
    char *line = NULL, *opcode = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file_pointer = fopen(argv[1], "r");
    if (file_pointer == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file_pointer) != -1)
    {
        line_number++;
        opcode = strtok(line, " \n\t");
        if (strncmp(opcode, "push", len) == 0)
        {
            fprintf(stdout, "%s\n", opcode);
        }
    }

    fclose(file_pointer);
    if (line != NULL)
        free(line);
    return (EXIT_SUCCESS);
}
