#include <stdio.h>

int *printx(void) {
  static int x = 0;
  printf("value of x is %d \n", x++);
  return (&x);
}

int main() {
  int *x_ptr;
  x_ptr = printx();
  x_ptr = printx();
  *x_ptr = (*x_ptr) + 1;
  printx();
}
