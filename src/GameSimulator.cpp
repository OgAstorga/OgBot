#include "GameSimulator.h"

short GameSimulator(Board board, short lastmove) {
  short lastplayer = 1;
  if (board.board.test(lastmove + 81)) {
    lastplayer = 2;
  }

  vector<short> moves = board.valid_moves(lastmove);
  vector<int> chances(81);

  pair<short, short> macro;
  pair<bool, bool> winner;

  int chance, chance_sum;
  int move_region, move_index;
  short shoot;

  while (moves.size()) {
    chance_sum = 0;

    // Ponderate each move with a simple greedy
    for (int i=0; i<moves.size(); ++i) {
      shoot = moves[i];

      board.set_cell(shoot, lastplayer == 1 ? 2 : 1);
      macro = board.macro_board();
      winner = make_pair(
        board.quadrant_won(macro.first),
        board.quadrant_won(macro.second)
      );

      // Set chance to be selected
      chance = 1;

      // Is this shot a global win?
      if (winner.first || winner.second) {
        chance += 1000000000;
      }

      // Is this shot a quadrant win?
      if ((macro.first | macro.second) & (1 << (shoot / 9))) {
        chance += moves.size() * 2;
      }

      // Is the next shoot a local move?
      if (((macro.first | macro.second) & (1 << (shoot % 9))) == 0) {
        chance += 3;
      }

      chances[i] = chance;
      chance_sum += chance;

      board.set_cell(shoot, 0);
    }

    /*
    DEBUG CHANCES

    for (int i=0, l=moves.size(); i<l; ++i) {
      shoot = moves[i];
      chance = chances[i];

      cout << shoot / 9 << ' ' << shoot % 9 << " -> " << chance << '/' << chance_sum <<  endl;
    }
    */

    // Select next move
    move_region = rand() % chance_sum;
    move_index = 0;

    while (move_region >= chances[move_index]) {
      move_region -= chances[move_index++];
    }

    lastmove = moves[move_index];
    lastplayer = lastplayer == 1 ? 2 : 1;

    board.set_cell(lastmove, lastplayer);
    moves = board.valid_moves(lastmove);

    /*
    DEBUG BOARD

    cout << "play > " << lastmove / 9 << ' ' << lastmove % 9 << endl;
    cout << board.to_string(true) << endl << endl;
    */
  }

  macro = board.macro_board();
  winner = {
    board.quadrant_won(macro.first),
    board.quadrant_won(macro.second)
  };

  return (winner.first * 1 + winner.second * 2);
}
