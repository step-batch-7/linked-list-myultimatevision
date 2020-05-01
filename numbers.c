#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create_list();
  add_to_end(list, 7);
  insert_at(list, 4, 0);
  add_to_start(list, 9);
  add_unique(list, 8);

  remove_from_start(list);
  remove_from_end(list);
  remove_at(list, 1);

  remove_first_occurrence(list, 5);
  remove_all_occurrences(list, 9);

  display(list);

  clear_list(list);
  destroy_list(list);
  return 0;
}