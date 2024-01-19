#include "monty.h"
#include <ctype.h>

/**
 * execute - Executes the Monty bytecode instructions.
 * @content: Instruction content
 * @stack: Pointer to the stack
 * @counter: Line number
 * @file: File pointer
 *
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter)
{
	instruction_t opst[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	/*
	 * Check if the line is empty or
	 * consists of only whitespace characters
	 */
	if (!content || is_all_whitespace(content))
		return (0);

	op = strtok(content, " \n\t");

	/* Check if it's a comment */
	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	/* Handle unknown instruction without exiting immediately */
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		return (1);
	}

	return (1);
}

/**
 * Helper function - Checks if a string consists of only whitespace characters.
 * @str: Input string
 *
 * Return: 1 if all whitespace, 0 otherwise
 */
int is_all_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
