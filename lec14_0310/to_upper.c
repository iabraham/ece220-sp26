#include <stdio.h>

int main(void) {
  FILE *infile, *outfile;
  char curr;

  infile = fopen("lower.txt", "r");
  outfile = fopen("upper.txt", "w");

  while ((curr = fgetc(infile)) != EOF) {
    if (curr >= 97 && curr <= 122) {
      curr -= 32;
    }
    fputc(curr, outfile);
  }

  fclose(infile);
  fclose(outfile);
}
