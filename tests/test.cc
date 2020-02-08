#include <iostream>
#include <cassert>
#include "../chess/chess.h"

extern void chessPieceTest();
extern void chessboardTest();
extern void chessTest();

int main(){
  chessTest();
  chessPieceTest();
  chessboardTest();

  return 0;
}