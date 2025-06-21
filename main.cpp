#include <stdio.h>
#include <stdlib.h>

// Copyright (c) 2025 Nicroxio. All Rights Reserved.
// Game Of Life a rough re-crtation of my python version but in C/C++

#define ROWS 10
#define COLS 30

struct Life {
  bool alive = false;
  bool boarder = false;
  int neighbours = 0;
};

void printBoard(Life Board[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%d", Board[row][col].alive);
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
      Board[row][col].alive = true;
      Board[row][col].neighbours = 0;
      Board[row][col].boarder = isEdge(row, col);
    }
  }
}

int counter(Life Board[ROWS][COLS]) {
  int vision[8][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0},
                      {0, 0}, {0, 0}, {0, 0}, {0, 0}};
  int count = 0;

  return count;
}

int main(int argc, char *argv[]) {
  Life Board[ROWS][COLS];
  initBoard(Board);
  printBoard(Board);
  return 0;
}
