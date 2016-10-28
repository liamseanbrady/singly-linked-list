#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

void push_end(node_t **head, int value);
void push_start(node_t **head, int value);
void pop_start(node_t **head);
void print_list(node_t *head);

int main(void)
{
  // define the node type

  // Create local var to point to head of list
  node_t *head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
    return 1;
  }

  (*head).val = 1;
  (*head).next = NULL;

  push_end(&head, 2);
  push_end(&head, 3);
  push_end(&head, 4);
  push_start(&head, 0);

  print_list(head);

  printf("Popping first item...\n");

  pop_start(&head);

  print_list(head);

  // Remember to free the memory
  free(head);

  return 0;
}

void push_end(node_t **head, int value)
{
  node_t *current = *head;
  while ((*current).next != NULL) {
    current = (*current).next;
  }

  (*current).next = malloc(sizeof(node_t));
  (*(*current).next).val = value;
  (*(*current).next).next = NULL;
}

void push_start(node_t **head, int value)
{
  node_t *new_node = malloc(sizeof(node_t));
  
  (*new_node).val = value;
  (*new_node).next = *head;

  *head = new_node;
}

void pop_start(node_t **head)
{
  node_t *next_node = (**head).next;

  free(*head);
  *head = next_node;
}

void print_list(node_t *head) 
{
  node_t *current = head;

  while (current != NULL) {
    printf("Value is %d\n", (*current).val);
    current = (*current).next;
  }
}
