#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* Filename is commandline argument */
  char *fname = argv[1];

  FILE *infile = fopen(fname, "r");
  int nr, nc;

  fscanf(infile, "%d, %d", &nr, &nc);
  int *mat = (int *)malloc(sizeof(int) * nr * nc);

  for (int i = 0; i < nr; i++)
    for (int j = 0; j < nc; j++)
      fscanf(infile, "%d, ", &mat[i * nc + j]);

  printf("Matrix read from file and stored as:\n");
  for (int i = 0; i < nr * nc; i++) {
    printf("%d ", mat[i]);
  }
  printf("\n");
  fclose(infile);
}
