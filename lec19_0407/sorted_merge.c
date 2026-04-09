#include "linkedlists.c"
#include <stdio.h>

node *merge_lists(node *list1, node *list2) {
  /* Create result pointer, initialize to null */
  node *result = NULL;

  /* If list1 is empty copy over other list */
  if (list1 == NULL) {
    while (list2) {
      /* Add at tail position */
      add_at_tail(&result, list2);

      /*Update list pointer */
      list2 = list2->next;
    }
    /* Return right away beause rest of it will segfault */
    return result;
  }
  /* If list 2 is empty copy over other list */
  if (list2 == NULL) {
    while (list1) {
      /* Add at tail position */
      add_at_tail(&result, list1);

      /*Update list pointer */
      list1 = list1->next;
    }
    /* Return right away beause rest of it will segfault */
    return result;
  }

  /* Neither list is empty, must compare and add */
  if (list1 && list2) {
    /* If list1 has smaller element */
    if (list1->byear <= list2->byear) {
      /* Add list1's element to result */
      add_at_tail(&result, list1);
      /* Recursively call merge list */
      result->next = merge_lists(list1->next, list2);

    } else {
      /* Add list2's element to result */
      add_at_tail(&result, list2);

      /* Recursively call merge list */
      result->next = merge_lists(list1, list2->next);
    }
    return result;
  } else
    return NULL; /*There was nothing to merge*/
}

/* Reverse a list */
node *rev_list(node *headptr) {
  /* Create a new pointer and set to NULL */
  node *result = NULL;

  /* While list exists */
  while (headptr) {
    /* Add list item to result in right place */
    add_at_head(&result, headptr);

    /* Update headptr */
    headptr = headptr->next;
  }

  /* Return reversed list */
  return result;
}

node *blue_head = NULL;
node *red_head = NULL;

int main(void) {

  // Define the names and birth years of some presidents
  char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};

  // Define the names and birth years of some presidents
  char *red_names[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int red_years[] = {1911, 1946, 1946, 1913};

  node temp;

  // Create a linked lists for democrats
  for (int i = 0; i < 4; i++) {
    temp.name = blue_names[i];
    temp.byear = blue_years[i];
    temp.next = NULL;
    insert(&blue_head, &temp);
  }

  // Create a linked list for republicans
  for (int i = 0; i < 4; i++) {
    temp.name = red_names[i];
    temp.byear = red_years[i];
    temp.next = NULL;
    insert(&red_head, &temp);
  }

  print_list(red_head);
  printf("------------------------------------------\n");
  print_list(blue_head);
  printf("------------------------------------------\n");

  node *merged = merge_lists(red_head, blue_head);
  printf("------------------------------------------\n");
  print_list(merged);

  printf("------------------------------------------\n");

  print_list(rev_list(merged));

  // Delete the lists
  destroy(&merged);
  printf("Cleared merged\n");

  destroy(&blue_head);
  printf("Cleared dems\n");

  destroy(&red_head);
  printf("Cleared reps\n");
}
