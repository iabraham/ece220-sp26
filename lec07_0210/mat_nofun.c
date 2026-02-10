#include <stdio.h>

int main(void) {
  int N, r, c;
  char choice;

  printf("Enter the size of the matrix: ");
  scanf("%d", &N);

  if (N > 9 || N < 2) {
    printf("Error: Incompatible dimensions!\n");
    return 1;
  }
  do {

    printf("Choose upper (u/U) or lower (l/L) triangular: ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'u':
    case 'U':
      for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
          if (c >= r) {
            (r == c) ? printf("1 ") : printf("0 ");
          } else {
            printf("  ");
          }
        }
        printf("\n");
      }
      break;
    case 'l':
    case 'L':
      for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
          if (c <= r) {
            (r == c) ? printf("1 ") : printf("0 ");
          }
        }
        printf("\n");
      }
      break;
    case 'e':
      return 0;
    default:
      printf("Unrecognized option; enter 'L' or 'l' or 'u' or 'U'.\n");
    }
  } while (c != 'e');
  return 0;
}
