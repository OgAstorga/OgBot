#include "Board.h"

#include <iostream>

vector<short> Board::valid_moves(short last_move) {
  pair<short, short> macro = macro_board();
  pair<bool, bool> winner = {
    quadrant_won(macro.first),
    quadrant_won(macro.second)
  };

  vector<short> moves;

  if (winner.first || winner.second) {
    return moves;
  }

  short row  = (last_move / 9) / 3;
  short col  = (last_move / 9) % 3;

  short srow = (last_move % 9) / 3;
  short scol = (last_move % 9) % 3;

  short available = macro.first | macro.second;
  if (((1 << (srow*3 + scol)) & available) == 0) {
    // local move
    int i = srow*3 + scol;
    for (int j=0; j<9; ++j) {
      if (!board.test(i*9 + j) && !board.test(81 + i*9 + j)) {
        moves.push_back(i*9 + j);
      }
    }

    // If pointed quadrant is not won but full, the next move is global
    if (moves.size()) {
      return moves;
    }
  }

  // global move
  for (int i=0; i<9; ++i) {
    if (available & (1 << i)) {
      for (int j=0; j<9; ++j) {
        if (!board.test(i*9 + j) && !board.test(81 + i*9 + j)) {
          moves.push_back(i*9 + j);
        }
      }
    }
  }

  return moves;
}
