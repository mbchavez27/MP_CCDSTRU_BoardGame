#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_SET 4
typedef char String25[26];

void checkWinner(char P_board[][A_SET], bool *gameOver, String25 winner)
{
  // Tres
  if (P_board[0][0] == 'T' && P_board[0][1] == 'T' && P_board[0][2] == 'T' &&
      P_board[0][3] == 'T')
  {
    *gameOver = true;
    strcpy(winner, "Tres");
  }
  else if (P_board[3][0] == 'T' && P_board[3][1] == 'T' &&
           P_board[3][2] == 'T' && P_board[3][3] == 'T')
  {
    *gameOver = true;
    strcpy(winner, "Tres");
  }
  else if (P_board[0][0] == 'T' && P_board[1][1] == 'T' &&
           P_board[2][2] == 'T' && P_board[3][3] == 'T')
  {
    *gameOver = true;
    strcpy(winner, "Tres");
  }
  else if (P_board[0][3] == 'T' && P_board[1][2] == 'T' &&
           P_board[2][1] == 'T' && P_board[3][0] == 'T')
  {
    *gameOver = true;
    strcpy(winner, "Tres");
  }
  // Uno
  if (P_board[0][0] == 'U' && P_board[0][1] == 'U' && P_board[0][2] == 'U' &&
      P_board[0][3] == 'U')
  {
    *gameOver = true;
    strcpy(winner, "Uno");
  }
  else if (P_board[3][0] == 'U' && P_board[3][1] == 'U' &&
           P_board[3][2] == 'U' && P_board[3][3] == 'U')
  {
    *gameOver = true;
    strcpy(winner, "Uno");
  }
  else if (P_board[0][0] == 'U' && P_board[1][1] == 'U' &&
           P_board[2][2] == 'U' && P_board[3][3] == 'U')
  {
    *gameOver = true;
    strcpy(winner, "Uno");
  }
  else if (P_board[0][3] == 'U' && P_board[1][2] == 'U' &&
           P_board[2][1] == 'U' && P_board[3][0] == 'U')
  {
    *gameOver = true;
    strcpy(winner, "Uno");
  }

  // Dos
  if (!(*gameOver))
  {
    bool allUsed = true;
    for (int i = 0; i < A_SET; i++)
    {
      for (int j = 0; j < A_SET; j++)
      {
        if (P_board[i][j] == ' ')
        {
          allUsed = false;
          break;
        }
      }
      if (!allUsed)
        break;
    }

    if (allUsed)
    {
      *gameOver = true;
      strcpy(winner, "Dos");
    }
  }
}

void printBoard(char P_board[][A_SET], bool isUnoTurn, bool isDosTurn,
                bool isTresTurn, int row, int col)
{
  system("clear");
  printf("Board: ");

  if (isTresTurn)
    printf("Tres' Turn\n");
  else if (isDosTurn)
    printf("Dos' Turn\n");
  else if (isUnoTurn)
    printf("Uno's Turn\n");

  printf("W:Left, S:Down, A:Left, D:Right, Q:Confirm\n");
  for (int i = 0; i < A_SET; i++)
  {
    for (int j = 0; j < A_SET; j++)
    {
      if (row == i && col == j)
        printf("| \033[1;31m%c\033[0m | ", P_board[i][j]);
      else
        printf("| \033[1;32m%c\033[0m | ", P_board[i][j]);
    }
    printf("\n");
  }
}

void initBoard(char P_board[][A_SET])
{
  for (int i = 0; i < A_SET; i++)
  {
    for (int j = 0; j < A_SET; j++)
    {
      P_board[i][j] = ' ';
    }
  }
}

void gameTurn(char P_board[][A_SET], bool *isUnoTurn, bool *isDosTurn,
              bool *isTresTurn)
{
  bool turn = true;
  int row = 0;
  int col = 0;

  char ch;

  for (int i = 0; i < A_SET; i++)
  {
    for (int j = 0; j < A_SET; j++)
    {
      if (P_board[i][j] == '-')
      {
        row = i;
        col = j;
        break;
      }
    }
  }

  while (turn)
  {
    printBoard(P_board, *isUnoTurn, *isDosTurn, *isTresTurn, row, col);
    printf("(%d,%d): ", row, col);
    ch = getchar();
    while (getchar() != '\n')
      ;

    int prevRow = row, prevCol = col;

    switch (ch)
    {
    case 'w':
    case 'W':
      if (row > 0)
      {
        row--;
      }
      break;
    case 'a':
    case 'A':
      if (col > 0)
      {
        col--;
      }
      break;
    case 's':
    case 'S':
      if (row < 3)
      {
        row++;
      }
      break;
    case 'd':
    case 'D':
      if (col < 3)
      {
        col++;
      }
      break;
    case 'Q':
    case 'q':
      turn = false;
      if (*isTresTurn && P_board[row][col] == '-')
      {
        P_board[row][col] = 'T';
        *isTresTurn = false;
        *isUnoTurn = true;
        *isDosTurn = false;
      }
      else if (*isUnoTurn && P_board[row][col] == '-')
      {
        P_board[row][col] = 'U';
        *isTresTurn = false;
        *isUnoTurn = false;
        *isDosTurn = true;
      }
      else if (*isDosTurn)
      {
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
  printBoard(P_board, *isUnoTurn, *isDosTurn, *isTresTurn, row, col);
}

int main()
{
  char P_board[A_SET][A_SET];
  bool isUnoTurn = false, isDosTurn = false, isTresTurn = true;
  bool gameOver = false;
  String25 winner;

  // Set Board
  initBoard(P_board);

  while (!gameOver)
  {
    gameTurn(P_board, &isUnoTurn, &isDosTurn, &isTresTurn);
    checkWinner(P_board, &gameOver, winner);
  }
  printf("Game Over!!!!\n");
  printf("Winner is %s\n", winner);
  return 0;
}
