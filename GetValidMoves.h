#ifndef GETVALIDMOVES_H_INCLUDED
#define GETVALIDMOVES_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include "ZoomOutBoard.h"

using namespace std;

vector<pair<int, int> > getValidMoves(vector<string> board, pair<int, int> lastMove);

#endif
