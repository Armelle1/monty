#ifndef STACK_H
#define STACK_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
size_t pall(const stack_t *h);
size_t dlistint_len(const stack_t *h);
stack_t *push(stack_t **head, const int n);
void free_stack(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *process(stack_t *stack, char *cmd, char *param, int line);
#endif
