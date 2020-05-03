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
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
};

int read(char *string)
{
  int value;
  printf("%s", string);
  scanf("%d", &value);
  return value;
}

void print_status(Status status, char *message)
{
  char *string = "is not done";
  if (status == Success)
  {
    string = "is done";
  }
  printf("%s %s\n", message, string);
}

void perform_operation(List_ptr list, char choice)
{
  int value, position;
  Status status;
  switch (choice)
  {
  case 'a':
    value = read("enter value to add to start: \n");
    status = add_to_start(list, value);
    print_status(status, "insert value to start");
    break;

  case 'b':
    value = read("enter value to add to end: \n");
    status = add_to_end(list, value);
    print_status(status, "insert value to end");

    break;

  case 'c':
    value = read("enter value to insert: \n");
    position = read("enter position to insert: \n");
    status = insert_at(list, value, position);
    print_status(status, "insert value at given position");

    break;

  case 'd':
    value = read("enter value to insert uniquely: \n");
    status = add_unique(list, value);
    print_status(status, "insert unique value to end");
    break;

  case 'e':
    status = remove_from_start(list);
    print_status(status, "remove value from start");
    break;

  case 'f':
    status = remove_from_end(list);
    print_status(status, "remove value from end");
    break;

  case 'g':
    position = read("enter position to remove: \n");
    status = remove_at(list, position);
    print_status(status, "remove value at given position");

    break;

  case 'h':
    value = read("enter value to insert: \n");
    status = remove_first_occurrence(list, value);
    print_status(status, "remove first occurence of value");
    break;

  case 'i':
    value = read("enter value to insert: \n");
    status = remove_all_occurrences(list, value);
    print_status(status, "remove all occurences of value");
    break;

  case 'j':
    status = clear_list(list);
    print_status(status, "clearing list");
    break;

  case 'k':
    value = read("enter value to search: \n");
    status = is_value_exists(list, value);
    print_status(status, "searching value");
    break;

  case 'l':
    display(list);

    break;

  case 'm':
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
  } while (choice != 'm');
  return 0;
}
