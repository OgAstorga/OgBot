#include "GetRandomPlayWinner.h"

char GetRandomPlayWinner(vector<string> board, pair<int, int> lastMove) {
  while (true) {
    // Get valid moves
    vector<pair<int, int> > moves = GetValidMoves(board, lastMove);

    if (moves.size() == 0) {
      break;
    }

    // Choose move at random
    pair<int, int> move = moves[rand() % moves.size()];

    // Do move
    char nextPlayer = FIRST_PLAYER;
    if (lastMove.first != -1 && lastMove.second != -1) {
      nextPlayer = board[lastMove.first][lastMove.second];
      nextPlayer = ( nextPlayer == 'o' ) ? 'x' : 'o';
    }

    board[move.first][move.second] = nextPlayer;

    // Update lastMove
    lastMove = move;
  }

  vector<string> zoomedOutBoard = ZoomOutBoard(board);
  char winner = QuadrantWinner(zoomedOutBoard, make_pair(0, 0));

  return winner;
}
