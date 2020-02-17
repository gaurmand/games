#include <iostream>
#include <vector>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"
#include "../chess/chessboard.h"
using namespace bg;

extern void assertChessPiece(ChessPiece* piece, bool isCaptured, Player player = NONE, ChessPieceType type = EMPTY, Position pos = {9,9});

namespace{

void test1(){
  //tests default constructor ChessBoard(), isPositionEmpty(), getPiece()
  ChessBoard chessBoard;
  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPositionEmpty({i,j}));
      assert(chessBoard.getPiece({i,j}) == nullptr);
    }
  }
}

void test2(){
  //test constructor ChessBoard(ChessPieceSet* chessSet), isPieceAtPosition()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  for(uint32_t i=2; i<6; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(chessBoard.isPositionEmpty({i,j}));
    }
  }
  for(uint32_t i=0; i<2; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(!chessBoard.isPositionEmpty({i,j}));
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }
  for(uint32_t i=6; i<8; i++){
    for(uint32_t j=0; j<ChessBoard::NUM_COLUMNS; j++){
      assert(!chessBoard.isPositionEmpty({i,j}));
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }

  assertChessPiece(chessBoard.getPiece({0,0}), false, BLACK, ROOK, {0,0});
  assertChessPiece(chessBoard.getPiece({0,1}), false, BLACK, KNIGHT, {0,1});
  assertChessPiece(chessBoard.getPiece({0,2}), false, BLACK, BISHOP, {0,2});
  assertChessPiece(chessBoard.getPiece({0,3}), false, BLACK, QUEEN, {0,3});
  assertChessPiece(chessBoard.getPiece({0,4}), false, BLACK, KING, {0,4});
  assertChessPiece(chessBoard.getPiece({0,5}), false, BLACK, BISHOP, {0,5});
  assertChessPiece(chessBoard.getPiece({0,6}), false, BLACK, KNIGHT, {0,6});
  assertChessPiece(chessBoard.getPiece({0,7}), false, BLACK, ROOK, {0,7}); 

  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessBoard.getPiece({1,i}), false, BLACK, PAWN, {1,i});
  }

  assertChessPiece(chessBoard.getPiece({7,0}), false, WHITE, ROOK, {7,0});
  assertChessPiece(chessBoard.getPiece({7,1}), false, WHITE, KNIGHT, {7,1});
  assertChessPiece(chessBoard.getPiece({7,2}), false, WHITE, BISHOP, {7,2});
  assertChessPiece(chessBoard.getPiece({7,3}), false, WHITE, QUEEN, {7,3});
  assertChessPiece(chessBoard.getPiece({7,4}), false, WHITE, KING, {7,4});
  assertChessPiece(chessBoard.getPiece({7,5}), false, WHITE, BISHOP, {7,5});
  assertChessPiece(chessBoard.getPiece({7,6}), false, WHITE, KNIGHT, {7,6});
  assertChessPiece(chessBoard.getPiece({7,7}), false, WHITE, ROOK, {7,7});

  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessBoard.getPiece({6,i}), false, WHITE, PAWN, {6,i});
  } 
}

void test3(){
  //test constructor ChessBoard(ChessPieceSet* chessSet, Positions* blackPos, Positions* whitePos)
  ChessPieceSet chessSet;
  Positions blackPos{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1}};
  Positions whitePos{{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6}};
  ChessBoard chessBoard(&chessSet, &blackPos, &whitePos);

  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    for(uint32_t j=2; j<6; j++){
      assert(chessBoard.isPositionEmpty({i,j}));
    }
  }
  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    for(uint32_t j=0; j<2; j++){
      assert(!chessBoard.isPositionEmpty({i,j}));
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }
  for(uint32_t i=0; i<ChessBoard::NUM_ROWS; i++){
    for(uint32_t j=6; j<8; j++){
      assert(!chessBoard.isPositionEmpty({i,j}));
      assert(chessBoard.isPieceAtPosition(chessBoard.getPiece({i,j})));
    }
  }

  assertChessPiece(chessBoard.getPiece({0,0}), false, BLACK, ROOK, {0,0});
  assertChessPiece(chessBoard.getPiece({1,0}), false, BLACK, KNIGHT, {1,0});
  assertChessPiece(chessBoard.getPiece({2,0}), false, BLACK, BISHOP, {2,0});
  assertChessPiece(chessBoard.getPiece({3,0}), false, BLACK, QUEEN, {3,0});
  assertChessPiece(chessBoard.getPiece({4,0}), false, BLACK, KING, {4,0});
  assertChessPiece(chessBoard.getPiece({5,0}), false, BLACK, BISHOP, {5,0});
  assertChessPiece(chessBoard.getPiece({6,0}), false, BLACK, KNIGHT, {6,0});
  assertChessPiece(chessBoard.getPiece({7,0}), false, BLACK, ROOK, {7,0}); 

  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessBoard.getPiece({i,1}), false, BLACK, PAWN, {i,1});
  }

  assertChessPiece(chessBoard.getPiece({0,7}), false, WHITE, ROOK, {0,7});
  assertChessPiece(chessBoard.getPiece({1,7}), false, WHITE, KNIGHT, {1,7});
  assertChessPiece(chessBoard.getPiece({2,7}), false, WHITE, BISHOP, {2,7});
  assertChessPiece(chessBoard.getPiece({3,7}), false, WHITE, QUEEN, {3,7});
  assertChessPiece(chessBoard.getPiece({4,7}), false, WHITE, KING, {4,7});
  assertChessPiece(chessBoard.getPiece({5,7}), false, WHITE, BISHOP, {5,7});
  assertChessPiece(chessBoard.getPiece({6,7}), false, WHITE, KNIGHT, {6,7});
  assertChessPiece(chessBoard.getPiece({7,7}), false, WHITE, ROOK, {7,7});

  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessBoard.getPiece({i,6}), false, WHITE, PAWN, {i,6});
  } 
}

void test4(){
  //tests ChessBoard.movePiece()
  ChessPieceSet chessSet;
  ChessBoard chessBoard(&chessSet);

  ChessPiece* blackKnight = chessBoard.getPiece({0,1});
  assert(chessBoard.movePiece(blackKnight, {2,0}));
  assertChessPiece(blackKnight, false, BLACK, KNIGHT, {2,0});
  assert(chessBoard.isPieceAtPosition(blackKnight));
  assert(chessBoard.isPositionEmpty({0,1}));

  ChessPiece* whitePawn = chessBoard.getPiece({6,5});
  assert(chessBoard.movePiece(whitePawn, {4,5}));
  assertChessPiece(whitePawn, false, WHITE, PAWN, {4,5});
  assert(chessBoard.isPieceAtPosition(whitePawn));
  assert(chessBoard.isPositionEmpty({6,5}));

  ChessPiece* whiteQueen = chessBoard.getPiece({7,3});
  ChessPiece* blackKing = chessBoard.getPiece({0,4});
  assert(chessBoard.movePiece(whiteQueen, {0,4}));
  assertChessPiece(whiteQueen, false, WHITE, QUEEN, {0,4});
  assert(chessBoard.isPieceAtPosition(whiteQueen));
  assert(!chessBoard.isPieceAtPosition(blackKing));
  assert(chessBoard.isPositionEmpty({7,3}));
}

} //unnamed namespace

void chessBoardTest(){
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
