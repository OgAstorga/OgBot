#include <iostream>

#include "Board.h"

int main() {
  Board b1({
    ".........",
    ".........",
    ".........",

    ".........",
    "...x.x...",
    ".........",

    ".........",
    ".........",
    ".........",
  });

  b1.set_cell(4*9 + 4, 2);

  pair<short, short> macro = b1.macro_board();
  if (macro.first == 0 && macro.second == (1 << 4)) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  b1.set_cell(0*9 + 0, 1);
  b1.set_cell(0*9 + 4, 1);
  b1.set_cell(0*9 + 8, 1);

  macro = b1.macro_board();
  if (macro.first == 1 && macro.second == (1 << 4)) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  b1.set_cell(0*9 + 4, 0);

  macro = b1.macro_board();
  if (macro.first == 0 && macro.second == (1 << 4)) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }

  b1.set_cell(4*9 + 3, 0);

  macro = b1.macro_board();
  if (macro.first == 0 && macro.second == 0) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }
}

