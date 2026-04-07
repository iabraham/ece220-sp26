#include "linkedlists.c"

node *stacktop = NULL;

void push(node **cursor, node *newnode) { add_at_head(cursor, newnode); }
node *pop(node **headptr) {
  if (*headptr == NULL)
    return NULL;
  else {
    node *new = (node *)malloc(sizeof(node));
    new->name = (*headptr)->name;
    new->byear = (*headptr)->byear;
    new->next = NULL;

    node *old_head = *headptr;
    *headptr = (*headptr)->next;
    free(old_head);

    return new;
  }
}

int main(void) {
  unsigned int years[] = {1988, 1986, 1990, 1992};
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  node temp;

  for (int i = 0; i < 4; i++) {
    temp.name = names[i];
    temp.byear = years[i];
    temp.next = NULL;
    push(&stacktop, &temp);
  }

  print_list(stacktop);
  printf("--------------\n");
  node *popped = pop(&stacktop);
  printf("We popped %s\n", popped->name);
  printf("--------------\n");
  print_list(stacktop);
  free(popped);
  destroy(&stacktop);
}
