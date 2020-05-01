#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create();
  add_to_end(list, 5);
  add_to_start(list, 6);
  display(list);
  return 0;
}