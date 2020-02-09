#include <iostream>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"
#include "../chess/chessboard.h"
using namespace bg;

namespace{

  void test1(){
    //valid strings
    assert(ChessMove::checkValidMoveString("h1 e5"));
    assert(ChessMove::checkValidMoveString("d8 a2"));

    //wrong length
    assert(!ChessMove::checkValidMoveString("a1b2"));
    assert(!ChessMove::checkValidMoveString("a1b2c3"));

    //wrong format
    assert(!ChessMove::checkValidMoveString("e3-c4"));
    assert(!ChessMove::checkValidMoveString("3e 4c"));

    //wrong file or rank
    assert(!ChessMove::checkValidMoveString("q1 a2"));
    assert(!ChessMove::checkValidMoveString("b0 a2"));
    assert(!ChessMove::checkValidMoveString("a1 s8"));
    assert(!ChessMove::checkValidMoveString("g3 e9"));
  }

  void test2(){
    ChessPieceSet chessSet;
    ChessBoard chessBoard(&chessSet);
    //ChessMove move();
  }

} //unnamed namspace

void chessMoveTest(){
  std::cout << "Chess test starting" << std::endl;
  test1();
  std::cout << "Test 1 complete" << std::endl;
  test2();
  std::cout << "Test 2 complete" << std::endl;
  std::cout << "Chess test complete" << std::endl;
  std::cout << "------------------------------" << std::endl;
}