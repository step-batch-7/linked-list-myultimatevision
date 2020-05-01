#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *create_node(int value)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create(void)
{
  List_ptr list = malloc(sizeof(list));
  list->head = NULL;
  list->last = NULL;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node *new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  return Success;
}