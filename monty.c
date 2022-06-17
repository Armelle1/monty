#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - Monty program
 * Return: Always EXIT_SUCCESS.
 */
int main(int argc, char *argv[])
{
  stack_t *stack;
  char  *filename, buffer[128];
  FILE *fp;
  char *ptr, *values[2] = {NULL, NULL};
  int i, line;

  if (argc < 2)
  {
	  dprintf(2, "Error");
  }
  filename = argv[1];
  stack = NULL;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
	  perror("Unable to open file!");
	  return (1);
  }
  line = 1;
  while (fgets(buffer, sizeof(buffer), fp) != NULL)
  {
	  i = 0;
	  ptr = strtok(buffer, " ");
	  ptr[4] = '\0';
	  while (ptr != NULL && i < 2)
	  {
		  if (strcmp(ptr, " ") != 0)
		  {
			  values[i++] = ptr;
		  }
		  ptr = strtok(NULL, " ");
	  }
	  stack = process(stack, values[0], values[1], line);
	  line++;

  }
 
  fclose(fp);
  return (EXIT_SUCCESS);
}
