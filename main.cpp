#include <iostream>
#include <vector>
#include <string>

#include "MoveWithMonteCarlo.h"

using namespace std;

int main() {
  // Read input
  pair<int, int> lastMove;
  vector<string> board(9);

  cin >> lastMove.first >> lastMove.second;
  for (int i=0; i<9; ++i) {
    cin >> board[i];
  }

  // Calc move
  pair<int, int> move = MoveWithMonteCarlo(board, lastMove);

  // Do move
  char player = FIRST_PLAYER;
  if (lastMove.first != -1 && lastMove.second != -1) {
    player = (board[lastMove.first][lastMove.second] == 'o') ? 'x' : 'o';
  }

  board[move.first][move.second] = player;

  // Show output
  cout << move.first << ' ' << move.second << endl;
  for (auto it : board) {
    cout << it << endl;
  }

  return 0;
}
