#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n <= 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
