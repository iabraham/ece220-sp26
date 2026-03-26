#include <stdio.h>
#include <stdlib.h>

typedef struct person {
  char *name;
  unsigned int byear;
  struct person *next;
} node;

// Code to print list - EX 1 (Slide 18)
void print_list(node *cursor) {}

// Code to add at head - EX 1 (Slide 18)
void add_at_head(node **cursor, node *new) {}

// Code to add at tail - (Slide 23)
void add_at_tail(node **cursor, node *new) {}

// Code to delete at head - (Slide 25)
void del_head(node **headptr) {}

// Code to destroy list - (Slide 31)
void destroy(node **headptr) {}

// Code to delete at tail - (Slide 26)
void del_tail(node **cursor) {}

int main(void) {
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  unsigned int byears[] = {1988, 1986, 1990, 1992};
  node temp;
  node *headptr = NULL;

  for (int i = 0; i < 4; i++) {
    temp.name = names[i];
    temp.byear = byears[i];
    temp.next = NULL;
    add_at_head(&headptr, &temp);
  }

  print_list(headptr);
  printf("\n----------------\n");
  del_head(&headptr);
  print_list(headptr);
  printf("\n----------------\n");
  del_tail(&headptr);
  print_list(headptr);

  destroy(&headptr);
}
