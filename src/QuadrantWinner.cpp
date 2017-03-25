#include "QuadrantWinner.h"

/*
  QuadrantWinner is a function that receives a uttt board and a quadrant and
  calculate if there is a winner in the given quadrant

  example
  board: --
    ..o .x. o..
    .o. .x. .o.
    o.. .x. ..o
    
    ... ... ...
    xxx ... xxx
    ... ... ...
    
    ..o .x. o..
    .o. .x. .o.
    o.. .x. ..o

  quadrant --
    0 0 -> o
    0 1 -> x
    1 1 -> .
*/
char QuadrantWinner(vector<string>& board, pair<int, int> quadrant) {
  char winner;
  int x = quadrant.first * 3;
  int y = quadrant.second * 3;

  // 3 in a row
  for (int r=0; r<3; ++r) {
    winner = board[x + r][y];
    for (int c=0; c<3; ++c) {
      if (winner != board[x + r][y + c]) {
        winner = '.';
        continue;
      }
    }

    if (winner != '.') {
      return winner;
    }
  }

  // 3 in a col
  for (int c=0; c<3; ++c) {
    winner = board[x][y + c];
    for (int r=0; r<3; ++r) {
      if (winner != board[x + r][y + c]) {
        winner = '.';
        continue;
      }
    }

    if (winner != '.') {
      return winner;
    }
  }

  // Diagonals
  winner = board[x][y];
  for (int i=0; i<3; ++i) {
    if (winner != board[x+i][y+i]) {
      winner = '.';
      continue;
    }
  }

  if (winner != '.') {
    return winner;
  }

  winner = board[x][y + 2];
  for (int i=0; i<3; ++i) {
    if (winner != board[x+i][y+2-i]) {
      winner = '.';
      continue;
    }
  }

  if (winner != '.') {
    return winner;
  }

  // Not defined
  return '.';
}

vector<int> winners = {
    7, // 000 000 111
   56, // 000 111 000
  448, // 111 000 000

   73, // 001 001 001
  146, // 010 010 010
  292, // 100 100 100

   84, // 001 010 100
  273  // 100 010 001
};

pair<bool, bool> QuadrantWinner(pair<int, int>& quadrant) {
  for (int it: winners) {
    if ((quadrant.first & it) == it) {
      return make_pair(true, false);
    }

    if ((quadrant.second & it) == it) {
      return make_pair(false, true);
    }
  }

  return make_pair(false, false);
}
