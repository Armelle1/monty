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
		{
			dprintf(2, "L<%d>: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		value = atoi(param);
		if (param[0] != '0' && value == 0)
		{
			dprintf(2, "L<%d>: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		push(&stack, value);
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		if (stack != NULL)
			pall(stack);
	}
	else if (strcmp(cmd, "pint") == 0)
	{
		st = get_dnodeint_at_index(stack, 0);
		if (st == NULL)
		{
			dprintf(2, "L<%d>: can't pint, stack empty\n", line);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", st->n);
	}
	else if (strstr(cmd, "pop") != NULL)
	{
	
		if (stack == NULL)
		{
			dprintf(2, "L<%d>: can't pop an empty stack\n", line);
			exit(EXIT_FAILURE);
		}
		pop(&stack, 0);
	}

	return (stack);
}

