#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 *pop - deletes the node at index
 *@head: list
 *@index: index
 *Return: 1 if it succeeded, -1 if it failed
 **/
int pop(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int idx;

	current = *head;
	idx = 0;
	if (*head == NULL && index == 0)
		return (1);
	while (current != NULL)
	{
		if (index == idx)
			break;
		current = current->next;
		idx++;
	}
	if (index != idx)
		return (-1);
	if (current->prev == NULL)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
	}
	else if (current->next != NULL)
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}
	else
	{
	       	current->prev-> next = NULL;
	}
	if(current != NULL)
	{	
		free(current);
		current = NULL;
	}
	return (1);
}
