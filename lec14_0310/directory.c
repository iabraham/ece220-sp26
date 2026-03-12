#include <stdio.h>

int main(void) {
  char name[20];
  char desc[100];
  int i, N;

  FILE *outfile = fopen("my_directory.txt", "w");

  printf("How many entries do you want to add? ");
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    printf("Name:\t ");
    scanf("%s", name);
    printf("Description:\t ");
    scanf("%s", desc);
    fputs(name, outfile);
    fputs(", ", outfile);
    fputs(desc, outfile);
    fputs("\n", outfile);
  }

  fclose(outfile);
  return 0;
}
