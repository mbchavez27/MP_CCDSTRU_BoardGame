#include <stdio.h>

int main() {
  char ch;
  printf("Use WASD to move. Press 'q' to quit.\n");

  while (1) {
    ch = getchar(); // Waits for Enter after each input
    if (ch == 'q')
      break;

    switch (ch) {
    case 'w':
      printf("Up\n");
      break;
    case 's':
      printf("Down\n");
      break;
    case 'a':
      printf("Left\n");
      break;
    case 'd':
      printf("Right\n");
      break;
    }
  }
  return 0;
}
