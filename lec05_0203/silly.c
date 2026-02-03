#include <stdio.h>

void silly(int a) {
  if (a > 0) {
    printf("Hi\n");
  } else {
    char *name = a; // Causes an error!
    printf("Hi %s", name);
  }
}

int main(void) {
  printf("Hello World\n");
  silly(-12);
  return 0;
}
