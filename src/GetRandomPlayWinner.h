#ifndef GETRANDOMPLAYWINNER_H_INCLUDED
#define GETRANDOMPLAYWINNER_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include "GetValidMoves.h"
#include "ZoomOutBoard.h"
#include "QuadrantWinner.h"

#define FIRST_PLAYER 'o'

using namespace std;

char GetRandomPlayWinner(vector<string>, pair<int, int>);

#endif
