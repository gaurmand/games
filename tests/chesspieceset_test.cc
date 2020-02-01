#include <iostream>
#include <vector>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"

using namespace bg;

void assertValidPieceIndex(ChessPieceType type, uint32_t pieceIndex){
  switch(type){
    case PAWN:
      assert(pieceIndex>7 && pieceIndex<16);
      break;
    case ROOK:
      assert(pieceIndex==0 || pieceIndex==7);
      break;
    case KNIGHT:
      assert(pieceIndex==1 || pieceIndex==6);
      break;
    case BISHOP:
      assert(pieceIndex==2 || pieceIndex==5);
      break;
    case QUEEN:
      assert(pieceIndex==3);
      break;
    case KING:
      assert(pieceIndex==4);
      break;
    default:
      assert(false);
  }
}

void assertValidPiece(ChessPiece* piece, Player player, ChessPieceType type, Position pos = {9,9}){
  assert(piece != nullptr);
  assert(piece->player == player);
  assert(piece->type == type);
  assert(!piece->isCaptured);

  //only assert position, if a position argument was given
  if(pos.row != 9 || pos.col !=9){
    assert(piece->pos.row == pos.row && piece->pos.col == pos.col);
  }
}

namespace {

void test1(){
  //tests ChessPieceSet.getChessPiece(Player player, uint32_t pieceIndex)
  ChessPieceSet chessSet;
  ChessPieces pieces;
  std::vector<Player> players{BLACK, WHITE};

  for(Player player: players){
    for(uint32_t i=0; i<16; i++){
      ChessPiece* piece = chessSet.getChessPiece(player, i);
      assertValidPieceIndex(piece->type, i);
    }
  }
}

void test2(){
  //tests ChessPieceSet.getPieces(Player player)
  ChessPieceSet chessSet;
  ChessPieces pieces;

  pieces = chessSet.getPieces(BLACK);
  assert(pieces.size() == 16);
  assertValidPiece(pieces[0], BLACK, ROOK, {0,0});
  assertValidPiece(pieces[1], BLACK, KNIGHT, {0,1});
  assertValidPiece(pieces[2], BLACK, BISHOP, {0,2});
  assertValidPiece(pieces[3], BLACK, QUEEN, {0,3});
  assertValidPiece(pieces[4], BLACK, KING, {0,4});
  assertValidPiece(pieces[5], BLACK, BISHOP, {0,5});
  assertValidPiece(pieces[6], BLACK, KNIGHT, {0,6});
  assertValidPiece(pieces[7], BLACK, ROOK, {0,7});

  for(uint32_t i=8; i<16; i++){
    assertValidPiece(pieces[i], BLACK, PAWN, {1,i-8});
  }

  pieces = chessSet.getPieces(WHITE);
  assert(pieces.size() == 16);
  assertValidPiece(pieces[0], WHITE, ROOK, {7,0});
  assertValidPiece(pieces[1], WHITE, KNIGHT, {7,1});
  assertValidPiece(pieces[2], WHITE, BISHOP, {7,2});
  assertValidPiece(pieces[3], WHITE, QUEEN, {7,3});
  assertValidPiece(pieces[4], WHITE, KING, {7,4});
  assertValidPiece(pieces[5], WHITE, BISHOP, {7,5});
  assertValidPiece(pieces[6], WHITE, KNIGHT, {7,6});
  assertValidPiece(pieces[7], WHITE, ROOK, {7,7});

  for(uint32_t i=8; i<16; i++){
    assertValidPiece(pieces[i], WHITE, PAWN, {6,i-8});
  }
}

void test3(){
  //tests ChessPieceSet.getPieces(Player player, ChessPieceType type)
  ChessPieceSet chessSet;
  ChessPieces pieces;
  std::vector<Player> players{BLACK, WHITE};

  for(Player player: players){
    pieces = chessSet.getPieces(player, ROOK);
    assert(pieces.size() == 2);
    assertValidPiece(pieces[0], player, ROOK);
    assertValidPiece(pieces[1], player, ROOK);

    pieces = chessSet.getPieces(player, KNIGHT);
    assert(pieces.size() == 2);
    assertValidPiece(pieces[0], player, KNIGHT);
    assertValidPiece(pieces[1], player, KNIGHT);

    pieces = chessSet.getPieces(player, BISHOP);
    assert(pieces.size() == 2);
    assertValidPiece(pieces[0], player, BISHOP);
    assertValidPiece(pieces[1], player, BISHOP);

    pieces = chessSet.getPieces(player, QUEEN);
    assert(pieces.size() == 1);
    assertValidPiece(pieces[0], player, QUEEN);

    pieces = chessSet.getPieces(player, KING);
    assert(pieces.size() == 1);
    assertValidPiece(pieces[0], player, KING);

    pieces = chessSet.getPieces(player, PAWN);
    assert(pieces.size() == 8);
    for(uint32_t i; i<8; i++){
      assertValidPiece(pieces[i], player, PAWN);
    }
  }
}

}//unnamed namespace

void chessPieceTest(){
  std::cout << "Chess piece test starting" << std::endl;
  test1();
  std::cout << "Test 1 complete" << std::endl;
  test2();
  std::cout << "Test 2 complete" << std::endl;
  test3();  
  std::cout << "Test 3 complete" << std::endl;
  std::cout << "Chess piece test complete" << std::endl;
}
