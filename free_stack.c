#include "monty.h"

/**
 * free_stack - frees a doubly linked list (stack)
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
