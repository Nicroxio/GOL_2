#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Copyright (c) 2025 Nicroxio. All Rights Reserved.
// Game Of Life a rough re-crtation of my python version but in C/C++

#define ROWS 10
#define COLS 30

typedef struct {
  bool alive;
  bool boarder;
  int neighbours;
} Life;

void printBoard(Life Board[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (Board[row][col].boarder == true) {
        continue;
      } else {
        printf("%d", Board[row][col].alive);
      }
    }
    printf("\n");
  }
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

int counter(Life Board[ROWS][COLS]) {
  int vision[8][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0},
                      {0, 0}, {0, 0}, {0, 0}, {0, 0}};
  int count = 0;
  Life Local[ROWS][COLS];
  memcpy(Local, Board, sizeof(Life));
  for (int row; row < ROWS; row++) {
    for (int col; col < COLS; col++) {
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  Life Board[ROWS][COLS];
  initBoard(Board);
  printBoard(Board);
  return 0;
}
