#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_SET 4
typedef char String25[26];

void checkWinner(char P_board[][A_SET], bool *gameOver, String25 winner) {
  if (P_board[0][0] == 'T' && P_board[0][1] == 'T' && P_board[0][2] == 'T' &&
      P_board[0][3] == 'T') {
    *gameOver = true;
    strcpy(winner, "Tres");
  }
}

void printBoard(char P_board[][A_SET], bool isUnoTurn, bool isDosTurn,
                bool isTresTurn) {
  system("clear");
  printf("Board: ");

  if (isTresTurn)
    printf("Tres' Turn\n");
  else if (isDosTurn)
    printf("Dos' Turn\n");
  else if (isUnoTurn)
    printf("Uno's Turn\n");

  printf("W:Left, S:Down, A:Left, D:Right, Q:Confirm\n");
  for (int i = 0; i < A_SET; i++) {
    for (int j = 0; j < A_SET; j++) {
      printf("| %c | ", P_board[i][j]);
    }
    printf("\n");
  }
}

void initBoard(char P_board[][A_SET]) {
  for (int i = 0; i < A_SET; i++) {
    for (int j = 0; j < A_SET; j++) {
      P_board[i][j] = ' ';
    }
  }
}

void gameTurn(char P_board[][A_SET], bool *isUnoTurn, bool *isDosTurn,
              bool *isTresTurn) {
  bool turn = true;
  int row = 0;
  int col = 0;

  char ch;

  for (int i = 0; i < A_SET; i++) {
    for (int j = 0; j < A_SET; j++) {
      if (P_board[i][j] == '-') {
        row = i;
        col = j;
        break;
      }
    }
  }

  while (turn) {
    printBoard(P_board, *isUnoTurn, *isDosTurn, *isTresTurn);
    printf("(%d,%d): ", row, col);
    ch = getchar();
    while (getchar() != '\n')
      ;

    int prevRow = row, prevCol = col;

    switch (ch) {
    case 'w':
    case 'W':
      if (row > 0) {
        row--;
      }
      break;
    case 'a':
    case 'A':
      if (col > 0) {
        col--;
      }
      break;
    case 's':
    case 'S':
      if (row < 3) {
        row++;
      }
      break;
    case 'd':
    case 'D':
      if (col < 3) {
        col++;
      }
      break;
    case 'Q':
    case 'q':
      turn = false;
      if (*isTresTurn && P_board[row][col] == '-') {
        P_board[row][col] = 'T';
        *isTresTurn = false;
        *isUnoTurn = true;
        *isDosTurn = false;
      } else if (*isUnoTurn && P_board[row][col] == '-') {
        P_board[row][col] = 'U';
        *isTresTurn = false;
        *isUnoTurn = false;
        *isDosTurn = true;
      } else if (*isDosTurn) {
        P_board[row][col] = ' ';
        *isTresTurn = true;
        *isUnoTurn = false;
        *isDosTurn = false;
      }
      break;
    }
    if (P_board[prevRow][prevCol] == '-')
      P_board[prevRow][prevCol] = ' ';

    if (P_board[row][col] != 'T' && P_board[row][col] != 'U')
      P_board[row][col] = '-';
  }
  printBoard(P_board, *isUnoTurn, *isDosTurn, *isTresTurn);
}

int main() {
  char P_board[A_SET][A_SET];
  bool isUnoTurn = false, isDosTurn = false, isTresTurn = true;
  bool gameOver = false;
  String25 winner;

  // Set Board
  initBoard(P_board);

  while (!gameOver) {
    gameTurn(P_board, &isUnoTurn, &isDosTurn, &isTresTurn);
    checkWinner(P_board, &gameOver, winner);
  }
  printf("Winner is %s\n", winner);
  return 0;
}
