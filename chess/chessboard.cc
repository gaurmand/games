#include <iostream>
#include "chessboard.h"

namespace bg{

ChessBoard::ChessBoard(ChessPieceSet* chessSet){
  //black pieces
  for(uint32_t i=0; i<NUM_COLUMNS; i++){
	  board[0][i] = chessSet->getChessPiece(BLACK, i);
    board[1][i] = chessSet->getChessPiece(BLACK, 8+i);
  }

  //white pieces
  for(uint32_t i=0; i<NUM_COLUMNS; i++){
	  board[7][i] = chessSet->getChessPiece(WHITE, i);
    board[6][i] = chessSet->getChessPiece(WHITE, 8+i);
  }

  //empty board squares
  for(uint32_t i=2; i<6; i++){
    for(uint32_t j=0; j<NUM_COLUMNS; j++){
      board[i][j] = nullptr;
    }
  }
}

ChessPiece* ChessBoard::getPiece(Position pos){
  if(!isPositionValid(pos)){
    std::cout << "Invalid position in ChessBoard::getPiece()" << std::endl;
  };
  return board[pos.row][pos.col];
}

bool ChessBoard::movePiece(ChessPiece* piece, Position to){
  if(!isPositionValid(piece->pos) || !isPositionValid(to) || !isPieceAtPosition(piece)){
    std::cout << "Invalid move" << std::endl;
    return false;
  }
  //update board
  board[to.row][to.col] = board[piece->pos.row][piece->pos.col];
  board[piece->pos.row][piece->pos.col] = nullptr;

  //update position in ChessPiece
  piece->pos.row = to.row;
  piece->pos.col = to.col;
}

bool ChessBoard::isPieceAtPosition(ChessPiece* piece){
  if(!isPositionValid(piece->pos)){
    std::cout << "Invalid position in ChessBoard::isPieceAtPosition()" << std::endl;
    return false;
  }
  return board[piece->pos.row][piece->pos.col] == piece;
}

bool ChessBoard::isPositionEmpty(Position pos){
  if(!isPositionValid(pos)){
    std::cout << "Invalid position in ChessBoard::isPositionEmpty()" << std::endl;
    return false;
  }
  return  board[pos.row][pos.col] == nullptr;
}

bool ChessBoard::isPositionValid(Position pos){
  return (pos.row < NUM_ROWS || pos.row >= 0 || pos.col < NUM_COLUMNS || pos.col >= 0);
}

}//namespace board_games