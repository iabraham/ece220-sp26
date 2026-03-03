#include <stdio.h>

void transpose(int *mat, int *tr_mat, int nr, int nc) {
  for (int i = 0; i < nr; i++)
    for (int j = 0; j < nc; j++)
      tr_mat[j * nr + i] = mat[i * nc + j];
}

void print_mat(int *mat, int nr, int nc) {
  for (int i = 0; i < nr; i++) {
    for (int j = 0; j < nc; j++)
      printf("%d", mat[i * nc + j]);
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  int mat[][3] = {1, 2, 3, 4, 5, 6};
  int tr_mat[3][2];

  /* Need to cast to (int *) to avoid compiler warning
   * about incompatible pointer types */
  print_mat((int *)mat, 2, 3);
  transpose((int *)mat, (int *)tr_mat, 2, 3);
  print_mat((int *)tr_mat, 3, 2);
}
