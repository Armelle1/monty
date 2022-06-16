#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 ** push - pushes an element to the stack
 **@head: head
 **@n: the value of the new node
 ** Return: the address of the new element, or NULL if it failed
 **/
stack_t *push(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (NULL);
	}
	new->n = n;
	if (*head != NULL)
	{
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
	}
	*head = new;
	return (new);
}
