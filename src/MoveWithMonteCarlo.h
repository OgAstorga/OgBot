#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>
#include <time.h>

#define MONTECARLO_TIME 5

#include "GetRandomPlayWinner.h"
#include "GetValidMoves.h"

#include "Board.h"
#include "GameSimulator.h"

using namespace std;

pair<int, int> MoveWithMonteCarlo(vector<string>, pair<int, int>);
short MoveWithMonteCarlo(Board, short);
