#include <iostream>
#include <cassert>
#include "../chess/chess.h"
extern void chessPieceTest();
extern void chessboardTest();

//void test1();

int main(){
  //test1();
  bg::Chess test;
  test.printBoard();
  chessPieceTest();
  chessboardTest();
  return 0;
}

// void test1(){
//   bg::Chess test;
//   test.printBoard();
//   std::cout << "Test 1 complete" << std::endl;
// }