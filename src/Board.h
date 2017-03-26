#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <bitset>
#include <string>

using namespace std;

/*
  Board representation

  player o
  +---+---+---+
  |012|   |   |
  |345| 1 | 2 |
  |678|   |   |
  +---+---+---+
  |   |   |   |
  | 3 | 4 | 5 |
  |   |   |   |
  +---+---+---+
  |   |   |   |
  | 6 | 7 | 8 |
  |   |   |   |
  +---+---+---+

  player x
  +-----------+
  |           |
  |           |
  |           |
  |           |
  |           |
  |     2     |
  |           |
  |           |
  |           |
  |           |
  |           |
  +-----------+
*/

class Board {
public:
  bitset<162> board;

  Board(bitset<162>);
  Board(vector<string>);

  pair<short, short> macro_board();
  bool quadrant_won(short& quadrant);
  vector<short> valid_moves(short);
  void set_cell(short, short);
  string to_string();
};

#endif
