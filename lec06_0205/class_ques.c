#include <stdio.h>

/* I think in class I said assignment always evaluates to true.
 * That is only half true as you can see by running this example.
 * The correct statement is: Assignment is an expression which
 * evaluates to the ASSIGNED value. More often than not the
 * assignment is NOT to zero; so it evaluates to true. */

int main(void) {
  int y;
  int x = 4;
  printf("x is %d\n", x);
  if ((y = x + 1) % 2 == 0) {
    printf("Evaluated true!\n");
    printf("x = %d \n", x);
    printf("y = %d \n", y);
  } else {
    printf("Evaluated false!\n");
    printf("x = %d \n", x);
    printf("y = %d \n", y);
  }
  if ((x = y + 1) % 2 == 0) {
    printf("Evaluated true!\n");
    printf("x = %d \n", x);
    printf("y = %d \n", y);
  } else {
    printf("Evaluated false!\n");
    printf("x = %d \n", x);
    printf("y = %d \n", y);
  }
}
