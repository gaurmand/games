#include <iostream>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"
#include "../chess/chessboard.h"
using namespace bg;

namespace{

  void test1(){
    //valid strings
    assert(ChessMove::isChessMoveString("h1 e5"));
    assert(ChessMove::isChessMoveString("d8 a2"));

    //wrong length
    assert(!ChessMove::isChessMoveString("a1b2"));
    assert(!ChessMove::isChessMoveString("a1b2c3"));

    //wrong format
    assert(!ChessMove::isChessMoveString("e3-c4"));
    assert(!ChessMove::isChessMoveString("3e 4c"));

    //wrong file or rank
    assert(!ChessMove::isChessMoveString("q1 a2"));
    assert(!ChessMove::isChessMoveString("b0 a2"));
    assert(!ChessMove::isChessMoveString("a1 s8"));
    assert(!ChessMove::isChessMoveString("g3 e9"));
  }

  void test2(){
    ChessPieceSet chessSet;
    ChessBoard chessBoard(&chessSet);

    ChessMove move(chessBoard.getPiece({7,4}), {6,4});
    assert(move.getPiece()->pos.row == 7 && move.getPiece()->pos.col == 4);
    assert(move.getPiece()->type == KING);
    assert(move.getPiece()->player == WHITE);
    assert(move.getTo().row == 6 && move.getTo().col == 4);

    ChessMove move1("h1 e5", &chessBoard);
    assert(move1.getPiece()->pos.row == 7 && move1.getPiece()->pos.col == 7);
    assert(move1.getPiece()->type == ROOK);
    assert(move1.getPiece()->player == WHITE);
    assert(move1.getTo().row == 3 && move1.getTo().col == 4);

    ChessMove move2("d8 a2", &chessBoard);
    assert(move2.getPiece()->pos.row == 0 && move2.getPiece()->pos.col == 3);
    assert(move2.getPiece()->type == QUEEN);
    assert(move2.getPiece()->player == BLACK);
    assert(move2.getTo().row == 6 && move2.getTo().col == 0);

    ChessMove move3("d8a2", &chessBoard);
    assert(!move3.isValidMove());
    ChessMove move4("e3-c4", &chessBoard);
    assert(!move4.isValidMove());
    ChessMove move5("q1 a2", &chessBoard);
    assert(!move5.isValidMove());
    ChessMove move6("b0 a2", &chessBoard);
    assert(!move6.isValidMove());
    ChessMove move7("a1 s8", &chessBoard);
    assert(!move7.isValidMove());
    ChessMove move8("g3 e9", &chessBoard);
    assert(!move8.isValidMove());
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