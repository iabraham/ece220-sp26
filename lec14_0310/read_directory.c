#include <stdio.h>

int main(void) {
  FILE *infile = fopen("directory.txt", "r");
  char name[20];
  char desc[100];
  int status;

  printf("=====FILE CONTAINS======\n");
  status = fscanf(infile, "%[^,], %s\n", name, desc);
  while (status != EOF) {
    printf("Read %d items\n\n", status);
    printf("Name:\t%s \n", name);
    printf("Desc:\t%s \n", desc);
    printf("\n----------\n");
    status = fscanf(infile, "%[^,], %s\n", name, desc);
  };
  fclose(infile);
  return 0;
}
