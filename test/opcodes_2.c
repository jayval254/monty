#include "monty.h"
/**
* add - adds top two elements of the stack
* @stack: stack
* @line_number: number of line from read file
*
* Return: nothing, but exit != 0 on failure
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		head->n += head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}

/**
* nop - no operation
* @stack: stack
* @line_number: number of line from read file
* Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	/* purposefully does nothing */
	(void) stack;
	(void) line_number;
}
