#include "monty.h"
/*
 * 
 * 
 * 
 * 
*/

char *cmd_tok;

int main(int argc, char **argv)
{
    FILE *monty_f;
    instruction_t instruction[] = {{"push",  push}, {"pall", pall}, {"push", push}};
    char *file_name;
    char *line = NULL;
    size_t len = 0;
    char *token;
    int i, line_number;
    stack_t *stack = NULL;

    if (argc == 1 || argc > 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file_name = argv[1];

    monty_f = fopen(file_name, "r");
    if (monty_f == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, monty_f) != -1)
    {
        token = strtok(line, "\t\n ");
        cmd_tok = strtok(NULL, " ");
        if (token != NULL)
        {
            for (i = 0, line_number = 1; i < (int)(sizeof(instruction) / sizeof(instruction[0])); i++, line_number++)
            {
                if (strcmp(token, instruction[i].opcode) == 0)
                {
                    instruction[i].f(&stack, line_number);
                    free (line);
                    break;
                }
            }
        }
        if (i == sizeof(instruction) / sizeof(instruction[0]))
        {
            fprintf(stderr, "L%u: unknown instruction %s\n",line_number, token);
            exit(EXIT_FAILURE);
        }
    }

    fclose(monty_f);
    return (0);
}