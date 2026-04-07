#include "linkedlists.c"

node *headptr_prez = NULL;

node *middle(node *start, node *end) {
  node *slow, *fast;
  /* Case of empty list */
  if (start == NULL)
    return NULL;

  /* Initialize pointers */
  slow = start;
  fast = start->next;

  while (fast != end) {
    /* Update fast once */
    fast = fast->next;
    if (fast != end) {
      /* Update slow once */
      slow = slow->next;
      /* If fast was not last, update it once more */
      fast = fast->next;
    }
  }

  return slow;
}

node *binary_search(node *cursor, int byear) {
  node *start, *end, *mid;
  start = cursor;
  end = NULL;
  do {
    mid = middle(start, end);
    if (mid == NULL) {
      return NULL; // Didn't find item
    }
    if (mid->byear == byear) {
      return mid;
    } else if (mid->byear < byear) {
      start = mid->next;
    } else {
      end = mid;
    }
  } while (start != end || end == NULL);

  return NULL;
}

int main(void) {
  char *gops[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int gop_years[] = {1942, 1924, 1961, 1946};

  char *dems[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int dem_years[] = {1911, 1946, 1946, 1913};

  node temp;
  for (int i = 0; i < 4; i++) {
    temp.name = gops[i];
    temp.byear = gop_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  for (int i = 0; i < 4; i++) {
    temp.name = dems[i];
    temp.byear = dem_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  print_list(headptr_prez);

  node *ww2_baby = binary_search(headptr_prez, 1970);
  ww2_baby != NULL
      ? printf("President %s was born during WWI\n", ww2_baby->name)
      : printf("Not found!\n");
  destroy(&headptr_prez);
}
