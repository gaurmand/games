#include <iostream>
#include <vector>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"
#include "../chess/chessboard.h"
using namespace bg;
extern void assertValidPiece(ChessPiece* piece, Player player, ChessPieceType type, Position pos = {9,9});

namespace{

void test1(){
  //tests constructor and ChessBoard.isPositionValid()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPositionValid({i,j}));
    }
  }
}

void test2(){
  //tests ChessBoard.getPiece()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  assertValidPiece(chessBoard.getPiece({0,0}), BLACK, ROOK, {0,0});
  assertValidPiece(chessBoard.getPiece({0,1}), BLACK, KNIGHT, {0,1});
  assertValidPiece(chessBoard.getPiece({0,2}), BLACK, BISHOP, {0,2});
  assertValidPiece(chessBoard.getPiece({0,3}), BLACK, QUEEN, {0,3});
  assertValidPiece(chessBoard.getPiece({0,4}), BLACK, KING, {0,4});
  assertValidPiece(chessBoard.getPiece({0,5}), BLACK, BISHOP, {0,5});
  assertValidPiece(chessBoard.getPiece({0,6}), BLACK, KNIGHT, {0,6});
  assertValidPiece(chessBoard.getPiece({0,7}), BLACK, ROOK, {0,7}); 

  for(uint32_t i=0; i<8; i++){
    assertValidPiece(chessBoard.getPiece({1,i}), BLACK, PAWN, {1,i});
  }

  assertValidPiece(chessBoard.getPiece({7,0}), WHITE, ROOK, {7,0});
  assertValidPiece(chessBoard.getPiece({7,1}), WHITE, KNIGHT, {7,1});
  assertValidPiece(chessBoard.getPiece({7,2}), WHITE, BISHOP, {7,2});
  assertValidPiece(chessBoard.getPiece({7,3}), WHITE, QUEEN, {7,3});
  assertValidPiece(chessBoard.getPiece({7,4}), WHITE, KING, {7,4});
  assertValidPiece(chessBoard.getPiece({7,5}), WHITE, BISHOP, {7,5});
  assertValidPiece(chessBoard.getPiece({7,6}), WHITE, KNIGHT, {7,6});
  assertValidPiece(chessBoard.getPiece({7,7}), WHITE, ROOK, {7,7});

  for(uint32_t i=0; i<8; i++){
    assertValidPiece(chessBoard.getPiece({6,i}), WHITE, PAWN, {6,i});
  } 
}

void test3(){
  //tests ChessBoard.isPieceAtPosition() and ChessBoard.isPositionEmpty()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  //assert black pieces
  for(uint32_t i=0; i<2; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }

  //assert white piece
  for(uint32_t i=6; i<8; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }

  //assert empty positions
  for(uint32_t i=2; i<6; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPositionEmpty({i,j}));
    }
  }
}

void test4(){
  //tests ChessBoard.movePiece()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  ChessPiece* blackKnight = chessBoard.getPiece({0,1});
  assert(chessBoard.movePiece(blackKnight, {2,0}));
  assertValidPiece(blackKnight, BLACK, KNIGHT, {2,0});
  assert(chessBoard.isPieceAtPosition(blackKnight));
  assert(chessBoard.isPositionEmpty({0,1}));

  ChessPiece* whitePawn = chessBoard.getPiece({6,5});
  assert(chessBoard.movePiece(whitePawn, {4,5}));
  assertValidPiece(whitePawn, WHITE, PAWN, {4,5});
  assert(chessBoard.isPieceAtPosition(whitePawn));
  assert(chessBoard.isPositionEmpty({6,5}));

  ChessPiece* whiteQueen = chessBoard.getPiece({7,3});
  ChessPiece* blackKing = chessBoard.getPiece({0,4});
  assert(chessBoard.movePiece(whiteQueen, {0,4}));
  assertValidPiece(whiteQueen, WHITE, QUEEN, {0,4});
  assert(chessBoard.isPieceAtPosition(whiteQueen));
  assert(!chessBoard.isPieceAtPosition(blackKing));
  assert(chessBoard.isPositionEmpty({7,3}));
}

} //unnamed namespace

void chessboardTest(){
  std::cout << "Chessboard test starting" << std::endl;
  test1();
  std::cout << "Test 1 complete" << std::endl;
  test2();
  std::cout << "Test 2 complete" << std::endl;
  test3();
  std::cout << "Test 3 complete" << std::endl;
  test4();
  std::cout << "Test 4 complete" << std::endl;
  std::cout << "Chessboard test complete" << std::endl;
  std::cout << "------------------------------" << std::endl;
}
