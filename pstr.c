#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
		{
			break;
		}
		putchar(h->n);
		if (h->n == 0)
			break;
		h = h->next;
	}
	putchar('\n');
}

