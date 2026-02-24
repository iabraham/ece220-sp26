#include <stdio.h>

void transpose(int *mat, int *tr_mat, int nr, int nc) {
  /* Fill in code to transpose the matrix mat into tr_mat. */
}

void print_mat(int *mat, int nr, int nc) {
  /* Fill in code to print the matrix mat. */
}

int main(void) {
  int mat[][3] = {1, 2, 3, 4, 5, 6};
  int tr_mat[3][2];
  print_mat((int *)mat, 2, 3);
  transpose((int *)mat, (int *)tr_mat, 2, 3);
  print_mat((int *)tr_mat, 3, 2);
}
