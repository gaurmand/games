#include <iostream>
#include "chessboard.h"

namespace bg{

Positions ChessBoard::initialBlackSetPositions = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
Positions ChessBoard::initialWhiteSetPositions = {{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7}};

ChessBoard::ChessBoard(){
  //initialize chess board to empty
  for(uint32_t i=0; i<NUM_ROWS; i++){
    for(uint32_t j=0; j<NUM_COLUMNS; j++){
      board[i][j] = nullptr;
    }
  }
}

ChessBoard::ChessBoard(ChessPieceSet* chessSet){
  setBoard(chessSet);
}

ChessBoard::ChessBoard(ChessPieceSet* chessSet, Positions* blackPos, Positions* whitePos){
  setBoard(chessSet, blackPos, whitePos);
}

bool ChessBoard::setBoard(ChessPieceSet* chessSet){
  return setBoard(chessSet, &initialBlackSetPositions, &initialWhiteSetPositions);
}

bool ChessBoard::setBoard(ChessPieceSet* chessSet, Positions* blackPos, Positions* whitePos){
  if(!isPositionsValid(blackPos) || !isPositionsValid(whitePos)){
    std::cout << "Invalid positions in positions vector" << std::endl;
    return false;
  }

  if(!chessSet->setPiecePositions(blackPos, whitePos)){
    return false;
  }

  //set all board positions to empty
  for(uint32_t i=0; i<NUM_ROWS; i++){
    for(uint32_t j=0; j<NUM_COLUMNS; j++){
      board[i][j] = nullptr;
    }
  }

  //set black pieces
  Positions& bpos = *blackPos;
  for(uint32_t i=0; i<16; i++){
    uint32_t row = bpos[i].row;
    uint32_t col = bpos[i].col;
    board[row][col] = chessSet->getChessPiece(BLACK, i);
  }
  
  //set white pieces
  Positions& wpos = *whitePos;
  for(uint32_t i=0; i<16; i++){
    uint32_t row = wpos[i].row;
    uint32_t col = wpos[i].col;
    board[row][col] = chessSet->getChessPiece(WHITE, i);
  }

  return true;
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
  
  return true;
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
  return (pos.row < NUM_ROWS && pos.row >= 0 && pos.col < NUM_COLUMNS && pos.col >= 0);
}

bool ChessBoard::isPositionsValid(Positions* positions){
  bool res = true;
  for(Position pos : *positions){
    res = res && isPositionValid(pos);
  }
  return res;
}

}//namespace board_games