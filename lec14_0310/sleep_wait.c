#include <stdio.h>
#include <unistd.h>

int main() {
  putchar('a');
  fflush(stdout); /*Manually flush the output buffer to ensure 'a' is printed
                     before sleeping*/
  sleep(5);
  putchar('b');
  fflush(stdout);
  sleep(5);
  putchar('c');
  // putchar('\n');
}
