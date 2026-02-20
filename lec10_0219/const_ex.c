#include <stdio.h>

int main(void) {
  const int var = 10;
  int *ptr = &var;

  *ptr = 12;
  printf("var = %d\n", *ptr);
}
