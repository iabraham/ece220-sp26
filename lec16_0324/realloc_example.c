#include <stdlib.h>

int main(void) {
  int *ptr;
  int *ptr_new;

  /* What does this code do? */
  ptr = (int *)calloc(2, sizeof(int));
  *ptr = 10;

  /* What is the contents of memory now? */
  ptr_new = (int *)realloc(ptr, 4 * sizeof(int));
  *(ptr_new + 2) = 30;
  *(ptr_new + 3) = 40;

  /* How much memory are we deallocating here? */
  free(ptr_new);
}
