#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_SET 4
typedef char String25[26];

/************************************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned.  I have constructed the functions and their respective algorithms and corresponding code by myself.  The
program was run, tested, and debugged by my own efforts.  I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.

                                                                              Max Benedict B. Chavez,    DLSU ID 12328146
************************************************************************************************************************/

void printInstructions()
{
  const char *red = "\033[1;31m";
  const char *green = "\033[1;32m";
  const char *reset = "\033[0m";

  printf("%s+---------------------------+%s\n", red, reset);
  printf("%s|   4 STEPS INSTRUCTIONS    |%s\n", red, reset);
  printf("%s+---------------------------+%s\n", red, reset);
  printf("%s| 1. Use 'W', 'A', 'S', 'D'  |%s\n", green, reset);
  printf("%s|    to move around the grid |%s\n", green, reset);
  printf("%s| 2. Press 'Q' to confirm    |%s\n", green, reset);
  printf("%s| 3. Place your mark (T/U)   |%s\n", green, reset);
  printf("%s|    on the board            |%s\n", green, reset);
  printf("%s| 4. Try to complete a row,  |%s\n", green, reset);
  printf("%s|    column, or diagonal!    |%s\n", green, reset);
  printf("%s+---------------------------+%s\n", red, reset);
  printf("\n\n");
  fgetc(stdin);
}

void printTitle()
{
  const char *red = "\033[1;31m";
  const char *green = "\033[1;32m";
  const char *reset = "\033[0m";

  printf("%s _____                ____              _   _             %s\n", red, reset);
  printf("|_   _| __ ___  ___  |  _ \\  ___  ___  | | | |_ __   ___  %s\n", green);
  printf("  | || '__/ _ \\/ __| | | | |/ _ \\/ __| | | | | '_ \\ / _ \\ %s\n", red);
  printf("  | || | |  __/\\__ \\ | |_| | (_) \\__ \\ | |_| | | | | (_) | %s\n", green);
  printf("  |_||_|  \\___||___/ |____/ \\___/|___/  \\___/|_| |_|\\___/  %s\n", red);
  printf("%s", reset);
  printf("\n");
}

void printMenu()
{
  const char *red = "\033[1;31m";
  const char *green = "\033[1;32m";
  const char *reset = "\033[0m";

  printf("%s+---------------------+%s\n", red, reset);
  printf("%s|     MENU OPTIONS    |%s\n", red, reset);
  printf("%s+---------------------+%s\n", red, reset);
  printf("%s| 1. Play             |%s\n", green, reset);
  printf("%s| 2. Instructions     |%s\n", green, reset);
  printf("%s| 3. Exit             |%s\n", green, reset);
  printf("%s+---------------------+%s\n", red, reset);
}

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
  printTitle();
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

void nextPlayerMove(char P_board[][A_SET], bool *isUnoTurn, bool *isDosTurn,
                    bool *isTresTurn, int row, int col, bool *turn)
{
  *turn = false;
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
    printf("(%d,%d): ", row + 1, col + 1);
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
      nextPlayerMove(P_board, isUnoTurn, isDosTurn, isTresTurn, row, col, &turn);
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
  int input;
  while (input != 3)
  {
    printTitle();
    printMenu();

    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
    {
      input = -1;
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
      printf("\n\n");
      printf("Game Over!!!!\n");
      printf("Winner is %s\n", winner);
      printf("\n\n");
    }
    if (input == 2)
    {
      printInstructions();
    }
    if (input == 3)
    {
      printf("Goodbye\n");
    }
  }
  return 0;
}
