#include "ZoomOutBoard.h"
#include "QuadrantWinner.h"

/*
  QuadrantWinner is a function that receives a uttt board and
  calculates the zoomed out board by getting the winner of each subboard

  example
  board: --
    ..o .x. o..
    .o. .x. .o.
    o.. .x. ..o
    
    ... ... ...
    xxx ... xxx
    ... ... ...
    
    ..o .x. o..
    .o. .x. .o.
    o.. .x. ..o

  ->
    oxo
    x.x
    oxo
*/
vector<string> ZoomOutBoard(vector<string> board) {
  vector<string> mini(3);

  for (int i=0; i<3; ++i) {
    mini[i] = "   ";

    for (int j=0; j<3; ++j) {
      mini[i][j] = QuadrantWinner(board, make_pair(i, j));
    }
  }

  return mini;
}
