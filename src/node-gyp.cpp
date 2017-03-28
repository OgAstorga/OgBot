#include <utility>

#include "Board.h"
#include "MoveWithMonteCarlo.h"

#include <node.h>

using std::pair;
using std::vector;
using std::string;

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void Play(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Read lastMove from input
  pair<int, int> lastMove;

  // @TODO: validate lastMove input
  lastMove.first = (int)args[0]->Int32Value();
  lastMove.second = (int)args[1]->Int32Value();

  // Read board from input
  vector<string> vectorBoard(9);
  String::Utf8Value StringBoard(args[2]->ToString());
  string stringBoard = string(*StringBoard);

  // Validate board
  if (stringBoard.size() != 81) {
    // Board must have 81 characters
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Board parameter is expected to have exactly 81 characters")
    ));

    return;
  }

  for (auto it : stringBoard) {
    if (it != '.' && it != 'x' && it != 'o') {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Board parameter is expected to be in the format: /^[ox\\.]{81}$/")
      ));

      return;
    }
  }

  // Transform board
  for (int row=0; row<9; ++row) {
    vectorBoard[row] = string(9, '.');
    for (int col=0; col<9; ++col) {
      vectorBoard[row][col] = stringBoard[row*9 + col];
    }
  }

  int row = lastMove.first / 3;
  int col =  lastMove.second / 3;
  int srow = lastMove.first % 3;
  int scol = lastMove.second % 3;

  Board board(vectorBoard);

  // Calc move
  short lmove = (row*3 + col)*9 + (srow*3 + scol);

  if (board.valid_moves(lmove).size() == 0) {
    // Board must be playable
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Board state is unplayable")
    ));

    return;
  }

  short nmove = MoveWithMonteCarlo(board, lmove);

  // Do move
  if (nmove != -1) {
    short player = 1;
    if (board.board.test(lmove)) {
      player = 2;
    }

    board.set_cell(nmove, player);

    row = (nmove / 9) / 3;
    col = (nmove / 9) % 3;
    srow = (nmove % 9) / 3;
    scol = (nmove % 9) % 3;
  }

  // Prepare JS output
  Local<Object> obj = Object::New(isolate);

  // insert lastMove to JS output
  Local<Object> lastMoveObject = Object::New(isolate);
  lastMoveObject->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, col*3 + scol));
  lastMoveObject->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, row*3 + srow));
  obj->Set(String::NewFromUtf8(isolate, "lastMove"), lastMoveObject);

  // Insert board to JS output
  obj->Set(String::NewFromUtf8(isolate, "board"), String::NewFromUtf8(isolate, board.to_string(false).c_str()));

  args.GetReturnValue().Set(obj);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "play", Play);
}

NODE_MODULE(addon, init)
