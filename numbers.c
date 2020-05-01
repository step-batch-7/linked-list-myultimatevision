#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 7);
  add_to_start(list, 9);
  insert_at(list, 4, 0);
  add_unique(list, 8);
  remove_from_start(list);
  display(list);
  return 0;
}