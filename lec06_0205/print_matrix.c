#include <stdio.h>

int main(void) {
  int i, j, n;

  printf("Enter dimension:\t");
  scanf("%d", &n);
  if (n > 0 && n <= 8) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i > j) {
          printf("0 ");
        } else if (i == j) {
          printf("1 ");
        }
      }
      printf("\n");
    }
  } else {
    printf("Too big a matrix!\n");
  }
  return 0;
}
