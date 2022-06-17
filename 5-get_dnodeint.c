#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 ** get_dnodeint_at_index - returns the nth node
 **@head: list
 **@index: index
 ** Return: the nth nodes
 **/
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	stack_t *current;
	unsigned int n;

	current = head;
	n = 0;
	while (current != NULL)
	{
		if (n == index)
			break;
		current = current->next;
		n++;
	}
	if (n != index)
		return (NULL);
	return (current);
}
