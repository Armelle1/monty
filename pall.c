#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 ** pall - prints all the elements of a stack_t
 **@h: list
 ** Return: the number of nodes
 **/
size_t pall(const stack_t *h)
{
	const stack_t *current;
	unsigned int n;

	current = h;
	n = 0;
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
		n++;
	}
	return (n);
}
