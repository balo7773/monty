#include "monty.h"

void pop(stack_t **head, unsigned int line_number)

{
    stack_t *current_top, *top;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    current_top = NULL;
    top = *head;

    while (top->next != NULL)
    {
        current_top = top;
        top = top->next;
    }

    if (current_top != NULL)
    {
        current_top->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(top);
}




void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_top;
    int number;
    number = atoi(cmd_tok);
    if (number == 0)
    {
        fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
    }
    new_top = (stack_t *)malloc(sizeof(stack_t));
    if (new_top == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
     new_top->n = number;
    if (*stack == NULL)
    {
        new_top->prev = NULL;
        new_top->next = NULL;
        *stack = new_top;
    }
    else
    {
        new_top->prev = NULL;
        new_top->next = *stack;
        (*stack)->prev = new_top;
        *stack = new_top;
    }
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;
    if (*stack == NULL)
    {
        return;
    }
    current = (stack_t *)malloc(sizeof(stack_t));
    if (current == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    current = *stack;
    
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}