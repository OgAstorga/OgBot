#include "Board.h"

vector<short> quadrant_winners = {
    7, // 000 000 111
   56, // 000 111 000
  448, // 111 000 000

   73, // 001 001 001
  146, // 010 010 010
  292, // 100 100 100

   84, // 001 010 100
  273  // 100 010 001
};

Board::Board(bitset<162> initial) {
  board = initial;
}

/*
  {
    "ooo......",
    "...ooo...",
    "......ooo",
    "xxx......",
    "...xxx...",
    "......xxx",
    "o.......x",
    ".o.....x.",
    "..o...x.."
  }

  means

  ooo ... ...
  ... ooo ...
  ... ... ooo

  xxx ... ...
  ... xxx ...
  ... ... xxx

  o.. ... ..x
  .o. ... .x.
  ..o ... x..
*/
Board::Board(vector<string> initial) {
  bitset<162> bitset_board;

  // split board into 9 quadrants
  for (int row=0; row<3; ++row) {
    for (int col=0; col<3; ++col) {

      // For each quadrant, calc o's and x's board
      bitset<162> o_board, x_board;

      for (int srow=0; srow<3; ++srow) {
        for (int scol=0; scol<3; ++scol) {
          switch (initial[row*3 + srow][col*3 + scol]) {
          case 'o':
            o_board.set(srow*3 + scol);
            break;
          case 'x':
            x_board.set(srow*3 + scol);
            break;
          }
        }
      }

      // shift bits to 
      o_board <<= (row*3 + col) * 9;
      x_board <<= (row*3 + col) * 9 + 81;

      bitset_board |= o_board;
      bitset_board |= x_board;
    }
  }

  board = bitset_board;
}

pair<short, short> Board::quadrant(short row, short col) {
  short o_quadrant = 0, x_quadrant = 0;

  for (int i=0; i<9; ++i) {
    if (board.test((row*3 + col) * 9 + i)) {
      o_quadrant |= (1<<i);
    }

    if (board.test((row*3 + col) * 9 + 81 + i)) {
      x_quadrant |= (1<<i);
    }
  }

  return make_pair(o_quadrant, x_quadrant);
}

bool Board::quadrant_won(short& quadrant) {
  for (short it: quadrant_winners) {
    if ((quadrant & it) == it) {
      return true;
    }
  }

  return false;
}

pair<short, short> Board::macro_board() {
  short o_macro = 0, x_macro = 0;
  short p, o_quadrant, x_quadrant;
  for (int q=0; q<9; ++q) {
    p = 1;
    o_quadrant = 0;
    x_quadrant = 0;

    for (int i=0; i<9; ++i) {
      if (board.test(q*9 + i)) {
        o_quadrant |= p;
      } else if (board.test(81 + q*9 + i)) {
        x_quadrant |= p;
      }

      p <<= 1;
    }

    if (quadrant_won(o_quadrant)) {
      o_macro |= 1<<q;
    } else if (quadrant_won(x_quadrant)) {
      x_macro |= 1<<q;
    }
  }

  return make_pair(o_macro, x_macro);
}
