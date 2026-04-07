#include "linkedlists.c"

node *front = NULL;

void enqueue(node **cursor, node *newnode) { add_at_tail(cursor, newnode); }

node *dequeue(node **headptr) {
  if (*headptr == NULL)
    return NULL;
  else {
    node *new = (node *)malloc(sizeof(node));
    new->name = (*headptr)->name;
    new->byear = (*headptr)->byear;

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
    enqueue(&front, &temp);
  }

  print_list(front);
  printf("--------------\n");
  node *removed = dequeue(&front);
  printf("We removed %s\n", removed->name);
  printf("--------------\n");
  print_list(front);

  free(removed);
  destroy(&front);
}
