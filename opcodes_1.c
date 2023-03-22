#include "monty.h"
int nodeval;
/**
* push - adds a node to the stack
* @stack: stack
* @line_number: number of line read from file
*
* Return: nothing, but exits with value != 0 on fail
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	line_number = line_number;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		errno = -1;
		return;
	}
	if (*stack == NULL)
	{
		temp->n = nodeval;
		temp->next = NULL;
		temp->prev = NULL;
		*stack = temp;
		return;
	}
	temp->n = nodeval;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
* pall - prints the stack
* @stack: stack
* @line_number: line number from read file
* Return: nothing, but exits != 0 if fail
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;

	if (stack == NULL) /* prints nothing if stack is empty */
	{
		printf("\n");
		return;
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
