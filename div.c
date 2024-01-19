#include "monty.h"

/**
 * f_div - Divides the second element by the top element of the stack.
 * @head: Pointer to the stack
 * @counter: Line number
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int stack_length, result;

	/* Check if the stack has at least two elements */
	stack_length = 0;
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element is zero */
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	/* Perform division and update the stack */
	result = temp->next->n / temp->n;
	temp->next->n = result;
	*head = temp->next;

	/* Free the memory of the top element */
	free(temp);
}

