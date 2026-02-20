#include <stdio.h>

int main(void) {
  int area_code, prefix, pnum, scanout;
  char mystr[13];

  printf("Enter a 10-digit phone number.\n");
  printf("Format: xxx-xxx-xxxx\n");

  fgets(mystr, 13, stdin);
  printf("You entered %s", mystr);
  scanout = scanf(mystr, "%d-%d-%d", &area_code, &prefix, &pnum);

  if (scanout != 3) {
    printf("Invalid input. Please enter a phone number in the format "
           "xxx-xxx-xxxx.\n");
    return 1;
  }
  printf("\nArea code: %d", area_code);
  printf("\nPrefix: %d", prefix);
  printf("\nLocal: %d", pnum);

  return 0;
}
