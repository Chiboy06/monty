#include "monty.h"

/**
 * f_pall - Prints the elements of the stack.
 * @head: Pointer to the stack.
 * @counter: Line number (not used).
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;
	(void)counter;
	/* To avoid unused parameter warning */

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
