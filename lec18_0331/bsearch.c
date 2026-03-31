#include "linkedlists.c"

node *headptr_prez = NULL;

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

  node *ww2_baby = binary_search(headptr_prez, 1942);
  printf("President %s was born during WWII\n", ww2_baby->name);
  destroy(&headptr_prez);
}
