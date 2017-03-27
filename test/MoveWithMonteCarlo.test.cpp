#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Board.h"
#include "MoveWithMonteCarlo.h"
#include "GameSimulator.h"

int main() {
  srand( time ( NULL ) );

  /* must play tic-tac-toe without losing nor knowing the rules of tic-tac-toe */
  Board board({
    "o...x...o",
    ".o..x..o.",
    "..o.x.o..",
    ".........",
    "xxx...xxx",
    ".........",
    "..o.x.o..",
    ".o..x..o.",
    "o...x...o",
  });
  short lastmove = 0*9 + 4;
  short player = 2;

  while (board.valid_moves(lastmove).size()) {
    lastmove = MoveWithMonteCarlo(board, lastmove);
    board.set_cell(lastmove, player);
    player = player == 1 ? 2 : 1;

    cout << board.to_string(true) << endl << endl;
  }

  pair<short, short> macro = board.macro_board();
  pair<bool, bool> winner = make_pair(
    board.quadrant_won(macro.first),
    board.quadrant_won(macro.second)
  );

  if (winner.first == 0 && winner.second == 0) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }
}
