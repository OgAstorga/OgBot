#include <iostream>

#include "QuadrantWinner.h"

/*
.a.
...
.b.

|
v

.a.....b.

|
v

.a.......
.......b.

|
v

(010000000) dot (2^0, 2^1, ...
(000000010) dot (2^0, 2^1, ...

|
v

10 base 2 = 2 base 10
10000000 base 2 = 128 base 10
*/

pair<int, int> encode(vector<string> board) {
  int a = 0;
  int b = 0;

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (board[i][j] == 'a') {
        a |= 1<<(3*i + j);
      }

      if (board[i][j] == 'b') {
        b |= 1<<(3*i + j);
      }
    }
  }

  return make_pair(a, b);
}

void test(vector<string> board, pair<bool, bool> expected) {
  pair<int, int> encodedBoard = encode(board);
  pair<bool, bool> winner = QuadrantWinner(encodedBoard);

  cout << "test" << endl;
  for (auto it: board) {
    cout << "  " << it << endl;
  }
  if (winner.first == expected.first && winner.second == expected.second) {
    cout << "pass" << endl;
  } else {
    cout << "fail" << endl;
  }
  cout << endl;
}

int main() {
  pair<int, int> board;
  pair<bool, bool> winner;

  // basic
  test({
    "a..",
    "a..",
    "a..",
  }, make_pair(true, false));

  test({
    ".b.",
    ".b.",
    ".b.",
  }, make_pair(false, true));

  test({
    "..a",
    "..a",
    "..a",
  }, make_pair(true, false));

  test({
    "bbb",
    "...",
    "...",
  }, make_pair(false, true));

  test({
    "...",
    "aaa",
    "...",
  }, make_pair(true, false));

  test({
    "...",
    "...",
    "bbb",
  }, make_pair(false, true));

  test({
    "a..",
    ".a.",
    "..a",
  }, make_pair(true, false));

  test({
    "..b",
    ".b.",
    "b..",
  }, make_pair(false, true));

  test({
    "a..",
    "...",
    "..b",
  }, make_pair(false, false));

  test({
    "aaa",
    "...",
    "..b",
  }, make_pair(true, false));

  test({
    "aab",
    "aab",
    "b.b",
  }, make_pair(false, true));

  test({
    "..a",
    "..a",
    "..a",
  }, make_pair(true, false));

  test({
    "a.b",
    ".aa",
    "bbb",
  }, make_pair(false, true));

  test({
    "...",
    "...",
    "...",
  }, make_pair(false, false));
}

