#include <utility>

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

  // Calc move
  pair<int, int> move = MoveWithMonteCarlo(vectorBoard, lastMove);

  // Do move
  char player = FIRST_PLAYER;
  if (lastMove.first != -1 && lastMove.second != -1) {
    player = (vectorBoard[lastMove.first][lastMove.second] == 'o') ? 'x' : 'o';
  }

  vectorBoard[move.first][move.second] = player;

  // Prepare JS output
  Local<Object> obj = Object::New(isolate);

  // insert lastMove to JS output
  Local<Object> lastMoveObject = Object::New(isolate);
  lastMoveObject->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, move.second));
  lastMoveObject->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, move.first));
  obj->Set(String::NewFromUtf8(isolate, "lastMove"), lastMoveObject);

  // Insert board to JS output
  stringBoard = string(81, '.');
  for (int row=0; row<9; ++row) {
    for (int col=0; col<9; ++col) {
      stringBoard[row*9 + col] = vectorBoard[row][col];
    }
  }
  obj->Set(String::NewFromUtf8(isolate, "board"), String::NewFromUtf8(isolate, stringBoard.c_str()));

  args.GetReturnValue().Set(obj);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "play", Play);
}

NODE_MODULE(addon, init)
