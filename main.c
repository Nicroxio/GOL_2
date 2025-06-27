#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Copyright (c) 2025 Nicroxio. All Rights Reserved.
// Game Of Life a rough re-crtation of my python version but in C/C++

#define ROWS 100
#define COLS 100

typedef struct {
  bool alive;
  bool boarder;
  int neighbours;
} Life;

void printBoard(Life Board[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      // if (Board[row][col].boarder == true) {
      // continue;
      //} else {
      printf("%s", Board[row][col].alive ? "█" : "⠀");
      //}
    }
    printf("\n");
  }
  printf("\033[2J \033[H");
}

bool isEdge(int row, int col) {
  return row == 0 || col == 0 || row == ROWS - 1 || col == COLS - 1;
}

void initBoard(Life Board[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      Board[row][col].boarder = isEdge(row, col);
      if (Board[row][col].boarder == true) {
        Board[row][col].alive = false;
      } else {
        Board[row][col].alive = rand() % 2;
      }
      Board[row][col].neighbours = 0;
    }
  }
}

void counter(Life Board[ROWS][COLS]) {
  int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      Board[row][col].neighbours = 0;
    }
  }

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      int count = 0;
      for (int i = 0; i < 8; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS &&
            Board[newRow][newCol].alive == true) {
          count++;
        }
      }
      Board[row][col].neighbours = count;
    }
  }
}

void updateScreen(Life Board[ROWS][COLS]) {
  Life internalBoard[ROWS][COLS];
  memcpy(internalBoard, Board, sizeof(Life) * ROWS * COLS);
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (internalBoard[row][col].neighbours < 2 &&
          internalBoard[row][col].alive) {
        internalBoard[row][col].alive = false;
      }

      if (internalBoard[row][col].neighbours > 3) {
        internalBoard[row][col].alive = false;
      }

      if (internalBoard[row][col].neighbours == 2 ||
          internalBoard[row][col].neighbours == 3 &&
              internalBoard[row][col].alive) {
        continue;
      }

      if (internalBoard[row][col].neighbours == 3 &&
          internalBoard[row][col].alive == false) {
        internalBoard[row][col].alive = true;
      }
    }
  }
  memcpy(Board, internalBoard, sizeof(Life) * ROWS * COLS);
}

int main(int argc, char *argv[]) {
  Life Board[ROWS][COLS];
  initBoard(Board);
  while (true) {
    printBoard(Board);
    counter(Board);
    updateScreen(Board);
    sleep(1);
  }
  return 0;
}
