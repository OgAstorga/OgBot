#include "MoveWithNegamax.h"

double negamax(Board node, short lastmove, short player, short depth) {
  vector<short> moves = node.valid_moves(lastmove);
  pair<short, short> macro = node.macro_board();
  pair<bool, bool> winner = make_pair(
    node.quadrant_won(macro.first),
    node.quadrant_won(macro.second)
  );

  if (winner.first || winner.second) {
    // lastplayer ended this game
    return 0;
  }

  if (moves.size() == 0) {
    // lastplayer tied this game
    return 0.5;
  }

  if (depth == 0) {
    int chances[3];
    chances[0] = chances[1] = chances[2] = 0;
    int shoots = 200;

    for (int i=0; i<shoots; ++i) {
      short sim = GameSimulator(node, lastmove);

      if (sim == player) {
        chances[0]++;
      } else if (sim == 0) {
        chances[1]++;
      } else {
        chances[2]++;
      }
    }

    /*
    cout << (player == 1 ? 'o' : 'x') << " ->";
    cout << " w: " << chances[0];
    cout << " t: " << chances[1];
    cout << " l: " << chances[2] << endl;
    cout << node.to_string(true) << endl << endl;
    */

    return (1.0 * chances[0] + 0.5 * chances[1]) / shoots;
  }

  double best = 0;
  for (auto move: moves) {
    node.set_cell(move, player);
    double v = negamax(node, move, (player == 1) ? 2 : 1, depth - 1);

    /*
    for (int i=0; i<5-depth; ++i) cout << '.';
    cout << (player == 1 ? 'x' : 'o') << " -> " << v << endl;
    */

    best = max(best, 1 - v);
    node.set_cell(move, 0);
  }

  return best;
}

short MoveWithNegamax(Board board, short lastmove) {
  short me = 1;
  if (board.board.test(lastmove)) {
    me = 2;
  }

  pair<short, short> macro = board.macro_board();
  short fullmacro = macro.first | macro.second;

  short available = 0;
  for (int i=0; i<9; ++i) {
    if (((1<<i) & fullmacro) == 0) {
      available++;
    }
  }

  short depth;
  if (available > 7) {
    depth = 0;
  } else if (available > 5) {
    depth = 1;
  } else if (available > 3) {
    depth = 2;
  } else if (available > 2) {
    depth = 3;
  } else {
    depth = 4;
  }

  vector<short> moves = board.valid_moves(lastmove);

  double best = 0;
  short selected = moves[0];

  for (auto move: moves) {
    board.set_cell(move, me);

    double v = negamax(board, move, (me == 1 ? 2 : 1), depth);
    // cout << move << ':' << v << endl;
    if (1 - v > best) {
      best = 1 - v;
      selected = move;
    }

    board.set_cell(move, 0);
  }

  return selected;
}
