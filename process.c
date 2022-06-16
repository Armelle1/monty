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

	if (cmd == NULL || param == NULL)
	{
		printf ("Invalid arguments at line : %d", line);
		return stack;
	}
  if (strcmp(cmd, "push") == 0){
	  push(&stack, atoi(param));
  }
  else if(strcmp(cmd, "pall") == 0){
	  pall(stack);
  }
  return stack;
}
