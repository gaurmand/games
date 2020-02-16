#include <iostream>
#include <cassert>
#include <cctype>
#include <cstring>

#include "../chess/chess.h"

extern void chessPieceTest();
extern void chessboardTest();
extern void chessMoveTest();
extern void chessTest();

int main(){
  //chessTest();
  chessPieceTest();
  //chessboardTest();
  //chessMoveTest();
  return 0;
}