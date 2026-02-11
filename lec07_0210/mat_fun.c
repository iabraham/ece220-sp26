#include <stdio.h>

/* Both declaration and defintion */
void print_upper(int N) {
  int r, c;
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
}

/* A declaration */;
void print_lower(int N);

int main(void) {
  int N;
  char choice;

  printf("Enter the size of the matrix: ");
  scanf("%d", &N);

  if (N > 9 || N < 2) {
    printf("Error: Incompatible dimensions!\n");
    return 1;
  }
  do {

    printf("Choose upper (u/U) or lower (l/L) triangular or exit (e): ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'u':
    case 'U':
      print_upper(N);
      break;
    case 'l':
    case 'L':
      print_lower(N);
      break;
    case 'e':
      return 0;
    default:
      printf("Unrecognized option; enter 'L' or 'l' or 'u' or 'U'.\n");
    }
  } while (choice != 'e');
  return 0;
}

/* Definition */
void print_lower(int N) {
  int r, c;
  for (r = 0; r < N; r++) {
    for (c = 0; c < N; c++) {
      if (c <= r) {
        (r == c) ? printf("1 ") : printf("0 ");
      }
    }
    printf("\n");
  }
}
