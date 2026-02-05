#include <stdio.h>

int main(void) {
  int a = 2;
  switch (a) {
  case 1:
    printf("A");
  case 2:
    printf("B");
  case 3:
    printf("C");
  default:
    printf("D");
  }
  return 0;
}
