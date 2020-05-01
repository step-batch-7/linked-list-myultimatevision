#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create(void)
{
  List_ptr list = malloc(sizeof(list));
  list->head = NULL;
  list->last = NULL;
  return list;
}