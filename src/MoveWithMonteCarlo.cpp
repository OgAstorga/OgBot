#include "MoveWithMonteCarlo.h"

pair<int, int> MoveWithMonteCarlo(vector<string> board, pair<int, int> lastMove) {
  srand( time ( NULL ) );

  vector<pair<int, int> > moves = GetValidMoves(board, lastMove);
  char player = FIRST_PLAYER;
  if (lastMove.first != -1 && lastMove.second != -1) {
    player = (board[lastMove.first][lastMove.second] == 'o') ? 'x' : 'o';
  }

  int t = time( NULL );
  vector<int> notWon(moves.size(), 0);
  while (1) {
    if (time( NULL ) - t >= MONTECARLO_TIME) {
      break;
    }

    for (int i=0, l=moves.size(); i<l; ++i) {
      pair<int, int>& move = moves[i];

      // Do move
      board[move.first][move.second] = player;

      // Calc chances
      char winner = GetRandomPlayWinner(board, move);
      if (winner != player) {
        notWon[i]++;
      }

      // Undo move
      board[move.first][move.second] = '.';
    }
  }

  int bestMoveIndex = 0;
  for (int i=0; i<moves.size(); ++i) {
    if (notWon[i] < notWon[bestMoveIndex]) {
      bestMoveIndex = i;
    }
  }

  return moves[bestMoveIndex];
}
