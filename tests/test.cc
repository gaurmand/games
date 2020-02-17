#include <iostream>
#include <cassert>
#include <cctype>
#include <cstring>

#include "../chess/chess.h"

extern void chessPieceTest();
extern void chessBoardTest();
extern void chessMoveTest();
extern void chessTest();

int main(){
  //chessTest();
  chessPieceTest();
  chessBoardTest();
  //chessMoveTest();
  return 0;
}