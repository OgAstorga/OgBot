#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <bitset>
#include <string>

using namespace std;

class Board {
public:
  bitset<162> board;
  Board(bitset<162>);
  Board(vector<string>);
  pair<short, short> quadrant(short row, short col);
  pair<short, short> macro_board();
  bool quadrant_won(short& quadrant);
};

#endif
