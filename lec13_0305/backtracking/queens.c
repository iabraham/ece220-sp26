#include <stdio.h>

int N = 6;

/*Function checks if it's safe to place a queen at board[row][col] */
int is_safe(int board[N][N], int row, int col) {}

/*Function places a queen in row rnum */
int place_queen(int board[N][N], int rnum) {}

/* Helper function to print state of board */
void print_board(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

int main(void) {
  int board[N][N];

  /* Initialize the board */
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      board[i][j] = 0;

  print_board(board);
  printf("\n");
  printf("=====================\n");

  /* Call solver */
  place_queen(board, 0);

  /* Print results */
  print_board(board);
}
