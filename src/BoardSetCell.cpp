#include "Board.h"

void Board::set_cell(short move, short player) {
  short position;

  switch (player) {
    case 0:
      board.reset(move);
      board.reset(move + 81);
      break;
    case 1:
      board.set(move);
      break;
    case 2:
      board.set(move + 81);
      break;
  };
}
