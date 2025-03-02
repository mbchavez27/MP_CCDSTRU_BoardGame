#include <stdio.h>

#define A_SET 4

void gameBoard() {
  for (int i = 0; i < A_SET; i++) {
    for (int j = 0; j < A_SET; j++) {
      printf("| %c | ", 'x');
    }
  }
}

int main() {

  char P_board[A_SET][A_SET];

  gameBoard();

  return 0;
}
