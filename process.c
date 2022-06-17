#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * process - interpreter command
 * @stack: stack
 * @cmd: command
 * @param: parameter
 * @line: current line
 * Return: result
 */
stack_t *process(stack_t *stack, char *cmd, char *param, int line)
{
	int value;
	stack_t *st;

	if (strcmp(cmd, "push") == 0)
	{
		if (param == NULL)
			dprintf(2, "l<%d>: usage: push integer", line);
		value = atoi(param);
		if (param[0] != '0' && value == 0)
			dprintf(2, "l<%d>: usage: push integer", line);
		push(&stack, value);
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(cmd, "pint") == 0)
	{
		st = get_dnodeint_at_index(stack, 0);
		if (st == NULL)
			dprintf(2, "l<%d>: can't pint, stack empty\n", line);
		printf("%d\n", st->n);
	}

	return (stack);
}

