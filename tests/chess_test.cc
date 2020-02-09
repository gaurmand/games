#include <iostream>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"
#include "../chess/chessboard.h"
using namespace bg;

namespace{
  void test1(){
    Chess chess;
    chess.printBoard();
  }
}

void chessTest(){
  std::cout << "Chess test starting" << std::endl;
  test1();
  std::cout << "Test 1 complete" << std::endl;
  std::cout << "Chess test complete" << std::endl;
  std::cout << "------------------------------" << std::endl;
}