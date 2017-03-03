#include "GetValidMoves.h"

/*
  Calculates valid moves given current board and last move
*/
vector<pair<int, int> > getValidMoves(vector<string> board, pair<int, int> lastMove) {
  vector<pair<int, int> > validMoves;

  vector<string> zoomedOutBoard = ZoomOutBoard(board);

  if (lastMove.first != -1 && lastMove.second != -1) {
    pair<int, int> moveQuadrant = lastMove;
    moveQuadrant.first = moveQuadrant.first % 3;
    moveQuadrant.second = moveQuadrant.second % 3;

    // LOCAL MOVE
    if (zoomedOutBoard[moveQuadrant.first][moveQuadrant.second] == '.') {
      for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
          if (board[moveQuadrant.first*3 + i][moveQuadrant.second*3 + j] == '.') {
            validMoves.push_back(make_pair(moveQuadrant.first*3 + i, moveQuadrant.second*3 + j));
          }
        }
      }
    }
  }

  // GLOBAL MOVE
  if (validMoves.size() == 0) {
    for (int x=0; x<3; ++x) {
      for (int y=0; y<3; ++y) {
        if (zoomedOutBoard[x][y] == '.') {
          for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
              if (board[x*3+i][y*3+j] == '.') {
                validMoves.push_back(make_pair(x*3+i, y*3+j));
              }
            }
          }
        }
      }
    }
  }

  return validMoves;
}

