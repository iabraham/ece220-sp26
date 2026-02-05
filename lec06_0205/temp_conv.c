#include <stdio.h>

int main(void) {
  int fahren;
  double celsius;
  do {
    printf("Enter current temp in deg F:\t");
    scanf("%d", &fahren);
    celsius = (fahren - 32) * 5 / 9.0;

    printf("\nTemp in deg C is :\t %f\n", celsius);
  } while (celsius > -273.15);
  return 0;
}
