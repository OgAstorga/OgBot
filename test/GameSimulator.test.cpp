#include <iostream>

#include "Board.h"
#include "GameSimulator.h"

#include <time.h>
#include <cstdlib>

int main() {
  srand( time ( NULL ) );
  short lastmove;
  int p[3];

  Board board({
    ".....x...",
    "...ox.o.o",
    ".o.....o.",
    "..x.o....",
    ".x..o...x",
    "x....x.o.",
    ".o.xxx...",
    ".........",
    ".......o.",
  });
  lastmove = 1*9 + 4;

  cout << board.to_string(true) << endl;

  p[0] = p[1] = p[2] = 0;

  cout << "simulating..." << endl;
  for (int i=0; i<10000; ++i) {
    short player = GameSimulator(board, lastmove);
    p[player]++;
  }
  cout << "done." << endl;
  cout << "ties: " << p[0] << endl;
  cout << "o-wins: " << p[1] << endl;
  cout << "x-wins: " << p[2] << endl;
  cout << endl;

  Board inverted({
    ".....o...",
    "...xo.x.x",
    ".x.....x.",
    "..o.x....",
    ".o..x...o",
    "o....o.x.",
    ".x.ooo...",
    ".........",
    ".......x.",
  });
  lastmove = 1*9 + 4;

  cout << inverted.to_string(true) << endl;

  p[0] = p[1] = p[2] = 0;

  cout << "simulating..." << endl;
  for (int i=0; i<10000; ++i) {
    short player = GameSimulator(inverted, lastmove);
    p[player]++;
  }
  cout << "done." << endl;
  cout << "ties: " << p[0] << endl;
  cout << "o-wins: " << p[1] << endl;
  cout << "x-wins: " << p[2] << endl;
  cout << endl;
}
