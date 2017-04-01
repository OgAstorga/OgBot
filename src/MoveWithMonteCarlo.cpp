#include "MoveWithMonteCarlo.h"

short MoveWithMonteCarlo(Board board, short lastmove) {
  vector<short> moves = board.valid_moves(lastmove);

  short me = 1;
  if (board.board.test(lastmove)) {
    me = 2;
  }

  int chances[81][3];
  for (int i=0; i<81; ++i) {
    for (int p=0; p<3; ++p) {
      chances[i][p] = 0;
    }
  }

  for (int j=0; j<1000; ++j) {
    for (int i=0, l=moves.size(); i<l; ++i) {
      short move = moves[i];
      board.set_cell(move, me);

      chances[i][GameSimulator(board, move)]++;

      board.set_cell(move, 0);
    }
  }

  short selected_index = 0;
  for (int i=0, l=moves.size(); i<l; ++i) {
    if (chances[i][0] / 2 + chances[i][me] > chances[selected_index][0] / 2 + chances[selected_index][me]) {
      selected_index = i;
    }
  }

  /*
  // SHOW SELECTION ODDS

  short move = moves[selected_index];
  cout << move / 9 << ' ' << move % 9 << " -> " << endl;
  cout << "  ties: "   << chances[selected_index][0] << endl;
  cout << "  o-wins: " << chances[selected_index][1] << endl;
  cout << "  x-wins: " << chances[selected_index][2] << endl;
  */

  return moves[selected_index];
}
