#include <stdio.h>
#include "list.h"

int main(void)
{
  List_ptr list = create();
  add_to_end(list, 5);
  return 0;
}