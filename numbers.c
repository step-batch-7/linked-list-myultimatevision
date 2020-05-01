#include <stdio.h>
#include "list.h"

void print_menu()
{
  printf("Main Menu\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) display the list of numbers\n");
  printf("(l) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
};

int read(char *string)
{
  int value;
  printf("%s", string);
  scanf("%d", &value);
  return value;
}

void perform_operation(List_ptr list, char choice)
{
  int value, position;
  switch (choice)
  {
  case 'a':
    value = read("enter value to insert to start: \n");
    add_to_start(list, value);
    break;

  case 'b':
    value = read("enter value to insert to end: \n");
    add_to_end(list, value);
    break;

  case 'c':
    value = read("enter value to insert: \n");
    position = read("enter position to insert: \n");
    insert_at(list, value, position);
    break;

  case 'd':
    value = read("enter value to insert uniquely: \n");
    add_unique(list, value);
    break;

  case 'e':
    remove_from_start(list);
    break;

  case 'f':
    remove_from_end(list);
    break;

  case 'g':
    position = read("enter position to remove: \n");
    remove_at(list, position);
    break;

  case 'h':
    value = read("enter value to insert: \n");
    remove_first_occurrence(list, value);
    break;

  case 'i':
    value = read("enter value to insert: \n");
    remove_all_occurrences(list, value);
    break;

  case 'j':
    clear_list(list);
    break;

  case 'k':
    display(list);
    break;

  case 'l':
    destroy_list(list);
    break;

  default:
    break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  char choice;
  do
  {
    print_menu();
    scanf("%c", &choice);
    perform_operation(list, choice);
    while ((getchar()) != '\n')
      ;
  } while (choice != 'l');
  return 0;
}
