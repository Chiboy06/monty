#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_rotr(stack_t **head, unsigned int counter)
{
	stack_t *h, *new_head;
	(void) counter;

	if (!*head || !(*head)->next)
		return;

	h = *head;
	while (h->next)
		h = h->next;

	new_head = h;
	new_head->next = *head;
	(*head)->prev->next = NULL;
	(*head)->prev = new_head;
	*head = new_head;
}
