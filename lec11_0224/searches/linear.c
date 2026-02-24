#include "search.h"

int search(int list[], int n, int key) {
  int i = 0;
  for (i = 0; i < n; i++) {
    if (list[i] == key)
      return i;
  }
  return -1;
}
