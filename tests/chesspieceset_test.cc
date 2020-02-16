#include <iostream>
#include <vector>
#include <cassert>
#include "../chess/chess.h"
#include "../chess/chesspieceset.h"

using namespace bg;

void assertChessPiece(ChessPiece* piece, bool isCaptured, Player player = NONE, ChessPieceType type = EMPTY, Position pos = {9,9}){
  assert(piece != nullptr);
  assert(piece->isCaptured == isCaptured);

  if(player != NONE)
    assert(piece->player == player);
  if (type != EMPTY)
    assert(piece->type == type);
  if (pos.row != 9)
    assert(piece->pos.row == pos.row);
  if (pos.col != 9)
    assert(piece->pos.col == pos.col);
}

namespace {

void test1(){
  //tests ChessPieceSet default constructor and ChessPieceSet.getChessPiece()
  //makes sure all chess pieces have invalid positions
  ChessPieceSet chessSet;
  Position invalidPos{9,9};
  assertChessPiece(chessSet.getChessPiece(BLACK, 0), false, BLACK, ROOK, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 1), false, BLACK, KNIGHT, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 2), false, BLACK, BISHOP, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 3), false, BLACK, QUEEN, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 4), false, BLACK, KING, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 5), false, BLACK, BISHOP, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 6), false, BLACK, KNIGHT, invalidPos);
  assertChessPiece(chessSet.getChessPiece(BLACK, 7), false, BLACK, ROOK, invalidPos);
  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessSet.getChessPiece(BLACK, i+8), false, BLACK, PAWN, invalidPos);
  }

  assertChessPiece(chessSet.getChessPiece(WHITE, 0), false, WHITE, ROOK, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 1), false, WHITE, KNIGHT, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 2), false, WHITE, BISHOP, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 3), false, WHITE, QUEEN, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 4), false, WHITE, KING, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 5), false, WHITE, BISHOP, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 6), false, WHITE, KNIGHT, invalidPos);
  assertChessPiece(chessSet.getChessPiece(WHITE, 7), false, WHITE, ROOK, invalidPos);
  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessSet.getChessPiece(WHITE, i+8), false, WHITE, PAWN, invalidPos);
  }
}

void test2() {
  //tests ChessPieceSet constructor
  //makes sure all chess pieces are in the specified positions
  Positions blackPos{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1}};
  Positions whitePos{{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6}};
  ChessPieceSet chessSet(&blackPos, &whitePos);

  assertChessPiece(chessSet.getChessPiece(BLACK, 0), false, BLACK, ROOK, {0,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 1), false, BLACK, KNIGHT, {1,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 2), false, BLACK, BISHOP, {2,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 3), false, BLACK, QUEEN, {3,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 4), false, BLACK, KING, {4,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 5), false, BLACK, BISHOP, {5,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 6), false, BLACK, KNIGHT, {6,0});
  assertChessPiece(chessSet.getChessPiece(BLACK, 7), false, BLACK, ROOK, {7,0});
  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessSet.getChessPiece(BLACK, i+8), false, BLACK, PAWN, {i,1});
  }

  assertChessPiece(chessSet.getChessPiece(WHITE, 0), false, WHITE, ROOK, {0,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 1), false, WHITE, KNIGHT, {1,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 2), false, WHITE, BISHOP, {2,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 3), false, WHITE, QUEEN, {3,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 4), false, WHITE, KING, {4,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 5), false, WHITE, BISHOP, {5,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 6), false, WHITE, KNIGHT, {6,7});
  assertChessPiece(chessSet.getChessPiece(WHITE, 7), false, WHITE, ROOK, {7,7});
  for(uint32_t i=0; i<8; i++){
    assertChessPiece(chessSet.getChessPiece(WHITE, i+8), false, WHITE, PAWN, {i,6});
  }
}

void test3(){
  //tests ChessPieceSet.getPieces(Player player)
  ChessPieceSet chessSet;
  std::vector<Player> players{BLACK, WHITE};

  for(Player player: players){
    ChessPieces pieces = chessSet.getPieces(player);
    assert(pieces.size() == 16);

    for(uint32_t i=0; i<16; i++){
      assertChessPiece(pieces[i], false, player);
      pieces[i]->isCaptured = true;
    }

    //filter out all captured pieces
    pieces = chessSet.getPieces(player);
    assert(pieces.size() == 0);

    //do not filter captured pieces
    pieces = chessSet.getPieces(player, false);
    assert(pieces.size() == 16);
  }
}

void test4(){
  //tests ChessPieceSet.getPieces(Player player, ChessPieceType type)
  ChessPieceSet chessSet;
  std::vector<Player> players{BLACK, WHITE};

  for(Player player: players){
    ChessPieces pieces = chessSet.getPieces(player, ROOK);
    assert(pieces.size() == 2);
    assertChessPiece(pieces[0], false, player, ROOK);
    assertChessPiece(pieces[1], false, player, ROOK);

    pieces = chessSet.getPieces(player, KNIGHT);
    assert(pieces.size() == 2);
    assertChessPiece(pieces[0], false, player, KNIGHT);
    assertChessPiece(pieces[1], false, player, KNIGHT);

    pieces = chessSet.getPieces(player, BISHOP);
    assert(pieces.size() == 2);
    assertChessPiece(pieces[0], false, player, BISHOP);
    assertChessPiece(pieces[1], false, player, BISHOP);

    pieces = chessSet.getPieces(player, QUEEN);
    assert(pieces.size() == 1);
    assertChessPiece(pieces[0], false,  player, QUEEN);

    pieces = chessSet.getPieces(player, KING);
    assert(pieces.size() == 1);
    assertChessPiece(pieces[0], false, player, KING);

    pieces = chessSet.getPieces(player, PAWN);
    assert(pieces.size() == 8);
    for(uint32_t i=0; i<8; i++){
      assertChessPiece(pieces[i], false, player, PAWN);
      pieces[i]->isCaptured = true; //capture all pawns
    }

    //filter captured pawns
    pieces = chessSet.getPieces(player, PAWN);
    assert(pieces.size() == 0);

    //do not filter captured pawns
    pieces = chessSet.getPieces(player, PAWN, false);
    assert(pieces.size() == 8);

  }
}

}//unnamed namespace

void chessPieceTest(){
  std::cout << "ChessPiece test starting" << std::endl;
  test1();
  std::cout << "Test 1 complete" << std::endl;
  test2();
  std::cout << "Test 2 complete" << std::endl;
  test3();  
  std::cout << "Test 3 complete" << std::endl;
  test4();  
  std::cout << "Test 4 complete" << std::endl;
  std::cout << "ChessPiece test complete" << std::endl;
  std::cout << "------------------------------" << std::endl;
}
