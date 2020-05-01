#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->last == NULL)
  {
    list->last = new_node;
  }
  else
  {
    new_node->next = list->head;
  }
  list->head = new_node;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  Node_ptr new_node = create_node(value);
  if (position < 0 && position > list->count)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position == list->count)
  {
    return add_to_end(list, value);
  }

  int count = 1;
  Node_ptr p_walk = list->head;
  while (count < position)
  {
    p_walk = p_walk->next;
    count++;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL && p_walk->value != value)
  {
    p_walk = p_walk->next;
  }
  return p_walk == NULL ? add_to_end(list, value) : Failure;
}

Status remove_from_start(List_ptr list)
{
  Node_ptr p_walk = list->head;
  free(list->head);
  list->head = p_walk->next;
  return Success;
}

void display(List_ptr list)
{
  printf("no of elements in list : %d\n", list->count);
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}
