#include "monty.h"

/**
 * f_mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Pointer to the stack
 * @counter: Line number
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int stack_length, result;

	/* Check if the stack has at least two elements */
	stack_length = 0;
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element is zero */
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	/* Perform modulo operation and update the stack */
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*head = temp->next;

	/* Free the memory of the top element */
	free(temp);
}
