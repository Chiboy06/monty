#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

